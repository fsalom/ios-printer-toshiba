//
//  ヘッド電圧微調設定範囲クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@class Marjin;

@interface HeadAdl : NSObject {
@public
    /** ﾏﾙﾁﾊﾟｽの設定範囲  */
    Marjin *Mult_;
    /**  転写の設定範囲 */
    Marjin *Ribon_;
    /**  発色の設定範囲 */
    Marjin *Heat_;
}

@property (nonatomic, retain) Marjin *Mult;
@property (nonatomic, retain) Marjin *Ribon;
@property (nonatomic, retain) Marjin *Heat;

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
