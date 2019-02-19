﻿/**
* @param DX.h
* @brief DX関係クラスのFacadeのヘッダ
* @author Harutaka-Tsujino
*/

#ifndef DX_H
#define DX_H

#include <windows.h>
#include <tchar.h>

#include <d3dx9.h>

#include "../Wnd/Data/RectSize.h"
#include "DX3D/DX3D.h"
#include "DXInput/DXInput.h"
#include "DX3D/CustomVertexEditor/Data/CustomVertex.h"
#include "DX3D/CustomVertexEditor/Data/ObjData.h"

/**
* @brief DX関係クラスのFacade
*/
class DX
{
public:
	DX(HWND hWnd, RectSize wndSize) :m_HWND(hWnd)
	{
		Create();

		m_pDX3D = new DX3D(m_HWND, wndSize, m_pD3D);

		m_pDXInput = new DXInput(m_HWND);
	}

	~DX()
	{
		delete m_pDX3D;
		delete m_pDXInput;
		m_pD3D->Release();
	}

	/**
	* @brief 描画の開始処理と入力状態の更新を行う,メッセージループの始まりで呼ぶ
	*/
	inline VOID PrepareMessageLoop() const
	{
		m_pDX3D->PrepareRendering();
		m_pDXInput->UpdataInputState();
	}

	/**
	* @brief 描画の終了処理と入力状態の保存を行う,メッセージループの終わりで呼ぶ
	*/
	inline VOID CleanUpMessageLoop() const
	{
		m_pDX3D->CleanUpRendering();
		m_pDXInput->StorePrevInputState();
	}

	inline VOID ToggleWndMode()								//使用時DX3DDevがロストする可能性がある
	{
		m_pDX3D->ToggleWndMode();
	}

	inline VOID DefaultBlendMode() const					//通常合成
	{
		m_pDX3D->DefaultBlendMode();
	}

	inline VOID AddtionBlendMode() const					//加算合成
	{
		m_pDX3D->AddtionBlendMode();
	}

	inline VOID DefaultColorBlending() const				//ウィンドウモードを切り替えた時には再設定する必要がある
	{
		m_pDX3D->DefaultColorBlending();
	}

	inline VOID SetLight(const D3DLIGHT9& rLight, DWORD index) const
	{
		m_pDX3D->SetLight(rLight, index);
	}

	inline VOID OnLight(DWORD index) const
	{
		m_pDX3D->OnLight(index);
	}

	inline VOID OffLight(DWORD index) const
	{
		m_pDX3D->OffLight(index);
	}

	inline VOID EnableLighting() const
	{
		m_pDX3D->EnableLighting();
	}

	inline VOID DisableLighting() const
	{
		m_pDX3D->DisableLighting();
	}

	inline VOID ChangeAmbientIntensity(DWORD aRGB) const
	{
		m_pDX3D->ChangeAmbientIntensity(aRGB);
	}

	inline VOID EnableSpecular() const
	{
		m_pDX3D->EnableSpecular();
	}

	inline VOID DisaableSpecular() const
	{
		m_pDX3D->DisaableSpecular();
	}

	inline VOID DefaultLighting() const						//ウィンドウモードを切り替えた時には再設定する必要がある
	{
		m_pDX3D->DefaultLighting();
	}

	inline VOID CreateTex(const TCHAR* pTexKey, const TCHAR* pTexPath)
	{
		m_pDX3D->CreateTex(pTexKey, pTexPath);
	}

	inline VOID ReleaseTex()
	{
		m_pDX3D->ReleaseTex();
	}

	inline VOID EraseTex(const TCHAR* pTexKey)
	{
		m_pDX3D->EraseTex(pTexKey);
	}

	inline const LPDIRECT3DTEXTURE9 GetTex(const TCHAR* pTexKey)
	{
		return m_pDX3D->GetTex(pTexKey);
	}

	inline const BOOL TexExists(const TCHAR* pTexKey)
	{
		return m_pDX3D->TexExists(pTexKey);
	}

	inline VOID GetCameraPos(D3DXVECTOR3* pCameraPos) const
	{
		m_pDX3D->GetCameraPos(pCameraPos);
	}

	inline VOID SetCameraPos(FLOAT x, FLOAT y, FLOAT z)
	{
		m_pDX3D->SetCameraPos(x, y, z);
	}

