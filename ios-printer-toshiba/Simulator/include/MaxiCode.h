//
//  MaxiCodeオブジェクトクラス
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

@interface MaxiCode : Figure {
 @public
    BarRotate *m_BarRotate_;       // 回転情報
    char	iCheckDigit_;	       // ﾁｪｯｸﾃﾞｼﾞｯﾄ種類
    long	Increment_;	           // ｲﾝｸﾘﾒﾝﾄ
    long	Additional_;	       // Zipｺｰﾄﾞ設定？
    long	MaxiLeng_;	           // 桁数
    long	Mode_;	               // ﾓｰﾄﾞ番号
    long	OffsetY_;	           // Contrast Block 付加時のＹ座標のズレ補正
    }
//@property (nonatomic, retain) BarRotate *m_BarRotate;
//@property (nonatomic, assign) char	iCheckDigit;
//@property (nonatomic, assign) long	Increment;
//@property (nonatomic, assign) long	Additional;
//@property (nonatomic, assign) long	MaxiLeng;
//@property (nonatomic, assign) long	Mode;
//@property (nonatomic, assign) long	OffsetY;

/**
 * ｺﾝｽﾄﾗｸﾀ
 * @param p_in ProfileInterfaceのインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

///**
//   * 関数名   : finalize()
//   * 機能     : ﾃﾞｽﾄﾗｸﾀ
//   * 機能説明 : ﾃﾞｽﾄﾗｸﾀ
//   * 返り値   : なし
//   * 備考     :
//*/
//- (void)dealloc;

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
 * ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param 	int iCode ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param 	TRANSBLOCK pTrans   送信ﾊﾞｯﾌｧ
 * @param 	BarSet Barset       ﾌﾟﾘﾝﾀ情報
 * @param 	ComStruct pCom      通信設定
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)SetFormatCommand:(long) iCode            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTRANSBLOCK:(TRANSBLOCK*) pTrans   // 送信ﾊﾞｯﾌｧ
              withBarSet:(BarSet*) Barset       // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct*) pCom;     // 通信設定


/**
   *  関数名   : SetDataCommand
   *  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
   *  機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
   *  返り値   : 成功：TRUE、失敗：FALSE
   *  備考     :
*/
-(BOOL) SetDataCommand:(long) iCode        // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
        withTRANSBLOCK:(TRANSBLOCK*) wpTrans	   // 送信ﾌﾞﾛｯｸ
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
