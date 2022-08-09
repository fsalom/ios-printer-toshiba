//
//  送信ﾌﾞﾛｯｸ構造体
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface TRANSBLOCK : NSObject < NSCopying > {
 @public
  /** ﾊﾞｯﾌｧｻｲｽﾞ */
  long BlockSize_;
  /** 現在の送信ﾊﾞｯﾌｧ(実際の送信ﾊﾞｯﾌｧ) */
  NSMutableData *pBlock_;
}

/** ﾊﾞｯﾌｧｻｲｽﾞ */
@property (nonatomic, assign) long BlockSize;
/** 現在の送信ﾊﾞｯﾌｧ(実際の送信ﾊﾞｯﾌｧ) */
@property (nonatomic,retain) NSMutableData *pBlock;

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
  　*　clear
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)clear;

/**
  　*　終了処理
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)dealloc;

@end
