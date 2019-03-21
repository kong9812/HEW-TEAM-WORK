//=============================================================================
// < SMASH STARS >
// タイトルのロゴ [titleLogo.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "titleLogo.h"

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		titleLogo;		// タイトルの背景

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitTitleLogo(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &titleLogo, TITLE_LOGO_TEXTURE);
	}

	{// 位置の初期化
		titleLogo.pos = TITLE_LOGO_POS;
		titleLogo.size = TITLE_LOGO_SIZE;
	}

	// 頂点情報の設定
	MakeVtxCenterData(&titleLogo);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitTitleLogo(void)
{
	// タイトルのロゴ
	RELEASE_TEXTURE(titleLogo);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateTitleLogo(void)
{
	// ロゴの移動処理
	if (titleLogo.pos.y >= TITLE_LOGO_STOP_POS_Y)
	{
		titleLogo.pos.y -= TITLE_LOGO_MOVE_SPEED;
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawTitleLogo(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(移動用・中心座標)
	DrawMoveCenterObject(device, titleLogo);

}
