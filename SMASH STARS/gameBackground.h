//=============================================================================
//
// �Q�[���̔w�i [gameBackground.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _GAME_BACKGROUND_H_
#define _GAME_BACKGROUND_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �w�i
#define GAME_BACKGROUND			_T("data/TEXTURE/UI/gameBackground.jpg")
#define GAME_BACKGROUND_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitGameBackground(int initType);	// ������
void	UninitGameBackground(void);		// �I������
void	UpdateGameBackground(void);		// �X�V����
void	DrawGameBackground(void);			// �`�揈��

#endif
