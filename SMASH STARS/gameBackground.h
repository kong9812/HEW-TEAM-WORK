//=============================================================================
//
// ゲームの背景 [gameBackground.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _GAME_BACKGROUND_H_
#define _GAME_BACKGROUND_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// 背景
#define GAME_BACKGROUND			_T("data/TEXTURE/UI/gameBackground.jpg")
#define GAME_BACKGROUND_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitGameBackground(int initType);	// 初期化
void	UninitGameBackground(void);		// 終了処理
void	UpdateGameBackground(void);		// 更新処理
void	DrawGameBackground(void);			// 描画処理

#endif
