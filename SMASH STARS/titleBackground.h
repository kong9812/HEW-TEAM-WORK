//=============================================================================
//
// タイトルの背景 [titleBackground.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _TITLE_BACKGROUND_H_
#define _TITLE_BACKGROUND_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// タイトルの背景
#define TITLE_BACKGROUND_TEXTURE	_T("data/TEXTURE/title/titleBackground.png")
#define TITLE_BACKGROUND_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)
#define TITLE_BACKGROUND_SIZE		D3DXVECTOR2(SCREEN_WIDTH,SCREEN_HEIGHT)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitTitleBackground(int initType);	// 初期化
void	UninitTitleBackground(void);		// 終了処理
void	UpdateTitleBackground(void);		// 更新処理
void	DrawTitleBackground(void);			// 描画処理


#endif
