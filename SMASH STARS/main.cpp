//=============================================================================
// < SMASH STARS >
// Main���� [main.cpp]
// Author : �� �F��
//
//=============================================================================
#include "main.h"
#include "input.h"
#include "sound.h"
#include "titleManager.h"
#include "stageManager.h"
#include "gameOver.h"
#include "shop.h"
#include "stars.h"
#include "gameClear.h"
#include "stageBar.h"
#include "coin.h"
#include <time.h>

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define CLASS_NAME		_T("AppClass")			// �E�C���h�E�̃N���X��
#define WINDOW_NAME		_T("SMASH STARS")		// �E�C���h�E�̃L���v�V������

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HRESULT Init(HWND hWnd, BOOL bWindow);
void Uninit(void);
void Update(HWND hWnd);
void Draw(HWND hWnd);

void ReInitGame(void);

#ifdef _DEBUG
// �f�o�b�O�\������
void DrawDebugFont(HWND hWnd);

// �f�o�b�N�p�X�e�[�^�X�J��
void SetDebugStage(void);
#endif

//*****************************************************************************
// �O���[�o���ϐ�:
//*****************************************************************************
LPDIRECT3D9				D3D = NULL;				// Direct3D�I�u�W�F�N�g
LPDIRECT3DDEVICE9		D3DDevice = NULL;		// Device�I�u�W�F�N�g(�`��ɕK�v)

#ifdef _DEBUG
LPD3DXFONT				D3DXFont = NULL;		// �t�H���g�ւ̃|�C���^
int						CountFPS;				// FPS�J�E���^
#endif

int						Stage = STAGE_TITLE;	// �X�e�[�W�ԍ�

//=============================================================================
// ���C���֐�
//=============================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);	// �����Ă��ǂ����ǁA�x�����o��i���g�p�錾�j
	UNREFERENCED_PARAMETER(lpCmdLine);		// �����Ă��ǂ����ǁA�x�����o��i���g�p�錾�j

	// ���Ԍv���p
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;
	
	WNDCLASSEX	wcex = {
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW+1),
		NULL,
		CLASS_NAME,
		NULL
	};
	HWND		hWnd;
	MSG			msg;
	
	// �E�B���h�E�N���X�̓o�^
	RegisterClassEx(&wcex);

	// �E�B���h�E�̍쐬
	hWnd = CreateWindow(CLASS_NAME,
						WINDOW_NAME,
						WS_OVERLAPPEDWINDOW,
						100,																		// �E�B���h�E�̍����W
						100,																		// �E�B���h�E�̏���W
						SCREEN_WIDTH + GetSystemMetrics(SM_CXDLGFRAME)*2,									// �E�B���h�E����
						SCREEN_HEIGHT + GetSystemMetrics(SM_CXDLGFRAME)*2+GetSystemMetrics(SM_CYCAPTION),	// �E�B���h�E�c��
						NULL,
						NULL,
						hInstance,
						NULL);

	// DirectX�̏�����(�E�B���h�E���쐬���Ă���s��)
	if(FAILED(Init(hWnd, true)))
	{
		return -1;
	}

	// ���͏����̏�����
	InitInput(hInstance, hWnd);

	// �t���[���J�E���g������
	timeBeginPeriod(1);	// ����\��ݒ�
	dwExecLastTime = dwFPSLastTime = timeGetTime();	// �V�X�e���������~���b�P�ʂŎ擾
	dwCurrentTime = dwFrameCount = 0;
	
	// �E�C���h�E�̕\��(Init()�̌�ɌĂ΂Ȃ��Ƒʖ�)
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	
	// ���b�Z�[�W���[�v
	while(1)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
			{// PostQuitMessage()���Ă΂ꂽ�烋�[�v�I��
				break;
			}
			else
			{
				// ���b�Z�[�W�̖|��ƃf�B�X�p�b�`
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();					// �V�X�e���������擾

			if ((dwCurrentTime - dwFPSLastTime) >= 500)	// 0.5�b���ƂɎ��s
			{
#ifdef _DEBUG
				CountFPS = (dwFrameCount * 1000) / (dwCurrentTime - dwFPSLastTime);	// FPS�𑪒�
#endif
				dwFPSLastTime = dwCurrentTime;				// FPS�𑪒肵��������ۑ�
				dwFrameCount = 0;							// �J�E���g���N���A
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))	// 1/60�b���ƂɎ��s
			{
				dwExecLastTime = dwCurrentTime;	// ��������������ۑ�

				Update(hWnd);		// �X�V����
				Draw(hWnd);				// �`�揈��
				
				dwFrameCount++;		// �����񐔂̃J�E���g�����Z
			}
		}
	}
	
	// �E�B���h�E�N���X�̓o�^������
	UnregisterClass(CLASS_NAME, wcex.hInstance);

	// �I������
	Uninit();

	return (int)msg.wParam;
}

