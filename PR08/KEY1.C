//  �ɦW:KEY1.C
//  �t�X"�����ߪO"
//  ���䪺�u���{�H(bounce)
//
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
sbit KEY1=P1^0 ;	//�w�q KEY1 ���� P1.0
main()			//�D�{��
{
 P0=0 ;			//��LED������
 for(;;)
   {
   while(KEY1 ==1) ; //�Y�L�����,�|���b��a,�Y������U�h���U����
   P0++;	     //������U�@���h P0 �֥[ n ��(�]�����u������)
   while(KEY1==0) ;  //�P�_����O�_��},�S��}�|���b��a,�Y�����}�h�~�����
   }
}