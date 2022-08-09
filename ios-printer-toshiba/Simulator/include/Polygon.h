//
//  Polygon の概要の説明です。
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
#import "ProfileInterface.h"
#import "Figure.h"

@class TRANSBLOCK;
@class ComStruct;
@class Barset;


@interface Polygon : Figure {
@public
    
}

/**  関数名   : Polygon
 *   能説明 : ｺﾝｽﾄﾗｸﾀ
 *   返り値   : なし
 *   備考     :
 */

- (id)init:(id<ProfileInterface>)p_in;



/**  関数名   : LoadFigure
 *   機能     : ｵﾌﾞｼﾞｪｸﾄの読み込み
 *   機能説明 : 指定したｵﾌﾞｼﾞｪｸﾄの読み込み
 *   返り値   : 成功：TRUE、失敗：FALSE
 *   備考     :
 */

-(BOOL) LoadFigure:(long) iCnt             // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
      withPathName:(NSString*) lpszPathName;  // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/**  関数名   : SetDataCommand
 *   機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 *   機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 *   返り値   : 成功：TRUE、失敗：FALSE
 *    備考     :
 */

-(BOOL) SetDataCommand:(long) iCode            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK*) pTrans    // 送信ﾌﾞﾛｯｸ
            withBarset:(Barset*) Barset        // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct*) pCom;      // 通信設定


@end
