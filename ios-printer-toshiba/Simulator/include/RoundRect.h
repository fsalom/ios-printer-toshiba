//
//  角丸四角形オブジェクトクラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


#import "Figure.h"

@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface RoundRect : Figure {
@public
    long Radius_;               // 半径
    long PointLine_;            // 線の太さ
    long DrawFlag_;             // 塗りつぶしﾌﾗｸﾞ
    long PointNum_;             // 角数
    long Color_;                // ｶﾗｰｲﾝﾃﾞｯｸｽ
}

#pragma mark Public

/**
 * 初期化関数
 */
- (id)init:(id<ProfileInterface>)p_in;


/**
 * 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ
 */
- (long)GetSendDataSize;

/**
 * ｵﾌﾞｼﾞｪｸﾄの読み込み
 * @param int iCnt      ｵﾌﾞｼﾞｪｸﾄ番号
 * @param String lpszPathName ﾌｫｰﾏｯﾄﾌｧｲﾙのﾌﾙﾊﾟｽ
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)LoadFigure:(long)iCnt                 // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName;  // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/**
 * ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 * @param int iCode ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param TRANSBLOCK wpTrans 送信ﾌﾞﾛｯｸ(未使用)
 * @param BarSet Barset ﾌﾟﾘﾝﾀ情報
 * @param ComStruct pCom 通信設定
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)SetDataCommand:(long)iCode            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK *)wpTrans  // 送信ﾌﾞﾛｯｸ(未使用)
            withBarSet:(BarSet *)Barset       // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct *)pCom;     // 通信設定

@end

