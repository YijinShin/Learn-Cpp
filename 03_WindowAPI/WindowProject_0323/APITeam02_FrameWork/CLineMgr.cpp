#include "stdafx.h"
#include "CLineMgr.h"

#include "CKeyMgr.h"
#include "CScrollMgr.h"

CLineMgr* CLineMgr::m_pInstance = new CLineMgr;

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize(int _eStageID)
{
	// �ѹ������� ����� �����ϱ�
	Release();
	// ���� �̸� �����ϱ� 
	Set_FileName(_eStageID);
	// ���� ���� �о���� 
	Lode_LineData();	
}
void CLineMgr::Update()
{
	// ���콺 ��ǥ �������� 
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	const float _x = CScrollMgr::Get_Instance()->Get_ScrollX();
	const float _y = CScrollMgr::Get_Instance()->Get_ScrollY();

	// ��Ŭ���� => LPoint�� ���� 
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON)) {
		// ���콺 ���� Ŭ���� => Ŭ�� ��ǥ�� Line�� LPoint�� ����
		m_tLinePoint[LPOINT].fX = (float)pt.x - _x;
		m_tLinePoint[LPOINT].fY = (float)pt.y - _y;
	}

	// ��Ŭ���� => RPoint�� ����
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_RBUTTON)) {
		m_tLinePoint[RPOINT].fX = (float)pt.x - _x;
		m_tLinePoint[RPOINT].fY = (float)pt.y - _y;

		// ���� ��->�·� �׸� ���
		if (m_tLinePoint[RPOINT].fX < m_tLinePoint[LPOINT].fX)
			swap(m_tLinePoint[LPOINT], m_tLinePoint[RPOINT]);

		m_LineList.push_back(new CLine(m_tLinePoint[LPOINT], m_tLinePoint[RPOINT]));

		m_tLinePoint[LPOINT].fX = m_tLinePoint[RPOINT].fX;
		m_tLinePoint[LPOINT].fY = m_tLinePoint[RPOINT].fY;
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
	HANDLE	hFile = CreateFile(m_sFileName,	// ���� ��ο� �̸��� �־���
		GENERIC_WRITE,		// ��� ����(GENERIC_WRITE : ���� GENERIC_READ : �б�)
		NULL,				// ���� ��� : ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ ������ �� �㰡�� ���ΰ�(NULL�� ��� �������� �ʴ´�)
		NULL,				// ���� �Ӽ� : NULL�� ��� �⺻ ���� ����
		CREATE_ALWAYS,		// ���� ���� ��� (CREATE_ALWAYS : ������ ���ٸ� �����ϰ�, ������ ���� �����ض�, OPEN_EXISTING : ������ ���� ��쿡�� �ε�)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�(�б� ����, ���� ���� ��) (FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ� ���� �Ϲ� ����) 
		NULL);	// ������ ������ �Ӽ��� ������ ���ø� ����(�Ⱦ��Ŵϱ� NULL)

	if (hFile == INVALID_HANDLE_VALUE) {
		MessageBox(g_hWnd,_T("Error"), L"Save Line Data", MB_OK);
		return;
	}


	// ���� ���� 
	DWORD	dwByte = 0;	// ����ó�� �� ����

	for (auto& iter : m_LineList) {
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
	
	if (INVALID_HANDLE_VALUE == hFile ) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
		return;
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

void CLineMgr::Set_FileName(int eStageID)
{
	if (eStageID == SC_STAGE_AJS) {
		m_sFileName = L"../Data/LineData_AJS.dat";
	}
	else if (eStageID == SC_STAGE_PIS) {
		m_sFileName = L"../Data/LineData_PIS.dat";
	}
	else if (eStageID == SC_STAGE_SHH) {
		m_sFileName = L"../Data/LineData_SHH.dat";
	}
	else if (eStageID == SC_STAGE_SYJ) {
		m_sFileName = L"../Data/LineData_SYJ.dat";
	}
}

// TODO �߰��� �Լ� 

bool CLineMgr::SYJ_Collision_Line(float _fX, float _fY, float* pCalcY)
{
	float Height(0.f);
	float fMinYDist(WINCY);
	bool	bIsExist(false);

	for (auto iter : m_LineList) {

		float fX1 = iter->Get_Line().tLpoint.fX;
		float fX2 = iter->Get_Line().tRpoint.fX;
		float fY1 = iter->Get_Line().tLpoint.fY;
		float fY2 = iter->Get_Line().tRpoint.fY;
		
		
		if (fX1-10.f <= _fX && _fX < fX2 + 10.f) {

			// y��ǥ ���ϱ� 
			float	fM = (fY2 - fY1) / (fX2 - fX1);  // ���� 
			float   fN = fY1 - fM * fX1;			// y����  
			float	fCalcY = fM * _fX + fN;
			
			float	fDist = _fY - fCalcY;

			// �÷��̾ ���� ��� �ִ��� Ȯ�� 
			if( fDist >= -20.f && fDist < 20.f){
				// ����ִٸ� fCalcY�� �÷��̾��� Y�� ����
				*pCalcY = fCalcY;
				// ����ִ� ���� �ִٰ� true ��ȯ
				return true;
			}
			
		}
	}

	// �ƹ� ���� ������� �ʴٸ� false ��ȯ
	return bIsExist;
}

