//  �ɦW:KEY2.C
//  �t�X"�����ߪO"
//  �t�X�Ѽu��(debounce)���{���]�p
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"

sbit KEY1=P1^0 ;	//�w�q KEY1 ���� P1.0
void delay20ms()	//�I�s���� 20 �@�����Ƶ{��
{
 Delay10ms();	//�I�s���� 10 �@���Ƶ{��
 Delay10ms();	//�I�s���� 10 �@���Ƶ{��
}

main()				//�D�{��
{
 P0=0 ;				//��LED������
 for(;;)
  {
    do
    {
    while(KEY1 ==1) ;	//���L�����,�|���b��a,�Y������U�h���U��������u��
    delay20ms() ;	//�I�s���� 20 �@���Ƶ{��(�����u����)
    }
    while(KEY1 == 1) ;	//�Y KEY1 ���� 1 ���ܬO���T,�h�^�W���� do �~�����
			//�Y KEY1 �� 0 �h���ܫ��䦳���U
    P0++;		//������U�@���h P0 �֥[�@��

    do
    {
      while(KEY1==0) ;	//�P�_����O�_��},�Y�S��}�h�|���b��a,�Y��}�h���U��������u��
      delay20ms() ;	//�I�s���� 20 �@���Ƶ{��(�����u��)
    }
    while(KEY1== 0) ;	//�Y KEY1 ���� 0 ���ܬO���T,�h�^�W���� do �~�����
			//�Y KEY1 �� 1 ���ܫ��䦳��}
  }
}