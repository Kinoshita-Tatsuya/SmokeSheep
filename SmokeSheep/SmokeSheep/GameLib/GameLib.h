﻿/**
* @file GameLib.h
* @brief 汎用クラスのFacadeのヘッダ
* @author Harutaka-Tsujino
*/

#ifndef GAME_LIB_H
#define GAME_LIB_H

#include <Windows.h>
#include <tchar.h>

#include <d3dx9.h>

#include "../Class/Singleton/Singleton.h"
#include "Wnd\Wnd.h"
#include "DX\DX.h"
#include "DX\DX3D\CustomVertexEditor\Data\CustomVertex.h"
#include "DX\DX3D\CustomVertexEditor\Data\ObjData.h"
#include "Timer\Timer.h"
#include "Collision\Collision.h"
#include "3DBoard\3DBoard.h"
#include "Sound\Sound.h"
#include "JoyconManager\JoyconManager.h"

template<typename T>
VOID SafeRelease(T** ppType)
{
	delete (*ppType);
	*ppType = nullptr;
}

/**
* @brief 汎用クラスのFacade,ウィンドウ生成やDX関係の初期化も行う
*/
class GameLib :public Singleton<GameLib>
{
public:
	friend class Singleton<GameLib>;

	~GameLib()
	{
		delete m_pSound;
		delete m_pBoard3D;
		delete m_pCollision;
		delete m_pTimer;
		delete m_pDX;
		delete m_pWnd;
		delete m_pJoyconManager;
	}

	/**
	* @brief ウィンドウを生成しDX関係を初期化する,一番初めにこれを呼ぶ
	* @param hInst インスタンスのハンドル
	* @param pAppName アプリケーションの名前のポインタ
	*/
	inline static VOID Create(const HINSTANCE hInst, const TCHAR* pAppName)
	{
		if (!m_pWnd)			m_pWnd = new Wnd(hInst, pAppName);
		if (!m_pDX)				m_pDX = new DX(m_pWnd->GetHWND(), m_pWnd->GetWndSize());
		if (!m_pTimer)			m_pTimer = new Timer();
		if (!m_pCollision)		m_pCollision = new Collision();
		if (!m_pSound)			m_pSound = new Sound();
		if (!m_pBoard3D)		m_pBoard3D = new Board3D();
		if (!m_pJoyconManager)	m_pJoyconManager = new JoyconManager();

		GetInstance();
	}

	/**
	* @brief メッセージループを作成し引数で与えられた関数を60fpsで回す
	* @param メッセージループで回す関数のポインタ
	*/
	VOID RunFunc(VOID(*pMainFunc)());

	/**
	* @brief クライアント領域をm_WND_SIZEと同じにする
	*/
	inline VOID ResizeWnd() const
	{
		m_pWnd->ResizeWnd();
	}

	inline RectSize GetWndSize() const
	{
		return m_pWnd->GetWndSize();
	}

	inline VOID ToggleWndMode()								//使用時DX3DDevがロストする可能性がある
	{
		m_pDX->ToggleWndMode();
	}

	inline VOID DefaultBlendMode() const					//通常合成
	{
		m_pDX->DefaultBlendMode();
	}

	inline VOID AddtionBlendMode() const					//加算合成
	{
		m_pDX->AddtionBlendMode();
	}

	inline VOID DefaultColorBlending() const				//ウィンドウモードを切り替えた時には再設定する必要がある
	{
		m_pDX->DefaultColorBlending();
	}

	inline VOID SetLight(const D3DLIGHT9& rLight, DWORD index) const
	{
		m_pDX->SetLight(rLight, index);
	}

	inline VOID OnLight(DWORD index) const
	{
		m_pDX->OnLight(index);
	}

	inline VOID OffLight(DWORD index) const
	{
		m_pDX->OffLight(index);
	}

	inline VOID EnableLighting() const
	{
		m_pDX->EnableLighting();
	}

	inline VOID DisableLighting() const
	{
		m_pDX->DisableLighting();
	}

	inline VOID ChangeAmbientIntensity(DWORD aRGB) const
	{
		m_pDX->ChangeAmbientIntensity(aRGB);
	}

