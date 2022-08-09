//
//  文字列クラス
//
//  Created by NC on 16/03/03.
//  Copyright (c) 2016年 TEC. All rights reserved.
//

@interface Charcters : NSObject {
@public
    /** ﾌｫﾝﾄ種類(ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄかｱｳﾄﾗｲﾝﾌｫﾝﾄか) */
    long chara_;
    /** ﾌｫﾝﾄ名(ﾌﾟﾘﾝﾀ) */
    NSString *name_;
    /** ﾌｫﾝﾄ種類(ｺﾏﾝﾄﾞ) */
    NSString *contr_;
    /** ﾌｫﾝﾄ名(ﾃﾞｨｽﾌﾟﾚｲ用) */
    NSString *font_;
    /** 入力可能文字種類(半角、全角、半全混合) */
    long mode_;
    /** 基本ﾌｫﾝﾄのｻｲｽﾞ */
    long point_;
    /** ﾋﾞｯﾄﾏｯﾌﾟﾌｫﾝﾄの文字間の基本ｻｲｽﾞ？ */
    long space_;
    /** 斜体ﾌｫﾝﾄか */
    long style_;
    /** ｱｳﾄﾗｲﾝﾌｫﾝﾄの設定可能なｻｲｽﾞ(最小、最大、単位)？ */
    NSString *sizex_;
    /** ｱｳﾄﾗｲﾝﾌｫﾝﾄの設定可能なｻｲｽﾞ(最小、最大、単位)？ */
    NSString *sizey_;
    /** 基本ｻｲｽﾞの何ﾊﾟｰｾﾝﾄか(幅) */
    long offsetx_;
    /** 基本ｻｲｽﾞの何ﾊﾟｰｾﾝﾄか(高さ) */
    long offsety_;
    /** 回転用文字列(回転の設定)の配列 */
    NSMutableArray *turnset_;
}

#pragma mark Public

/**
 ｺﾝｽﾄﾗｸﾀ
 */
- (id)init;

/**
 * 配列ｸﾘｱ
 * @param String lpStr 追加文字列
 */
- (void)AddTurn:(NSString *)lpStr;


/**
 * 指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
 * @param int Index 取得開始ｲﾝﾃﾞｯｸｽ
 */
- (NSString *)GetTurn:(long)Index;

#pragma mark Protected

- (void)DeleteTurn;

- (void)dealloc;

@end

/**
 * 文字型クラス
 */
@interface CharType : NSObject {
@public
    /**
     * 文字型クラス
     */
    long kind_;               //CHARTYPE	KIND	// 選択可能なﾓｰﾄﾞ数
    /** ﾓｰﾄﾞ設定用文字列の配列(ｺﾏﾝﾄﾞ、文字種類) */
    NSMutableArray *mode_;   //				MODE	// ﾓｰﾄﾞ設定用文字列の配列(ｺﾏﾝﾄﾞ、文字種類)
    /** 文字背景のｴﾘｱの有功無効 0:無効、1:有効 */
    NSMutableArray *BkMode_; //CHARTYPE		MODE_BK	// 文字背景のｴﾘｱの有功無効 0:無効、1:有効
    /** 文字背景のｴﾘｱの縦横の設定の有功無効 */
    NSMutableArray *XYMode_; //				MODE_XY	// 文字背景のｴﾘｱの縦横の設定の有功無効//						0:XY共に無効
    //						1:X方向のみ有効
    //						2:Y方向のみ有効
    //						3:XY共に有効
    
}

#pragma mark Public

/**
 * ｺﾝｽﾄﾗｸﾀ
 * 内部で保持する配列のｸﾘｱをおこなう
 */
- (id)init;

/**
 * 配列に追加
 * 配列に追加(文字背景の有功/無効)
 * @param String lpStr 追加文字列
 */
- (void)AddBkMode:(NSString *)lpStr;

/**
 * 配列に追加
 * クラス内部で保持する配列に引数で指定した文字列を追加する
 * @param String lpStr 追加文字列
 */
