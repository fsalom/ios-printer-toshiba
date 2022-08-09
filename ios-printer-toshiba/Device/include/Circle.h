//
//  円オブジェクトクラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


#import "Figure.h"

@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Circle : Figure {
@public
    /** 半径  */
    long Radius_;    // 半径
    /** 線の太さ  */
    long PointLine_; // 線の太さ
    /**  内部塗りつぶしﾌﾗｸﾞ */
    long DrawFlag_;  // 内部塗りつぶしﾌﾗｸﾞ
}

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 * @param ProfileInterface p_in ProfileInterfaceを持つインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

/**
 * 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ
 */
- (long)GetSendDataSize;

/**
 * ｵﾌﾞｼﾞｪｸﾄの読み込み
 * 指定されたｵﾌﾞｼﾞｪｸﾄ番号のﾃﾞｰﾀの読み込み
 * @param int iCnt  ｵﾌﾞｼﾞｪｸﾄ番号
 * @param String lpszPathName  ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @return boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)LoadFigure:(long)iCnt                // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName; // ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/**
 * ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 * @param int iCode             ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param TRANSBLOCK wpTrans  	ﾃﾞｰﾀ作成ﾊﾞｯﾌｧ(使用せず)
 * @param BarSet Barset         ﾌﾟﾘﾝﾀ情報
 * @param ComStruct pCom        通信設定
 * @return boolean 処理結果 成功：true、失敗：false
 */
- (BOOL)SetDataCommand:(long)iCode           // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK *)wpTrans // ﾃﾞｰﾀ作成ﾊﾞｯﾌｧ(使用せず)
            withBarSet:(BarSet *)Barset      // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct *)pCom;    // 通信設定


@end

