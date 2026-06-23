#include <godot_cpp/classes/scene_tree.hpp>
#include "godot_ros/scene_tree.hpp"

#include <rclcpp/rclcpp.hpp>

namespace godot
{

void RosSceneTree::_initialize()
{
    rclcpp::init(0, nullptr);
}

void RosSceneTree::_finalize()
{
    // Intentionally not calling rclcpp::shutdown() here: RosNode instances
    // still alive in the scene tree are destructed after _finalize() runs,
    // and destructing their rclcpp::Node after the context has shut down
    // causes an intermittent segfault during process exit.
}

void RosSceneTree::_bind_methods() {}

}