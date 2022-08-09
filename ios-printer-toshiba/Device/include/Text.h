//
//  Text の概要の説明です。
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


#import "Figure.h"

@class BarSet;
@class ComStruct;
@class IntRef;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Text : Figure {
@public
    IntRef *m_PrnPosX_;                 // 始点位置 X
    IntRef *m_PrnPosY_;					// 始点位置 Y
    long BackHeight_;                   // 文字背景高さ
    long BackWidth_;		            // 文字背景幅
    long charlen_;                      // 桁数
    long yDoubleStrike_;       		    // 強調Y方向
    long xDoubleStrike_;                // 高調X方向
    long kyou_;                         // 強調設定
    char Back_;                         // 文字背景指定文字(ｺﾏﾝﾄﾞ文字列)
    long RotateString_;                 // 文字列回転
    long RotateChar_;                   // 文字回転
    long rotayLine_;                    // 文字列回転
    long rotaChar_;                     // 文字回転
    
    char cData_;                        // 挿入文字
    char cTop1_;                        // 先頭表示文字
    long iDelimita_;                    // ｶﾝﾏ編集
    long iDecimal_;                     // 小数点編集ﾞ
    char iCheckDigit_;                  // ﾁｪｯｸﾃﾞｼﾞｯﾄ種類
    long Increment_;                    // ｲﾝｸﾘﾒﾝﾄ
    BOOL NumFlag_;                      // 文字編集ﾌﾗｸﾞ
    long Interval_;                     // 文字間
    long DrawFlag_;                     // 文字位置
    long CharType_;                     // 文字種類(半角、全角、半全混合)
    long ZeroSup_;                      // ｾﾞﾛｻﾌﾟﾚｽ
    NSString *ySize_;                   // 文字倍率高さ(ｺﾏﾝﾄﾞ文字列)
    NSString *xSize_;                   // 文字倍率幅(ｺﾏﾝﾄﾞ文字列)
    
    NSString *Font_;                    // ﾌｫﾝﾄ指定(ｺﾏﾝﾄﾞ文字列)
    long selectFont_;                   // 文字種類(ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄorｱｳﾄﾗｲﾝﾌｫﾝﾄ)
    // <<<<< 2018-02-23 TIS Open Type Font addition >>>>>
    NSString *OtfFileName_;
    long OtfFileExt_;
    long OtfDrive_;
    long OtfDirection_;
    // <<<<< 2018-02-23 TIS Open Type Font addition >>>>>
}

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 * @param p_in ProfileInterfaceのインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

/**
 * ｵﾌﾞｼﾞｪｸﾄ種類判断
 */
- (long)CheckObjID;

/**
 * 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ
 */
- (long)GetSendDataSize;

/*
 *  関数名   : GetSendFormatSize
 *  機能     : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
 *  機能説明 : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
 *  返り値   : 送信ﾌｨｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ
 *  備考     :
 */
- (long)GetSendFormatSize;

/**
 *  関数名   : LoadFigure
 *  機能     : ｵﾌﾞｼﾞｪｸﾄの読み込み
 *  機能説明 : 指定されたｵﾌﾞｼﾞｪｸﾄの読み込み
 *  返り値   : 成功：TRUE、失敗：FALSE
 *  備考     :
 */
- (BOOL)LoadFigure:(long)iCnt      // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName;    // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/*
 *  関数名   : SetDataCommand
 *  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 *  機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 *  返り値   : 成功：TRUE、失敗：FALSE
 *  備考     :
 */
- (BOOL)SetDataCommand:(long)iCode
             withTrans:(TRANSBLOCK *)wpTrans
            withBarSet:(BarSet *)Barset
         withComStruct:(ComStruct *)pCom;

/**
 *  関数名   : SetFormatCommand
 *  機能     : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 *  機能説明 : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 *  返り値   : 成功：TRUE、失敗：FALSE
 *  備考     :
 */
- (BOOL)SetFormatCommand:(long)iCode          // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK *)pTrans // 送信ﾌﾞﾛｯｸ
              withBarSet:(BarSet *)Barset     // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct *)pCom;   // 通信設定

#pragma mark Protected

/**
 * 始点位置の計算
 * @param pPosX 計算された始点X
 * @param pPosY 計算された始点Y
 * @param pFontX ﾌｫﾝﾄの大きさ
 * @param pFontY ﾌｫﾝﾄの大きさ
 */
- (void)CharTurnPos:(IntRef *)pPosX            // 計算された始点
           withPosY:(IntRef *)pPosY            // 計算された始点
          withFontX:(long)pFontX               // ﾌｫﾝﾄの大きさ
          withFontY:(long)pFontY;              // ﾌｫﾝﾄの大きさ

/**
 * ﾃﾞｰﾀの編集
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)DecorateCharField;

/**
 * ｱｳﾄﾗｲﾝﾌｫﾝﾄﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param pPointX 始点X
 * @param pPointY 始点Y
 * @param pTrans 送信ﾌﾞﾛｯｸ
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)OutLineFontFormat:(long)pPointX       // 始点
               withPointY:(long)pPointY       // 送信ﾌﾞﾛｯｸ
                withTrans:(TRANSBLOCK *)pTrans;

/**
 *  ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param pPointX 始点X
 * @param pPointY 始点Y
 //		 * @param pTrans 送信ﾌﾞﾛｯｸ
 * @return
 */
- (BOOL)RasterFontFormat:(long)pPointX
              withPointY:(long)pPointY
               withTrans:(TRANSBLOCK *)pTrans;

/**
 * ﾃﾞｰﾀﾚﾝｸﾞｽをﾌｫｰﾏｯﾄの桁数に合わせる
 */
- (void)SetCharPosition;

@end
