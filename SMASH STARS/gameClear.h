//=============================================================================
//
// �Q�[���N���A [gameClear.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _GAME_CLEAR_H_
#define _GAME_CLEAR_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �w�i
#define GAME_CLEAR			_T("data/TEXTURE/UI/gameClear.png")
#define GAME_CLEAR_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)
#define TIME_DIGIT			(3)
#define TIME_NUM_SIZE		D3DXVECTOR2(35.0f,70.0f)
#define TIME_X_PATTERN		(10)
#define TIME_Y_PATTERN		(1)
#define TIME_DEFAULT		(60)
#define TIME_ADD			(30)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitGameClear(int initType);	// ������
void	UninitGameClear(void);			// �I������
void	UpdateGameClear(void);			// �X�V����
void	DrawGameClear(void);			// �`�揈��

#endif
