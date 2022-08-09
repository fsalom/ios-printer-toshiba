//
//  受信データ保持クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface ReceiveData : NSObject < NSCopying > {
 @public
  /** データ配列 */
  NSMutableArray *mReceiveDataList_;
}

/** データ配列 */
@property (nonatomic, retain) NSMutableArray *mReceiveDataList;

/**
  　*　初期化
  　*
  　* @param 
  　* @return 初期化された受信データ保持クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(NSMutableArray *)mObList;

/**
  　*　データクリア
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)ClearData;

/**
  　*　データリスト設定
  　*
  　* @param mObList データリスト
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setReceiveDataList:(NSMutableArray *)mObList;

/**
  　*　copyWithZone
  　*
  　* @param NSZone* zone
  　* @return id
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)copyWithZone:(NSZone *)zone;

/**
  　*　データ配列取得
  　*
  　* @return NSMutableArray*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSMutableArray *)getReceiveDataList;
@end
