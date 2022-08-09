//
//  LfmFile
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@class BarRotate;
@class BarSet;
@class ComStruct;
@class LongRef;
@class StringRef;
@class TRANSBLOCK;
@class PrinterInfo;
@class Figure;

#import "ProfileInterface.h"

@interface LfmFile : NSObject <ProfileInterface> {
 @public
  /** RFIDｵﾌﾞｼﾞｪｸﾄ番号 */
  int iRfid_;
  /** ｴﾗｰ種別 */
  long iErrType_;
  /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換ﾁｪｯｸ用文字列 */
  NSString *BarCheck_;
  /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換設定(埋め) */
  int BarFill_;
  /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換設定(寄せ) */
  int BarEdit_;
  /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換設定のﾌﾗｸﾞ */
  int BarMode_;
  /** ﾋﾞｯﾄﾏｯﾌﾟ送信用Y方向移動量 */
  int SendPosY_;
  /** ﾋﾞｯﾄﾏｯﾌﾟ送信用X方向移動量 */
  int SendPosX_;
  /** ﾋﾞｯﾄﾏｯﾌﾟ送信用読み込みﾗｲﾝ数 */
  int iSendY_;
  /** ﾋﾞｯﾄﾏｯﾌﾟ送信用読み込みﾊﾞｲﾄ数 */
  int iSendX_;
  /** WPCﾃﾞｰﾀ変換ﾌﾗｸﾞ */
  int WpcFlag_;
  /** ﾚｺｰﾄﾞ発行ﾌﾗｸﾞ(未使用) */
  int RecordPrintFlag_;
  /** ｺﾋﾟｰ発行ﾌﾗｸﾞ(未使用) */
  int CopyPrintFlag_;
  /** 発行方向 */
  int mIssueCondition_;
  /** ﾌﾟﾘﾝﾀ情報 */
  PrinterInfo *PInfo_;
  /** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
  int m_CtlCode_;
  /** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
  unichar cLast2_;
  /** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
  unichar cLast1_;
  /** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
  unichar cTop_;
  /** ﾋﾞｯﾄﾏｯﾌﾟ種類の数 */
  int iBitMap_;
  /** ｱｳﾄﾗｲﾝﾌｫﾝﾄの数 */
  int iOutChar_;
  /** ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄの数 */
  int iDotChar_;
  /** 線系ｵﾌﾞｼﾞｪｸﾄの数 */
  int iLine_;
  /** ﾊﾞｰｺｰﾄﾞ系ｵﾌﾞｼﾞｪｸﾄの数 */
  int iBarcode_;
  /** LFMﾌｧｲﾙ名 */
  NSString *m_strPathName_;
  NSMutableArray *mObArray_;
  NSMutableArray* aryInsertData_;
  /** LoadPCSave用領域 */
  NSString *m_strLoadPCSave_;
  /** ビットマップ処理モード 0:ニブル 1:ヘキサ 3:TOPIX圧縮 */
  int m_GraphicType_;
  /** ヘッド分割設定用フラグ 0:未設定でコマンド省略 1:設定済 */
  int m_SetHeadAdjust_;
  /** 上位クラスに向けて要求するインターフェイス */
  id<ProfileInterface> m_profInterface_;
}

