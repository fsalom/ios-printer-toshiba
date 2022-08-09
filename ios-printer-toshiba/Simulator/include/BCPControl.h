//
//  BcpIssue
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@class ComStruct;
@class Generate;
@class LongRef;
@class StringRef;
@class RetryIssueData;
@class Charset;
@class IntRef;
@class LfmFile;
@class PrintModeStatus;
@class BarSet;
@protocol LIBBcpControlCallBack;



#import "IComStructCallBack.h"
#import "ProfileInterface.h"

@interface BCPControl : NSObject < IComStructCallBack,ProfileInterface > {
@public
	/** Bluetooth */
    NSString *BLUETOOTH_CNCSTR_;
    /** ignoreComStructCallBack */
    BOOL ignoreComStructCallBack_;
    /** m_EventThrough */
    BOOL m_EventThrough_;
    /** 通信設定クラスのインスタンス */
    ComStruct *pCom_;
    /** 受信イベント通知インタフェースのインスタンス */
    id<LIBBcpControlCallBack> m_CallBack_;
    /** ｺﾝﾄﾛｰﾙｺｰﾄﾞｲﾝﾃﾞｯｸｽ */
    int m_controlCode_;
    /** Generateクラスのインスタンス */
    Generate *m_geneClass_;
    /** 使用言語 0:日本語 1:英語 */
    int m_language_;
    /** 画像処理モード 0:ニブル 1:ヘキサ 2:TOPIX圧縮 default:1*/
    int m_GraphicType_;
    /** 受信ﾀｲﾑｱｳﾄ */
    int m_RecvTimeout_;
    /** 使用コードページ 37以降コードページ番号にも対応 */
    int m_codePage_;
    /** 再印字用データ保持クラスのインスタンス */
    RetryIssueData *mRetryIssueData_;
    /** 通信設定 */
    NSString *m_PortSetting_;
    NSMutableArray *MODE_CODE_TBL_;
    NSMutableArray *MODE_NAME_TBL_;
    NSMutableArray *MODE_NAME_TBL2_;
    NSMutableArray *MODE_NAME_TBL3_;
    /** メッセージファイル名 */
    NSString *m_MsgFilename_;
    /** 実際に読み込んでいるプリンタ番号 */
    int m_ReadPrinter_;
    /** 情報読込み済みプリンタ番号 = -2 */
    int m_InitPrinter_;
    /** プリンタ番号 */
    int m_UsePrinter_;
    /** 改行コード */
    NSString *CrLf_;
    /** LFMﾌｧｲﾙがﾛｰﾄﾞ済みかのﾌﾗｸﾞ */
    BOOL m_LoadStatus_;
    /** ラベルフォーマットファイル処理 */
    LfmFile *m_LfmFile_;
    
    NSString* m_SystemPath_;                 // デフォルトは、コンストラクタにて設定しています。
    NSString* m_ORGSystemPath_;              // デフォルトは、コンストラクタにて設定しています。

    PrintModeStatus* m_PrModeStatus_;
    /// <summary>プリンタ情報クラス</summary>
    BarSet* m_Barset_;                      // プリンタ情報ファイル処理
    long m_BackFeedAdjust_;					// ﾊﾞｯｸﾌｨｰﾄﾞ微調
    long m_CutAdjust_;						// ｶｯﾄ微調
    long m_FeedAdjust_;						// ﾌｨｰﾄﾞ微調
    long m_HeatAdjust_;						// 電圧微調(発色)
    long m_RibbonAdjust_;					// 電圧微調(転写)
    NSString* m_PrintMode_;                 // 発行ﾓｰﾄﾞ= "C";
    long m_PrintSpeed_;                     // 印字ｽﾋﾟｰﾄﾞ= 0;
    long m_RibbonMode_;						// ﾘﾎﾞﾝ種類
    long m_Rotation_;						// ﾀｸﾞﾛｰﾃｰｼｮﾝ
    long m_Sensor_;							// ｾﾝｻｰ種別
    
    int m_CodeIndex_;						// ｺﾝﾄﾛｰﾙｺｰﾄﾞｲﾝﾃﾞｯｸｽ
    