//=============================================================================
// �v���V�[�W��
//=============================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch( message )
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_ESCAPE:					// [ESC]�L�[�������ꂽ
			DestroyWindow(hWnd);		// �E�B���h�E��j������悤�w������
			break;
		}
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

//=============================================================================
// ����������
//=============================================================================
HRESULT Init(HWND hWnd, BOOL bWindow)
{
	D3DPRESENT_PARAMETERS d3dpp;
	D3DDISPLAYMODE d3ddm;

	srand((unsigned)time(NULL));

	// Direct3D�I�u�W�F�N�g�̍쐬
	D3D = Direct3DCreate9(D3D_SDK_VERSION);
	if(D3D == NULL)
	{
		return E_FAIL;
	}

	// ���݂̃f�B�X�v���C���[�h���擾
	if(FAILED(D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// �f�o�C�X�̃v���[���e�[�V�����p�����[�^�̐ݒ�
	ZeroMemory(&d3dpp, sizeof(d3dpp));							// ���[�N���[���N���A
	d3dpp.BackBufferCount			= 1;						// �o�b�N�o�b�t�@�̐�
	d3dpp.BackBufferWidth			= SCREEN_WIDTH;				// �Q�[����ʃT�C�Y(��)
	d3dpp.BackBufferHeight			= SCREEN_HEIGHT;			// �Q�[����ʃT�C�Y(����)
	d3dpp.BackBufferFormat			= D3DFMT_UNKNOWN;			// �o�b�N�o�b�t�@�̃t�H�[�}�b�g�͌��ݐݒ肳��Ă�����̂��g��
	d3dpp.SwapEffect				= D3DSWAPEFFECT_DISCARD;	// �f���M���ɓ������ăt���b�v����
	d3dpp.Windowed					= bWindow;					// �E�B���h�E���[�h
	d3dpp.EnableAutoDepthStencil	= TRUE;						// �f�v�X�o�b�t�@�i�y�o�b�t�@�j�ƃX�e���V���o�b�t�@���쐬
	d3dpp.AutoDepthStencilFormat	= D3DFMT_D16;				// �f�v�X�o�b�t�@�Ƃ���16bit���g��
	d3dpp.BackBufferFormat			= d3ddm.Format;				// �J���[���[�h�̎w��

	if(bWindow)
	{// �E�B���h�E���[�h
		d3dpp.BackBufferFormat           = D3DFMT_UNKNOWN;					// �o�b�N�o�b�t�@
		d3dpp.FullScreen_RefreshRateInHz = 0;								// ���t���b�V�����[�g
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;	// �C���^�[�o��
	}
	else
	{// �t���X�N���[�����[�h
		d3dpp.BackBufferFormat           = D3DFMT_R5G6B5;					// �o�b�N�o�b�t�@
		d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;			// ���t���b�V�����[�g
		d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_DEFAULT;		// �C���^�[�o��
	}

	// �f�o�C�X�̐���
	// �f�B�X�v���C�A�_�v�^��\�����߂̃f�o�C�X���쐬
	// �`��ƒ��_�������n�[�h�E�F�A�ōs�Ȃ�
	if(FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT,							// �f�B�X�v���C�A�_�v�^
									D3DDEVTYPE_HAL,								// �f�B�X�v���C�^�C�v
									hWnd,										// �t�H�[�J�X����E�C���h�E�ւ̃n���h��
									D3DCREATE_HARDWARE_VERTEXPROCESSING,		// �f�o�C�X�쐬����̑g�ݍ��킹
									&d3dpp,										// �f�o�C�X�̃v���[���e�[�V�����p�����[�^
									&D3DDevice)))							// �f�o�C�X�C���^�[�t�F�[�X�ւ̃|�C���^
	{
		// ��L�̐ݒ肪���s������
		// �`����n�[�h�E�F�A�ōs���A���_������CPU�ōs�Ȃ�
		if(FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, 
										D3DDEVTYPE_HAL, 
										hWnd, 
										D3DCREATE_SOFTWARE_VERTEXPROCESSING, 
										&d3dpp,
										&D3DDevice)))
		{
			// ��L�̐ݒ肪���s������
			// �`��ƒ��_������CPU�ōs�Ȃ�
			if(FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, 
											D3DDEVTYPE_REF,
											hWnd, 
											D3DCREATE_SOFTWARE_VERTEXPROCESSING, 
											&d3dpp,
											&D3DDevice)))
			{
				// ���������s
				return E_FAIL;
			}
		}
	}

	// �����_�����O�X�e�[�g�p�����[�^�̐ݒ�
	D3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				// �J�����O���s��Ȃ�
	D3DDevice->SetRenderState(D3DRS_ZENABLE, TRUE);						// Z�o�b�t�@���g�p
	D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				// ���u�����h���s��
	D3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
	D3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	// ���f�X�e�B�l�[�V�����J���[�̎w��

	// �T���v���[�X�e�[�g�p�����[�^�̐ݒ�
	D3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);	// �e�N�X�`���t�l�̌J��Ԃ��ݒ�
	D3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);	// �e�N�X�`���u�l�̌J��Ԃ��ݒ�
	D3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	// �e�N�X�`���g�厞�̕�Ԑݒ�
	D3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);	// �e�N�X�`���k�����̕�Ԑݒ�

