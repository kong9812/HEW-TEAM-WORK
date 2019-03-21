//=============================================================================
// < SMASH STARS >
// �U�� [attack.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "sound.h"
#include "soundEffect.h"
#include "fastDraw2D.h"
#include "input.h"
#include "weapons.h"
#include "stars.h"
#include "timer.h"
#include "coin.h"
#include "stageBar.h"
#include "attackEffect.h"
#include "explosion.h"
#include "attack.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
int GetSaveTime(void);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
LPDIRECTSOUNDBUFFER8	SE[SE_MAX];					// �T�E���h�G�t�F�N�g
int						attack = DEFAULT_ATTACK;	// �U����
int						clearTime;
//=============================================================================
// ������
//=============================================================================
HRESULT InitAttack(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < SE_MAX; i++)
		{
			// �T�E���h�̓ǂݍ���
			SE[i] = LoadSound(E_DS8_FLAG_LOOP, SE_ATTACK);
		}
	}

	attack = DEFAULT_ATTACK;	// ������

	clearTime = 0;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitAttack(void)
{

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateAttack(HWND hWnd)
{
	STARS		*stars		= GetStars(GetGameStage());

	if (stars->use)
	{
		// �}�E�X�̍��{�^������������
		if (IsMouseLeftTriggered())
		{
			// HP
			stars->HP -= attack;

			// �G�t�F�N�g
			SetAttackEffect(GetMousePos(hWnd));

			for (int i = 0; i < SE_MAX; i++)
			{
				if (!IsPlaying(SE[i]))
				{
					// �T�E���h�G�t�F�N�g
					PlaySound(SE[i], E_DS8_FLAG_NONE);
					SetSoundEffect
					(SE[i], E_DS8_FLAG_NONE, DISTORTION_SOUND_EFFECT);
					
					break;
				}
			}

			// HP=0�Ȃ�N���A
			if (stars->HP <= 0)
			{
				// �N���A�^�C���̃Z�[�u
				SetSaveTime();

				// �R�C���̃G�t�F�N�g
				SetCoin(GetMousePos(hWnd));

				// ��
				stars->use = false;

				// �G�t�F�N�g
				SetExplosion();
			}
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawAttack(void)
{

}

//=============================================================================
// �U���͂̕ύX
//=============================================================================
void SetAttack(int atk)
{
	attack = atk;
}

//=============================================================================
// �N���A�^�C���̃Z�[�u
//=============================================================================
void SetSaveTime(void)
{
	clearTime += (TIMER_DEFAULT - GetTimeCnt());
}

//=============================================================================
// �N���A�^�C�����擾
//=============================================================================
int GetSaveTime(void)
{
	return clearTime;
}
