//
//  ﾗﾍﾞﾙｻｲｽﾞ
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@interface BXLabelSize : NSObject {
@public
    long Pitch_;		// 実際のﾗﾍﾞﾙﾋﾟｯﾁ
    long Width_;		// 実際の用紙幅
    long Gap_;		    // 実際のｷﾞｬｯﾌﾟ
    long FormWide_;	    // 用紙幅
    long FormPitch_;	// ﾗﾍﾞﾙﾋﾟｯﾁ
    long Colums_;		// ｶﾗﾑ数
    long ColumnGap_;	// ｶﾗﾑ間ｷﾞｬｯﾌﾟ
}

@property (nonatomic, assign) long Pitch;
@property (nonatomic, assign) long Width;
@property (nonatomic, assign) long Gap;
@property (nonatomic, assign) long FormWide;
@property (nonatomic, assign) long FormPitch;
@property (nonatomic, assign) long Colums;
@property (nonatomic, assign) long ColumnGap;


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
 * 設定値の初期化
 */
- (void)Clear;
@end