#ifdef _DEBUG
																			// ���\���p�t�H���g��ݒ�
	D3DXCreateFont(D3DDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Terminal"), &D3DXFont);
#endif
	
	{// ������
		// �T�E���h
		InitSound(hWnd);

		// �^�C�g���̃}�l�[�W���[
		InitTitleManager(INIT_FIRST);

		// �X�e�[�W�̃}�l�[�W���[
		InitStageManager(INIT_FIRST);

		// ���X
		InitShop(INIT_FIRST);

		// �Q�[���I�[�o�[
		InitGameOver(INIT_FIRST);

		// �Q�[���N���A
		InitGameClear(INIT_FIRST);
	}

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void Uninit(void)
{
	// ���͏����̏I������
	UninitInput();

	if (D3DDevice != NULL)
	{// �f�o�C�X�̊J��
		D3DDevice->Release();
	}

	if (D3D != NULL)
	{// Direct3D�I�u�W�F�N�g�̊J��
		D3D->Release();
	}
	// �T�E���h
	UninitSound();

	// �^�C�g���̃}�l�[�W���[
	UninitTitleManager();

	// �X�e�[�W�̃}�l�[�W���[
	UninitStageManager();

	// ���X
	UninitShop();

	// �Q�[���I�[�o�[
	UninitGameOver();

	// �Q�[���N���A
	UninitGameClear();
}

//=============================================================================
// �X�V����
//=============================================================================
void Update(HWND hWnd)
{
	// ���͂̍X�V����
	UpdateInput();
	
	// �X�e�[�W�ɕ���
	switch (Stage)
	{
	case STAGE_TITLE:
		// �^�C�g���̃}�l�[�W���[
		UpdateTitleManager();
		break;
	case STAGE_GAME:
		// �X�e�[�W�̃}�l�[�W���[
		UpdateStageManager(hWnd);
		break;
	case STAGE_GAME_OVER:
		// �Q�[���I�[�o�[
		UpdateGameOver();
		break;
	case STAGE_SHOP:
		// ���X
		UpdateShop(hWnd);

		// �R�C���̃G�t�F�N�g
		UpdateCoin();
		break;
	case STAGE_CLEAR:
		// �Q�[���N���A
		UpdateGameClear();
		break;
	default:
		break;
	}

#ifdef _DEBUG
	// �f�o�b�N�p�X�e�[�^�X�J��
	SetDebugStage();
#endif

}

//=============================================================================
// �`�揈��
//=============================================================================
void Draw(HWND hWnd)
{
	// �o�b�N�o�b�t�@���y�o�b�t�@�̃N���A
	D3DDevice->Clear(0, NULL, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER), D3DCOLOR_RGBA(128, 128, 255, 0), 1.0f, 0);

	// Direct3D�ɂ��`��̊J�n
	if(SUCCEEDED(D3DDevice->BeginScene()))
	{
		// �X�e�[�W�ɕ���
		switch (Stage)
		{
		case STAGE_TITLE:
			// �^�C�g���̃}�l�[�W���[
			DrawTitleManager();
			break;
		case STAGE_GAME:
			// �X�e�[�W�̃}�l�[�W���[
			DrawStageManager();
			break;
		case STAGE_GAME_OVER:
			// �X�e�[�W�̃}�l�[�W���[
			DrawStageManager();

			// �Q�[���I�[�o�[
			DrawGameOver();
			break;
		case STAGE_SHOP:
			// �X�e�[�W�̃}�l�[�W���[
			DrawStageManager();

			// ���X
			DrawShop();
			break;
		case STAGE_CLEAR:
			// �Q�[���N���A
			DrawGameClear();
			break;
		default:
			break;
		}

#ifdef _DEBUG
		// �f�o�b�O�\��
		DrawDebugFont(hWnd);
#endif
		
		// Direct3D�ɂ��`��̏I��
		D3DDevice->EndScene();
	}

	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�̓���ւ�
	D3DDevice->Present(NULL, NULL, NULL, NULL);
}

