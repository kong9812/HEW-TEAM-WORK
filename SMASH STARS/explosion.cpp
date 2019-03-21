//=============================================================================
// < SMASH STARS >
// 星の爆発 [explosion.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "soundEffect.h"
#include "sound.h"
#include "stars.h"
#include "stageBar.h"
#include "explosion.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
LPDIRECTSOUNDBUFFER8	explosionSe;	// サウンドエフェクト
EXPLOSION				explosion;		// 爆発の構造体
static int				frameCnt;		// アニメション用フレームカウンター

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitExplosion(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &explosion.texture, EXPLOSION_TEXTURE);

		// サウンドの読み込み
		explosionSe = LoadSound(SOUND_2D, SE_EXPLOSION);
	}

	{// 他の初期化
	 // フレームカウンター
		frameCnt = 0;
	}

	{// 攻撃のエフェクト構造体の初期化 & 頂点情報の設定

			// 攻撃のエフェクト
			explosion.texture.pos = EXPLOSION_POS;
			// 攻撃のエフェクト
			explosion.texture.size = STARS_SIZE;
			// 使用状況
			explosion.use = false;
			// カウンター
			explosion.cnt = 0;

			// 頂点情報の設定
			MakeCutVtx4PointData
			(&explosion.texture, EXPLOSION_X_PATTERN, EXPLOSION_Y_PATTERN,
			EXPLOSION_X_PATTERN * EXPLOSION_Y_PATTERN);
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitExplosion(void)
{
	// 攻撃のエフェクト
	RELEASE_TEXTURE(explosion.texture);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateExplosion(void)
{
	// フレームの経過
	frameCnt++;

	// 600フレーム一回
	if ((frameCnt%EXPLOSION_UPDATE_FREQ) == 0)
	{
		// 使用状況をチェック
		if (explosion.use)
		{
			// カウンターの初期化
			explosion.cnt++;

			// オーバー
			if (explosion.cnt > EXPLOSION_END)
			{
				// カウンターを0に
				explosion.cnt = 0;

				// 画面の外移動
				explosion.texture.pos = EXPLOSION_POS;

				// アニメション完了
				explosion.use = false;

				if (GetGameStage() == STARS_SUN)
				{
					// 画面遷移
					SetStage(STAGE_CLEAR);
				}
				else
				{
					// 画面遷移
					SetStage(STAGE_SHOP);
				}
			}
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawExplosion(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 使用状況をチェック
	if (explosion.use)
	{
		// 描画処理(一般的な描画処理)
		DrawAnimationObject
		(device, explosion.texture, explosion.cnt, EXPLOSION_X_PATTERN, EXPLOSION_Y_PATTERN);
	}
}

//=============================================================================
// エフェクトの設置
//=============================================================================
void SetExplosion(void)
{
	// 使用状況をチェック
	if (!explosion.use)
	{
		// 位置をセット
		explosion.texture.pos = STARS_POS;

		// 使用=true
		explosion.use = true;

		// サウンドエフェクト
		PlaySound(explosionSe, E_DS8_FLAG_NONE);
		SetSoundEffect(explosionSe, E_DS8_FLAG_NONE, DISTORTION_SOUND_EFFECT);
	}
}