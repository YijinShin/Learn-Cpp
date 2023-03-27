#include "stdafx.h"
#include "CTileMgr.h"

#include "AbstractFactory.h"
#include "CTile.h"

CTileMgr*			CTileMgr::m_pInstance = nullptr;


CTileMgr::CTileMgr()
{
	m_vecTile.reserve(TILEX * TILEY);
}

CTileMgr::~CTileMgr()
{
	Release();
}

void CTileMgr::Initialize()
{
	for (int i = 0; i < TILEY; i ++) {
		
		for (int j = 0; j < TILEX; j ++) {
			
			float fX = (float)(TILECX >> 1) + (TILECX * j); //(TILECX >> 1) 이게 그 타일 반지름. 
			float fY = (float)(TILECY >> 1) + (TILECY * i);

			CObj*		pObj = CAbstractFactory<CTile>::Create(fX, fY);
			m_vecTile.push_back(pObj); 
		}
	}
}

void CTileMgr::Update()
{
	for (auto iter : m_vecTile)
		iter->Update();
}

void CTileMgr::Late_Update()
{
	for (auto iter : m_vecTile)
		iter->Late_Update();
}

void CTileMgr::Render(HDC hDC)
{
	for (auto iter : m_vecTile)
		iter->Render(hDC);
}

void CTileMgr::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), CDeleteObj());

	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

void CTileMgr::Picking(POINT _pt, int _iDrawID, int _iOption)
{
	// 인덱스 찾기
	int i = _pt.x / TILECX;
	int j = _pt.y / TILECY;
	int iIndex = j * TILEX + i;

	// 만약 구한 인덱스가 타일 백터를 벗어나면 리턴 
	if (0 > iIndex || size_t(iIndex) > m_vecTile.size() )
		return;

	// 해당 인덱스의 CTile 객체의 DrawID바꾸기 
	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(_iDrawID);
	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_Option(_iOption);


}

void CTileMgr::Save_TileData()
{
	// 파일 생성
	HANDLE		hFile = CreateFile(L"../Data/TileData.dat", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile) {
		MessageBox(g_hWnd, _T("Error"), L"Save Tile Data", MB_OK);
		return;
	}

	// 파일 쓰기 전용으로 열기
	int			iDrawID = 0;
	int			iOption = 0;
	DWORD		dwByte = 0;

	// 데이터 쓰기 
	for (auto iter : m_vecTile) {
		iDrawID = dynamic_cast<CTile*>(iter)->Get_DrawID();
		iOption = dynamic_cast<CTile*>(iter)->Get_Option();
		
		INFO tInfo = iter->Get_Info();

		WriteFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, nullptr);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, nullptr);
	}

	// 파일 닫기 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Save Tile Data", MB_OK);
}

void CTileMgr::Load_TileData()
{
	// 파일 생성
	HANDLE		hFile = CreateFile(L"../Data/TileData.dat", GENERIC_READ, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	// 데이터 읽기
	INFO		tInfo{};
	int			iDrawID = 0;
	int			iOption = 0;
	DWORD		dwByte = 0;

	while (true) {
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);
		ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, nullptr);
		ReadFile(hFile, &iOption, sizeof(int), &dwByte, nullptr);

		if (dwByte == 0) break;

		CObj* pObj = CAbstractFactory<CTile>::Create(tInfo.fX, tInfo.fY);
		dynamic_cast<CTile*>(pObj)->Set_DrawID(iDrawID);
		dynamic_cast<CTile*>(pObj)->Set_Option(iOption);

		m_vecTile.push_back(pObj);
	}

	// 파일 닫기 
	CloseHandle(hFile);
}
