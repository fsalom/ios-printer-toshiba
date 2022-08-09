//
//  long型参照渡し用クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface LongRef : NSObject {
 @public
  /** longValue */
  long long int longValue_;
}

/** longValue */
@property (nonatomic, assign) long long int longValue;

/**
  　*　setLongValueWithInt
  　*
  　* @param int intValue
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setLongValueWithInt:(int)intValue;

/**
  　*　初期化
  　*
  　* @param long long int value
  　* @return 初期化されたlong型参照渡し用クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(long long int)value;

/**
  　*　初期化
  　*
  　* @param long long int value
  　* @return 初期化されたlong型参照渡し用クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)initWithLongInt:(long long int)value;
@end
