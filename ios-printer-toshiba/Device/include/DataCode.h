//
//  データコードオブジェクトクラス
//
//  Created by NC on 16/03/06.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
#import "Figure.h"

@class BarRotate;
@class TRANSBLOCK;
@class BarSet;
@class ComStruct;
@class ProfileInterface;
@interface DataCode : Figure {
 @public
    
    BarRotate *m_BarRotate_;	// 回転情報
    long iSell_Y_;	// ｾﾙ数Y
    long iSell_X_;	// ｾﾙ数X
    BOOL bSellAppoint_;	// ｾﾙ数の指定
    char iCheckDigit_;	// ﾁｪｯｸﾃﾞｼﾞｯﾄ
    long Increment_;	        // ｲﾝｸﾘﾒﾝﾄ
    long Rotation_;	            // 回転角度
    long Cell_Dot_;	            // ｾﾙﾄﾞｯﾄ数
    long Ecc_Type_;	            // ECCﾀｲﾌﾟ
    long FormID_;	            // ﾌｫｰﾏｯﾄID
    long BarLeng_;	            // 桁数
}

@property (nonatomic, retain) BarRotate *m_BarRotate;
@property (nonatomic, assign) long iSell_Y;
@property (nonatomic, assign) long iSell_X;
@property (nonatomic, assign) BOOL bSellAppoint;
@property (nonatomic, assign) char iCheckDigit;
@property (nonatomic, assign) long Increment;
@property (nonatomic, assign) long Rotation;
@property (nonatomic, assign) long Cell_Dot;
@property (nonatomic, assign) long Ecc_Type;
@property (nonatomic, assign) long FormID;
@property (nonatomic, assign) long BarLeng;

/**
 * 関数名   : CDataCode
 * 機能     : ｺﾝｽﾄﾗｸﾀ
 * 機能説明 : ｺﾝｽﾄﾗｸﾀ
 * 返り値   : なし
 * 備考     :
 * コンストラクタ
 * @param ProfileInterface p_in ProfileInterfaceを持つインスタンス
 */
- (id)init:(ProfileInterface*)p_in;


/**
 * 関数名   : LoadFigure
 * 機能     : ｵﾌﾞｼﾞｪｸﾄの読み込み
 * 機能説明 : 指定したｵﾌﾞｼﾞｪｸﾄ番号のｵﾌﾞｼﾞｪｸﾄの読み込み
 * 返り値   : 成功：TRUE、失敗：FALSE
 * 備考     :
 * 指定したｵﾌﾞｼﾞｪｸﾄ番号のｵﾌﾞｼﾞｪｸﾄの読み込み
 * @param int iCnt              ｵﾌﾞｼﾞｪｸﾄ番号
 * @param String lpszPathName   ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @return boolean 処理結果 成功：true、失敗：false
 */

-(BOOL) LoadFigure:(long) iCnt                // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
      withPathName:(NSString*) lpszPathName;  // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/**  関数名   : SetRotate
 *   機能     : 回転情報設定
 *   機能説明 : 回転情報設定
 *   返り値   : なし
 *    備考     :
 */
-(void) SetRotate : (BarRotate*) Data;

/**
 * 関数名   : SetFormatCommand
 * 機能     : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * 機能説明 : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * 返り値   : 成功：TRUE、失敗：FALSE
 * 備考     :
 * ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param 	int iCode                   ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param 	TRANSBLOCK pTrans           送信ﾌﾞﾛｯｸ
 * @param 	BarSet Barset               ﾌﾟﾘﾝﾀ情報
 * @param 	ComStruct pCom              通信設定
 * @return boolean 処理結果 成功：true、失敗：false
 */
-(BOOL)SetFormatCommand:(long)iCode    // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
         withTrans:(TRANSBLOCK*) pTrans	// 送信ﾌﾞﾛｯｸ
         withBarSet:(BarSet*) Barset 		// ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct*) pCom ;	// 通信設定

/**
   * 関数名   : SetDataCommand
   * 機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
   * 機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
   * 返り値   : 成功：TRUE、失敗：FALSE
   * 備考     :
   * ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
   * @param int iCode                         ｺﾝﾄﾛｰﾙｺｰﾄﾞ
   * @param TRANSBLOCK wpTrans                送信ﾌﾞﾛｯｸ(未使用)
   * @param BarSet Barset                     ﾌﾟﾘﾝﾀ情報
   * @param ComStruct pCom                    通信設定
   * @return boolean 処理結果 成功：true、失敗：false
*/
-(BOOL)SetDataCommand:(long)iCode    // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
            withTrans:(TRANSBLOCK*) pTrans	// 送信ﾌﾞﾛｯｸ
           withBarSet:(BarSet*) Barset 		// ﾌﾟﾘﾝﾀ情報
        withComStruct:(ComStruct*) pCom ;	// 通信設定
/**
   *  関数名   : GetSendFormatSize
   *  機能     : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
   *  機能説明 : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
   *  返り値   : 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ
   *  備考     :
   * 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
   * @return int 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ
*/
-(long)GetSendFormatSize;

/**
 *
 *  関数名   : GetSendDataSize
 *
 *  機能     : 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 *
 *  機能説明 : 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 *
 *  返り値   : 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ
 *
 *  備考     :
 *
 */
- (long)GetSendDataSize;

/**
   *  関数名   : CheckObjID
   *  機能     : ｺﾏﾝﾄﾞ種類取得
   *  機能説明 : ｺﾏﾝﾄﾞ種類取得
   *  返り値   :
   *  備考     :
   *  ｺﾏﾝﾄﾞ種類取得
   *  @return int 3固定
*/
-(long)CheckObjID;


@end
