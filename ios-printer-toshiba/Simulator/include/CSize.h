//
//  サイズデータクラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface CSize : NSObject {
 @public
  /** 高さ */
  int height_;
  /** 幅 */
  int width_;
}

/** 高さ */
@property (nonatomic, assign) int height;
/** 幅 */
@property (nonatomic, assign) int width;

/**
  　*　初期化
  　*
  　* @param int width 幅
  　* @param int height 高さ
  　* @return 初期化されたサイズデータクラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(int)width
		height:(int)height;

/**
  　*　初期化
  　*
  　* @param CSize* csize サイズデータクラスのインスタンス。
  　* @return 初期化されたサイズデータクラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(CSize *)csize;
@end
