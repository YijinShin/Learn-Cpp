#pragma once
#include "Define.h"

#define MAXNAMESIZE 20


typedef struct stFieldCreatureINFO{
	char szName[MAXNAMESIZE];
	int iTotalHP;
	int iCurrHP;
	int iOffencePower;
}FCINFO, *PFCINFO;

typedef struct stPlayerINFO {
	char szJob[MAXNAMESIZE];
	int iLv;
}PINFO, *PPINFO;

typedef struct stMonsterINFO {
	
}MINFO, *PMINFO;