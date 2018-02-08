
// HCSG_ManagerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HCSG_Manager.h"
#include "HCSG_ManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHCSG_ManagerDlg �Ի���


CHCSG_ManagerDlg::CHCSG_ManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHCSG_ManagerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CHCSG_ManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_TabMain);
	DDX_Control(pDX, IDC_EDIT_IP, m_CeditIP);
	DDX_Control(pDX, IDC_EDIT_ACC, m_CeditAcc);
	DDX_Control(pDX, IDC_EDIT_PW, m_CeditPw);
	DDX_Control(pDX, IDC_STATIC_STAT, m_CStatic_stat);
	DDX_Control(pDX, IDC_BUTTON_CONCT, m_CButtonConct);
	DDX_Control(pDX, IDC_EDIT_SERVER_PATH, m_EditServerPath);
	DDX_Control(pDX, IDC_BUTTON_ENABLE, m_CButtonEnable);
}

BEGIN_MESSAGE_MAP(CHCSG_ManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SHOWTASK,onShowTask)
	ON_BN_CLICKED(IDC_BUTTON_CONCT, &CHCSG_ManagerDlg::OnBnClickedButtonConct)
	ON_BN_CLICKED(IDC_BUTTON_SACN, &CHCSG_ManagerDlg::OnBnClickedButtonSacn)
	ON_BN_CLICKED(IDC_BUTTON_ENABLE, &CHCSG_ManagerDlg::OnBnClickedButtonEnable)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CHCSG_ManagerDlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()

//ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CHCSG_ManagerDlg::OnTcnSelchangeTabMain)
// CHCSG_ManagerDlg ��Ϣ�������

BOOL CHCSG_ManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	::CoInitialize(NULL);

	Common::ReadConfig();
	InitCurConfig();
	Common::IsEnConn = TRUE;
	Common::SystemInit();

	InitTabMain();
	Common::Log(Info, "Server Start!!");

	if(Common::IsDbConct)
	{
		m_CButtonConct.SetWindowText("�Ͽ�����");
		m_CStatic_stat.SetWindowText("���������ݿ⣡");
		m_CStatic_stat.SetTextColor(RGB(0,0,205));
		Common::IsDbConct = TRUE;
	}
	else
	{
		m_CButtonConct.SetWindowText("�������");
		m_CStatic_stat.SetWindowText("δ�������ݿ⣡");
		m_CStatic_stat.SetTextColor(RGB(255,0,0));
		Common::m_pConnection = NULL;
		Common::IsDbConct = FALSE;
	}

	//SetTimer(TIMER_UPDATE, 60 * 1000, 0);  // ÿ�����Զ�����һ������

	if (IDYES == AfxMessageBox("�Ƿ������Ž�����" , MB_YESNO))
	{
		OnBnClickedButtonEnable();
	}
 
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHCSG_ManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (nID == SC_MINIMIZE)
	{  
		ToTray();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHCSG_ManagerDlg::OnPaint()
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

void CHCSG_ManagerDlg::InitCurConfig()
{
	m_EditServerPath.SetWindowText(Common::ServerPath);
	m_CeditIP.SetWindowText(Common::SQLServer);
	m_CeditAcc.SetWindowText(Common::SQLAccount);
	m_CeditPw.SetWindowText(Common::SQLPassWord);
}

void CHCSG_ManagerDlg::InitTabMain()
{
	CRect tabRect;   // ��ǩ�ؼ��ͻ�����λ�úʹ�С
	m_TabMain.InsertItem(0, _T("��־"));
	m_TabMain.InsertItem(1, _T("�������"));
	m_TabMain.InsertItem(2, _T("��սӢ�۽���"));
	m_TabMain.InsertItem(3, _T("��ս���Ž���"));
	m_TabMain.InsertItem(4, _T("��ڽ���"));
	m_TabMain.InsertItem(5, _T("�鱦����"));
	m_TabMain.InsertItem(6, _T("��������"));
	m_TabMain.InsertItem(7, _T("��ֵ + VIP"));
	

	Common::DlgLog = m_TabMain.InsetPage(0, IDD_DIALOG_LOG, new CLogDlg);
	Common::DlgServer = m_TabMain.InsetPage(1, IDD_DIALOG_SERVER, new CLoginDlg);
	Common::DlgCwarPlayer = m_TabMain.InsetPage(2, IDD_DIALOG_CWAR_PLAYER, new CCwarPlayerDlg);
	Common::DlgCwarOrg = m_TabMain.InsetPage(3, IDD_DIALOG_CWAR_ORG, new CCwarOrgDlg);
	Common::DlgCB = m_TabMain.InsetPage(4, IDD_DIALOG_CB, new CCBDlg);
	Common::DlgXubao = m_TabMain.InsetPage(5, IDD_DIALOG_XUBAO, new CXubaoDlg);
	Common::DlgAttr = m_TabMain.InsetPage(6, IDD_DIALOG_ATTR, new CAttrDlg);
	Common::DlgVip = m_TabMain.InsetPage(7, IDD_DIALOG_VIP, new CVip);
	

	if (IDYES == AfxMessageBox("�Ƿ���Ҫ�鿴�������ֿ���Ϣ��" , MB_YESNO))
	{
		m_TabMain.InsertItem(8, _T("��ɫ�б�"));  // �ʺ�һ��Ῠ��������  �ƽ������ع����У��ɼ�������
		m_TabMain.InsertItem(9, _T("��Ʒ�浵"));
		m_TabMain.InsertItem(10, _T("�ֿ�浵"));
		Common::DlgAttrList = m_TabMain.InsetPage(8, IDD_DIALOG_PLAYERLIST, new CPlayerListDlg);
		Common::DlgItems = m_TabMain.InsetPage(9, IDD_DIALOG_ITEMS, new CItemDlg);
		Common::DlgStore = m_TabMain.InsetPage(10, IDD_DIALOG_STORE, new CStoreDlg);
		m_TabMain.SetNumberOfPages(11);
	}
	else
	{
		m_TabMain.SetNumberOfPages(8);		
	}

	m_TabMain.SetCurrentPage(0);
}

void CHCSG_ManagerDlg::ToTray()
{
	NOTIFYICONDATA nid;

	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA); 
	nid.hWnd = this->m_hWnd; 
	nid.uID = IDR_MAINFRAME; 
	nid.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP ; 
	nid.uCallbackMessage = WM_SHOWTASK;//�Զ������Ϣ���� 
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME)); 
	strcpy_s(nid.szTip,_T("�ʳ�GM"));//��Ϣ��ʾ��Ϊ"�ƻ���������" 
	Shell_NotifyIcon(NIM_ADD,&nid);//�����������ͼ�� 
	ShowWindow(SW_HIDE);//����������
}

