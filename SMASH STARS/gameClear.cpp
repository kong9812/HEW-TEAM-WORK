//=============================================================================
// < SMASH STARS >
// �Q�[���N���A [gameClear.h]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "timer.h"
#include "input.h"
#include "attack.h"
#include "gameClear.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void DrawGameClearTime(void);		// �N���A�^�C��

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE gameClear;
TEXTURE	timeNum[TIME_DIGIT];

//=============================================================================
// ������
//=============================================================================
HRESULT InitGameClear(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &gameClear, GAME_CLEAR);

		for (int i = 0; i < TIME_DIGIT; i++)
		{
			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &timeNum[i], TIMER_TEXTURE);
		}
	}

	{// �e�N�X�`���\���̂̏�����
		gameClear.pos = GAME_CLEAR_POS;
		gameClear.size = D3DXVECTOR2(SCREEN_WIDTH, SCREEN_HEIGHT);

		for (int i = 0; i < TIME_DIGIT; i++)
		{
			// �ʒu
			timeNum[i].pos = D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f);
			timeNum[i].pos.x -= TIME_NUM_SIZE.x * i;

			// �T�C�Y
			timeNum[i].size = TIME_NUM_SIZE;
		}

	}

	for (int i = 0; i < TIME_DIGIT; i++)
	{
		// ���_���̐ݒ�
		MakeCutVtx4PointData(&timeNum[i], TIME_X_PATTERN, TIME_Y_PATTERN, TIME_X_PATTERN * TIME_Y_PATTERN);
	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&gameClear);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitGameClear(void)
{
	// �w�i
	RELEASE_TEXTURE(gameClear);

	for (int i = 0; i < TIME_DIGIT; i++)
	{
		// �N���A�^�C��
		RELEASE_TEXTURE(timeNum[i]);
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateGameClear(void)
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
void DrawGameClear(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawNormalObject(device, gameClear);

	// �N���A�^�C��
	DrawGameClearTime();
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawGameClearTime(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �ω��\�ȃ^�C�}�[����(���Z�p)
	int number = GetSaveTime();

	for (int i = 0; i < TIME_DIGIT; i++)
	{
		// ������
		int x = (number % 10);

		// �`�揈��(�����X�N���[���p)
		DrawNumDataObject(device, timeNum[i], x);

		
		// �����
		number /= 10;
	}
}
		