//=============================================================================
// < SMASH STARS >
// 攻撃 [attack.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "input.h"
#include "Collider.h"
#include "coin.h"
#include "attack.h"
#include "stageBar.h"
#include "timer.h"
#include "shop.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
// 描画処理
void DrawShopBoard(void);				// 商店ボード
void DrawShopItem(void);				// アイテム
void DrawShopSelect(void);				// アイテム選択用
void DrawItemPrice(void);				// 値札
void DrawBackButton(void);				// 戻りボタン

// 更新処理
void ItemCollider(HWND hWnd);			// アイテムとの当たり判定
void BackButtonCollider(HWND hWnd);		// 戻りボタンの当たり判定

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		shopBoard;							// 商店ボード
TEXTURE		shopItem[SHOP_ITEM_MAX];			// アイテム
TEXTURE		itemName[SHOP_ITEM_MAX];			// アイテム名
TEXTURE		itemSelect[SHOP_ITEM_MAX];			// アイテムの選択用
TEXTURE		itemPrice[SHOP_ITEM_MAX];			// 値札
TEXTURE		backButton;							// 戻りボタン
TEXTURE		backButtonBg;						// 戻りボタンの背景

int			weaponsAttack[SHOP_ITEM_MAX];		// 攻撃力
int			weaponsPrice[SHOP_ITEM_MAX];		// 値段
bool		weapons[SHOP_ITEM_MAX];				// 武器	true=持っている

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitShop(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &shopBoard, SHOP_BOARD_TEXTURE);

		// テクスチャの読み込み
		LoadTexture(device, &shopItem[ITEM_STICK], SHOP_ITEM_STICK);
		LoadTexture(device, &shopItem[ITEM_AX], SHOP_ITEM_AX);
		LoadTexture(device, &shopItem[ITEM_SWORD], SHOP_ITEM_SWORD);
		LoadTexture(device, &shopItem[ITEM_MAGIC_SWORD], SHOP_ITEM_MAGICSWORD);
		LoadTexture(device, &shopItem[ITEM_MISSILE], SHOP_ITEM_MISSILE);

		// テクスチャの読み込み
		LoadTexture(device, &itemName[ITEM_STICK], STICK_NAME);
		LoadTexture(device, &itemName[ITEM_AX], AX_NAME);
		LoadTexture(device, &itemName[ITEM_SWORD], SWORD_NAME);
		LoadTexture(device, &itemName[ITEM_MAGIC_SWORD], MAGICSWORD_NAME);
		LoadTexture(device, &itemName[ITEM_MISSILE], MISSILE_NAME);

		// テクスチャの読み込み
		LoadTexture(device, &backButton, BACK_BUTTON_TEXTURE);
		LoadTexture(device, &backButtonBg, BACK_BUTTON_BG_TEXTURE);

		// テクスチャの初期化
		for (int i = 0; i < SHOP_ITEM_MAX; i++)
		{
			itemSelect[i].texture = NULL;
		}

		// テクスチャの初期化
		LoadTexture(device, &itemPrice[ITEM_STICK], PRICE_STICK);
		LoadTexture(device, &itemPrice[ITEM_AX], PRICE_AX);
		LoadTexture(device, &itemPrice[ITEM_SWORD], PRICE_SWORD);
		LoadTexture(device, &itemPrice[ITEM_MAGIC_SWORD], PRICE_MAGICSWORD);
		LoadTexture(device, &itemPrice[ITEM_MISSILE], PRICE_MISSILE);
	}

	{// テクスチャ構造体の初期化

		{// サイズ
			// 商店ボード
			shopBoard.size = SHOP_BOARD_SIZE;

			// アイテム&値札
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				shopItem[i].size = SHOP_ITEM_SIZE;

			}

			// アイテム名
			itemName[ITEM_STICK].size		= STICK_NAME_SIZE;
			itemName[ITEM_AX].size			= AX_NAME_SIZE;
			itemName[ITEM_SWORD].size		= SWORD_NAME_SIZE;
			itemName[ITEM_MAGIC_SWORD].size = MAGICSWORD_NAME_SIZE;
			itemName[ITEM_MISSILE].size		= MISSILE_NAME_SIZE;

			// アイテムの選択用
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				itemSelect[i].size = SHOP_SELECT_SIZE;
				itemPrice[i].size = PRICE_SIZE;
			}

			// 戻りボタン
			backButton.size		= BACK_BUTTON_SIZE;
			backButtonBg.size	= BACK_BUTTON_SIZE;
		}

		{// 位置
			// 商店ボード
			shopBoard.pos = SHOP_BOARD_POS;

			// アイテム
			shopItem[ITEM_STICK].pos = STICK_POS;
			shopItem[ITEM_AX].pos = AX_POS;
			shopItem[ITEM_SWORD].pos = SWORD_POS;
			shopItem[ITEM_MAGIC_SWORD].pos = MAGICSWORD_POS;
			shopItem[ITEM_MISSILE].pos = MISSILE_POS;

			// アイテム名
			itemName[ITEM_STICK].pos = STICK_NAME_POS;
			itemName[ITEM_AX].pos = AX_NAME_POS;
			itemName[ITEM_SWORD].pos = SWORD_NAME_POS;
			itemName[ITEM_MAGIC_SWORD].pos = MAGICSWORD_NAME_POS;
			itemName[ITEM_MISSILE].pos = MISSILE_NAME_POS;

			// アイテムの選択用 & 値札
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				itemSelect[i].pos = shopItem[i].pos;
				itemPrice[i].pos = shopItem[i].pos + PRICE_POS;
			}

			// 戻りボタン
			backButton.pos		= BACK_BUTTON_POS;
			backButtonBg.pos	= BACK_BUTTON_POS;
		}

		{// 色

			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				// アイテムの選択用
				itemSelect[i].col = SHOP_SELECT_COL0;
			}

			// 戻りボタン
			backButton.col = SHOP_SELECT_COL0;
		}

		{// 他の初期化
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				// 持っていない
				weapons[i] = false;
			}
		}

		{// 攻撃力
			weaponsAttack[ITEM_STICK]		= STICK_ATTACK;
			weaponsAttack[ITEM_AX]			= AX_ATTACK;
			weaponsAttack[ITEM_SWORD]		= SWORD_ATTACK;
			weaponsAttack[ITEM_MAGIC_SWORD]	= MAGICSWORD_ATTACK;
			weaponsAttack[ITEM_MISSILE]		= MISSILE_ATTACK;
		}

		{// 値段
			weaponsPrice[ITEM_STICK]		= STICK_PRICE;
			weaponsPrice[ITEM_AX]			= AX_PRICE;
			weaponsPrice[ITEM_SWORD]		= SWORD_PRICE;
			weaponsPrice[ITEM_MAGIC_SWORD]	= MAGICSWORD_PRICE;
			weaponsPrice[ITEM_MISSILE]		= MISSILE_PRICE;
		}

	}

	// 頂点情報の設定
	MakeVtx4PointData(&shopBoard);

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// 頂点情報の設定
		MakeVtxCenterData(&itemName[i]);

		// 頂点情報の設定
		MakeVtxCenterData(&shopItem[i]);

		// 頂点情報の設定
		MakeVtxCenterData(&itemSelect[i]);

		// 頂点情報の設定
		MakeVtxCenterData(&itemPrice[i]);
	}

	// 頂点情報の設定
	MakeVtxCenterData(&backButtonBg);
	MakeVtxCenterData(&backButton);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitShop(void)
{
	// 商店ボード
	RELEASE_TEXTURE(shopBoard);

	// アイテム&アイテム名
	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		RELEASE_TEXTURE(itemName[i]);
		RELEASE_TEXTURE(shopItem[i]);
		RELEASE_TEXTURE(itemPrice[i]);
	}

	// 戻りボタン
	RELEASE_TEXTURE(backButtonBg);
	RELEASE_TEXTURE(backButton);

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateShop(HWND hWnd)
{
	// アイテムとの当たり判定
	ItemCollider(hWnd);		

	// 戻りボタンの当たり判定
	BackButtonCollider(hWnd);
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawShop(void)
{
	// 商店ボード
	DrawShopBoard();

	// 選択用
	DrawShopSelect();

	// アイテム
	DrawShopItem();

	// 値札
	DrawItemPrice();

	// 戻りボタン
	DrawBackButton();
}

//=============================================================================
// 描画処理 [商店ボード]
//=============================================================================
void DrawShopBoard(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(一般的な描画処理)
	DrawNormalObject(device, shopBoard);
}

//=============================================================================
// 描画処理 [アイテム]
//=============================================================================
void DrawShopItem(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// 描画処理(一般的な描画処理)
		DrawMoveCenterObject(device, shopItem[i]);

		// 描画処理(一般的な描画処理)
		DrawMoveCenterObject(device, itemName[i]);
	}
}

