
## ��·�屳����Ϣ

```
��ˮ���壬�� 
 
���� ASTROCLK_V02

�� stc15f2k60s2  
@24M
```

 

=================================
ָ��
c0 <freq_high> <freq_low> <delay_high> <delay_low>
����OK\n\r
freq=0�Ǿ���

c1 00 00 00 00
�����ͨ
����OK\n\r


c2 00 00 00 00
����Ͽ�
����OK\n\r


c3 00 00 00 00
��ѯ����ֵ
�����ַ�����ʽ�ǣ�
num1,num2\n\r
����num1��0��1023�Ĳ���ֵ������ʪ�ȵ�����
num2��0��1�Ĳ���ֵ������ʪ�ȱ���·������Ľ���
num2��������ֵ���Ե��ڡ�


echo -e -n "\xc0\x00\x21\x01\x0a">/dev/ttyS2
echo -e -n "\xc0\x00\x41\x01\x0a">/dev/ttyS2
echo -e -n "\xc0\x00\x71\x01\x0a">/dev/ttyS2
stty -F /dev/ttyS2 -a
stty -F /dev/ttyS2 ispeed 57600 ospeed 57600 cs8

echo -e -n "\xc2\x00\x21\x01\x0a">/dev/ttyS2
