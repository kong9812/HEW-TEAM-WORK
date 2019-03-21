//=============================================================================
// < SMASH STARS >
// �U�� [attack.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "input.h"
#include "Collider.h"
#include "coin.h"
#include "attack.h"
#include "stageBar.h"
#include "timer.h"
#include "shop.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
// �`�揈��
void DrawShopBoard(void);				// ���X�{�[�h
void DrawShopItem(void);				// �A�C�e��
void DrawShopSelect(void);				// �A�C�e���I��p
void DrawItemPrice(void);				// �l�D
void DrawBackButton(void);				// �߂�{�^��

// �X�V����
void ItemCollider(HWND hWnd);			// �A�C�e���Ƃ̓����蔻��
void BackButtonCollider(HWND hWnd);		// �߂�{�^���̓����蔻��

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		shopBoard;							// ���X�{�[�h
TEXTURE		shopItem[SHOP_ITEM_MAX];			// �A�C�e��
TEXTURE		itemName[SHOP_ITEM_MAX];			// �A�C�e����
TEXTURE		itemSelect[SHOP_ITEM_MAX];			// �A�C�e���̑I��p
TEXTURE		itemPrice[SHOP_ITEM_MAX];			// �l�D
TEXTURE		backButton;							// �߂�{�^��
TEXTURE		backButtonBg;						// �߂�{�^���̔w�i

int			weaponsAttack[SHOP_ITEM_MAX];		// �U����
int			weaponsPrice[SHOP_ITEM_MAX];		// �l�i
bool		weapons[SHOP_ITEM_MAX];				// ����	true=�����Ă���

