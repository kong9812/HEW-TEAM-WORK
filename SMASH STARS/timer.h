//=============================================================================
//
// タイマー [timer.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// タイマー
#define TIMER_TEXTURE		_T("data/TEXTURE/UI/number.png")
#define TIMER_NUM_MAX		(2)
#define TIMER_NUM_POS		D3DXVECTOR3(85.0f,30.0f,0.0f)
#define TIMER_NUM_SIZE		D3DXVECTOR2(35.0f,70.0f)
#define TIMER_X_PATTERN		(10)
#define TIMER_Y_PATTERN		(1)
#define TIMER_DEFAULT		(60)
#define TIMER_ADD			(30)

// タイマーのフレーム
#define TIMER_FRAME_TEXTURE	_T("data/TEXTURE/UI/timeFlame.png")
#define TIMER_FRAME_POS		D3DXVECTOR3(10.0f,0.0f,0.0f)
#define TIMER_FRAME_SIZE	D3DXVECTOR2(157.0f,101.6f)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitTimer(int initType);	// 初期化
void	UninitTimer(void);			// 終了処理
void	UpdateTimer(void);			// 更新処理
void	DrawTimer(void);			// 描画処理

void	SetSaveTime(void);			// クリアタイムのセーブ
int		GetTimeCnt(void);			// クリアタイムを取得

#endif
