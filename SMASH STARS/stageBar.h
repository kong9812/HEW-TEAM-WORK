//=============================================================================
//
// �X�e�[�W�o�[ [stageBar.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _STAGE_BAR_H_
#define _STAGE_BAR_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �X�e�[�W�o�[
#define STAGE_BAR_TEXTURE			_T("data/TEXTURE/UI/stageBar.png")
#define STAGE_BAR_POS				D3DXVECTOR3(1150.0f,10.0f,0.0f)
#define STAGE_BAR_SIZE				D3DXVECTOR2(50.0f,700.0f)

// �����w�����
#define STAGE_BAR_ARROW_TEXTURE		_T("data/TEXTURE/UI/stageArrow.png")
#define STAGE_BAR_ARROW_POS			D3DXVECTOR3(1050.0f,500.0f,0.0f)
#define STAGE_BAR_ARROW_SIZE		D3DXVECTOR2(60.1f,36.9f)
#define STAGE_BAR_ARROW_MOVE_SPEED	(0.1f) 

// ��
#define STAGE_BAR_SUN_POS			D3DXVECTOR3(1175.0f,50.0f,0.0f)
#define STAGE_BAR_PLUTO_POS			D3DXVECTOR3(1175.0f,120.0f,0.0f)	
#define STAGE_BAR_NEPTUNE_POS		D3DXVECTOR3(1175.0f,190.0f,0.0f)	
#define STAGE_BAR_URANUS_POS		D3DXVECTOR3(1175.0f,260.0f,0.0f)	
#define STAGE_BAR_SATURN_POS		D3DXVECTOR3(1175.0f,330.0f,0.0f)	
#define STAGE_BAR_JUPITOR_POS		D3DXVECTOR3(1175.0f,400.0f,0.0f)	
#define STAGE_BAR_MARS_POS			D3DXVECTOR3(1175.0f,470.0f,0.0f)	
#define STAGE_BAR_EARTH_POS			D3DXVECTOR3(1175.0f,540.0f,0.0f)	
#define STAGE_BAR_VENUS_POS			D3DXVECTOR3(1175.0f,610.0f,0.0f)	
#define STAGE_BAR_MERCURY_POS		D3DXVECTOR3(1175.0f,680.0f,0.0f)	

#define STAGE_BAR_STARS_SIZE		D3DXVECTOR2(25.0f,25.0f)


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitStageBar(int initType);	// ������
void	UninitStageBar(void);		// �I������
void	UpdateStageBar(void);		// �X�V����
void	DrawStageBar(void);			// �`�揈��

int		GetGameStage(void);			// �Q�[���X�e�[�W���擾
void	SetGameStage(int stage);	// �Q�[���X�e�[�W��ݒ�

#endif
