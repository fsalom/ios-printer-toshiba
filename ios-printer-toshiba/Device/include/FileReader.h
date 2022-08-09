//
//  ファイル読込クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface FileReader : NSObject

- (id)initWithFilePath:(NSString *)path;
- (id)initWithFilePath:(NSString *)path encoding:(NSStringEncoding)encoding;
- (id)initWithFilePath:(NSString *)path encoding:(NSStringEncoding)encoding bufferSize:(NSInteger)size;

- (NSString *)readLine;

- (void)close;

@end
