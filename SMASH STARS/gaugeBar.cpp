//=============================================================================
// < SMASH STARS >
// タイトルの背景 [titleBackground.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "stageBar.h"
#include "stars.h"
#include "gaugeBar.h"

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		gaugeBackground;		// ゲージの背景
TEXTURE		gauge;					// ゲージ

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitGaugeBar(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &gaugeBackground, GAUGE_BACKGROUNG_TEXTURE);

		// テクスチャの初期化
		gauge.texture = NULL;
	}

	{// テクスチャ構造体の初期化
		// ゲージの背景
		gaugeBackground.pos		= GAUGE_BACKGROUNG_POS;
		gaugeBackground.size	= GAUGE_BACKGROUNG_SIZE;

		// ゲージ
		gauge.pos				= GAUGE_POS;
		gauge.size				= GAUGE_SIZE;
		gauge.col				= GAUGE_COL;
	}

	// 頂点情報の設定
	MakeVtx4PointData(&gaugeBackground);

	// 頂点情報の設定
	MakeVtx4PointData(&gauge);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitGaugeBar(void)
{
	// タイトルの背景 
	RELEASE_TEXTURE(gaugeBackground);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateGaugeBar(void)
{

}

//=============================================================================
// 描画処理
//=============================================================================
void DrawGaugeBar(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();
	STARS star = *GetStars(GetGameStage());

	if (star.HP > 0)
	{
		// 描画処理(ゲージ用・色の変更)
		DrawGaugeObject
		(device, gauge, star.HP / (STARS_HP + (STARS_HP * GetGameStage())), GAUGE_RIGHT);
	}

	// 描画処理(一般的な描画処理)
	DrawNormalObject(device, gaugeBackground);
}
