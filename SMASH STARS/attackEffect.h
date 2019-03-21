//=============================================================================
//
// 攻撃のエフェクト [attackEffect.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _ATTACK_EFFECT_H
#define _ATTACK_EFFECT_H

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// エフェクト
#define ATTACK_EFFECT_TEXTURE		_T("data/TEXTURE/effect/attackEffect.png")
#define ATTACK_EFFECT_POS			D3DXVECTOR3(-100.0f,-100.0f,0.0f)
#define ATTACK_EFFECT_SIZE			D3DXVECTOR2(100.0f,100.0f)
#define ATTACK_EFFECT_MAX			(100)
#define ATTACK_EFFECT_X_PATTERN		(8)
#define ATTACK_EFFECT_Y_PATTERN		(2)
#define ATTACK_EFFECT_UPDATE_FREQ	(1)
#define ATTACK_EFFECT_END			(16)

//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct				// 攻撃のエフェクト構造体
{
	TEXTURE		texture;	// テクスチャ構造体
	bool		use;		// true:使用中	false:使用していない
	int			cnt;		// アニメション用カウンター
}ATTACK_EFFECT;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitAttackEffect(int initType);		// 初期化
void UninitAttackEffect(void);				// 終了処理
void UpdateAttackEffect(void);			// 更新処理
void DrawAttackEffect(void);				// 描画処理

void SetAttackEffect(D3DXVECTOR3 pos);		// エフェクトの設置

#endif
