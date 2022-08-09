//
//  ラベルオブジェクトクラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//

@class BarRotate;
@class BarSet;
@class CRectangle;
@class ComStruct;
@class Figure_StartPosition;
@class TRANSBLOCK;
@protocol ProfileInterface;


@interface Figure : NSObject {
@public
    //	CRect mMaskRect;
    long mFigMode_;          // ｵﾌﾞｼﾞｪｸﾄ種類(LFM)
    BOOL m_DataSend_;        // ﾃﾞｰﾀｺﾏﾝﾄﾞ送信ﾌﾗｸﾞ
    BOOL m_FormatSend_;      // ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ送信ﾌﾗｸﾞ
    long m_ObjID_;           // ｵﾌﾞｼﾞｪｸﾄ種類
    CRectangle *mFieldRect_; // ｵﾌﾞｼﾞｪｸﾄ矩形
    //		protected char cLast1 = (char)0x0a;	// ｺﾝﾄﾛｰﾙｺｰﾄﾞ
    //		protected char cLast2 = (char)0x00;	// ｺﾝﾄﾛｰﾙｺｰﾄﾞ
    //		protected char cTop	 = (char)0x1b;	// ｺﾝﾄﾛｰﾙｺｰﾄﾞ
    char cLast1_;            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
    char cLast2_;            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
    char cTop_;              // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
    long SendPosY_;          // ﾋﾞｯﾄﾏｯﾌﾟ送信時のY方向移動量
    long SendPosX_;          // ﾋﾞｯﾄﾏｯﾌﾟ送信時のX方向移動量
    long iSendY_;            // ﾋﾞｯﾄﾏｯﾌﾟ送信時のﾋﾞｯﾄﾏｯﾌﾟ読み込みﾗｲﾝ数
    long iSendX_;            // ﾋﾞｯﾄﾏｯﾌﾟ送信時のﾋﾞｯﾄﾏｯﾌﾟ読み込みﾊﾞｲﾄ数
    NSString *m_szIssData2_; // 送信ﾃﾞｰﾀ(Work) -> 最終的に送信するﾃﾞｰﾀ
    NSString *m_szIssData_;  // 送信ﾃﾞｰﾀ(元) -> 設定された送信ﾃﾞｰﾀ
    long mFigFlag_;          // ｵﾌﾞｼﾞｪｸﾄﾊﾞｰｼﾞｮﾝ
    long mLColorIndex_;      // 線ｶﾗｰｲﾝﾃﾞｯｸｽ
    NSString *mFieldName_;   // 項目名
    long m_CustomData_;      // 可変データフラグ
}

#pragma mark Public

/**
 * コンストラクタ
 * @param ProfileInterface p_in ProfileInterfaceを持つインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

/**
 * ｱｽｷｰｺｰﾄﾞから数値へ変換
 * ﾕﾆｺｰﾄﾞでは正しく動作しないので注意
 * @param  char bData 変換するﾃﾞｰﾀ
 * @return  int 変換結果  成功：変換された数値、失敗：-1
 */
- (long)AsciiToHex:(char)bData;   // 変換するﾃﾞｰﾀ

// ｵﾌﾞｼﾞｪｸﾄ種類の取得
- (long)CheckObjID;

/**
 * 発行ﾃﾞｰﾀを作業用発行ﾃﾞｰﾀにｺﾋﾟｰ
 */
- (void)CopyIssOne;

/**
 *  関数名   : GetCustomData
 *  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞの"可変データ"状態取得
 *  機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞの"可変データ"状態状態取得
 *  返り値   : Lfmファイルに登録されている値
 * 備考     :
*/
- (long)GetCustomData;

/**
 *  関数名   : GetDataSendState
 *  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞの送信状態取得
 *  機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞの送信状態取得
 * 返り値   : 未送信：FALSE、送信済み：TRUE
 *  備考     :
*/
- (BOOL)GetDataSendState;

/**
*  関数名   : GetFieldName
*  機能     : ﾌｨｰﾙﾄﾞ名称の取得
*  機能説明 : ﾌｨｰﾙﾄﾞ名称の取得
*  返り値   : ﾌｨｰﾙﾄﾞ名称
*  備考     :
*/
- (NSString *)GetFieldName;

