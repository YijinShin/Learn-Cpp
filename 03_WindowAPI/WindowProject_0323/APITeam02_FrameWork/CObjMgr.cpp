#include "stdafx.h"
#include "CObjMgr.h"
#include "CCollisionMgr.h"

#include "AbstractFactory.h"

#include "CMonster.h"
#include "CObstacle.h"

CObjMgr*	CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}

CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Set_FileName(int eStageID)
{
	if (eStageID == SC_STAGE_AJS) {
		m_sMonsterFileName = L"../Data/MonsterData_AJS.dat";
		m_sObstacleFileName = L"../Data/ObstacleData_AJS.dat";
	}
	else if (eStageID == SC_STAGE_PIS) {
		m_sMonsterFileName = L"../Data/MonsterData_PIS.dat";
		m_sObstacleFileName = L"../Data/ObstacleData_PIS.dat";
	}
	else if (eStageID == SC_STAGE_SHH) {
		m_sMonsterFileName = L"../Data/MonsterData_SHH.dat";
		m_sObstacleFileName = L"../Data/ObstacleData_SHH.dat";
	}
	else if (eStageID == SC_STAGE_SYJ) {
		m_sMonsterFileName = L"../Data/MonsterData_SYJ.dat";
		m_sObstacleFileName = L"../Data/ObstacleData_SYJ.dat";
	}
}

void CObjMgr::Add_Object(OBJID eObjID, CObj* pObj)
{
	if (eObjID >= OBJ_END || pObj == nullptr) return;
	m_ObjList[eObjID].push_back(pObj);

}

void CObjMgr::Initialize(int _eStageID)
{
	// �ѹ������� ����� �����ϱ�
	//Release();

	// ���� �̸� �����ϱ� 
	Set_FileName(_eStageID);
	// ������Ʈ ���� �о���� 
		//Load_MonsterData();
		//Load_ObstacleData();
}

void CObjMgr::Update()
{
	int iResult(0);

	for (size_t i = 0; i < OBJ_END; i++) {
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();) {
			iResult = (*iter)->Update();

			if (iResult == OBJ_DEAD) {
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else iter++;
		}
	}
}

void CObjMgr::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; i++) {
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();

			if (m_ObjList[i].empty())
				break;
		}
	}

	// TODO: �浹 ó��
	CCollisionMgr::Collision_Flag_Player(m_ObjList[OBJ_FLAG], m_ObjList[OBJ_PLAYER]);
}

void CObjMgr::Render(HDC hDC)
{
	for (size_t i = 0; i < OBJ_END; i++) {
		for (auto iter : m_ObjList[i]) {
			iter->Render(hDC);
		}
	}
}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJ_END; i++) {
		for_each( m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}

void CObjMgr::Load_MonsterData()
{
	// ���� ����
	HANDLE	hFile = CreateFile(m_sMonsterFileName,
		GENERIC_READ,		// ��� ����(GENERIC_WRITE : ���� GENERIC_READ : �б�)
		NULL,				// ���� ��� : ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ ������ �� �㰡�� ���ΰ�(NULL�� ��� �������� �ʴ´�)
		NULL,				// ���� �Ӽ� : NULL�� ��� �⺻ ���� ����
		OPEN_EXISTING,		// ���� ���� ��� (CREATE_ALWAYS : ������ ���ٸ� �����ϰ�, ������ ���� �����ض�, OPEN_EXISTING : ������ ���� ��쿡�� �ε�)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�(�б� ����, ���� ���� ��) (FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ� ���� �Ϲ� ����) 
		NULL);	// ������ ������ �Ӽ��� ������ ���ø� ����(�Ⱦ��Ŵϱ� NULL)

	if (INVALID_HANDLE_VALUE == hFile) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
		return;
	}

	// ���� �б� 
	DWORD	dwByte = 0;	// ����ó�� �� ����
	INFO	tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);

		if (0 == dwByte) break;

		CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(tInfo.fX, tInfo.fY));
	}

	// ���� �ݱ� 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Load Line Data", MB_OK);
}

void CObjMgr::Load_ObstacleData()
{
	// ���� ����
	HANDLE	hFile = CreateFile(m_sObstacleFileName,
		GENERIC_READ,		// ��� ����(GENERIC_WRITE : ���� GENERIC_READ : �б�)
		NULL,				// ���� ��� : ������ ���� �ִ� ���¿��� �ٸ� ���μ����� ������ ������ �� �㰡�� ���ΰ�(NULL�� ��� �������� �ʴ´�)
		NULL,				// ���� �Ӽ� : NULL�� ��� �⺻ ���� ����
		OPEN_EXISTING,		// ���� ���� ��� (CREATE_ALWAYS : ������ ���ٸ� �����ϰ�, ������ ���� �����ض�, OPEN_EXISTING : ������ ���� ��쿡�� �ε�)
		FILE_ATTRIBUTE_NORMAL,	// ���� �Ӽ�(�б� ����, ���� ���� ��) (FILE_ATTRIBUTE_NORMAL : �ƹ��� �Ӽ� ���� �Ϲ� ����) 
		NULL);	// ������ ������ �Ӽ��� ������ ���ø� ����(�Ⱦ��Ŵϱ� NULL)

	if (INVALID_HANDLE_VALUE == hFile) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
		return;
	}

	// ���� �б� 
	DWORD	dwByte = 0;	// ����ó�� �� ����
	INFO	tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);

		if (0 == dwByte) break;

		CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CObstacle>::Create(tInfo.fX, tInfo.fY));
	}

	// ���� �ݱ� 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Load Line Data", MB_OK);
}

void CObjMgr::Draw_Monster()
{

}

void CObjMgr::Delete_ID(int iObjID)
{
	for (auto iter : m_ObjList[iObjID]) {
		Safe_Delete(iter);
	}
	m_ObjList[iObjID].clear();
}

