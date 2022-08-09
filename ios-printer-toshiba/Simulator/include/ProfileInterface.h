//
//  BcpIssue
//
//  Created by NC on 13/01/30.
//  Copyright (c) 2013年 TEC. All rights reserved.
//


@protocol ProfileInterface < NSObject >
- (NSString *)wishGetPrivateProfileString:(NSString *)AppName
                                  KeyName:(NSString *)KeyName
                                  Default:(NSString *)Default
                                 FileName:(NSString *)FileName;
- (int)wishGetPrivateProfileInt:(NSString *)AppName
                        KeyName:(NSString *)KeyName
                        Default:(long)Default
                       FileName:(NSString *)FileName;
- (NSData *)wishGetBytes:(NSString *)szSourceString
            StringLength:(long)StringLength
             UseEncoding:(NSString *)UseEncoding;
- (NSString *)wishGetCurrentEncoding;
- (BOOL)wishGenerateBarcode:(NSString *)BarType
                     CDType:(NSString *)CDType
                     lpData:(NSMutableString *)lpData;
@end
