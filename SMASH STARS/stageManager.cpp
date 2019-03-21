//=============================================================================
// < SMASH STARS >
// �X�e�[�W�̃}�l�[�W���[ [stageManager.cpp]
// Author : �� �F��
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
// ������
//=============================================================================
HRESULT InitStageManager(int initType)
{
	// �w�i
	InitGameBackground(initType);

	// �X�e�[�W�o�[
	InitStageBar(initType);

	// ����
	InitWeapons(initType);

	// �^�C�}�[
	InitTimer(initType);

	// ��
	InitStars(initType);

	// ����
	InitExplosion(initType);

	// �Q�[�W
	InitGaugeBar(initType);

	// �U��
	InitAttack(initType);

	// �U���̃G�t�F�N�g
	InitAttackEffect(initType);

	// �R�C���̃G�t�F�N�g
	InitCoin(initType);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitStageManager(void)
{
	// �w�i
	UninitGameBackground();

	// �X�e�[�W�o�[
	UninitStageBar();

	// ����
	UninitWeapons();

	// �^�C�}�[
	UninitTimer();

	// ��
	UninitStars();

	// ����
	UninitExplosion();

	// �Q�[�W
	UninitGaugeBar();

	// �U��
	UninitAttack();

	// �U���̃G�t�F�N�g
	UninitAttackEffect();

	// �R�C���̃G�t�F�N�g
	UninitCoin();
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateStageManager(HWND hWnd)
{
	// �w�i
	UpdateGameBackground();

	// �X�e�[�W�o�[
	UpdateStageBar();

	// ����
	UpdateWeapons();

	// �^�C�}�[
	UpdateTimer();
	
	// ��
	UpdateStars();

	// ����
	UpdateExplosion();

	// �Q�[�W
	UpdateGaugeBar();

	// �U��
	UpdateAttack(hWnd);

	// �U���̃G�t�F�N�g
	UpdateAttackEffect();

	// �R�C���̃G�t�F�N�g
	UpdateCoin();
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawStageManager(void)
{
	// �w�i
	DrawGameBackground();

	// �X�e�[�W�o�[
	DrawStageBar();

	// ����
	DrawWeapons();

	// �^�C�}�[
	DrawTimer();

	// ��
	DrawStars();

	// ����
	DrawExplosion();

	// �Q�[�W
	DrawGaugeBar();

	// �U��
	DrawAttack();

	// �U���̃G�t�F�N�g
	DrawAttackEffect();

	// �R�C���̃G�t�F�N�g
	DrawCoin();
}
