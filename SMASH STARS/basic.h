//=============================================================================
//
// 頂点処理 [basic.h]
// Author : 蔡 友剛
//
//=============================================================================
#ifndef _BASIC_H_
#define _BASIC_H_

//*****************************************************************************
// マクロ定義
//*****************************************************************************
// テクスチャの終了処理[Release]
#ifndef RELEASE_TEXTURE
#define RELEASE_TEXTURE(p)		{ if(p.texture) { (p.texture)->Release(); (p.texture)=nullptr; } }
#endif

// 定数
#define HALF				(2)
#define MAX_DEGIT			(10)

//*****************************************************************************
// 定数定義
//*****************************************************************************
// ゲージ方向用
enum GAUGE_DIRECTION
{
	GAUGE_UP,
	GAUGE_RIGHT
};

//*****************************************************************************
// 構造体宣言
//*****************************************************************************
typedef struct
{
	LPDIRECT3DTEXTURE9	texture;
	VERTEX_2D			vertexWk[NUM_VERTEX];
	D3DXVECTOR3			pos;
	D3DXVECTOR3			rot;
	D3DXVECTOR2			size;
	D3DXCOLOR			col;

}TEXTURE;

typedef struct	// 3Dオブジェクト構造体
{
	LPDIRECT3DTEXTURE9	Texture;	// テクスチャへのポインタ
	LPD3DXMESH			Mesh;		// メッシュ情報へのポインタ
	LPD3DXBUFFER		BuffMat;	// マテリアル情報へのポインタ
	DWORD				NumMat;		// マテリアル情報の数
	D3DXMATRIX			mtxWorld;	// ワールドマトリックス

}OBJECT;

typedef struct	// Drawに使う構造体
{
	D3DXMATRIX  mtxScl;
	D3DXMATRIX 	mtxRot;
	D3DXMATRIX	mtxTranslate;
	D3DXMATERIAL *pD3DXMat;
	D3DMATERIAL9 matDef;

}DRAW_TOOL;

//*****************************************************************************
// プロトタイプ宣言(頂点フォーマット)
//*****************************************************************************
// 頂点フォーマット
HRESULT MakeVtx4PointData(TEXTURE *object);

// 頂点フォーマット(中心座標)
HRESULT MakeVtxCenterData(TEXTURE *object);

// 頂点フォーマット(分割テクスチャ頂点情報)
HRESULT MakeCutVtx4PointData
(TEXTURE *object, int PatternX, int PatternY, int cntPattern);

//*****************************************************************************
// プロトタイプ宣言(頂点情報の設定)
//*****************************************************************************
// 頂点座標の設定(頂点情報)
void SetVtx4PointData
(TEXTURE *object);

// 頂点座標の設定(中心座標)
void SetVtxCenterData
(TEXTURE *object);

// 頂点座標の設定(回転用)
void SetVtxRotData
(TEXTURE *object, float angle, float Length);

// テクスチャ座標の設定(スクロール用)
void SetTextureScrollData
(TEXTURE *object, float distance);

// 頂点座標の設定(ゲージ用)
void SetVtx4PointGaugeDate
(TEXTURE *object, float Length, int dir);

// テクスチャ座標の設定(数字スクロール用)
void SetTextureNumData
(TEXTURE *object, int number);

// テクスチャ座標の設定(背景スクロール用)
void SetTextureScrollData
(TEXTURE *object, float distance);

// テクスチャ座標の設定(アニメーション用)
void SetTextureAnimationData
(TEXTURE *object, int cntPattern, int PatternX, int PatternY);

// 反射光の設定(一頂点ずつ)
void SetSingleDiffuseData
(TEXTURE *object, int no);

// 反射光の設定(全頂点)
void SetAllDiffuseData
(TEXTURE *object);

#endif