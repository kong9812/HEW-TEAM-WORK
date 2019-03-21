//=============================================================================
// < SMASH STARS >
// 星 [stars.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "stageBar.h"
#include "stars.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
STARS		starsWk[STARS_MAX];	// 星の構造体

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitStars(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &starsWk[STARS_MERCURY].texture, STAR_MERCURY_TEXTURE);
		LoadTexture(device, &starsWk[STARS_VENUS].texture, STAR_VENUS_TEXTURE);
		LoadTexture(device, &starsWk[STARS_EARTH].texture, STAR_EARTH_TEXTURE);
		LoadTexture(device, &starsWk[STARS_MARS].texture, STAR_MARS_TEXTURE);
		LoadTexture(device, &starsWk[STARS_JUPITOR].texture, STAR_JUPITOR_TEXTURE);
		LoadTexture(device, &starsWk[STARS_SATURN].texture, STAR_SATURN_TEXTURE);
		LoadTexture(device, &starsWk[STARS_URANUS].texture, STAR_URANUS_TEXTURE);
		LoadTexture(device, &starsWk[STARS_NEPTUNE].texture, STAR_NEPTUNE_TEXTURE);
		LoadTexture(device, &starsWk[STARS_PLUTO].texture, STAR_PLUTO_TEXTURE);
		LoadTexture(device, &starsWk[STARS_SUN].texture, STAR_SUN_TEXTURE);
	}

	{// テクスチャ構造体の初期化
		for (int i = 0; i < STARS_MAX; i++)
		{
			// 位置
			starsWk[i].texture.pos = STARS_POS;

			// サイズ
			starsWk[i].texture.size = STARS_SIZE;

			// HP
			starsWk[i].HP = STARS_HP + (STARS_HP * i);

			// 生存
			starsWk[i].use = true;
		}
	}

	for (int i = 0; i < STARS_MAX; i++)
	{
		// 頂点情報の設定
		MakeVtxCenterData(&starsWk[i].texture);
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitStars(void)
{
	// 星
	for (int i = 0; i < STARS_MAX; i++)
	{
		RELEASE_TEXTURE(starsWk[i].texture);
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateStars(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawStars(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	if (starsWk[GetGameStage()].use)
	{
		// 描画処理(移動用・中心座標)
		DrawMoveCenterObject(device, starsWk[GetGameStage()].texture);
	}
}

//=============================================================================
// 星の情報を取得
//=============================================================================
STARS *GetStars(int no)
{
	return &starsWk[no];
}