/** RFIDｵﾌﾞｼﾞｪｸﾄ番号 */
@property (nonatomic, assign) int iRfid;
/** ｴﾗｰ種別 */
@property (nonatomic, assign) long iErrType;
/** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換ﾁｪｯｸ用文字列 */
@property (nonatomic, copy) NSString *BarCheck;
/** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換設定(埋め) */
@property (nonatomic, assign) int BarFill;
/** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換設定(寄せ) */
@property (nonatomic, assign) int BarEdit;
/** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換設定のﾌﾗｸﾞ */
@property (nonatomic, assign) int BarMode;
/** ﾋﾞｯﾄﾏｯﾌﾟ送信用Y方向移動量 */
@property (nonatomic, assign) int SendPosY;
/** ﾋﾞｯﾄﾏｯﾌﾟ送信用X方向移動量 */
@property (nonatomic, assign) int SendPosX;
/** ﾋﾞｯﾄﾏｯﾌﾟ送信用読み込みﾗｲﾝ数 */
@property (nonatomic, assign) int iSendY;
/** ﾋﾞｯﾄﾏｯﾌﾟ送信用読み込みﾊﾞｲﾄ数 */
@property (nonatomic, assign) int iSendX;
/** WPCﾃﾞｰﾀ変換ﾌﾗｸﾞ */
@property (nonatomic, assign) int WpcFlag;
/** ﾚｺｰﾄﾞ発行ﾌﾗｸﾞ(未使用) */
@property (nonatomic, assign) int RecordPrintFlag;
/** ｺﾋﾟｰ発行ﾌﾗｸﾞ(未使用) */
@property (nonatomic, assign) int CopyPrintFlag;
/** 発行方向 */
@property (nonatomic, assign) int mIssueCondition;
//@property (nonatomic, retain) PrinterInfo *PInfo;
/** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
@property (nonatomic, assign) int m_CtlCode;
/** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
@property (nonatomic, assign) unichar cLast2;
/** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
@property (nonatomic, assign) unichar cLast1;
/** ｺﾝﾄﾛｰﾙｺｰﾄﾞ */
@property (nonatomic, assign) unichar cTop;
/** ﾋﾞｯﾄﾏｯﾌﾟ種類の数 */
@property (nonatomic, assign) int iBitMap;
/** ｱｳﾄﾗｲﾝﾌｫﾝﾄの数 */
@property (nonatomic, assign) int iOutChar;
/** ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄの数 */
@property (nonatomic, assign) int iDotChar;
/** 線系ｵﾌﾞｼﾞｪｸﾄの数 */
@property (nonatomic, assign) int iLine;
/** ﾊﾞｰｺｰﾄﾞ系ｵﾌﾞｼﾞｪｸﾄの数 */
@property (nonatomic, assign) int iBarcode;
/** LFMﾌｧｲﾙ名 */
@property (nonatomic, copy) NSString *m_strPathName;
@property (nonatomic, retain) NSMutableArray *mObArray;
@property (nonatomic, retain) NSMutableArray *aryInsertData;

/** LoadPCSave用領域 */
@property (nonatomic, copy) NSString *m_strLoadPCSave;
/** ビットマップ処理モード 0:ニブル 1:ヘキサ 3:TOPIX圧縮 */
@property (nonatomic, assign) int m_GraphicType;
/** ヘッド分割設定用フラグ 0:未設定でコマンド省略 1:設定済 */
@property (nonatomic, assign) int m_SetHeadAdjust;
/** 上位クラスに向けて要求するインターフェイス */
@property (nonatomic, retain) id<ProfileInterface> m_profInterface;

