//
//  文字列クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@interface Charcters : NSObject {
@public
    /** ﾌｫﾝﾄ種類(ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄかｱｳﾄﾗｲﾝﾌｫﾝﾄか) */
    int chara_;
    /** ﾌｫﾝﾄ名(ﾌﾟﾘﾝﾀ) */
    NSString *name_;
    /** ﾌｫﾝﾄ種類(ｺﾏﾝﾄﾞ) */
    NSString *contr_;
    /** ﾌｫﾝﾄ名(ﾃﾞｨｽﾌﾟﾚｲ用) */
    NSString *font_;
    /** 入力可能文字種類(半角、全角、半全混合) */
    int mode_;
    /** 基本ﾌｫﾝﾄのｻｲｽﾞ */
    int point_;
    /** ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄの文字間の基本ｻｲｽﾞ？ */
    int space_;
    /** 斜体ﾌｫﾝﾄか */
    int style_;
    /** ｱｳﾄﾗｲﾝﾌｫﾝﾄの設定可能なｻｲｽﾞ(最小、最大、単位)？ */
    NSString *sizex_;
    /** ｱｳﾄﾗｲﾝﾌｫﾝﾄの設定可能なｻｲｽﾞ(最小、最大、単位)？ */
    NSString *sizey_;
    /** 基本ｻｲｽﾞの何ﾊﾟｰｾﾝﾄか(幅) */
    int offsetx_;
    /** 基本ｻｲｽﾞの何ﾊﾟｰｾﾝﾄか(高さ) */
    int offsety_;
    /** 回転用文字列(回転の設定)の配列 */
    NSMutableArray *turnset_;
}
/** ﾌｫﾝﾄ種類(ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄかｱｳﾄﾗｲﾝﾌｫﾝﾄか) */
@property (nonatomic, assign) int chara;
/** ﾌｫﾝﾄ名(ﾌﾟﾘﾝﾀ) */
@property (nonatomic, copy) NSString *name;
/** ﾌｫﾝﾄ種類(ｺﾏﾝﾄﾞ) */
@property (nonatomic, copy) NSString *contr;
/** ﾌｫﾝﾄ名(ﾃﾞｨｽﾌﾟﾚｲ用) */
@property (nonatomic, copy) NSString *font;
/** 入力可能文字種類(半角、全角、半全混合) */
@property (nonatomic, assign) int mode;
/** 基本ﾌｫﾝﾄのｻｲｽﾞ */
@property (nonatomic, assign) int point;
/** ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄの文字間の基本ｻｲｽﾞ？ */
@property (nonatomic, assign) int space;
/** 斜体ﾌｫﾝﾄか */
@property (nonatomic, assign) int style;
/** ｱｳﾄﾗｲﾝﾌｫﾝﾄの設定可能なｻｲｽﾞ(最小、最大、単位)？ */
@property (nonatomic, copy) NSString *sizex;
/** ｱｳﾄﾗｲﾝﾌｫﾝﾄの設定可能なｻｲｽﾞ(最小、最大、単位)？ */
@property (nonatomic, copy) NSString *sizey;
/** 基本ｻｲｽﾞの何ﾊﾟｰｾﾝﾄか(幅) */
@property (nonatomic, assign) int offsetx;
/** 基本ｻｲｽﾞの何ﾊﾟｰｾﾝﾄか(高さ) */
@property (nonatomic, assign) int offsety;
/** 回転用文字列(回転の設定)の配列 */
@property (nonatomic, strong) NSMutableArray *turnset;

/**
 　*　
 　* 初期化
 　*
 　* @return 初期化されたバーコード回転情報クラスのインスタンス。
 　* @author NC。
 　* @version 1.0。
 　* @since 1.0。
 　* @see CSize。
 　*/
- (id)init;

/**
  　*　終了処理
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)dealloc;

/**
  　*　 配列ｸﾘｱ
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)DeleteTurn;

/**
  　*　配列に追加
  　*
  　* @param String lpStr 追加文字列
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)AddTurn:(NSString *)lpStr;

/**
  　*　指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
  　*
  　* @param int Index 取得開始ｲﾝﾃﾞｯｸｽ
  　* @return NSString ｲﾝﾃﾞｯｸｽのﾃﾞｰﾀ
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)GetTurn:(int)Index;
@end
