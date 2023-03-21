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
		// TODO : �ʿ��� �������� ���� �о����
		m_sFileName = L"../Data/LineData_AJS.dat";
		Lode_LineData();
	}
	else if (eStageID == STAGE_PIS) {
		// TODO : �ʿ��� �������� ���� �о����
		m_sFileName = L"../Data/LineData_PIS.dat";
		Lode_LineData();
	}
	else if (eStageID == STAGE_SHH) {
		// TODO : �ʿ��� �������� ���� �о����
		m_sFileName = L"../Data/LineData_SHH.dat";
		Lode_LineData();
	
	}
	else if (eStageID == STAGE_SYJ) {
		// TODO : �ʿ��� �������� ���� �о����
		m_sFileName = L"../Data/LineData_SYJ.dat";
		Lode_LineData();
	}
}

void CLineMgr::Update()
{
	// ���콺 ��ǥ �������� 
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	// ��Ŭ�� ó�� 
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON)) {
		
		// ���콺 ���� Ŭ���� => Ŭ�� ��ǥ�� Line�� LPoint�� ����
		if (!m_tLinePoint[LPOINT].fX && !m_tLinePoint[RPOINT].fY) {
			m_tLinePoint[LPOINT].fX = (float)pt.x;
			m_tLinePoint[LPOINT].fY = (float)pt.y;
		}
		// ���� Ŭ���� �ƴѰ�� => RPoint�� ���� 
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
	// ���� ����
	HANDLE	hFile = CreateFile(m_sFileName,
					GENERIC_READ,		// ��� ����(GENERIC_WRITE : ���� GENERIC_READ : �б�)
					NULL,				// ���� ��� : ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ ������ �� �㰡�� ���ΰ�(NULL�� ��� �������� �ʴ´�)
					NULL,				// ���� �Ӽ� : NULL�� ��� �⺻ ���� ����
					CREATE_ALWAYS,		// ���� ���� ��� (CREATE_ALWAYS : ������ ���ٸ� �����ϰ�, ������ ���� �����ض�, OPEN_EXISTING : ������ ���� ��쿡�� �ε�)
					FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�(�б� ����, ���� ���� ��) (FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ� ���� �Ϲ� ����) 
					NULL);	// ������ ������ �Ӽ��� ������ ���ø� ����(�Ⱦ��Ŵϱ� NULL)
	
	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBox(g_hWnd,_T("Error"), L"Save Line Data", MB_OK);
	}

	// ���� ���� 
	DWORD	dwByte = 0;	// ����ó�� �� ����

	for (auto iter : m_LineList) {
		WriteFile( hFile, &(iter->Get_Line()), sizeof(LINE), &dwByte, nullptr);
	}
	
	// ���� �ݱ� 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Save Line Data", MB_OK);
}

/* FIX */
void CLineMgr::Lode_LineData()
{
	// ���� ����
	HANDLE	hFile = CreateFile(m_sFileName,
		GENERIC_READ,		// ��� ����(GENERIC_WRITE : ���� GENERIC_READ : �б�)
		NULL,				// ���� ��� : ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ ������ �� �㰡�� ���ΰ�(NULL�� ��� �������� �ʴ´�)
		NULL,				// ���� �Ӽ� : NULL�� ��� �⺻ ���� ����
		OPEN_EXISTING,		// ���� ���� ��� (CREATE_ALWAYS : ������ ���ٸ� �����ϰ�, ������ ���� �����ض�, OPEN_EXISTING : ������ ���� ��쿡�� �ε�)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�(�б� ����, ���� ���� ��) (FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ� ���� �Ϲ� ����) 
		NULL);	// ������ ������ �Ӽ��� ������ ���ø� ����(�Ⱦ��Ŵϱ� NULL)
	
	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
	}

	// ���� �б� 
	DWORD	dwByte = 0;	// ����ó�� �� ����
	LINE	tLine{};
	while (true)
	{
		ReadFile(hFile, &tLine, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte) break;

		m_LineList.push_back(new CLine(tLine));
	}

	// ���� �ݱ� 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Load Line Data", MB_OK);



}
