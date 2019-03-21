//=============================================================================
// < SMASH STARS >
// �� [stars.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "stageBar.h"
#include "stars.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
STARS		starsWk[STARS_MAX];	// ���̍\����

//=============================================================================
// ������
//=============================================================================
HRESULT InitStars(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &starsWk[STARS_MERCURY].texture, STAR_MERCURY_TEXTURE);
		LoadTexture(device, &starsWk[STARS_VENUS].texture, STAR_VENUS_TEXTURE);
		LoadTexture(device, &starsWk[STARS_EARTH].texture, STAR_EARTH_TEXTURE);
		LoadTexture(device, &starsWk[STARS_MARS].texture, STAR_MARS_TEXTURE);
		LoadTexture(device, &starsWk[STARS_JUPITOR].texture, STAR_JUPITOR_TEXTURE);
		LoadTexture(device, &starsWk[STARS_SATURN].texture, STAR_SATURN_TEXTURE);
		LoadTexture(device, &starsWk[STARS_URANUS].texture, STAR_URANUS_TEXTURE);
		LoadTexture(device, &starsWk[STARS_NEPTUNE].texture, STAR_NEPTUNE_TEXTURE);
		LoadTexture(device, &starsWk[STARS_PLUTO].texture, STAR_PLUTO_TEXTURE);
		LoadTexture(device, &starsWk[STARS_SUN].texture, STAR_SUN_TEXTURE);
	}

	{// �e�N�X�`���\���̂̏�����
		for (int i = 0; i < STARS_MAX; i++)
		{
			// �ʒu
			starsWk[i].texture.pos = STARS_POS;

			// �T�C�Y
			starsWk[i].texture.size = STARS_SIZE;

			// HP
			starsWk[i].HP = STARS_HP + (STARS_HP * i);

			// ����
			starsWk[i].use = true;
		}
	}

	for (int i = 0; i < STARS_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeVtxCenterData(&starsWk[i].texture);
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitStars(void)
{
	// ��
	for (int i = 0; i < STARS_MAX; i++)
	{
		RELEASE_TEXTURE(starsWk[i].texture);
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateStars(void)
{

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawStars(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	if (starsWk[GetGameStage()].use)
	{
		// �`�揈��(�ړ��p�E���S���W)
		DrawMoveCenterObject(device, starsWk[GetGameStage()].texture);
	}
}

//=============================================================================
// ���̏����擾
//=============================================================================
STARS *GetStars(int no)
{
	return &starsWk[no];
}