- (void)AddMode:(NSString *)lpStr;

/**
 * 配列に追加
 * 配列に追加(文字背景のXY方向の設定)
 * @param String lpStr 追加するﾃﾞｰﾀ
 */
- (void)AddXYMode:(NSString *)lpStr;

/**
 * ﾃﾞｰﾀの取得
 * @param int Index 取得するｲﾝﾃﾞｯｸｽ
 * @return 成功：ﾃﾞｰﾀ、失敗：0
 */
- (long)GetBkMode:(long)Index;

/**
 * ﾃﾞｰﾀの取得
 * 指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
 * @param int Index　取得するｲﾝﾃﾞｯｸｽ値
 */
- (NSString *)GetMode:(long)Index;

/**
 * ﾃﾞｰﾀの取得
 * @param int Index 取得するｲﾝﾃﾞｯｸｽ
 * @return 成功：ﾃﾞｰﾀ、失敗：0
 */
- (long)GetXYMode:(long)Index;

#pragma mark Protected

/**
 * 配列のｸﾘｱ
 */
- (void)DeleteMode;

/**
 * 終了処理
 * 内部で保持する配列のｸﾘｱをおこなう
 */
- (void)dealloc;

@end


@class BarRotate;
@class CharType;
@class Charcters;
@class DoubleRef;
@protocol ProfileInterface;

@interface BarSet : NSObject {
@public
    /**  ﾌﾟﾘﾝﾀ名 */
    NSString *printer_;     //PRINTSYSTEM	PRINTER			// ﾌﾟﾘﾝﾀ名
    /**  ﾌﾟﾘﾝﾀのDPI(横) */
    long print_dpix_;       //				PRINT_DPIX		// ﾌﾟﾘﾝﾀのDPI(横)
    /**  ﾌﾟﾘﾝﾀのDPI(縦) */
    long print_dpiy_;       //				PRINT_DPIY		// ﾌﾟﾘﾝﾀのDPI(縦)
    /**  1ﾄﾞｯﾄの大きさ(横) */
    long print_dotx_;       //				PRINT_DOTX		// 1ﾄﾞｯﾄの大きさ(横)
    /**  1ﾄﾞｯﾄの大きさ(縦) */
    long print_doty_;       //				PRINT_DOTY		// 1ﾄﾞｯﾄの大きさ(縦)
    /**  ｶﾗｰの使用の可不可 */
    long color_;            //				COLOR			// ｶﾗｰの使用の可不可
    /**  ｵﾌﾞｼﾞｪｸﾄの最大数 */
    long obj_max_;          //				OBJ_MAX			// ｵﾌﾞｼﾞｪｸﾄの最大数
    /**  ﾊﾞｰｺｰﾄﾞの最大数 */
    long bar_max_;          //				BAR_MAX			// ﾊﾞｰｺｰﾄﾞの最大数
    /**  ﾋﾞｯﾄﾏｯﾌﾟの最大数 */
    long graph_max_;        //				GRAPH_MAX		// ﾋﾞｯﾄﾏｯﾌﾟの最大数
    /**  ﾃｷｽﾄの最大数 */
    long text_max_;         //				TEXT_MAX		// ﾃｷｽﾄの最大数
    /**  ﾌｫﾝﾄ登録数 */
    long chara_kind_;       //CHARACTERS	KIND			// ﾌｫﾝﾄ登録数
    /**  ﾌｫﾝﾄの設定(配列) */
    NSMutableArray *characters_; //				CHAR ... TURNSET// ﾌｫﾝﾄの設定(配列)
    /**  横倍率の設定数 */
    long widthcount_;       //				WIDTHCOUNT		// 横倍率の設定数
    /**  横倍率の設定文字列(倍率、表示用文字列、ｺﾏﾝﾄﾞ) */
    NSMutableArray *widtname_; //				WIDTNAME		// 横倍率の設定文字列(倍率、表示用文字列、ｺﾏﾝﾄﾞ)
    /**  縦倍率の設定数 */
    long hightcount_;       //				HIGHTCOUNT		// 縦倍率の設定数
    /**  縦倍率の設定文字列(倍率、表示用文字列、ｺﾏﾝﾄﾞ) */
    NSMutableArray *higtname_; //				HIGTNAME		// 縦倍率の設定文字列(倍率、表示用文字列、ｺﾏﾝﾄﾞ)
    /**  文字間の設定の可不可 */
    long charspace_;        //CHARSYSTEM	CHARSPACE		// 文字間の設定の可不可
    /**  行間の設定の可不可 */
    long linespace_;        //				LINESPACE		// 行間の設定の可不可
    /**   */
    long spacing_;          //				SPACING			//
    /**  強調の設定の可不可 */
    long bold_;             //				BOLD			// 強調の設定の可不可
    /** 文字種類の設定(配列)  */
    NSMutableArray *chartype_;  //CHARTYPE						// 文字種類の設定(配列)
    /** ﾊﾞｰｺｰﾄﾞの回転設定  */
    long turnbarseting_[5]; //TURNBARSETING TURNSET			// ﾊﾞｰｺｰﾄﾞの回転設定
    /**  ﾊﾞｰｺｰﾄﾞの使用の可不可//V2ﾊﾞｰｺｰﾄﾞの数変更 */
    long barcode_[23];     //BARCODE
    /**  ﾃﾞｰﾀｺｰﾄﾞの使用の可不可 */
    long datacode_enable_; //DATACODE		ENABLEF			// ﾃﾞｰﾀｺｰﾄﾞの使用の可不可
    /**  ﾃﾞﾌｫﾙﾄ表示のﾋﾞｯﾄﾏｯﾌﾟﾌｧｲﾙ名(FULL PATH)//V2 */
    NSString *def_datacode_; //				DEFBMP			// ﾃﾞﾌｫﾙﾄ表示のﾋﾞｯﾄﾏｯﾌﾟﾌｧｲﾙ名(FULL PATH)//V2
    /**  PDFの使用の可不可 */
    long pdfcode_enable_;  //PDFCODE		ENABLEF			// PDFの使用の可不可
    
