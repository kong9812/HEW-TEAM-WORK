//=============================================================================
// < SMASH STARS >
// �^�C�}�[ [timer.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "stars.h"
#include "fastDraw2D.h"
#include "timer.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		timer[TIMER_NUM_MAX];		// �^�C�}�[�̐���
TEXTURE		timerFrame;					// �^�C�}�[�̃t���[��

int			timeCnt;					// �^�C�}�[�̃J�E���^�[
int			timerCnt;					// ����

//=============================================================================
// ������
//=============================================================================
HRESULT InitTimer(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < TIMER_NUM_MAX; i++)
		{
			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &timer[i], TIMER_TEXTURE);
		}

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &timerFrame, TIMER_FRAME_TEXTURE);
	}

	{// �e�N�X�`���\���̂̏�����
		for (int i = 0; i < TIMER_NUM_MAX; i++)
		{
			// �ʒu
			timer[i].pos = TIMER_NUM_POS;
			timer[i].pos.x -= TIMER_NUM_SIZE.x * i;

			// �T�C�Y
			timer[i].size = TIMER_NUM_SIZE;
		}

		// �ʒu
		timerFrame.pos	= TIMER_FRAME_POS;
		// �T�C�Y
		timerFrame.size = TIMER_FRAME_SIZE;
	}

	{// ���̏�����
		timeCnt = 0;
		timerCnt = TIMER_DEFAULT;
	}

	for (int i = 0; i < TIMER_NUM_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeCutVtx4PointData(&timer[i], TIMER_X_PATTERN, TIMER_Y_PATTERN, TIMER_X_PATTERN * TIMER_Y_PATTERN);
	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&timerFrame);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitTimer(void)
{
	// �^�C�}�[
	for (int i = 0; i < TIMER_NUM_MAX; i++)
	{
		RELEASE_TEXTURE(timer[i]);
	}

	// �^�C�}�[�̃t���[��
	RELEASE_TEXTURE(timerFrame);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateTimer(void)
{
	// ���Ԃ̌���
	timeCnt++;

	// �I�[�o�[�h�~
	if (timeCnt > 60)
	{
		// �I�[�o�[�h�~
		timeCnt = 0;

		// 1�b�o��
		timerCnt--;

		if (timerCnt <= 0)
		{
			SetStage(STAGE_GAME_OVER);
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTimer(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �^�C�}�[�̃t���[��
	DrawNormalObject(device, timerFrame);

	// �ω��\�ȃ^�C�}�[����(���Z�p)
	int number = (int)timerCnt;

	for (int i = 0; i < TIMER_NUM_MAX; i++)
	{
		// ������
		int x = (number % 10);

		// �`�揈��(�����X�N���[���p)
		DrawNumDataObject(device, timer[i], x);

		// �����
		number /= 10;
	}
}

//=============================================================================
// �N���A�^�C�����擾
//=============================================================================
int GetTimeCnt(void)
{
	return timerCnt;
}
