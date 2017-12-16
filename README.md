
## 电路板背景信息

```
浇水主板，用 
 
板用 ASTROCLK_V02

用 stc15f2k60s2  
@24M
```

 

=================================
指令
c0 <freq_high> <freq_low> <delay_high> <delay_low>
返回OK\n\r
freq=0是静音

c1 00 00 00 00
命令接通
返回OK\n\r


c2 00 00 00 00
命令断开
返回OK\n\r


c3 00 00 00 00
查询采样值
返回字符串格式是：
num1,num2\n\r
其中num1是0至1023的采样值，代表湿度的评估
num2是0或1的采样值，代表湿度被电路评估后的结论
num2的评估阀值可以调节。


echo -e -n "\xc0\x00\x21\x01\x0a">/dev/ttyS2
echo -e -n "\xc0\x00\x41\x01\x0a">/dev/ttyS2
echo -e -n "\xc0\x00\x71\x01\x0a">/dev/ttyS2
stty -F /dev/ttyS2 -a
stty -F /dev/ttyS2 ispeed 57600 ospeed 57600 cs8

echo -e -n "\xc2\x00\x21\x01\x0a">/dev/ttyS2