    long qrcode_enable_;  //QRCODE		ENABLEF			// QRｺｰﾄﾞの使用の可不可
    
    NSString *def_qrcode_; //				DEFBMP			// ﾃﾞﾌｫﾙﾄ表示のﾋﾞｯﾄﾏｯﾌﾟﾌｧｲﾙ名(FULL PATH)//V2
    
    long postcode_enable_; //POSTCODE		ENABLEF			// POSTCODEの使用の可不可//V2
    
    NSString *def_postcode_; //				DEFBMP			// ﾃﾞﾌｫﾙﾄ表示のﾋﾞｯﾄﾏｯﾌﾟﾌｧｲﾙ名(FULL PATH)//V2
    
    long maxicode_enable_; //MAXICODE		ENABLEF			// MAXICODEの使用の可不可//V2
    
    NSString *def_maxicode_; //				DEFBMP			// ﾃﾞﾌｫﾙﾄ表示のﾋﾞｯﾄﾏｯﾌﾟﾌｧｲﾙ名(FULL PATH)//V2
    
    long gaiji_enable_;    //FREEGAIJI		ENABLEF			// FREEGAIJIの使用の可不可//V2
    
    NSString *def_gaiji_;  //			DEFBMP			// FREEGAIJIのﾃﾞﾌｫﾙﾄ表示のﾋﾞｯﾄﾏｯﾌﾟﾌｧｲﾙ名(FULL PATH)//V2
    
    long gaiji_kind_;  //GAIJITOOL		KIND			// 使用可能な外字数(ｺﾝﾎﾞﾎﾞｯｸｽの初期化等に使用)//V2
    
    Charcters *gaiji_char_; //				CHAR ... TURNSET// FREEGAIJIの文字設定(外字種類共通で使用)//V2
    // ただし外字ではいくつかの項目が0の設定
    // 場合によっては外字用のArrayに変更するかも
    // 外字の倍率は文字ｵﾌﾞｼﾞｪｸﾄと共通で使用
    long line_enable_;     //LINETOOL		ENABLEF			// 線の使用の可不可
    
