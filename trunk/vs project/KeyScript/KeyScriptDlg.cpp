
// KeyScriptDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KeyScript.h"
#include "KeyScriptDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HANDLE hSelProc;
HWND hSelWnd;
DWORD dwMineProcId;
HANDLE hMineProc;
HWND hMineWnd;
BOOL bStop;
int m_num;
HWND g_hWnd = NULL;
struct sWindowInfo
{
	HWND hHwnd;
	HANDLE hProc;
	DWORD dwProcId;
	CString csWindowName;
	CString csClassName;
};
struct sWindowInfo m_WindowInfo[32];

const int Keys[11] = { VK_TAB, VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8,
WM_LBUTTONDOWN, WM_RBUTTONDOWN };

struct stParam
{
	int nCulSel;
	int nIndex;
};
struct stParam m_stParam;

// CKeyScriptDlg �Ի���



CKeyScriptDlg::CKeyScriptDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKeyScriptDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyScriptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PROCESS, m_CComboBoxProcess);
	DDX_Control(pDX, IDC_COMBO_KEYS, m_CComboBoxKey);
	DDX_Control(pDX, IDC_START, m_CButtonCrtl);
}

BEGIN_MESSAGE_MAP(CKeyScriptDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLOSE, &CKeyScriptDlg::OnBnClickedClose)
	ON_BN_CLICKED(IDC_START, &CKeyScriptDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_HIDE, &CKeyScriptDlg::OnBnClickedHide)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_CBN_SELCHANGE(IDC_COMBO_KEYS, &CKeyScriptDlg::OnCbnSelchangeComboKeys)
END_MESSAGE_MAP()


// CKeyScriptDlg ��Ϣ�������

BOOL CALLBACK MyEnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	// 	if (::GetWindowLong(hwnd, GWL_STYLE)& WS_VISIBLE)
	// 	{
	// 		m_WindowInfo[m_num].hHwnd = hwnd;//record the HWND handle into array
	// 		::GetWindowThreadProcessId(hwnd, &m_WindowInfo[m_num].dwProcId); //��ȡ���ڽ���ID
	// 		CWnd* pWnd = CWnd::FromHandle(hwnd);
	// 		pWnd->GetWindowText(m_WindowInfo[m_num].csWindowName);// ��ȡ��������
	// 		//m_CComboBoxProcess.AddString(m_WindowInfo[m_num].csWindowName);
	// 		m_num++;//count start
	// 	}

	CKeyScriptDlg* pView = (CKeyScriptDlg*)lParam;
	/*	CListCtrl& lc = pView->GetListCtrl();*/

	if (hwnd != pView->GetParentFrame()->GetSafeHwnd()) //���Ǳ�����
	{
		DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);
		if ((dwStyle & WS_OVERLAPPEDWINDOW) && (dwStyle & WS_VISIBLE))
		{
			CString csWinName;
			CWnd* pWnd = CWnd::FromHandle(hwnd);
			// ���ڱ���
			pWnd->GetWindowText(csWinName);
			//if (csWinName.Find("����") >= 0 || csWinName.Find("online") >= 0 || csWinName.Find("loader") >= 0)
			if (csWinName.Find("����ȺӢ��") >= 0)
			{
				m_WindowInfo[m_num].hHwnd = hwnd;//record the HWND handle into array

				//��ȡ���ڽ���ID
				::GetWindowThreadProcessId(hwnd, &m_WindowInfo[m_num].dwProcId);

				//���洰����
				CString csProcId;
				csProcId.Format(_T(" - PID:%d"), m_WindowInfo[m_num].dwProcId);
				m_WindowInfo[m_num].csWindowName = csWinName + csProcId;

				// ��������
				::GetClassName(hwnd, m_WindowInfo[m_num].csClassName.GetBuffer(256), 256);
				m_num++;
			}

		}
	}

	return TRUE;
}

