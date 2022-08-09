//
//  Line の概要の説明です。
//  Lineオブジェクトクラス
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


#import "Figure.h"

@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Line : Figure {
@public
    long PointLine_;      // 線の太さ
}

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 * @param p_in ProfileInterfaceのインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;


/**
 * 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ
 */
- (long)GetSendDataSize;

/**
 *  関数名   : LoadFigure
 *  機能     : ｵﾌﾞｼﾞｪｸﾄの読み込み
 *  機能説明 : 指定されたｵﾌﾞｼﾞｪｸﾄの読み込み
 *  返り値   : 成功：TRUE、失敗：FALSE
 *  備考     :
 */
- (BOOL)LoadFigure:(long)iCnt  // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName; // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/**
 *  関数名   : SetDataCommand
 *  機能     : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 *  機能説明 : ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 *  返り値   : 成功：TRUE、失敗：FALSE
 *  備考     :
 */
- (BOOL)SetDataCommand:(long)iCode
             withTrans:(TRANSBLOCK *)wpTrans
            withBarSet:(BarSet *)Barset
         withComStruct:(ComStruct *)pCom;

@end