//=============================================================================
// ������
//=============================================================================
HRESULT InitShop(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &shopBoard, SHOP_BOARD_TEXTURE);

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &shopItem[ITEM_STICK], SHOP_ITEM_STICK);
		LoadTexture(device, &shopItem[ITEM_AX], SHOP_ITEM_AX);
		LoadTexture(device, &shopItem[ITEM_SWORD], SHOP_ITEM_SWORD);
		LoadTexture(device, &shopItem[ITEM_MAGIC_SWORD], SHOP_ITEM_MAGICSWORD);
		LoadTexture(device, &shopItem[ITEM_MISSILE], SHOP_ITEM_MISSILE);

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &itemName[ITEM_STICK], STICK_NAME);
		LoadTexture(device, &itemName[ITEM_AX], AX_NAME);
		LoadTexture(device, &itemName[ITEM_SWORD], SWORD_NAME);
		LoadTexture(device, &itemName[ITEM_MAGIC_SWORD], MAGICSWORD_NAME);
		LoadTexture(device, &itemName[ITEM_MISSILE], MISSILE_NAME);

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &backButton, BACK_BUTTON_TEXTURE);
		LoadTexture(device, &backButtonBg, BACK_BUTTON_BG_TEXTURE);

		// �e�N�X�`���̏�����
		for (int i = 0; i < SHOP_ITEM_MAX; i++)
		{
			itemSelect[i].texture = NULL;
		}

		// �e�N�X�`���̏�����
		LoadTexture(device, &itemPrice[ITEM_STICK], PRICE_STICK);
		LoadTexture(device, &itemPrice[ITEM_AX], PRICE_AX);
		LoadTexture(device, &itemPrice[ITEM_SWORD], PRICE_SWORD);
		LoadTexture(device, &itemPrice[ITEM_MAGIC_SWORD], PRICE_MAGICSWORD);
		LoadTexture(device, &itemPrice[ITEM_MISSILE], PRICE_MISSILE);
	}

	{// �e�N�X�`���\���̂̏�����

		{// �T�C�Y
			// ���X�{�[�h
			shopBoard.size = SHOP_BOARD_SIZE;

			// �A�C�e��&�l�D
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				shopItem[i].size = SHOP_ITEM_SIZE;

			}

			// �A�C�e����
			itemName[ITEM_STICK].size		= STICK_NAME_SIZE;
			itemName[ITEM_AX].size			= AX_NAME_SIZE;
			itemName[ITEM_SWORD].size		= SWORD_NAME_SIZE;
			itemName[ITEM_MAGIC_SWORD].size = MAGICSWORD_NAME_SIZE;
			itemName[ITEM_MISSILE].size		= MISSILE_NAME_SIZE;

			// �A�C�e���̑I��p
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				itemSelect[i].size = SHOP_SELECT_SIZE;
				itemPrice[i].size = PRICE_SIZE;
			}

			// �߂�{�^��
			backButton.size		= BACK_BUTTON_SIZE;
			backButtonBg.size	= BACK_BUTTON_SIZE;
		}

		{// �ʒu
			// ���X�{�[�h
			shopBoard.pos = SHOP_BOARD_POS;

			// �A�C�e��
			shopItem[ITEM_STICK].pos = STICK_POS;
			shopItem[ITEM_AX].pos = AX_POS;
			shopItem[ITEM_SWORD].pos = SWORD_POS;
			shopItem[ITEM_MAGIC_SWORD].pos = MAGICSWORD_POS;
			shopItem[ITEM_MISSILE].pos = MISSILE_POS;

			// �A�C�e����
			itemName[ITEM_STICK].pos = STICK_NAME_POS;
			itemName[ITEM_AX].pos = AX_NAME_POS;
			itemName[ITEM_SWORD].pos = SWORD_NAME_POS;
			itemName[ITEM_MAGIC_SWORD].pos = MAGICSWORD_NAME_POS;
			itemName[ITEM_MISSILE].pos = MISSILE_NAME_POS;

			// �A�C�e���̑I��p & �l�D
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				itemSelect[i].pos = shopItem[i].pos;
				itemPrice[i].pos = shopItem[i].pos + PRICE_POS;
			}

			// �߂�{�^��
			backButton.pos		= BACK_BUTTON_POS;
			backButtonBg.pos	= BACK_BUTTON_POS;
		}

		{// �F

			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				// �A�C�e���̑I��p
				itemSelect[i].col = SHOP_SELECT_COL0;
			}

			// �߂�{�^��
			backButton.col = SHOP_SELECT_COL0;
		}

		{// ���̏�����
			for (int i = 0; i < SHOP_ITEM_MAX; i++)
			{
				// �����Ă��Ȃ�
				weapons[i] = false;
			}
		}

		{// �U����
			weaponsAttack[ITEM_STICK]		= STICK_ATTACK;
			weaponsAttack[ITEM_AX]			= AX_ATTACK;
			weaponsAttack[ITEM_SWORD]		= SWORD_ATTACK;
			weaponsAttack[ITEM_MAGIC_SWORD]	= MAGICSWORD_ATTACK;
			weaponsAttack[ITEM_MISSILE]		= MISSILE_ATTACK;
		}

		{// �l�i
			weaponsPrice[ITEM_STICK]		= STICK_PRICE;
			weaponsPrice[ITEM_AX]			= AX_PRICE;
			weaponsPrice[ITEM_SWORD]		= SWORD_PRICE;
			weaponsPrice[ITEM_MAGIC_SWORD]	= MAGICSWORD_PRICE;
			weaponsPrice[ITEM_MISSILE]		= MISSILE_PRICE;
		}

	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&shopBoard);

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeVtxCenterData(&itemName[i]);

		// ���_���̐ݒ�
		MakeVtxCenterData(&shopItem[i]);

		// ���_���̐ݒ�
		MakeVtxCenterData(&itemSelect[i]);

		// ���_���̐ݒ�
		MakeVtxCenterData(&itemPrice[i]);
	}

	// ���_���̐ݒ�
	MakeVtxCenterData(&backButtonBg);
	MakeVtxCenterData(&backButton);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitShop(void)
{
	// ���X�{�[�h
	RELEASE_TEXTURE(shopBoard);

	// �A�C�e��&�A�C�e����
	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		RELEASE_TEXTURE(itemName[i]);
		RELEASE_TEXTURE(shopItem[i]);
		RELEASE_TEXTURE(itemPrice[i]);
	}

	// �߂�{�^��
	RELEASE_TEXTURE(backButtonBg);
	RELEASE_TEXTURE(backButton);

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateShop(HWND hWnd)
{
	// �A�C�e���Ƃ̓����蔻��
	ItemCollider(hWnd);		

	// �߂�{�^���̓����蔻��
	BackButtonCollider(hWnd);
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawShop(void)
{
	// ���X�{�[�h
	DrawShopBoard();

	// �I��p
	DrawShopSelect();

	// �A�C�e��
	DrawShopItem();

	// �l�D
	DrawItemPrice();

	// �߂�{�^��
	DrawBackButton();
}

//=============================================================================
// �`�揈�� [���X�{�[�h]
//=============================================================================
void DrawShopBoard(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawNormalObject(device, shopBoard);
}

//=============================================================================
// �`�揈�� [�A�C�e��]
//=============================================================================
void DrawShopItem(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// �`�揈��(��ʓI�ȕ`�揈��)
		DrawMoveCenterObject(device, shopItem[i]);

		// �`�揈��(��ʓI�ȕ`�揈��)
		DrawMoveCenterObject(device, itemName[i]);
	}
}

