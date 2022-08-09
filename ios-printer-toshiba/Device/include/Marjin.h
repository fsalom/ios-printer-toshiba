//
//  設定範囲クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//

@interface Marjin : NSObject {
@public
    /**
     * ﾃﾞﾌｫﾙﾄ値
     */
    long DefData_;
    /**
     * 最大値
     */
    long Maximum_;
    /**
     * 最小値
     */
    long Minimum_;
    
}

@property (nonatomic, assign) long DefData;
@property (nonatomic, assign) long Maximum;
@property (nonatomic, assign) long Minimum;

/**
 * ｺﾝｽﾄﾗｸﾀ
 */
- (id)init;

/**関数名   : finalize
 * 機能     : ﾃﾞｽﾄﾗｸﾀ
 * 機能説明 : ﾃﾞｽﾄﾗｸﾀ
 * 返り値   : なし
 * 備考     :
 */
- (void)dealloc;


/**
 * 設定値の初期化ß
 */
- (void)Clear;

@end
