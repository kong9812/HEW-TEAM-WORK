//=============================================================================
//
// ゲージバー [gaugeBar.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _GAUGE_BAR_H_
#define _GAUGE_BAR_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// ゲージの背景
#define GAUGE_BACKGROUNG_TEXTURE	_T("data/TEXTURE/gauge/gaugeBackground.png")
#define GAUGE_BACKGROUNG_POS		D3DXVECTOR3(170.0f,10.0f,0.0f)
#define GAUGE_BACKGROUNG_SIZE		D3DXVECTOR2(800.0f,100.0f)
// ゲージ
#define GAUGE_POS					D3DXVECTOR3(185.0f,30.0f,0.0f)
#define GAUGE_SIZE					D3DXVECTOR2(775.0f,60.0f)
#define GAUGE_COL					D3DXCOLOR(255.0f,0.0f,0.0f,255.0f)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitGaugeBar(int initType);	// 初期化
void	UninitGaugeBar(void);		// 終了処理
void	UpdateGaugeBar(void);		// 更新処理
void	DrawGaugeBar(void);			// 描画処理

#endif
