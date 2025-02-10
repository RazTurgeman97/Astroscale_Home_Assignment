#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <std_srvs/srv/trigger.hpp>

class SliderControl : public rclcpp::Node
{
public:
    SliderControl() : Node("slider_control"), last_positions_({0.0, 0.0})
    {
        init_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            [this]() { this->initializeMoveGroup(); });
    }

private:
    void initializeMoveGroup()
    {
        move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "arm");
        move_group_->setPlanningTime(5.0);

        sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "joint_commands", 10, std::bind(&SliderControl::sliderCallback, this, std::placeholders::_1));

        execute_service_ = this->create_service<std_srvs::srv::Trigger>(
            "execute_plan", std::bind(&SliderControl::executeServiceCallback, this, std::placeholders::_1, std::placeholders::_2));

        RCLCPP_INFO(this->get_logger(), "Slider Control Node initialized.");
        init_timer_->cancel();
    }

    void sliderCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        std::vector<double> target_positions = {msg->position[0], msg->position[1]};
        if (last_positions_ != target_positions) {
            RCLCPP_INFO(this->get_logger(), "New slider values: [%f, %f]", target_positions[0], target_positions[1]);
            move_group_->setJointValueTarget(target_positions);
            bool success = (move_group_->plan(last_plan_) == moveit::core::MoveItErrorCode::SUCCESS);
            if (success) {
                RCLCPP_INFO(this->get_logger(), "Planning succeeded!");
                move_group_->asyncExecute(last_plan_);
            } else {
                RCLCPP_ERROR(this->get_logger(), "Planning failed!");
            }
            last_positions_ = target_positions;
        }
    }

    void executeServiceCallback(
        const std_srvs::srv::Trigger::Request::SharedPtr req,
        const std_srvs::srv::Trigger::Response::SharedPtr res)
    {
        (void)req;
        if (last_plan_.trajectory_.joint_trajectory.points.empty()) {
            res->success = false;
            res->message = "No valid plan to execute!";
            RCLCPP_ERROR(this->get_logger(), "Execution failed: No plan available.");
            return;
        }

        RCLCPP_INFO(this->get_logger(), "Executing plan...");
        auto result = move_group_->execute(last_plan_);
        if (result == moveit::core::MoveItErrorCode::SUCCESS) {
            res->success = true;
            res->message = "Plan executed successfully!";
        } else {
            res->success = false;
            res->message = "Execution failed with error code: " + std::to_string(result.val);
            RCLCPP_ERROR(this->get_logger(), "Execution failed. MoveIt error code: %d", result.val);
        }
    }

    rclcpp::TimerBase::SharedPtr init_timer_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;
    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr execute_service_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    std::vector<double> last_positions_;
    moveit::planning_interface::MoveGroupInterface::Plan last_plan_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SliderControl>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}