//=============================================================================
//
// ���_���� [basic.h]
// Author : �� �F��
//
//=============================================================================
#ifndef _BASIC_H_
#define _BASIC_H_

//*****************************************************************************
// �}�N����`
//*****************************************************************************
// �e�N�X�`���̏I������[Release]
#ifndef RELEASE_TEXTURE
#define RELEASE_TEXTURE(p)		{ if(p.texture) { (p.texture)->Release(); (p.texture)=nullptr; } }
#endif

// �萔
#define HALF				(2)
#define MAX_DEGIT			(10)

//*****************************************************************************
// �萔��`
//*****************************************************************************
// �Q�[�W�����p
enum GAUGE_DIRECTION
{
	GAUGE_UP,
	GAUGE_RIGHT
};

//*****************************************************************************
// �\���̐錾
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

typedef struct	// 3D�I�u�W�F�N�g�\����
{
	LPDIRECT3DTEXTURE9	Texture;	// �e�N�X�`���ւ̃|�C���^
	LPD3DXMESH			Mesh;		// ���b�V�����ւ̃|�C���^
	LPD3DXBUFFER		BuffMat;	// �}�e���A�����ւ̃|�C���^
	DWORD				NumMat;		// �}�e���A�����̐�
	D3DXMATRIX			mtxWorld;	// ���[���h�}�g���b�N�X

}OBJECT;

typedef struct	// Draw�Ɏg���\����
{
	D3DXMATRIX  mtxScl;
	D3DXMATRIX 	mtxRot;
	D3DXMATRIX	mtxTranslate;
	D3DXMATERIAL *pD3DXMat;
	D3DMATERIAL9 matDef;

}DRAW_TOOL;

//*****************************************************************************
// �v���g�^�C�v�錾(���_�t�H�[�}�b�g)
//*****************************************************************************
// ���_�t�H�[�}�b�g
HRESULT MakeVtx4PointData(TEXTURE *object);

// ���_�t�H�[�}�b�g(���S���W)
HRESULT MakeVtxCenterData(TEXTURE *object);

// ���_�t�H�[�}�b�g(�����e�N�X�`�����_���)
HRESULT MakeCutVtx4PointData
(TEXTURE *object, int PatternX, int PatternY, int cntPattern);

//*****************************************************************************
// �v���g�^�C�v�錾(���_���̐ݒ�)
//*****************************************************************************
// ���_���W�̐ݒ�(���_���)
void SetVtx4PointData
(TEXTURE *object);

// ���_���W�̐ݒ�(���S���W)
void SetVtxCenterData
(TEXTURE *object);

// ���_���W�̐ݒ�(��]�p)
void SetVtxRotData
(TEXTURE *object, float angle, float Length);

// �e�N�X�`�����W�̐ݒ�(�X�N���[���p)
void SetTextureScrollData
(TEXTURE *object, float distance);

// ���_���W�̐ݒ�(�Q�[�W�p)
void SetVtx4PointGaugeDate
(TEXTURE *object, float Length, int dir);

// �e�N�X�`�����W�̐ݒ�(�����X�N���[���p)
void SetTextureNumData
(TEXTURE *object, int number);

// �e�N�X�`�����W�̐ݒ�(�w�i�X�N���[���p)
void SetTextureScrollData
(TEXTURE *object, float distance);

// �e�N�X�`�����W�̐ݒ�(�A�j���[�V�����p)
void SetTextureAnimationData
(TEXTURE *object, int cntPattern, int PatternX, int PatternY);

// ���ˌ��̐ݒ�(�꒸�_����)
void SetSingleDiffuseData
(TEXTURE *object, int no);

// ���ˌ��̐ݒ�(�S���_)
void SetAllDiffuseData
(TEXTURE *object);

#endif