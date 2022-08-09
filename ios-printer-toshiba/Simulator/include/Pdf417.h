//
//  Pdf417オブジェクトクラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
#import "Figure.h"



@class BarRotate;
@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Pdf417 : Figure {
 @public
    BarRotate *m_BarRotate_;       // 回転情報
    char	iCheckDigit_;	       // ﾁｪｯｸﾃﾞｼﾞｯﾄ種類
    long	Increment_;	           // ｲﾝｸﾘﾒﾝﾄ
    long	Rotation_;	           // 回転
    long	Height_;	           // 1行のﾊﾞｰ高さ
    long	Rows_;	               // 1ﾓｼﾞｭｰﾙのﾄﾞｯﾄ数
    long	Col_;	               // ｶﾗﾑ数
    long	SccLevel_;	           // ｾｷｭﾘﾃｨﾚﾍﾞﾙ
    long	BarLeng_;	           // 桁数
    }

/**
 *  ｺﾝｽﾄﾗｸﾀ
 * @param p_in ProfileInterfaceのインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;


/**
   *  関数名   : LoadFigure
   *  機能     : ｵﾌﾞｼﾞｪｸﾄの読み込み
   *  機能説明 : 指定したｵﾌﾞｼﾞｪｸﾄの読み込み
   *  返り値   : 成功：TRUE、失敗：FALSE
   *  備考     :
*/
-(BOOL) LoadFigure:(long) iCnt   // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString*) lpszPathName;   // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
/**
 * 回転情報設定
 * @param Data バーコード回転情報
 */
- (void)SetRotate:(BarRotate *)Data;


/**
 *  関数名   : SetFormatCommand
 *  機能     : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 *  機能説明 : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 *  返り値   : 成功：TRUE、失敗：FALSE
 *  備考     :
 */
-(bool) SetFormatCommand:(long) iCode      // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK*) pTrans	   // 送信ﾌﾞﾛｯｸ
              withBarSet:(BarSet*) Barset	       // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct*) pCom;	       // 通信設定


/**
  *  関数名   : SetDataCommand
  *  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
  *  機能説明  : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
  *  返り値   : 成功：TRUE、失敗：FALSE
  *  備考     :
  */
-(BOOL) SetDataCommand:(long) iCode        // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK*) wpTrans	   // 送信ﾌﾞﾛｯｸ
            withBarSet:(BarSet*) Barset	       // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct*) pCom;	       // 通信設定

/**
   *  関数名   : GetSendFormatSize
   *  機能     : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
   *  機能説明 : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
   *  返り値   : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ
   *  備考     :
*/
-(long) GetSendFormatSize;

/**
 *  関数名   : GetSendDataSize
 *  機能     : 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 *  機能説明 : 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 *  返り値   : 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ
 *  備考     :
 */
-(long)GetSendDataSize;

/**
   * ｵﾌﾞｼﾞｪｸﾄ種類判断
*/
- (long)CheckObjID;

@end
