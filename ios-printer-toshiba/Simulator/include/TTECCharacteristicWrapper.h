/************************************************************************
 *																		*
 *		Copyright (C) 2015												*
 *		TOSHIBA TEC CORPORATION All Right Reserved						*
 *		6-78 Minami-cho, Mishima-shi, Shizuoka-ken, JAPAN				*
 *																		*
 ************************************************************************/
/**
 *  @file     TTECCharacteristicWrapper.h
 *
 *  @brief    Core Bluetoothフレームワークで用意されている、<br>
 *            CBCharacteristic のラッパークラスのヘッダーファイル
 *
 *  @note     Characteristic 情報へのアクセスをサポートするクラス
 */
/*=====================================================================*/

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

/**
 * クラス:ペリフェラルから通知されたCharacteristics
 */
@interface TTECCharacteristicWrapper : NSObject

/// ペリフェラル
@property (nonatomic,readonly) CBPeripheral* peripheral ;
/// Characteristics:通知
@property (nonatomic,readonly) CBCharacteristic* characteristic ;
/// value
@property (nonatomic,readonly) NSData* value ;
/// UUID
@property (nonatomic,readonly) CBUUID* UUID ;
/// エラー
@property (nonatomic,readonly) NSError* error ;

#pragma mark - Utility methods
/**
 * インスタンスの生成
 *
 * @param [in] characteristic   対象のcharacteristic
 * @param [in] peripheral       対象のペリフェラル
 * @param [in] error            対象のエラー
 *
 * @return TTECCharacteristicWrapper 生成したインスタンス
 */
+ (instancetype) characteristic:(CBCharacteristic *)characteristic
                     peripheral:(CBPeripheral *)peripheral
                          error:(NSError *)error ;

@end
