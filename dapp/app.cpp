#include <chrono>

#include <rclcpp/rclcpp.hpp>

#include <std_msgs/msg/string.hpp>

class App final : public rclcpp::Node
{
public:
  App()
  : rclcpp::Node("app"),
    chatter_pub_(this->create_publisher<std_msgs::msg::String>(
        "chatter", rclcpp::SensorDataQoS{})),
    pub_timer_(this->create_wall_timer(
        std::chrono::seconds {1}, std::bind(&App::pub_callback, this))),
    count_{0} {}

private:
  void pub_callback()
  {
    RCLCPP_INFO(
      this->get_logger(), "Publishing message with count %lu",
      count_);

    std_msgs::msg::String msg;
    msg.data = "hello: " + std::to_string(count_);
    chatter_pub_->publish(msg);

    ++count_;
  }

  const rclcpp::Publisher<std_msgs::msg::String>::SharedPtr chatter_pub_;
  const rclcpp::TimerBase::SharedPtr pub_timer_;

  std::uint64_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  const auto node = std::make_shared<App>();

  rclcpp::spin(node);

  return EXIT_SUCCESS;
}
