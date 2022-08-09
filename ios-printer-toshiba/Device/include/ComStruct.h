//
//  通信設定クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

#import "BluetoothController.h"

@class LockObject;
@class RecObject;
@class ReceiveData;
@class TransBlockData;
@class LongRef;
@class SocketCommunication;
@class StringRef;
@class NSData;
@class TRANSBLOCK;
@class BluetoothController;
@protocol IComStructCallBack;
@class TTECPeripheralWrapper;



#define ComStruct_BLUETOOTH_DEVNO 5
#define ComStruct_FILE_DEVNO 2
#define ComStruct_TCP_DEFAULT_PORT 5555
#define ComStruct_TCP_DEVNO 3
#define ComStruct_BLE_SEND_INTERVAL 0.05
#define ComStruct_BLE_SEND_MAX_DUMMY_SLEEP 200
#define ComStruct_BLE_CHECKSUM_TIMEOUT 1.0
#define ComStruct_BLE_CONNECT_TIMEOUT 10.0
#define ComStruct_BLE_SEND_MAX_SIZE 20
#define ComStruct_BLE_DEVNO 6

#define ComStruct_BLUETOOTH_PROTOCOL @"jp.co.toshibatec"

@interface ComStruct : NSObject {
 @public
  /** 受信イベント通知インタフェースのインスタンス */
  id<IComStructCallBack> m_CallBack_;
  /** 出力先の種類、COM:0,(DRV:1,)FILE:2,TCP:3,IrDA:4 */
  int DeviceNumber_;
  /** 発行ﾓｰﾄﾞ 0：ファイル、1：送信完了(非同期)、2：発行完了(同期) */
  int iIssMode_;
  /** ｽﾃｰﾀｽ */
  int iStatus_;
  /** ｲﾍﾞﾝﾄｽﾃｰﾀｽ */
  int EventStatus_;
  /** ﾀｲﾑｱｳﾄ値 */
  int dwTimeOut_;
  /** 送信データ、未解析受信データ保持クラスのインスタンス */
  TransBlockData *mTransBlockData_;
  /** 受信データ保持クラスのインスタンス */
  ReceiveData *mReceiveData_;
  /** ソケット通信クラスのインスタンス */
  SocketCommunication *sck_;
  /** ロック用オブジェクト */
  LockObject *mtxSocket_;
  /** ソケット通信断通知済みフラグ */
  BOOL sckErrorReported_;
  /** スレッドステータス */
  BOOL mThreadStatus_;
  /** ソケット受信監視プロセスのスレッドステータス */
  BOOL SocketReceiveWatchProc1_ThreadStatus_;
  /** 書き込み成功フラグ */
  BOOL bWritten_;
  /** コマンドサイズ */
  int COMMANDSIZE_;
  /** 送信データ、未解析受信データ保持クラスのインスタンス */
  TransBlockData *mRetryTransBlockData_;
  /** 受信データ保持クラスのインスタンス */
  ReceiveData *mRetryReceiveData_;
  /** スレッドスリープフラグ */
  BOOL ThreadSleep_;
  /** BT用通信クラスのインスタンス */
  //BluetoothCommunication *m_BlueComm_ ;
  /** 書き込みファイル名 */
  NSString* mFS_;
  /** 書き込みファイルOption */
  int mFileOption;
    
//  NSArray* _peripheralList;
    
    /** BLEデバイス送信シーケンス(index) */
    int bleSendSequence_;
    /** BLEデバイス送信数(count) */
    long bleSendCnt_;
    /** BLEデバイス送信Checksumフラグ　0:未チェック, 1:Checksum OK 2:Checksum Error */
    int bleChecksumFlag_;
    /** BLEデバイスへ一回送信データChecksum値 */
    UInt8 bleChecksumValue_;
    /** BLEデバイスへ一回送信データChecksum String値 */
    NSString* bleChecksumStringValue_;
    /** BLEデバイス送信データ */
    NSData* bleSendData_;
    /** BLEデバイスへ一回送信結果フラグ */
    BOOL blWriteFlag_;
    /** BLEデバイスへ送信中フラグ */
    BOOL blSendingFlag_;
}

