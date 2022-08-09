/************************************************************************
 *																		*
 *		Copyright (C) 2015												*
 *		TOSHIBA TEC CORPORATION All Right Reserved						*
 *		6-78 Minami-cho, Mishima-shi, Shizuoka-ken, JAPAN				*
 *																		*
 ************************************************************************/
/**
 *  @file     TTECBLEHelper.h
 *
 *  @brief    BLEライブラリの内部クラスを用いて下記のAPIを提供する。
 *              - ペリフェラルの検出
 *              - ペリフェラルとの接続
 *              - ペリフェラルとの切断
 *              - サービスとキャラクタリスティックの検出
 *              - キャラクタリスティックの通知の有効化
 *              - ペリフェラルへの書き込み
 *            NSNotificationCenterを使用して以下の通知を行う
 *              - セントラルのステートの更新
 *              - ペリフェラルの検出の通知
 *              - ペリフェラルからの通知
 *              - ペリフェラルとの切断通知
 *
 *  @note    ここでの内部クラスとは以下のクラスを指す
 *              - TTECPeripheralWrapper
 *              - TTECPeripheralWrapperDelegate
 *              - TTECCharacteristicWrapper
 *
 *  @note
 */
/*=====================================================================*/

#import <Foundation/Foundation.h>

#import "TTECCharacteristicWrapper.h"
#import "TTECPeripheralWrapper.h"

/// 通知:BLEのセントラルのステート更新
extern NSString *const kNotificationUpdateCentralState;
/// 通知:ペリフェラルの検出
extern NSString *const kNotificationDiscoverPeripheral;
/// 通知:ペリフェラルからの通知
extern NSString *const kNotificationNotifyPeripheral;
/// 通知:ペリフェラルからの切断通知
extern NSString *const kNotificationDisconnectPeripheral;

/**
 * クラス:BLEマネージャー
 */
@interface TTECBLEHelper : NSObject
/// フラグ:検索時の端末の重複
@property (nonatomic,assign) BOOL isScanOverlay ;
/// ステート
@property (nonatomic,readonly) CBCentralManagerState centralState ;
/// タイムアウト
@property (nonatomic,assign) NSTimeInterval timeout ;
/// 接続先
@property (nonatomic,readonly) TTECPeripheralWrapper* connectedPeripheral ;

#pragma mark - share instance methods
/**
 * インスタンスの生成
 */
+ (instancetype) sharedHelper ;

/**
 * セントラルマネージャーのリセット
 */
- (void) resetCentralManager ;

#pragma mark - search methods
/**
 * ペリフェラルの検出を開始
 *
 * @param [in] serviceUUIDs サービスUUID(CBUUIDの配列)
 */
- (void) startScanWithServiceUUIDs:(NSArray *)serviceUUIDs ;

/**
 * ペリフェラルの検索を停止
 */
- (void) stopScan ;

#pragma mark - connected methods
/**
 * 指定されたペリフェラルに接続
 *
 * @paran [in] peripheral   ペリフェラル
 * @paran [in] response     レスポンス
 */
- (void) connect:(TTECPeripheralWrapper *)peripheral
        response:(TTECPeripheralResponseBlock)response ;

/**
 * ペリフェラルとの接続を切断
 */
- (void) disconnect ;

/**
 * 接続中か取得
 *
 * @return BOOL YES:接続中 NO:未接続
 */
- (BOOL) isConnected ;

/**
 * サービスと特性の検出
 *
 * @param [in] serviceUUIDs サービスUUIDのリスト
 * @param [in] response     レスポンス
 */
- (void) discoverServiceWithServiceUUIDs:(NSArray *)serviceUUIDs
                                response:(TTECPeripheralResponseBlock)response ;

#pragma mark - notification methods
/**
 * 通知の有効化
 *
 * @param [in] serviceUUID          サービスUUID
 * @param [in] characteristicUUID   CharacteristicのUUID
 * @param [in] responseBlock        レスポンス
 */
- (BOOL) setEnableNotificationWithServiceUUID:(CBUUID *)serviceUUID
                           characteristicUUID:(CBUUID *)characteristicUUID
                                responseBlock:(TTECPeripheralResponseBlock)responseBlock ;

#pragma mark - write methods
/**
 * ペリフェラルへの書き込み
 *
 * @param [in] serviceUUID          対象のサービスUUID
 * @param [in] characteristicUUID   対象のCharacteristicUUID
 * @param [in] writeData            書き込むデータ
 * @param [in] responseBlock        ブロック:レスポンス
 */
- (void) writeForServiceUUID:(CBUUID *)serviceUUID
          characteristicUUID:(CBUUID *)characteristicUUID
                   writeData:(NSData *)writeData
               responseBlock:(TTECPeripheralResponseBlock)response ;
@end
