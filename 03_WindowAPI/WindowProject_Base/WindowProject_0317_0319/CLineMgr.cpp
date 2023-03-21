#include "stdafx.h"
#include "CLineMgr.h"

#include "CKeyMgr.h"

CLineMgr* CLineMgr::m_pInstance = new CLineMgr;

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize(int eStageID)
{
	if (eStageID == STAGE_AJS) {
		// TODO : 필요한 라인정보 파일 읽어오기
		m_sFileName = L"../Data/LineData_AJS.dat";
		Lode_LineData();
	}
	else if (eStageID == STAGE_PIS) {
		// TODO : 필요한 라인정보 파일 읽어오기
		m_sFileName = L"../Data/LineData_PIS.dat";
		Lode_LineData();
	}
	else if (eStageID == STAGE_SHH) {
		// TODO : 필요한 라인정보 파일 읽어오기
		m_sFileName = L"../Data/LineData_SHH.dat";
		Lode_LineData();
	
	}
	else if (eStageID == STAGE_SYJ) {
		// TODO : 필요한 라인정보 파일 읽어오기
		m_sFileName = L"../Data/LineData_SYJ.dat";
		Lode_LineData();
	}
}

void CLineMgr::Update()
{
	// 마우스 좌표 가져오기 
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	// 좌클릭 처리 
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON)) {
		
		// 마우스 최초 클릭시 => 클릭 좌표를 Line의 LPoint로 간주
		if (!m_tLinePoint[LPOINT].fX && !m_tLinePoint[RPOINT].fY) {
			m_tLinePoint[LPOINT].fX = (float)pt.x;
			m_tLinePoint[LPOINT].fY = (float)pt.y;
		}
		// 최초 클릭이 아닌경우 => RPoint로 간주 
		else {
			m_tLinePoint[RPOINT].fX = (float)pt.x;
			m_tLinePoint[RPOINT].fY = (float)pt.y;

			m_LineList.push_back(new CLine(m_tLinePoint[LPOINT], m_tLinePoint[RPOINT]));

			m_tLinePoint[LPOINT].fX = m_tLinePoint[RPOINT].fX;
			m_tLinePoint[LPOINT].fY = m_tLinePoint[RPOINT].fY;
		}
	}
}

/* FIX */
void CLineMgr::Render(HDC hDC)
{
	for (auto iter : m_LineList)
		iter->Render(hDC);
}

/* FIX */
void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}

/* FIX */
void CLineMgr::Save_LineData()
{
	// 파일 개방
	HANDLE	hFile = CreateFile(m_sFileName,
					GENERIC_READ,		// 모드 설정(GENERIC_WRITE : 쓰기 GENERIC_READ : 읽기)
					NULL,				// 공유 방식 : 파일이 열려 있는 상태에서 다른 프로세스가 파일을 오픈할 때 허가할 것인가(NULL인 경우 공유하지 않는다)
					NULL,				// 보안 속성 : NULL인 경우 기본 보안 상태
					CREATE_ALWAYS,		// 파일 생성 방식 (CREATE_ALWAYS : 파일이 없다면 생성하고, 있으면 덮어 쓰기해라, OPEN_EXISTING : 파일이 있을 경우에만 로드)
					FILE_ATTRIBUTE_NORMAL,	// 파일 속성(읽기 전용, 숨김 파일 등) (FILE_ATTRIBUTE_NORMAL : 아무런 속성 없는 일반 파일) 
					NULL);	// 생성할 파일의 속성을 제공할 템플릿 파일(안쓸거니깐 NULL)
	
	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBox(g_hWnd,_T("Error"), L"Save Line Data", MB_OK);
	}

	// 파일 쓰기 
	DWORD	dwByte = 0;	// 예외처리 용 변수

	for (auto iter : m_LineList) {
		WriteFile( hFile, &(iter->Get_Line()), sizeof(LINE), &dwByte, nullptr);
	}
	
	// 파일 닫기 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Save Line Data", MB_OK);
}

/* FIX */
void CLineMgr::Lode_LineData()
{
	// 파일 개방
	HANDLE	hFile = CreateFile(m_sFileName,
		GENERIC_READ,		// 모드 설정(GENERIC_WRITE : 쓰기 GENERIC_READ : 읽기)
		NULL,				// 공유 방식 : 파일이 열려 있는 상태에서 다른 프로세스가 파일을 오픈할 때 허가할 것인가(NULL인 경우 공유하지 않는다)
		NULL,				// 보안 속성 : NULL인 경우 기본 보안 상태
		OPEN_EXISTING,		// 파일 생성 방식 (CREATE_ALWAYS : 파일이 없다면 생성하고, 있으면 덮어 쓰기해라, OPEN_EXISTING : 파일이 있을 경우에만 로드)
		FILE_ATTRIBUTE_NORMAL,	// 파일 속성(읽기 전용, 숨김 파일 등) (FILE_ATTRIBUTE_NORMAL : 아무런 속성 없는 일반 파일) 
		NULL);	// 생성할 파일의 속성을 제공할 템플릿 파일(안쓸거니깐 NULL)
	
	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
	}

	// 파일 읽기 
	DWORD	dwByte = 0;	// 예외처리 용 변수
	LINE	tLine{};
	while (true)
	{
		ReadFile(hFile, &tLine, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte) break;

		m_LineList.push_back(new CLine(tLine));
	}

	// 파일 닫기 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Load Line Data", MB_OK);



}