/** ソケット通信クラスのインスタンス */
@property (nonatomic, retain) SocketCommunication *sck;
/** 受信イベント通知インタフェースのインスタンス */
@property (nonatomic, retain) id<IComStructCallBack> m_CallBack;
/** 出力先の種類、COM:0,(DRV:1,)FILE:2,TCP:3,IrDA:4 */
@property (nonatomic, assign) int DeviceNumber;
/** 発行ﾓｰﾄﾞ 0：ファイル、1：送信完了(非同期)、2：発行完了(同期) */
@property (nonatomic, assign) int iIssMode;
/** ｽﾃｰﾀｽ */
@property (nonatomic, assign) int iStatus;
/** ｲﾍﾞﾝﾄｽﾃｰﾀｽ */
@property (nonatomic, assign) int EventStatus;
/** ﾀｲﾑｱｳﾄ値 */
@property (nonatomic, assign) int dwTimeOut;
/** 送信データ、未解析受信データ保持クラスのインスタンス */
@property (nonatomic, retain) TransBlockData *mTransBlockData;
/** 受信データ保持クラスのインスタンス */
@property (nonatomic, retain) ReceiveData *mReceiveData;
/** ロック用オブジェクト */
@property (nonatomic, retain) LockObject *mtxSocket;
/** ソケット通信断通知済みフラグ */
@property (nonatomic, assign) BOOL sckErrorReported;
/** スレッドステータス */
@property (nonatomic) BOOL mThreadStatus;
/** ソケット受信監視プロセスのスレッドステータス */
@property (nonatomic, assign) BOOL SocketReceiveWatchProc1_ThreadStatus;
/** 書き込み成功フラグ */
@property (nonatomic, assign) BOOL bWritten;
/** 送信データ、未解析受信データ保持クラスのインスタンス */
@property (nonatomic, retain) TransBlockData *mRetryTransBlockData;
/** 受信データ保持クラスのインスタンス */
@property (nonatomic, retain) ReceiveData *mRetryReceiveData;
/** スレッドスリープフラグ */
@property (nonatomic, assign) BOOL ThreadSleep;
/** コマンドサイズ */
@property (nonatomic, assign) int COMMANDSIZE;
/// 書き込みファイル名
@property (nonatomic,strong) NSString* mFS;
/** 書き込みファイルOption */
@property (nonatomic,assign) int mFileOption;

/// フラグ:検索リトライ
@property (nonatomic,assign) BOOL isScanRetry;
/// ペリフェラルリスト
@property (nonatomic,strong) NSArray* peripheralList;
/// 接続名
@property (nonatomic,strong) NSString* connectName;
/// 接続文字列
@property (nonatomic,strong) NSString* portSetting;
/// 接続済みのペリフェラル
@property (nonatomic,strong) TTECPeripheralWrapper* connect ;
/// 接続済みのペリフェラル
@property (nonatomic, retain) EAAccessory* connectedAccessory;

/// BLE接続デバイス種類：BT:0 BLE:1
@property (nonatomic, assign) int BluetoothType;

+ (int)FILE_DEVNO;
+ (int)BLUETOOTH_DEVNO;
+ (NSString *)TCP_CON_MATCHING;
+ (int)TCP_DEVNO;
+ (int)BLE_DEVNO;

/**
  　*　文字列にstartIndexからcount個を削除
  　*
  　* @param NSString str
  　* @param int startIndex
  　* @param int count
  　* @return NSString
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
+ (NSString *)StrRemove:(NSString *)str
             startIndex:(long)startIndex
                  count:(long)count;

/**
  　*　ﾃﾞｰﾀの取得 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄﾘｽﾄから最初のﾃﾞｰﾀを取得する
  　*
  　* @return RecObject 成功：受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄ、失敗：NULL
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (RecObject *)GetHeadRecData;

/**
  　*　ﾃﾞｰﾀの削除 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄﾘｽﾄの最初のﾃﾞｰﾀを削除する
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)DellRecData;

/**
  　*　初期化
  　*
  　* @param IComStructCallBack callback
  　* @return 初期化された通信設定クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(id<IComStructCallBack>)callback;

/**
  　*　通信設定のｸﾘｱ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)Clear;

/**
   *　通信設定の初期化 通信設定の初期化処理&ﾎﾟｰﾄのｵｰﾌﾟﾝ
   *
   * @param NSString portSetting 通信設定ポート情報
   * @param LongRef Result エラー情報
   * @param int file_option ﾌｧｲﾙの書込みｵﾌﾟｼｮﾝ 0:新規作成   0以外:既存ファイルの終端から書き込む
   * @return BOOL 実行結果 成功：true、失敗：false
   * @author NC。
   * @version 1.0。
   * @since 1.0
   */
