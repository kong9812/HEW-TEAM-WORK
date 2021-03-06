//=============================================================================
// < SMASH STARS >
// Xe[WΜ}l[W[ [stageManager.cpp]
// Author : δο F
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
// ϊ»
//=============================================================================
HRESULT InitStageManager(int initType)
{
	// wi
	InitGameBackground(initType);

	// Xe[Wo[
	InitStageBar(initType);

	// ν
	InitWeapons(initType);

	// ^C}[
	InitTimer(initType);

	// ―
	InitStars(initType);

	// ­
	InitExplosion(initType);

	// Q[W
	InitGaugeBar(initType);

	// U
	InitAttack(initType);

	// UΜGtFNg
	InitAttackEffect(initType);

	// RCΜGtFNg
	InitCoin(initType);

	return S_OK;
}

//=============================================================================
// IΉ
//=============================================================================
void UninitStageManager(void)
{
	// wi
	UninitGameBackground();

	// Xe[Wo[
	UninitStageBar();

	// ν
	UninitWeapons();

	// ^C}[
	UninitTimer();

	// ―
	UninitStars();

	// ­
	UninitExplosion();

	// Q[W
	UninitGaugeBar();

	// U
	UninitAttack();

	// UΜGtFNg
	UninitAttackEffect();

	// RCΜGtFNg
	UninitCoin();
}

//=============================================================================
// XV
//=============================================================================
void UpdateStageManager(HWND hWnd)
{
	// wi
	UpdateGameBackground();

	// Xe[Wo[
	UpdateStageBar();

	// ν
	UpdateWeapons();

	// ^C}[
	UpdateTimer();
	
	// ―
	UpdateStars();

	// ­
	UpdateExplosion();

	// Q[W
	UpdateGaugeBar();

	// U
	UpdateAttack(hWnd);

	// UΜGtFNg
	UpdateAttackEffect();

	// RCΜGtFNg
	UpdateCoin();
}

//=============================================================================
// `ζ
//=============================================================================
void DrawStageManager(void)
{
	// wi
	DrawGameBackground();

	// Xe[Wo[
	DrawStageBar();

	// ν
	DrawWeapons();

	// ^C}[
	DrawTimer();

	// ―
	DrawStars();

	// ­
	DrawExplosion();

	// Q[W
	DrawGaugeBar();

	// U
	DrawAttack();

	// UΜGtFNg
	DrawAttackEffect();

	// RCΜGtFNg
	DrawCoin();
}
