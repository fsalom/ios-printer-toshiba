/************************************************************************
 *																		*
 *		Copyright (C) 2015												*
 *		TOSHIBA TEC CORPORATION All Right Reserved						*
 *		6-78 Minami-cho, Mishima-shi, Shizuoka-ken, JAPAN				*
 *																		*
 ************************************************************************/
/**
 *  @file     TTECBLECentralManager.h
 *
 *  @brief    Core Bluetoothフレームワークで用意されている、<br>
 *            CBCentralManagerを制御するためのクラスで下記のことを行う
 *              - セントラルのステートの監視
 *              - ペリフェラルの検出
 *              - ペリフェラルとの接続
 *              - ペリフェラルとの切断
 *
 *  @note     
 *
 */
/*=====================================================================*/

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

#import "TTECPeripheralWrapper.h"

@class TTECPeripheralWrapper ;

/**
 * プロトコル:BLEのセントラルマネージャー
 */
@protocol TTECBLECentralManagerDelegate <NSObject>
#pragma mark - Central delegete methods
/**
 * セントラルのステートが更新
 *
 * @param [in] state    ステート
 */
- (void) updateCentralState:(CBCentralManagerState)state ;

/**
 * ペリフェラルが検出された
 *
 * @param [in] peripherals  検出したペリフェラルのリスト
 */
- (void) didDiscoverPeripherals:(NSArray *)peripherals ;

/**
 * 接続の可否
 *
 * @param [in] peripheralDic    接続先
 * @param [in] erroe            エラー
 */
- (void) didConnectPertipheral:(CBPeripheral *)peripheralDic
                         error:(NSError *)error ;

/**
 * ペリフェラルとの接続が切れた
 *
 * @param [in] peripheral   対象のペリフェラル
 * @param [in] error        エラー
 *
 * @memo
 *      cancelPeripheralConnection以外で切断された場合は
 *      引数[error]に内容が格納されている
 */
- (void) didDisconnectPeripheral:(CBPeripheral *)peripheral
                           error:(NSError *)error ;

@end

/**
 * クラス:BLEセントラルマネージャー
 */
@interface TTECBLECentralManager : NSObject

/// フラグ:検索時の端末の重複
@property (nonatomic,assign)    BOOL isScanOverlay ;
/// ステート
@property (nonatomic,readonly)  CBCentralManagerState state ;
/// タイムアウト
@property (nonatomic,assign)    NSTimeInterval timeout ;
/// デリゲート
@property (nonatomic,assign)    id<TTECBLECentralManagerDelegate> delegeate ;

#pragma mark - share instance methods
/**
 * インスタンスの生成
 *
 * @return 生成したインスタンス
 */
+ (instancetype) shareManager ;

#pragma mark - Utility methods
/**
 * セントラルマネージャーのリセット
 */
- (void) resetManager ;

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
 * @param [in] info   対象のペリフェラル
 */
- (void) connect:(TTECPeripheralWrapper *)info ;

/**
 * 対象のペリフェラルとの接続を切る
 *
 * @param [in] info ペリフェラル
 */
- (void) disconnect:(TTECPeripheralWrapper *)info ;

@end

