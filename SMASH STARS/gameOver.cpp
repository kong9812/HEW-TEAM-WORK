//=============================================================================
// < SMASH STARS >
// ゲームオーバー [gameOver.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "input.h"
#include "gameOver.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE	gameOver;		// ゲームオーバー[文字]
TEXTURE	gameOverLogo;	// ゲームオーバー[ロゴ]

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitGameOver(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &gameOver, GAME_OVER_TEXTURE);

		// テクスチャの読み込み
		LoadTexture(device, &gameOverLogo, GAME_OVER_LOGO_TEXTURE);
	}

	{// テクスチャ構造体の初期化
		{// サイズ
			gameOver.size		= GAME_OVER_SIZE;
			gameOverLogo.size	= GAME_OVER_LOGO_SIZE;
		}

		{// 位置
			gameOver.pos		= D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f);
			gameOver.pos		+= GAME_OVER_POS;
			gameOverLogo.pos	= D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f);
			gameOverLogo.pos	+= GAME_OVER_LOGO_POS;
		}
	}

	// 頂点情報の設定
	MakeVtxCenterData(&gameOver);
	
	// 頂点情報の設定
	MakeVtxCenterData(&gameOverLogo);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitGameOver(void)
{
	// ゲームオーバー[文字]
	RELEASE_TEXTURE(gameOver);

	// ゲームオーバー[ロゴ]
	RELEASE_TEXTURE(gameOverLogo);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateGameOver(void)
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
void DrawGameOver(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(一般的な描画処理)
	DrawMoveCenterObject(device, gameOver);

	// 描画処理(一般的な描画処理)
	DrawMoveCenterObject(device, gameOverLogo);
}