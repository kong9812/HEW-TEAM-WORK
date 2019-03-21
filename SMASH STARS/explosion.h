//=============================================================================
//
// 星の爆発 [explosion.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _EXPLOSION_H
#define _EXPLOSION_H

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// エフェクト
#define EXPLOSION_TEXTURE		_T("data/TEXTURE/effect/explosionAnimation.png")
#define EXPLOSION_POS			D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define EXPLOSION_X_PATTERN		(5)
#define EXPLOSION_Y_PATTERN		(3)
#define EXPLOSION_UPDATE_FREQ	(3)
#define EXPLOSION_END			(11)
#define SE_EXPLOSION			_T("data/SOUND/SE/bomb000.wav")
//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct				// 爆発の構造体
{
	TEXTURE		texture;	// テクスチャ構造体
	bool		use;		// true:使用中	false:使用していない
	int			cnt;		// アニメション用カウンター
}EXPLOSION;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitExplosion(int initType);	// 初期化
void UninitExplosion(void);				// 終了処理
void UpdateExplosion(void);				// 更新処理
void DrawExplosion(void);				// 描画処理

void SetExplosion(void);		// エフェクトの設置

#endif
