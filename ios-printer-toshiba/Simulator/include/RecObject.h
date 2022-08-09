//
//  受信データオブジェクトクラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@class StringRef;

@interface RecObject : NSObject < NSCopying > {
 @public
  /** 受信ﾃﾞｰﾀ */
  NSString *lpData_;
  /** 受信ｽﾃｰﾀｽ */
  long long int mReceiveStatus_;
}

/** 受信ﾃﾞｰﾀ */
@property (nonatomic, copy) NSString *lpData;
/** 受信ｽﾃｰﾀｽ */
@property (nonatomic, assign) long long int mReceiveStatus;

/**
  　*　初期化
  　*
  　* @return 初期化された受信データオブジェクトクラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init;

	/**
  　*　ｲﾍﾞﾝﾄﾃﾞｰﾀの取得
  　*
  　* @param StringRef* szData
  　* @return ｲﾍﾞﾝﾄ情報(ｴﾗｰ情報)
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long long int)GetRecData:(StringRef *)szData;

/**
  　*　受信ﾃﾞｰﾀ設定
  　*
  　* @param int lStatus ｲﾍﾞﾝﾄ情報(ｴﾗｰ情報)
  　* @param NSString* lpcData 受信ﾃﾞｰﾀ
  　* @param int iLen 受信ﾃﾞｰﾀﾚﾝｸﾞｽ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)SetRecDataEx:(int)lStatus
		lpcData:(NSString *)lpcData
		iLen:(int)iLen;

/**
  　*　受信ﾃﾞｰﾀﾚﾝｸﾞｽ
  　*
  　* @param NSZone* zone
  　* @return id
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)copyWithZone:(NSZone *)zone;

/**
  　*　ｵﾌﾞｼﾞｪｸﾄの読み込み
  　*
  　* @param StringRef* szData
  　* @return long long int
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long long int)GetRecDataWithStringRef:(StringRef *)szData;
@end
