//
//  フィード量設定範囲クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@class Marjin;

@interface FeedAdj : NSObject {
@public
    /** ﾊﾞｯｸﾌｨｰﾄﾞ量の設定範囲  */
    Marjin *BackFed_;  // ﾊﾞｯｸﾌｨｰﾄﾞ量の設定範囲
    /**  ｶｯﾄ位置の設定範囲 */
    Marjin *Cut_;	// ｶｯﾄ位置の設定範囲
    /**  ﾌｨｰﾄﾞ量の設定範囲 */
    Marjin *Feed_;	// ﾌｨｰﾄﾞ量の設定範囲
}

@property (nonatomic, retain) Marjin *BackFed;
@property (nonatomic, retain) Marjin *Cut;
@property (nonatomic, retain) Marjin *Feed;

/**
 * コンストラクタ
 */
- (id)init;   // TODO: コンストラクタ ロジックをここに追加してください。

/**
 * 終了処理
 */
- (void)dealloc;


/**
 * 設定値の初期化ß
 */
- (void)Clear;

@end