    long linecount_;       //				LINECOUNT		// 線の登録数
    
    NSString *linestyle_;  //				LINESTYLE		// 線のｽﾀｲﾙ
    
    NSString *displin_;    //				DISPLIN			// 表示用の線の太さ
    
    NSString *prinlin_;    //				PRINLIN			// ｺﾏﾝﾄﾞの線の太さ
    
    long facecolor_;       //FIGURETOOL	FACECOLOR		// 面色の設定の可不可
    
    long linecolor_;       //				LINECOLOR		// 線色の設定の可不可
    
    long colorfill_;       //				COLORFILL		// 塗りつぶしの設定の可不可
    
    long rect_enable_;     //RECTANGLETOOL	ENABLEF			// 四角形の使用の可不可
    
    long rndrect_enable_;  //ROUNDRECTTOOL	ENABLEF			// 角丸四角形の使用可不可
    
    long circle_enable_;   //CIRCLETOOL	ENABLEF			// 円の使用の可不可
    
    long polygon_enable_;  //POLYGONTOOL	ENABLEF			// 多角形の使用の可不可
    
    long bmp_autozoom_;    //BITMAPTOOL	AUTOZOOM		// ﾋﾞｯﾄﾏｯﾌﾟの自動伸縮の可不可
    
    long bmp_sizelimit_;   //				SIZELIMIT		// ﾋﾞｯﾄﾏｯﾌﾟｻｲｽﾞの制限が有るか
    
    long bmp_width_;       //				WIDTH			// 横幅制限ｻｲｽﾞ
    
    long bmp_height_;      //				HEIGHT			// 縦幅制限ｻｲｽﾞ
    
    long bmp_enable_;      //BITMAPTOOL	ENABLEF			// ﾋﾞｯﾄﾏｯﾌﾟの使用の可不可
    
    long datacode_ecc200_; //DATACODE		ExtensionUse	// ECC200対応の設定の有効無効
    
    long fillcolor_max_;   //PRINTSYSTEM	FILLCOLOR_MAX	// 塗りつぶしの最大数(51)
    
    long max_boldx_;       //CHARSYSTEM	BOLDMAX			// 文字強調の最大ﾄﾞｯﾄ数横方向
    
    long max_boldy_;       //				BOLDMAX			// 文字強調の最大ﾄﾞｯﾄ数縦方向
    
    
    /** 機種ｴﾗｰ判断用ﾌﾗｸﾞ */
    long iErrType_;       // 機種ｴﾗｰ判断用ﾌﾗｸﾞ
    /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換用判断ﾃﾞｰﾀ */
    NSString *BarCheck_;  // ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換用判断ﾃﾞｰﾀ
    /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換用埋めの設定 */
    long BarFill_;        // ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換用埋めの設定
    /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換用寄せの設定 */
    long BarEdit_;        // ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換用寄せの設定
    /** ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換の有無 */
    long BarMode_;        // ﾊﾞｰｺｰﾄﾞﾃﾞｰﾀ変換の有無
    /** ﾋﾞｯﾄﾏｯﾌﾟ送信用X座標移動量 */
    long SendPosY_;       // ﾋﾞｯﾄﾏｯﾌﾟ送信用X座標移動量
    /** ﾋﾞｯﾄﾏｯﾌﾟ送信用Y座標移動量 */
    long SendPosX_;       // ﾋﾞｯﾄﾏｯﾌﾟ送信用Y座標移動量
    /** ﾋﾞｯﾄﾏｯﾌﾟ送信用X方向読み込みﾊﾞｲﾄ数 */
    long iSendY_;         // ﾋﾞｯﾄﾏｯﾌﾟ送信用X方向読み込みﾊﾞｲﾄ数
    /** ﾋﾞｯﾄﾏｯﾌﾟ送信用Y方向読み込みﾗｲﾝ数 */
    long iSendX_;         // ﾋﾞｯﾄﾏｯﾌﾟ送信用Y方向読み込みﾗｲﾝ数
    /** WPCﾃﾞｰﾀ変換の有無 */
    long WpcFlag_;        // WPCﾃﾞｰﾀ変換の有無
    /** ﾚｺｰﾄﾞ単位印刷の有無 */
    long RecordPrintFlag_;// ﾚｺｰﾄﾞ単位印刷の有無
    /** ｺﾋﾟｰ単位印刷の有無 */
    long CopyPrintFlag_;  // ｺﾋﾟｰ単位印刷の有無
    /** ﾌｧｲﾙの書込みｵﾌﾟｼｮﾝ */
    long FileOption_;     // ﾌｧｲﾙの書込みｵﾌﾟｼｮﾝ
    /** */
    BarRotate *m_BarRotate_;
}