	inline VOID EnableSpecular() const
	{
		m_pDX->EnableSpecular();
	}

	inline VOID DisaableSpecular() const
	{
		m_pDX->DisaableSpecular();
	}

	inline VOID DefaultLighting() const						//ウィンドウモードを切り替えた時には再設定する必要がある
	{
		m_pDX->DefaultLighting();
	}

	inline VOID CreateTex(const TCHAR* pTexKey, const TCHAR* pTexPath)
	{
		m_pDX->CreateTex(pTexKey, pTexPath);
	}

	inline VOID ReleaseTex()
	{
		m_pDX->ReleaseTex();
	}

	inline VOID EraseTex(const TCHAR* pTexKey)
	{
		m_pDX->EraseTex(pTexKey);
	}

	inline const LPDIRECT3DTEXTURE9 GetTex(const TCHAR* pTexKey)
	{
		return m_pDX->GetTex(pTexKey);
	}

	inline const BOOL TexExists(const TCHAR* pTexKey)
	{
		return m_pDX->TexExists(pTexKey);
	}

	inline VOID GetCameraPos(D3DXVECTOR3* pCameraPos) const
	{
		m_pDX->GetCameraPos(pCameraPos);
	}

	inline VOID SetCameraPos(FLOAT x, FLOAT y, FLOAT z)
	{
		m_pDX->SetCameraPos(x, y, z);
	}

	inline VOID SetCameraPos(const D3DXVECTOR3& rCameraPos)
	{
		m_pDX->SetCameraPos(rCameraPos);
	}
	
	inline VOID GetCameraEyePt(D3DXVECTOR3* pEyePoint) const
	{
		m_pDX->GetCameraPos(pEyePoint);
	}
	
	inline VOID SetCameraEyePt(FLOAT x, FLOAT y, FLOAT z)
	{
		m_pDX->SetCameraEyePt(x, y, z);
	}
	
	inline VOID SetCameraEyePt(const D3DXVECTOR3& rEyePt)
	{
		m_pDX->SetCameraEyePt(rEyePt);
	}
	
	inline VOID GetView(D3DXMATRIX* pView) const
	{
		m_pDX->GetView(pView);
	}
	
	inline VOID GetProj(D3DXMATRIX* pProj) const
	{
		m_pDX->GetProj(pProj);
	}
	
	VOID SetCameraTransform()
	{
		m_pDX->SetCameraTransform();
	}
	
	inline VOID TransBillBoard(D3DXMATRIX* pWorld) const
	{
		m_pDX->TransBillBoard(pWorld);
	}
	
	inline D3DXVECTOR3 TransScreen(const D3DXVECTOR3& Pos) const
	{
		return m_pDX->TransScreen(Pos);
	}

	inline D3DXVECTOR3 TransWorld(const D3DXVECTOR3& Pos) const
	{
		return m_pDX->TransWorld(Pos);
	}

	inline VOID RotateRectXYZ(CustomVertex* pCustomVertices, const D3DXVECTOR3& rDeg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX->RotateRectXYZ(pCustomVertices, rDeg, rRelativeRotateCenter);
	}
	
	inline VOID RotateRectX(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX->RotateRectX(pCustomVertices, deg, rRelativeRotateCenter);
	}
	
	inline VOID RotateRectY(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX->RotateRectY(pCustomVertices, deg, rRelativeRotateCenter);
	}
	
	inline VOID RotateRectZ(CustomVertex* pCustomVertices, FLOAT deg, const D3DXVECTOR3& rRelativeRotateCenter) const
	{
		m_pDX->RotateRectZ(pCustomVertices, deg, rRelativeRotateCenter);
	}
	
	inline VOID RescaleRect(CustomVertex* pCustomVertices, const D3DXVECTOR2& rScaleRate) const
	{
		m_pDX->RescaleRect(pCustomVertices, rScaleRate);
	}
	
	inline VOID MoveRect(CustomVertex* pCustomVertices, const D3DXVECTOR3& rMovement) const
	{
		m_pDX->MoveRect(pCustomVertices, rMovement);
	}
	
