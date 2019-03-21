//=============================================================================
// < SMASH STARS >
// ゲームクリア [gameClear.h]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "timer.h"
#include "input.h"
#include "attack.h"
#include "gameClear.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void DrawGameClearTime(void);		// クリアタイム

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE gameClear;
TEXTURE	timeNum[TIME_DIGIT];

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitGameClear(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &gameClear, GAME_CLEAR);

		for (int i = 0; i < TIME_DIGIT; i++)
		{
			// テクスチャの読み込み
			LoadTexture(device, &timeNum[i], TIMER_TEXTURE);
		}
	}

	{// テクスチャ構造体の初期化
		gameClear.pos = GAME_CLEAR_POS;
		gameClear.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

		for (int i = 0; i < TIME_DIGIT; i++)
		{
			// 位置
			timeNum[i].pos = D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f);
			timeNum[i].pos.x -= TIME_NUM_SIZE.x * i;

			// サイズ
			timeNum[i].size = TIME_NUM_SIZE;
		}

	}

	for (int i = 0; i < TIME_DIGIT; i++)
	{
		// 頂点情報の設定
		MakeCutVtx4PointData(&timeNum[i], TIME_X_PATTERN, TIME_Y_PATTERN, TIME_X_PATTERN * TIME_Y_PATTERN);
	}

	// 頂点情報の設定
	MakeVtx4PointData(&gameClear);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitGameClear(void)
{
	// 背景
	RELEASE_TEXTURE(gameClear);

	for (int i = 0; i < TIME_DIGIT; i++)
	{
		// クリアタイム
		RELEASE_TEXTURE(timeNum[i]);
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateGameClear(void)
{
	if (GetKeyboardTrigger(DIK_RETURN))
	{		
		// ステージ遷移
		SetStage(STAGE_TITLE);

		// 初期化
		ReInitGame();
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawGameClear(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(一般的な描画処理)
	DrawNormalObject(device, gameClear);

	// クリアタイム
	DrawGameClearTime();
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawGameClearTime(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 変化可能なタイマー数字(減算用)
	int number = GetSaveTime();

	for (int i = 0; i < TIME_DIGIT; i++)
	{
		// 仮数字
		int x = (number % 10);

		// 描画処理(数字スクロール用)
		DrawNumDataObject(device, timeNum[i], x);

		
		// 桁取り
		number /= 10;
	}
}
		