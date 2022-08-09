//
//  double型 参照クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface DoubleRef : NSObject {
 @public
  /** 保持値double */
  double doubleValue_;
}

/** 保持値double */
@property (nonatomic, assign) double doubleValue;

/**
  　*　初期化
  　*
  　* @param double value
  　* @return 初期化されたdouble型 参照クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(double)value;
@end
