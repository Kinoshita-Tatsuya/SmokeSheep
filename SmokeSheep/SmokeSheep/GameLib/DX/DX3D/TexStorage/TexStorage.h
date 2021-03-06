﻿/**
* @file TexStorage.h
* @brief テクスチャ管理クラスのヘッダ
* @author Harutaka-Tsujino
*/

#ifndef TEX_STORAGE_H
#define TEX_STORAGE_H

#include <windows.h>
#include <tchar.h>

#include <map>

#include <d3dx9.h>

/**
* @brief テクスチャを作成保存しそれを渡したりするクラス
*/
class TexStorage
{
public:
	TexStorage(const LPDIRECT3DDEVICE9& rpDX3DDev) :m_rpDX3D_DEV(rpDX3DDev) {};
	~TexStorage()
	{ 
		ReleaseTex();
	}

	/**
	* @brief テクスチャを作成する
	* @param pTexKey テクスチャにつける名前のポインタ キー 連想配列
	* @param pTexPath 画像のパスのポインタ
	*/
	inline VOID CreateTex(const TCHAR* pTexKey, const TCHAR* pTexPath)
	{
		if (Exists(pTexKey)) return;

		D3DXCreateTextureFromFile(
			m_rpDX3D_DEV, 
			pTexPath, 
			&m_pTexMap[pTexKey]);
	}

	/**
	* @brief 全てのテクスチャの開放
	*/
	inline VOID ReleaseTex()
	{
		if (!m_pTexMap.size()) return;

		for (auto i : m_pTexMap)
		{
			if (!i.second) continue;

			(i.second)->Release();
		}

		m_pTexMap.clear();
	}

	/**
	* @brief テクスチャを取得する
	* @param pTexKey テクスチャを作るときに決めたキーのポインタ
	* @return テクスチャのポインタ
	*/
	inline const LPDIRECT3DTEXTURE9 GetTex(const TCHAR* pTexKey)
	{
		return m_pTexMap[pTexKey];
	}

	inline VOID EraseTex(const TCHAR* pTexKey)
	{
		if (!Exists(pTexKey)) return;

		m_pTexMap[pTexKey]->Release();
		m_pTexMap.erase(pTexKey);
	}

	/**
	* @brief テクスチャが生成されているか判断する
	* @param pTexKey テクスチャを作るときに決めたキーのポインタ
	* @return 存在していたらTRUE
	*/
	inline const BOOL Exists(const TCHAR* pTexKey)
	{
		return (m_pTexMap.find(pTexKey) != m_pTexMap.end());
	}

private:
	const LPDIRECT3DDEVICE9& m_rpDX3D_DEV = nullptr;

	std::map<const TCHAR*, LPDIRECT3DTEXTURE9> m_pTexMap;
};

#endif //! TEX_STORAGE_H
