//=============================================================================
// < SMASH STARS >
// �^�C�g���̃}�l�[�W���[ [titleManager.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "titleBackground.h"
#include "titleLogo.h"
#include "titleManager.h"

//=============================================================================
// ������
//=============================================================================
HRESULT InitTitleManager(int initType)
{
	// �w�i
	InitTitleBackground(initType);

	// ���S
	InitTitleLogo(initType);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitTitleManager(void)
{
	// �w�i
	UninitTitleBackground();

	// ���S
	UninitTitleLogo();
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateTitleManager(void)
{
	// �w�i
	UpdateTitleBackground();

	// ���S
	UpdateTitleLogo();
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTitleManager(void)
{
	// �w�i
	DrawTitleBackground();

	// ���S
	DrawTitleLogo();
}