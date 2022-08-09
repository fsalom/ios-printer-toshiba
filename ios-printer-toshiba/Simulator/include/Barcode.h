//
//  バーコードオブジェクトクラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


#import "Figure.h"

@class BarRotate;
@class BarSet;
@class ComStruct;
@class TRANSBLOCK;
@protocol ProfileInterface;

@interface Barcode : Figure {
@public
    BarRotate *m_BarRotate_;       // 回転情報
    char iCheckDigit_;             // ﾁｪｯｸﾃﾞｼﾞｯﾄ
    long Increment_;               // ｲﾝｸﾘﾒﾝﾄ
    long GuardBar_;                // ｶﾞｰﾄﾞﾊﾞｰ高さ
    long BarHeight_;               // ﾊﾞｰｺｰﾄﾞ高さ
    char CDKind_;                  // ﾁｪｯｸﾃﾞｼﾞｯﾄ
    long Orientation_;             // 回転角度
    long UnderChar_;               // ﾊﾞｰ下数字
    long CharSpace_;               // ｷｬﾗｸﾀ間ｽﾍﾟｰｽ
    long WideSpace_;               // ﾜｲﾄﾞﾊﾞｰｽﾍﾟｰｽ
    long NarrowSpace_;             // ﾅﾛｰﾊﾞｰｽﾍﾟｰｽ
    long WideBar_;                 // ﾜｲﾄﾞﾊﾞｰ
    long NarrowBar_;               // ﾅﾛｰﾊﾞｰ(1ﾓｼﾞｭｰﾙ)
    long BarLeng_;                 // 桁数
    char BarKind_;                 // ﾊﾞｰｺｰﾄﾞ種類
    long OffsetX_;                 // X座標補正値
    long OffsetY_;                 // Y座標補正値
}

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 * @param ProfileInterface p_in ProfileInterfaceのインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

/**
 * ｵﾌﾞｼﾞｪｸﾄ種類判断
 */
- (long)CheckObjID;

/**
 * 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾃﾞｰﾀｺﾏﾝﾄﾞｻｲｽﾞ
 */
- (long)GetSendDataSize;

/**
 * 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ取得
 * @return int 送信ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞｻｲｽﾞ
 */
- (long)GetSendFormatSize;

/**
 * ｵﾌﾞｼﾞｪｸﾄの読み込み
 * @param int iCnt      ｵﾌﾞｼﾞｪｸﾄ番号
 * @param String lpszPathName ﾌｧｲﾙのﾌﾙﾊﾟｽ
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)LoadFigure:(long)iCnt                // ｵﾌﾞｼﾞｪｸﾄ番号
      withPathName:(NSString *)lpszPathName; // ﾌｧｲﾙのﾌﾙﾊﾟｽ

/**
 * ﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 * @param int iCode ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param TRANSBLOCK wpTrans 送信ﾊﾞｯﾌｧ
 * @param BarSet Barset ﾌﾟﾘﾝﾀ情報
 * @param ComStruct pCom 通信設定
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)SetDataCommand:(long)iCode              // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
             withTrans:(TRANSBLOCK *)wpTrans    // 送信ﾊﾞｯﾌｧ
            withBarSet:(BarSet *)Barset         // ﾌﾟﾘﾝﾀ情報
         withComStruct:(ComStruct *)pCom;       // 通信設定

/**
 * ﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param 	int iCode ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param 	TRANSBLOCK pTrans   送信ﾊﾞｯﾌｧ
 * @param 	BarSet Barset       ﾌﾟﾘﾝﾀ情報
 * @param 	ComStruct pCom      通信設定
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)SetFormatCommand:(long)iCode            // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK *)pTrans   // 送信ﾊﾞｯﾌｧ
              withBarSet:(BarSet *)Barset       // ﾌﾟﾘﾝﾀ情報
           withComStruct:(ComStruct *)pCom;     // 通信設定

/**
 * 回転情報設定
 * @param  BarRotate Data バーコード回転情報
 */
- (void)SetRotate:(BarRotate *)Data; // 回転設定

#pragma mark Protected

/**
 * ｽﾍﾟｰｽﾃﾞｰﾀ付加ﾁｪｯｸ
 * @param BarSet Barset ﾌﾟﾘﾝﾀ情報
 * @return boolean 付加可能：true、付加不可能：false
 */
- (BOOL)CheckBarSpace:(BarSet *)Barset; // ﾌﾟﾘﾝﾀ情報

/**
 * WPCｽﾍﾟｰｽﾃﾞｰﾀ削除
 * @param BarSet Barset ﾌﾟﾘﾝﾀ情報
 * @return boolean 実行結果 成功:true
 */
- (BOOL)CheckWpcSpace:(BarSet *)Barset;  // ﾌﾟﾘﾝﾀ情報

/**
 * ﾀﾞﾐｰﾃﾞｰﾀｺﾏﾝﾄﾞ作成
 * @param int iCode ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param TRANSBLOCK pTrans 送信ﾊﾞｯﾌｧ
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)DummyDataCommand:(long)iCode           // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
               withTrans:(TRANSBLOCK *)pTrans; // 送信ﾊﾞｯﾌｧ

/**
 * ﾀﾞﾐｰﾌｫｰﾏｯﾄｺﾏﾝﾄﾞ作成
 * @param 	int iCode   ｺﾝﾄﾛｰﾙｺｰﾄﾞ
 * @param 	TRANSBLOCK pTrans 送信ﾊﾞｯﾌｧ
 * @return boolean 実行結果 成功：true、失敗：false
 */
- (BOOL)DummyFormatCommand:(long)iCode           // ｺﾝﾄﾛｰﾙｺｰﾄﾞ
                 withTrans:(TRANSBLOCK *)pTrans; // 送信ﾊﾞｯﾌｧ

/**
 * ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ中にｽﾍﾟｰｽﾃﾞｰﾀを付加する
 * LFMの桁数に満たないﾃﾞｰﾀにｽﾍﾟｰｽﾃﾞｰﾀを付加して、桁数を揃える
 * @param BarSet Barset ﾌﾟﾘﾝﾀ情報
 */
- (void)SetBarSpaceDataWithBarSet:(BarSet *)Barset; // ﾌﾟﾘﾝﾀ情報

/**
 * ｽﾀｰﾄｺｰﾄﾞ/ｽﾄｯﾌﾟｺｰﾄﾞの付加
 * NW-7のﾃﾞｰﾀにｽﾀｰﾄｺｰﾄﾞ/ｽﾄｯﾌﾟｺｰﾄﾞを付加する
 */
- (void)SetStartEnd;



@end
