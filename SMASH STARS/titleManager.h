//=============================================================================
//
// タイトルのマネージャー [titleManager.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _TITLE_MANAGER_H_
#define _TITLE_MANAGER_H_

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitTitleManager(int initType);			// 初期化
void UninitTitleManager(void);					// 終了処理
void UpdateTitleManager(void);					// 更新処理
void DrawTitleManager(void);					// 描画処理

#endif