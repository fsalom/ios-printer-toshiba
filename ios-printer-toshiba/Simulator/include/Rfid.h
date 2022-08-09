//
//  
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
#include "Figure.h"

@class BarRotate;
@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Rfid : Figure {
@public
    long Increment_;							// インクリメント値 0=省略
    long DataKind_;								// データ種別
    long LockFunction_;							// ロック機能 99=省略
    NSString *KillPassword_;				    // KILLパスワード　""=省略
    NSString *ExecPassword_;				    // 実行パスワード　""=省略
    NSString *AccessPassword_;				    // アクセスパスワード　""=省略
    long EndPos_;								// 書き込み終了位置
    long StartPos_;							    // 書き込み開始位置
    long FeedAdjust_;							// 発行前フィード量
    BOOL fOnTheFly_;							// オンザフライフラグ 0=発行前フィード量 1=書き込み開始、停止位置
    BOOL fWriteAction_;							// 書き込みオプション 0=省略 1=オンザフライフラグ有効
    long Filter_;								// フィルター -1=省略
    long Partation_;							// パーテーション -1=省略
    long WriteAddress_;							// 書き込みアドレス -1=省略
    long  WriteArea_;							// 書き込みエリア -1=省略
    long EPCFormat_;							// EPCフォーマット -1=省略
    long TagKind_;								// タグ種類
    BOOL fEnable_;								// 有効フラグ FALSE=無効 TRUE=有効

}

#pragma mark Public

/**
 *  関数名    : Rfid
 *  機能     : ｺﾝｽﾄﾗｸﾀ
 *  機能説明  : ｺﾝｽﾄﾗｸﾀ
 *  返り値   : なし
 *  備考     :
*/
- (id)init:(id<ProfileInterface>)p_in;


/**
 *  関数名   : LoadFigure
 *  機能     : LFMファイルのオブジェクトデータを展開する
 *  機能説明 : LFMファイルのRFIDオブジェクトデータを展開する
 *  返り値   : TRUE：完了	FALSE：失敗
 *  備考     :
*/
- (BOOL)LoadFigure:(long)iCnt                // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName; // ﾌｧｲﾙのﾌﾙﾊﾟｽ

/**
 *  関数名   : CheckObjID
 *  機能     : ｵﾌﾞｼﾞｪｸﾄ種類判断
 *  機能説明 :
 *  返り値   : int
 *  備考     :
*/
- (long)CheckObjID;

/**
 * 関数名   : SetFormatCommand
 * 機能     : RFIDフォーマットコマンド生成
 * 機能説明  : RFIDフォーマットコマンドを生成する
 * 返り値   : TRUE：生成完了
 * 備考     :
 */
- (BOOL)SetFormatCommand:(long)iCode             // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK *)pTrans    // 送信ﾌﾞﾛｯｸ
              withBarSet:(BarSet *)Barset        // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct *)pCom;      // 通信設定

/**
 * 関数名   : SetDataCommand
 * 機能     : RFIDデータコマンドを生成
 * 機能説明  :RFIDデータコマンドを生成する
 * 返り値   : TRUE：生成完了
 * 備考     :
 */
- (BOOL)SetDataCommand:(long)iCode            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK *)wpTrans  // 送信ﾌﾞﾛｯｸ(未使用)
            withBarSet:(BarSet *)Barset       // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct *)pCom;     // 通信設定
    
/**
 *  関数名   : GetSendFormatSize
 *  機能     : RFIDフォーマットコマンドのサイズを算出する
 *  機能説明 : RFIDフォーマットコマンドバイト数を算出する
 *  返り値   : RFIDフォーマットコマンドバイト数
 *  備考     :
*/
- (long)GetSendFormatSize;

/**
 *  関数名   : GetSendDataSize
 *  機能     : RFIDフォーマットコマンドのサイズを算出する
 *  機能説明 : RFIDフォーマットコマンドバイト数を算出する
 *  返り値   : RFIDフォーマットコマンドバイト数
 *  備考     :
 */
- (long)GetSendDataSize;

/**
 *  関数名   : SetExtentionSection
 *  機能     : Extentionセクション展開
 *  機能説明 : LFMファイルRFIDモジュールのExtentionセクションを展開する
 *  返り値   : TRUE：完了　FALSE：失敗
 *  備考     :
*/
- (BOOL)SetExtentionSection:(NSString *)No
      withPathName:(NSString *)lpszPathName;
/**
*  関数名   : CRfid::SetPREXTENTIONSection
*  機能     : PREXTENTIONセクション展開
*  機能説明 : LFMファイルRFIDモジュールのPREXTENTIONセクションを展開する
*  返り値   : TRUE：完了　FALSE：失敗
*  備考     :
*/
- (BOOL)SetPREXTENTIONSection:(NSString *)No
      withPathName:(NSString *)lpszPathName;

/**
 *  関数名   : SetWriteOption
 *  機能     : 書き込みオプション展開
 *  機能説明 : PREXTENTIONセクションの書き込みオプションを展開する
 *  返り値   : なし
 *  備考     :
*/
- (void)SetWriteOption:(NSString *) pBuff;


/*
*  関数名   : SetGen2Option
*  機能     : C1 Gen2 オプション展開
*  機能説明 : PREXTENTIONセクションのC1 Gen2 オプションを展開する
*  返り値   : なし
*  備考     :
*/
- (void)SetGen2Option:(NSString *) pBuff;


/**
 *  関数名   : CnvtPassword
 *  機能     : パスワードのASCIIコードをHEX文字列に変換する
 *  機能説明 : パスワードASCII４バイトをHEX文字列８バイトに変換する
 *  返り値   : 変換結果を格納した　CString クラス
 *  備考     :
*/
- (NSString *)CnvtPassword:(NSString *)sPassword;


/**
 *  関数名   : CRfid::SetSampleSection
 *  機能     : Sampleセクション展開
 *  機能説明 : LFMファイルRFIDモジュールのSampleセクションを展開する
 *  返り値   : TRUE：完了　FALSE：失敗
 *  備考     :
*/
- (BOOL)SetSampleSection:(NSString *)No
                 withPathName:(NSString *)lpszPathName;

@end
