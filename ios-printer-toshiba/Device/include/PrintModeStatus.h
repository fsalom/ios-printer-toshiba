//
//  印刷情報保持クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//
#import "ProfileInterface.h"

@class HeadAdl;
@class FeedAdj;

@interface PrintModeStatus : NSObject {
@public
    /**
     * ﾀｸﾞﾛｰﾃｰｼｮﾝ設定配列
     */
    NSMutableArray *m_RotateArray_;
    /**
     * ﾘﾎﾞﾝ種類設定配列
     */
    NSMutableArray *m_RibonArray_;
    /**
     * 発行ｽﾋﾟｰﾄﾞ設定配列
     */
    NSMutableArray *m_SpeedArray_;
    /**
     * ｾﾝｻｰ種類設定配列
     */
    NSMutableArray *m_SensorArray_;
    /**
     * 発行ﾓｰﾄﾞ設定配列
     */
    NSMutableArray *m_PrModeArray_;
    /**
     * 印字濃度微調設定範囲
     */
    HeadAdl *m_HeadAdl_;
    /**
     * 位置微調設定範囲
     */
    FeedAdj *m_FeedAdj_;
    
    /**
     * 上位クラスで生成されているプロファイル系共通処理を呼び出すためのインターフェイス
     */
    id<ProfileInterface> m_profInterface_;
    
}
@property (nonatomic, retain)NSMutableArray *m_RotateArray;
@property (nonatomic, retain)NSMutableArray *m_RibonArray;
@property (nonatomic, retain)NSMutableArray *m_SpeedArray;
@property (nonatomic, retain)NSMutableArray *m_SensorArray;
@property (nonatomic, retain)NSMutableArray *m_PrModeArray;
@property (nonatomic, retain)HeadAdl *m_HeadAdl;
@property (nonatomic, retain)FeedAdj *m_FeedAdj;

/**
 * コンストラクタ
 * @param p_in プロファイル系共通処理を呼び出すためのインターフェイス
 */
- (id)init:(id<ProfileInterface>)p_in;

/**
 * 関数名   : finalize
 * 機能     : ﾃﾞｽﾄﾗｸﾀ
 * 機能説明 : ﾃﾞｽﾄﾗｸﾀ
 * 返り値   : なし
 * 備考     :
 */
- (void)dealloc;

/**
 * 印刷条件読み込み<br>
 * 印刷条件(各微調ｺﾏﾝﾄﾞの範囲や設定ﾘｽﾄ)の読み込み
 * @param szIniFile ﾌﾟﾘﾝﾀ情報ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @return 成功：TRUE、失敗：FALSE
 */
-(BOOL) LoadPrintModeStatus:(NSString*) szIniFile;

/**
 * 印字濃度微調の範囲ﾁｪｯｸ
 * @param iHeat 発色
 * @param iRibon 転写
 * @return 成功：TRUE、失敗：FALSE
 */
-(BOOL)CheckHeadVoltage:(long) iHeat            // 発色
              withRibon:(long) iRibon; // 転写

/**
 * 位置微調の範囲ﾁｪｯｸ
 * @param iFeed ﾌｨｰﾄﾞ量
 * @param iCut ｶｯﾄ位置
 * @param iBackF ﾊﾞｯｸﾌｨｰﾄﾞ量
 * @return 成功：TRUE、失敗：FALSE
 */
-(BOOL) CheckPosition:(long)iFeed  // ﾌｨｰﾄﾞ量
              withCut:(long)iCut   // ｶｯﾄ位置
            withBackF:(long)iBackF;// ﾊﾞｯｸﾌｨｰﾄﾞ量

/**
 * 発行ｺﾏﾝﾄﾞ有効ﾁｪｯｸ
 * @param lpszPrintMode ﾌﾟﾘﾝﾄﾓｰﾄﾞ
 * @param iSpeed 印刷ｽﾋﾟｰﾄﾞ
 * @param iRibon ﾘﾎﾞﾝ種類
 * @param iRotation ﾀｸﾞﾛｰﾃｰｼｮﾝ種別
 * @param iSensor ｾﾝｻｰ種別
 * @return 成功：TRUE、失敗：FALSE
 */
-(BOOL) CheckIssueMode: (NSString*) lpszPrintMode // ﾌﾟﾘﾝﾄﾓｰﾄﾞ
             withSpeed: (long)iSpeed               // 印刷ｽﾋﾟｰﾄﾞ
             withRibon: (long) iRibon				// ﾘﾎﾞﾝ種類
          withRotation: (long) iRotation			// ﾀｸﾞﾛｰﾃｰｼｮﾝ種別
            withSensor: (long) iSensor;			// ｾﾝｻｰ種別


/**
 * カット設定有効チェック<br>
 * カッター有効のモードがあるかどうかチェック
 * @return 成功：TRUE、失敗：FALSE
 */
-(BOOL)CheckCutMode;


/**
 * バックフィード有効チェック<br>
 * バックフィードの範囲設定があるかどうかチェック
 * @return 成功：TRUE、失敗：FALSE
 */
-(BOOL)CheckBkFeed;


/**
 * 設定値のｸﾘｱ
 */
-(void)Clear;


/**
 * 設定ファイルから、文字列型で読み込み
 * @param AppName セクション名
 * @param KeyName キー名
 * @param Default デフォルト値
 * @param FileName iniファイル名
 * @return true:成功/false:失敗
 */

-(NSString*)GetPrivateProfileString:(NSString*) AppName
                        withKeyName:(NSString*) KeyName
                        withDefault:(NSString*) Default
                       withFileName:(NSString*) FileName;


/**
 * 設定ファイルから、文字列型で読み込み
 * @param AppName セクション名
 * @param KeyName キー名
 * @param Default デフォルト値
 * @param FileName iniファイル名
 * @return true:成功/false:失敗
 */
- (int)GetPrivateProfileInt:(NSString *)AppName
                withKeyName:(NSString *)KeyName
                withDefault:(int)Default
               withFileName:(NSString *)FileName;


@end
