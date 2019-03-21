//=============================================================================
//
// �^�C�g���̔w�i [titleBackground.cpp]
// Author : �� �F��
//
//=============================================================================
#ifndef _TITLE_BACKGROUND_H_
#define _TITLE_BACKGROUND_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �^�C�g���̔w�i
#define TITLE_BACKGROUND_TEXTURE	_T("data/TEXTURE/title/titleBackground.png")
#define TITLE_BACKGROUND_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)
#define TITLE_BACKGROUND_SIZE		D3DXVECTOR2(SCREEN_WIDTH,SCREEN_HEIGHT)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitTitleBackground(int initType);	// ������
void	UninitTitleBackground(void);		// �I������
void	UpdateTitleBackground(void);		// �X�V����
void	DrawTitleBackground(void);			// �`�揈��


#endif
