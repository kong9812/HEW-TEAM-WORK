//=============================================================================
//
// Q[Μwi [gameBackground.h]
// Author : δο F
//
//=============================================================================
#ifndef _GAME_BACKGROUND_H_
#define _GAME_BACKGROUND_H_

//*****************************************************************************
// }Nθ`
//*****************************************************************************
// wi
#define GAME_BACKGROUND			_T("data/TEXTURE/UI/gameBackground.jpg")
#define GAME_BACKGROUND_POS		D3DXVECTOR3(0.0f,0.0f,0.0f)

//*****************************************************************************
// vg^CvιΎ
//*****************************************************************************
HRESULT InitGameBackground(int initType);	// ϊ»
void	UninitGameBackground(void);		// IΉ
void	UpdateGameBackground(void);		// XV
void	DrawGameBackground(void);			// `ζ

#endif
