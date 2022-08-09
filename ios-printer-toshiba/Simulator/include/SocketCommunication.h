//
//  ソケット通信クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

#define SocketCommunication_SOCKET_CONNECT_TIMEOUT 5000
#define SocketCommunication_SOCKET_SO_TIMEOUT 10000
#define SocketCommunication_TIMEOUT_CHECK_MSEC 200

@interface SocketCommunication : NSObject<NSStreamDelegate> {
 @public
  /** 接続フラグ */
  BOOL connected_;
  /** データ有フラグ */
  BOOL hasData_;
  /** ホスト */
  NSString *m_savedHostNameString_;
  /** ポート */
  long m_savedPortNumber_;
}

/** ホスト */
@property (nonatomic, copy) NSString *m_savedHostNameString;
/** ポート */
@property (nonatomic, assign) long m_savedPortNumber;
/** 接続フラグ */
@property (nonatomic, assign) BOOL connected;
/** データ有フラグ */
@property (nonatomic, assign) BOOL hasData;

/**
  　*　初期化
  　*
  　* @return 初期化されたソケット通信クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init;

/**
  　*　終了処理
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)dealloc;

/**
  　*　ソケット新規
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)NewSockCreate;

/**
  　*　クライアントソケットのオープン
  　*
  　* @param NSString* HostNameString
  　* @param int PortNumber
  　* @return 実行結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)Open:(NSString *)HostNameString
                 PortNumber:(long)PortNumber;

/**
  　*　クライアントソケットのオープン
  　*
  　* @param NSString* HostNameString
  　* @param int PortNumber
  　* @return 実行結果 成功：true、失敗：false
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ConnectByHostName:(NSString *)HostNameString
                              PortNumber:(int)PortNumber;

/**
  　*　データを送信する
  　*
  　* @param NSData* data
  　* @return int 送ったデータのレングス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)Send:(NSData *)data;

/**
  　*　データを送信する
  　*
  　* @param Byte* buffer
  　* @param int size
  　* @return int 送ったデータのレングス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)Send:(Byte *)buffer size:(int)size;

/**
  　*　データを受信する
  　*
  　* @param Byte* buffer
  　* @return 受信したデータのレングス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)Receive:(Byte *)buffer;

/**
  　*　1970年から1msごとに加算（インクリメント）されているタイマ
  　*
  　* @return long long int 1970年から1msごとに加算（インクリメント）されているタイマ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
+ (long long int)TickCount;

/**
  　*　データを受信する
  　*
  　* @param Byte* buffer
  　* @param int size
  　* @return 受信したデータのレングス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)Receive:(Byte *)buffer size:(int)size;

/**
  　*　データを受信する
  　*
  　* @param Byte* buffer
  　* @param int size
  　* @param int WaitSecond
  　* @return 受信したデータのレングス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)ReceiveTimer:(Byte *)buffer
               size:(long)size
         WaitSecond:(int)WaitSecond;
/**
  　*　ソケットクローズ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)Close;

/**
  　*　ストリーム処理
  　*
  　* @param NSStream* theStream
  　* @param NSStreamEvent streamEvent
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)stream:(NSStream*)theStream handleEvent:(NSStreamEvent)streamEvent;
@end