//=============================================================================
// �`�揈�� [�I��p]
//=============================================================================
void DrawShopSelect(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// �`�揈��(�F�̕ύX�E���S���W)
		DrawColorCenterObject(device, itemSelect[i]);
	}
}

//=============================================================================
// �`�揈�� [�l�D]
//=============================================================================
void DrawItemPrice(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		// �`�揈��(�ړ��p�E���S���W)
		DrawMoveCenterObject(device, itemPrice[i]);
	}
}

//=============================================================================
// �߂�{�^��
//=============================================================================
void DrawBackButton(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �w�i
	// �`�揈��(�ړ��p�E���S���W)
	DrawMoveCenterObject(device, backButtonBg);


	// �`�揈��(�F�̕ύX�E���S���W)
	DrawColorCenterObject(device, backButton);
}

//=============================================================================
// �A�C�e���Ƃ̓����蔻��
//=============================================================================
void ItemCollider(HWND hWnd)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < SHOP_ITEM_MAX; i++)
	{
		if (!weapons[i])
		{
			// �A�C�e���Ƃ̓����蔻��
			if (CheckHitBB(GetMousePos(hWnd), shopItem[i].pos, CURSOR_SIZE / 32, shopItem[i].size))
			{
				// �A�C�e���̈ʒu
				itemSelect[i].pos = shopItem[i].pos;

				// �F(�I������Ă��Ȃ�)
				itemSelect[i].col = SHOP_SELECT_COL1;

				if ((IsMouseLeftTriggered() == true) && SetPlayerCoin(0) > weaponsPrice[i])
				{
					// �R�C���̌��Z
					SetPlayerCoin(weaponsPrice[i]);

					// �F(�I�����ꂽ)
					itemSelect[i].col = SHOP_SELECT_COL2;

					// �e�N�X�`���̓ǂݍ���
					LoadTexture(device, &shopItem[i], SHOP_USED_TEXTURE);

					// �����Ă���
					weapons[i] = true;
				}
			}

			else
			{
				// �A�C�e���̐F
				itemSelect[i].col = SHOP_SELECT_COL0;
			}
		}
	}
}

//=============================================================================
// �߂�{�^���̓����蔻��
//=============================================================================
void BackButtonCollider(HWND hWnd)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �A�C�e���Ƃ̓����蔻��
	if (CheckHitBB(GetMousePos(hWnd), backButton.pos, CURSOR_SIZE / 32, backButton.size))
	{
		// �F(�I������Ă��Ȃ�)
		backButton.col = SHOP_SELECT_COL1;

		if (IsMouseLeftTriggered() == true)
		{
			// �Q�[���X�e�[�W
			SetGameStage(1);

			// ��ʑJ��
			SetStage(STAGE_GAME);

			// �^�C�}�[�̃��Z�b�g
			InitTimer(INIT_RE);
		}
	}

	else
	{
		// �A�C�e���̐F
		backButton.col = SHOP_SELECT_COL0;
	}
}

//=============================================================================
// �w������������擾
//=============================================================================
bool GetBoughtWeapons(int no)
{
	return weapons[no];
}