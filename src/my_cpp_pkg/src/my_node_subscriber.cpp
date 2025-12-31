#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::placeholders;

class MinimalSubscriber : public rclcpp::Node                       //MODIFY NAME
{
public:
    MinimalSubscriber() : Node("minimal_subscriber")                //MODIFY NAME
    {
        subscription_ = this->create_subscription<example_interfaces::msg::String>(
            "topic", 10, 
            std::bind(&MinimalSubscriber::callbackTopic, this, _1));
        RCLCPP_INFO(this->get_logger(), "Minimal Subscriber");
    }

private:
    void callbackTopic(const example_interfaces::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Log: %s", msg->data.c_str());
    }
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscription_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalSubscriber>();              //MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
