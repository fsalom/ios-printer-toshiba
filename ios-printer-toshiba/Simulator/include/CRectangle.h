//
//  四角形処理クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.


@interface CRectangle : NSObject {
 @public
  long m_x_;
  long m_y_;
  long m_height_;
  long m_width_;
}

@property (nonatomic, assign) long m_x;
@property (nonatomic, assign) long m_y;
@property (nonatomic, assign) long m_height;
@property (nonatomic, assign) long m_width;

/**
 　*　初期化
 　*
 　* @param int x
 　* @param int y
 　* @param int width
 　* @param int height
 　* @return 四角形処理クラスのインスタンス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (id)init:(long)x
          y:(long)y
          width:(long)width
          height:(long)height;

/**
 　*　底辺座標取得
 　*
 　* @return 底辺の座標
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (long)getBottom;

/**
 　*　左座標取得
 　*
 　* @return 左座標
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (long)getLeft;


/**
 　*　ロケーション取得
 　*
 　* @return ロケーション
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (long)getLocation;

/**
 　*　右座標取得
 　*
 　* @return 右座標
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (long)getRight;

/**
 　*　サイズ取得
 　*
 　* @param
 　* @return サイズ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (long)getSize;

/**
 　*　上部座標取得
 　*
 　* @return 上部座標
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (long)getTop;

/**
 　*　left,top,right,bottomの情報から四角形オブジェクトセット
 　*
 　* @param int left 左のX座標
 　* @param int top 上のY座標
 　* @param int right 右のX座標
 　* @param int bottom 下のY座標
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
- (void)setFromLTRB:(long)left
		top:(long)top
		right:(long)right
		bottom:(long)bottom;

/**
 　*　left,top,right,bottomの情報から四角形オブジェクト作成
 　*
 　* @param int left 左のX座標
 　* @param int top 上のY座標
 　* @param int right 右のX座標
 　* @param int bottom 下のY座標
 　* @return 四角形オブジェクトのインスタンス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
 　*/
+ (CRectangle *)FromLTRB:(long)left
		top:(long)top
		right:(long)right
		bottom:(long)bottom;
@end