#pragma mark Public

/**
 * 終了処理
 * @param ProfileInterface p_in　ProfileInterfaceインタフェースを持つインスタンス
 */
- (id)init:(id<ProfileInterface>)p_in;

/**
 * 配列に追加
 * @param Charcters pFigure  追加ﾃﾞｰﾀ
 */
- (void)AddChar:(Charcters *)pFigure; // 追加ﾃﾞｰﾀ

/**
 * 配列に追加(文字種類)
 * @param CharType pFigure 追加するﾃﾞｰﾀ
 */
- (void)AddCharType:(CharType *)pFigure; // 追加ﾃﾞｰﾀ

/**
 * 配列に追加
 * @param String lpStr 追加ﾃﾞｰﾀ
 */
- (void)AddHight:(NSString *)lpStr; // 追加ﾃﾞｰﾀ

/**
 * 配列に追加
 * 配列に追加(横倍率設定)
 * @param String lpStr  追加ﾃﾞｰﾀ
 */
- (void)AddWidth:(NSString *)lpStr; // 追加ﾃﾞｰﾀ

/**
 * ﾃﾞｰﾀの取得
 * 指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
 * @param int Index  取得するｲﾝﾃﾞｯｸｽ
 * @return Charcters 指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀ
 */
- (Charcters *)GetCharcters:(long)Index; // 取得するｲﾝﾃﾞｯｸｽ

/**
 * ﾃﾞｰﾀの取得
 * 指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
 * @param int Index 取得するｲﾝﾃﾞｯｸｽ
 * @return CharType 成功：ﾃﾞｰﾀ、失敗：NULL
 */
- (CharType *)GetCharType:(long)Index; // 取得するｲﾝﾃﾞｯｸｽ

/**
 * ﾌｫﾝﾄｻｲｽﾞ取得
 * 指定したｺﾏﾝﾄﾞ文字列のﾌｫﾝﾄｻｲｽﾞ(ﾎﾟｲﾝﾄ)＆微調値を取得
 * @param 	String lpFont  	文字種類のｺﾏﾝﾄﾞ文字列
 * @param 	DoubleRef pSize ﾌｫﾝﾄｻｲｽﾞ(ﾎﾟｲﾝﾄ)
 * @param 	DoubleRef pWidth 指定文字の横幅微調値
 * @param 	DoubleRef pHeight 指定文字の縦幅微調値
 * @return int ﾌｫﾝﾄ番号、失敗：0<p>
 * 見つからない場合(失敗)はﾌｫﾝﾄ番号0の情報
 */
- (long)GetFontSize:(NSString *)lpFont   // 文字種類のｺﾏﾝﾄﾞ文字列
          withPSize:(DoubleRef *)pSize   // ﾌｫﾝﾄｻｲｽﾞ(ﾎﾟｲﾝﾄ)
         withPWidth:(DoubleRef *)pWidth  // 指定文字の横幅微調値
        withPHeight:(DoubleRef *)pHeight;// 指定文字の縦幅微調値

