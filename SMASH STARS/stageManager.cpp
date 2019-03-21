//=============================================================================
// < SMASH STARS >
// ステージのマネージャー [stageManager.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "gameBackground.h"
#include "stageBar.h"
#include "timer.h"
#include "stars.h"
#include "coin.h"
#include "gaugeBar.h"
#include "weapons.h"
#include "attack.h"
#include "explosion.h"
#include "attackEffect.h"
#include "stageManager.h"

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitStageManager(int initType)
{
	// 背景
	InitGameBackground(initType);

	// ステージバー
	InitStageBar(initType);

	// 武器
	InitWeapons(initType);

	// タイマー
	InitTimer(initType);

	// 星
	InitStars(initType);

	// 爆発
	InitExplosion(initType);

	// ゲージ
	InitGaugeBar(initType);

	// 攻撃
	InitAttack(initType);

	// 攻撃のエフェクト
	InitAttackEffect(initType);

	// コインのエフェクト
	InitCoin(initType);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitStageManager(void)
{
	// 背景
	UninitGameBackground();

	// ステージバー
	UninitStageBar();

	// 武器
	UninitWeapons();

	// タイマー
	UninitTimer();

	// 星
	UninitStars();

	// 爆発
	UninitExplosion();

	// ゲージ
	UninitGaugeBar();

	// 攻撃
	UninitAttack();

	// 攻撃のエフェクト
	UninitAttackEffect();

	// コインのエフェクト
	UninitCoin();
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateStageManager(HWND hWnd)
{
	// 背景
	UpdateGameBackground();

	// ステージバー
	UpdateStageBar();

	// 武器
	UpdateWeapons();

	// タイマー
	UpdateTimer();
	
	// 星
	UpdateStars();

	// 爆発
	UpdateExplosion();

	// ゲージ
	UpdateGaugeBar();

	// 攻撃
	UpdateAttack(hWnd);

	// 攻撃のエフェクト
	UpdateAttackEffect();

	// コインのエフェクト
	UpdateCoin();
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawStageManager(void)
{
	// 背景
	DrawGameBackground();

	// ステージバー
	DrawStageBar();

	// 武器
	DrawWeapons();

	// タイマー
	DrawTimer();

	// 星
	DrawStars();

	// 爆発
	DrawExplosion();

	// ゲージ
	DrawGaugeBar();

	// 攻撃
	DrawAttack();

	// 攻撃のエフェクト
	DrawAttackEffect();

	// コインのエフェクト
	DrawCoin();
}
