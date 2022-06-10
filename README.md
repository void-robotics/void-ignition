# Task: Using the Lidar Node


First setup ROS2 and Gazebo ignition. Follow these instructions

https://docs.ros.org/en/foxy/Installation.html
https://gazebosim.org/docs/citadel

Once the setup is complete 
Clone the repo

## Using Lidar Sensor

Inside void-ignition folder. Build a build directory


mkdir build

cd build

Run cmake and build the code:

cmake ..

make lidar_node

# Run the simulation
ign gazebo sensor_demo.sdf

# Run the lidar node
. /build/lidar_node

# In order to launch the node as well as simulation use this single launch file

ign launch sensor_launch.ign

Note: After making any changes to lidar_node configuration, you will need to rebuild the node

cd /build

make lidar_node

#### References
https://gazebosim.org/docs/citadel/sensors

##  Task: Using ROS_IGN_bridge to move robot in Gazebo

### Create a ROS2 to IGN bridge
Follow these instructions to setup ROS ignition bridge.

https://github.com/gazebosim/ros_gz/tree/foxy#binaries


### Open terminal: A
ros2 run ros_ign_bridge parameter_bridge /cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist


## Run the simulation
### Open new terminal: B
ign gazebo sensors_demo.sdf

## Publishing message to ign through ROS2
### Open new terminal: C
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.8}}"

You would now see the robot moving in the gazebo world.

Note: Make sure the gazebo ignition is not paused

References:

https://github.com/gazebosim/ros_gz/blob/ros2/ros_ign_bridge/README.md#example-1a-ignition-transport-talker-and-ros-2-listener
https://gazebosim.org/docs/citadel/ros2_integration