    /** 接続フラグ */
    BOOL bbConected;
}
/** ignoreComStructCallBack */
@property (nonatomic, assign) BOOL ignoreComStructCallBack;
/** m_EventThrough */
@property (nonatomic, assign) BOOL m_EventThrough;
/** LFMﾌｧｲﾙがﾛｰﾄﾞ済みかのﾌﾗｸﾞ */
@property (nonatomic, assign) BOOL m_LoadStatus;
/** 通信設定クラスのインスタンス */
@property (nonatomic, retain) ComStruct *pCom;
/** 受信イベント通知インタフェースのインスタンス */
@property (nonatomic, retain) id<LIBBcpControlCallBack> m_CallBack;
/** ｺﾝﾄﾛｰﾙｺｰﾄﾞｲﾝﾃﾞｯｸｽ */
@property (nonatomic, assign) int m_controlCode;
/** Generateクラスのインスタンス */
@property (nonatomic, retain) Generate *m_geneClass;
/** 使用言語 0:日本語 1:英語 */
@property (nonatomic, assign) int m_language;
/** 受信ﾀｲﾑｱｳﾄ */
@property (nonatomic, assign) int m_RecvTimeout;
/** 実際に読み込んでいるプリンタ番号 */
@property (nonatomic, assign) int m_ReadPrinter;
/** プリンタ番号 */
@property (nonatomic, assign)  int m_UsePrinter;
/** 使用コードページ 37以降コードページ番号にも対応 */
@property (nonatomic, assign) int m_codePage;
/** 再印字用データ保持クラスのインスタンス */
@property (nonatomic, retain) RetryIssueData *mRetryIssueData;
/** ラベルフォーマットファイル処理 */
@property (nonatomic, retain) LfmFile *m_LfmFile;

/** Bluetooth */
@property (nonatomic, copy) NSString *BLUETOOTH_CNCSTR;
/** 通信設定 */
@property (nonatomic, copy) NSString *m_PortSetting;
/** メッセージファイル名 */
@property (nonatomic, copy) NSString *m_MsgFilename;

/** 改行コード */
@property (nonatomic, copy) NSString *CrLf;
@property (nonatomic, retain) NSMutableArray *MODE_CODE_TBL;
@property (nonatomic, retain) NSMutableArray *MODE_NAME_TBL;
@property (nonatomic, retain) NSMutableArray *MODE_NAME_TBL2;
@property (nonatomic, retain) NSMutableArray *MODE_NAME_TBL3;



