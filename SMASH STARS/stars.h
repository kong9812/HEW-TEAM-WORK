//=============================================================================
//
// �� [stage.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _STAR_H_
#define _STAR_H_

#include "basic.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// ���̃e�N�X�`��
#define STAR_MERCURY_TEXTURE	_T("data/TEXTURE/stars/space02_mercury.png")
#define STAR_VENUS_TEXTURE		_T("data/TEXTURE/stars/space03_venus.png")
#define STAR_EARTH_TEXTURE		_T("data/TEXTURE/stars/space04_earth.png")
#define STAR_MARS_TEXTURE		_T("data/TEXTURE/stars/space05_mars.png")
#define STAR_JUPITOR_TEXTURE	_T("data/TEXTURE/stars/space06_jupitor.png")
#define STAR_SATURN_TEXTURE		_T("data/TEXTURE/stars/space07_saturn.png")
#define STAR_URANUS_TEXTURE		_T("data/TEXTURE/stars/space07_uranus .png")
#define STAR_NEPTUNE_TEXTURE	_T("data/TEXTURE/stars/space08_neptune.png")
#define STAR_PLUTO_TEXTURE		_T("data/TEXTURE/stars/space09_pluto.png")
#define STAR_SUN_TEXTURE		_T("data/TEXTURE/stars/space01_sun.png")
#define STAR_SUN0_TEXTURE		_T("data/TEXTURE/stars/space01_sun0.png")

// ��
#define STARS_MAX				(10)
#define STARS_POS				D3DXVECTOR3(500.0f,400.0f,0.0f)
#define STARS_SIZE				D3DXVECTOR2(300,300)

#define STARS_HP				(100.0f)

// BGM
#define BGM_PATH				_T("data/SOUND/bgm.wav")

//*****************************************************************************
// �\���̐錾
//*****************************************************************************
typedef struct
{
	TEXTURE	texture;		// �X�e�[�W���w�����
	int		HP;				// HP
	bool	use;			// �����Ă�H true:�����Ă�
}STARS;

//*****************************************************************************
// �萔��`
//*****************************************************************************
enum STARS_LIST
{
	STARS_MERCURY,
	STARS_VENUS,
	STARS_EARTH,
	STARS_MARS,
	STARS_JUPITOR,
	STARS_SATURN,
	STARS_URANUS,
	STARS_NEPTUNE,
	STARS_PLUTO,
	STARS_SUN
};

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitStars(int initType);	// ������
void	UninitStars(void);			// �I������
void	UpdateStars(void);			// �X�V����
void	DrawStars(void);			// �`�揈��

STARS	*GetStars(int no);			// ���̏����擾


#endif
