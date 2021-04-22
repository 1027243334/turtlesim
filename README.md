# turtlesim
It's my first project to learn ROS. Download and play with turtlesim workspace, which includes some packages developed to learn the turtlesim_node. Please enjoy it.

Now, I am going to introduce ./src/turtlesim_name pacakge to you for a better understanding. You can follow my steps to create another one.


## Principle
Create the **draw_my_name** node and publish the message to the topic **turtle1/cmd_vel**. And create the **turtle1** node and subscribe to the topic **turtle1/cmd_vel**(automatically subscribed when created). The message published by the **draw_my_name** node is implemented by compiling the demo.cpp file and Cmakelist.txt file, covered in a later tutorial. The node-topic communication method is used to make the turtle follow the predetermined route and the three letters **PRT** are drawn.


## Step 1
![pic](https://raw.githubusercontent.com/linux-downey/bloc_test/master/picture/Makedown/Makedown.png)
