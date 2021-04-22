# turtlesim
It's my first project to learn ROS. Download and play with turtlesim workspace, which includes some packages developed to learn the turtlesim_node. Please enjoy it.

Now, I am going to introduce ./src/turtlesim_name pacakge to you for a better understanding. You can follow my steps to create another one.


## Principle
First, create the **draw_my_name** node and publish the message to the topic **turtle1/cmd_vel**. And then create the **turtle1** node and subscribe to the topic **turtle1/cmd_vel** (automatically subscribed when created). 
![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZsqEWHjgbXMo1XWKAP0Y7jdTkiJyO3vePJgZw7UHcQW4nv31zuLS1hVIqlGLrMp8LoU0K2aCaR.RP*L9JxuI1I!/b&bo=HQXCAQAAAAABF.s!&rf=viewer_4)

The message published by the **draw_my_name** node is implemented by compiling the *demo.cpp* file and *CMakelist.txt* file, covered in a later tutorial. This is node-topic communication method, which can make the turtle follow the predetermined route and the three letters **PRT** will be drawn.

## Step 1: Create Workspace
`$ mkdir -p ~/turtlesim/src `
The *turtlesim* folder is generated under the *home* directory and the *src* folder is generated within the turtlesim folder.

`$ cd ~/turtlesim/`
`$ catkin_make`
The first time you run it in your workspace, a *CMakelists.txt* file is created in the *src* folder. In addition, *build* and *devel* folders will be generated in the current directory.
![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZ4u9lod5A0RGiMbl*jDuQb.hMqXcgWJ5qPrQ69C3chNDM.j7h.OjjdMUfHPmGpUqciWwYOIkZx*kFpgAHhqz*A!/b&bo=egMXAnoDFwIDGTw!&rf=viewer_4)
