//
//  プリンター情報クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@class PrinterInfoComm;
@class PrinterInfoConfig;
@class PrinterInfoHeader;
@interface PrinterInfo : NSObject {
@public
    /**
     * ﾌﾟﾘﾝﾀ情報(ｺﾋﾟｰ枚数)
     */
    PrinterInfoComm *piComm_;
    /**
     * 印刷設定
     */
    PrinterInfoConfig *piConfig_;
    /**
     * ﾌﾟﾘﾝﾀ情報
     */
    PrinterInfoHeader *piHead_;
}
@property (nonatomic, retain) PrinterInfoComm *piComm;
@property (nonatomic, retain) PrinterInfoConfig *piConfig;
@property (nonatomic, retain) PrinterInfoHeader *piHead;

/**
 * ｺﾝｽﾄﾗｸﾀ
 */
- (id)init;

/**
 * 関数名   : finalize
 * 機能     : ﾃﾞｽﾄﾗｸﾀ
 * 機能説明 : ﾃﾞｽﾄﾗｸﾀ
 * 返り値   : なし
 * 備考     :
 */
- (void)dealloc;

/**
 * 設定値のｸﾘｱ
 */
- (void)Clear;


@end
