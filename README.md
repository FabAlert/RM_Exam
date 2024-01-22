# _Multi-robot system with Turtlebot and Kuka_Iiwa_

Simulation in an industrial environment in which Turtlebot must search for a tool represented by an aruco marker, and then bring it to the Kuka Iiwa. The second robot simulates the picking of the object and places it on another marker on the ground.

## Features

- The project shows the modularity of a multi-robot system
- Example of a service behaviour
- Insight on the usage of sensors 

## Getting Started (pre-requirements)

- Ubuntu 20.04
- ROS Noetic
- Gazebo 11

## Packages

This project uses some external packages provided by the University Course of Robotics Lab and the _aruco-ros_ package. 

## Install the packages

To install all the needed packages to run the simulation it is enough to clone this repository in the _src_ folder of your ros workspace and compile the packages with the following instructions:

```sh
$ git clone https://github.com/FabAlert/RL_Exam.git
$ cd ..
$ catkin_make catkin_make -DCATKIN_WHITELIST_PACKAGES="aruco"
$ catkin_make catkin_make -DCATKIN_WHITELIST_PACKAGES="aruco_msgs"
$ catkin_make catkin_make -DCATKIN_WHITELIST_PACKAGES="aruco_ros"
$ catkin_make catkin_make -DCATKIN_WHITELIST_PACKAGES="rl_project_cuccaro"

```
## Prepare and run the simulation

On different terminals launch the following commands:

- Start the roscore:

```sh
$ roscore
```

- Launch the main node:

```sh
$ roslaunch rl_project_cuccaro scenario_multiple_robots.launch
```


- Start the client node: 

```sh
$ rosrun rl_project_cuccaro movebase_client
```

If you want to visualize the images on the camera sensors you can use the tool from ROS:

```sh
$ rqt_image_view
```
If you want to manually control the turtlebot movement:

```sh
$ rosrun rl_project_cuccaro key_teleop
```

## Output on image_view

- /aruco_marker_publisher/result: the topic on which the images from the turtlebot camera are streamed;
- /kuka_iiwa/aruco_marker_publisher_kuka_iiwa/result: the topic on which the images from the kuka iiwa camera are streamed.

## Outline

![Client terminal results](/Images_for_readme/terminale.png)  
![Gazebo results](/Images_for_readme/final.png) 
