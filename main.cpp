#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class CmdVelPublisher : public rclcpp::Node {
public:
    CmdVelPublisher() : Node("my_bot_node") {
        // Create a publisher for the /cmd_vel topic with geometry_msgs/Twist messages
        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        // Set up a timer to publish the Twist message every 1 second
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&CmdVelPublisher::publish_cmd_vel, this));
    }

    ~CmdVelPublisher() {
        twist_msg->linear.x = 0.0;  // Linear velocity in the x-axis (m/s)
        twist_msg->angular.z = 0.0;  // Angular velocity in the z-axis (rad/s)
        cmd_vel_publisher_->publish(std::move(twist_msg));
    }

private:
    void publish_cmd_vel() {
        // Create a Twist message
        twist_msg = std::make_unique<geometry_msgs::msg::Twist>();

        // Set linear and angular velocities
        twist_msg->linear.x = 0.2;  // Linear velocity in the x-axis (m/s)
        twist_msg->angular.z = 0.1;  // Angular velocity in the z-axis (rad/s)

        // Publish the Twist message
        cmd_vel_publisher_->publish(std::move(twist_msg));
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
    std::unique_ptr<geometry_msgs::msg::Twist> twist_msg;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    // Create an instance of the CmdVelPublisher class
    auto node = std::make_shared<CmdVelPublisher>();

    // Spin the node to handle the callbacks
    rclcpp::spin(node);

    // Clean up before exiting
    rclcpp::shutdown();

    return 0;
}
