//=============================================================================
// < SMASH STARS >
// ���� [weapons.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "input.h"
#include "shop.h"
#include "attack.h"
#include "timer.h"
#include "fastDraw2D.h"
#include "weapons.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
WEAPONS weapons[WEAPONS_MAX];		// ����

//=============================================================================
// ������
//=============================================================================
HRESULT InitWeapons(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &weapons[ITEM_STICK].weapons, SHOP_ITEM_STICK);
		LoadTexture(device, &weapons[ITEM_AX].weapons, SHOP_ITEM_AX);
		LoadTexture(device, &weapons[ITEM_SWORD].weapons, SHOP_ITEM_SWORD);
		LoadTexture(device, &weapons[ITEM_MAGIC_SWORD].weapons, SHOP_ITEM_MAGICSWORD);
		LoadTexture(device, &weapons[ITEM_MISSILE].weapons, SHOP_ITEM_MISSILE);

		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// �e�N�X�`���̏�����
			weapons[i].background.texture = NULL;

			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &weapons[i].frame, WEAPONS_FRAME_TEXTURE);

			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &weapons[i].num, TIMER_TEXTURE);
		}
	}

	{// ����\���̂̏�����
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// ����̃t���[��
			weapons[i].frame.size = WEAPONS_FRAME_SIZE;
			weapons[i].frame.pos = (((float)i * WEAPONS_FRAME_POS) + WEAPONS_FRAME_DEFAULT);

			// ����
			weapons[i].weapons.size = WEAPONS_SIZE;
			weapons[i].weapons.pos = (((float)i * WEAPONS_POS) + WEAPONS_DEFAULT);
		
			// ����
			weapons[i].num.size = WEAPONS_NUM_SIZE;
			weapons[i].num.pos = (((float)i * WEAPONS_NUM_POS) + WEAPONS_NUM_DEFAULT);
		
			// �w�i
			weapons[i].background.col = SHOP_SELECT_COL0;
			weapons[i].background.size = weapons[i].frame.size;
			weapons[i].background.pos = weapons[i].frame.pos;
		}
	}

	for (int i = 0; i < WEAPONS_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeVtx4PointData(&weapons[i].weapons);
		// ���_���̐ݒ�
		MakeVtx4PointData(&weapons[i].frame);
		// ���_���̐ݒ�
		MakeVtx4PointData(&weapons[i].background);
		// ���_���̐ݒ�
		MakeCutVtx4PointData(&weapons[i].num, TIMER_X_PATTERN, TIMER_Y_PATTERN, TIMER_X_PATTERN*TIMER_Y_PATTERN);
	}

	return S_OK;
}


//=============================================================================
// �I������
//=============================================================================
void UninitWeapons(void)
{
	for (int i = 0; i < WEAPONS_MAX; i++)
	{
		RELEASE_TEXTURE(weapons[i].background);
		RELEASE_TEXTURE(weapons[i].frame);
		RELEASE_TEXTURE(weapons[i].weapons);
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateWeapons(void)
{
	if (GetKeyboardTrigger(DIK_1) && (GetBoughtWeapons(ITEM_STICK)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// �F�̏�����
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// �U���͂̕ύX
		SetAttack(STICK_ATTACK);

		// �F�̕ύX
		weapons[ITEM_STICK].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_STICK].background);
	}


	if (GetKeyboardTrigger(DIK_2) && (GetBoughtWeapons(ITEM_AX)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// �F�̏�����
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// �U���͂̕ύX
		SetAttack(AX_ATTACK);

		// �F�̕ύX
		weapons[ITEM_AX].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_AX].background);
	}

	if (GetKeyboardTrigger(DIK_3) && (GetBoughtWeapons(ITEM_SWORD)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// �F�̏�����
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// �U���͂̕ύX
		SetAttack(SWORD_ATTACK);

		// �F�̕ύX
		weapons[ITEM_SWORD].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_SWORD].background);
	}

	if (GetKeyboardTrigger(DIK_4) && (GetBoughtWeapons(ITEM_MAGIC_SWORD)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// �F�̏�����
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// �U���͂̕ύX
		SetAttack(MAGICSWORD_ATTACK);

		// �F�̕ύX
		weapons[ITEM_MAGIC_SWORD].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_MAGIC_SWORD].background);
	}

	if (GetKeyboardTrigger(DIK_5) && (GetBoughtWeapons(ITEM_MISSILE)))
	{
		for (int i = 0; i < WEAPONS_MAX; i++)
		{
			// �F�̏�����
			weapons[i].background.col = SHOP_SELECT_COL0;
			SetAllDiffuseData(&weapons[i].background);
		}

		// �U���͂̕ύX
		SetAttack(MISSILE_ATTACK);

		// �F�̕ύX
		weapons[ITEM_MISSILE].background.col = SHOP_SELECT_COL1;
		SetAllDiffuseData(&weapons[ITEM_MISSILE].background);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawWeapons(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < WEAPONS_MAX; i++)
	{
		// �w�i
		// �`�揈��(�ړ��p�E���S���W)
		DrawNormalObject(device, weapons[i].background);

		// �t���[��
		// �`�揈��(�ړ��p�E���S���W)
		DrawNormalObject(device, weapons[i].frame);

		// ����
		// �`�揈��(�����X�N���[���p)
		DrawNumDataObject(device, weapons[i].num, i + 1);

		// ����
		// �`�揈��(��ʓI�ȕ`�揈��)
		DrawNormalObject(device, weapons[i].weapons);
	}
}

//=============================================================================
// ������擾
//=============================================================================
WEAPONS *GetWeapons(int no)
{
	return weapons;
}