//
//  印刷設定クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//

@class BXDensAdjust;
@class BXExecute;
@class BXLabelSize;
@class BXPosAdjust;
// <<<<< 2018-02-23 TIS Open Type Font addition >>>>>
@class BXOtfSetting;
// <<<<< 2018-02-23 TIS Open Type Font addition >>>>>


@interface PrinterInfoConfig : NSObject {
@public
    /**
     * 発行ｺﾏﾝﾄﾞ送信ﾌﾗｸﾞ
     */
    BOOL m_exeCmdSend_;
    /**
     * 印字濃度微調ｺﾏﾝﾄﾞ送信ﾌﾗｸﾞ
     */
    BOOL m_DensAdjSend_;
    /**
     * 位置微調ｺﾏﾝﾄﾞ送信ﾌﾗｸﾞ
     */
    BOOL m_PosAdjSend_;
    /**
     * ﾗﾍﾞﾙｻｲｽﾞ設定ｺﾏﾝﾄﾞ送信ﾌﾗｸﾞ
     */
    BOOL m_LabelSizeSend_;
    /**
     *  ﾗﾍﾞﾙｻｲｽﾞ
     */
    BXLabelSize *LabelSize_;
    /**
     * 位置微調
     */
    BXPosAdjust *PosAdjust_;
    /**
     * 印字濃度微調
     */
    BXDensAdjust *DensAdjust_;
    /**
     * 発行ｺﾏﾝﾄﾞ
     */
    BXExecute *executeCmd_;
    // <<<<< 2018-02-23 TIS Open Type Font addition >>>>>
    BXOtfSetting *OtfSetting_;
    // <<<<< 2018-02-23 TIS Open Type Font addition >>>>>
}

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 */
- (id)init;

/**
 * 設定値のｸﾘｱ
 */
- (void)Clear;

/**
 * 印字濃度微調ｺﾏﾝﾄﾞ送信状態取得
 * @return 未送信：FALSE、送信済み：TRUE
 */
- (BOOL)GetDensAdjSendState;

/**
 * 発行ｺﾏﾝﾄﾞ送信状態取得
 * @return 未送信：FALSE、送信済み：TRUE
 */
- (BOOL)GetExeCmdSendState;

/**
 * ﾗﾍﾞﾙｻｲｽﾞ設定ｺﾏﾝﾄﾞ送信状態取得
 * @return 未送信：FALSE、送信済み：TRUE
 */
- (BOOL)GetLabelSizeSendState;

/**
 * 位置微調ｺﾏﾝﾄﾞ送信状態取得
 * @return 未送信：FALSE、送信済み：TRUE
 */
- (BOOL)GetPosAdjSendState;

/**
 * 印字濃度微調ｺﾏﾝﾄﾞ送信状態設定<br>
 * 印字濃度微調ｺﾏﾝﾄﾞ送信状態設定(未送信：FALSE、送信済み：TRUE)
 */
- (void)SetDensAdjSendState; // 送信状態

/**
 * 印字濃度微調ｺﾏﾝﾄﾞ送信状態設定<br>
 * 印字濃度微調ｺﾏﾝﾄﾞ送信状態設定(未送信：FALSE、送信済み：TRUE)
 * @param iSet 送信状態
 */
- (void)SetDensAdjSendState:(BOOL)iSet; // 送信状態

/**
 * 発行ｺﾏﾝﾄﾞ送信状態設定
 */
- (void)SetExeCmdSendState; // 送信状態

/**
 * 発行ｺﾏﾝﾄﾞ送信状態設定
 * @param iSet 送信状態(未送信：FALSE、送信済み：TRUE)
 */
- (void)SetExeCmdSendState:(BOOL)iSet; // 送信状態

/**
 * ﾗﾍﾞﾙｻｲｽﾞ設定ｺﾏﾝﾄﾞ送信状態設定<br>
 * ﾗﾍﾞﾙｻｲｽﾞ設定ｺﾏﾝﾄﾞ送信状態設定(未送信：FALSE、送信済み：TRUE)
 */
- (void)SetLabelSizeSendState; // 送信状態

/**
 * ﾗﾍﾞﾙｻｲｽﾞ設定ｺﾏﾝﾄﾞ送信状態設定
 * @param iSet 未送信：FALSE、送信済み：TRUE
 */
- (void)SetLabelSizeSendState:(BOOL)iSet; // 送信状態

/**
 * 位置微調ｺﾏﾝﾄﾞ送信状態設定<br>
 * 位置微調ｺﾏﾝﾄﾞ送信状態設定(未送信：FALSE、送信済み：TRUE)
 */
- (void)SetPosAdjSendState; // 送信状態

/**
 * 位置微調ｺﾏﾝﾄﾞ送信状態設定<br>
 * 位置微調ｺﾏﾝﾄﾞ送信状態設定(未送信：FALSE、送信済み：TRUE)
 * @param iSet 送信状態
 */
- (void)SetPosAdjSendState:(BOOL)iSet; // 送信状態

#pragma mark Protected

/**
 *  関数名   : finalize
 *  機能     : ﾃﾞｽﾄﾗｸﾀ
 *  機能説明 : ﾃﾞｽﾄﾗｸﾀ
 *  返り値   : なし
 *  備考     :
 */
- (void)dealloc;

@end

