//=============================================================================
//
// ���X [shop.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _SHOP_H_
#define _SHOP_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// ���X�̃{�[�h
#define SHOP_BOARD_TEXTURE		_T("data/TEXTURE/shop/shopBoard.png")
#define SHOP_BOARD_SIZE			D3DXVECTOR2(691.0f,672.0f)
#define SHOP_BOARD_POS			D3DXVECTOR3(294.5f,10.0f,0.0f)
// �A�C�e��
#define SHOP_ITEM_MAX			(5)
#define SHOP_ITEM_SIZE			D3DXVECTOR2(40.0f,40.0f)
#define NAME_SIZE				D3DXVECTOR2(35.0f,35.0f)
// �؂̖_
#define SHOP_ITEM_STICK			_T("data/TEXTURE/shop/item/stick.png")	
#define STICK_NAME				_T("data/TEXTURE/shop/name/nameStick.png")	
#define STICK_POS				D3DXVECTOR3(480.0f,150.0f,0.0f)
#define STICK_NAME_SIZE			D3DXVECTOR2(NAME_SIZE.x * 3.0f,NAME_SIZE.y)
#define STICK_NAME_POS			D3DXVECTOR3(480.0f,230.0f,0.0f)
#define STICK_PRICE				(100)
#define STICK_ATTACK			(2)
// ��
#define SHOP_ITEM_AX			_T("data/TEXTURE/shop/item/ax.png")				
#define AX_NAME					_T("data/TEXTURE/shop/name/nameAx.png")	
#define AX_POS					D3DXVECTOR3(780.0f,150.0f,0.0f)
#define AX_NAME_SIZE			D3DXVECTOR2(NAME_SIZE.x,NAME_SIZE.y)
#define AX_NAME_POS				D3DXVECTOR3(780.0f,230.0f,0.0f)
#define AX_PRICE				(300)
#define AX_ATTACK				(3)
// ��
#define SHOP_ITEM_SWORD			_T("data/TEXTURE/shop/item/sword.png")				
#define SWORD_NAME				_T("data/TEXTURE/shop/name/nameSword.png")	
#define SWORD_POS				D3DXVECTOR3(480.0f,350.0f,0.0f)
#define SWORD_NAME_SIZE			D3DXVECTOR2(NAME_SIZE.x,NAME_SIZE.y)
#define SWORD_NAME_POS			D3DXVECTOR3(480.0f,430.0f,0.0f)
#define SWORD_PRICE				(500)
#define SWORD_ATTACK			(5)
// ���@�̌�
#define SHOP_ITEM_MAGICSWORD	_T("data/TEXTURE/shop/item/magicSword.png")				
#define MAGICSWORD_NAME			_T("data/TEXTURE/shop/name/nameMagicSword.png")	
#define MAGICSWORD_POS			D3DXVECTOR3(780.0f,350.0f,0.0f)
#define MAGICSWORD_NAME_SIZE	D3DXVECTOR2(NAME_SIZE.x * 4.0f,NAME_SIZE.y)
#define MAGICSWORD_NAME_POS		D3DXVECTOR3(780.0f,430.0f,0.0f)
#define MAGICSWORD_PRICE		(800)
#define MAGICSWORD_ATTACK		(8)
// �~�T�C��
#define SHOP_ITEM_MISSILE		_T("data/TEXTURE/shop/item/missile.png")
#define MISSILE_NAME			_T("data/TEXTURE/shop/name/nameMissile.png")	
#define MISSILE_POS				D3DXVECTOR3(625.0f,550.0f,0.0f)
#define MISSILE_NAME_SIZE		D3DXVECTOR2(NAME_SIZE.x * 4.0f,NAME_SIZE.y)
#define MISSILE_NAME_POS		D3DXVECTOR3(625.0f,630.0f,0.0f)
#define MISSILE_PRICE			(1000)
#define MISSILE_ATTACK			(10)
// �I��p
#define SHOP_USED_TEXTURE		_T("data/TEXTURE/shop/item/used.png")				
#define SHOP_SELECT_POS			D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define SHOP_SELECT_SIZE		D3DXVECTOR2(40.0f,40.0f)
#define SHOP_SELECT_COL0		D3DXCOLOR(255.0f,255.0f,255.0f,255.0f)	
#define SHOP_SELECT_COL1		D3DXCOLOR(0.0f,255.0f,0.0f,255.0f)	
#define SHOP_SELECT_COL2		D3DXCOLOR(255.0f,0.0f,0.0f,255.0f)	

// �l�D
#define PRICE_STICK				_T("data/TEXTURE/shop/price/stickPrice.png")
#define PRICE_AX				_T("data/TEXTURE/shop/price/axPrice.png")
#define PRICE_SWORD				_T("data/TEXTURE/shop/price/swordPrice.png")
#define PRICE_MAGICSWORD		_T("data/TEXTURE/shop/price/magicSwordPrice.png")
#define PRICE_MISSILE			_T("data/TEXTURE/shop/price/missilePrice.png")
#define PRICE_POS				D3DXVECTOR3(100.0f,0.0f,0.0f)
#define PRICE_SIZE				D3DXVECTOR2(50.0f,32.0f)

// �߂�{�^��
#define BACK_BUTTON_TEXTURE		_T("data/TEXTURE/UI/backBotton/logo.png")
#define BACK_BUTTON_BG_TEXTURE	_T("data/TEXTURE/UI/backBotton/background.png")
#define BACK_BUTTON_POS			D3DXVECTOR3(1180.0f,620.0f,0.0f)
#define BACK_BUTTON_SIZE		D3DXVECTOR2(100.0f,100.0f)

//*****************************************************************************
// �萔��`
//*****************************************************************************
enum SHOP_ITEM
{
	ITEM_STICK,
	ITEM_AX,
	ITEM_SWORD,
	ITEM_MAGIC_SWORD,
	ITEM_MISSILE
};

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitShop(int initType);		// ������
void	UninitShop(void);			// �I������
void	UpdateShop(HWND hWnd);		// �X�V����
void	DrawShop(void);				// �`�揈��

bool	GetBoughtWeapons(int no);	// �w������������擾

#endif