	inline VOID LocaleRect(CustomVertex* pCustomVertices, const D3DXVECTOR3& rPos) const
	{
		m_pDX->LocaleRect(pCustomVertices, rPos);
	}
	
	inline VOID SetRectTexUV(CustomVertex* pCustomVertices,
		FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f) const
	{
		m_pDX->SetRectTexUV(pCustomVertices, startTU, startTV, endTU, endTV);
	}
	
	inline VOID SetRectARGB(CustomVertex *pCustomVertices, DWORD aRGB) const
	{
		m_pDX->SetRectARGB(pCustomVertices, aRGB);
	}

	inline VOID SetTopBottomARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pDX->SetTopBottomARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID SetLeftRightARGB(CustomVertex *pCustomVertices, DWORD leftARGB, DWORD rightARGB) const
	{
		m_pDX->SetLeftRightARGB(pCustomVertices, leftARGB, rightARGB);
	}
	
	inline VOID SetObliqueToBottomRightARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pDX->SetObliqueToBottomRightARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID SetObliqueToBottomLeftARGB(CustomVertex *pCustomVertices, DWORD topARGB, DWORD bottomARGB) const
	{
		m_pDX->SetObliqueToBottomLeftARGB(pCustomVertices, topARGB, bottomARGB);
	}

	inline VOID FlashRect(CustomVertex* pVertices, INT* pFrameCnt, INT flashFlameMax, BYTE alphaMax, BYTE alphaMin = 0)
	{
		m_pDX->FlashRect(pVertices, pFrameCnt, flashFlameMax, alphaMax, alphaMin);
	}

	inline VOID CreateRect(CustomVertex *pCustomVertices, const D3DXVECTOR3& rCenter, const D3DXVECTOR3& rHalfScale,
		DWORD aRGB = 0xFFFFFFFF, FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f) const
	{
		m_pDX->CreateRect(pCustomVertices, rCenter, rHalfScale, aRGB, startTU, startTV, endTU, endTV);
	}
	
	inline VOID CreateRect(CustomVertex *pCustomVertices, const ObjData& rObjData) const
	{
		m_pDX->CreateRect(pCustomVertices, rObjData);
	}
	
	inline VOID CreateRect(Vertex3D* p3DVertices, const D3DXVECTOR3& rHalfScale, const D3DXVECTOR3& rCenter,
		DWORD aRGB = 0xFFFFFFFF, FLOAT startTU = 0.0f, FLOAT startTV = 0.0f, FLOAT endTU = 1.0f, FLOAT endTV = 1.0f)
	{
		m_pBoard3D->CreateRect(p3DVertices, rHalfScale, rCenter, aRGB, startTU, startTV, endTU, endTV);
	}

	inline VOID CreateRect(Vertex3D* p3DVertices, const ObjData& rObjData)
	{
		m_pBoard3D->CreateRect(p3DVertices, rObjData);
	}

	inline VOID Render(const FbxRelated& rFBXModel, const D3DXMATRIX& rWorld, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pDX->Render(rFBXModel, rWorld, pTexture);
	}

	inline VOID Render(const CustomVertex* pCustomVertices, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pDX->Render(pCustomVertices, pTexture);
	}

	inline VOID Render(const Vertex3D* pVertex3D, const D3DXMATRIX& rWorld, const LPDIRECT3DTEXTURE9 pTexture = nullptr)
	{
		m_pDX->Render(pVertex3D, rWorld, pTexture);
	}

	inline VOID Render(const D3DXVECTOR2& topLeft, const TCHAR* pText, UINT format, LPD3DXFONT pFont, DWORD color = 0xFFFFFFFF)
	{
		m_pDX->Render(topLeft, pText, format, pFont, color);
	}

	inline VOID CreateAndRenderRect(const ObjData& rObjData, const LPDIRECT3DTEXTURE9 pTexture = nullptr) const
	{
		m_pDX->CreateAndRenderRect(rObjData, pTexture);
	}

