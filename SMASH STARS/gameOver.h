//=============================================================================
// < SMASH STARS >
// ゲームオーバー [gameOver.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// ゲームオーバー[文字]
#define GAME_OVER_TEXTURE		_T("data/TEXTURE/gameOver/gameOver.png")
#define GAME_OVER_SIZE			D3DXVECTOR2(417.0f,75.5f)
#define GAME_OVER_POS			D3DXVECTOR3(0.0f,-100.0f,0.0f)

// ゲームオーバー[ロゴ]
#define GAME_OVER_LOGO_TEXTURE	_T("data/TEXTURE/gameOver/gameOverLogo.png")
#define GAME_OVER_LOGO_SIZE		D3DXVECTOR2(412.0f,415.0f)
#define GAME_OVER_LOGO_POS		D3DXVECTOR3(0.0f,100.0f,0.0f)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitGameOver(int initType);		// 初期化
void UninitGameOver(void);				// 終了処理
void UpdateGameOver(void);				// 更新処理
void DrawGameOver(void);				// 描画処理

#endif