//=============================================================================
// �f�o�C�X�擾�֐�
//=============================================================================
LPDIRECT3DDEVICE9 GetDevice(void)
{
	return D3DDevice;
}

#ifdef _DEBUG
//=============================================================================
// �f�o�b�O�\������
//=============================================================================
void DrawDebugFont(HWND hWnd)
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	STARS stars = *GetStars(GetGameStage());

	char str[256];

	// �e�L�X�g�`��
	sprintf(str, _T("FPS:%d"), CountFPS);
	D3DXFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

	// �X�e�[�W
	rect.top += 20;
	sprintf(str, _T("stage:%d"), Stage);
	D3DXFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

	// ��
	rect.top += 20;
	sprintf(str, _T("Game Stage:%d"), GetGameStage());
	D3DXFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

	// ��
	rect.top += 20;
	sprintf(str, _T("HP:%d"), stars.HP);
	D3DXFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

	// �}�E�X���W
	rect.top += 20;
	sprintf(str, _T("mouse pos:%f %f %f"), GetMousePos(hWnd).x, GetMousePos(hWnd).y, GetMousePos(hWnd).z);
	D3DXFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));
}
#endif

//=============================================================================
// ��ʑJ��
//=============================================================================
void SetStage( int stage )
{
	// �X�e�[�W�J��
	Stage = stage;
}

//=============================================================================
// �Q�[���̍ď�������������
// �߂�l�F����
//=============================================================================
void ReInitGame(void)
{
	{// �ď�����	 
		// �^�C�g���̃}�l�[�W���[
		InitTitleManager(INIT_RE);

		// �X�e�[�W�̃}�l�[�W���[
		InitStageManager(INIT_RE);

		// ���X(�I������)
		UninitShop();

		// ���X
		InitShop(INIT_FIRST);

		// �Q�[���I�[�o�[
		InitGameOver(INIT_RE);

		// �Q�[���N���A
		InitGameClear(INIT_RE);
	}
}

#ifdef _DEBUG
//=============================================================================
// �f�o�b�N�p�X�e�[�^�X�J��
//=============================================================================
void SetDebugStage(void)
{
	// "-" �L�[��������
	if (GetKeyboardTrigger(DIK_MINUS))
	{
		// �X�e�[�W�J��
		Stage--;

		// �I�[�o�[�h�~
		if (Stage < STAGE_TITLE)
		{
			// �I�[�o�[�h�~
			Stage = STAGE_TITLE;

			// �ď�����
			ReInitGame();
		}
	}

	// "=" �L�[��������
	else if (GetKeyboardTrigger(DIK_EQUALS))
	{
		// �X�e�[�W�J��
		Stage++;

		// �I�[�o�[�h�~
		if (Stage > STAGE_RESULT)
		{
			// �^�C�g���ɖ߂�
			Stage = STAGE_TITLE;

			// �ď�����
			ReInitGame();
		}
	}
}
#endif