BOOL CKeyScriptDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_num = 0;
	EnumWindows(MyEnumWindowsProc, (LPARAM)this);//�������ڳ���

	CString strName;
	for (int i = 0; i < m_num; i++)
	{
		strName.Format("%d-%s", i + 1, m_WindowInfo[i].csWindowName);
		m_CComboBoxProcess.AddString(strName);
	}

	m_CComboBoxProcess.SetCurSel(0);
	m_CComboBoxKey.SetCurSel(0);

	bStop = TRUE;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CKeyScriptDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CKeyScriptDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKeyScriptDlg::OnBnClickedClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	exit(0);
}

LPARAM VKBParam(int VirtKey, int flag)
{
	if (flag == 1) // ����
	{
		return (0x1 | (MapVirtualKey(VirtKey, MAPVK_VK_TO_VSC) << 16));
	}
	else if (flag == 0)
	{
		return (0x1 | ((KF_REPEAT | KF_UP | MapVirtualKey(VirtKey, MAPVK_VK_TO_VSC)) << 16));
	}
}

static DWORD WINAPI  DoAutoScript(void *pArg)
{
	//����д�ϴ����߳���ʲô�ĺ���

	while (1)
	{
		if (bStop)
		{
			return 0;
		}

		::SendMessage(m_WindowInfo[m_stParam.nCulSel].hHwnd, WM_KEYDOWN, Keys[m_stParam.nIndex], VKBParam(Keys[m_stParam.nIndex], 1));
		Sleep(500);
		::SendMessage(m_WindowInfo[m_stParam.nCulSel].hHwnd, WM_KEYUP, Keys[m_stParam.nIndex], VKBParam(Keys[m_stParam.nIndex], 0));
		Sleep(500);
	}
}

void CKeyScriptDlg::OnBnClickedStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (bStop == TRUE)
	{
		m_CButtonCrtl.SetWindowText("��ͣ");
		bStop = FALSE;
	}
	else if (bStop == FALSE)
	{
		m_CButtonCrtl.SetWindowText("��ʼ");
		bStop = TRUE;
		return;
	}

	int nCurSel = m_CComboBoxProcess.GetCurSel();
	hMineProc = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_WindowInfo[nCurSel].dwProcId); //�򿪽��̾��
	g_hWnd = m_WindowInfo[nCurSel].hHwnd;

	CRect rtGameWnd, rtMyWnd;
	CWnd *pWnd = CWnd::FromHandle(g_hWnd);
	pWnd->GetWindowRect(&rtGameWnd);  // ��ȡ��Ϸ���ڳߴ�
	GetWindowRect(&rtMyWnd);		// ��ȡ��dll�Ĵ��ڳߴ�


	int nIndex = m_CComboBoxKey.GetCurSel();
	if (nIndex < 0)
		return ;

	m_stParam.nCulSel = nCurSel;
	m_stParam.nIndex = nIndex;

	DWORD dwThreadID = 0;
	HANDLE hThread = CreateThread(NULL, 0, DoAutoScript, 0, NULL, &dwThreadID);	
}


void CKeyScriptDlg::OnBnClickedHide()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}


void CKeyScriptDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	isMouseDown = true;
	startPoint = point;
	this->GetWindowRect(startRect);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CKeyScriptDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
// 	if (isMouseDown == true)
// 	{
// 		int Dx = point.x - startPoint.x;
// 		int Dy = point.y - startPoint.y;
// 		startRect.left += Dx;
// 		startRect.right += Dx;
// 		startRect.top += Dy;
// 		startRect.bottom += Dy;             //��ȡ�µ�λ��
// 		this->MoveWindow(&startRect);     //�������Ƶ��µ�λ��
// 	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CKeyScriptDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	isMouseDown = false;

	//CDialogEx::OnLButtonUp(nFlags, point);
}


void CKeyScriptDlg::OnCbnSelchangeComboKeys()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int nIndex = m_CComboBoxKey.GetCurSel();
	if (nIndex < 0)
		return;

	m_stParam.nIndex = nIndex;
}
