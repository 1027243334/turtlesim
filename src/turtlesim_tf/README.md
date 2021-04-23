# turtlesim_tf

I am going to introduce how to create turtlesim_tf pacakge to you. You can follow my steps or just download and run it.

## Principle

![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mcZxMkC8aCSQSaIAvXUz1wBIH7EoH*ruCs.WPujmzlIGuP9eOFtI3FWO*GF1yj6geu0vgy20pfAuvdAehooKGF*o!/b&bo=bQUVA20FFQMDGTw!&rf=viewer_4)

Two **turtle_tf_broadcaster nodes** broadcast the coordinate transformation of turtle1 and turtle2 relative to the world coordinate system. The **listener** listens to the coordinate transformation between turtle1 and turtle2, and then uses the **keyboard node** to control the movement of turtle1, then, turtle2 follows the movement of turtle1.
