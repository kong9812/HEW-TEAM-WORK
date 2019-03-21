//=============================================================================
// < SMASH STARS >
// タイトルの背景 [titleBackground.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "input.h"
#include "titleBackground.h"

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		titleBackground;		// タイトルの背景

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitTitleBackground(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &titleBackground, TITLE_BACKGROUND_TEXTURE);
	}

	{// テクスチャ構造体の初期化
		titleBackground.pos = TITLE_BACKGROUND_POS;
		titleBackground.size = TITLE_BACKGROUND_SIZE;
	}

	// 頂点情報の設定
	MakeVtx4PointData(&titleBackground);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitTitleBackground(void)
{
	// タイトルの背景 
	RELEASE_TEXTURE(titleBackground);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateTitleBackground(void)
{
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		// ステージ遷移
		SetStage(STAGE_GAME);
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawTitleBackground(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(一般的な描画処理)
	DrawNormalObject(device, titleBackground);
}
