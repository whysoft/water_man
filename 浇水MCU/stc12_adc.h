
//2017-02-06

#ifndef __H_STC12_ADC_H
#define __H_STC12_ADC_H


extern void InitADC(unsigned char ch_map);          // �����ͨ���б���8��λ����ʾ������������ͨ���� 

extern unsigned int GetADCResult(unsigned char ch);	// 0��7	��8��ͨ����һ��ֻ�ܼ���һ��ͨ�����ұ����ǳ�ʼ��ʱͨ���б�֮�е�ͨ���� 

unsigned char GetADCResultU8(unsigned char ch);	// 


#endif
