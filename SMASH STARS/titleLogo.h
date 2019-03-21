//=============================================================================
//
// 高速描画処理[2D] [fastDraw2D.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _TITLE_LOGO_H_
#define _TITLE_LOGO_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// タイトルのロゴ
#define TITLE_LOGO_TEXTURE			_T("data/TEXTURE/title/titleLogo.png")
#define TITLE_LOGO_POS				D3DXVECTOR3(SCREEN_WIDTH/HALF,SCREEN_HEIGHT*2.0f,0.0f)
#define TITLE_LOGO_SIZE				D3DXVECTOR2(291.0f,241.5f)
#define TITLE_LOGO_MOVE_SPEED		(25.0f)
#define TITLE_LOGO_STOP_POS_Y		(SCREEN_HEIGHT/HALF)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitTitleLogo(int initType);	// 初期化
void	UninitTitleLogo(void);			// 終了処理
void	UpdateTitleLogo(void);			// 更新処理
void	DrawTitleLogo(void);			// 描画処理



#endif