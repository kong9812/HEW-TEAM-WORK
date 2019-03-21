//=============================================================================
// < SMASH STARS >
// コイン [coin.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "coin.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
// 描画処理
void DrawCoinNum(void);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		coinCnt[COIN_NUM_MAX];	// コインのカウンター
TEXTURE		coinFrame;				// コインのフレーム

COIN		coin[COIN_MAX];			// コインの構造体
int			playerCoin;				// プレイヤーのコイン

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitCoin(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < COIN_MAX; i++)
		{
			// テクスチャの読み込み
			LoadTexture(device, &coin[i].texture, COIN_TEXTURE);
		}

		for (int i = 0; i < COIN_NUM_MAX; i++)
		{
			// テクスチャの読み込み
			LoadTexture(device, &coinCnt[i], COIN_NUM_TEXTURE);
		}

		// テクスチャの読み込み
		LoadTexture(device, &coinFrame, COIN_FRAME_TEXTURE);
	}

	{// テクスチャ構造体の初期化
		for (int i = 0; i < COIN_MAX; i++)
		{
			coin[i].texture.pos		= COIN_POS;
			coin[i].texture.size	= COIN_SIZE;
			coin[i].use				= false;
		}

		for (int i = 0; i < COIN_NUM_MAX; i++)
		{
			// 位置
			coinCnt[i].pos = COIN_NUM_POS;
			coinCnt[i].pos.x -= COIN_NUM_SIZE.x * i;

			// サイズ
			coinCnt[i].size = COIN_NUM_SIZE;
		}

		// コインのフレーム
		// 位置
		coinFrame.pos = COIN_FRAME_POS;
		// サイズ
		coinFrame.size = COIN_FRAME_SIZE;
	}

	{// 他の初期化
		// プレイヤーのコイン
		playerCoin = 0;
	}

	for (int i = 0; i < COIN_NUM_MAX; i++)
	{
		// 頂点情報の設定
		MakeCutVtx4PointData(&coinCnt[i], COIN_X_PATTERN, COIN_Y_PATTERN, COIN_X_PATTERN * COIN_Y_PATTERN);
	}

	for (int i = 0; i < COIN_MAX; i++)
	{
		// 頂点情報の設定
		MakeVtxCenterData(&coin[i].texture);
	}

	// 頂点情報の設定
	MakeVtx4PointData(&coinFrame);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitCoin(void)
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		// タイトルの背景 
		RELEASE_TEXTURE(coin[i].texture);
	}

	for (int i = 0; i < COIN_NUM_MAX; i++)
	{
		// タイトルの背景 
		RELEASE_TEXTURE(coinCnt[i]);
	}

	// コインフレーム
	RELEASE_TEXTURE(coinFrame);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateCoin(void)
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].use)
		{
			// 位置
			coin[i].texture.pos.y += ((rand() % COIN_DROP_SPEED) / 2.0f);

			if (coin[i].texture.pos.y > SCREEN_HEIGHT)
			{
				// プレイヤーのコイン
				playerCoin++;

				coin[i].use = false;
			}
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawCoin(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// コインフレーム
	DrawNormalObject(device, coinFrame);


	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].use)
		{
			// 描画処理(移動用・中心座標)
			DrawMoveCenterObject(device, coin[i].texture);
		}
	}

	// コインの数字
	DrawCoinNum();
}

//=============================================================================
// 描画処理[コインの数字]
//=============================================================================
void DrawCoinNum(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 変化可能なコイン数字(減算用)
	int number = playerCoin;

	for (int i = 0; i < COIN_NUM_MAX; i++)
	{
		// 仮数字
		int x = (number % 10);

		// 描画処理(数字スクロール用)
		DrawNumDataObject(device, coinCnt[i], x);

		// 桁取り
		number /= 10;
	}

}

//=============================================================================
// コインの設置
//=============================================================================
void SetCoin(D3DXVECTOR3 pos)
{
	int coinNum = (rand() % COIN_MAX + 1);	// コインの数

	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coinNum > 0)
		{
			if (!coin[i].use)
			{
				// 一枚の使用
				coinNum--;

				// 位置
				D3DXVECTOR3 temPos;
				temPos.x = (pos.x + ((rand() % 1000) - 500));
				temPos.y = (pos.x + ((rand() % 1000) - 500));

				// 使用
				coin[i].use = true;

				// 位置
				coin[i].texture.pos = temPos;
			}
		}
	}
}

//=============================================================================
// プレイヤーの近を取得
// price = 0 ... Get関数
//=============================================================================
int SetPlayerCoin(int price)
{
	// 減算
	playerCoin -= price;

	// 結果を出す
	return playerCoin;
}