/*
 *  関数名   : GetFormatSendState
 *  機能     : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞの送信状態取得
 *  機能説明 : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞの送信状態取得
 *  返り値   : 未送信：FALSE、送信済み：TRUE
 *  備考     :
*/
- (BOOL)GetFormatSendState;

/**
 * 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ 0固定
 */
- (long)GetSendDataSize; // ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞの取得

/**
 * 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ 0固定
 */
- (long)GetSendFormatSize;

/**
 * ｵﾌﾞｼﾞｪｸﾄの読み込み
 * 指定されたｵﾌﾞｼﾞｪｸﾄを読み込む
 * @param 	int iCnt ｵﾌﾞｼﾞｪｸﾄ番号 ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @param 	String lpszPathName
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)LoadFigure:(long)iCnt    // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName;  // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
/**
 * ｸﾞﾗﾌｨｯｸｺﾏﾝﾄﾞ送信設定
 * @param 	int iSx 送信ﾋﾞｯﾄ数
 * @param 	int iSy 送信ﾗｲﾝ数
 * @param 	int iSpX 始点移動量X方向
 * @param 	int iSpY 始点移動量Y方向
 */
- (void)SetBmpEx:(long)iSx        // 送信ﾋﾞｯﾄ数
          withSy:(long)iSy        // 送信ﾗｲﾝ数
         withSpX:(long)iSpX       // 始点移動量X方向
         withSpY:(long)iSpY;      // 始点移動量Y方向

/**
 * ｺﾝﾄﾛｰﾙｺｰﾄﾞの設定
 * @param  int iCode ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 */
- (void)SetCtlCode:(long)iCode;  // ｺﾝﾄﾛｰﾙｺｰﾄﾞ

/**
 * ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param 	int iCode           ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param 	TRANSBLOCK pTrans   送信ﾌﾞﾛｯｸ
 * @param 	BarSet Barset       ﾌﾟﾘﾝﾀ情報
 * @param 	ComStruct pCom      通信設定
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetFormatCommand:(long)iCode          // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK *)pTrans // 送信ﾌﾞﾛｯｸ
              withBarSet:(BarSet *)Barset     // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct *)pCom;   // 通信設定

/**
 * ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 * @param 	int iCode           ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param 	TRANSBLOCK pTrans   送信ﾌﾞﾛｯｸ
 * @param 	BarSet Barset       ﾌﾟﾘﾝﾀ情報
 * @param 	ComStruct pCom      通信設定
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetDataCommand:(long)iCode          // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK *)pTrans // 送信ﾌﾞﾛｯｸ
              withBarSet:(BarSet *)Barset     // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct *)pCom;   // 通信設定

/**
*  関数名   : SetDataSendState
*  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ送信状態設定
*  機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞ送信状態設定(未送信：FALSE、送信済み：TRUE)
*  返り値   : なし
*  備考     :
*/
- (void)SetDataSendState;

- (void)SetDataSendState:(BOOL)iSet; // 送信状態

/**
 *  関数名   : SetFormatSendState
 *  機能     : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞの送信状態設定
 *  機能説明 : ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞの送信状態設定(未送信：FALSE、送信済み：TRUE)
 *  返り値   : なし
 *  備考     :
**/
- (void)SetFormatSendState;

- (void)SetFormatSendState:(BOOL)iSet; // 送信状態

// 画像処理モードの設定
- (void)SetGraphicType:(long)iType;

/**
 * 発行ﾃﾞｰﾀ設定
 * @param 	String szData    発行ﾃﾞｰﾀ
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetIssData:(NSString *)szData;   // 発行ﾃﾞｰﾀ

/**
 * 発行ﾃﾞｰﾀ設定
 * @param 	String szData   発行ﾃﾞｰﾀ
 * @param 	String szField  ﾌｨｰﾙﾄﾞ名
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetIssData:(NSString *)szData   // 発行ﾃﾞｰﾀ
         withField:(NSString *)szField; // ﾌｨｰﾙﾄﾞ名

/**
 * ｵﾌﾞｼﾞｪｸﾄ毎の番号設定
 * @param int iID  ｵﾌﾞｼﾞｪｸﾄ種類
 */