	inline VOID CreateFbx(const TCHAR* pKey, const CHAR* pFilePath)
	{
		m_pDX->CreateFbx(pKey, pFilePath);
	}

	inline FbxRelated& GetFbx(const TCHAR* pKey)
	{
		return m_pDX->GetFbx(pKey);
	}

	inline VOID SetStartTime()
	{
		m_pTimer->Start();
	}

	inline VOID SetEndTime()
	{
		m_pTimer->End();
	}

	inline VOID ResetTime()
	{
		m_pTimer->Reset();
	}

	inline VOID StopTime()
	{
		m_pTimer->Stop();
	}

	inline VOID RestartTime()
	{
		m_pTimer->Restart();
	}

	inline LONGLONG GetSecond()
	{
		return m_pTimer->GetSecond();
	}

	inline LONGLONG GetMilliSecond()
	{
		return m_pTimer->GetMilliSecond();
	}

	inline LONGLONG GetMicroSecond()
	{
		return m_pTimer->GetMicroSecond();
	}

	inline BOOL GetTimeIsStoped()
	{
		return m_pTimer->GetIsStoped();
	}
	
	inline BOOL MouseIsPressed(INT key) const
	{
		return m_pDX->MouseIsPressed(key);
	}

	inline BOOL MouseIsHeld(INT key) const
	{
		return m_pDX->MouseIsHeld(key);
	}

	inline BOOL MouseIsReleased(INT key) const
	{
		return m_pDX->MouseIsReleased(key);
	}

	inline BOOL MouseIsNeutral(INT key) const
	{
		return m_pDX->MouseIsNeutral(key);
	}

	inline BOOL MouseAnyKeyIsPressed() const
	{
		return m_pDX->MouseAnyKeyIsPressed();
	}

	inline VOID CursorPos(POINT* pPos) const
	{
		m_pDX->CursorPos(pPos);
	}

	inline LONG MouseWheelScrollingFromPrev() const
	{
		return m_pDX->MouseWheelScrollingFromPrev();
	}

	inline BOOL KeyboardIsPressed(INT key) const
	{
		return m_pDX->KeyboardIsPressed(key);
	}

	inline BOOL KeyboardIsHeld(INT key) const
	{
		return m_pDX->KeyboardIsHeld(key);
	}

	inline BOOL KeyboardIsReleased(INT key) const
	{
		return m_pDX->KeyboardIsReleased(key);
	}

	inline BOOL KeyboardIsNeutral(INT key) const
	{
		return m_pDX->KeyboardIsNeutral(key);
	}

	inline BOOL KeyboardAnyKeyIsPressed() const
	{
		return m_pDX->KeyboardAnyKeyIsPressed();
	}

	inline BOOL CollidesCircles(const CustomVertex* pA, const CustomVertex* pB) const
	{
		return m_pCollision->CollidesCircles(pA, pB);
	}

	inline BOOL CollidesRects(const CustomVertex* pObjA, const CustomVertex* pObjB) const
	{
		return m_pCollision->CollidesRects(pObjA, pObjB);
	}

	inline BOOL CollidesCircles(const D3DXVECTOR3* pA, const D3DXVECTOR3* pB,
		const FLOAT& aRadius, const FLOAT& bRadius) const
	{
		return m_pCollision->CollidesCircles(pA, pB, aRadius, bRadius);
	}

	inline VOID AddSoundFile(const TCHAR* pFilePath, const TCHAR* pKey)
	{
		m_pSound->AddFile(pFilePath, pKey);
	}
	
	inline VOID AddSimultaneousSoundFile(const TCHAR* pFilePath, const TCHAR* pKey)
	{
		m_pSound->AddSimultaneousFile(pFilePath, pKey);
	}

	inline VOID OneShotSimultaneousSound(const TCHAR* pKey)
	{
		m_pSound->OneShotSimultaneous(pKey);
	}

	inline VOID LoopStartSound(const TCHAR* pKey)
	{
		m_pSound->LoopStart(pKey);
	}

	inline VOID OneShotStartSound(const TCHAR* pKey)
	{
		m_pSound->OneShotStart(pKey);
	}

