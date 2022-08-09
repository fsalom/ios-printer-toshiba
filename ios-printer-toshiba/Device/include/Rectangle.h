//
//  Rectangle の概要の説明です。
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Rectangle : Figure

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 * @param p_in ProfileInterfaceのインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

- (long)GetSendDataSize;

/**
 *  <summary>
 * 指定されたｵﾌﾞｼﾞｪｸﾄの読み込み
 * </summary>
 * <param name="iCnt">ｵﾌﾞｼﾞｪｸﾄ番号</param>
 * <param name="lpszPathName">ﾌｫｰﾏｯﾄﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)</param>
 * <returns>成功：TRUE、失敗：FALSE</returns>
 **/
- (BOOL)LoadFigure:(long)iCnt
      withPathName:(NSString *)lpszPathName;

/** <summary>
 * ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 * </summary>
 * <param name="iCode">ｺﾝﾄﾛｰﾙｺｰﾄﾞ</param>
 * <param name="wpTrans">送信ﾌﾞﾛｯｸ(未使用)</param>
 * <param name="Barset">ﾌﾟﾘﾝﾀ情報</param>
 * <param name="pCom">通信設定</param>
 * <returns>成功：TRUE、失敗：FALSE</returns>
 */
- (BOOL)SetDataCommand:(long)iCode           // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK *)wpTrans // 送信ﾌﾞﾛｯｸ(未使用)
            withBarSet:(BarSet *)Barset      // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct *)pCom;    // 通信設定

@end

