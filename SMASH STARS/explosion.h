//=============================================================================
//
// ���̔��� [explosion.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _EXPLOSION_H
#define _EXPLOSION_H

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �G�t�F�N�g
#define EXPLOSION_TEXTURE		_T("data/TEXTURE/effect/explosionAnimation.png")
#define EXPLOSION_POS			D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define EXPLOSION_X_PATTERN		(5)
#define EXPLOSION_Y_PATTERN		(3)
#define EXPLOSION_UPDATE_FREQ	(3)
#define EXPLOSION_END			(11)
#define SE_EXPLOSION			_T("data/SOUND/SE/bomb000.wav")
//*****************************************************************************
// �\���̐錾
//*****************************************************************************
typedef struct				// �����̍\����
{
	TEXTURE		texture;	// �e�N�X�`���\����
	bool		use;		// true:�g�p��	false:�g�p���Ă��Ȃ�
	int			cnt;		// �A�j���V�����p�J�E���^�[
}EXPLOSION;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitExplosion(int initType);	// ������
void UninitExplosion(void);				// �I������
void UpdateExplosion(void);				// �X�V����
void DrawExplosion(void);				// �`�揈��

void SetExplosion(void);		// �G�t�F�N�g�̐ݒu

#endif
