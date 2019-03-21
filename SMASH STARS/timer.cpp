//=============================================================================
// < SMASH STARS >
// タイマー [timer.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "stars.h"
#include "fastDraw2D.h"
#include "timer.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		timer[TIMER_NUM_MAX];		// タイマーの数字
TEXTURE		timerFrame;					// タイマーのフレーム

int			timeCnt;					// タイマーのカウンター
int			timerCnt;					// 数字

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitTimer(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < TIMER_NUM_MAX; i++)
		{
			// テクスチャの読み込み
			LoadTexture(device, &timer[i], TIMER_TEXTURE);
		}

		// テクスチャの読み込み
		LoadTexture(device, &timerFrame, TIMER_FRAME_TEXTURE);
	}

	{// テクスチャ構造体の初期化
		for (int i = 0; i < TIMER_NUM_MAX; i++)
		{
			// 位置
			timer[i].pos = TIMER_NUM_POS;
			timer[i].pos.x -= TIMER_NUM_SIZE.x * i;

			// サイズ
			timer[i].size = TIMER_NUM_SIZE;
		}

		// 位置
		timerFrame.pos	= TIMER_FRAME_POS;
		// サイズ
		timerFrame.size = TIMER_FRAME_SIZE;
	}

	{// 他の初期化
		timeCnt = 0;
		timerCnt = TIMER_DEFAULT;
	}

	for (int i = 0; i < TIMER_NUM_MAX; i++)
	{
		// 頂点情報の設定
		MakeCutVtx4PointData(&timer[i], TIMER_X_PATTERN, TIMER_Y_PATTERN, TIMER_X_PATTERN * TIMER_Y_PATTERN);
	}

	// 頂点情報の設定
	MakeVtx4PointData(&timerFrame);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitTimer(void)
{
	// タイマー
	for (int i = 0; i < TIMER_NUM_MAX; i++)
	{
		RELEASE_TEXTURE(timer[i]);
	}

	// タイマーのフレーム
	RELEASE_TEXTURE(timerFrame);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateTimer(void)
{
	// 時間の減少
	timeCnt++;

	// オーバー防止
	if (timeCnt > 60)
	{
		// オーバー防止
		timeCnt = 0;

		// 1秒経過
		timerCnt--;

		if (timerCnt <= 0)
		{
			SetStage(STAGE_GAME_OVER);
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawTimer(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// タイマーのフレーム
	DrawNormalObject(device, timerFrame);

	// 変化可能なタイマー数字(減算用)
	int number = (int)timerCnt;

	for (int i = 0; i < TIMER_NUM_MAX; i++)
	{
		// 仮数字
		int x = (number % 10);

		// 描画処理(数字スクロール用)
		DrawNumDataObject(device, timer[i], x);

		// 桁取り
		number /= 10;
	}
}

//=============================================================================
// クリアタイムを取得
//=============================================================================
int GetTimeCnt(void)
{
	return timerCnt;
}
