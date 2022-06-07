# Task: Using the Lidar Node

# Download the repo


# Run the simulation
ign gazebo sensor_demo.sdf

# Run the lidar node
. /build/lidar_node

# In order to launch the node as well as simulation use this single launch file

ign launch sensor_launch.ign

Note: In order to make the changes in the lidar node

cd /build
make lidar_node


#  Task: Using ROS_IGN_bridge to move robot in Gazebo

# Create a ROS2 to IGN bridge
## Open terminal: A
ros2 run ros_ign_bridge parameter_bridge /cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist


# Run the simulation
## Open new terminal: B
ign gazebo sensors_demo.sdf

# Publishing message to ign through ROS2
## Open new terminal: C
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.8}}"