	inline VOID SetCameraPos(const D3DXVECTOR3& rCameraPos)
	{
		m_pDX3D->SetCameraPos(rCameraPos);
	}

	inline VOID GetCameraEyePt(D3DXVECTOR3* pEyePoint) const
	{
		m_pDX3D->GetCameraPos(pEyePoint);
	}

	inline VOID SetCameraEyePt(FLOAT x, FLOAT y, FLOAT z)
	{
		m_pDX3D->SetCameraEyePt(x, y, z);
	}

	inline VOID SetCameraEyePt(const D3DXVECTOR3& rEyePt)
	{
		m_pDX3D->SetCameraEyePt(rEyePt);
	}

	inline VOID GetView(D3DXMATRIX* pView) const
	{
		m_pDX3D->GetView(pView);
	}

	inline VOID GetProj(D3DXMATRIX* pProj) const
	{
		m_pDX3D->GetProj(pProj);
	}

	VOID SetCameraTransform()
	{
		m_pDX3D->SetCameraTransform();
	}

	inline VOID TransBillBoard(D3DXMATRIX* pWorld) const
	{
		m_pDX3D->TransBillBoard(pWorld);
	}

	inline D3DXVECTOR3 TransScreen(const D3DXVECTOR3& Pos) const
	{
		return m_pDX3D->TransScreen(Pos);
	}

	inline D3DXVECTOR3 TransWorld(const D3DXVECTOR3& Pos) const
	{
		return m_pDX3D->TransWorld(Pos);
	}

	inline VOID RotateRectXYZ(CustomVertex* pCustomVertices, const D3DXVECTOR3& rDeg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX3D->RotateRectXYZ(pCustomVertices, rDeg, rRelativeRotateCenter);
	}

	inline VOID RotateRectX(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX3D->RotateRectX(pCustomVertices, deg, rRelativeRotateCenter);
	}

	inline VOID RotateRectY(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX3D->RotateRectY(pCustomVertices, deg, rRelativeRotateCenter);
	}

	inline VOID RotateRectZ(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX3D->RotateRectZ(pCustomVertices, deg, rRelativeRotateCenter);
	}

	inline VOID RescaleRect(CustomVertex* pCustomVertices, const D3DXVECTOR2& rScaleRate) const
	{
		m_pDX3D->RescaleRect(pCustomVertices, rScaleRate);
	}

	inline VOID MoveRect(CustomVertex* pCustomVertices, const D3DXVECTOR3& rMovement) const
	{
		m_pDX3D->MoveRect(pCustomVertices, rMovement);
	}

	inline VOID LocaleRect(CustomVertex* pCustomVertices, const D3DXVECTOR3& rPos) const
	{
		m_pDX3D->LocaleRect(pCustomVertices, rPos);
	}

	inline VOID SetRectTexUV(CustomVertex* pCustomVertices,
		FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f) const
	{
		m_pDX3D->SetRectTexUV(pCustomVertices, startTU, startTV, endTU, endTV);
	}

	inline VOID SetRectARGB(CustomVertex *pCustomVertices, DWORD aRGB) const
	{
		m_pDX3D->SetRectARGB(pCustomVertices, aRGB);
	}

	inline VOID SetTopBottomARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pDX3D->SetTopBottomARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID SetLeftRightARGB(CustomVertex *pCustomVertices, DWORD leftARGB, DWORD rightARGB) const
	{
		m_pDX3D->SetLeftRightARGB(pCustomVertices, leftARGB, rightARGB);
	}

	inline VOID SetObliqueToBottomLeftARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pDX3D->SetObliqueToBottomLeftARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID SetObliqueToBottomRightARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pDX3D->SetObliqueToBottomRightARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID FlashRect(CustomVertex* pVertices, INT* pFrameCnt, INT flashFlameMax, BYTE alphaMax, BYTE alphaMin = 0)
	{
		m_pDX3D->FlashRect(pVertices, pFrameCnt, flashFlameMax, alphaMax, alphaMin);
	}

	inline VOID CreateRect(CustomVertex *pCustomVertices, const D3DXVECTOR3& rCenter, const D3DXVECTOR3& rHalfScale,
		DWORD aRGB = 0xFFFFFFFF, FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f) const
	{
		m_pDX3D->CreateRect(pCustomVertices, rCenter, rHalfScale, aRGB, startTU, startTV, endTU, endTV);
	}