/**
  　*　fireOnStatusEvent
  　*
  　* @param NSString PrinterStatus プリンタステータス
  　* @param long Result
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)fireOnStatusEvent:(NSString *)PrinterStatus
                          Result:(long long int)Result;
//2017-08-25 E.Ohshima(jse) 接続完了イベント対応 Add Start
- (void)fireOnOpenedEvent:(BOOL*)ReturnValue;
//2017-08-25 E.Ohshima(jse) 接続完了イベント対応 Add End
/**
  　*　コマンド制御コード方式を設定します
  　*
  　* @param int value ESC,LF,NULL方式：0 {,|,}方式：1
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setControlCode:(int)value;

/**
  　*　CodePageを設定します
  　*
  　* @param int value
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setCodePage:(int)value;
/**
  　*　表示する言語を設定します。
  　*
  　* @param int value 日本語：0 英語：1
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setLanguage:(int)value;

/**
 　*　システムパスを設定します。
 　*
 　* @param NSString* value
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (void)setSystemPath:(NSString*)value;


/**
 　*　システムパスを取得します。
 　*
 　* @param NSString* value
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (NSString*)getSystemPath;


/**
  　*　受信ｲﾍﾞﾝﾄ発生
  　*　受信ｲﾍﾞﾝﾄ発生(ﾒｯｾｰｼﾞ)
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)ComStruct_BcpUnSyncMessage;
//2017-08-25 E.Ohshima(jse) 接続完了イベント対応 Add Start
- (void)ComStruct_BcpBLEUnSyncMessage:(BOOL*)ReturnValue;
//2017-08-25 E.Ohshima(jse) 接続完了イベント対応 Add End
/**
  　*　ポートのクローズ
  　*
  　* @param LongRef Result ｴﾗｰ情報
  　* @return 処理結果 成功：true 失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ClosePort:(LongRef *)Result;

/**
  　*　初期化
  　*
  　* @return 初期化されたバーコード回転情報クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init;

/**
  　*　ﾎﾟｰﾄのｵｰﾌﾟﾝ
  　*
  　* @param int IssueMode 復帰モード 1:送信完了復帰 2:発行完了復帰
  　* @param LongRef Result エラー情報
  　* @return boolean 実行結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)OpenPort:(int)IssueMode Result:(LongRef *)Result;

/**
  　*　通信設定判断処理 PortSettingﾌﾟﾛﾊﾟﾃｨからﾎﾟｰﾄの種別を取得し、判断する
  　*
  　* @param StringRef szData1 ﾘｿｰｽ判断用文字列
  　* @return int ﾎﾟｰﾄ種類
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)GetPortName:(StringRef *)szData1;

/**
  　*　受信データ取得
  　*
  　* @param StringRef Data 受信データ格納バッファ
  　* @param LongRef Result 処理結果
  　* @return int 受信データ数
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)ReadPort:(StringRef *)Data withResult:(LongRef *)Result;

/**
  　*　受信データ取得
  　*
  　* @param StringRef Data 受信データ格納バッファ
  　* @param int Length 受信データ格納バッファサイズ
  　* @param LongRef Result 処理結果
  　* @return int 受信データ数
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)ReadPort:(StringRef *)Data Length:(long)Length Result:(LongRef *)Result;

/**
  　*　Issueメソッド実行時のリトライエラー情報のクリア
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)clearRetryErrorInformation;

/**
 　*　データ送信処理
 　*
 　* @param byte[] Binary 送信するバイナリデータ
 　* @param int Length 送信するバイナリデータサイズ
 　* @param LongRef Result 処理結果
 　* @return BOOL 処理結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (BOOL)WritePort:(Byte [])Binary
       withLength:(int)Length
       withResult:(LongRef *)Result;

/**
  　*　データ送信処理
  　*
  　* @param NSString Data 送信するデータ
  　* @param LongRef Result 処理結果
  　* @return BOOL 処理結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)WritePort:(NSString *)Data
       withResult:(LongRef *)Result;

/**
  　*　ステータス値からメッセージ文字列を取得
  　*
  　* @param NSString PrinterStatus ステータス値
  　* @param StringRef Message メッセージ
  　* @return BOOL 処理結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetMessage:(NSString *)PrinterStatus
       withMessage:(StringRef *)Message;

/**
  　*　送信ﾊﾞｯﾌｧ数の取得
  　*
  　* @param IntRef Count 送信ﾊﾞｯﾌｧ数を返すﾎﾟｲﾝﾀ
  　* @param LongRef Result ｴﾗｰ情報
  　* @return BOOL 処理結果 成功：true 失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetSendBuffCount:(IntRef *)Count
                       withResult:(LongRef *)Result;

/**
  　*　ｽﾃｰﾀｽ要求ｺﾏﾝﾄﾞ送信
  　*
  　* @param StringRef PrinterStatus 受信ｽﾃｰﾀｽ
  　* @param LongRef Result ｽﾃｰﾀｽ情報
  　* @return BOOL 処理結果 成功：true 失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetStatus:(StringRef *)PrinterStatus
                   withResult:(LongRef *)Result;

/**
  　*　送信ﾊﾞｯﾌｧｸﾘｱ
  　*
  　* @param int Wait 待機時間
  　* @param long PrinterReset ﾘｾｯﾄﾓｰﾄﾞ
  　* @param LongRef Result エラー情報
  　* @return BOOL 実行結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)Reset:(int)Wait
withPrinterReset:(long long int)PrinterReset
   withResult:(LongRef *)Result;

/**
  　*　ｺﾏﾝﾄﾞ送信
  　*
  　* @param NSString Command 送信ｺﾏﾝﾄﾞ
  　* @param LongRef Result エラー情報
  　* @return BOOL 実行結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)SendCommand:(NSString *)Command
         withResult:(LongRef *)Result;

/**
  　*　発行モード切替
  　*
  　* @param int PrintMode
  　* @param LongRef Result
  　* @return 処理結果 true : 正常終了 false : 処理失敗
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)SetPrintModeWithInt:(int)PrintMode
withLongRef:(LongRef *)Result;

/**
  　*　受信ステータス取得
  　*
  　* @param StringRef PrinterStatus
  　* @param LongRef Result
  　* @return 処理結果 true : 成功 false : 失敗
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ReadStatus:(StringRef *)PrinterStatus
                    withResult:(LongRef *)Result;

/**
  　*　送信処理終了監視
  　*
  　* @param int Wait
  　* @param int EndPoint
  　* @param StringRef PrinterStatus
  　* @param LongRef Result
  　* @return 処理結果 1 : 正常終了 0 : 処理失敗
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)Watch:(int)Wait
withEndPoint:(int)EndPoint
withPrinterStatus:(StringRef *)PrinterStatus
   withResult:(LongRef *)Result;

/**
  　*　通信設定を設定します
  　*
  　* @param NSString mPortSetting
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setPortSettingWithNSString:(NSString *)mPortSetting;

/**
  　*　TickCount
  　*
  　* @return long TickCount
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
+ (long long int)TickCount;

	/**
  　*　ﾁｪｯｸﾃﾞｼﾞｯﾄ計算
  　*
  　* @param NSString BarType ﾊﾞｰｺｰﾄﾞ種類
  　* @param NSString CDType ﾁｪｯｸﾃﾞｼﾞｯﾄ種類
  　* @param NSString SrcData 計算を行うﾃﾞｰﾀ
  　* @param NSString ResData 計算結果(ﾃﾞｰﾀ＋C/D)
  　* @return 処理結果 成功：true 失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)CreateBarcodeData:(NSString *)BarType
               withCDType:(NSString *)CDType
              withSrcData:(NSString *)SrcData
              withResData:(StringRef *)ResData;

///**
//  　*　wishGetPrivateProfileString
//  　*
//  　* @param NSString AppName
//  　* @param NSString KeyName
//  　* @param NSString Default
//  　* @param NSString FileName
//  　* @return NSString
// 　 * @author NC。
// 　 * @version 1.0。
// 　 * @since 1.0。
//  　*/
//- (NSString *)wishGetPrivateProfileString:(NSString *)AppName
//                                  KeyName:(NSString *)KeyName
//                                  Default:(NSString *)Default
//                                 FileName:(NSString *)FileName;

