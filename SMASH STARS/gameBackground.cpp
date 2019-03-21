//=============================================================================
// < SMASH STARS >
// ゲームの背景 [gameBackground.h]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "gameBackground.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE gameBackground;

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitGameBackground(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &gameBackground, GAME_BACKGROUND);
	}

	{// テクスチャ構造体の初期化
		gameBackground.pos	= GAME_BACKGROUND_POS;
		gameBackground.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	// 頂点情報の設定
	MakeVtx4PointData(&gameBackground);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitGameBackground(void)
{
	// 背景
	RELEASE_TEXTURE(gameBackground);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateGameBackground(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawGameBackground(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(一般的な描画処理)
	DrawNormalObject(device, gameBackground);
}
