﻿/**
* @file DX3D.h
* @brief 描画関係クラスのFacadeのヘッダ
* @author Harutaka-Tsujino
*/

#ifndef DX3D_H
#define DX3D_H

#include <windows.h>
#include <tchar.h>

#include <d3dx9.h>

#include "D3DPP/D3DPP.h"
#include "ColorBlender/ColorBlender.h"
#include "Light/Light.h"
#include "TexStorage/TexStorage.h"
#include "Camera/Camera.h"
#include "CustomVertexEditor/CustomVertexEditor.h"
#include "Renderer/Renderer.h"
#include "../../Wnd/Data/RectSize.h"
#include "CustomVertexEditor/Data/CustomVertex.h"
#include "CustomVertexEditor/Data/ObjData.h"
#include "FbxStorage/FbxStorage.h"
#include "FbxStorage/FbxRelated/FbxRelated.h"
#include "Font/Font.h"

/**
* @brief 描画関係クラスのFacade
*/
class DX3D
{
public:
	DX3D(HWND hWnd, RectSize wndSize, LPDIRECT3D9 pD3D);	//Create(LPDIRECT3D9) InitViewPort()を呼ぶ
	~DX3D()
	{
		delete m_pFbxStorage;
		delete m_pRenderer;
		delete m_pCustomVertex;
		delete m_pCamera;
		delete m_pTexStorage;
		delete m_pLight;
		delete m_pColorBlender;
		delete m_D3DPP;
		delete m_pFont;
		m_pDX3DDev->Release();
	}

	/**
	* @brief 描画の削除及び描画の開始宣言,メッセージループの始まりで呼ぶ
	*/
	inline VOID PrepareRendering() const
	{
		m_pDX3DDev->Clear(
					0,
					NULL,
					D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
					D3DCOLOR_XRGB(0, 0, 0),					//画面をクリアするときの色
					1.f,
					0);

		m_pDX3DDev->BeginScene();
	}

	/**
	* @brief 描画の終了宣言及びバックバッファの入れ替え,メッセージループの終わりで呼ぶ
	*/
	inline VOID CleanUpRendering() const
	{
		m_pDX3DDev->EndScene();
		m_pDX3DDev->Present(
					NULL,
					NULL,
					NULL,
					NULL);
	}
	
	/**
	* @brief ウィンドウモードの切替,3Dデバイスがロストする危険性がある
	*/
	VOID ToggleWndMode();

	inline VOID DefaultBlendMode() const					//通常合成
	{
		m_pColorBlender->DefaultBlendMode();
	}

	inline VOID AddtionBlendMode() const					//加算合成
	{
		m_pColorBlender->AddtionBlendMode();
	}

	inline VOID DefaultColorBlending() const				//ウィンドウモードを切り替えた時には再設定する必要がある
	{
		m_pColorBlender->DefaultColorBlending();
	}

	inline VOID SetLight(const D3DLIGHT9& rLight, DWORD index) const
	{
		m_pLight->SetLight(rLight, index);
	}

	inline VOID OnLight(DWORD index) const
	{
		m_pLight->OnLight(index);
	}

	inline VOID OffLight(DWORD index) const
	{
		m_pLight->OffLight(index);
	}

	inline VOID EnableLighting() const
	{
		m_pLight->EnableLighting();
	}

	inline VOID DisableLighting() const
	{
		m_pLight->DisableLighting();
	}

	inline VOID ChangeAmbientIntensity(DWORD aRGB) const
	{
		m_pLight->ChangeAmbientIntensity(aRGB);
	}

	inline VOID EnableSpecular() const
	{
		m_pLight->EnableSpecular();
	}

	inline VOID DisaableSpecular() const
	{
		m_pLight->DisaableSpecular();
	}

	inline VOID DefaultLighting() const						//ウィンドウモードを切り替えた時には再設定する必要がある
	{
		m_pLight->DefaultLighting();
	}

	inline VOID CreateTex(const TCHAR* pTexKey, const TCHAR* pTexPath)
	{
		m_pTexStorage->CreateTex(pTexKey, pTexPath);
	}

	inline VOID ReleaseTex()
	{
		m_pTexStorage->ReleaseTex();
	}

