// WindowsProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
/*
* 함수 호출 규약: 함수의 실행이 종료되면 스텍을 해제해야하는데 함수를 호출한 호출워(cller)에 의해 
  stack을 저이할 것인가 아니면 호출 받은 피호출자(callee)에서 할 것인가에 대한 양곳ㄱ, 또는 규약
* callback함수: 운영 체제에 의해 호출되는 응용 프로그램 내의 함수. 
* _cdecl: C/C++의 기본 호출 규약, 호출자(caller)가 스텍을 정리한다. 
    ex) printf, scanf 등
    공통점은 정작 자기 자신에게 매개 변수가 얼마나 들어올지 모른다는 점(가변인자함수) 
    그렇게 때문에 본인 스스로가 메모리를 해제할 수 없다. 
        int iData = 10;
        printf("%d", iData);    //  메개변수가 2개인데, %d대신 뭐가 들어오냐에 따라 용량이(?) 달라지는데, 이걸 함수가 미리 알 수 없음. 
                                    이렇게 매개변수가 가변적이면 가변인자라고 한다. 
* _stdcall: win32 api의 기본 호출 규약.
    피 호출자가 스텍을 정리한다. 
    api에서 제공하는 대부분의 함수들은 고정인자이다(<->가변인자) 
    즉, 매개변수에 어떤 타입의 데이터가 들어올지 미리 고정되어어있다. 그래서 호출자가 스택을 알아서 할게 라고 할수있다. 

* _fastcall: 함수 호출을 빠르게 처리하기 위한 호출 규약, ecx와 edx라는 레지스터를 통해 저장, 레지스터를 사용한다는 점에서 함수 호출 속도가 (못봄^^) 대충 빠르다는 얘기겠지. 레지스터니까 
* _thiscall: this 포인터를 매개변수로 넘겨 받았을 때 사용되어지는 호출 규약

* _cdecl만 호출자가 스텍을 정리함. / _cdecl과 _stdcall의 차이점 잘 알아두기 
   
    
*/

#include "framework.h"
#include "WindowsProject1.h"
#include <vector>
#include <list>
using namespace std;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);    // 여기 CALLBACK이런게 함수의 호출 규약을 정해준거임. stdcall이라고 써있지 cdecl과 stdcall의 차이 이런거 공부해오기 
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);  // 쓸모가 없어서 삭제해도됨. 뿅
/* 창실행은 F5, 도움말 관령 어쩌구 뜨는게 어바웃 함수 때문임.없어도됨.뿅
 이거 위에 4개 함수랑 밑에 main이렇게가 함ㅅ쳐서 윈도우 초기화 구문(?)인듯 뿅*/

