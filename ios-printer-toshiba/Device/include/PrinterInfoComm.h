//
//  プリンター情報（コピー枚数）クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


@interface PrinterInfoComm : NSObject {
@public
    /**
     * ｺﾋﾟｰ枚数(未使用)
     */
    long  numCopies_;
}
@property (nonatomic, assign) long numCopies;

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