	inline VOID EraseTex(const TCHAR* pTexKey)
	{
		m_pTexStorage->EraseTex(pTexKey);
	}

	inline const LPDIRECT3DTEXTURE9 GetTex(const TCHAR* pTexKey)
	{
		return m_pTexStorage->GetTex(pTexKey);
	}

	inline const BOOL TexExists(const TCHAR* pTexKey)
	{
		return m_pTexStorage->Exists(pTexKey);
	}

	inline VOID GetCameraPos(D3DXVECTOR3* pCameraPos) const
	{
		m_pCamera->GetCameraPos(pCameraPos);
	}

	inline VOID SetCameraPos(FLOAT x, FLOAT y, FLOAT z)
	{
		m_pCamera->SetCameraPos(x, y, z);
	}

	inline VOID SetCameraPos(const D3DXVECTOR3& rCameraPos)
	{
		m_pCamera->SetCameraPos(rCameraPos);
	}

	inline VOID GetCameraEyePt(D3DXVECTOR3* pEyePoint) const
	{
		m_pCamera->GetCameraPos(pEyePoint);
	}

	inline VOID SetCameraEyePt(FLOAT x, FLOAT y, FLOAT z)
	{
		m_pCamera->SetEyePt(x, y, z);
	}

	inline VOID SetCameraEyePt(const D3DXVECTOR3& rEyePt)
	{
		m_pCamera->SetEyePt(rEyePt);
	}

	inline VOID GetView(D3DXMATRIX* pView) const
	{
		m_pCamera->GetView(pView);
	}

	inline VOID GetProj(D3DXMATRIX* pProj) const
	{
		m_pCamera->GetProj(pProj);
	}

	VOID SetCameraTransform()
	{
		m_pCamera->SetTransform();
	}

	inline VOID TransBillBoard(D3DXMATRIX* pWorld) const
	{
		m_pCamera->TransBillBoard(pWorld);
	}

	inline D3DXVECTOR3 TransScreen(const D3DXVECTOR3& Pos)
	{
		return m_pCamera->TransScreen(Pos);
	}

	inline D3DXVECTOR3 TransWorld(const D3DXVECTOR3& Pos)
	{
		return m_pCamera->TransWorld(Pos);
	}

	inline VOID RotateRectXYZ(CustomVertex* pCustomVertices, const D3DXVECTOR3& rDeg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pCustomVertex->RotateXYZ(pCustomVertices, rDeg, rRelativeRotateCenter);
	}

	inline VOID RotateRectX(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pCustomVertex->RotateX(pCustomVertices, deg, rRelativeRotateCenter);
	}

	inline VOID RotateRectY(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pCustomVertex->RotateY(pCustomVertices, deg, rRelativeRotateCenter);
	}

	inline VOID RotateRectZ(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pCustomVertex->RotateZ(pCustomVertices, deg, rRelativeRotateCenter);
	}

	inline VOID RescaleRect(CustomVertex* pCustomVertices, const D3DXVECTOR2& rScaleRate) const
	{
		m_pCustomVertex->Rescale(pCustomVertices, rScaleRate);
	}

	inline VOID MoveRect(CustomVertex* pCustomVertices, const D3DXVECTOR3& rMovement) const
	{
		m_pCustomVertex->Move(pCustomVertices, rMovement);
	}

	inline VOID LocaleRect(CustomVertex* pCustomVertices, const D3DXVECTOR3& rPos) const
	{
		m_pCustomVertex->Locale(pCustomVertices, rPos);
	}

	inline VOID SetRectTexUV(CustomVertex* pCustomVertices,
		FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f) const
	{
		m_pCustomVertex->SetTexUV(pCustomVertices, startTU, startTV, endTU, endTV);
	}

	inline VOID SetRectARGB(CustomVertex *pCustomVertices, DWORD aRGB) const
	{
		m_pCustomVertex->SetARGB(pCustomVertices, aRGB);
	}

	inline VOID SetTopBottomARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pCustomVertex->SetTopBottomARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID SetLeftRightARGB(CustomVertex *pCustomVertices, DWORD leftARGB, DWORD rightARGB) const
	{
		m_pCustomVertex->SetLeftRightARGB(pCustomVertices, leftARGB, rightARGB);
	}

	inline VOID SetObliqueToBottomRightARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pCustomVertex->SetObliqueToBottomRightARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID SetObliqueToBottomLeftARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pCustomVertex->SetObliqueToBottomLeftARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID FlashRect(CustomVertex* pVertices, INT* pFrameCnt, INT flashFlameMax, BYTE alphaMax, BYTE alphaMin = 0)
	{
		m_pCustomVertex->Flash(pVertices, pFrameCnt, flashFlameMax, alphaMax, alphaMin);
	}

	inline VOID CreateRect(CustomVertex *pCustomVertices, const D3DXVECTOR3& rCenter, const D3DXVECTOR3& rHalfScale,
		DWORD aRGB = 0xFFFFFFFF, FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f) const
	{
		m_pCustomVertex->Create(pCustomVertices, rCenter, rHalfScale, aRGB, startTU, startTV, endTU, endTV);
	}

	inline VOID CreateRect(CustomVertex *pCustomVertices,const ObjData& rObjData) const
	{
		m_pCustomVertex->Create(pCustomVertices, rObjData);
	}

	inline VOID Render(const FbxRelated& rFBXModel, const D3DXMATRIX& rWorld, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pRenderer->Render(rFBXModel, rWorld, pTexture);
	}

	inline VOID Render(const CustomVertex* pCustomVertices, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pRenderer->Render(pCustomVertices, pTexture);
	}

	inline VOID Render(const Vertex3D* pVertex3D, const D3DXMATRIX& rWorld, const LPDIRECT3DTEXTURE9 pTexture = nullptr)
	{
		m_pRenderer->Render(pVertex3D, rWorld, pTexture);
	}

	inline VOID Render(const D3DXVECTOR2& topLeft, const TCHAR* pText, UINT format, LPD3DXFONT pFont, DWORD color)
	{
		m_pRenderer->Render(topLeft, pText, format, pFont, color);
	}

	inline VOID CreateAndRenderRect(const ObjData& rObjData, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		CustomVertex vertices[CustomVertex::m_RECT_VERTICES_NUM];

		m_pCustomVertex->Create(vertices, rObjData);

		m_pRenderer->Render(vertices, pTexture);
	}

	inline VOID CreateFbx(const TCHAR* pKey, const CHAR* pFilePath)
	{
		m_pFbxStorage->CreateFbx(pKey, pFilePath);
	}

	inline FbxRelated& GetFbx(const TCHAR* pKey)
	{
		return m_pFbxStorage->GetFbx(pKey);
	}

	inline VOID ReleaseFont()
	{
		m_pFont->Release();
	}

	inline VOID EraseFont(const TCHAR* pFontKey)
	{
		m_pFont->Erase(pFontKey);
	}

	inline VOID CreateFont(const TCHAR* pKey, D3DXVECTOR2 scale, const TCHAR* pFontName, UINT thickness = 0)
	{
		m_pFont->Create(pKey, scale, pFontName, thickness);
	}

	inline BOOL FontExists(const TCHAR* pKey)
	{
		return m_pFont->Exists(pKey);
	}

	inline const LPD3DXFONT GetFont(const TCHAR* pKey)
	{
		return m_pFont->Get(pKey);
	}

private:
	VOID Create(LPDIRECT3D9 pD3D);							//先にDXクラスを生成しなければいけない

	VOID OnFailedChangeWndMode(HRESULT resetRetVal);		//先に引数をFAILEDマクロで調べた後呼ぶ 呼んだあとはreturnする

	inline VOID InitViewPort();								//描画する距離の初期化を行う

	const HWND m_HWND = nullptr;

	LPDIRECT3DDEVICE9 m_pDX3DDev = nullptr;

	D3DPP* m_D3DPP = nullptr;

	ColorBlender* m_pColorBlender = nullptr;

	Light* m_pLight = nullptr;

	TexStorage* m_pTexStorage = nullptr;

	Camera* m_pCamera = nullptr;

	CustomVertexEditor* m_pCustomVertex = nullptr;

	Renderer* m_pRenderer = nullptr;

	FbxStorage* m_pFbxStorage = nullptr;

	Font* m_pFont = nullptr;
};

#endif //! DX3D_H