- (BOOL)InitializeDevice:(NSString *)portSetting Result:(LongRef *)Result withFileOption:(int)file_option;

/**
  　*　ｿｹｯﾄのｵｰﾌﾟﾝ ｿｹｯﾄのｵｰﾌﾟﾝ&同期ｿｹｯﾄﾚｯﾄﾞの開始を行います
  　*
  　* @param NSString lpszParam コネクションストリング（ホスト名・ポート番号）
  　* @return 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ConnectUnSyncSocket:(NSString *)lpszParam;

/**
  　*　ｿｹｯﾄのｵｰﾌﾟﾝ ｿｹｯﾄのｵｰﾌﾟﾝ&同期ｿｹｯﾄﾚｯﾄﾞの開始を行います
  　*
  　* @param NSString lpszParam コネクションストリング（ホスト名・ポート番号）
  　* @return 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ConnectSyncSocket:(NSString *)lpszParam;

/**
  　*　ﾎﾟｰﾄのｸﾛｰｽﾞ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)CloseDevice;

/**
  　*　スレッドのステータスを開始に変更する
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetStartStatus;

/**
  　*　スレッドのステータスを終了に変更する
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetEndStatus;

/**
  　*　スレッドの実行ステータスの取得
  　*
  　* @return スレッドのステータス 開始:true 終了:false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)CheckThreadStatus;

/**
  　*　ｿｹｯﾄ用ｽﾚｯﾄﾞﾌﾟﾛｼｰｼﾞｬ起動
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SocketUnSyncWatchProc1_run;

/**
  　*　ｽﾚｯﾄﾞﾌﾟﾛｼｰｼﾞｬ起動
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SocketSyncWatchProc1_run;

/**
  　*　送信ﾊﾞｯﾌｧｸﾘｱ 送信ﾌﾞﾛｯｸのﾒﾓﾘを解放する
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)TransClear;

/**
  　*　ｽﾚｯﾄﾞﾌﾟﾛｼｰｼﾞｬ（受信イベント用スレッドクラス）起動
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SocketReceiveWatchProc1_run;

/**
  　*　送信ﾃﾞｰﾀの書き込み(TCPIP)
  　*
  　* @return 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ReceiveSocketData;

/**
  　*　電源断用受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄの作成 電源断用受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄの作成(非同期)
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetNoActiveObject;

/**
  　*　受信ﾃﾞｰﾀの解析 受信ﾃﾞｰﾀから13byteｽﾃｰﾀｽのみ受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄを作成する
  　*
  　* @return BOOL 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)CheckReceiveStatus;

/**
  　*　送信ﾃﾞｰﾀの書き込み
  　*
  　* @return BOOL 処理結果 成功：ture、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)SendSocketData;

/**
  　*　indexOf
  　*
  　* @param NSString* string
  　* @param int ch
  　* @param fromIndex index
  　* @return int
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)indexOf:(NSString *)string ch:(int)ch fromIndex:(int)index;

/**
  　*　ステータス値変換
  　*
  　* @param String Code 変換対象データ
  　* @param StringRef Ret 変換結果
  　* @param int Mode 動作モード 0=5to13 1=13to5
  　* @return 処理結果 成功：ture、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ConvertStatus:(NSString *)Code Ret:(StringRef *)Ret Mode:(int)Mode;

/**
  　*　受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄﾘｽﾄｸﾘｱ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)ListClear;

/**
  　*　送信ｽﾚｯﾄﾞ休止の設定 電源断用受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄの作成(非同期) 実質送信を休止するのは同期の場合のみ
  　*
  　* @param BOOL iFlag 休止の状態 休止中：true、正常動作中：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetSleepThreadWithBOOL:(BOOL)iFlag;

/**
  　*　SetSleepWithBOOL
  　*
  　* @param BOOL iStatus
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetSleepWithBOOL:(BOOL)iStatus;

/**
 * リトライ情報をバックアップする処理
 * @return 処理結果 正常:true 失敗:false
 */
