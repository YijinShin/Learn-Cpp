#pragma once

// max length of name
#define MAXCHERSIZE 20	

#define SAFE_DELETE(p) {delete p; p = nullptr;}
#define SAFE_ARRAT_DELETE(p) {delete[] p; p = nullptr;}
