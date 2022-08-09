/************************************************************************
 *																		*
 *		Copyright (C) 2015												*
 *		TOSHIBA TEC CORPORATION All Right Reserved						*
 *		6-78 Minami-cho, Mishima-shi, Shizuoka-ken, JAPAN				*
 *																		*
 ************************************************************************/
/**
 *  @file     BLEManager.h
 *
 *  @brief    TTECBLEHelperを用いて以下のことを行う
 *            - ペリフェラルの検出<br>
 *                検出したペリフェラルリストの管理
 *            - ペリフェラルとの接続
 *                - ペリフェラルとの接続
 *                - サービスの検出
 *                - キャラクタリスティックの検出
 *            - ペリフェラルへの書き込み
 *            - ペリフェラルからの通知の受け取り
 *
 *  @note     TTECBLEHelperを継承したクラス
 */
/*=====================================================================*/

#import "TTECBLEHelper.h"

/**
 * クラス:BLEマネージャー
 *
 * TTECBLEHelperを継承したクラスで<br>
 * サービスやキャラクタリスティックの登録など<br>
 * 本アプリ用のメソッドなどを追加定義したクラス<br>
 */
@interface BLEManager : TTECBLEHelper

/// 接続リスト
@property (nonatomic,readonly) NSArray* peripheralList ;

#pragma mark - Utility methods
/**
 * BLEの準備
 */
- (void) ready ;

#pragma mark - scan methods
/**
 * ペリフェラルの検出を開始
 */
- (void) startScan ;

#pragma mark - write methods
/**
 * NSDataの書き込み
 *
 * @param [in] data         deta
 * @param [in] response     ブロック:レスポンス
 */
- (void) writeWithData:(NSData *)data
              response:(TTECPeripheralResponseBlock)response ;

#pragma mark - Notify methods
/**
 * セントラルのステート更新通知を登録
 *
 * @param [in] object   対象のオブジェクト
 * @param [in] action   対象のアクション
 */
- (void) addUpdateCentralStatusObserver:(NSObject *)object action:(SEL)action ;
/**
 * セントラルのステート更新通知を破棄
 *
 * @param [in] object   対象のオブジェクト
 */
- (void) removeUpdateCentralStatusObserver:(NSObject *)object ;

/**
 * ペリフェラルの検出を通知
 *
 * @param [in] object   対象のオブジェクト
 * @param [in] action   対象のアクション
 */
- (void) addDiscoverPeripheralObserver:(NSObject *)object
                                action:(SEL)action ;
/**
 * ペリフェラルの検出を通知を破棄
 *
 * @param [in] object   対象のオブジェクト
 */
- (void) removeDiscoverPeripheralObserver:(NSObject *)object ;

/**
 * ペリフェラルとの切断の通知を通知
 *
 * @param [in] object   対象のオブジェクト
 * @param [in] action   対象のアクション
 */
- (void) addDisconnectedPeripheralObserver:(NSObject *)object
                                    action:(SEL)action ;
/**
 * ペリフェラルとの切断の通知を破棄
 *
 * @param [in] object   対象のオブジェクト
 */
- (void) removeDisconnectedPeripheralObserver:(NSObject *)object ;

/**
 * ペリフェラルからの通知受信(checkSum)を追加
 *
 * @param [in] object   対象のオブジェクト
 * @param [in] action   対象のアクション
 */
- (void) addNotificationCheckSumObserver:(NSObject *)object
                                  action:(SEL)action ;
/**
 * ペリフェラルからの通知受信(checkSum)を破棄
 *
 * @param [in] object   対象のオブジェクト
 */
- (void) removeNotificationCheckSumObserver:(NSObject *)object ;

/**
 * ペリフェラルからの通知受信(データ)を追加
 *
 * @param [in] object   対象のオブジェクト
 * @param [in] action   対象のアクション
 */
- (void) addNotificationDataObserver:(NSObject *)object
                              action:(SEL)action;
/**
 * ペリフェラルからの通知受信(データ)を破棄
 *
 * @param [in] object   対象のオブジェクト
 */
- (void) removeNotificationDataObserver:(NSObject *)object;

/**
 * ペリフェラルからの通知受信(データ)を通知
 *
 * @param [in] value    受信内容(NSData)
 */
- (void) notificationDataWithNSData:(NSData *)value;

@end
