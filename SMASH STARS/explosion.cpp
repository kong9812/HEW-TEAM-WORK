//=============================================================================
// < SMASH STARS >
// ���̔��� [explosion.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "fastDraw2D.h"
#include "soundEffect.h"
#include "sound.h"
#include "stars.h"
#include "stageBar.h"
#include "explosion.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
LPDIRECTSOUNDBUFFER8	explosionSe;	// �T�E���h�G�t�F�N�g
EXPLOSION				explosion;		// �����̍\����
static int				frameCnt;		// �A�j���V�����p�t���[���J�E���^�[

//=============================================================================
// ������
//=============================================================================
HRESULT InitExplosion(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &explosion.texture, EXPLOSION_TEXTURE);

		// �T�E���h�̓ǂݍ���
		explosionSe = LoadSound(SOUND_2D, SE_EXPLOSION);
	}

	{// ���̏�����
	 // �t���[���J�E���^�[
		frameCnt = 0;
	}

	{// �U���̃G�t�F�N�g�\���̂̏����� & ���_���̐ݒ�

			// �U���̃G�t�F�N�g
			explosion.texture.pos = EXPLOSION_POS;
			// �U���̃G�t�F�N�g
			explosion.texture.size = STARS_SIZE;
			// �g�p��
			explosion.use = false;
			// �J�E���^�[
			explosion.cnt = 0;

			// ���_���̐ݒ�
			MakeCutVtx4PointData
			(&explosion.texture, EXPLOSION_X_PATTERN, EXPLOSION_Y_PATTERN,
			EXPLOSION_X_PATTERN * EXPLOSION_Y_PATTERN);
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitExplosion(void)
{
	// �U���̃G�t�F�N�g
	RELEASE_TEXTURE(explosion.texture);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateExplosion(void)
{
	// �t���[���̌o��
	frameCnt++;

	// 600�t���[�����
	if ((frameCnt%EXPLOSION_UPDATE_FREQ) == 0)
	{
		// �g�p�󋵂��`�F�b�N
		if (explosion.use)
		{
			// �J�E���^�[�̏�����
			explosion.cnt++;

			// �I�[�o�[
			if (explosion.cnt > EXPLOSION_END)
			{
				// �J�E���^�[��0��
				explosion.cnt = 0;

				// ��ʂ̊O�ړ�
				explosion.texture.pos = EXPLOSION_POS;

				// �A�j���V��������
				explosion.use = false;

				if (GetGameStage() == STARS_SUN)
				{
					// ��ʑJ��
					SetStage(STAGE_CLEAR);
				}
				else
				{
					// ��ʑJ��
					SetStage(STAGE_SHOP);
				}
			}
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawExplosion(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �g�p�󋵂��`�F�b�N
	if (explosion.use)
	{
		// �`�揈��(��ʓI�ȕ`�揈��)
		DrawAnimationObject
		(device, explosion.texture, explosion.cnt, EXPLOSION_X_PATTERN, EXPLOSION_Y_PATTERN);
	}
}

//=============================================================================
// �G�t�F�N�g�̐ݒu
//=============================================================================
void SetExplosion(void)
{
	// �g�p�󋵂��`�F�b�N
	if (!explosion.use)
	{
		// �ʒu���Z�b�g
		explosion.texture.pos = STARS_POS;

		// �g�p=true
		explosion.use = true;

		// �T�E���h�G�t�F�N�g
		PlaySound(explosionSe, E_DS8_FLAG_NONE);
		SetSoundEffect(explosionSe, E_DS8_FLAG_NONE, DISTORTION_SOUND_EFFECT);
	}
}