//=============================================================================
// < SMASH STARS >
// 武器 [weapons.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "input.h"
#include "shop.h"
#include "attack.h"
#include "timer.h"
#include "fastDraw2D.h"
#include "weapons.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
WEAPONS weapons[WEAPONS_MAX];		// 武器

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitWeapons(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &weapons[ITEM_STICK].weapons, SHOP_ITEM_STICK);
		LoadTexture(device, &weapons[ITEM_AX].weapons, SHOP_ITEM_AX);
		LoadTexture(device, &weapons[ITEM_SWORD].weapons, SHOP_ITEM_SWORD);
		LoadTexture(device, &weapons[ITEM_MAGIC_SWORD].weapons, SHOP_ITEM_MAGICSWORD);
		LoadTexture(device, &weapons[ITEM_MISSILE].weapons, SHOP_ITEM_MISSILE);

		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// テクスチャの初期化
			weapons[i].background.texture = NULL;

			// テクスチャの読み込み
			LoadTexture(device, &weapons[i].frame, WEAPONS_FRAME_TEXTURE);

			// テクスチャの読み込み
			LoadTexture(device, &weapons[i].num, TIMER_TEXTURE);
		}
	}

	{// 武器構造体の初期化
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// 武器のフレーム
			weapons[i].frame.size = WEAPONS_FRAME_SIZE;
			weapons[i].frame.pos = (((float)i * WEAPONS_FRAME_POS) + WEAPONS_FRAME_DEFAULT);

			// 武器
			weapons[i].weapons.size = WEAPONS_SIZE;
			weapons[i].weapons.pos = (((float)i * WEAPONS_POS) + WEAPONS_DEFAULT);
		
			// 数字
			weapons[i].num.size = WEAPONS_NUM_SIZE;
			weapons[i].num.pos = (((float)i * WEAPONS_NUM_POS) + WEAPONS_NUM_DEFAULT);
		
			// 背景
			weapons[i].background.col = SHOP_SELECT_COL0;
			weapons[i].background.size = weapons[i].frame.size;
			weapons[i].background.pos = weapons[i].frame.pos;
		}
	}

	for (int i = 0; i < WEAPONS_MAX; i++)
	{
		// 頂点情報の設定
		MakeVtx4PointData(&weapons[i].weapons);
		// 頂点情報の設定
		MakeVtx4PointData(&weapons[i].frame);
		// 頂点情報の設定
		MakeVtx4PointData(&weapons[i].background);
		// 頂点情報の設定
		MakeCutVtx4PointData(&weapons[i].num, TIMER_X_PATTERN, TIMER_Y_PATTERN, TIMER_X_PATTERN*TIMER_Y_PATTERN);
	}

	return S_OK;
}


//=============================================================================
// 終了処理
//=============================================================================
void UninitWeapons(void)
{
	for (int i = 0; i < WEAPONS_MAX; i++)
	{
		RELEASE_TEXTURE(weapons[i].background);
		RELEASE_TEXTURE(weapons[i].frame);
		RELEASE_TEXTURE(weapons[i].weapons);
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateWeapons(void)
{
	if (GetKeyboardTrigger(DIK_1) && (GetBoughtWeapons(ITEM_STICK)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// 色の初期化
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// 攻撃力の変更
		SetAttack(STICK_ATTACK);

		// 色の変更
		weapons[ITEM_STICK].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_STICK].background);
	}


	if (GetKeyboardTrigger(DIK_2) && (GetBoughtWeapons(ITEM_AX)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// 色の初期化
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// 攻撃力の変更
		SetAttack(AX_ATTACK);

		// 色の変更
		weapons[ITEM_AX].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_AX].background);
	}

	if (GetKeyboardTrigger(DIK_3) && (GetBoughtWeapons(ITEM_SWORD)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// 色の初期化
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// 攻撃力の変更
		SetAttack(SWORD_ATTACK);

		// 色の変更
		weapons[ITEM_SWORD].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_SWORD].background);
	}

	if (GetKeyboardTrigger(DIK_4) && (GetBoughtWeapons(ITEM_MAGIC_SWORD)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// 色の初期化
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// 攻撃力の変更
		SetAttack(MAGICSWORD_ATTACK);

		// 色の変更
		weapons[ITEM_MAGIC_SWORD].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_MAGIC_SWORD].background);
	}

	if (GetKeyboardTrigger(DIK_5) && (GetBoughtWeapons(ITEM_MISSILE)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// 色の初期化
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// 攻撃力の変更
		SetAttack(MISSILE_ATTACK);

		// 色の変更
		weapons[ITEM_MISSILE].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_MISSILE].background);
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawWeapons(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < WEAPONS_MAX; i++)
	{
		// 背景
		// 描画処理(移動用・中心座標)
		DrawNormalObject(device, weapons[i].background);

		// フレーム
		// 描画処理(移動用・中心座標)
		DrawNormalObject(device, weapons[i].frame);

		// 数字
		// 描画処理(数字スクロール用)
		DrawNumDataObject(device, weapons[i].num, i + 1);

		// 武器
		// 描画処理(一般的な描画処理)
		DrawNormalObject(device, weapons[i].weapons);
	}
}

//=============================================================================
// 武器を取得
//=============================================================================
WEAPONS *GetWeapons(int no)
{
	return weapons;
}