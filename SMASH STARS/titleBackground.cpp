//=============================================================================
// < SMASH STARS >
// �^�C�g���̔w�i [titleBackground.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "input.h"
#include "titleBackground.h"

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		titleBackground;		// �^�C�g���̔w�i

//=============================================================================
// ������
//=============================================================================
HRESULT InitTitleBackground(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &titleBackground, TITLE_BACKGROUND_TEXTURE);
	}

	{// �e�N�X�`���\���̂̏�����
		titleBackground.pos = TITLE_BACKGROUND_POS;
		titleBackground.size = TITLE_BACKGROUND_SIZE;
	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&titleBackground);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitTitleBackground(void)
{
	// �^�C�g���̔w�i 
	RELEASE_TEXTURE(titleBackground);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateTitleBackground(void)
{
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		// �X�e�[�W�J��
		SetStage(STAGE_GAME);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTitleBackground(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawNormalObject(device, titleBackground);
}
