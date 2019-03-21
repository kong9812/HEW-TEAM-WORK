//=============================================================================
// < SMASH STARS >
// 攻撃のエフェクト [attackEffect.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "attackEffect.h"
#include "attackEffect.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
ATTACK_EFFECT	attackEffect[ATTACK_EFFECT_MAX];	// 攻撃のエフェクト構造体
static int		frameCnt;							// アニメション用フレームカウンター

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitAttackEffect(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
		{
			// テクスチャの読み込み
			LoadTexture(device, &attackEffect[i].texture, ATTACK_EFFECT_TEXTURE);
		}
	}

	{// 他の初期化
		// フレームカウンター
		frameCnt = 0;
	}

	{// 攻撃のエフェクト構造体の初期化 & 頂点情報の設定

		for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
		{
			// 攻撃のエフェクト
			attackEffect[i].texture.pos = ATTACK_EFFECT_POS;
			// 攻撃のエフェクト
			attackEffect[i].texture.size = ATTACK_EFFECT_SIZE;
			// 使用状況
			attackEffect[i].use = false;
			// カウンター
			attackEffect[i].cnt = 0;

			// 頂点情報の設定
			MakeCutVtx4PointData
			(&attackEffect[i].texture, ATTACK_EFFECT_X_PATTERN, ATTACK_EFFECT_Y_PATTERN,
				ATTACK_EFFECT_X_PATTERN * ATTACK_EFFECT_Y_PATTERN);
		}
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitAttackEffect(void)
{
	for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
	{
		// 攻撃のエフェクト
		RELEASE_TEXTURE(attackEffect[i].texture);
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateAttackEffect(void)
{
	// フレームの経過
	frameCnt++;

	// 600フレーム一回
	if ((frameCnt%ATTACK_EFFECT_UPDATE_FREQ) == 0)
	{
		for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
		{
			// 使用状況をチェック
			if (attackEffect[i].use)
			{
				// カウンターの初期化
				attackEffect[i].cnt++;

				// オーバー
				if (attackEffect[i].cnt > ATTACK_EFFECT_END)
				{
					// カウンターを0に
					attackEffect[i].cnt = 0;

					// 画面の外移動
					attackEffect[i].texture.pos = ATTACK_EFFECT_POS;

					// アニメション完了
					attackEffect[i].use = false;
				}
			}
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawAttackEffect(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
	{
		// 使用状況をチェック
		if (attackEffect[i].use)
		{
			// 描画処理(一般的な描画処理)
			DrawAnimationObject
			(device, attackEffect[i].texture, attackEffect[i].cnt, ATTACK_EFFECT_X_PATTERN, ATTACK_EFFECT_Y_PATTERN);
		}
	}
}

//=============================================================================
// エフェクトの設置
//=============================================================================
void SetAttackEffect(D3DXVECTOR3 pos)
{
	for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
	{
		// 使用状況をチェック
		if (!attackEffect[i].use)
		{
			// 位置をセット
			attackEffect[i].texture.pos = pos;

			// 使用=true
			attackEffect[i].use = true;

			// 一回ずつ
			break;
		}
	}
}