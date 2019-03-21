//=============================================================================
//
// �U�� [attack.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _ATTACK_H
#define _ATTACK_H

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define DEFAULT_ATTACK		(1)
#define SE_MAX				(20)

// �T�E���h�G�t�F�N�g
#define SE_ATTACK			_T("data/SOUND/SE/defend000.wav")
//#define SE_STICK			_T("data/SOUND/SE/hit000.wav")
//#define SE_AX				_T("data/SOUND/SE/defend001.wav")
//#define SE_SWORD			_T("data/SOUND/SE/defend001.wav")
//#define SE_MAGICSWORD		_T("data/SOUND/SE/defend001.wav")
//#define SE_MISSILE		_T("data/SOUND/SE/bomb000.wav")

//*****************************************************************************
// �\���̐錾
//*****************************************************************************
typedef struct				// �����̍\����
{
	TEXTURE		num;		// �e�N�X�`���\����
	TEXTURE		frame;		// �e�N�X�`���\����
	TEXTURE		background;	// �e�N�X�`���\����
	TEXTURE		weapons;	// �e�N�X�`���\����
}SOUND;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitAttack(int initType);
void UninitAttack(void);
void UpdateAttack(HWND hWnd);
void DrawAttack(void);				

void SetAttack(int atk);			// �U���͂̕ύX
int GetSaveTime(void);	

#endif
