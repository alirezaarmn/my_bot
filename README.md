## Robot Package Template

This is a GitHub template. You can make your own copy by clicking the green "Use this template" button.

It is recommended that you keep the repo/package name the same, but if you do change it, ensure you do a "Find all" using your IDE (or the built-in GitHub IDE by hitting the `.` key) and rename all instances of `my_bot` to whatever your project's name is.

if you use "--symlink-install" argument then you won't need rebuild every time update the `uidf` file. It'll handle that automatically except for whenever you add a new file
```
colcon build --symlink-install
```