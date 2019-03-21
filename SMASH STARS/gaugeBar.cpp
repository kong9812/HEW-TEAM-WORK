//=============================================================================
// < SMASH STARS >
// �^�C�g���̔w�i [titleBackground.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "stageBar.h"
#include "stars.h"
#include "gaugeBar.h"

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		gaugeBackground;		// �Q�[�W�̔w�i
TEXTURE		gauge;					// �Q�[�W

//=============================================================================
// ������
//=============================================================================
HRESULT InitGaugeBar(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &gaugeBackground, GAUGE_BACKGROUNG_TEXTURE);

		// �e�N�X�`���̏�����
		gauge.texture = NULL;
	}

	{// �e�N�X�`���\���̂̏�����
		// �Q�[�W�̔w�i
		gaugeBackground.pos		= GAUGE_BACKGROUNG_POS;
		gaugeBackground.size	= GAUGE_BACKGROUNG_SIZE;

		// �Q�[�W
		gauge.pos				= GAUGE_POS;
		gauge.size				= GAUGE_SIZE;
		gauge.col				= GAUGE_COL;
	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&gaugeBackground);

	// ���_���̐ݒ�
	MakeVtx4PointData(&gauge);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitGaugeBar(void)
{
	// �^�C�g���̔w�i 
	RELEASE_TEXTURE(gaugeBackground);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateGaugeBar(void)
{

}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawGaugeBar(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();
	STARS star = *GetStars(GetGameStage());

	if (star.HP > 0)
	{
		// �`�揈��(�Q�[�W�p�E�F�̕ύX)
		DrawGaugeObject
		(device, gauge, star.HP / (STARS_HP + (STARS_HP * GetGameStage())), GAUGE_RIGHT);
	}

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawNormalObject(device, gaugeBackground);
}
