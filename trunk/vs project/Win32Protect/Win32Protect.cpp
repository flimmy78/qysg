// Win32Protect.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32Protect.h"
#include "Common.h"
#include "Utils.h"
#include "tlhelp32.h"

//���������
#include "xcgui.h"
#pragma comment(lib,"XCGUI.lib")

HWINDOW hWindow = NULL;
HWINDOW hWindowRegit = NULL;

#define MAX_LOADSTRING 100

#include <WinSock2.h>
SOCKET sClient;
HELE hRichEditRegitAccount;
HELE hRichEditRegitPasswd;
HELE hRichEditRegitPasswd2;
HELE hRichEditRegitCode;
HXCGUI hPicCode;
CString m_bitmapCode;
HELE hRichEdit;

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

CString StartFile;
CString ClntPid;

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinClose_EventBtnClick(BOOL *pbHandled)
{
	*pbHandled = TRUE;
	INT PID = Utils::KillProcessByName(StartFile);

	::SendMessage(XWnd_GetHWND(hWindow), WM_CLOSE, NULL, NULL);
	return 0;
}

int CALLBACK WinMin_EventBtnClick(BOOL *pbHandled)
{
	XWnd_ShowWindow(hWindow, SW_MINIMIZE);
	*pbHandled = TRUE;
	return 0;
}

BOOL g_bLimitKeyPress = true;

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	CString str[] = { L"����κ����", L"��������", L"����С����" };
	INT pid[] = { _ttoi(ClntPid) };
	while (1)
	{
		try
		{
			BOOL result = Utils::GetProcessList(str, 3, pid, 1);
			if (result)
			{
				//close client 
				BOOL flag;
				WinClose_EventBtnClick(&flag);
				//MessageBox(NULL, L"��⵽�Ƿ��������У���������Ϸ����", L"��ʾ", NULL);
			}

			/*if (FindWindow(NULL, L"QYProClient") == 0)
			{
				BOOL flag;
				WinClose_EventBtnClick(&flag);
			}*/
		}
		catch (CException& w)
		{
		}
		
		Sleep(5000);
	}
	return 0;
}

int InitializeComponent()
{
	hWindow = XWnd_Create(20, 20, 597, 333, L"�����¼��",NULL,xc_window_style_modal);//��������
	if (hWindow)
	{
		XShapeText_Create(12, 6, 0, 0, L"��������", hWindow);

		HELE hBtnWinClose = XBtn_Create(573, 7, 15, 15, L"X", hWindow);
		XEle_RegEventC(hBtnWinClose, XE_BNCLICK, WinClose_EventBtnClick);

		HELE hBtnWinMin = XBtn_Create(553, 7, 15, 15, L"-", hWindow);
		XEle_RegEventC(hBtnWinMin, XE_BNCLICK, WinMin_EventBtnClick);

		//XWnd_ShowWindow(hWindow, SW_SHOW);
	}

	//start listen
	DWORD threadID;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, &threadID); // �����߳�
	if (hThread == NULL)
	{
		MessageBox(NULL, L"����ʧ�ܣ�", L"��ʾ", NULL);
		BOOL flag;
		WinClose_EventBtnClick(&flag);
		return -1;
	}

	return 0;
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	XInitXCGUI();//��ʼ��
	XC_EnableDebugFile(FALSE);

	CString CmdLine = lpCmdLine;

	TCHAR seps[] = _T(" ");
	TCHAR* token = _tcstok((LPTSTR)(LPCTSTR)CmdLine, seps);

	INT COUNT = 0;
	while (token != NULL)
	{
		COUNT++;
		if (COUNT == 1)
		{
			StartFile.Format(TEXT("%s"), token);
		}
		else if (COUNT == 2)
		{
			ClntPid.Format(TEXT("%s"), token);
		}
		else
		{
			break;
		}
		token = _tcstok(NULL, seps);
	}

	InitializeComponent(); 
	//��lpCmdLine������Ҫ�رյĽ������ͱ����Ľ���ID
	//MessageBox(NULL, lpCmdLine, L"��ʾ", MB_OK);

	//MessageBox(NULL, StartFile, L"��ʾStartFile", MB_OK);
	//MessageBox(NULL, ClntPid, L"��ʾClntPid", MB_OK);

	XRunXCGUI();
	XExitXCGUI();
	return 0;
}