/**
  　*　現在開かれているLFMﾌｧｲﾙ名を返却
  　*
  　* @return 現在開かれているLFMﾌｧｲﾙ名
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)GetLFMName;


/**
  　*　LFMﾌｧｲﾙ名の設定
  　*
  　* @param NSString* pPathName
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetLFMNameWithNSString:(NSString *)pPathName;

/**
  　*　初期化
  　*
  　* @param ProfileInterface p_in
  　* @return 初期化されたLfmFileクラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(id<ProfileInterface>)p_in;

/**
  　*　終了処理。
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)dealloc;

/**
  　*　設定値のｸﾘｱ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)Clear;

/**
  　*　ｵﾌﾞｼﾞｪｸﾄの削除
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)DeleteContents;

/**
  　*　ﾌﾟﾘﾝﾀｰﾘｾｯﾄｺﾏﾝﾄﾞの作成
  　*
  　* @param TRANSBLOCK* pTrans
  　* @return 成功：TRUE、失敗：FALSE
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)PrinterResetCommandWithTRANSBLOCK:(TRANSBLOCK *)pTrans;

/**
  　*　指定ｺﾏﾝﾄﾞの作成
  　*
  　* @param NSString* lpCmd
  　* @param TRANSBLOCK* pTrans
  　* @return 成功：TRUE、失敗：FALSE
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)SetSendCommandWithNSString:(NSString *)lpCmd
withTRANSBLOCK:(TRANSBLOCK *)pTrans;

/**
  　*　ｽﾃｰﾀｽ要求ｺﾏﾝﾄﾞの作成
  　*
  　* @param TRANSBLOCK* pTrans
  　* @return  成功：TRUE、失敗：FALSE
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)RequestStatusCommandWithTRANSBLOCK:(TRANSBLOCK *)pTrans;

/**
  　*　ｺﾝﾄﾛｰﾙｺｰﾄﾞの設定
  　*
  　* @param int iCode
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetCtlCodeWithInt:(int)iCode ;

/**
  　*　指定ｺﾏﾝﾄﾞの作成
  　*  指定された文字列を使用してｺﾏﾝﾄﾞの作成
  　*
  　* @param StringRef* lpCmd
  　* @return 成功：TRUE、失敗：FALSE
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)SetSendCommand2:(StringRef *)lpCmd ;

/**
 * 送信ｺﾏﾝﾄﾞ作成
 * @param pCom
 * @param Barset
 * @return 成功：TRUE、失敗：FALSE
 */
- (long)CreateSendData:(ComStruct *)pCom
            withBarSet:(BarSet *)Barset;

/**
 * 送信ｺﾏﾝﾄﾞ作成
 * @param pCom
 * @param Barset
 * @return 成功：TRUE、失敗：FALSE
 */
- (long)CreateSaveData:(ComStruct *)pCom
            withBarSet:(BarSet *)Barset;

- (NSString *)GetPrivateProfileString:(NSString *)AppName
                          withKeyName:(NSString *)KeyName
                          withDefault:(NSString *)Default
                         withFileName:(NSString *)FileName;

- (int)GetPrivateProfileInt:(NSString *)AppName
                withKeyName:(NSString *)KeyName
                withDefault:(int)Default
               withFileName:(NSString *)FileName;

- (NSData *)GetBytesWithNSString:(NSString *)szSourceString
                         withInt:(long)StringLength
       withJavaNioCharsetCharset:(NSString *)UseEncoding;

- (NSString *)GetCurrentEncoding;

/**
 *
 *  関数名   : LoadPrinterInfo
 *
 *  機能     : ﾌﾟﾘﾝﾀ情報の読み込み
 *
 *  機能説明 : ﾌｫｰﾏｯﾄﾌｧｲﾙに設定されているﾌﾟﾘﾝﾀ情報(種類、用紙ｻｲｽﾞ等)を読み込む
 *
 *  返り値   : 成功：TRUE、失敗：FALSE
 *
 *  備考     :
 *
 */
- (long)LoadPrinterInfo:(NSString *)pPrinter;

/**
 * ﾌｨｰﾄﾞ量微調の取得
 * @return  ﾌｨｰﾄﾞ量微調設定値
 */
- (long)GetFeedAdj;

/**
 * 印字濃度微調(発色)の取得
 * @return 印字濃度微調(発色)
 */
- (long)GetHeatAdj;

/**
 * 印字濃度微調(転写)の取得
 * @return 印字濃度微調(転写)
 */
- (long)GetRibbonAdj;

/**
 * ﾊﾞｯｸﾌｨｰﾄﾞ量微調の取得
 * @return ﾊﾞｯｸﾌｨｰﾄﾞ量微調
 */
- (long)GetBackFeedAdj;

/**
 * ｶｯﾄ位置微調の取得
 * @return ｶｯﾄ位置微調
 */
- (long)GetCutAdj;

/**
 * 発行ﾓｰﾄﾞの取得
 * @return 発行ﾓｰﾄﾞ
 */
- (NSString *)GetPrintMode;

/**
 * 印字速度の取得
 * @return 印字速度
 */
- (long)GetPrintSpeed;

/**
 * ﾘﾎﾞﾝ種類の取得
 * @return ﾘﾎﾞﾝ種類
 */
