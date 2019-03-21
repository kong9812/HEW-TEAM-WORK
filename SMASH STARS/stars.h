//=============================================================================
//
// 星 [stage.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _STAR_H_
#define _STAR_H_

#include "basic.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// 星のテクスチャ
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

// 星
#define STARS_MAX				(10)
#define STARS_POS				D3DXVECTOR3(500.0f,400.0f,0.0f)
#define STARS_SIZE				D3DXVECTOR2(300,300)

#define STARS_HP				(100.0f)

// BGM
#define BGM_PATH				_T("data/SOUND/bgm.wav")

//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct
{
	TEXTURE	texture;		// ステージを指す矢印
	int		HP;				// HP
	bool	use;			// 生きてる？ true:生きてる
}STARS;

//*****************************************************************************
// 定数定義
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
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitStars(int initType);	// 初期化
void	UninitStars(void);			// 終了処理
void	UpdateStars(void);			// 更新処理
void	DrawStars(void);			// 描画処理

STARS	*GetStars(int no);			// 星の情報を取得


#endif
