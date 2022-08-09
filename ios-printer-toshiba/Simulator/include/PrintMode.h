//
//  プリントモードクラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//

@interface PrintMode : NSObject {
@public
    /**
     * ｶｯﾄﾓｰﾄﾞ(ｺﾏﾝﾄﾞ文字列)
     */
    NSString* CutMode_;
    /**
     * 発行ﾓｰﾄﾞ(ｺﾏﾝﾄﾞ文字列)
     */
    NSString* m_PrintMode_;
    /**
     * 発行ﾓｰﾄﾞ(画面表示)
     */
    NSString* PrintName_;
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
