//=============================================================================
// < SMASH STARS >
// �Q�[���I�[�o�[ [gameOver.cpp]
// Author : �� �F��
//
//=============================================================================
#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �Q�[���I�[�o�[[����]
#define GAME_OVER_TEXTURE		_T("data/TEXTURE/gameOver/gameOver.png")
#define GAME_OVER_SIZE			D3DXVECTOR2(417.0f,75.5f)
#define GAME_OVER_POS			D3DXVECTOR3(0.0f,-100.0f,0.0f)

// �Q�[���I�[�o�[[���S]
#define GAME_OVER_LOGO_TEXTURE	_T("data/TEXTURE/gameOver/gameOverLogo.png")
#define GAME_OVER_LOGO_SIZE		D3DXVECTOR2(412.0f,415.0f)
#define GAME_OVER_LOGO_POS		D3DXVECTOR3(0.0f,100.0f,0.0f)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitGameOver(int initType);		// ������
void UninitGameOver(void);				// �I������
void UpdateGameOver(void);				// �X�V����
void DrawGameOver(void);				// �`�揈��

#endif