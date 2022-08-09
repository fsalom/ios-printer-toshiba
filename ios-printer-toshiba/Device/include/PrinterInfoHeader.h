//
//  プリンター情報クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


@interface PrinterInfoHeader : NSObject {
@public
    /**
     * ﾌﾟﾘﾝﾀﾀｲﾌﾟ
     */
    NSString* piType_;
    /**
     * ﾌﾟﾘﾝﾀﾊﾞｰｼﾞｮﾝ
     */
    NSString* piVer_;
    
}

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
