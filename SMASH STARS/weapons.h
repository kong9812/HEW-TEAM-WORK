//=============================================================================
//
// 武器 [weapons.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _WEAPONS_H
#define _WEAPONS_H

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// 武器
#define WEAPONS_FRAME_TEXTURE	_T("data/TEXTURE/UI/weapons/itemFrame.png")
#define WEAPONS_DEFAULT			D3DXVECTOR3(50.0f,250.0f,0.0f)
#define WEAPONS_POS				D3DXVECTOR3(0.0f,90.0f,0.0f)
#define WEAPONS_SIZE			D3DXVECTOR2(100.0f,100.0f)
// フレーム
#define WEAPONS_FRAME_DEFAULT	D3DXVECTOR3(0.0f,250.0f,0.0f)
#define WEAPONS_FRAME_POS		D3DXVECTOR3(0.0f,90.0f,0.0f)
#define WEAPONS_FRAME_SIZE		D3DXVECTOR2(150.0f,100.0f)
// 数字
#define WEAPONS_NUM_DEFAULT		D3DXVECTOR3(10.0f,270.0f,0.0f)
#define WEAPONS_NUM_POS			D3DXVECTOR3(0.0f,90.0f,0.0f)
#define WEAPONS_NUM_SIZE		D3DXVECTOR2(35.0f,70.0f)

#define WEAPONS_MAX				(5)

//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct				// 爆発の構造体
{
	TEXTURE		num;		// テクスチャ構造体
	TEXTURE		frame;		// テクスチャ構造体
	TEXTURE		background;	// テクスチャ構造体
	TEXTURE		weapons;	// テクスチャ構造体
	int			times;		// 使える回数
}WEAPONS;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitWeapons(int initType);	// 初期化
void UninitWeapons(void);			// 終了処理
void UpdateWeapons(void);			// 更新処理
void DrawWeapons(void);				// 描画処理

#endif