/*

*/
    int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 프로그램 인스턴스라고 부름. H가 핸들이라는 의미. 
                                                /* 프로새스, 스레드, 파일 = 윈도우의 리소스
                                                    vs라는 프로세스, 크롬이라는 프로세스. ppt라는 프로세스 => 동시에 구동한가 멀티 프로세스라는 것. 
                                                    이중에 내가 크롬창을 클릭하고 검색창에 클릭하면 거기에만 입력됨. => 윈도우가 어디에 메세지를 발생시키느냐(마우스 클릭이나 이런메세지들)를 윈도우가 명령을 내리는거임. "크롬에! 클릭이라는 메세지를 보낸다."
                                                    이때 이 "몇번"프로세스인지 구분하는 번호가 헨들임. 우리가 생성하는 스트림이 곧 파일의 헨들임. 
                                                    프로세스, 스레드, 파일 모두 핸들을 가지고있어야지 고유 식별이 가능함.
                                                */
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,  /* LPWSTR: wchar_t 의 타입디파인. 유니코드 기반의 문자열 포인터임. 자료형앞에 LP가 붙으면 포인터이고, 문자열이면 SRT이 붙음*/
                     _In_ int       nCmdShow)   /* 윈도우 창 스타일. int라고 되어있지만 int 매개변수는 아니고. 플래그값임. 이 플래그 값이 뭐냐에 따라 해당 케이스를 보여주는..그런식의 동작임.  */
{
    UNREFERENCED_PARAMETER(hPrevInstance);  
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); 

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1)); // 창에 관련된 단축키 

    MSG msg;    // msg: 메세지 줄임말
    /* 윈도우는 메세지 기반 운영체제. 메세지를 주고받는 식의 운영*/

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0)) // GetMessage:멀티 프로세스를 위해 꼭 필요한 함수 . WM_QUIT메세지를 읽어오면 FALSE를 반환, 그 외에는 true반홤
        /* 멀티 프로세스라는게 윈도우는 아주빠른 속도로 두개를 왔다갔다하면서 실행하는거임. 
           메세지를 가져올게 있으면 계속 true를 반환. 
           블락: 너만 구동할수없으니까 잠깐 기다려라고 일시적으로 메세지 생성을 제어하는 것. 종료가아님. 
           a를 블락하고, b를 레디-런하고 왔다갔다 하면서 멀티 프로세스를 구현함. 
           이 역할을하는게 GetMessage라는 함수 */
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))/* TranslateAccelerator: 메뉴 기능의 단축키가 제대로 작동하도록 검사하는 함수 */
        {
            TranslateMessage(&msg); // 키보드 메세지를 가공하여 프로그램에세 쉽게 사용할 수 있도록해주는 함수 
                // getmessage()에서 읽어들인걸 가공하는함수 
            DispatchMessage(&msg); // 시스템 메세지 큐에서 꺼낸 메세지를 WndProc에게 전달하는 함수 
                /* GetMessage가 가져온 메세지를 프로시저(?)한테 전할하는 것. */

            /* GetMessage로 가져온애를TranslateMessage가 윈도우 프로시저가 알아들을 수 있도록 가공하고,  DispatchMessage를 통해 윈도우 프로시저한테 보내는것. */
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//창을 만들때, 창에 대한 속성을 어떻게 바꿀지에 대한 함수. 창 스타일을 지정하는 함수 .
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;   // 구조체 

    wcex.cbSize = sizeof(WNDCLASSEX);   // 창 사이즈 

    wcex.style          = CS_HREDRAW | CS_VREDRAW;  
    wcex.lpfnWndProc    = WndProc;  // 윈도우 프로시저 
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)    // 창 생성 함수 
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   /*RECT라는 자료헝이있다. 
     api에서는 데카르트 좌표계를 ㅏㅇㄴ쓴다. x축의 양의 방향은 똑같은데, y축은 반대임. 아래쪽이 +임. 당연함. 알쥐?

     우리는 앞으로 800*600 해상도를 쓸거임. 
     api는 그래픽카드를 실질적으로 쓰지 않으면 렌더링 퍼포먼스를 최적화할수없다. cpu가 일을 다 처리해야하기 떄문에
     전체화면모드는 다렉가서 쓸거임. 
   */

   RECT rc{ 0,0,800,600 };  // 창 사이즈 지정해서 생성하기 위해 

   HWND hWnd = CreateWindowW(
       szWindowClass,
       szTitle,  // 이거 문자열 상수를 쓰고싶으면 앞에 대문자 L붙여야함. L"제목"
       WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0,
       //CW_USEDEFAULT, 0, 
          rc.right - rc.left, rc.bottom - rc.top,   // 창사이즈. 이거 상수로 쓰지 않는 이유가 있음. 비율로 지정해야..나중에뭐.. 어쩌구 한대 
       nullptr, 
       nullptr, 
       hInstance, 
       nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);  // 창 내용 갱신 

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
RECT rcRect{ 100,100,200,200 };
RECT rcEILL{ 125,125,175,175 };
list<RECT> BulletList;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        /* 그리기를 수행하려면 꼭 필요한게 있는데 HDC이다.
           H는 헨들이고, DC는 디바이드 컨텍스트.
           우리가 생성하는 win api는 윈도우의 자식 프로세스 형태. 윈도우없음 win32프로그램 못돌림.
           윈도우에 종속되어있는창들이 기본적으로 소유한 라이브러리 3개. 커널, 유저, GDI
               커널: 메모리 관리하고 프로그램을 실행
               유저: 유저 인터페이스와 위도우 창을 관리
               GDI: 화면 처리화 그래픽을 담당. 그래픽 디바이스 인터페이스. 얘를 통해서 그림, 글자 등을 화면에 출력가능
           DC는 GDI에 속한 데이터 구조체. 출력에 관한 정보를 가지고있음.
           그림그리려면 도화지가 있어야함. 그 도화지를 관리하는애가 DC임.
           우리가 창에 그리려면 해당 창을 일단 얻어와야함. 우리가 생성한 DC를(창) 얻어와야함. 방법1. beginpaint함수로 얻어오기, 2. getdc()로 얻어오기

           그리기 과정
               그릴거야(BeginPaint) -> 그리고 -> 다그렸어.(endpaint) 알려야함.
               다 그린상황을 기준으로 화면을 갱신함. 그래야 우리가 눈으로 그린걸 볼 수 있음. */
    case WM_PAINT: 
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);    // 얻엉온 DC핸들을 기준으로 그리기를 시작
           
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            /*//선그리기
                MoveToEx(hdc, 10, 10, nullptr);
                LineTo(hdc, 110, 10);*/
            
            // 사각형 그리기
                //Rectangle(hdc, 400,400,500,500);
            // 움직이는 사각형 그리기  
                   Rectangle(hdc, rcRect.left, rcRect.top, rcRect.right, rcRect.bottom);
            // 원 그리기
                //Ellipse(hdc, 300,300,400,400);
            
            /* 과제: 그림그려오기 뭐든 */
                MoveToEx(hdc, 400,400, nullptr);
                LineTo(hdc, 400,450);
                LineTo(hdc, 420,460);
                LineTo(hdc, 420, 420);
                MoveToEx(hdc, 420, 460, nullptr);
                LineTo(hdc, 445,445);
                MoveToEx(hdc, 400,400,nullptr);
                LineTo(hdc, 470, 470);
                LineTo(hdc, 500, 460);
                LineTo(hdc, 500, 390);
                LineTo(hdc, 470, 380);
                LineTo(hdc, 470, 470);
                MoveToEx(hdc, 400, 400, nullptr);
                LineTo(hdc, 420,390);
                LineTo(hdc, 470, 440);
                MoveToEx(hdc, 470, 380, nullptr);
                LineTo(hdc, 441, 411);
                MoveToEx(hdc, 470,425,nullptr);
                LineTo(hdc, 460,432);
                MoveToEx(hdc, 420, 432, nullptr);
                LineTo(hdc,426,426);

            // 총알쏘기
            /* 과제: 총알을 3방향 쏘기. 위, 양쪽 대각선 */
            for (list<RECT>::iterator iter = BulletList.begin(); iter != BulletList.end();iter++) {
                Ellipse(hdc, iter->left, iter->top, iter->right, iter->bottom);
                iter->top -= 10;
                iter->bottom -= 10;  // WM_PAINT가 계속 호출되기 떄문에 이게 계속 불리는거임. 

                iter++;
                Ellipse(hdc, iter->left, iter->top, iter->right, iter->bottom);
                iter->top -= 10;
                iter->bottom -= 10;
                iter->left += 5;
                iter->right += 5;

                iter++;
                Ellipse(hdc, iter->left, iter->top, iter->right, iter->bottom);
                iter->top -= 10;
                iter->bottom -= 10;
                iter->left -= 5;
                iter->right -= 5;
            }
            
            EndPaint(hWnd, &ps);    // 얻어온 DC또한 시스템 자원이기 때문에 반드시 소멸 ㅅㅣ켜줘야한다.
        }
        break;
    case WM_CREATE: // 창을 생성하는 최초 시점 한번만 불림
        SetTimer(hWnd, 0,0,0);  //타이머 설치. 윈도우 핸들, 타이머 id번호, 타이머 주기(0이면 1/1000초) , 0인경우 주기적으로 WM_TIMER메세지 생성

        break;
    case WM_TIMER://위에서 settimer가 발생시킨 메세지 처리
       // InvalidateRect(hWnd, 0, FALSE); // 윈도우 갱신 함수, 이 함수가 호출 되면 WM_PAINT가 자동 발생.
        InvalidateRect(hWnd, 0, TRUE); // 잔상이 안보임. 근데 기존의 rect들이 안보인다고해서 지운건아님. api에서는 기존에 그린 렌더링요소가 지워질수없움. 
                                            //그래서 api로 게임안만드는거임. 
        break;
    case WM_KEYDOWN:    // esc누르면 창꺼지는거 추가함. 
        switch (wParam)
        {
        case VK_RIGHT: 
            rcRect.left += 10;
            rcRect.right += 10;
            rcEILL.left += 10;
            rcEILL.right += 10;
            break;
        case VK_LEFT:
            rcRect.left -= 10;
            rcRect.right -= 10;
            rcEILL.left -= 10;
            rcEILL.right -= 10;
            break;
        case VK_DOWN:
            rcRect.top += 10;
            rcRect.bottom += 10;
            rcEILL.top += 10;
            rcEILL.bottom += 10;
            break;
        case VK_UP: 
            rcRect.top -= 10;
            rcRect.bottom -= 10;
            rcEILL.top -= 10;
            rcEILL.bottom -= 10;
            break;
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        case VK_SPACE:  
            // 생성
            BulletList.push_back(rcEILL);
            BulletList.push_back(rcEILL);
            BulletList.push_back(rcEILL);
            break;
        default:
            break;
        }
        break;
    case WM_DESTROY:    // 창 x버튼 눌러서 끌대 발생함. 
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
