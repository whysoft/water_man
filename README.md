
## 电路板背景信息

```
浇水主板，用 
 
板用 ASTROCLK_V02

用 stc15f2k60s2  
@24M
```



## orange pi zero
```
串口使用 /dev/ttyS2, 57600, 向主板发指令和获取信息。 
例如：
stty -F /dev/ttyS2 ispeed 57600 ospeed 57600 cs8
用无线串口调试 orange pi zero
```



## 用电器规范
```
外接电器的功率不可高于80W。
插头上有“16”字样的一侧推荐接火线，以提高安全度。
```




## 指令集

### 发出声音
```
c0 <freq_high> <freq_low> <delay_high> <delay_low>
返回OK\n\r
freq值越小频率越高
注意：delay值不要过大，因为执行完delay才会返回OK。
例如（伪码）
echo -e -n "\xc0\x00\x21\x01\x0a">/dev/ttyS2
wait for OK\n\r
echo -e -n "\xc0\x00\x41\x01\x0a">/dev/ttyS2
wait for OK\n\r
echo -e -n "\xc0\x00\x71\x01\x0a">/dev/ttyS2
wait for OK\n\r
```


### 通电指令
```
c1 00 00 00 00
命令接通
返回OK\n\r
指令后插座对外提供220V市电。
```


### 断电指令
```
c2 00 00 00 00
命令断开
返回OK\n\r
指令后插座停止对外供电。
```


### 查询指令
```
c3 00 00 00 00
查询采样值
返回字符串格式是：
num1,num2\n\r
其中num1是0至1023的采样值，代表湿度的评估，用户可以在程序逻辑中判断和决策。
num2是0或1的采样值，代表湿度被电路评估后的结论，num2的评估阀值可以调节，
在采样模块上有一个微型可调电阻，调节它可以改变电路上的比较器的工作参数，
建议在湿度刚好适当时调节它使得湿度高于和低于时能得到不同的值。
例如返回1023，1
```



## 常用指令例子
```
stty -F /dev/ttyS2 -a
stty -F /dev/ttyS2 ispeed 57600 ospeed 57600 cs8

echo -e -n "\xc0\x00\x21\x01\x0a">/dev/ttyS2
echo -e -n "\xc0\x00\x41\x01\x0a">/dev/ttyS2
echo -e -n "\xc0\x00\x71\x01\x0a">/dev/ttyS2

echo -e -n "\xc2\x00\x21\x01\x0a">/dev/ttyS2
```


