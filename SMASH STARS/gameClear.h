//=============================================================================
//
// ゲームクリア [gameClear.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _GAME_CLEAR_H_
#define _GAME_CLEAR_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// 背景
#define GAME_CLEAR			_T("data/TEXTURE/UI/gameClear.png")
#define GAME_CLEAR_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)
#define TIME_DIGIT			(3)
#define TIME_NUM_SIZE		D3DXVECTOR2(35.0f,70.0f)
#define TIME_X_PATTERN		(10)
#define TIME_Y_PATTERN		(1)
#define TIME_DEFAULT		(60)
#define TIME_ADD			(30)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitGameClear(int initType);	// 初期化
void	UninitGameClear(void);			// 終了処理
void	UpdateGameClear(void);			// 更新処理
void	DrawGameClear(void);			// 描画処理

#endif
