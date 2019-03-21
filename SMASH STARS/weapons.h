//=============================================================================
//
// ���� [weapons.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _WEAPONS_H
#define _WEAPONS_H

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// ����
#define WEAPONS_FRAME_TEXTURE	_T("data/TEXTURE/UI/weapons/itemFrame.png")
#define WEAPONS_DEFAULT			D3DXVECTOR3(50.0f,250.0f,0.0f)
#define WEAPONS_POS				D3DXVECTOR3(0.0f,90.0f,0.0f)
#define WEAPONS_SIZE			D3DXVECTOR2(100.0f,100.0f)
// �t���[��
#define WEAPONS_FRAME_DEFAULT	D3DXVECTOR3(0.0f,250.0f,0.0f)
#define WEAPONS_FRAME_POS		D3DXVECTOR3(0.0f,90.0f,0.0f)
#define WEAPONS_FRAME_SIZE		D3DXVECTOR2(150.0f,100.0f)
// ����
#define WEAPONS_NUM_DEFAULT		D3DXVECTOR3(10.0f,270.0f,0.0f)
#define WEAPONS_NUM_POS			D3DXVECTOR3(0.0f,90.0f,0.0f)
#define WEAPONS_NUM_SIZE		D3DXVECTOR2(35.0f,70.0f)

#define WEAPONS_MAX				(5)

//*****************************************************************************
// �\���̐錾
//*****************************************************************************
typedef struct				// �����̍\����
{
	TEXTURE		num;		// �e�N�X�`���\����
	TEXTURE		frame;		// �e�N�X�`���\����
	TEXTURE		background;	// �e�N�X�`���\����
	TEXTURE		weapons;	// �e�N�X�`���\����
	int			times;		// �g�����
}WEAPONS;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitWeapons(int initType);	// ������
void UninitWeapons(void);			// �I������
void UpdateWeapons(void);			// �X�V����
void DrawWeapons(void);				// �`�揈��

#endif
