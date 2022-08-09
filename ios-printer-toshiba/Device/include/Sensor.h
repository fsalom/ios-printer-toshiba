//
//  通信設定クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//

@interface Sensor : NSObject {
 @public
    
    /**
     * ｾﾝｻｰ種類(ｺﾏﾝﾄﾞ文字列)
     */
    NSString* SensorCode_;
    /**
     * ｾﾝｻｰ種別(画面表示)
     */
    NSString* SensorName_;
}

/**
 * ｺﾝｽﾄﾗｸﾀ
 */
- (id)init;

/**関数名   : ~Sensor
 * 機能     : ﾃﾞｽﾄﾗｸﾀ
 * 機能説明 : ﾃﾞｽﾄﾗｸﾀ
 * 返り値   : なし
 * 備考     :
 */
- (void)dealloc;

@end
