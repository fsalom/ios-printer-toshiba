//
//  int型参照渡し用クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface IntRef : NSObject {
 @public
  /** 値格納直変数 */
  long intValue_;
}
/** 値格納直変数 */
@property (nonatomic, assign) long intValue;
/**
  　*　初期化
  　*
  　* @param 
  　* @return 初期化されたint型参照渡し用クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(int)value;
@end
