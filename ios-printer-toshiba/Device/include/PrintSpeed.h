//
//  印刷スピードクラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//


@interface PrintSpeed : NSObject {
 @public
    /**
     * 印字ｽﾋﾟｰﾄﾞ(ｺﾏﾝﾄﾞ文字列)
     */
    NSString* SpeedCode_;
    /**
     * 印字ｽﾋﾟｰﾄﾞ(画面表示)
     */
    NSString* SpeedName_;
}

/**
   * 関数名   : PrintSpeed
   * 機能     : ｺﾝｽﾄﾗｸﾀ
   * 機能説明 : ｺﾝｽﾄﾗｸﾀ
   * 返り値   : なし
   * 備考     :
   * ｺﾝｽﾄﾗｸﾀ
*/
- (id)init;

/**
   * 関数名   : finalize
   * 機能     : ﾃﾞｽﾄﾗｸﾀ
   * 機能説明 : ﾃﾞｽﾄﾗｸﾀ
   * 返り値   : なし
   * 備考     :
*/
- (void)dealloc;


@end
