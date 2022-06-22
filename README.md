# Task: Using the Lidar Node


First setup ROS2 and Gazebo ignition. Follow these instructions

https://docs.ros.org/en/foxy/Installation.html
https://gazebosim.org/docs/citadel

Once the setup is complete 
Clone the repo

## Using Lidar Sensor

Follow these commands to build a ROS2 package to run lidar Node

```
source /opt/ros/<distro>/setup.bash

mkdir void-ignition/src

cd src

ros2 pkg create --build-type ament_cmake --node-name lidar_node <package name>

**Copy the code from the Cmake list provided into the Cmake list of the package you just Created**
**Copy the code of the lidar_node.cpp into my_node.cpp file inside your package src folder** 

<!-- Build the package -->

cd ~/void-ignition 

colcon build

```

Run the package 

```
 . /install/setup.bash

 ros2 run <package name> lidar_node

```


Download the sensors_demo.sdf file in your system and run it

```
ign gazebo sensors_demo.sdf
```

#### Make sure the simulation is not paused. 
#### You will see the robot first moving forward and once it is 1 meter away from the wall it will try to avoid it by changing direction.

#### References
https://gazebosim.org/docs/citadel/sensors

https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html


#  Task: Using ROS_IGN_bridge to move robot in Gazebo

Follow these instructions to setup ROS ignition bridge.

https://github.com/gazebosim/ros_gz/tree/foxy#binaries


## Create a ROS2 to IGN bridge
#### Open terminal: A
```
ros2 run ros_ign_bridge parameter_bridge /cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist
```

## Run the simulation
#### Open new terminal: B

```
ign gazebo sensors_demo.sdf
```

## Publishing message to ign through ROS2 using the ign bridge
#### Open new terminal: C

```
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "{linear: {x: -1.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.8}}"
```

You would now see the robot moving in the gazebo world.

Note: Make sure the gazebo ignition is not paused

#### References:

https://github.com/gazebosim/ros_gz/blob/ros2/ros_ign_bridge/README.md#example-1a-ignition-transport-talker-and-ros-2-listener

https://gazebosim.org/docs/citadel/ros2_integration


