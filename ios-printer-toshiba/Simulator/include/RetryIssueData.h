//
//  再印字用データ保持クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//


@interface RetryIssueData : NSObject {
 @public
  long mIssueCnt_;
  long mICnt_;
  NSString *mPrintMode_;
  long mIIssCnt_;
  BOOL mRetryError_;
  NSString *mTitle_;
  NSString *mErrorMessage_;
}

@property (nonatomic, assign) long mIssueCnt;
@property (nonatomic, assign) long mICnt;
@property (nonatomic, copy) NSString *mPrintMode;
@property (nonatomic, assign) long mIIssCnt;
@property (nonatomic, assign) BOOL mRetryError;
@property (nonatomic, copy) NSString *mTitle;
@property (nonatomic, copy) NSString *mErrorMessage;

/**
  　*　初期化
  　*
  　* @return 初期化された受信データオブジェクトクラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init;

/**
  　*　データを一括保持
  　*
  　* @param int issueCnt
  　* @param int icnt
  　* @param NSString* printMode
  　* @param int iissCnt
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)Backup:(long)issueCnt
              icnt:(long)icnt
         printMode:(NSString *)printMode
              iissCnt:(long)iissCnt;

/**
  　*　リトライ可能か
  　*
  　* @return BOOL
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (BOOL)ismRetryError;
@end
