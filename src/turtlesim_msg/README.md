# turtlesim_msg

I am going to introduce how to create turtlesim_msg pacakge to you. You can follow my steps or just download and run it.

## Principle
![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mccI8vUJjTUl76edME61C8GB9HkfucY9BZIcKur90nYCxAToKCqk2MWVOwYLCV8Ij0EkIWjQ2.l4Tia66rDmvfBk!/b&bo=bQUVA20FFQMDGTw!&rf=viewer_4)

Here, I create two nodes. One is **/showInfo**, which is used to get the turtle's pose. In addition, I also define a message to record the name of turtle, x-axis coordinate, y-axis coordinate and the sum of x value and y value. In order to learn about service communication, I create another node called **/add_two_floats_server**. You can notice that there is no line between **/showInfo** and **/add_two_floats_server**, but they really communicate with each other. It's the different between topic communication and service communication.

## Step 1: Create package

`$ cd ./turtlesim/src`

`$ catkin_create_pkg turtlesim_msg roscpp rospy std_msgs turtlesim`

## Step 2: Create a custom message and service

`$ cd ./turtlesim_msg`

`$ mkdir msg`

`$ cd ./msg`

`$ touch Info.msg`

Then, you should edit the *Info.msg* file. Please check mine. Next, create a service file.

`$ cd ./src/turtlesim_msg`

`$ mkdir srv`

`$ cd ./srv`

`$ touch AddTwoFloats.srv`

You should also edit the *AddTwoFloats.srv* file. Please check mine.

## Step 3: Edit configuration files

*package.xml* file and *CMakefile.txt* file are showed below. It's different from turtlesim_name and turtlesim_tf package. Be careful about the meessage_generation and message_runtime dependencies and another configuration.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mccI8vUJjTUl76edME61C8GCyWa4PA3SdXfhtT1bQ4lVRA2.HW*tLv*bViFnJ350N6KOYKYoCuVOdOxpHF0NrTro!/b&bo=LATdAiwE3QIDGTw!&rf=viewer_4)

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mceSJBgvIe3fDR9i86A..uJRtiyxLBskpAQWrFiLbWZnPXFv5yXFmoGzSbLV*Y0CNFEMMRNUDmAioeYezXa5KoQI!/b&bo=LATeAiwE3gIDGTw!&rf=viewer_4)

After finishing it, run the following command to complie them.

`$ cd ~/turtlesim`

`$ catkin_make`

And then, you can check the result, which will show you the format of the message and service.

`$ rosmsg show turtlesim_msg/Info`

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mccI8vUJjTUl76edME61C8GCXgHA6m8cW*0xRpGEaU84VH.Iofg6ZSXcV481jrnPUYCh87ZAKtgIeur43gf5tmKc!/b&bo=3gLoAd4C6AEDGTw!&rf=viewer_4)

`$ rossrv show turtlesim_msg/AddTwoFloats`

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mccI8vUJjTUl76edME61C8GCbO313EmgjPGldn9mONVygZyfmLHsG*hTbairPzaGaU1KaIVJRkkmu8YEarVVxNgg!/b&bo=3gLoAd4C6AEDGTw!&rf=viewer_4)

## Step 4: Write cpp files

`$ cd ./src/turtlesim_msg/src`

`$ touch add_two_floats_server.cpp`

`$ touch showInfo.cpp`

You should copy my code to these files. These two cpp files contains a lot of knowledge about how to use custom message and services. In my project, I don't send the message to another node. In actual use, custom messages are used for node-topic communication to facilitate the transmission of a group of data at one time.

After coding, you should edit *CMakefile.txt* file to generate executable files and link libraries.

`add_executable(add_two_floats_server src/add_two_floats_server.cpp)`

`target_link_libraries(add_two_floats_server ${catkin_LIBRARIES})`

`add_executable(showInfo src/showInfo.cpp)`

`target_link_libraries(showInfo ${catkin_LIBRARIES})`

At last, use `catkin_make` to check them.

`$ cd ~/turtlesim`

`$ catkin_make`

## Step 5: Run the files

[Here is a video](https://www.bilibili.com/video/BV1ao4y1f7pZ/) shows you how to run them. Before running them, you should run `$ roscore`, `$ rosrun turtlesim turtlesim_node`, `$ rosrun turtlesim turtle_teleop_key` at first.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcTWhcXs5eYxTuke8xyxKGx0WvJLrhTWrKzv2cbKZGY9qtpAySH2ewLYa1yVQlh*5PGXABOmTzRtzKGP*O2aYjX8!/b&bo=CAYjBAAAAAABJyk!&rf=viewer_4)
