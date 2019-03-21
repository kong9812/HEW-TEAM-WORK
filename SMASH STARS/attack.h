//=============================================================================
//
// 攻撃 [attack.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _ATTACK_H
#define _ATTACK_H

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define DEFAULT_ATTACK		(1)
#define SE_MAX				(20)

// サウンドエフェクト
#define SE_ATTACK			_T("data/SOUND/SE/defend000.wav")
//#define SE_STICK			_T("data/SOUND/SE/hit000.wav")
//#define SE_AX				_T("data/SOUND/SE/defend001.wav")
//#define SE_SWORD			_T("data/SOUND/SE/defend001.wav")
//#define SE_MAGICSWORD		_T("data/SOUND/SE/defend001.wav")
//#define SE_MISSILE		_T("data/SOUND/SE/bomb000.wav")

//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct				// 爆発の構造体
{
	TEXTURE		num;		// テクスチャ構造体
	TEXTURE		frame;		// テクスチャ構造体
	TEXTURE		background;	// テクスチャ構造体
	TEXTURE		weapons;	// テクスチャ構造体
}SOUND;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitAttack(int initType);
void UninitAttack(void);
void UpdateAttack(HWND hWnd);
void DrawAttack(void);				

void SetAttack(int atk);			// 攻撃力の変更
int GetSaveTime(void);	

#endif
