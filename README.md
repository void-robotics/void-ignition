# Installation

* Install [ROS2 Foxy](https://docs.ros.org/en/foxy/Installation.html)
* Install [colcon](https://colcon.readthedocs.io/en/released/user/installation.html)
* Install [Gazebo Ignition Citadel](https://gazebosim.org/docs/citadel)
* `sudo apt install ros-foxy-ros-ign-bridge`
* `git clone https://github.com/void-robotics/void-ignition.git`
* `cd void-ignition; colcon build`

# Running

## Lidar Obstacle Avoidance
The robot will move towards a wall and backpedal and move towards another direction.
* `ign gazebo ~/void-ignition/src/lidar_node/src/sensors_demo.sdf`
* `ros2 run lidar_node lidar_node`

![Lidar Detecting the Wall](https://github.com/void-robotics/void-ignition/blob/main/GIF_Lidar.gif)

## ROS2 <-> Ignition Bridge Test
The robot will spin in a circle.
* `ign gazebo ~/void-ignition/src/lidar_node/src/sensors_demo.sdf`
* `ros2 run ros_ign_bridge parameter_bridge /cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist`
* `ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.8}}"`

![Publishing msgs using ROS-IGN bridge](https://github.com/void-robotics/void-ignition/blob/main/GIF_ROS-IGN.gif)
