//=============================================================================
//
// �����`�揈��[2D] [fastDraw2D.cpp]
// Author : �� �F��
//
//=============================================================================
#ifndef _TITLE_LOGO_H_
#define _TITLE_LOGO_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �^�C�g���̃��S
#define TITLE_LOGO_TEXTURE			_T("data/TEXTURE/title/titleLogo.png")
#define TITLE_LOGO_POS				D3DXVECTOR3(SCREEN_WIDTH/HALF,SCREEN_HEIGHT*2.0f,0.0f)
#define TITLE_LOGO_SIZE				D3DXVECTOR2(291.0f,241.5f)
#define TITLE_LOGO_MOVE_SPEED		(25.0f)
#define TITLE_LOGO_STOP_POS_Y		(SCREEN_HEIGHT/HALF)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitTitleLogo(int initType);	// ������
void	UninitTitleLogo(void);			// �I������
void	UpdateTitleLogo(void);			// �X�V����
void	DrawTitleLogo(void);			// �`�揈��



#endif