/**
 * 縦倍率の比率取得
 * 指定したｺﾏﾝﾄﾞ文字列の縦倍率の比率を取得
 * @param String lpHeight 倍率指定のｺﾏﾝﾄﾞ文字列
 * @return double 成功：縦倍率比、失敗：最小倍率での比率または0
 */
- (double)GetHeightRaito:(NSString *)lpHeight;  // 倍率指定のｺﾏﾝﾄﾞ文字列

/**
 * ﾃﾞｰﾀの取得
 * 指定したｲﾝﾃﾞｯｸｽのﾃﾞｰﾀを取得
 * @param int Index 取得するｲﾝﾃﾞｯｸｽ
 * @return String   ﾃﾞｰﾀ(縦倍率設定)
 */
- (NSString *)GetHight:(long)Index; // 取得するｲﾝﾃﾞｯｸｽ

/**
 * ﾃﾞｰﾀの取得
 * @param int Index 取得するｲﾝﾃﾞｯｸｽ
 * @return String ﾃﾞｰﾀ(横倍率設定)
 */
- (NSString *)GetWidth:(long)Index;  // 取得するｲﾝﾃﾞｯｸｽ

/**
 * 横倍率の比率取得
 * 指定したｺﾏﾝﾄﾞ文字列の横倍率の比率を取得する
 * @param String lpWidth 倍率指定のｺﾏﾝﾄﾞ文字列
 * @return  double 成功：横倍率比、失敗：最小倍率での比率または0
 */
- (double)GetWidthRaito:(NSString *)lpWidth; // 倍率指定のｺﾏﾝﾄﾞ文字列

/**
 * ﾌﾟﾘﾝﾀ情報ﾌｧｲﾙの読み込み
 * @param String pathName  ﾌﾟﾘﾝﾀ情報ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @return  boolean 実行結果 成功:true 失敗:false
 */
- (BOOL)LoadBarset:(NSString *)pathName;  // ﾌﾟﾘﾝﾀ情報ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

#pragma mark Protected

/**
 * 配列のｸﾘｱ
 *
 */
- (void)DeleteChar;

/**
 * 配列のｸﾘｱ(文字種類)
 */
- (void)DeleteCharType;

/**
 * 配列のｸﾘｱ
 * 配列のｸﾘｱ(縦倍率設定)
 */
- (void)DeleteHight;

/**
 * 配列のｸﾘｱ
 * 配列のｸﾘｱ(横倍率設定)
 */
- (void)DeleteWidth;

/**
 * 設定ﾌｧｲﾙより数値ﾃﾞｰﾀ取得
 * @param 	String sectionName          ｾｸｼｮﾝ名
 * @param 	String entryName            ｴﾝﾄﾘｰ名
 * @param 	int defInt                  ﾃﾞﾌｫﾙﾄ値
 * @param 	String pathName
 * @return  int 取得した数値ﾃﾞｰﾀ
 */
- (long)GetIntBarsetIni:(NSString *)sectionName // ｾｸｼｮﾝ名
          withEntryName:(NSString *)entryName   // ｴﾝﾄﾘｰ名
             withDefInt:(long)defInt            // ﾃﾞﾌｫﾙﾄ値
           withPathName:(NSString *)pathName;   // 設定ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

/**
 * 設定ﾌｧｲﾙより文字列ﾃﾞｰﾀ取得
 * @param String sectionName            ｾｸｼｮﾝ名
 * @param 	String entryName            ｴﾝﾄﾘｰ名
 * @param 	String defString            ﾃﾞﾌｫﾙﾄの文字列
 * @param 	String pathName             設定ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)
 * @return  String                      取得した文字列
 */
- (NSString *)GetStringBarsetIni:(NSString *)sectionName // ｾｸｼｮﾝ名
                   withEntryName:(NSString *)entryName   // ｴﾝﾄﾘｰ名
                   withDefString:(NSString *)defString   // ﾃﾞﾌｫﾙﾄの文字列
                    withPathName:(NSString *)pathName;   // 設定ﾌｧｲﾙ名(ﾌﾙﾊﾟｽ)

@end
