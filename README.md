## Robot Package Template

This is a GitHub template. You can make your own copy by clicking the green "Use this template" button.

It is recommended that you keep the repo/package name the same, but if you do change it, ensure you do a "Find all" using your IDE (or the built-in GitHub IDE by hitting the `.` key) and rename all instances of `my_bot` to whatever your project's name is.

if you use "--symlink-install" argument then you won't need rebuild every time update the `urdf` file. It'll handle that automatically except for whenever you add a new file
```
colcon build --symlink-install
```

```
ros2 launch my_bot launch_sim.launch.py
```

you can publish topic like this
```
ros2 topic pub --once /cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}"
```

manipolation with joint and tf
```
ros2 run joint_state_publisher_gui joint_state_publisher_gui
```