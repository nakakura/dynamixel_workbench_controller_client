#include <ros/ros.h>

#include "dynamixel_workbench_msgs/DynamixelCommand.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "dynamixel_workbench_controller_client");
    ros::AsyncSpinner spinner(1);
    spinner.start();

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<dynamixel_workbench_msgs::DynamixelCommand>("/dynamixel_workbench/dynamixel_command");
    dynamixel_workbench_msgs::DynamixelCommand srv;
    srv.request.command = "";
    srv.request.id = 2;
    srv.request.addr_name = "Goal_Position";
    srv.request.value = 2000;

    if (client.call(srv))
    {
        ROS_INFO("Sum: %d", (bool)srv.response.comm_result);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
    }

    ROS_ERROR("exit");

    return 0;
}