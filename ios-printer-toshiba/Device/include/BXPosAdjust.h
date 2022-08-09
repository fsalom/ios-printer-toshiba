//
//  位置微調
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@interface BXPosAdjust : NSObject {
@public
    NSString* pos_;	    // 現在未使用のﾎﾟｼﾞｼｮﾝｺﾏﾝﾄﾞ文字列
    long xPosOffset_;	// X方向のｵﾌｾｯﾄ
    long leftOffset_;	// 左余白
    long topOffset_;	// 上余白
    long CutAdjust_;	// ｶｯﾄ位置微調
    long FeedAdjust_;	// ﾌｨｰﾄﾞ位置微調
    long StopPos_;	    // ｽﾄｯﾌﾟ位置微調
}

@property (nonatomic, assign) long pos;
@property (nonatomic, assign) long xPosOffset;
@property (nonatomic, assign) long leftOffset;
@property (nonatomic, assign) long topOffset;
@property (nonatomic, assign) long CutAdjust;
@property (nonatomic, assign) long FeedAdjust;
@property (nonatomic, assign) long StopPos;


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
