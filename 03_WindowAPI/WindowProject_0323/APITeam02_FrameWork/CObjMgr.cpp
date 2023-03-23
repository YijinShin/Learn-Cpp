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
	// 한번깨끗히 지우고 시작하기
	//Release();

	// 파일 이름 설정하기 
	Set_FileName(_eStageID);
	// 오브젝트 정보 읽어오기 
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

	// TODO: 충돌 처리
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
	// 파일 개방
	HANDLE	hFile = CreateFile(m_sMonsterFileName,
		GENERIC_READ,		// 모드 설정(GENERIC_WRITE : 쓰기 GENERIC_READ : 읽기)
		NULL,				// 공유 방식 : 파일이 열려 있는 상태에서 다른 프로세스가 파일을 오픈할 때 허가할 것인가(NULL인 경우 공유하지 않는다)
		NULL,				// 보안 속성 : NULL인 경우 기본 보안 상태
		OPEN_EXISTING,		// 파일 생성 방식 (CREATE_ALWAYS : 파일이 없다면 생성하고, 있으면 덮어 쓰기해라, OPEN_EXISTING : 파일이 있을 경우에만 로드)
		FILE_ATTRIBUTE_NORMAL,	// 파일 속성(읽기 전용, 숨김 파일 등) (FILE_ATTRIBUTE_NORMAL : 아무런 속성 없는 일반 파일) 
		NULL);	// 생성할 파일의 속성을 제공할 템플릿 파일(안쓸거니깐 NULL)

	if (INVALID_HANDLE_VALUE == hFile) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
		return;
	}

	// 파일 읽기 
	DWORD	dwByte = 0;	// 예외처리 용 변수
	INFO	tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);

		if (0 == dwByte) break;

		CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create(tInfo.fX, tInfo.fY));
	}

	// 파일 닫기 
	CloseHandle(hFile);

	MessageBox(g_hWnd, _T("Success"), L"Load Line Data", MB_OK);
}

void CObjMgr::Load_ObstacleData()
{
	// 파일 개방
	HANDLE	hFile = CreateFile(m_sObstacleFileName,
		GENERIC_READ,		// 모드 설정(GENERIC_WRITE : 쓰기 GENERIC_READ : 읽기)
		NULL,				// 공유 방식 : 파일이 열려 있는 상태에서 다른 프로세스가 파일을 오픈할 때 허가할 것인가(NULL인 경우 공유하지 않는다)
		NULL,				// 보안 속성 : NULL인 경우 기본 보안 상태
		OPEN_EXISTING,		// 파일 생성 방식 (CREATE_ALWAYS : 파일이 없다면 생성하고, 있으면 덮어 쓰기해라, OPEN_EXISTING : 파일이 있을 경우에만 로드)
		FILE_ATTRIBUTE_NORMAL,	// 파일 속성(읽기 전용, 숨김 파일 등) (FILE_ATTRIBUTE_NORMAL : 아무런 속성 없는 일반 파일) 
		NULL);	// 생성할 파일의 속성을 제공할 템플릿 파일(안쓸거니깐 NULL)

	if (INVALID_HANDLE_VALUE == hFile) {
		MessageBox(g_hWnd, _T("Error"), L"Load Line Data", MB_OK);
		return;
	}

	// 파일 읽기 
	DWORD	dwByte = 0;	// 예외처리 용 변수
	INFO	tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, nullptr);

		if (0 == dwByte) break;

		CObjMgr::Get_Instance()->Add_Object(OBJ_OBSTACLE, CAbstractFactory<CObstacle>::Create(tInfo.fX, tInfo.fY));
	}

	// 파일 닫기 
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