///**
//  　*　wishGetPrivateProfileInt
//  　*
//  　* @param NSString AppName
//  　* @param NSString KeyName
//  　* @param int Default
//  　* @param NSString FileName
//  　* @return int
// 　 * @author NC。
// 　 * @version 1.0。
// 　 * @since 1.0。
//  　*/
//- (int)wishGetPrivateProfileInt:(NSString *)AppName
//                        KeyName:(NSString *)KeyName
//                        Default:(int)Default
//                       FileName:(NSString *)FileName;

///**
//  　*　wishGetBytes
//  　*
//  　* @param NSString szSourceString
//  　* @param int StringLength
//  　* @param NSString UseEncoding
//  　* @return NSData
// 　 * @author NC。
// 　 * @version 1.0。
// 　 * @since 1.0。
//  　*/
//- (NSData *)wishGetBytes:(NSString *)szSourceString
//                    StringLength:(int)StringLength
//                     UseEncoding:(NSString *)UseEncoding;

///**
//  　*　wishGetCurrentEncoding
//  　*
//  　* @return NSString
// 　 * @author NC。
// 　 * @version 1.0。
// 　 * @since 1.0。
//  　*/
//- (NSString *)wishGetCurrentEncoding;

///**
//  　*　wishGenerateBarcode
//  　*
//  　* @param NSString BarType
//  　* @param NSString CDType
//  　* @param NSString lpData
//  　* @return BOOL
// 　 * @author NC。
// 　 * @version 1.0。
// 　 * @since 1.0。
//  　*/
//- (BOOL)wishGenerateBarcode:(NSString *)BarType
//                     CDType:(NSString *)CDType
//                     lpData:(NSString *)lpData;

