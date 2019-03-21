//=============================================================================
// < SMASH STARS >
// �R�C�� [coin.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "coin.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
// �`�揈��
void DrawCoinNum(void);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		coinCnt[COIN_NUM_MAX];	// �R�C���̃J�E���^�[
TEXTURE		coinFrame;				// �R�C���̃t���[��

COIN		coin[COIN_MAX];			// �R�C���̍\����
int			playerCoin;				// �v���C���[�̃R�C��

//=============================================================================
// ������
//=============================================================================
HRESULT InitCoin(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < COIN_MAX; i++)
		{
			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &coin[i].texture, COIN_TEXTURE);
		}

		for (int i = 0; i < COIN_NUM_MAX; i++)
		{
			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &coinCnt[i], COIN_NUM_TEXTURE);
		}

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &coinFrame, COIN_FRAME_TEXTURE);
	}

	{// �e�N�X�`���\���̂̏�����
		for (int i = 0; i < COIN_MAX; i++)
		{
			coin[i].texture.pos		= COIN_POS;
			coin[i].texture.size	= COIN_SIZE;
			coin[i].use				= false;
		}

		for (int i = 0; i < COIN_NUM_MAX; i++)
		{
			// �ʒu
			coinCnt[i].pos = COIN_NUM_POS;
			coinCnt[i].pos.x -= COIN_NUM_SIZE.x * i;

			// �T�C�Y
			coinCnt[i].size = COIN_NUM_SIZE;
		}

		// �R�C���̃t���[��
		// �ʒu
		coinFrame.pos = COIN_FRAME_POS;
		// �T�C�Y
		coinFrame.size = COIN_FRAME_SIZE;
	}

	{// ���̏�����
		// �v���C���[�̃R�C��
		playerCoin = 0;
	}

	for (int i = 0; i < COIN_NUM_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeCutVtx4PointData(&coinCnt[i], COIN_X_PATTERN, COIN_Y_PATTERN, COIN_X_PATTERN * COIN_Y_PATTERN);
	}

	for (int i = 0; i < COIN_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeVtxCenterData(&coin[i].texture);
	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&coinFrame);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitCoin(void)
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		// �^�C�g���̔w�i 
		RELEASE_TEXTURE(coin[i].texture);
	}

	for (int i = 0; i < COIN_NUM_MAX; i++)
	{
		// �^�C�g���̔w�i 
		RELEASE_TEXTURE(coinCnt[i]);
	}

	// �R�C���t���[��
	RELEASE_TEXTURE(coinFrame);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateCoin(void)
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].use)
		{
			// �ʒu
			coin[i].texture.pos.y += ((rand() % COIN_DROP_SPEED) / 2.0f);

			if (coin[i].texture.pos.y > SCREEN_HEIGHT)
			{
				// �v���C���[�̃R�C��
				playerCoin++;

				coin[i].use = false;
			}
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawCoin(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �R�C���t���[��
	DrawNormalObject(device, coinFrame);


	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].use)
		{
			// �`�揈��(�ړ��p�E���S���W)
			DrawMoveCenterObject(device, coin[i].texture);
		}
	}

	// �R�C���̐���
	DrawCoinNum();
}

//=============================================================================
// �`�揈��[�R�C���̐���]
//=============================================================================
void DrawCoinNum(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �ω��\�ȃR�C������(���Z�p)
	int number = playerCoin;

	for (int i = 0; i < COIN_NUM_MAX; i++)
	{
		// ������
		int x = (number % 10);

		// �`�揈��(�����X�N���[���p)
		DrawNumDataObject(device, coinCnt[i], x);

		// �����
		number /= 10;
	}

}

//=============================================================================
// �R�C���̐ݒu
//=============================================================================
void SetCoin(D3DXVECTOR3 pos)
{
	int coinNum = (rand() % COIN_MAX + 1);	// �R�C���̐�

	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coinNum > 0)
		{
			if (!coin[i].use)
			{
				// �ꖇ�̎g�p
				coinNum--;

				// �ʒu
				D3DXVECTOR3 temPos;
				temPos.x = (pos.x + ((rand() % 1000) - 500));
				temPos.y = (pos.x + ((rand() % 1000) - 500));

				// �g�p
				coin[i].use = true;

				// �ʒu
				coin[i].texture.pos = temPos;
			}
		}
	}
}

//=============================================================================
// �v���C���[�̋߂��擾
// price = 0 ... Get�֐�
//=============================================================================
int SetPlayerCoin(int price)
{
	// ���Z
	playerCoin -= price;

	// ���ʂ��o��
	return playerCoin;
}