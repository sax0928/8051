//  �ɦW:ADC1.C
//  �t�X"ADC0804��ߪO"
//  Ū��ADC0804������q����(�ĥΩ���覡�ӦP�B),�ñN����ܩ�8��LED�W
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
sbit ADCRD=P1^0 ;	//�]�wP1.0���}�W�٬�ADCRD
sbit ADCWR=P1^1 ;	//�]�wP1.1���}�W�٬�ADCWR
 void delay150us()	//����150�L�����禡
{
        int i=0 ;		//��l�]�wi=0
        for(i=0;i<18;i++) ;	//�֥[18��
}

 main()
{
     for(;;)
     {			//start ADC
       ADCWR=0 ;	//�]�wADCWR(�g�J)�H���H�Ұ�ADC�ഫ
       ADCWR=1 ;	//�M��ADCWR(�g�J)�H��
       delay150us() ;	//�I�s����150us
       ADCRD=0 ;	//�]�wADCRD(Ū�X)�H���HŪ���ഫ���G��
       P2=P0 ;		//P0��J���Ȱe��P2��LED��ܼƦ��
       ADCRD=1 ;	//�M��ADCRD(Ū�X)�H��
     }
}