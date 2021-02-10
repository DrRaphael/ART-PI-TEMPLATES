如何去配置你的STM32CubeIDE工程

1.设置PI9、PA0作为UART4的复用引脚，这对引脚是连接到ART-PI板载的STLink V2.1的串口的。

![image-20210210193733938](PIC/image-20210210193733938.png)

2.设置UART4串口，波特率为1152000Bits/s，这样你就可以和电脑通过串口通信了（还需要重映射printf函数，然后才能使用printf打印功能）

![image-20210210194204447](PIC/image-20210210194204447.png)