//=============================================================================
// 描画処理 [選択用]
//=============================================================================
void DrawShopSelect(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// 描画処理(色の変更・中心座標)
		DrawColorCenterObject(device, itemSelect[i]);
	}
}

//=============================================================================
// 描画処理 [値札]
//=============================================================================
void DrawItemPrice(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// 描画処理(移動用・中心座標)
		DrawMoveCenterObject(device, itemPrice[i]);
	}
}

//=============================================================================
// 戻りボタン
//=============================================================================
void DrawBackButton(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 背景
	// 描画処理(移動用・中心座標)
	DrawMoveCenterObject(device, backButtonBg);


	// 描画処理(色の変更・中心座標)
	DrawColorCenterObject(device, backButton);
}

//=============================================================================
// アイテムとの当たり判定
//=============================================================================
void ItemCollider(HWND hWnd)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		if (!weapons[i])
		{
			// アイテムとの当たり判定
			if (CheckHitBB(GetMousePos(hWnd), shopItem[i].pos, CURSOR_SIZE / 32, shopItem[i].size))
			{
				// アイテムの位置
				itemSelect[i].pos = shopItem[i].pos;

				// 色(選択されていない)
				itemSelect[i].col = SHOP_SELECT_COL1;

				if ((IsMouseLeftTriggered() == true) && SetPlayerCoin(0) > weaponsPrice[i])
				{
					// コインの減算
					SetPlayerCoin(weaponsPrice[i]);

					// 色(選択された)
					itemSelect[i].col = SHOP_SELECT_COL2;

					// テクスチャの読み込み
					LoadTexture(device, &shopItem[i], SHOP_USED_TEXTURE);

					// 持っている
					weapons[i] = true;
				}
			}

			else
			{
				// アイテムの色
				itemSelect[i].col = SHOP_SELECT_COL0;
			}
		}
	}
}

//=============================================================================
// 戻りボタンの当たり判定
//=============================================================================
void BackButtonCollider(HWND hWnd)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// アイテムとの当たり判定
	if (CheckHitBB(GetMousePos(hWnd), backButton.pos, CURSOR_SIZE / 32, backButton.size))
	{
		// 色(選択されていない)
		backButton.col = SHOP_SELECT_COL1;

		if (IsMouseLeftTriggered() == true)
		{
			// ゲームステージ
			SetGameStage(1);

			// 画面遷移
			SetStage(STAGE_GAME);

			// タイマーのリセット
			InitTimer(INIT_RE);
		}
	}

	else
	{
		// アイテムの色
		backButton.col = SHOP_SELECT_COL0;
	}
}

//=============================================================================
// 購入した武器を取得
//=============================================================================
bool GetBoughtWeapons(int no)
{
	return weapons[no];
}