//
//  リボン種類クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
@interface Ribon : NSObject {
@public
    /**
     * ﾘﾎﾞﾝ種類(ｺﾏﾝﾄﾞ文字列)
     */
    NSString* RibonCode_;
    /**
     * ﾘﾎﾞﾝ種類(画面表示)
     */
    NSString* RibonName_;
}

/**
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