	inline VOID PauseSound(const TCHAR* pKey)
	{
		m_pSound->Pause(pKey);
	}

	inline VOID ResumeSound(const TCHAR* pKey)
	{
		m_pSound->Resume(pKey);
	}

	inline VOID StopSound(const TCHAR* pKey)
	{
		m_pSound->Stop(pKey);
	}

	inline VOID SetVolume(const TCHAR* pKey, INT vol)
	{
		m_pSound->SetVolume(pKey, vol);
	}

	inline BOOL ConnectJoycon(Joycon::CONTROLLER_TYPE controllerType) const
	{
		return m_pJoyconManager->Connect(controllerType);
	}

	inline BOOL GetIsConnectJoycon(Joycon::CONTROLLER_TYPE controllerType) const
	{
		return m_pJoyconManager->GetJoycon(controllerType)->GetIsConnect();
	}

	inline VOID DisconnectJoycon(Joycon::CONTROLLER_TYPE controllerType) const
	{
		m_pJoyconManager->Disconnect(controllerType);
	}

	inline BOOL PushJoyconButton(Joycon::CONTROLLER_TYPE controllerType, int button) const
	{
		return m_pJoyconManager->PushButton(controllerType, button);
	}

	inline BOOL ReleaseJoyconButton(Joycon::CONTROLLER_TYPE controllerType, int button) const
	{
		return m_pJoyconManager->ReleaseButton(controllerType, button);
	}

	inline BOOL HoldJoyconButton(Joycon::CONTROLLER_TYPE controllerType, int button) const
	{
		return m_pJoyconManager->HoldButton(controllerType, button);
	}

	inline BOOL NeutralJoyconButton(Joycon::CONTROLLER_TYPE controllerType, int button) const
	{
		return m_pJoyconManager->NeutralButton(controllerType, button);
	}

	inline BOOL PushJoyconAnalogStick(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->PushAnalogStick(controllerType, direction);
	}

	inline BOOL HoldJoyconAnalogStick(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->HoldAnalogStick(controllerType, direction);
	}

	inline BOOL ReleaseJoyconAnalogStick(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->ReleaseAnalogStick(controllerType, direction);
	}

	inline BOOL NeutralJoyconAnalogStick(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->NeutralAnalogStick(controllerType, direction);
	}
	
	inline BOOL InputGyroSensor(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->InputGyroSensor(controllerType, direction);
	}

	inline BOOL MoveGyroSensor(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->MoveGyroSensor(controllerType, direction);
	}

	inline BOOL StopGyroSensor(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->StopGyroSensor(controllerType, direction);
	}

	inline BOOL NeutralGyroSensor(Joycon::CONTROLLER_TYPE controllerType, int direction) const
	{
		return m_pJoyconManager->NeutralGyroSensor(controllerType, direction);
	}

	inline VOID JoyconRumble(Joycon::CONTROLLER_TYPE controllerType)
	{
		m_pJoyconManager->GetJoycon(controllerType)->SendRumble();
	}

	inline VOID ReleaseFont()
	{
		m_pDX->ReleaseFont();
	}

	inline VOID EraseFont(const TCHAR* pFontKey)
	{
		m_pDX->EraseFont(pFontKey);
	}

	inline VOID CreateFont(const TCHAR* pKey, D3DXVECTOR2 scale, const TCHAR* pFontName, UINT thickness = 0)
	{
		m_pDX->CreateFont(pKey, scale, pFontName, thickness);
	}

	inline BOOL FontExists(const TCHAR* pKey)
	{
		return m_pDX->FontExists(pKey);
	}

	inline const LPD3DXFONT GetFont(const TCHAR* pKey)
	{
		return m_pDX->GetFont(pKey);
	}

private:
	GameLib() {};

	static Wnd* m_pWnd;

	static DX* m_pDX;

	static Timer* m_pTimer;

	static Collision* m_pCollision;

	static Board3D* m_pBoard3D;

	static Sound* m_pSound;

	static JoyconManager* m_pJoyconManager;
};

#endif //! GAME_LIB_H