/**
  　*　ｽﾃｰﾀｽ要求ｺﾏﾝﾄﾞ送信(ｺﾏﾝﾄﾞ送信前状態確認用)
  　*
  　* @param StringRef PrinterStatus 受信ｽﾃｰﾀｽ
  　* @param LongRef Result ｴﾗｰ情報
  　* @return 実行結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetStatusEx:(StringRef *)PrinterStatus
             Result:(LongRef *)Result;

/**
  　*　配列から、目的の値の入っているインデックスを取得する
  　*
  　* @param NSMutableArray data
  　* @param int target
  　* @return int インデックス値 ,　見つからない場合は-1を返す
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
+ (long)ArrayIndex:(NSMutableArray *)data
           target:(int)target;

/**
  　*　発行モード取得 WXコマンドを送信し、戻り値の文字列を返します
  　*
  　* @param int Wait 完了待ち時間 ms単位
  　* @param StringRef name 完了待ち時間 ms単位
  　* @param LongRef Result 完了待ち時間 ms単位
  　* @return 処理結果 1 : 正常終了 0 : 処理失敗
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetPrinterMode:(int)Wait
                  name:(StringRef *)name
                Result:(LongRef *)Result;

/**
  　*　getStatusMessage
  　*
  　* @param StringRef szErr
  　* @param StringRef szTemp
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)getStatusMessage:(StringRef *)szErr
                  szTemp:(StringRef *)szTemp;

/**
  　*　ステータス値からメッセージ文字列を取得
  　*
  　* @param long long int ErrorCode
  　* @param StringRef Message
  　* @return BOOL 処理結果 成功:true 失敗:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetMessageWithErrorCode:(long long int)ErrorCode
                    withMessage:(StringRef *)Message;

/**
  　*　prepareBridge
  　*
  　* @param delegate
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)prepareBridge:(id)delegate;

/**
  　*　ConnectPrinter
  　*
  　* @param NSString Address
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
-(void)ConnectPrinter:(NSString *)Address;

/**
  　*　SendDataToPrinter
  　*
  　* @param char* Buffer
  　* @param int length
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
-(void)SendDataToPrinter:(char *)Buffer:(int)length;


/**
  　*　DisplayConnectionStatus
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)DisplayConnectionStatus;

/**
  　*　DisplayAlert
  　*
  　* @param bool on
  　* @param NSString* message
  　* @param NSString* button
  　* @param bool startTimer
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)DisplayAlert:(bool)on:(NSString *)message:(NSString *)button:(bool)startTimer;

/**
  　*　BarcodeDataArrived
  　*
  　* @param char* BarcodeData
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)BarcodeDataArrived:(char *)BarcodeData;

/**
  　*　SynchronizeFinished
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SynchronizeFinished;

/**
  　*　SaveEmailSettings
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SaveEmailSettings;

/**
  　*　StartSynchronize
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)StartSynchronize;

/////QQQ    ///
/**
 * 可変ﾃﾞｰﾀ設定
 * @param int ObjectNo オブジェクト番号
 * @param  String ObjectData 可変データ
 * @param  LongRef Result エラー情報
 * @return boolean 実行結果 成功:true 失敗:false
 */
- (BOOL) SetObjectData:(long) ObjectNo withObjectData:(NSString*) ObjectData Result:(LongRef*) Result;

/**
 * 可変ﾃﾞｰﾀ設定
 * @param String ObjectName ｵﾌﾞｼﾞｪｸﾄ名
 * @param  String ObjectData 可変ﾃﾞｰﾀ
 * @param  LongRef Result ｴﾗｰ情報
 * @return boolean 実行結果 成功:true 失敗:false
 */
- (BOOL) SetObjectDataEx:(NSString*) ObjectName
          withObjectData:(NSString*) ObjectData Result:(LongRef*) Result;

