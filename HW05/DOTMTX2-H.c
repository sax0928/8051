//   檔名:DOTMTX2.C
//   配合"8*8彩色點矩陣LED實習板"
//   在8*8彩色點矩陣LED上依序顯示三種顏色的中文字---"大"
//
//      色彩說明 P0 P2
//                0  0        黃
//                0  1        紅
//                1  0        綠
//                1  1        不亮
// 作業改成 一個大 但以三種顏色組成 2紅-3綠-2黃

#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sDelay.h"
unsigned char code dai[]= { 0xdd,0xdb,0xd7,0x0f,0xd7,0xdb,0xdd,0xff} ;  //建立資料表 dai
#define BASEINT 10                      //巨集 定義 BASEINT = 25
#define INTERVAL1       BASEINT*1       //巨集 定義 INTERVAL1 = BASEINT * 1 = 25 * 1 = 25
#define INTERVAL2       BASEINT*2       //巨集 定義 INTERVAL2 = BASEINT * 2 = 25 * 2 = 50
#define INTERVAL3       BASEINT*3       //巨集 定義 INTERVAL3 = BASEINT * 3 = 25 * 3 = 75

delay3ms()                              //呼叫延遲 3 毫秒之副程式
{
        Delay1ms() ;            //呼叫延遲 1 毫秒副程式
        Delay1ms() ;            //呼叫延遲 1 毫秒副程式
        Delay1ms() ;            //呼叫延遲 1 毫秒副程式
}
main()
{       char idx ;              //宣告字元變數 idx
        unsigned char com ;     //宣告無號數字元變數 com
        unsigned int interval ; //宣告無號數整數變數 interval
        unsigned char color ;   //宣告無號數字元變數 color ,color=0(紅)color=1(綠),color=2(黃)
        idx=0 ;                 //令 idx = 0
        com=0x80 ;              //令 com = 0x80
        interval=0 ;            //令 interval = 0
        color=0 ;               //令 color = 0
        for( ; ;){
            P1=0xff ;                           //使矩陣LED全熄滅
            if((color== 0) || (color== 2)){     //若color=0(紅)或color=2(黃) 則
                P0=dai[idx] ;                   //取得資料表中第 idx 筆資料,並輸出至P0
            }
            else{
                P0=0xff ;                       //否則 P0 輸出 11111111
            }
            if((color == 1) || (color== 2)){    //若color=1(綠)或color=2(黃) 則
                P2=dai[idx] ;                   //取得資料表中第 idx 筆資料,並輸出至P2
            }
            else{
                P2=0xff ;                       //否則 P2 輸出 11111111
            }
            idx++ ;                             //idx 加 1,以取得下一筆資料
            P1=~com ;                           //配合P0資料輸出,啟動行位址(P1.7 ~ P1.0)
            com >>=1 ;                          //右移一行位址
                                    
                                
                                  
                                
            
                                                //延遲時間
            if(idx ==  2){         //idx 到2時 換顏色
                color=1 ;                       //設 color = 1 轉換成綠色
            }
            else if(idx == 5){     //idx 到5時 再換顏色
                color=2 ;                       //設 color = 2 轉換成黃色
            }
            else if(idx == 8){     //idx 到8時 換顏色
                idx=0 ;                    //設 interval = 0 重新計算延遲時間
                color=0 ;         //顏色回到紅色
                com=0x80 ;      //com 回到第一個
            }
            delay3ms() ;                        //呼叫延遲 3 毫秒副程式
        }
}
