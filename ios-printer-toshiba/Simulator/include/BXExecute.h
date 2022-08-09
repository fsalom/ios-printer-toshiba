//
//  発行ｺﾏﾝﾄﾞ
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@interface BXExecute : NSObject {
@public
    long sensor_;		    // ｾﾝｻｰ種別
    long speed_;		    // 発行ｽﾋﾟｰﾄﾞ
    long feedMode_;	        // ﾌｨｰﾄﾞ種別
    long ribon_;		    // ﾘﾎﾞﾝ種別
    long rotation_;	        // ﾀｸﾞﾛｰﾃｰｼｮﾝ種別
    NSString* printMode_;	// 発行ﾓｰﾄﾞ
    NSString* cut_;		    // ｶｯﾄ設定
    long cutPitch_;	        // ｶｯﾄ間隔
}

@property (nonatomic, assign) long sensor;
@property (nonatomic, assign) long speed;
@property (nonatomic, assign) long feedMode;
@property (nonatomic, assign) long ribon;
@property (nonatomic, assign) long rotation;
@property (nonatomic, assign) long cutPitch;


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
