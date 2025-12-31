#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node            //MODIFY NAME
{
public:
    MinimalPublisher() : Node("minimal_publisher"), name_("Thuc")              //MODIFY NAME
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(0.5s, std::bind(&MinimalPublisher::publishNews, this));
        RCLCPP_INFO(this->get_logger(), "Minimal Publisher");
    }

private:
    void publishNews()
    {
        auto msg = example_interfaces::msg::String();
        msg.data = std::string("Hi ") + name_ + std::string(" DevBriX");  
        publisher_->publish(msg); 
    }

    std::string name_;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MinimalPublisher>();   //MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
