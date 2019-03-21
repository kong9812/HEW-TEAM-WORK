//=============================================================================
// < SMASH STARS >
// �^�C�g���̃��S [titleLogo.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "titleLogo.h"

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		titleLogo;		// �^�C�g���̔w�i

//=============================================================================
// ������
//=============================================================================
HRESULT InitTitleLogo(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &titleLogo, TITLE_LOGO_TEXTURE);
	}

	{// �ʒu�̏�����
		titleLogo.pos = TITLE_LOGO_POS;
		titleLogo.size = TITLE_LOGO_SIZE;
	}

	// ���_���̐ݒ�
	MakeVtxCenterData(&titleLogo);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitTitleLogo(void)
{
	// �^�C�g���̃��S
	RELEASE_TEXTURE(titleLogo);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateTitleLogo(void)
{
	// ���S�̈ړ�����
	if (titleLogo.pos.y >= TITLE_LOGO_STOP_POS_Y)
	{
		titleLogo.pos.y -= TITLE_LOGO_MOVE_SPEED;
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTitleLogo(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �`�揈��(�ړ��p�E���S���W)
	DrawMoveCenterObject(device, titleLogo);

}