- (BOOL)  backupData;

/**
 * リトライ情報バックアップデータを書き戻す処理
 * @return 処理結果 正常:true 失敗:false
 */
- (BOOL) restoreData;

/**
  　*　リトライ情報バックアップデータをクリアする処理
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)clearData;

/**
  　*　送信ﾌﾞﾛｯｸ取得
  　*
  　* @param int CommandSize 使用ｺﾏﾝﾄﾞｻｲｽﾞ
  　* @return TRANSBLOCK 送信ﾌﾞﾛｯｸ(作業用)のｱﾄﾞﾚｽ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (TRANSBLOCK *)GetTransBlockWithLong:(long)CommandSize;

/**
  　*　送信ﾌﾞﾛｯｸ確保
  　*
  　* @return BOOL 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)GetTransBuffer;

/**
  　*　信ﾌﾞﾛｯｸ(作業用)を送信ﾌﾞﾛｯｸへ移行、送受信ｽﾚｯﾄﾞへ通知
  　*
  　* @return BOOL 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)FlushSendBuffer;

/**
  　*　書き込み終了待ち
  　*  送信ﾌﾞﾛｯｸ数が0になるまで待機する
  　*
  　* @return BOOL 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)WaitReceiveStatus2;

/**
  　*　書き込み終了待ち
  　*
  　* @param int TimeOutCount　ﾀｲﾑｱｳﾄ値
  　* @return BOOL 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)WaitReceiveStatus2WithInt:(int)TimeOutCount;

/**
 * 受信ﾃﾞｰﾀの解析
 * 受信ﾃﾞｰﾀの解析(正常ｽﾃｰﾀｽﾁｪｯｸ用)
 * @return long 処理結果 正常ｽﾃｰﾀｽ：ｽﾃｰﾀｽｺｰﾄﾞ、異常ｽﾃｰﾀｽ：-1または-2
 */
- (long) CheckRecStatusEx3;

/**
 * 受信待ち
 * 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成されるまで待機する
 * 発行終了(40)以外の正常ｽﾃｰﾀｽは無視すること
 * @return boolean 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成：true、ｴﾗｰ：false
 */
- (BOOL) WaitReceiveStatus3; // 　オーバーロード

/**
 * 受信待ち
 * 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成されるまで待機する
 * 発行終了(40)以外の正常ｽﾃｰﾀｽは無視する
 * @param int TimeOutCount ﾀｲﾑｱｳﾄ値
 * @return boolean 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成：true、ｴﾗｰ：false
 */
- (BOOL) WaitReceiveStatus3:(long) TimeOutCount; // ﾀｲﾑｱｳﾄ値

/**
 * 受信待ち
 * 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成されるまで待機する
 *  ﾌｨｰﾄﾞ終了(41)以外の正常ｽﾃｰﾀｽは無視する
 * @return BOOL 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成：true、ｴﾗｰ：false
 */
- (BOOL) WaitReceiveStatus4; // 　オーバーロード

/**
 * 受信待ち
 * 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成されるまで待機する
 *  ﾌｨｰﾄﾞ終了(41)以外の正常ｽﾃｰﾀｽは無視する
 * @param long TimeOutCount ﾀｲﾑｱｳﾄ値
 * @return BOOL 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成：true、ｴﾗｰ：false
 */
- (BOOL) WaitReceiveStatus4:(long)TimeOutCount; // ﾀｲﾑｱｳﾄ値

