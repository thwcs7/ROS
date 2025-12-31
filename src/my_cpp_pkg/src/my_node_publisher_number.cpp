#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

using namespace std::chrono_literals;

class NumberPublisherNode : public rclcpp::Node                     //MODIFY NAME
{
public:
    NumberPublisherNode() : Node("minimal_publisher")               //MODIFY NAME
    {
        this->declare_parameter("number", 2);
        this->declare_parameter("timer_period", 1.0);

        number_ = this->get_parameter("number").as_int();
        double timer_period = this->get_parameter("timer_period").as_double();
        
        number_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        number_timer_ = this->create_wall_timer(std::chrono::duration<double>(timer_period),
                                                std::bind(&NumberPublisherNode::publishNumber, this));
        RCLCPP_INFO(this->get_logger(), "Minimal Publisher");
    }

private:
    void publishNumber()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_; 
        number_publisher_->publish(msg); 
    }

    int number_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();            //MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