/**
 * ﾍｯﾄﾞ断線ﾁｪｯｸｺﾏﾝﾄﾞ送信
 * @param int Wait 待機時間
 * @param  StringRef PrinterStatus 受信ｽﾃｰﾀｽ
 * @param LongRef Result ｴﾗｰ情報
 * @return 処理結果 成功：true 失敗：false
 */
- (BOOL) HeadCheck:(long)Wait PrinterStatus:(StringRef*) PrinterStatus Result:(LongRef*) Result;

/**
 * フィードコマンド発行
 * @param long Cutting カット枚数指定
 * @param  StringRef PrinterStatus 受信ステータス
 * @param LongRef Result エラー情報
 * @return 処理結果 成功：true 失敗：false
 */
- (BOOL) Feed:(long) Cutting PrinterStatus:(StringRef*) PrinterStatus Result:(LongRef*) Result;


/**
 * ヘッド電圧微調を設定する。
 * @param int Flag 変更するﾓｰﾄﾞ
 * @param  int Adjust 微調値
 * @param  LongRef Result ｴﾗｰ情報
 * @return  処理結果 成功：true 失敗：false
 */
- (BOOL) ChangeHeadVoltage:(long) Flag withAdjust:(long)Adjust Result:(LongRef*) Result;

/**
 * 発行条件の変更
 * @param long Flag 変更するﾓｰﾄﾞ ｾﾝｻｰ種別:0 発行方法:1 印字速度:2 ﾘﾎﾞﾝ種別:3 ﾀｸﾞﾛｰﾃｰｼｮﾝ:4
 * @param  long Type 種類  <p>
 *             センサー種別 設定時<p>
 *                   0：センサーなし<p>
 *                   1：反射センサー<p>
 *                   2：透過センサー<p>
 *                   3：透過センサー（手動スレッショルド値使用時）<p>
 *                   4：反射センサー（手動スレッショルド値使用時）<p>
 * 　　　　　　発行方法     設定時<p>
 *                   2：連続発行<p>
 *             発行スピード 設定時<p>
 *                   0：自動<p>
 *                   2：３分割固定（低速）<p>
 *                   3：自動１（高速）<p>
 *                   4：６分割固定（低速）<p>
 *                   5：自動２<p>
 *             リボンモード 設定時<p>
 *                  0：リボンなし<p>
 *             ローテーション 設定時<p>
 *                  0：尻出し印字<p>
 *                  1：頭出し印字<p>
 *
 * @param  LongRef Result ｴﾗｰ情報
 * @return  処理結果 成功：true 失敗：false
 */
- (BOOL) ChangeIssueMode:(long)Flag  withType:(long)Type Result:(LongRef*) Result;

/**
 * 位置微調の変更
 * @param int Flag 変更するモード
 * @param  int Adjust 微調値
 * @param  LongRef Result エラー情報
 * @return  処理結果 成功：true 失敗：false
 */
- (BOOL) ChangePosition:(long)Flag withAdjust:(long) Adjust Result:(LongRef*) Result;

/**
 * 発行ｺﾏﾝﾄﾞ送信
 * @param int IssueCnt 発行枚数
 * @param  int CutInterval カット間隔
 * @param  StringRef PrinterStatus 受信ステータス
 * @param  LongRef Result エラー情報
 * @return 処理結果 成功：true 失敗：false
 */
- (BOOL) Issue:(long)IssueCnt withCutInterval:(long)CutInterval
 PrinterStatus:(StringRef*) PrinterStatus Result:(LongRef*) Result;

/**
 *
 * @param long IssueCnt
 * @param StringRef PrinterStatus
 * @param  LongRef Result
 * @param  long TimeOut
 * @return 処理結果 成功：true 失敗：false
 */
- (BOOL) completionWatchIssue:(long)IssueCnt
                PrinterStatus:(StringRef*) PrinterStatus
                       Result:(LongRef*) Result
                  withTimeOut:(long) TimeOut;

/**
 * ラベル発行コマンドリトライデータバックアップ処理
 * @param long IssueCnt
 * @param  StringRef szTemp
 * @param  StringRef szTitle
 * @param  long iCnt
 * @param  String szPrintMode
 * @param  long iIssCnt
 */
