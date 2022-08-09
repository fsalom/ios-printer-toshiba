//
//  送信データ、未解析受信データ保持クラス
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@class TRANSBLOCK;

@interface TransBlockData : NSObject < NSCopying > {
 @public
  /** 送信ブロック数 */
  long TransBlockCount_;
  /** 送信ブロック配列 */
  NSMutableArray *pTransBlock_;
  /** pCurrentBlock */
  TRANSBLOCK *pCurrentBlock_;
  /** 未解析受信データサイズ */
  long RecDataLength_;
  /** 未解析受信データバッファ */
  NSString *RecBuffer_;
}
/** 送信ブロック数 */
@property (nonatomic, assign) long TransBlockCount;
/** 送信ブロック配列 */
@property (nonatomic, retain) NSMutableArray *pTransBlock;
/** pCurrentBlock */
@property (nonatomic, retain) TRANSBLOCK *pCurrentBlock;
/** 未解析受信データサイズ */
@property (nonatomic, assign) long RecDataLength;
/** 未解析受信データバッファ */
@property (nonatomic, copy) NSString *RecBuffer;

/**
  　*　初期化
  　*
  　* @param int transBlockCount
  　* @param NSMutableArray* pTransBlock
  　* @param TRANSBLOCK* pCurrentBlock
  　* @param int recDataLength
  　* @param NSString* recBuffer
  　* @return 初期化された送信データ、未解析受信データ保持クラスのインスタンス。
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)init:(long)transBlockCount
TransBlock:(NSMutableArray *)pTransBlock
CurrentBlock:(TRANSBLOCK *)pCurrentBlock
          DataLength:(long)recDataLength
     Buffer:(NSString *)recBuffer;

	/**
  　*　CurrentBlockを取得
  　*
  　* @return CurrentBlock
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (TRANSBLOCK *)getpCurrentBlock;

/**
  　*　データクリア
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)ClearData;

/**
  　*　copyWithZone
  　*
  　* @param NSZone* zone
  　* @return id
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (id)copyWithZone:(NSZone *)zone;

/**
  　*　終了処理
  　*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)dealloc;

/**
  　*　pTransBlock取得
  　*
  　* @return NSMutableArray*
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSMutableArray *)getpTransBlock;

/**
  　*　TransBlockのカウントを返却
  　*
  　* @return int TransBlockのカウント
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)getTransBlockCount;

/**
  　*　TransBlockカウントをセット
  　*
  　* @param int transBlockCount
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setTransBlockCountWithInt:(long)transBlockCount;

/**
  　*　pCurrentBlockをセット
  　*
  　* @param TRANSBLOCK* pCurrentBlock
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setpCurrentBlockWithTRANSBLOCK:(TRANSBLOCK *)pCurrentBlock;

/**
  　*　RecDataのレングスを返却
  　*
  　* @return int RecDataのレングス
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (long)getRecDataLength ;

/**
  　*　RecBufferを返却
  　*
  　* @return NSString* RecBuffer
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (NSString *)getRecBuffer;

/**
  　*　RecBufferをセット
  　*
  　* @param NSString* recBuffer
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setRecBufferWithNSString:(NSString *)recBuffer;

/**
  　*　RecDataのレングスをセット
  　*
  　* @param int recDataLength
 　 * @author NC。
 　 * @version 1.0。
 　 * @since 1.0。
  　*/
- (void)setRecDataLength:(long)recDataLength;
@end
