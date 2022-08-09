//
//  BcpIssue
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//

@protocol IComStructCallBack < NSObject >
- (void)ComStruct_BcpUnSyncMessage;
//2017-08-24 E.Ohshima(jse) 接続完了イベント対応 Add Start
- (void)ComStruct_BcpBLEUnSyncMessage:(BOOL*)ReturnValue;
//2017-08-24 E.Ohshima(jse) 接続完了イベント対応 Add End
@end
