//=============================================================================
// < SMASH STARS >
// 攻撃 [attack.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "sound.h"
#include "soundEffect.h"
#include "fastDraw2D.h"
#include "input.h"
#include "weapons.h"
#include "stars.h"
#include "timer.h"
#include "coin.h"
#include "stageBar.h"
#include "attackEffect.h"
#include "explosion.h"
#include "attack.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
int GetSaveTime(void);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
LPDIRECTSOUNDBUFFER8	SE[SE_MAX];					// サウンドエフェクト
int						attack = DEFAULT_ATTACK;	// 攻撃力
int						clearTime;
//=============================================================================
// 初期化
//=============================================================================
HRESULT InitAttack(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < SE_MAX; i++)
		{
			// サウンドの読み込み
			SE[i] = LoadSound(E_DS8_FLAG_LOOP, SE_ATTACK);
		}
	}

	attack = DEFAULT_ATTACK;	// 初期化

	clearTime = 0;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitAttack(void)
{

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateAttack(HWND hWnd)
{
	STARS		*stars		= GetStars(GetGameStage());

	if (stars->use)
	{
		// マウスの左ボタンを押したら
		if (IsMouseLeftTriggered())
		{
			// HP
			stars->HP -= attack;

			// エフェクト
			SetAttackEffect(GetMousePos(hWnd));

			for (int i = 0; i < SE_MAX; i++)
			{
				if (!IsPlaying(SE[i]))
				{
					// サウンドエフェクト
					PlaySound(SE[i], E_DS8_FLAG_NONE);
					SetSoundEffect
					(SE[i], E_DS8_FLAG_NONE, DISTORTION_SOUND_EFFECT);
					
					break;
				}
			}

			// HP=0ならクリア
			if (stars->HP <= 0)
			{
				// クリアタイムのセーブ
				SetSaveTime();

				// コインのエフェクト
				SetCoin(GetMousePos(hWnd));

				// 星
				stars->use = false;

				// エフェクト
				SetExplosion();
			}
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawAttack(void)
{

}

//=============================================================================
// 攻撃力の変更
//=============================================================================
void SetAttack(int atk)
{
	attack = atk;
}

//=============================================================================
// クリアタイムのセーブ
//=============================================================================
void SetSaveTime(void)
{
	clearTime += (TIMER_DEFAULT - GetTimeCnt());
}

//=============================================================================
// クリアタイムを取得
//=============================================================================
int GetSaveTime(void)
{
	return clearTime;
}
