
#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

// コマンド送信エラー
#define COMMAND_SEND_ERROR @"1001";

//  通信バッファーサイズ
#define EAD_INPUT_BUFFER_SIZE 2048

extern NSString *EADSessionDataReceivedNotification;
// NOTE: EADSessionController is not threadsafe, calling methods from different threads will lead to unpredictable results
@interface BluetoothController : NSObject <EAAccessoryDelegate, NSStreamDelegate> {
    EAAccessory *_accessory;
    EASession *_session;
    NSString *_protocolString;
    
    NSMutableData *_writeData;
    NSMutableData *_readData;
    
    NSString*       receivedData;
    NSString*       errorMessage;
}

+ (BluetoothController *)sharedController;
+ (void)setNilSessionController;
- (void)setupControllerForAccessory:(EAAccessory *)accessory withProtocolString:(NSString *)protocolString;

- (BOOL)openSession;
- (void)closeSession;

- (BOOL)writeData:(NSData *)data;
- (NSUInteger)readBytesAvailable;
- (NSData *)readData:(NSUInteger)bytesToRead;
- (NSString*)readData;
- (NSData *)readBinData;
- (NSMutableArray *)getReadDataArray;
- (NSInteger)countOfGotData;

- (BOOL)sendCommand:(NSString *) command;

// エラーコード取得
-(NSString *)getErrorCode;
// エラーメッセージ取得
-(NSString *)getErrorMessage;

@property (nonatomic, readonly) EAAccessory *accessory;
@property (nonatomic, readonly) NSString *protocolString;
@property (nonatomic, assign) bool isSessionOpen;
@property (nonatomic, assign) NSString *processType;
@property (nonatomic, assign) bool isReading;
@property (nonatomic, readonly) NSString *errorCode;

@end
