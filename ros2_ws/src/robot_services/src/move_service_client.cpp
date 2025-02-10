#include <rclcpp/rclcpp.hpp>
#include <memory>
#include "robot_msgs/srv/move_to_position.hpp"

using MoveToPosition = robot_msgs::srv::MoveToPosition;

using namespace std::chrono_literals;
using namespace std::placeholders;

class MoveServiceClient : public rclcpp::Node
{
public:
    MoveServiceClient(int forearm_position, int hand_position) : Node("move_service_client")
    {
        client_ = create_client<MoveToPosition>("move_to_position");
        auto request = std::make_shared<MoveToPosition::Request>();
        request->forearm_position = forearm_position;
        request->hand_position = hand_position;

        while (!client_->wait_for_service(3s))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_WARN(rclcpp::get_logger("rclcpp"), "Service not available, waiting...");
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Communication with Service Established!");
        
        auto result = client_->async_send_request(request, std::bind(&MoveServiceClient::responseCallback, this, _1));
    }

private:
    rclcpp::Client<MoveToPosition>::SharedPtr client_;

    void responseCallback(rclcpp::Client<MoveToPosition>::SharedFuture future)
    {
        auto response = future.get();
        if (response->success)
        {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Success: %s", response->message.c_str());
        }
        else
        {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed: %s", response->message.c_str());
        }
        rclcpp::shutdown();
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    if (argc != 3)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Wrong number of arguments! Usage: ros2 run robot_services move_service_client <forearm_position> <hand_position>");
        return 1;
    }

    auto node = std::make_shared<MoveServiceClient>(atoi(argv[1]), atoi(argv[2]));

    // Use an executor to spin the node
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}