- (void)SetObjID:(long)iID;   // ｵﾌﾞｼﾞｪｸﾄ種類の設定

/**
 * 余白の設定
 * @param 	int iTop    上余白
 * @param 	int iLeft   左余白
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetOffset:(long)iTop    // 上余白
         withLeft:(long)iLeft;  // 左余白

// 回転設定
- (void)SetRotate:(BarRotate *)Data;

/**
 * ﾊﾞｰｺｰﾄﾞ回転時の始点座標の変換
 * @param 	int Rotation       回転角度
 * @param 	CRectangle lpRect  ｵﾌﾞｼﾞｪｸﾄ領域
 * @param 	BarRotate Data     回転情報
 * @param 	StartPosition startPos	変換後の始点(X,Y)
 * @return  boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetXYPos:(long)Rotation       // 回転角度
  withCRectangle:(CRectangle *)lpRect // ｵﾌﾞｼﾞｪｸﾄ領域
withBarRotateData:(BarRotate *)Data   // 回転情報
withFigure_StartPosition:(Figure_StartPosition *)startPos; // 変換後の始点(X,Y)

#pragma mark Protected

/**
 *  関数名   : CheckBarKind
 *  機能     : ﾊﾞｰｺｰﾄﾞ種類取得
 *  機能説明 : C/D種類とﾃﾞｰﾀﾚﾝｸﾞｽより、C/D計算に使用するﾊﾞｰｺｰﾄﾞ種類を取得
 *  返り値   : ﾊﾞｰｺｰﾄﾞ種類
 *  備考     :
*/
- (char)CheckBarKind:(char)cd      // C/D種類
            withLeng:(long)iLeng;  // ﾃﾞｰﾀﾚﾝｸﾞｽ

/*
*  関数名   : CheckCrlf
*機能     : 改行ｺｰﾄﾞ変換
*機能説明 : 読み込んだ(設定された)発行ﾃﾞｰﾀ中の改行ﾃﾞｰﾀ("\n")を改行ｺｰﾄﾞに変換(2次元ﾊﾞｰｺｰﾄﾞのみ)
*返り値   : なし
*備考     :
*/
- (void)CheckCrlf;

- (NSData *)GetBytes:(NSString *)szSourceString
        StringLength:(long)StringLength
         UseEncoding:(NSString *)UseEncoding;

- (NSString *)GetCurrentEncoding;

- (long)GetPrivateProfileInt:(NSString *)AppName
                 withKeyName:(NSString *)KeyName
                 withDefault:(long)Default
                withFileName:(NSString *)FileName;

- (NSString *)GetPrivateProfileString:(NSString *)AppName
                                     withKeyName:(NSString *)KeyName
                                     withDefault:(NSString *)Default
                                     withFileName:(NSString *)FileName;

/**
 *  関数名   : Set2BarData
 *  機能     : 制御ｺｰﾄﾞ変換
 *  機能説明 : 作業用発行ﾃﾞｰﾀ中の改行ｺｰﾄﾞを制御ｺｰﾄﾞに変換
 *  返り値   : なし
 *  備考     :
*/
- (void)Set2BarData;

/**
 * ﾁｪｯｸﾃﾞｼﾞｯﾄの計算
 * @param  char CDKind 計算後のﾃﾞｰﾀﾚﾝｸﾞｽ
 */
- (long)SetCheckDigit:(char)CDKind; // ﾁｪｯｸﾃﾞｼﾞｯﾄ種類

/**
 * 送信データをTRANSBLOCKへセット
 */
- (BOOL) appendTransData:(NSData*)bsData withComStruct:(ComStruct*)pCom withTrans:(TRANSBLOCK*) pTrans;

@end


/** オブジェクト開始位置クラス */
@interface Figure_StartPosition : NSObject {
@public
    /** 変換後の始点X */
    long pX_;
    /** 変換後の始点Y */
    long pY_;
}

#pragma mark Public
/**
 * コンストラクタ
 * @param int XPosition 始点X座標位置
 * @param  int YPostion 始点Y座標位置
 */
- (id)init:(long)XPosition
withYPosition:(long)YPostion;

@end
