//=============================================================================
// < SMASH STARS >
// �Q�[���I�[�o�[ [gameOver.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "input.h"
#include "gameOver.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE	gameOver;		// �Q�[���I�[�o�[[����]
TEXTURE	gameOverLogo;	// �Q�[���I�[�o�[[���S]

//=============================================================================
// ������
//=============================================================================
HRESULT InitGameOver(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &gameOver, GAME_OVER_TEXTURE);

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &gameOverLogo, GAME_OVER_LOGO_TEXTURE);
	}

	{// �e�N�X�`���\���̂̏�����
		{// �T�C�Y
			gameOver.size		= GAME_OVER_SIZE;
			gameOverLogo.size	= GAME_OVER_LOGO_SIZE;
		}

		{// �ʒu
			gameOver.pos		= D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f);
			gameOver.pos		+= GAME_OVER_POS;
			gameOverLogo.pos	= D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f);
			gameOverLogo.pos	+= GAME_OVER_LOGO_POS;
		}
	}

	// ���_���̐ݒ�
	MakeVtxCenterData(&gameOver);
	
	// ���_���̐ݒ�
	MakeVtxCenterData(&gameOverLogo);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitGameOver(void)
{
	// �Q�[���I�[�o�[[����]
	RELEASE_TEXTURE(gameOver);

	// �Q�[���I�[�o�[[���S]
	RELEASE_TEXTURE(gameOverLogo);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateGameOver(void)
{
	if (GetKeyboardTrigger(DIK_RETURN))
	{
		// �X�e�[�W�J��
		SetStage(STAGE_TITLE);

		// ������
		ReInitGame();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawGameOver(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawMoveCenterObject(device, gameOver);

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawMoveCenterObject(device, gameOverLogo);
}