	inline VOID CreateRect(CustomVertex *pCustomVertices, const ObjData& rObjData) const
	{
		m_pDX3D->CreateRect(pCustomVertices, rObjData);
	}

	inline VOID Render(const FbxRelated& rFBXModel, const D3DXMATRIX& rWorld, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pDX3D->Render(rFBXModel, rWorld, pTexture);
	}

	inline VOID Render(const CustomVertex* pCustomVertices, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pDX3D->Render(pCustomVertices, pTexture);
	}

	inline VOID Render(const Vertex3D* pVertex3D, const D3DXMATRIX& rWorld, const LPDIRECT3DTEXTURE9 pTexture = nullptr)
	{
		m_pDX3D->Render(pVertex3D, rWorld, pTexture);
	}

	inline VOID Render(const D3DXVECTOR2& topLeft, const TCHAR* pText, UINT format, LPD3DXFONT pFont, DWORD color)
	{
		m_pDX3D->Render(topLeft, pText, format, pFont, color);
	}

	inline VOID CreateAndRenderRect(const ObjData& rObjData, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pDX3D->CreateAndRenderRect(rObjData, pTexture);
	}

	inline VOID CreateFbx(const TCHAR* pKey, const CHAR* pFilePath)
	{
		m_pDX3D->CreateFbx(pKey, pFilePath);
	}

	inline FbxRelated& GetFbx(const TCHAR* pKey)
	{
		return m_pDX3D->GetFbx(pKey);
	}

	inline BOOL MouseIsPressed(INT key) const
	{
		return m_pDXInput->MouseIsPressed(key);
	}

	inline BOOL MouseIsHeld(INT key) const
	{
		return m_pDXInput->MouseIsHeld(key);
	}

	inline BOOL MouseIsReleased(INT key) const
	{
		return m_pDXInput->MouseIsReleased(key);
	}

	inline BOOL MouseIsNeutral(INT key) const
	{
		return m_pDXInput->MouseIsNeutral(key);
	}

	inline BOOL MouseAnyKeyIsPressed() const
	{
		return m_pDXInput->MouseAnyKeyIsPressed();
	}

	inline VOID CursorPos(POINT* pPos) const
	{
		m_pDXInput->CursorPos(pPos);
	}

	inline LONG MouseWheelScrollingFromPrev() const
	{
		return m_pDXInput->MouseWheelScrollingFromPrev();
	}

	inline BOOL KeyboardIsPressed(INT key) const
	{
		return m_pDXInput->KeyboardIsPressed(key);
	}

	inline BOOL KeyboardIsHeld(INT key) const
	{
		return m_pDXInput->KeyboardIsHeld(key);
	}

	inline BOOL KeyboardIsReleased(INT key) const
	{
		return m_pDXInput->KeyboardIsReleased(key);
	}

	inline BOOL KeyboardIsNeutral(INT key) const
	{
		return m_pDXInput->KeyboardIsNeutral(key);
	}

	inline BOOL KeyboardAnyKeyIsPressed() const
	{
		return m_pDXInput->KeyboardAnyKeyIsPressed();
	}

	inline VOID ReleaseFont()
	{
		m_pDX3D->ReleaseFont();
	}

	inline VOID EraseFont(const TCHAR* pFontKey)
	{
		m_pDX3D->EraseFont(pFontKey);
	}

	inline VOID CreateFont(const TCHAR* pKey, D3DXVECTOR2 scale, const TCHAR* pFontName, UINT thickness = 0)
	{
		m_pDX3D->CreateFont(pKey, scale, pFontName, thickness);
	}

	inline BOOL FontExists(const TCHAR* pKey)
	{
		return m_pDX3D->FontExists(pKey);
	}

	inline const LPD3DXFONT GetFont(const TCHAR* pKey)
	{
		return m_pDX3D->GetFont(pKey);
	}

private:
	VOID Create();	//他DX機能の基盤となるので初めに生成する

	const HWND m_HWND = nullptr;

	LPDIRECT3D9 m_pD3D = nullptr;

	DX3D* m_pDX3D = nullptr;

	DXInput* m_pDXInput = nullptr;
};

#endif //! DX_H
