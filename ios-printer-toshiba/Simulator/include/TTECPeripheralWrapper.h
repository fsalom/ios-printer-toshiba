/************************************************************************
 *																		*
 *		Copyright (C) 2015												*
 *		TOSHIBA TEC CORPORATION All Right Reserved						*
 *		6-78 Minami-cho, Mishima-shi, Shizuoka-ken, JAPAN				*
 *																		*
 ************************************************************************/
/**
 *  @file     TTECPeripheralWrapper.h
 *
 *  @brief    Core Bluetoothフレームワークで用意されている、<br>
 *            CBPeripheralを用いて下記のことを行う
 *              - サービスの検出
 *              - キャラクタリスティックの検出
 *              - ペリフェラルへの書き込み
 *              - ペリフェラルからのNotify(Indicate)の通知の受信
 *
 *  @note     
 */
/*=====================================================================*/

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class TTECPeripheralWrapper ;
@class TTECCharacteristicWrapper ;

/**
 * プロトコル:ペリフェラル
 */
@protocol TTECPeripheralWrapperDelegate <NSObject>
/**
 * ペリフェラルからの通知を受信
 *
 * @param [in] peripheral   ペリフェラル
 */
- (void) didUpdateValueForPeripheral:(TTECCharacteristicWrapper *)peripheral ;

@end

/**
 * ブロック:ペリフェラルからのレスポンス
 *
 * @param [in] error    エラー情報(nilの場合は処理が成功)
 */
typedef void (^TTECPeripheralResponseBlock)(NSError* error);

/**
 * クラス:ペリフェラル
 */
@interface TTECPeripheralWrapper : NSObject

/// ペリフェラル
@property (nonatomic,readonly) CBPeripheral* peripheral ;
/// 名前
@property (nonatomic,readonly) NSString* name ;
/// UUID
@property (nonatomic,readonly) CBUUID* uuid ;
/// advertisement情報
@property (nonatomic,readonly) NSDictionary* advertisementData ;
/// RSSI
@property (nonatomic,readonly) NSNumber* RSSI ;
/// エラー
@property (nonatomic,readonly) NSError* error ;

/// デリゲート
@property (nonatomic,assign) id<TTECPeripheralWrapperDelegate> delegate ;

#pragma mark - Utility methods
/**
 * インスタンスの生成
 *
 * @param [in] peripheral   ペリフェラル
 *
 * @return TTECPeripheralWrapper    生成したインスタンス
 */
+ (instancetype) peripheral:(CBPeripheral*)peripheral ;

/**
 * インスタンスの生成
 *
 * @param [in] peripheral           ペリフェラル
 * @param [in] advertisementData    advertisement情報
 * @param [in] RSSI                 RSSI
 *
 * @return TTECPeripheralWrapper    生成したインスタンス
 */
+ (instancetype) peripheral:(CBPeripheral*)peripheral
          advertisementData:(NSDictionary *)advertisementData
                       RSSI:(NSNumber *)RSSI ;

/**
 * 何らかの理由でペリフェラルとの接続が切れた
 *
 * @param [in] error    切断理由
 *                      nilの場合は[cancelPeripheralConnection]で切断された
 */
- (void) disconnectWithError:(NSError *)error ;

/**
 * 接続中か取得
 *
 * @return BOOL YES:接続中 NO:未接続
 */
- (BOOL) isConnected ;

/**
 * 検出済みの特性を取得
 *
 * @param [in] serviceUUID          対象のサービスUUID
 * @param [in] characteristicUUID   対象のcharacteristicUUID
 *
 * @return CBCharacteristic 取得した特性
 */
- (CBCharacteristic *) characteristicWithServiceUUID:(CBUUID *)serviceUUID
                                      characteristic:(CBUUID *)characteristicUUID ;

#pragma mark - connect methods
/**
 * サービスと特性の検出
 *
 * @param [in] serviceUUIDs サービスUUIDのリスト
 * @param [in] response     レスポンス
 */
- (void) discoverServiceWithServiceUUIDs:(NSArray *)serviceUUIDs
                                response:(TTECPeripheralResponseBlock)response ;

/**
 * 通知の有効化
 *
 * @param [in] serviceUUID          サービスUUID
 * @param [in] characteristicUUID   CharacteristicのUUID
 * @param [in] response             レスポンス
 */
- (BOOL) setEnableNotificationWithServiceUUID:(CBUUID *)serviceUUID
                               characteristic:(CBUUID *)characteristicUUID
                                     response:(TTECPeripheralResponseBlock)response ;

#pragma mark - Write methods
/**
 * ペリフェラルへの書き込み
 *
 * @param [in] serviceUUID          対象のサービスUUID
 * @param [in] characteristicUUID   対象のCharacteristicUUID
 * @param [in] writeData            書き込むデータ
 * @param [in] response             ブロック:レスポンス
 */
- (BOOL) writeForServiceUUID:(CBUUID *)serviceUUID
          characteristicUUID:(CBUUID *)characteristicUUID
                   writeData:(NSData *)writeData
                    response:(TTECPeripheralResponseBlock)response ;
@end
