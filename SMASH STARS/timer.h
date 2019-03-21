//=============================================================================
//
// �^�C�}�[ [timer.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _TIMER_H_
#define _TIMER_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �^�C�}�[
#define TIMER_TEXTURE		_T("data/TEXTURE/UI/number.png")
#define TIMER_NUM_MAX		(2)
#define TIMER_NUM_POS		D3DXVECTOR3(85.0f,30.0f,0.0f)
#define TIMER_NUM_SIZE		D3DXVECTOR2(35.0f,70.0f)
#define TIMER_X_PATTERN		(10)
#define TIMER_Y_PATTERN		(1)
#define TIMER_DEFAULT		(60)
#define TIMER_ADD			(30)

// �^�C�}�[�̃t���[��
#define TIMER_FRAME_TEXTURE	_T("data/TEXTURE/UI/timeFlame.png")
#define TIMER_FRAME_POS		D3DXVECTOR3(10.0f,0.0f,0.0f)
#define TIMER_FRAME_SIZE	D3DXVECTOR2(157.0f,101.6f)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitTimer(int initType);	// ������
void	UninitTimer(void);			// �I������
void	UpdateTimer(void);			// �X�V����
void	DrawTimer(void);			// �`�揈��

void	SetSaveTime(void);			// �N���A�^�C���̃Z�[�u
int		GetTimeCnt(void);			// �N���A�^�C�����擾

#endif
