//=============================================================================
// < SMASH STARS >
// ステージバー [stageBar.cpp]
// Author : 蔡 友剛
//
//=============================================================================
#include "main.h"
#include "basic.h"
#include "input.h"
#include "sound.h"
#include "soundEffect.h"
#include "fastDraw2D.h"
#include "stars.h"
#include "stageBar.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
//----描画処理
void DrawStageArrow(void);		// ステージを指す矢印の描画処理
void DrawStageStar(void);		// 星

//----更新処理
void SetStageArrowMove(void);	// ステージを指す矢印の移動処理

//*****************************************************************************
// グローバル変数
//*****************************************************************************
TEXTURE		stageBar;						// ステージバー
TEXTURE		stageArrow;						// ステージを指す矢印
TEXTURE		stageStars[STARS_MAX];			// 星

LPDIRECTSOUNDBUFFER8 bgm;

float		stageArrowCnt;					// 移動用カウンター

int			gameStage;						// ゲームステージ

//=============================================================================
// 初期化
//=============================================================================
HRESULT InitStageBar(int initType)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 一回目の初期化
	if (initType == INIT_FIRST)
	{
		// テクスチャの読み込み
		LoadTexture(device, &stageBar, STAGE_BAR_TEXTURE);

		// テクスチャの読み込み
		LoadTexture(device, &stageArrow, STAGE_BAR_ARROW_TEXTURE);

		// テクスチャの読み込み
		LoadTexture(device, &stageStars[STARS_MERCURY], STAR_MERCURY_TEXTURE);
		LoadTexture(device, &stageStars[STARS_VENUS], STAR_VENUS_TEXTURE);
		LoadTexture(device, &stageStars[STARS_EARTH], STAR_EARTH_TEXTURE);
		LoadTexture(device, &stageStars[STARS_MARS], STAR_MARS_TEXTURE);
		LoadTexture(device, &stageStars[STARS_JUPITOR], STAR_JUPITOR_TEXTURE);
		LoadTexture(device, &stageStars[STARS_SATURN], STAR_SATURN_TEXTURE);
		LoadTexture(device, &stageStars[STARS_URANUS], STAR_URANUS_TEXTURE);
		LoadTexture(device, &stageStars[STARS_NEPTUNE], STAR_NEPTUNE_TEXTURE);
		LoadTexture(device, &stageStars[STARS_PLUTO], STAR_PLUTO_TEXTURE);
		LoadTexture(device, &stageStars[STARS_SUN], STAR_SUN0_TEXTURE);

		// サウンドの読み込み
		bgm = LoadSound(SOUND_2D, BGM_PATH);
		PlaySound(bgm, E_DS8_FLAG_LOOP);
		SetSoundEffect(bgm, E_DS8_FLAG_LOOP, WAVES_REVERB_SOUND_EFFECT);
	}

	// 初期周波数
	SetSoundFrequency(bgm, 88200);

	{// テクスチャ構造体の初期化

		// ステージバー 
		stageBar.pos	= STAGE_BAR_POS;
		stageBar.size	= STAGE_BAR_SIZE;

		// 星
		stageStars[STARS_MERCURY].pos	= STAGE_BAR_MERCURY_POS;
		stageStars[STARS_VENUS].pos		= STAGE_BAR_VENUS_POS;
		stageStars[STARS_EARTH].pos		= STAGE_BAR_EARTH_POS;
		stageStars[STARS_MARS].pos		= STAGE_BAR_MARS_POS;
		stageStars[STARS_JUPITOR].pos	= STAGE_BAR_JUPITOR_POS;
		stageStars[STARS_SATURN].pos	= STAGE_BAR_SATURN_POS;
		stageStars[STARS_URANUS].pos	= STAGE_BAR_URANUS_POS;
		stageStars[STARS_NEPTUNE].pos	= STAGE_BAR_NEPTUNE_POS;
		stageStars[STARS_PLUTO].pos		= STAGE_BAR_PLUTO_POS;
		stageStars[STARS_SUN].pos		= STAGE_BAR_SUN_POS;

		for (int i = 0; i < STARS_MAX; i++)
		{
			// サイズ
			stageStars[i].size = STAGE_BAR_STARS_SIZE;
		}

		// ステージを指す矢印
		stageArrow.pos	= STAGE_BAR_ARROW_POS;
		stageArrow.size = STAGE_BAR_ARROW_SIZE;

	}

	{// 他の初期化

		// 移動用カンター
		stageArrowCnt = NULL;

		// ゲームステージ
		gameStage = STARS_MERCURY;	// 初期ステージ

	}

	// 頂点情報の設定
	MakeVtx4PointData(&stageBar);

	// 頂点情報の設定
	MakeVtxCenterData(&stageArrow);

	for (int i = 0; i < STARS_MAX; i++)
	{
		// 頂点情報の設定
		MakeVtxCenterData(&stageStars[i]);
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitStageBar(void)
{
	// ステージバー
	RELEASE_TEXTURE(stageBar);
	
	// ステージを指す矢印
	RELEASE_TEXTURE(stageArrow);

	// 星
	for (int i = 0; i < STARS_MAX; i++)
	{
		RELEASE_TEXTURE(stageStars[i]);
	}

}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateStageBar(void)
{
	// ステージを指す矢印の移動処理
	SetStageArrowMove();
}

//=============================================================================
// ステージを指す矢印の移動処理
//=============================================================================
void SetStageArrowMove(void)
{
	// カウント
	stageArrowCnt += STAGE_BAR_ARROW_MOVE_SPEED;

	// オーバー防止
	if (stageArrowCnt > INT_MAX)
	{
		// オーバー防止
		stageArrowCnt -= INT_MAX;
	}

#ifdef _DEBUG
	if (GetKeyboardTrigger(DIK_W))
	{
		gameStage++;

		// オーバー防止
		if (gameStage > STARS_SUN)
		{
			gameStage = STARS_MERCURY;
		}
	}
	else if (GetKeyboardTrigger(DIK_S))
	{
		gameStage--;

		// オーバー防止
		if (gameStage < STARS_MERCURY)
		{
			gameStage = STARS_SUN;
		}
	}
#endif

	// 左右の移動処理
	stageArrow.pos.x += sinf(stageArrowCnt);

	// ステージ状態
	stageArrow.pos.y = stageStars[gameStage].pos.y;
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawStageBar(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	// 描画処理(一般的な描画処理)
	DrawNormalObject(device, stageBar);

	{// 他の描画処理

		// ステージを指す矢印の描画処理
		DrawStageArrow();

		// 星の描画処理
		DrawStageStar();
	}
}

//=============================================================================
// ステージを指す矢印の描画処理
//=============================================================================
void DrawStageArrow(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();
	STARS star = *GetStars(GetGameStage());

	// 描画処理(移動用・中心座標)
	DrawMoveCenterObject(device, stageArrow);

	if (gameStage == STARS_SUN)
	{	
		float freq = 88200.0f*(((STARS_HP + (STARS_HP * GetGameStage()) - star.HP)) / (STARS_HP + (STARS_HP * GetGameStage())));

		SetSoundFrequency(bgm, 44100 + freq);
	}

}

//=============================================================================
// 星の描画処理
//=============================================================================
void DrawStageStar(void)
{
	LPDIRECT3DDEVICE9 device = GetDevice();

	for (int i = 0; i < STARS_MAX; i++)
	{
		// 描画処理(移動用・中心座標)
		DrawMoveCenterObject(device, stageStars[i]);
	}
}


//=============================================================================
// ゲームステージを取得
//=============================================================================
int GetGameStage(void)
{
	return gameStage;
}

//=============================================================================
// ゲームステージを取得
//=============================================================================
void SetGameStage(int stage)
{
	gameStage += stage;

	if (GetGameStage() > STARS_SUN)
	{
		SetStage(STAGE_RESULT);
	}
}