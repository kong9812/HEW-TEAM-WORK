//=============================================================================
// < SMASH STARS >
// �U���̃G�t�F�N�g [attackEffect.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "attackEffect.h"
#include "attackEffect.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
ATTACK_EFFECT	attackEffect[ATTACK_EFFECT_MAX];	// �U���̃G�t�F�N�g�\����
static int		frameCnt;							// �A�j���V�����p�t���[���J�E���^�[

//=============================================================================
// ������
//=============================================================================
HRESULT InitAttackEffect(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
		{
			// �e�N�X�`���̓ǂݍ���
			LoadTexture(device, &attackEffect[i].texture, ATTACK_EFFECT_TEXTURE);
		}
	}

	{// ���̏�����
		// �t���[���J�E���^�[
		frameCnt = 0;
	}

	{// �U���̃G�t�F�N�g�\���̂̏����� & ���_���̐ݒ�

		for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
		{
			// �U���̃G�t�F�N�g
			attackEffect[i].texture.pos = ATTACK_EFFECT_POS;
			// �U���̃G�t�F�N�g
			attackEffect[i].texture.size = ATTACK_EFFECT_SIZE;
			// �g�p��
			attackEffect[i].use = false;
			// �J�E���^�[
			attackEffect[i].cnt = 0;

			// ���_���̐ݒ�
			MakeCutVtx4PointData
			(&attackEffect[i].texture, ATTACK_EFFECT_X_PATTERN, ATTACK_EFFECT_Y_PATTERN,
				ATTACK_EFFECT_X_PATTERN * ATTACK_EFFECT_Y_PATTERN);
		}
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitAttackEffect(void)
{
	for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
	{
		// �U���̃G�t�F�N�g
		RELEASE_TEXTURE(attackEffect[i].texture);
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateAttackEffect(void)
{
	// �t���[���̌o��
	frameCnt++;

	// 600�t���[�����
	if ((frameCnt%ATTACK_EFFECT_UPDATE_FREQ) == 0)
	{
		for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
		{
			// �g�p�󋵂��`�F�b�N
			if (attackEffect[i].use)
			{
				// �J�E���^�[�̏�����
				attackEffect[i].cnt++;

				// �I�[�o�[
				if (attackEffect[i].cnt > ATTACK_EFFECT_END)
				{
					// �J�E���^�[��0��
					attackEffect[i].cnt = 0;

					// ��ʂ̊O�ړ�
					attackEffect[i].texture.pos = ATTACK_EFFECT_POS;

					// �A�j���V��������
					attackEffect[i].use = false;
				}
			}
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawAttackEffect(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
	{
		// �g�p�󋵂��`�F�b�N
		if (attackEffect[i].use)
		{
			// �`�揈��(��ʓI�ȕ`�揈��)
			DrawAnimationObject
			(device, attackEffect[i].texture, attackEffect[i].cnt, ATTACK_EFFECT_X_PATTERN, ATTACK_EFFECT_Y_PATTERN);
		}
	}
}

//=============================================================================
// �G�t�F�N�g�̐ݒu
//=============================================================================
void SetAttackEffect(D3DXVECTOR3 pos)
{
	for (int i = 0; i < ATTACK_EFFECT_MAX; i++)
	{
		// �g�p�󋵂��`�F�b�N
		if (!attackEffect[i].use)
		{
			// �ʒu���Z�b�g
			attackEffect[i].texture.pos = pos;

			// �g�p=true
			attackEffect[i].use = true;

			// ��񂸂�
			break;
		}
	}
}