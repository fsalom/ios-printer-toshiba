//
//  バーコード回転情報クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@class CSize;

@interface BarRotate : NSObject {
 @public
  /** 回転座標 */
  CSize *Rotate0_;
  /** 回転座標 */
  CSize *Rotate90_;
  /** 回転座標 */
  CSize *Rotate180_;
  /** 回転座標 */
  CSize *Rotate270_;
}

/** 回転座標 */
@property (nonatomic, retain) CSize *Rotate0;
/** 回転座標 */
@property (nonatomic, retain) CSize *Rotate90;
/** 回転座標 */
@property (nonatomic, retain) CSize *Rotate180;
/** 回転座標 */
@property (nonatomic, retain) CSize *Rotate270;

/**
 　*　
 　* 初期化
 　*
 　* @return 初期化されたバーコード回転情報クラスのインスタンス。
 　* @author NC。
 　* @version 1.0。
 　* @since 1.0。
 　* @see CSize。
 　*/
- (id)init;

/**
 　*　回転情報設定
 　*
 　* @param BarRotate Data 回転情報
 　* @author NC。
 　* @version 1.0。
 　* @since 1.0。
 　* @see CSize。
 　*/
- (void)SetRotate:(BarRotate *)Data;
@end