//wParam���յ���ͼ���ID����lParam���յ���������Ϊ 
LRESULT CHCSG_ManagerDlg::onShowTask(WPARAM wParam,LPARAM lParam)
{ 
	//	if(wParam!=IDR_MAINFRAME) 
	//		return 1; 
	switch(lParam) 
	{ 
	case WM_RBUTTONUP:
		{ 
			LPPOINT lpoint = new tagPOINT; 
			::GetCursorPos(lpoint); 
			CMenu menu; 
			menu.CreatePopupMenu();
			menu.AppendMenu(MF_STRING,SW_SHOW,_T("��ʾ����"));
			menu.AppendMenu(MF_STRING,WM_DESTROY,_T("�˳�"));
			//ȷ������ʽ�˵���λ�� 
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this); 
			//��Դ���� 
			HMENU hmenu=menu.Detach(); 
			menu.DestroyMenu(); 
			delete lpoint; 
		} 
		break; 
	case WM_LBUTTONDOWN:
		{ 
			this->ShowWindow(SW_SHOW);
		} 
		break; 
	} 
	return 0; 
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHCSG_ManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHCSG_ManagerDlg::OnBnClickedButtonConct()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(!Common::IsDbConct)
	{
		m_CeditIP.GetWindowText(Common::SQLServer);
		m_CeditAcc.GetWindowText(Common::SQLAccount);
		m_CeditPw.GetWindowText(Common::SQLPassWord);
		Common::IsEnConn = TRUE;
		Common::ConnToSQLServer();
		if(!Common::IsDbConct)
		{
			AfxMessageBox("�������ݿ�ʧ�ܣ�");
			Common::IsEnConn = FALSE;
			return;
		}
		m_CButtonConct.SetWindowText("�Ͽ�����");
		m_CStatic_stat.SetWindowText("���������ݿ⣡");
		m_CStatic_stat.SetTextColor(RGB(0,0,205));
		Common::IsEnConn = TRUE;
		Common::SaveConfig();
		
	}
	else
	{
		Common::ConnToSQLServer();
		m_CButtonConct.SetWindowText("�������");
		m_CStatic_stat.SetWindowText("δ�������ݿ⣡");
		m_CStatic_stat.SetTextColor(RGB(255,0,0));
		Common::IsEnConn = FALSE;
	}
}


void CHCSG_ManagerDlg::OnBnClickedButtonSacn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char szPath[MAX_PATH];     //���ѡ���Ŀ¼·�� 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));   

	BROWSEINFO bi;   
	bi.hwndOwner = m_hWnd;   
	bi.pidlRoot = NULL;   
	bi.pszDisplayName = szPath;   
	//bi.lpszTitle = INFO_CHOICE_DIR;  
	bi.lpszTitle = "";
	bi.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX;  
	bi.lpfn = NULL;   
	bi.lParam = 0;   
	bi.iImage = 0;   
	bi.hwndOwner = GetSafeHwnd();//��ȡ���ھ�� 
	//bi.pszDisplayName = (LPTSTR)buffer;//�˲������Ϊ�գ�������ʾ�Ի��� 
	//����ѡ��Ŀ¼�Ի���
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);   

	if(lp && SHGetPathFromIDList(lp, szPath))   
	{
		strcat_s(szPath, "\\");
		m_EditServerPath.SetWindowText(szPath);
		Common::ServerPath = szPath;
		Common::SaveConfig();
	}
}


void CHCSG_ManagerDlg::OnBnClickedButtonEnable()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(Common::SanGuoServerIsRuning)
	{
		m_CButtonEnable.SetWindowText("������");
		Common::SanGuoServerIsRuning = FALSE;
	}
	else
	{
		m_CButtonEnable.SetWindowText("��ֹ����");
		Common::SanGuoServerIsRuning = TRUE;
		Common::SaveConfig();
	}
}


void CHCSG_ManagerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent){
	case TIMER_UPDATE:
		{
			KillTimer(TIMER_UPDATE);
			SetTimer(TIMER_UPDATE, 60 * 1000, 0);  // ÿ�����Զ�����һ������ 
			//Common::SaveConfig();
			break;
		}
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CHCSG_ManagerDlg::OnBnClickedButtonReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	Common::Log(Info, "�ض�������ս�������ʱ�����ã�");
	Common::GetServerConfig();

	::SendMessage(Common::DlgCwarOrg, WM_CWARORGRESET, 0, NULL);
	::SendMessage(Common::DlgCwarPlayer, WM_CWARPLAYERRESET, 0, NULL);
	::SendMessage(Common::DlgCB, WM_CBAWARDSRESET, 0, NULL);
}
