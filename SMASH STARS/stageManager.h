//=============================================================================
//
// �X�e�[�W�̃}�l�[�W���[ [stageManager.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _STAGE_MANAGER_H_
#define _STAGE_MANAGER_H_

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitStageManager(int initType);	// ������
void	UninitStageManager(void);		// �I������
void	UpdateStageManager(HWND hWnd);	// �X�V����
void	DrawStageManager(void);			// �`�揈��


#endif
