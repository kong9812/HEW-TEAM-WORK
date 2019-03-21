//=============================================================================
//
// �R�C�� [coin.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _COIN_H_
#define _COIN_H_

#include "basic.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �R�C��
#define COIN_TEXTURE				_T("data/TEXTURE/effect/coin.png")
#define COIN_POS					D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define COIN_SIZE					D3DXVECTOR2(25.0f,25.0f)
#define COIN_MAX					(300)
#define COIN_DROP_SPEED				(20)

// �R�C���J�E���^�[
#define COIN_NUM_TEXTURE			_T("data/TEXTURE/UI/number.png")
#define COIN_NUM_MAX				(4)
#define COIN_NUM_POS				D3DXVECTOR3(120.0f,110.0f,0.0f)
#define COIN_NUM_SIZE				D3DXVECTOR2(35.0f,70.0f)
#define COIN_X_PATTERN				(10)
#define COIN_Y_PATTERN				(1)

// �R�C���̃t���[��
#define COIN_FRAME_TEXTURE			_T("data/TEXTURE/UI/gameCoinflame.png")
#define COIN_FRAME_POS				D3DXVECTOR3(10.0f,101.6f,0.0f)
#define COIN_FRAME_SIZE				D3DXVECTOR2(157.0f,101.6f)

//*****************************************************************************
// �\���̐錾
//*****************************************************************************
typedef struct
{
	TEXTURE texture;
	bool	use;

}COIN;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitCoin(int initType);		// ������
void	UninitCoin(void);			// �I������
void	UpdateCoin(void);			// �X�V����
void	DrawCoin(void);				// �`�揈��

void	SetCoin(D3DXVECTOR3 pos);	// �R�C���̐ݒu
int		SetPlayerCoin(int price);	// �R�C���̎擾�E�ݒ�
#endif
