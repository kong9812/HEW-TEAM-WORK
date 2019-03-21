//=============================================================================
//
// ステージのマネージャー [stageManager.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _STAGE_MANAGER_H_
#define _STAGE_MANAGER_H_

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitStageManager(int initType);	// 初期化
void	UninitStageManager(void);		// 終了処理
void	UpdateStageManager(HWND hWnd);	// 更新処理
void	DrawStageManager(void);			// 描画処理


#endif
