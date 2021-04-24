# turtlesim_msg

I am going to introduce how to create turtlesim_msg pacakge to you. You can follow my steps or just download and run it.

## Principle
![pic](http://m.qpic.cn/psc?/V53W2FkB1yOtnS25GEyd38amA54P7fxq/45NBuzDIW489QBoVep5mccI8vUJjTUl76edME61C8GB9HkfucY9BZIcKur90nYCxAToKCqk2MWVOwYLCV8Ij0EkIWjQ2.l4Tia66rDmvfBk!/b&bo=bQUVA20FFQMDGTw!&rf=viewer_4)

Here, I create two nodes. One is **/showInfo**, which is used to get the turtle's pose. In addition, I also define a message to record the name of turtle, x-axis coordinate, y-axis coordinate and the sum of x value and y value. In order to learn about service communication, I create another node called **/add_two_floats_server**. You can notice that there is no line between **/showInfo** and **/add_two_floats_server**, but they really communicate with each other. It's the different between topic communication and service communication.

## Step 1: Create package


## Step 2: Create a custom message and service


## Step 3: Edit configuration files

## Step 4: Write cpp files


## Step 5: Run the files

