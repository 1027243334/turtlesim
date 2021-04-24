# turtlesim_name
I am going to introduce how to create turtlesim_name pacakge to you. You can follow my steps or just download and run it.

## Principle
Create the **draw_my_name** node and publish the message to the topic **turtle1/cmd_vel**. And then create the **turtle1** node and subscribe to the topic **turtle1/cmd_vel** (automatically subscribed when created). 
![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZsqEWHjgbXMo1XWKAP0Y7jdTkiJyO3vePJgZw7UHcQW4nv31zuLS1hVIqlGLrMp8LoU0K2aCaR.RP*L9JxuI1I!/b&bo=HQXCAQAAAAABF.s!&rf=viewer_4)

The message published by the **draw_my_name** node is implemented by compiling the *demo.cpp* file and *CMakelist.txt* file, covered in a later tutorial. This is node-topic communication method, which can make the turtle follow the predetermined route and draw the three letters **PRT** on the plant.

## Step 1: Create Workspace
`$ mkdir -p ~/turtlesim/src `

The *turtlesim* folder is generated under the *home* directory and the *src* folder is generated within the *turtlesim* folder.

`$ cd ~/turtlesim/`

`$ catkin_make`

The first time you run it in your workspace, a *CMakelists.txt* file is created in the *src* folder. In addition, *build* and *devel* folders will be generated in the current directory.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZ4u9lod5A0RGiMbl*jDuQb.hMqXcgWJ5qPrQ69C3chNDM.j7h.OjjdMUfHPmGpUqciWwYOIkZx*kFpgAHhqz*A!/b&bo=egMXAnoDFwIDGTw!&rf=viewer_4)

## Step 2: Create Package
`$ cd ~/turtlesim/src`

`$ catkin_create_pkg turtlesim_name std_msgs rospy roscpp`

(Format for catkin_create_pkg <package_name> [depend1] [depend2] [depend3])

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZ4u9lod5A0RGiMbl*jDuQaOBvBRd*MH8h*Iw98SEFKjA90AedzWuJeKS76RRol.VbEknahn7Yo7aoxnMxmozyk!/b&bo=egMXAnoDFwIDGTw!&rf=viewer_4)

## Step 3: Write cpp files and edit configuration files
`$ cd ~/turtlesim/src/turtlesim_name/src`

`$ touch demo.cpp`

This file wiritten code is to control the turtle movement. The code can refer to my *demo.cpp* file.

Then, as follows, modify the *CMakelists.txt* file.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcahBevoIg066oyla.RCWLaPpBQxqgpzyQdRFQKPkAvf*ukdJeAsM5SssH3ix.oBfNRpEXKQsT5NcuVUGYYTdiFw!/b&bo=hAPmAoQD5gIDGTw!&rf=viewer_4)

At last, modify the *package.xml* file.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcahBevoIg066oyla.RCWLaNo9mlE8FUAMoNxjlNQwIE3isQp.Tppg.w*I5ReMGY6LzXujBEWluLnuZyl3lYS6Hk!/b&bo=hAPmAoQD5gIDGTw!&rf=viewer_4)

Then, use catkin_make to compile the *demo.cpp* file.

`$ cd ~/catkin_ws`

`$ catkin_make`

If there are some errors, you can correct the error as prompted. After modifying, you can run the command again. While the it is completed to **100%**, you succeed.

Finally, change your path to *turtlesim workspace*, then, open three terminals and type in the following command and run them one by one. (If there are some errors indicate files can not be found, you should run the commond `$ devel/setup.bash` at first.)

`$ roscore`

`$ rosrun turtlesim turtlesim_node`

`$ rosrun turtlesim_name turtlesim_name`

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcahBevoIg066oyla.RCWLaMaGChLzrQCNEO6G3xrCPIn8h1DjYLWpeOeuOP1hsjK27d99pzcdMFctk9jlj7Tcc0!/b&bo=gAc4BIAHOAQDORw!&rf=viewer_4)

[Here is the video](https://www.bilibili.com/video/BV13p4y1b7ya) showed the movement effect.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcRHgcXXNu0QQn5BD5Hz73Q1qKHGCkpmLiGXnQs*M9E.BhgGbvSqKEU3XtdWHfYBBwiB0aMQuszqNhdt8PvPd9No!/b&bo=vwHQAQAAAAABF18!&rf=viewer_4)
