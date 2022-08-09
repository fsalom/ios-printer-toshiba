//
//  BcpIssue
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013ﾄ・TEC. All rights reserved.
//

@protocol LIBBcpControlCallBack < NSObject >
- (void)BcpControl_OnStatus:(NSString *)PrinterStatus
                            Result:(long long int)Result;
//2017-08-24 E.Ohshima(jse) 接続完了イベント対応 Add Start
- (void)BcpControl_OnOpened:(BOOL*)ReturnValue
                            Result:(LongRef *)Result;
//2017-08-24 E.Ohshima(jse) 接続完了イベント対応 Add End
@end
