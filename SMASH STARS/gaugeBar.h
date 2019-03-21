//=============================================================================
//
// �Q�[�W�o�[ [gaugeBar.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _GAUGE_BAR_H_
#define _GAUGE_BAR_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �Q�[�W�̔w�i
#define GAUGE_BACKGROUNG_TEXTURE	_T("data/TEXTURE/gauge/gaugeBackground.png")
#define GAUGE_BACKGROUNG_POS		D3DXVECTOR3(170.0f,10.0f,0.0f)
#define GAUGE_BACKGROUNG_SIZE		D3DXVECTOR2(800.0f,100.0f)
// �Q�[�W
#define GAUGE_POS					D3DXVECTOR3(185.0f,30.0f,0.0f)
#define GAUGE_SIZE					D3DXVECTOR2(775.0f,60.0f)
#define GAUGE_COL					D3DXCOLOR(255.0f,0.0f,0.0f,255.0f)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitGaugeBar(int initType);	// ������
void	UninitGaugeBar(void);		// �I������
void	UpdateGaugeBar(void);		// �X�V����
void	DrawGaugeBar(void);			// �`�揈��

#endif
