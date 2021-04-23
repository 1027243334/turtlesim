# turtlesim_tf

I am going to introduce how to create turtlesim_tf pacakge to you. You can follow my steps or just download and run it.

## Principle

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZxMkC8aCSQSaIAvXUz1wBIH7EoH*ruCs.WPujmzlIGuP9eOFtI3FWO*GF1yj6geu0vgy20pfAuvdAehooKGF*o!/b&bo=bQUVA20FFQMDGTw!&rf=viewer_4)

Two **turtle_tf_broadcaster nodes** broadcast the coordinate transformation of turtle1 and turtle2 relative to the world coordinate system. The **listener** listens to the coordinate transformation between turtle1 and turtle2, and then uses the **keyboard node** to control the movement of turtle1, then, turtle2 follows the movement of turtle1.

## Step 1: Create package

Refer to *turtlesim_name* package to create *turtlesim_tf* package.

`$ cd ./turtle/src`

`$ catkin_create_pgk roscpp rospy std_msgs tf turtlesim`

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcd*etHiSksihcYCiZDUPRJEacSW3dBphZQmDUcJ3YxFWqhc4EwHb9SkxZ.6r99cXKJfOskB8Z46yauflBmMbmrs!/b&bo=egMUAnoDFAIDGTw!&rf=viewer_4)

## Step2: Edit configuration files
First, create two files, *turtle_tf_broadcaster.cpp* and *turtle_tf_listener.cpp*. The previous file is used to broadcast the coordinates of the turtle, and the latter file is used to monitor the coordinate transformation between the two turtles. Code analysis has been annotated in the file, please check it yourself.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcd*etHiSksihcYCiZDUPRJEu3pI2pFZW5uR6Fw*4YtDnmj0EMyEH3A5ULmxWmxo4lEGkP6N3.cpJGzLDDMmZ.yo!/b&bo=egMUAnoDFAIDGTw!&rf=viewer_4)

Second, edit *CMakefile.txt* file.

Third, edit *package.xml file*.

Please check them according to the files I wrote.

At last, the most important is to create a start_tf.launch file, which is stored in */turtlesim_tf/launch* folder, which you should create by yourself.

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZxMkC8aCSQSaIAvXUz1wBLFKe2Gj6X55Pf3SaWmNTSXASNab0ZN6GdWvnA6vIxq42vS7xdHyUTwUH.NKSD24RA!/b&bo=egMUAnoDFAIDGTw!&rf=viewer_4)
