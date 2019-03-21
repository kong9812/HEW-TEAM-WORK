//=============================================================================
//
// コイン [coin.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _COIN_H_
#define _COIN_H_

#include "basic.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// コイン
#define COIN_TEXTURE				_T("data/TEXTURE/effect/coin.png")
#define COIN_POS					D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define COIN_SIZE					D3DXVECTOR2(25.0f,25.0f)
#define COIN_MAX					(300)
#define COIN_DROP_SPEED				(20)

// コインカウンター
#define COIN_NUM_TEXTURE			_T("data/TEXTURE/UI/number.png")
#define COIN_NUM_MAX				(4)
#define COIN_NUM_POS				D3DXVECTOR3(120.0f,110.0f,0.0f)
#define COIN_NUM_SIZE				D3DXVECTOR2(35.0f,70.0f)
#define COIN_X_PATTERN				(10)
#define COIN_Y_PATTERN				(1)

// コインのフレーム
#define COIN_FRAME_TEXTURE			_T("data/TEXTURE/UI/gameCoinflame.png")
#define COIN_FRAME_POS				D3DXVECTOR3(10.0f,101.6f,0.0f)
#define COIN_FRAME_SIZE				D3DXVECTOR2(157.0f,101.6f)

//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct
{
	TEXTURE texture;
	bool	use;

}COIN;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitCoin(int initType);		// 初期化
void	UninitCoin(void);			// 終了処理
void	UpdateCoin(void);			// 更新処理
void	DrawCoin(void);				// 描画処理

void	SetCoin(D3DXVECTOR3 pos);	// コインの設置
int		SetPlayerCoin(int price);	// コインの取得・設定
#endif