- (long)GetRibbonMode;

/**
 * ﾀｸﾞﾛｰﾃｰｼｮﾝ種類の取得
 * @return ﾀｸﾞﾛｰﾃｰｼｮﾝ種類
 */
- (long)GetRotation;

/**
 * ｾﾝｻｰ種別の取得
 * @return ｾﾝｻｰ種別
 */
- (long)GetSensor;

/**
 * ﾊﾞｯｸﾌｨｰﾄﾞ量微調の設定
 * @param Adj 設定値
 */
- (void)SetBackFeedAdj:(long)Adj;

/**
 * ｶｯﾄ位置微調の設定
 * @param Adj 設定値
 */
- (void)SetCutAdj:(long)Adj;

/**
 * ﾌｨｰﾄﾞ量微調の設定
 * @param Adj 設定値
 */
- (void)SetFeedAdj:(long)Adj;

/**
 * 印字濃度微調(発色)の設定
 * @param Adj 設定値
 */
- (void)SetHeatAdjWithInt:(long)Adj;

/**
 * 発行ﾓｰﾄﾞの設定
 * @param cMode 設定値
 */
- (void)SetPrintMode:(unichar)cMode;

/**
 * 印字速度の設定
 * @param iSpeed 印字速度
 */
- (void)SetPrintSpeed:(long)iSpeed;

/**
 * 印字濃度微調(転写)の設定
 * @param Adj 設定値
 */
- (void)SetRibbonAdj:(long)Adj;

/**
 * ﾘﾎﾞﾝ種類の設定
 * @param iMode 設定値
 */
- (void)SetRibbonMode:(long)iMode;

/**
 * ﾀｸﾞﾛｰﾃｰｼｮﾝの設定
 * @param iRotation 設定値
 */
- (void)SetRotation:(long)iRotation ;

/**
 * ｾﾝｻｰ種別の設定
 * @param iSensor 設定値
 */
- (void)SetSensor:(long)iSensor;

/**
 * 印字濃度微調(ﾍｯﾄﾞ分割)の設定
 * @param Adj 設定値
 */
- (void)SetHeadAdj:(long)Adj;

/**
 *
 *  関数名   : LoadLfm
 *
 *  機能     : ﾌｫｰﾏｯﾄﾌｧｲﾙの読み込み
 *
 *  機能説明 : ﾌｫｰﾏｯﾄﾌｧｲﾙよりｵﾌﾞｼﾞｪｸﾄ情報を読み込み、ｵﾌﾞｼﾞｪｸﾄを作成
 *
 *  返り値   : 成功：TRUE、失敗：FALSE
 *
 *  備考     :
 *
 */
- (long)LoadLfm;

/**
 *
 *  関数名   : AddFigure
 *
 *  機能     : 配列に追加
 *
 *  機能説明 : 配列(ｵﾌﾞｼﾞｪｸﾄ配列)に追加
 *
 *  返り値   : なし
 *
 *  備考     :
 *
 */
- (void)AddFigure:(Figure *)pFigure;

/**
 *
 *  関数名   : SetObjOffset
 *
 *  機能     : 余白の設定
 *
 *  機能説明 : 余白の設定分、始点終点をずらす
 *
 *  返り値   : 成功：TRUE、失敗：FALSE
 *
 *  備考     :
 *
 */
- (BOOL)SetObjOffset;

/**
 *
 *  関数名   : GetNumFigure
 *
 *  機能     : 現在のｵﾌﾞｼﾞｪｸﾄ数の取得
 *
 *  機能説明 : 現在のｵﾌﾞｼﾞｪｸﾄ数の取得
 *
 *  返り値   : ｵﾌﾞｼﾞｪｸﾄ数
 *
 *  備考     :
 *
 */
- (long)GetNumFigure;

/**
 * ｵﾌﾞｼﾞｪｸﾄの取得<br>
 * 指定したｲﾝﾃﾞｯｸｽのｵﾌﾞｼﾞｪｸﾄを取得する
 * @param Index ｲﾝﾃﾞｯｸｽ
 * @return 成功：ｵﾌﾞｼﾞｪｸﾄ、失敗：NULL
 */