- (void) setRetryIssueDataBackup:(long) IssueCnt
                      withSzTemp:(StringRef*) szTemp
                     withSzTitle:(StringRef*) szTitle
                         withCnt:(long) iCnt
                 withSzPrintMode:(NSString*) szPrintMode
                      whitIssCnt:(long)iIssCnt;


/**
 * LFMﾌｧｲﾙの読み込み
 * @param String FilePathName ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @param  LongRef Result エラー情報
 * @return boolean 実行結果 成功:true 失敗:false
 */
- (BOOL) LoadLfmFile:(NSString*)FilePathName Result:(LongRef*) Result;

// <<<<< 2018-03-12 TIS LoadLfmFile Encoding >>>>>
/**
 * LFMﾌｧｲﾙの読み込み
 * @param String FilePathName ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @param int EncodeType ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @param  LongRef Result エラー情報
 * @return boolean 実行結果 成功:true 失敗:false
 */
- (BOOL) LoadLfmFile:(NSString*)FilePathName EncodeType:(int)EncodeType Result:(LongRef*) Result;
// <<<<< 2018-03-12 TIS LoadLfmFile Encoding >>>>>

/**
 * プリンタ情報ファイル名の取得
 * @param String lpszPath PrtList.iniの格納フォルダへのフルパス
 * @param 	int nSet プリンタ番号
 * @return 	String プリンタ情報ファイル名（フルパス）
 */

- (NSString*) CheckBarset:(NSString*) lpszPath withSet:(long) nSet;

/**
 * プリンタ情報ファイル読み込み
 * @param  LongRef Result
 * @return boolean 処理結果 成功:true 失敗:false
 */
- (BOOL) Initialize:(LongRef*) Result;


/**
 * 90度回転用ﾀﾞﾐｰﾌｧｲﾙのﾌﾙﾊﾟｽを作成
 * @param String szFileName 元ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @param String szFileName 90度回転用ﾀﾞﾐｰﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 */
- (NSString*) CreatePathName90:(NSString*)szFileName;

/**
 * フルパスから、拡張子を取ったファイル名を返す
 * @param String path　ファイルパス
 * @return String 拡張子を取ったファイル名
 */
- (NSString*) GetFileNameWithoutExtension:(NSString*) path;

/**
 * 90度回転用にデータを変更
 * @param String lpFile 90度回転用ﾀﾞﾐｰﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @return 処理結果 成功：true 失敗：false
 */
- (BOOL)ChangeFile:(NSString*) lpFile;


/**
 * 文字列から発見されたインデックスを返す
 * @param String str 検出対象データ
 * @param char[] findwords 検出対象文字列
 * @return int インデックス値
 */
- (long) StringIndexOfAny:(NSString*) str withChars:(char*)findwords withLen:(int)len;

/////QQQ    ///

@end

@interface NSData (BcpIssueNSData)
/**
  　*　サイズを返却
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSUInteger)count;
@end;

#define BCPControl_DialogResult_Abort 3
#define BCPControl_DialogResult_Cancel 2
#define BCPControl_DialogResult_Ignore 5
#define BCPControl_DialogResult_No 7
#define BCPControl_DialogResult_None 0
#define BCPControl_DialogResult_OK 1
#define BCPControl_DialogResult_Retry 4
#define BCPControl_DialogResult_Yes 6

@interface BCPControl_DialogResult : NSObject {
@public
    BCPControl *this$0_;
    int ResultValue_;
}

@property (nonatomic, retain) BCPControl *this$0;
@property (nonatomic, assign) int ResultValue;

+ (int)None;
+ (int)OK;
+ (int)Cancel;
+ (int)Abort;
+ (int)Retry;
+ (int)Ignore;
+ (int)Yes;
+ (int)No;

/**
  　*　initWithBCPControl
  　*
  　* @param BCPControl* outer$0
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)initWithBCPControl:(BCPControl *)outer$0;

/**
  　*　initWithBCPControl
  　*
  　* @param BCPControl* outer$1
  　* @param int init_res
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)initWithBCPControl:(BCPControl *)outer$1
withInt:(int)init_res;
@end


