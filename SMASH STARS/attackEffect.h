//=============================================================================
//
// �U���̃G�t�F�N�g [attackEffect.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _ATTACK_EFFECT_H
#define _ATTACK_EFFECT_H

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �G�t�F�N�g
#define ATTACK_EFFECT_TEXTURE		_T("data/TEXTURE/effect/attackEffect.png")
#define ATTACK_EFFECT_POS			D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define ATTACK_EFFECT_SIZE			D3DXVECTOR2(100.0f,100.0f)
#define ATTACK_EFFECT_MAX			(100)
#define ATTACK_EFFECT_X_PATTERN		(8)
#define ATTACK_EFFECT_Y_PATTERN		(2)
#define ATTACK_EFFECT_UPDATE_FREQ	(1)
#define ATTACK_EFFECT_END			(16)

//*****************************************************************************
// �\���̐錾
//*****************************************************************************
typedef struct				// �U���̃G�t�F�N�g�\����
{
	TEXTURE		texture;	// �e�N�X�`���\����
	bool		use;		// true:�g�p��	false:�g�p���Ă��Ȃ�
	int			cnt;		// �A�j���V�����p�J�E���^�[
}ATTACK_EFFECT;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitAttackEffect(int initType);		// ������
void UninitAttackEffect(void);				// �I������
void UpdateAttackEffect(void);			// �X�V����
void DrawAttackEffect(void);				// �`�揈��

void SetAttackEffect(D3DXVECTOR3 pos);		// �G�t�F�N�g�̐ݒu

#endif
