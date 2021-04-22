# turtlesim
It's my first project to learn ROS. Download and play with turtlesim workspace, which includes some packages developed to learn the turtlesim_node. Please enjoy it.

Now, I am going to introduce ./src/turtlesim_name pacakge to you for a better understanding. You can follow my steps to create another one.


## Principle
First, create the **draw_my_name** node and publish the message to the topic **turtle1/cmd_vel**. And then create the **turtle1** node and subscribe to the topic **turtle1/cmd_vel** (automatically subscribed when created). 
![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZsqEWHjgbXMo1XWKAP0Y7jdTkiJyO3vePJgZw7UHcQW4nv31zuLS1hVIqlGLrMp8LoU0K2aCaR.RP*L9JxuI1I!/b&bo=HQXCAQAAAAABF.s!&rf=viewer_4)

The message published by the **draw_my_name** node is implemented by compiling the demo.cpp file and Cmakelist.txt file, covered in a later tutorial. This is node-topic communication method, which can make the turtle follow the predetermined route and the three letters **PRT** will be drawn.



## Step 1
