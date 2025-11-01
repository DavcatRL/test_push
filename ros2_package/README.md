# ros2_package

## :package: About

This package contains the tutorial code to create and run your first publisher and subscriber node using C++ with custom interfaces.

Created following [ROS 2 Documentation](https://docs.ros.org/en/humble/Tutorials/Beginner-Client-Libraries/Custom-ROS2-Interfaces.html)

## :hammer: Build
Clone this package in the `src` folder of your ROS 2 workspace. Check for missing dependencies
```
$ rosdep install -i --from-path src --rosdistro humble -y
```
Build your new package
```
$ colcon build --packages-select ros2_package
```
Source the setup files
```
$ . install/setup.bash
```

## :white_check_mark: Usage
Run the talker node
```
$ ros2 run ros2_package talker
```
Open another terminal, source the setup files, and then start the listener node
```
$ ros2 run ros2_package listener
```
You can run the two nodes together via the launch file
```
$ ros2 launch ros2_package ros2_package_launch.xml
```