/**
  　*　受信待ち
  　*  受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成されるまで待機する
  　*  既に受信オブジェクトが存在した場合Trueを返す
  　* @param int TimeOutCount ﾀｲﾑｱｳﾄ値
  　* @return BOOL 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄが作成：true、ｴﾗｰ：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)WaitReceiveStatus5WithInt:(int)TimeOutCount ;

/**
  　*　受信ﾃﾞｰﾀの解析
  　*  受信ﾃﾞｰﾀの解析(正常ｽﾃｰﾀｽﾁｪｯｸ用)
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)CheckRecStatusEx4;

/**
  　*　受信ﾃﾞｰﾀを解析し、ｽﾃｰﾀｽを設定する処理 受信ｲﾍﾞﾝﾄｵﾌﾞｼﾞｪｸﾄから取得した受信ﾃﾞｰﾀを解析し、受信ﾃﾞｰﾀをｴﾗｰ情報を設定する
  　*
  　* @param StringRef PrinterStatus 受信ﾃﾞｰﾀ
  　* @param LongRef Result エラー情報
  　* @return 処理結果 正常ｽﾃｰﾀｽ：0、異常ｽﾃｰﾀｽ：ｽﾃｰﾀｽｺｰﾄﾞ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)CheckRecStatusWithStringRef:(StringRef *)PrinterStatus
                       withLongRef:(LongRef *)Result;
/**
  　*　受信ｽﾃｰﾀｽのﾁｪｯｸ
  　*
  　* @param  String lpStat 受信ステータス
  　* @return int 受信ステータス 正常ｽﾃｰﾀｽ：0、ｴﾗｰｽﾃｰﾀｽ：-1
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)CheckWatchStatusWithNSString:(NSString *)lpStat;

/**
  　*　受信待ち
  　*
  　* @return BOOL 処理結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)WaitReceiveStatus1WithInt:(long)TimeOutCount;

/**
  　*　受信ﾃﾞｰﾀの解析 本処理では、チェック時に受信データオブジェクトの削除しない
  　*
  　* @return int 処理結果 正常ｽﾃｰﾀｽ：0、異常ｽﾃｰﾀｽ：ｽﾃｰﾀｽｺｰﾄﾞまたは-1
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)CheckRecStatusEx ;

/**
 * ペリフェラルの検索を開始
 */
- (void) _startScan;
- (void) didUpdateCentralState:(NSNotification *)notification;

@end

@interface LockObject : NSObject {
@public
    ComStruct *this$0_;
}

@property (nonatomic, retain) ComStruct *this$0;

- (id)init:(ComStruct *)outer$0;
@end

@interface NSThread (BcpIssueThread)
/**
  　*　sleepWithLongInt
  　*
  　* @param long millis
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
+ (void)sleepWithLongInt:(long long int)millis;

/**
  　*　sleepWithLongInt
  　*
  　* @param long millis
  　* @param int nanos
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
+ (void)sleepWithLongInt:(long long int)millis
                 withInt:(int)nanos;
@end

@interface NSString (BcpIssue)

/**
  　*　getBytesWithEncoding
  　*
  　* @param NSString* encoding
  　* @return NSData*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSData *)getBytesWithEncoding:(NSString *)encoding;

/**
  　*　substring
  　*
  　* @param int beginIndex
  　* @param int endIndex
  　* @return NSString*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)substring:(long)beginIndex
               endIndex:(long)endIndex;

/**
  　*　charAtWithInt
  　*
  　* @param int index
  　* @return unichar
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (unichar)charAtWithInt:(long)index;

/**
 　*　setCharAt
 　*
 　* @param int index
 　* @return NSString
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (NSString*)setCharAt:(long)index withChar:(char)newChar;

/**
  　*　trim
  　*
  　* @return NSString* trim
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)trim;

/**
  　*　replace
  　*
  　* @param NSString* oldSequence
  　* @param NSString* newSequence
  　* @return NSString
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)replace:(NSString *)oldSequence
         withSequence:(NSString *)newSequence;

/**
  　*　indexOf
  　*
  　* @param int ch
  　* @return int
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)indexOf:(int)ch;

/**
  　*　indexOf
  　*
  　* @param int ch
  　* @param int index
  　* @return int
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)indexOf:(int)ch fromIndex:(long)index;

/**
  　*　indexOfString
  　*
  　* @param NSString* s
  　* @return int
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)indexOfString:(NSString *)s;

/**
 　*　lastIndexOfString
 　*
 　* @param NSString* s
 　* @return int
 　* @author NC。
 　* @version 1.0。
 　* @since 1.0。
 　*/
- (long)lastIndexOfString:(NSString *)s;

/**
  　*　indexOfString
  　*
  　* @param NSString* s 
  　* @param int index 
  　* @return int
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
-(long)indexOfString:(NSString *)s fromIndex:(long)index;


@end;

