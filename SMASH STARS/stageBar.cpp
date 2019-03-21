//=============================================================================
// < SMASH STARS >
// �X�e�[�W�o�[ [stageBar.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "input.h"
#include "sound.h"
#include "soundEffect.h"
#include "fastDraw2D.h"
#include "stars.h"
#include "stageBar.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
//----�`�揈��
void DrawStageArrow(void);		// �X�e�[�W���w�����̕`�揈��
void DrawStageStar(void);		// ��

//----�X�V����
void SetStageArrowMove(void);	// �X�e�[�W���w�����̈ړ�����

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
TEXTURE		stageBar;						// �X�e�[�W�o�[
TEXTURE		stageArrow;						// �X�e�[�W���w�����
TEXTURE		stageStars[STARS_MAX];			// ��

LPDIRECTSOUNDBUFFER8 bgm;

float		stageArrowCnt;					// �ړ��p�J�E���^�[

int			gameStage;						// �Q�[���X�e�[�W

//=============================================================================
// ������
//=============================================================================
HRESULT InitStageBar(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// ���ڂ̏�����
	if (initType == INIT_FIRST)
	{
		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &stageBar, STAGE_BAR_TEXTURE);

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &stageArrow, STAGE_BAR_ARROW_TEXTURE);

		// �e�N�X�`���̓ǂݍ���
		LoadTexture(device, &stageStars[STARS_MERCURY], STAR_MERCURY_TEXTURE);
		LoadTexture(device, &stageStars[STARS_VENUS], STAR_VENUS_TEXTURE);
		LoadTexture(device, &stageStars[STARS_EARTH], STAR_EARTH_TEXTURE);
		LoadTexture(device, &stageStars[STARS_MARS], STAR_MARS_TEXTURE);
		LoadTexture(device, &stageStars[STARS_JUPITOR], STAR_JUPITOR_TEXTURE);
		LoadTexture(device, &stageStars[STARS_SATURN], STAR_SATURN_TEXTURE);
		LoadTexture(device, &stageStars[STARS_URANUS], STAR_URANUS_TEXTURE);
		LoadTexture(device, &stageStars[STARS_NEPTUNE], STAR_NEPTUNE_TEXTURE);
		LoadTexture(device, &stageStars[STARS_PLUTO], STAR_PLUTO_TEXTURE);
		LoadTexture(device, &stageStars[STARS_SUN], STAR_SUN0_TEXTURE);

		// �T�E���h�̓ǂݍ���
		bgm = LoadSound(SOUND_2D, BGM_PATH);
		PlaySound(bgm, E_DS8_FLAG_LOOP);
		SetSoundEffect(bgm, E_DS8_FLAG_LOOP, WAVES_REVERB_SOUND_EFFECT);
	}

	// �������g��
	SetSoundFrequency(bgm, 88200);

	{// �e�N�X�`���\���̂̏�����

		// �X�e�[�W�o�[ 
		stageBar.pos	= STAGE_BAR_POS;
		stageBar.size	= STAGE_BAR_SIZE;

		// ��
		stageStars[STARS_MERCURY].pos	= STAGE_BAR_MERCURY_POS;
		stageStars[STARS_VENUS].pos		= STAGE_BAR_VENUS_POS;
		stageStars[STARS_EARTH].pos		= STAGE_BAR_EARTH_POS;
		stageStars[STARS_MARS].pos		= STAGE_BAR_MARS_POS;
		stageStars[STARS_JUPITOR].pos	= STAGE_BAR_JUPITOR_POS;
		stageStars[STARS_SATURN].pos	= STAGE_BAR_SATURN_POS;
		stageStars[STARS_URANUS].pos	= STAGE_BAR_URANUS_POS;
		stageStars[STARS_NEPTUNE].pos	= STAGE_BAR_NEPTUNE_POS;
		stageStars[STARS_PLUTO].pos		= STAGE_BAR_PLUTO_POS;
		stageStars[STARS_SUN].pos		= STAGE_BAR_SUN_POS;

		for (int i = 0; i < STARS_MAX; i++)
		{
			// �T�C�Y
			stageStars[i].size = STAGE_BAR_STARS_SIZE;
		}

		// �X�e�[�W���w�����
		stageArrow.pos	= STAGE_BAR_ARROW_POS;
		stageArrow.size = STAGE_BAR_ARROW_SIZE;

	}

	{// ���̏�����

		// �ړ��p�J���^�[
		stageArrowCnt = NULL;

		// �Q�[���X�e�[�W
		gameStage = STARS_MERCURY;	// �����X�e�[�W

	}

	// ���_���̐ݒ�
	MakeVtx4PointData(&stageBar);

	// ���_���̐ݒ�
	MakeVtxCenterData(&stageArrow);

	for (int i = 0; i < STARS_MAX; i++)
	{
		// ���_���̐ݒ�
		MakeVtxCenterData(&stageStars[i]);
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitStageBar(void)
{
	// �X�e�[�W�o�[
	RELEASE_TEXTURE(stageBar);
	
	// �X�e�[�W���w�����
	RELEASE_TEXTURE(stageArrow);

	// ��
	for (int i = 0; i < STARS_MAX; i++)
	{
		RELEASE_TEXTURE(stageStars[i]);
	}

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateStageBar(void)
{
	// �X�e�[�W���w�����̈ړ�����
	SetStageArrowMove();
}

//=============================================================================
// �X�e�[�W���w�����̈ړ�����
//=============================================================================
void SetStageArrowMove(void)
{
	// �J�E���g
	stageArrowCnt += STAGE_BAR_ARROW_MOVE_SPEED;

	// �I�[�o�[�h�~
	if (stageArrowCnt > INT_MAX)
	{
		// �I�[�o�[�h�~
		stageArrowCnt -= INT_MAX;
	}

#ifdef _DEBUG
	if (GetKeyboardTrigger(DIK_W))
	{
		gameStage++;

		// �I�[�o�[�h�~
		if (gameStage > STARS_SUN)
		{
			gameStage = STARS_MERCURY;
		}
	}
	else if (GetKeyboardTrigger(DIK_S))
	{
		gameStage--;

		// �I�[�o�[�h�~
		if (gameStage < STARS_MERCURY)
		{
			gameStage = STARS_SUN;
		}
	}
#endif

	// ���E�̈ړ�����
	stageArrow.pos.x += sinf(stageArrowCnt);

	// �X�e�[�W���
	stageArrow.pos.y = stageStars[gameStage].pos.y;
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawStageBar(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// �`�揈��(��ʓI�ȕ`�揈��)
	DrawNormalObject(device, stageBar);

	{// ���̕`�揈��

		// �X�e�[�W���w�����̕`�揈��
		DrawStageArrow();

		// ���̕`�揈��
		DrawStageStar();
	}
}

//=============================================================================
// �X�e�[�W���w�����̕`�揈��
//=============================================================================
void DrawStageArrow(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();
	STARS star = *GetStars(GetGameStage());

	// �`�揈��(�ړ��p�E���S���W)
	DrawMoveCenterObject(device, stageArrow);

	if (gameStage == STARS_SUN)
	{	
		float freq = 88200.0f*(((STARS_HP + (STARS_HP * GetGameStage()) - star.HP)) / (STARS_HP + (STARS_HP * GetGameStage())));

		SetSoundFrequency(bgm, 44100 + freq);
	}

}

//=============================================================================
// ���̕`�揈��
//=============================================================================
void DrawStageStar(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < STARS_MAX; i++)
	{
		// �`�揈��(�ړ��p�E���S���W)
		DrawMoveCenterObject(device, stageStars[i]);
	}
}


//=============================================================================
// �Q�[���X�e�[�W���擾
//=============================================================================
int GetGameStage(void)
{
	return gameStage;
}

//=============================================================================
// �Q�[���X�e�[�W���擾
//=============================================================================
void SetGameStage(int stage)
{
	gameStage += stage;

	if (GetGameStage() > STARS_SUN)
	{
		SetStage(STAGE_RESULT);
	}
}