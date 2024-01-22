# _Admittance control with Kuka LBR-Med 7_

Simulation in a Gazebo environment in which Kuka LBR-Med 7 robot follows the desired trajectory through an admittance control.

## Getting Started (pre-requirements)

- Ubuntu 20.04
- ROS Noetic
- Gazebo 11


## Install the packages

To install all the needed packages to run the simulation it is enough to clone this repository in the _src_ folder of your ros workspace and compile the packages with the following instructions:

```sh
$ git clone https://github.com/FabAlert/RL_Exam.git
$ cd ..
$ catkin_make
```
## Prepare and run the simulation

On different terminals launch the following commands:

- Start the roscore:

```sh
$ roscore
```

- Launch the main node:

```sh
$ roslaunch rm_kuka_project iiwa7_upload.launch
```


- Start the client node: 

```sh
$ rosrun rm_kuka_project controllo_forza 
```

## Outline

![Client terminal results](/Images_for_readme/terminale.png)  
![Gazebo results](/Images_for_readme/final.png) 