- (Figure *)GetFigure:(long)Index;

/**
 * 回転情報設定
 * @param Data ﾊﾞｰｺｰﾄﾞ回転情報
 */
- (void)SetRotate:(BarRotate *)Data;

/**
 * 発行の拡張設定の読み込み
 * @param lpszPathName ﾌﾟﾘﾝﾀ情報ﾌｧｲﾙ
 */
- (void)LoadExPrinterInfo:(NSString *)lpszPathName;

/**
 * 発行ﾃﾞｰﾀの設定
 * @param iCnt オブジェクト番号
 * @param szData 設定データ
 * @return 成功：TRUE、失敗：FALSE
 */
- (long)SetObjData:(long)iCnt
          withData:(NSString *)szData;

/**
 * 発行ﾃﾞｰﾀの設定
 * @param lpField 項目名
 * @param szData 設定データ
 * @param Result リザルト
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)SetObjDataEx2:(NSString *)lpField
             withData:(NSString *)szData
           withResult:(LongRef *)Result;

/**
 * ﾍｯﾄﾞ断線ﾁｪｯｸｺﾏﾝﾄﾞの作成
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)BadDotCheckCommand:(TRANSBLOCK *)pTrans;

/**
 * 印字濃度微調ｺﾏﾝﾄﾞ作成
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)SetDensAdjust:(TRANSBLOCK *)pTrans;

/**
 * ｲﾒｰｼﾞﾊﾞｯﾌｧｸﾘｱｺﾏﾝﾄﾞ作成
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)ClrImage:(TRANSBLOCK *)pTrans;

/**
 * 位置微調ｺﾏﾝﾄﾞ作成
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)SetPosAdjust:(TRANSBLOCK *)pTrans;

/**
 * ﾗﾍﾞﾙｻｲｽﾞ設定ｺﾏﾝﾄﾞ作成
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)SetLabelSize:(TRANSBLOCK *)pTrans;

/**
 * 発行ｺﾏﾝﾄﾞ作成
 * @param IssueCount 発行数
 * @param CutInterval カット間隔
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */

- (BOOL)IssueCommand:(long)IssueCount
     withCutInterval:(long)CutInterval
           withTrans:(TRANSBLOCK *)pTrans;

/**
 * ﾌｨｰﾄﾞｺﾏﾝﾄﾞ作成
 * @param Cut カット
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)FeedCommand:(long)Cut
          withTrans:(TRANSBLOCK *)pTrans;

/**
 * 排出ｺﾏﾝﾄﾞ作成
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)ExhaustCommand:(TRANSBLOCK *)pTrans;

/**
 * 正転ﾌｨｰﾄﾞｺﾏﾝﾄﾞ作成
 * @param FeedCount フィード数
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)ForwardFeedCommand:(long)FeedCount
                 withTrans:(TRANSBLOCK *)pTrans;

/**
 * 逆転ﾌｨｰﾄﾞｺﾏﾝﾄﾞ作成
 * @param FeedCount フィード数
 * @param pTrans TRANSBLOCK
 * @return 成功：TRUE、失敗：FALSE
 */
- (BOOL)BackwardFeedCommand:(long)FeedCount
                  withTrans:(TRANSBLOCK *)pTrans;

/**
 * 発行データ挿入
 * @param Position
 * @param pCom
 * @param pTrans
 * @return 成功：TRUE、失敗：FALSE
 */
- (long)LoadInsertData:(long)Position
               withCom:(ComStruct *)pCom
             withTrans:(TRANSBLOCK *)pTrans;

/**
 * 挿入データ消去
 */
- (void)DelInsertData;

/**
 * 画像処理方式の設定
 * @param iType
 */
- (void)SetGraphicType:(int)iType;
/**
 * 画像処理方式の設定
 * @param iFlg
 */
- (void)SetHeadAdjustFlg:(int)iFlg;

@end
