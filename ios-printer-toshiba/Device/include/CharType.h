//
//  文字型クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface CharType : NSObject {
 @public
  /** 選択可能なﾓｰﾄﾞ数 */
  int kind_;
  /** ﾓｰﾄﾞ設定用文字列の配列(ｺﾏﾝﾄﾞ、文字種類) */
  NSMutableArray *mode_;
  /** 文字背景のｴﾘｱの有功無効 0:無効、1:有効 */
  NSMutableArray *BkMode_;
  /** 文字背景のｴﾘｱの縦横の設定の有功無効 */
  NSMutableArray *XYMode_;
}

/** 選択可能なﾓｰﾄﾞ数 */
@property (nonatomic, assign) int kind;
/** ﾓｰﾄﾞ設定用文字列の配列(ｺﾏﾝﾄﾞ、文字種類) */
@property (nonatomic, strong) NSMutableArray *mode;
/** 文字背景のｴﾘｱの有功無効 0:無効、1:有効 */
@property (nonatomic, strong) NSMutableArray *BkMode;
/** 文字背景のｴﾘｱの縦横の設定の有功無効 */
@property (nonatomic, strong) NSMutableArray *XYMode;

/**
  　*　初期化
  　*
  　* @return 初期化された文字型クラスのインスタンス。。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init;
/**
  　*　終了処理
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)dealloc;
/**
  　*　配列のｸﾘｱ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　* @see 関連項目はこのように記述します。
  　*/
- (void)DeleteMode;
/**
  　*　配列に追加
  　*　クラス内部で保持する配列に引数で指定した文字列を追加する
  　*
  　* @param String lpStr 追加文字列
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)AddMode:(NSString *)lpStr;
/**
  　*　ﾃﾞｰﾀの取得
  　*　指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
  　*
  　* @param int Index　取得するｲﾝﾃﾞｯｸｽ値
  　* @return ﾃﾞｰﾀ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)GetMode:(int)Index;
/**
  　*　配列に追加
  　*  配列に追加(文字背景の有功/無効)
  　*
  　* @param String lpStr 追加文字列
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)AddBkMode:(NSString *)lpStr;
/**
  　*　ﾃﾞｰﾀの取得
  　*
  　* @param int Index 取得するｲﾝﾃﾞｯｸｽ
  　* @return 成功：ﾃﾞｰﾀ、失敗：0
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)GetBkMode:(int)Index;
/**
  　*　配列に追加
  　*　配列に追加(文字背景のXY方向の設定)
  　*
  　* @param String lpStr 追加するﾃﾞｰﾀ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)AddXYMode:(NSString *)lpStr;
/**
  　*　ﾃﾞｰﾀの取得
  　*
  　* @param int Index 取得するｲﾝﾃﾞｯｸｽ
  　* @return 成功：ﾃﾞｰﾀ、失敗：0
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (int)GetXYMode:(int)Index;
@end
