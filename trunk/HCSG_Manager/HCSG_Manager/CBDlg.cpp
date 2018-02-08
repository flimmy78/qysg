// CBDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "afxdb.h"
#include "HCSG_Manager.h"
#include "CBDlg.h"
#include "afxdialogex.h"

#include <iostream>
using namespace std;


static CList <HistoryCbHeroes, HistoryCbHeroes&> LHistoryCbHeroes;


// CCBDlg �Ի���

IMPLEMENT_DYNAMIC(CCBDlg, CDialogEx)

	CCBDlg::CCBDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCBDlg::IDD, pParent)
{
	ExeStart = FALSE;
}

CCBDlg::~CCBDlg()
{
}

void CCBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ACC, m_CListCtrlAcc);
	DDX_Control(pDX, IDC_LIST_ITEM, m_CListCtrlItem);
	DDX_Control(pDX, IDC_LIST_CONFIG, m_CListCtrlConfig);
	DDX_Control(pDX, IDC_EDIT_FIND_ACC, m_CEditFindAcc);
	DDX_Control(pDX, IDC_EDIT_FIND_ITEM, m_CEditFindItem);
	DDX_Control(pDX, IDC_EDIT_DISPLAY_ACC, m_CEditDisplayAcc);
	DDX_Control(pDX, IDC_EDIT_DISPLAY_NAME, m_CEditDisplayName);
	DDX_Control(pDX, IDC_EDIT_ITEM_ID, m_CEditItemId);
	DDX_Control(pDX, IDC_EDIT_ITEM_ID2, m_CEditItemId2);
	DDX_Control(pDX, IDC_EDIT_ITEM_ID3, m_CEditItemId3);
	DDX_Control(pDX, IDC_EDIT_ITEM_ID4, m_CEditItemId4);
	DDX_Control(pDX, IDC_EDIT_ITEM_ID5, m_CEditItemId5);
	DDX_Control(pDX, IDC_EDIT_ITEM_NAME, m_CEditItemName);
	DDX_Control(pDX, IDC_EDIT_ITEM_NAME2, m_CEditItemName2);
	DDX_Control(pDX, IDC_EDIT_ITEM_NAME3, m_CEditItemName3);
	DDX_Control(pDX, IDC_EDIT_ITEM_NAME4, m_CEditItemName4);
	DDX_Control(pDX, IDC_EDIT_ITEM_NAME5, m_CEditItemName5);
	DDX_Control(pDX, IDC_EDIT_NUM, m_CEditItemNum);
	DDX_Control(pDX, IDC_EDIT_NUM2, m_CEditItemNum2);
	DDX_Control(pDX, IDC_EDIT_NUM3, m_CEditItemNum3);
	DDX_Control(pDX, IDC_EDIT_NUM4, m_CEditItemNum4);
	DDX_Control(pDX, IDC_EDIT_NUM5, m_CEditItemNum5);
	DDX_Control(pDX, IDC_COMBO_CONFIG_ID, m_CComboBoxCfgID);
	DDX_Control(pDX, IDC_STATIC_TIME, m_CStaticCbTime);
	DDX_Control(pDX, IDC_EDIT_RANK1, m_CEditRank1);
	DDX_Control(pDX, IDC_EDIT_RANK2, m_CEditRank2);
	DDX_Control(pDX, IDC_EDIT_MINKILLS, m_CEditMinKills);
	DDX_Control(pDX, IDC_EDIT_MINHONORS, m_CEditMinHonors);
	DDX_Control(pDX, IDC_CHECK_MINKILLS, m_CButtonMinKills);
	DDX_Control(pDX, IDC_CHECK_MINHONORS, m_CButtonMinHonors);
}


BEGIN_MESSAGE_MAP(CCBDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FIND_ACC, &CCBDlg::OnBnClickedButtonFindAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ACC, &CCBDlg::OnBnClickedButtonFindNextAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_ITEM, &CCBDlg::OnBnClickedButtonFindItem)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ITEM, &CCBDlg::OnBnClickedButtonFindNextItem)
	ON_BN_CLICKED(IDC_BUTTON_ADD_CONFIG, &CCBDlg::OnBnClickedButtonAddConfig)
	ON_BN_CLICKED(IDC_BUTTON_DEL_CONFIG, &CCBDlg::OnBnClickedButtonDelConfig)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CONFIG, &CCBDlg::OnBnClickedButtonSaveConfig)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_CONFIG, &CCBDlg::OnBnClickedButtonLoadConfig)
	ON_BN_CLICKED(IDC_BUTTON_EXE, &CCBDlg::OnBnClickedButtonExe)
	ON_BN_CLICKED(IDC_BUTTON_ADDTOSWAP, &CCBDlg::OnBnClickedButtonAddtoswap)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CCBDlg::OnBnClickedButtonInit)
	ON_EN_CHANGE(IDC_EDIT_RANK1, &CCBDlg::OnEnChangeEditRank1)
	ON_WM_TIMER()
	ON_MESSAGE(WM_SAVECBAWARDS, DoSaveConfig)
	ON_MESSAGE(WM_CBAWARDSRESET, DoResetConfig)
	ON_BN_CLICKED(IDC_CHECK_MINKILLS, &CCBDlg::OnBnClickedCheckMinkills)
	ON_BN_CLICKED(IDC_CHECK_MINHONORS, &CCBDlg::OnBnClickedCheckMinhonors)
	ON_EN_CHANGE(IDC_EDIT_MINKILLS, &CCBDlg::OnEnChangeEditMinkills)
	ON_EN_CHANGE(IDC_EDIT_MINHONORS, &CCBDlg::OnEnChangeEditMinhonors)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID, &CCBDlg::OnEnChangeEditItemId)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID2, &CCBDlg::OnEnChangeEditItemId2)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID3, &CCBDlg::OnEnChangeEditItemId3)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID4, &CCBDlg::OnEnChangeEditItemId4)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID5, &CCBDlg::OnEnChangeEditItemId5)
END_MESSAGE_MAP()


// CCBDlg ��Ϣ�������



BOOL CCBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_CListCtrlAcc.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlAcc.InsertColumn(0, _T("����"), LVCFMT_LEFT, 40);
	m_CListCtrlAcc.InsertColumn(1, _T("ע���ʺ�"), LVCFMT_LEFT, 70);
	m_CListCtrlAcc.InsertColumn(2, _T("��ɫ����"), LVCFMT_LEFT, 70);//������
	m_CListCtrlAcc.InsertColumn(3, _T("��ѫ"), LVCFMT_LEFT, 40);
	m_CListCtrlAcc.InsertColumn(4, _T("ɱ��"), LVCFMT_LEFT, 40);

	m_CListCtrlItem.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlItem.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);//������
	m_CListCtrlItem.InsertColumn(1, _T("��Ʒ����"), LVCFMT_LEFT, 190);

	m_CListCtrlConfig.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlConfig.InsertColumn(0, _T("��ʼ����"), LVCFMT_LEFT, 60);//������
	m_CListCtrlConfig.InsertColumn(1, _T("��������"), LVCFMT_LEFT, 60);

	m_CListCtrlConfig.InsertColumn(2, _T("��ƷID1"), LVCFMT_LEFT, 55);
	m_CListCtrlConfig.InsertColumn(3, _T("��Ʒ��1"), LVCFMT_LEFT, 100);  // ������Ʒ1
	m_CListCtrlConfig.InsertColumn(4, _T("����1"), LVCFMT_LEFT, 45);

	m_CListCtrlConfig.InsertColumn(5, _T("��ƷID2"), LVCFMT_LEFT, 55);
	m_CListCtrlConfig.InsertColumn(6, _T("��Ʒ��2"), LVCFMT_LEFT, 100);  // ������Ʒ2
	m_CListCtrlConfig.InsertColumn(7, _T("����2"), LVCFMT_LEFT, 45);

	m_CListCtrlConfig.InsertColumn(8, _T("��ƷID3"), LVCFMT_LEFT, 55);
	m_CListCtrlConfig.InsertColumn(9, _T("��Ʒ��3"), LVCFMT_LEFT, 100);  // ������Ʒ3
	m_CListCtrlConfig.InsertColumn(10, _T("����3"), LVCFMT_LEFT, 45);

	m_CListCtrlConfig.InsertColumn(11, _T("��ƷID4"), LVCFMT_LEFT, 55);
	m_CListCtrlConfig.InsertColumn(12, _T("��Ʒ��4"), LVCFMT_LEFT, 100);  // ������Ʒ4
	m_CListCtrlConfig.InsertColumn(13, _T("����4"), LVCFMT_LEFT, 45);

	m_CListCtrlConfig.InsertColumn(14, _T("��ƷID5"), LVCFMT_LEFT, 55);
	m_CListCtrlConfig.InsertColumn(15, _T("��Ʒ��5"), LVCFMT_LEFT, 100);  // ������Ʒ5
	m_CListCtrlConfig.InsertColumn(16, _T("����5"), LVCFMT_LEFT, 45);

	m_CEditItemNum.SetWindowText("1");
	m_CEditItemNum2.SetWindowText("1");
	m_CEditItemNum3.SetWindowText("1");
	m_CEditItemNum4.SetWindowText("1");
	m_CEditItemNum5.SetWindowText("1");

	m_CEditRank1.SetWindowText("1");
	m_CEditRank2.SetWindowText("3");

	m_CEditMinKills.SetWindowText((Common::m_CbMinKills.IsEmpty()) ? "5" : Common::m_CbMinKills);
	m_CEditMinHonors.SetWindowText((Common::m_CbMinHonors.IsEmpty()) ? "10" : Common::m_CbMinHonors);
	m_CButtonMinKills.SetCheck((Common::m_CbChkMinKills.IsEmpty()) ? FALSE : TRUE);
	m_CButtonMinHonors.SetCheck((Common::m_CbChkMinHonors.IsEmpty()) ? FALSE : TRUE);

	m_CComboBoxCfgID.SetCurSel(0);

	SetStateStatic(FALSE);

	OnBnClickedButtonInit();

	CString strFilePath="";
	::GetCurrentDirectory(1024,strFilePath.GetBuffer(1024));
	strFilePath.ReleaseBuffer();
	strFilePath += "\\AwardsConfig.xls";
	DoLoadConfig(strFilePath);

	OnBnClickedButtonExe();

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CCBDlg::SetStateStatic(BOOL IsStart)
{
	if(IsStart)
	{
		CString strResult;
		strResult = "���֮ս�����У�";
		m_CStaticCbTime.SetWindowText(strResult);
		CFont* pFont=GetFont();
		LOGFONT logFont={0};
		pFont->GetObject(sizeof(LOGFONT),&logFont);
		logFont.lfHeight=30; //�������������С
		m_CStaticCbTime.SetBold(TRUE);
		m_CStaticCbTime.SetFont(&logFont, 0);
		m_CStaticCbTime.SetTextColor(RGB(0,205,0));
	}
	else
	{
		CString strResult;
		strResult = "ս��δ��ʼ��";
		m_CStaticCbTime.SetWindowText(strResult);
		CFont* pFont=GetFont();
		LOGFONT logFont={0};
		pFont->GetObject(sizeof(LOGFONT),&logFont);
		logFont.lfHeight=36; //�������������С
		m_CStaticCbTime.SetBold(TRUE);
		m_CStaticCbTime.SetFont(&logFont, 0);
		m_CStaticCbTime.SetTextColor(RGB(255,0,0));
	}
}


void CCBDlg::GetHores()
{
	CString strPathName;
	int ret = 0;
	int GetValueStep = 0;
	int index;
	POSITION pos;
	struct AccAttr TmpAccAttr;
	CList <AccAttr, AccAttr&> *LCurAccAttr = &Common::LAccAttr;

	strPathName = Common::ServerPath + "Map\\history\\history_0351.txt";
	CString szLine = "";
	CString strGap = _T(",");
	CStringArray strResult;

	//����ļ��Ƿ����
	DWORD dwRe = GetFileAttributes(strPathName);
	if ( dwRe != (DWORD)-1 )
	{
		//ShellExecute(NULL, NULL, strFilePath, NULL, NULL, SW_RESTORE); 
	}
	else 
	{
		CString errormessage;
		errormessage.Format("�����ļ������ڣ�");
		Common::Log(Error, errormessage);
		return;
	}

	LHistoryCbHeroes.RemoveAll();
	//���ļ�
	CStdioFile StdFile;
	StdFile.Open(strPathName,CFile::modeRead | CFile::shareDenyNone | CFile::typeBinary);

	//���ж�ȡ�ַ���
	while( StdFile.ReadString( szLine ) )
	{
		strResult.RemoveAll();
		szLine.Replace('\t', ' ');
		szLine.Replace(_T(" "), _T(""));
		index = szLine.Find(';');
		if(index >= 0)
			szLine.Delete(szLine.Find(';'), szLine.GetLength() - szLine.Find(';'));
		if(0 != GetValueStep && szLine.Find("[last_result]") == 0) {
			GetValueStep = 0;
			continue;
		}
		if(0 == GetValueStep && szLine.Find("[last_result]") == 0) {
			GetValueStep++;
			continue;
		}
		if(1 == GetValueStep && szLine.Find("type=1") == 0)
		{
			GetValueStep++;
			continue;
		}


		if(2 == GetValueStep && szLine.Find("item=") == 0)
		{
			szLine.Replace(_T("item="), _T(""));
			int nPos = szLine.Find(strGap);
			CString strLeft = _T("");
			while(0 <= nPos)
			{
				strLeft = szLine.Left(nPos);
				if (!strLeft.IsEmpty())
					strResult.Add(strLeft);

				szLine = szLine.Right(szLine.GetLength() - nPos - 1);
				nPos = szLine.Find(strGap);
			}

			if (!szLine.IsEmpty()) {
				strResult.Add(szLine);
			}

			struct HistoryCbHeroes TmpHistoryCbHeroes;
			TmpHistoryCbHeroes.Name = strResult[0];
			TmpHistoryCbHeroes.Job = strResult[1];
			TmpHistoryCbHeroes.Nationality = strResult[2];
			TmpHistoryCbHeroes.Honor = strResult[3];
			TmpHistoryCbHeroes.Points = strResult[4];
			TmpHistoryCbHeroes.Kills = strResult[5];
			if(LHistoryCbHeroes.GetCount() == 0)
				LHistoryCbHeroes.AddTail(TmpHistoryCbHeroes);
			else
			{
				int i;
				pos = LHistoryCbHeroes.GetHeadPosition();
				for (i=0;i < LHistoryCbHeroes.GetCount();i++)
				{
					POSITION curPos = pos;
					HistoryCbHeroes temp = LHistoryCbHeroes.GetNext(pos);
					if(_ttoi(TmpHistoryCbHeroes.Honor) > _ttoi(temp.Honor))
					{
						LHistoryCbHeroes.InsertBefore(curPos, TmpHistoryCbHeroes);
						break;
					}
				}
				if(i == LHistoryCbHeroes.GetCount())
					LHistoryCbHeroes.AddTail(TmpHistoryCbHeroes);
			}
		}
	}
	//�ر��ļ�
	StdFile.Close();

	m_CListCtrlAcc.DeleteAllItems();

	//����õ�Ӣ�۰���ʾ��ClistCtrl��ȥ
	pos = LHistoryCbHeroes.GetHeadPosition();
	for (int i=0;i < LHistoryCbHeroes.GetCount();i++)
	{
		struct HistoryCbHeroes TmpHistoryCbHeroes = LHistoryCbHeroes.GetNext(pos);

		int nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
		int nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));
		CString ForItoStr;
		ForItoStr.Format("%d", i+1);
		m_CListCtrlAcc.SetItemText(nItem, 0, ForItoStr);
		POSITION pos2 = LCurAccAttr->GetHeadPosition();
		for (int j=0;j < LCurAccAttr->GetCount();j++)
		{
			TmpAccAttr = LCurAccAttr->GetNext(pos2);
			if(0 == strcmp(TmpAccAttr.Name, TmpHistoryCbHeroes.Name))
				m_CListCtrlAcc.SetItemText(nItem, 1, _T(TmpAccAttr.Account));
		}
		m_CListCtrlAcc.SetItemText(nItem, 2, _T(Common::Big2GB((LPSTR)(LPCTSTR)TmpHistoryCbHeroes.Name)));
		m_CListCtrlAcc.SetItemText(nItem, 3, _T(TmpHistoryCbHeroes.Honor));
		m_CListCtrlAcc.SetItemText(nItem, 4, _T(TmpHistoryCbHeroes.Kills));
	}
}


void CCBDlg::OnBnClickedButtonFindAcc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strKey;
	int iColumnNum,iRowCount;
	char chTemp[32];
	int ListIndex = 0;

	m_CEditFindAcc.GetWindowText(strKey);
	if(strKey.IsEmpty()) return;

	iColumnNum = m_CListCtrlAcc.GetHeaderCtrl()->GetItemCount();
	iRowCount = m_CListCtrlAcc.GetItemCount();

	for (int j=0 ; j<iRowCount ; j++ )
	{
		memset(chTemp, 0 ,32);
		for ( int i=0 ; i<iColumnNum ; i++ )
		{
			m_CListCtrlAcc.GetItemText(j,i,chTemp, 32);
			if(strstr(chTemp,strKey))
			{
				ListIndex = j;
				goto BreakLoop;
			}
		}
	}
BreakLoop:
	m_CListCtrlAcc.SetFocus();  
	m_CListCtrlAcc.SetItemState(ListIndex, LVIS_SELECTED, LVIS_SELECTED);
	m_CListCtrlAcc.SetSelectionMark(ListIndex);
	m_CListCtrlAcc.EnsureVisible(ListIndex, FALSE);
	::SendMessage(m_CListCtrlAcc.m_hWnd,  LVM_SETEXTENDEDLISTVIEWSTYLE,  
		LVS_EX_FULLROWSELECT,  LVS_EX_FULLROWSELECT); 
}


void CCBDlg::OnBnClickedButtonFindNextAcc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strKey;
	int iColumnNum,iRowCount;
	char chTemp[32];
	int ListIndex = 0;
	int iCurListIndex  = m_CListCtrlAcc.GetSelectionMark();

	m_CEditFindAcc.GetWindowText(strKey);
	if(strKey.IsEmpty()) return;

	iColumnNum = m_CListCtrlAcc.GetHeaderCtrl()->GetItemCount();
	iRowCount = m_CListCtrlAcc.GetItemCount();

	int j = iCurListIndex + 1;
	do
	{
		memset(chTemp, 0 ,32);
		for ( int i=0 ; i<iColumnNum ; i++ )
		{
			m_CListCtrlAcc.GetItemText(j,i,chTemp, 32);
			if(strstr(chTemp,strKey))
			{
				ListIndex = j;
				goto BreakLoop;
			}
		}
		if(j == iRowCount) 
			j = -1;
	}while(j != iCurListIndex && (j++ || j!=0));
BreakLoop:
	m_CListCtrlAcc.SetFocus();  
	m_CListCtrlAcc.SetItemState(ListIndex, LVIS_SELECTED, LVIS_SELECTED);
	m_CListCtrlAcc.SetSelectionMark(ListIndex);
	m_CListCtrlAcc.EnsureVisible(ListIndex, FALSE);
	::SendMessage(m_CListCtrlAcc.m_hWnd,  LVM_SETEXTENDEDLISTVIEWSTYLE,  
		LVS_EX_FULLROWSELECT,  LVS_EX_FULLROWSELECT); 
}


void CCBDlg::OnBnClickedButtonFindItem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strKey;
	int iColumnNum,iRowCount;
	char chTemp[32];
	int ListIndex = 0;

	m_CEditFindItem.GetWindowText(strKey);
	if(strKey.IsEmpty()) return;

	iColumnNum = m_CListCtrlItem.GetHeaderCtrl()->GetItemCount();
	iRowCount = m_CListCtrlItem.GetItemCount();

	for (int j=0 ; j<iRowCount ; j++ )
	{
		memset(chTemp, 0 ,32);
		for ( int i=0 ; i<iColumnNum ; i++ )
		{
			m_CListCtrlItem.GetItemText(j,i,chTemp, 32);
			if(strstr(chTemp,strKey))
			{
				ListIndex = j;
				goto BreakLoop;
			}
		}
	}
BreakLoop:
	m_CListCtrlItem.SetFocus();  
	m_CListCtrlItem.SetItemState(ListIndex, LVIS_SELECTED, LVIS_SELECTED);
	m_CListCtrlItem.SetSelectionMark(ListIndex);
	m_CListCtrlItem.EnsureVisible(ListIndex, FALSE);
	::SendMessage(m_CListCtrlItem.m_hWnd,  LVM_SETEXTENDEDLISTVIEWSTYLE,  
		LVS_EX_FULLROWSELECT,  LVS_EX_FULLROWSELECT); 
}


void CCBDlg::OnBnClickedButtonFindNextItem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strKey;
	int iColumnNum,iRowCount;
	char chTemp[32];
	int ListIndex = 0;
	int iCurListIndex  = m_CListCtrlItem.GetSelectionMark();

	m_CEditFindItem.GetWindowText(strKey);
	if(strKey.IsEmpty()) return;

	iColumnNum = m_CListCtrlItem.GetHeaderCtrl()->GetItemCount();
	iRowCount = m_CListCtrlItem.GetItemCount();

	int j = iCurListIndex + 1;
	do
	{
		memset(chTemp, 0 ,32);
		for ( int i=0 ; i<iColumnNum ; i++ )
		{
			m_CListCtrlItem.GetItemText(j,i,chTemp, 32);
			if(strstr(chTemp,strKey))
			{
				ListIndex = j;
				goto BreakLoop;
			}
		}
		if(j == iRowCount) 
			j = -1;
	}while(j != iCurListIndex && (j++ || j!=0));
BreakLoop:
	m_CListCtrlItem.SetFocus();  
	m_CListCtrlItem.SetItemState(ListIndex, LVIS_SELECTED, LVIS_SELECTED);
	m_CListCtrlItem.SetSelectionMark(ListIndex);
	m_CListCtrlItem.EnsureVisible(ListIndex, FALSE);
	::SendMessage(m_CListCtrlItem.m_hWnd,  LVM_SETEXTENDEDLISTVIEWSTYLE,  
		LVS_EX_FULLROWSELECT,  LVS_EX_FULLROWSELECT);  
}


void CCBDlg::OnBnClickedButtonAddConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strRank1, strRank2;
	CString strItem, strNum, strItem2, strNum2, strItem3, strNum3, strItem4, strNum4, strItem5, strNum5;
	CString strItemName, strItemName2, strItemName3, strItemName4, strItemName5;

	// ����
	m_CEditRank1.GetWindowTextA(strRank1);
	m_CEditRank2.GetWindowTextA(strRank2);

	//��Ʒ1
	m_CEditItemId.GetWindowTextA(strItem);
	m_CEditItemName.GetWindowTextA(strItemName);
	m_CEditItemNum.GetWindowTextA(strNum);
	//��Ʒ2
	m_CEditItemId2.GetWindowTextA(strItem2);
	m_CEditItemName2.GetWindowTextA(strItemName2);
	m_CEditItemNum2.GetWindowTextA(strNum2);
	//��Ʒ3
	m_CEditItemId3.GetWindowTextA(strItem3);
	m_CEditItemName3.GetWindowTextA(strItemName3);
	m_CEditItemNum3.GetWindowTextA(strNum3);
	//��Ʒ4
	m_CEditItemId4.GetWindowTextA(strItem4);
	m_CEditItemName4.GetWindowTextA(strItemName4);
	m_CEditItemNum4.GetWindowTextA(strNum4);
	//��Ʒ5
	m_CEditItemId5.GetWindowTextA(strItem5);
	m_CEditItemName5.GetWindowTextA(strItemName5);
	m_CEditItemNum5.GetWindowTextA(strNum5);

	if(strItem.IsEmpty()){	strItemName = ""; strNum = "";}
	if(strItem2.IsEmpty()){	strItemName2 = ""; strNum2 = "";}
	if(strItem3.IsEmpty()){	strItemName3 = ""; strNum3 = "";}
	if(strItem4.IsEmpty()){	strItemName4 = ""; strNum4 = "";}
	if(strItem5.IsEmpty()){	strItemName5 = ""; strNum5 = "";}

	if(strRank1.IsEmpty() || strRank2.IsEmpty() || (strItem.IsEmpty() && strItem2.IsEmpty() 
		&& strItem3.IsEmpty() && strItem4.IsEmpty() && strItem5.IsEmpty()))
		return;

	int nrow = m_CListCtrlConfig.GetItemCount();//ȡ����
	int nItem = m_CListCtrlConfig.InsertItem(nrow+1, _T(""));
	m_CListCtrlConfig.SetItemText(nItem, 0, strRank1);
	m_CListCtrlConfig.SetItemText(nItem, 1, strRank2);
	m_CListCtrlConfig.SetItemText(nItem, 2, strItem);
	m_CListCtrlConfig.SetItemText(nItem, 3, strItemName);
	m_CListCtrlConfig.SetItemText(nItem, 4, strNum);
	m_CListCtrlConfig.SetItemText(nItem, 5, strItem2);
	m_CListCtrlConfig.SetItemText(nItem, 6, strItemName2);
	m_CListCtrlConfig.SetItemText(nItem, 7, strNum2);
	m_CListCtrlConfig.SetItemText(nItem, 8, strItem3);
	m_CListCtrlConfig.SetItemText(nItem, 9, strItemName3);
	m_CListCtrlConfig.SetItemText(nItem, 10, strNum3);
	m_CListCtrlConfig.SetItemText(nItem, 11, strItem4);
	m_CListCtrlConfig.SetItemText(nItem, 12, strItemName4);
	m_CListCtrlConfig.SetItemText(nItem, 13, strNum4);
	m_CListCtrlConfig.SetItemText(nItem, 14, strItem5);
	m_CListCtrlConfig.SetItemText(nItem, 15, strItemName5);
	m_CListCtrlConfig.SetItemText(nItem, 16, strNum5);

	OnBnClickedButtonSaveConfig();
}


void CCBDlg::OnBnClickedButtonDelConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ListIndex  = m_CListCtrlConfig.GetSelectionMark();
	if(ListIndex == -1) return;
	m_CListCtrlConfig.DeleteItem(ListIndex);//ɾ��ѡ����

	OnBnClickedButtonSaveConfig();
}


void CCBDlg::OnBnClickedButtonSaveConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if ( m_CListCtrlConfig.GetItemCount()<= 0 )
	{
		Common::Log(Error, "�б���û�м�¼��Ҫ���棡");
		return;
	}
	Common::SaveAwardsConfig();
}


LRESULT CCBDlg::DoSaveConfig(WPARAM wParam, LPARAM lParam)
{
	CDatabase database;//���ݿ����Ҫ����ͷ�ļ� #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel����
	CString sSql,strInsert;
	CString strFilePath = *((CString*)lParam);
	TRY
	{
		// �������д�ȡ���ַ���
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, strFilePath, strFilePath);

		// �������ݿ� (��Excel����ļ�)
		if( database.OpenEx(sSql,CDatabase::noOdbcDialog) )
		{
			//����б��������
			int iColumnNum,iRowCount;
			LVCOLUMN lvCol;
			CString strColName; //���ڱ����б�������
			int i,j; //�С���ѭ������

			iColumnNum = m_CListCtrlConfig.GetHeaderCtrl()->GetItemCount();
			iRowCount = m_CListCtrlConfig.GetItemCount();
			sSql = " CREATE TABLE ���Ӣ�۽��� ( ";
			strInsert = " INSERT INTO ���Ӣ�۽��� ( " ;
			//����б�������
			lvCol.mask = LVCF_TEXT; //�������ã�˵��LVCOLUMN������pszText������Ч
			lvCol.cchTextMax = 32; //���裬pszText������ָ����ַ����Ĵ�С
			lvCol.pszText = strColName.GetBuffer(32); //���裬pszText ��ָ����ַ�����ʵ�ʴ洢λ�á�
			//���������������ú����ͨ�� GetColumn()��������б��������
			for( i=0 ; i< iColumnNum ; i++ )
			{
				if ( !(m_CListCtrlConfig.GetColumn(i,&lvCol)) )
					return -1;
				if ( i<iColumnNum-1 )
				{
					sSql = sSql + lvCol.pszText + " TEXT , ";
					strInsert = strInsert + lvCol.pszText + " , ";
				}
				else
				{
					sSql = sSql + lvCol.pszText + " TEXT ) ";
					strInsert = strInsert + lvCol.pszText + " )  VALUES ( ";
				}
			}
			//����Excel����ļ�
			database.ExecuteSQL(sSql);
			//ѭ����ȡ��¼�����뵽EXCEL��
			sSql = strInsert;
			char chTemp[33];
			for ( j=0 ; j<iRowCount ; j++ )
			{
				memset(chTemp,0,32);
				for ( i=0 ; i<iColumnNum ; i++ )
				{
					m_CListCtrlConfig.GetItemText(j,i,chTemp,33);
					if ( i < (iColumnNum-1) )
					{
						sSql = sSql + "'" + chTemp + "' , ";
					}
					else
					{
						sSql = sSql + "'" + chTemp + "' ) ";
					}
				}
				//����¼���뵽�����
				database.ExecuteSQL(sSql);
				sSql = strInsert; 
			}
		}     
		// �ر�Excel����ļ�
		database.Close();
		Common::Log(Info, "������Ӣ�۽������óɹ���");
	}
	CATCH_ALL(e)
	{
		//�������ͺܶ࣬������Ҫ���б���
		Common::Log(Error, "��ڽ������ñ���ʧ�ܡ�");
	}
	END_CATCH_ALL;

	return 0;
}


void CCBDlg::OnBnClickedButtonLoadConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg( TRUE, //TRUE��FALSE��TRUEΪ���ļ���FALSEΪ�����ļ�
		"xls", //Ϊȱʡ����չ��
		"", //Ϊ��ʾ���ļ�����Ͽ�ı༭����ļ�����һ���ѡNULL 
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,//Ϊ�Ի�����һ��ΪOFN_HIDEREADONLY   |   OFN_OVERWRITEPROMPT,������ֻ��ѡ��͸��������ļ�ǰ��ʾ�� 
		"Excel �ļ�(*.xls)|*.xls||"//Ϊ�����б�������ʾ�ļ�����
		);
	dlg.m_ofn.lpstrTitle = "��������";

	if (dlg.DoModal() != IDOK)
		return;
	CString strFilePath;
	//����ļ�·����
	strFilePath = dlg.GetPathName();
	//�ж��ļ��Ƿ��Ѿ����ڣ���������ļ�

	if(DoLoadConfig(strFilePath))
		MessageBox("������Ϣ�ɹ�����ϵͳ!","����ɹ�");
	else
		MessageBox("������Ϣ����ϵͳʧ��!","����ʧ��");
}

BOOL CCBDlg::DoLoadConfig(CString strFilePath)
{
	DWORD dwRe = GetFileAttributes(strFilePath);
	if ( dwRe != (DWORD)-1 )
	{
		//ShellExecute(NULL, NULL, strFilePath, NULL, NULL, SW_RESTORE); 
	}
	else return FALSE;
	CDatabase db;//���ݿ����Ҫ����ͷ�ļ� #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel����
	CString sSql,arr[17];
	sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%s\";DBQ=%s",sDriver, strFilePath, strFilePath);
	if(!db.OpenEx(sSql,CDatabase::noOdbcDialog))//��������ԴDJB��xls
	{
		//MessageBox("�������ļ�ʧ��!","����");
		return FALSE;
	}
	//��EXCEL��
	CRecordset pset(&db);
	m_CListCtrlConfig.DeleteAllItems();
	/* sSql = "SELECT ѧ��,����,�ɼ� "       
	"FROM EXCELDEMO";      */          
	// "ORDER BY ����";
	sSql.Format("SELECT ��ʼ���� , �������� , ��ƷID1 , ��Ʒ��1 , ����1 , ��ƷID2 , ��Ʒ��2 , ����2 ,"
		" ��ƷID3 , ��Ʒ��3 , ����3 , ��ƷID4 , ��Ʒ��4 , ����4 , ��ƷID5 , ��Ʒ��5 , ����5 FROM ���Ӣ�۽���");
	pset.Open(CRecordset::forwardOnly,sSql,CRecordset::readOnly);
	while(!pset.IsEOF())
	{
		pset.GetFieldValue("��ʼ����",arr[0]);//ǰ���ֶα�������е���ͬ���������
		pset.GetFieldValue("��������",arr[1]);

		pset.GetFieldValue("��ƷID1",arr[2]);
		pset.GetFieldValue("��Ʒ��1",arr[3]);
		pset.GetFieldValue("����1",arr[4]);

		pset.GetFieldValue("��ƷID2",arr[5]);
		pset.GetFieldValue("��Ʒ��2",arr[6]);
		pset.GetFieldValue("����2",arr[7]);

		pset.GetFieldValue("��ƷID3",arr[8]);
		pset.GetFieldValue("��Ʒ��3",arr[9]);
		pset.GetFieldValue("����3",arr[10]);

		pset.GetFieldValue("��ƷID4",arr[11]);
		pset.GetFieldValue("��Ʒ��4",arr[12]);
		pset.GetFieldValue("����4",arr[13]);

		pset.GetFieldValue("��ƷID5",arr[14]);
		pset.GetFieldValue("��Ʒ��5",arr[15]);
		pset.GetFieldValue("����5",arr[16]);

		int nItem = m_CListCtrlConfig.GetItemCount();//���뵽ListCtrl��
		int count = m_CListCtrlConfig.InsertItem(nItem,arr[0]);
		m_CListCtrlConfig.InsertItem(count,arr[0]);
		m_CListCtrlConfig.SetItemText(count,1,arr[1]);

		m_CListCtrlConfig.SetItemText(count,2,arr[2]);
		m_CListCtrlConfig.SetItemText(count,3,arr[3]);
		m_CListCtrlConfig.SetItemText(count,4,arr[4]);

		m_CListCtrlConfig.SetItemText(count,5,arr[5]);
		m_CListCtrlConfig.SetItemText(count,6,arr[6]);
		m_CListCtrlConfig.SetItemText(count,7,arr[7]);

		m_CListCtrlConfig.SetItemText(count,8,arr[8]);
		m_CListCtrlConfig.SetItemText(count,9,arr[9]);
		m_CListCtrlConfig.SetItemText(count,10,arr[10]);

		m_CListCtrlConfig.SetItemText(count,11,arr[11]);
		m_CListCtrlConfig.SetItemText(count,12,arr[12]);
		m_CListCtrlConfig.SetItemText(count,13,arr[13]);

		m_CListCtrlConfig.SetItemText(count,14,arr[14]);
		m_CListCtrlConfig.SetItemText(count,15,arr[15]);
		m_CListCtrlConfig.SetItemText(count,16,arr[16]);

		pset.MoveNext();
	}
	db.Close();

	return TRUE;
}


void CCBDlg::StartTimer(CStringArray *StartTimes)
{
	CTime CurTime = CTime::GetCurrentTime();
	int y=CurTime.GetYear(); //��ȡ���
	int m=CurTime.GetMonth(); //��ȡ��ǰ�·�
	int d=CurTime.GetDay(); //��ü���
	int h=CurTime.GetHour(); //��ȡ��ǰΪ��ʱ
	int mm=CurTime.GetMinute(); //��ȡ����

	CString strCurSystemTime;
	strCurSystemTime.Format("%02d:%02d", h, mm);

	int i;
	for(i = 0; i < StartTimes->GetCount(); i++)
	{
		if(StartTimes->GetAt(i) > strCurSystemTime)
			break;
	}
	if(i < StartTimes->GetCount())
	{
		enHandle = TRUE;
		CString strWarStartTime = StartTimes->GetAt(i);
		Common::Log(Info, "�´γ��ʱ�䣺" + strWarStartTime);
		int  tmp_h, tmp_mm;
		sscanf_s(strWarStartTime.GetBuffer(strWarStartTime.GetLength()),
			"%d:%d", &tmp_h, &tmp_mm); 
		CTime WarStartTime(y, m, d, tmp_h, tmp_mm, 0);
		CTimeSpan DelayTime = WarStartTime - CurTime;
		SetTimer(TIMER1, (UINT)DelayTime.GetTotalSeconds() * 1000, 0);
		//SetTimer(TIMER1, 3 * 1000, 0); // for test
	}
	else
	{
		enHandle = FALSE;
		CTime WarStartTime(y, m, d+1, 0, 0, 0);
		CTimeSpan DelayTime = WarStartTime - CurTime;
		SetTimer(TIMER1, (UINT)DelayTime.GetTotalSeconds() * 1000, 0);
	}

}


void CCBDlg::DoButtonExe()
{
	ServerConfigTime *CurTimeForCB = &Common::TimeForCB;
	CTime CurTime = CTime::GetCurrentTime();
	int DayOfWeek = CurTime.GetDayOfWeek(); //��ȡ���ڼ���ע��1Ϊ�����죬7Ϊ������

	switch (DayOfWeek)
	{
	case 1:
		{
			StartTimer(&CurTimeForCB->SunStartTimes);
			break;
		}
	case 2:
		{
			StartTimer(&CurTimeForCB->ModStartTimes);
			break;
		}
	case 3:
		{
			StartTimer(&CurTimeForCB->TuseStartTimes);
			break;
		}
	case 4:
		{
			StartTimer(&CurTimeForCB->WedStartTimes);
			break;
		}
	case 5:
		{
			StartTimer(&CurTimeForCB->ThursStartTimes);
			break;
		}

	case 6:
		{
			StartTimer(&CurTimeForCB->FriStartTimes);
			break;
		}
	case 7:
		{
			StartTimer(&CurTimeForCB->SatStartTimes);
			break;
		}
	default:
		break;
	}
}


void CCBDlg::OnBnClickedButtonExe()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DoButtonExe();

	if(ExeStart)
	{
		GetDlgItem(IDC_BUTTON_EXE)->SetWindowText("�����Զ�ģʽ");
		Common::Log(Info, "��ڽ������ֹͣ");
		ExeStart = FALSE;
	}
	else
	{
		GetDlgItem(IDC_BUTTON_EXE)->SetWindowText("ֹͣ�Զ�ģʽ");
		Common::Log(Info, "��ڽ�����⿪ʼ");
		ExeStart = TRUE;
	}
}


void CCBDlg::OnBnClickedButtonAddtoswap()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ListIndex = m_CListCtrlItem.GetSelectionMark();
	if(ListIndex == -1) return;
	switch (m_CComboBoxCfgID.GetCurSel())
	{
	case 0:
		{
			m_CEditItemId.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));
			m_CEditItemName.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 1));
			break;
		}
	case 1:
		{
			m_CEditItemId2.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));
			m_CEditItemName2.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 1));
			break;
		}
	case 2:
		{
			m_CEditItemId3.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));
			m_CEditItemName3.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 1));
			break;
		}
	case 3:
		{
			m_CEditItemId4.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));
			m_CEditItemName4.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 1));
			break;
		}
	case 4:
		{
			m_CEditItemId5.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));
			m_CEditItemName5.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 1));
			break;
		}
	default:
		break;
	}
}


void CCBDlg::OnBnClickedButtonInit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	int ret = 0;
	POSITION pos;

	m_CListCtrlItem.DeleteAllItems();

	//����õ���Ʒ��ʾ��ClistCtrl��ȥ
	pos = LCurItemDef->GetHeadPosition();
	for (int i=0;i < LCurItemDef->GetCount();i++)
	{
		TmpItemDef = LCurItemDef->GetNext(pos);

		int nrow = m_CListCtrlItem.GetItemCount();//ȡ����
		int nItem = m_CListCtrlItem.InsertItem(nrow+1, _T(""));
		m_CListCtrlItem.SetItemText(nItem, 0, _T(TmpItemDef.ID));
		CString tempName = TmpItemDef.Name;
		tempName.Replace("item_", "");
		m_CListCtrlItem.SetItemText(nItem, 1, _T(Common::Big2GB((LPSTR)(LPCTSTR)tempName)));
	}
}


void CCBDlg::OnEnChangeEditRank1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString StrValue, StrValue2;
	m_CEditRank1.GetWindowText(StrValue);
	m_CEditRank2.GetWindowText(StrValue2);
	if(_ttoi(StrValue) > _ttoi(StrValue2))
		m_CEditRank2.SetWindowText(StrValue);
}


void CCBDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(!enHandle)
	{
		Sleep(1000);
		DoButtonExe();
		CDialogEx::OnTimer(nIDEvent);
		return;
	}

	switch(nIDEvent){
	case TIMER1:
		{
			SetStateStatic(TRUE);
			KillTimer(TIMER1);
			Common::Log(Info, "���֮ս��ʼ��");
			SetTimer(TIMER2, _ttoi(Common::TimeForCB.Period) * 60 * 1000, 0);
			//SetTimer(TIMER2, 8 * 1000, 0); // for test
			break;
		}
	case TIMER2:
		{
			SetStateStatic(FALSE);
			KillTimer(TIMER2);
			Common::Log(Info, "���֮ս������");
			SetTimer(TIMER3, 3 * 60 * 1000, 0); // �Ƴ�3���ӷ���

			//SetTimer(TIMER3, 7 * 1000, 0); // for test
			break;
		}
	case TIMER3:
		{
			SetStateStatic(FALSE);
			KillTimer(TIMER3);
			GetHores();
			PaymentOfAwards();
			DoButtonExe();
			break;
		}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CCBDlg::PaymentOfAwards()
{
	if(!Common::SanGuoServerIsRuning)
		return;

	int iColumnNumAcc,iRowCountAcc;
	int iColumnNumConfig,iRowCountConfig;
	CString strAccount, strItem, strNum, strItem2, strNum2, strItem3, strNum3, strItem4, strNum4, strItem5, strNum5;
	int nRanking;

	Common::Log(Info, "��ڽ������ſ�ʼ");

	iColumnNumAcc = m_CListCtrlAcc.GetHeaderCtrl()->GetItemCount();
	iRowCountAcc = m_CListCtrlAcc.GetItemCount();

	iColumnNumConfig = m_CListCtrlConfig.GetHeaderCtrl()->GetItemCount();
	iRowCountConfig = m_CListCtrlConfig.GetItemCount();

	for(int i = 0; i < iRowCountAcc; i++)
	{
		m_CEditMinKills.GetWindowText(Common::m_CbMinKills);
		m_CEditMinHonors.GetWindowText(Common::m_CbMinHonors);
		strAccount = m_CListCtrlAcc.GetItemText(i, 1); // ��ý�ɫ�˻�
		nRanking = _ttoi(m_CListCtrlAcc.GetItemText(i, 0)); // �������
		CString strTemp;
		strTemp = m_CListCtrlAcc.GetItemText(i, 3);  // ��ѫֵ��Ҫ�������Ҫ��		
		if((strTemp == "0") || (m_CButtonMinHonors.GetCheck() && _ttoi(strTemp) < _ttoi(Common::m_CbMinHonors)))
			continue;
		strTemp = m_CListCtrlAcc.GetItemText(i, 4);  // ɱ������Ҫ�������Ҫ��
		if((strTemp == "0") || (m_CButtonMinKills.GetCheck() && _ttoi(strTemp) < _ttoi(Common::m_CbMinKills)))
			continue;

		for (int j=0 ; j<iRowCountConfig ; j++ )
		{
			CString strTemp, strTemp2;
			strTemp = m_CListCtrlConfig.GetItemText(j,0);
			strTemp2 = m_CListCtrlConfig.GetItemText(j,1);
			if(_ttoi(strTemp) <= nRanking && _ttoi(strTemp2) >= nRanking)
			{
				strItem = m_CListCtrlConfig.GetItemText(j,2);
				strNum = m_CListCtrlConfig.GetItemText(j,4);

				strItem2 = m_CListCtrlConfig.GetItemText(j,5);
				strNum2 = m_CListCtrlConfig.GetItemText(j,7);

				strItem3 = m_CListCtrlConfig.GetItemText(j,8);
				strNum3 = m_CListCtrlConfig.GetItemText(j,10);

				strItem4 = m_CListCtrlConfig.GetItemText(j,11);
				strNum4 = m_CListCtrlConfig.GetItemText(j,13);

				strItem5 = m_CListCtrlConfig.GetItemText(j,14);
				strNum5 = m_CListCtrlConfig.GetItemText(j,16);

				if(strItem.IsEmpty())	strNum = "";
				if(strItem2.IsEmpty())	strNum2 = "";
				if(strItem3.IsEmpty())	strNum3 = "";
				if(strItem4.IsEmpty())	strNum4 = "";
				if(strItem5.IsEmpty())	strNum5 = "";

				if(strAccount.IsEmpty() || (strItem.IsEmpty() && strItem2.IsEmpty() 
					&& strItem3.IsEmpty() && strItem4.IsEmpty() && strItem5.IsEmpty()))
					continue;

				CStringArray ItemList;
				ItemList.Add(strItem);
				ItemList.Add(strNum);
				ItemList.Add(strItem2);
				ItemList.Add(strNum2);
				ItemList.Add(strItem3);
				ItemList.Add(strNum3);
				ItemList.Add(strItem4);
				ItemList.Add(strNum4);
				ItemList.Add(strItem5);
				ItemList.Add(strNum5);

				if(!Common::SendXubao(strAccount, &ItemList))
				{
					Common::Log(Error, "���ų�ڽ���ʧ��");
				}
			}
		}
	}
	Common::Log(Info, "��ڽ������Ž���");
}


void CCBDlg::OnBnClickedCheckMinkills()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Common::m_CbChkMinKills = m_CButtonMinKills.GetCheck() ? "1" : "";
	Common::SaveConfig();
}


void CCBDlg::OnBnClickedCheckMinhonors()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Common::m_CbChkMinHonors = m_CButtonMinHonors.GetCheck() ? "1" : "";
	Common::SaveConfig();
}


void CCBDlg::OnEnChangeEditMinkills()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_CEditMinKills.GetWindowText(Common::m_CbMinKills);
	Common::SaveConfig();
}


void CCBDlg::OnEnChangeEditMinhonors()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_CEditMinHonors.GetWindowText(Common::m_CbMinHonors);
	Common::SaveConfig();
}


void CCBDlg::LocalConfigSave()
{
	m_CEditMinKills.GetWindowText(Common::m_CbMinKills);
	m_CEditMinHonors.GetWindowText(Common::m_CbMinHonors);
	Common::m_CbChkMinKills = m_CButtonMinKills.GetCheck() ? "1" : "";
	Common::m_CbChkMinHonors = m_CButtonMinHonors.GetCheck() ? "1" : "";
	Common::SaveConfig();
}


void CCBDlg::OnEnChangeEditItemId()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	POSITION pos;
	int i;

	CString strItemId;
	m_CEditItemId.GetWindowText(strItemId);

	//ȷ����Ʒ�Ƿ����
	if(!strItemId.IsEmpty())
	{
		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			if(strItemId == TmpItemDef.ID)
			{
				CString tempName = TmpItemDef.Name;
				tempName.Replace("item_", "");

				m_CEditItemName.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditItemName.SetWindowText("");
		}
	}
	else
	{
		m_CEditItemName.SetWindowText("");
	}
}


void CCBDlg::OnEnChangeEditItemId2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	POSITION pos;
	int i;

	CString strItemId;
	m_CEditItemId2.GetWindowText(strItemId);

	//ȷ����Ʒ�Ƿ����
	if(!strItemId.IsEmpty())
	{
		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			if(strItemId == TmpItemDef.ID)
			{
				CString tempName = TmpItemDef.Name;
				tempName.Replace("item_", "");

				m_CEditItemName2.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditItemName2.SetWindowText("");
		}
	}
	else
	{
		m_CEditItemName2.SetWindowText("");
	}
}


void CCBDlg::OnEnChangeEditItemId3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	POSITION pos;
	int i;

	CString strItemId;
	m_CEditItemId3.GetWindowText(strItemId);

	//ȷ����Ʒ�Ƿ����
	if(!strItemId.IsEmpty())
	{
		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			if(strItemId == TmpItemDef.ID)
			{
				CString tempName = TmpItemDef.Name;
				tempName.Replace("item_", "");

				m_CEditItemName3.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditItemName3.SetWindowText("");
		}
	}
	else
	{
		m_CEditItemName3.SetWindowText("");
	}
}


void CCBDlg::OnEnChangeEditItemId4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	POSITION pos;
	int i;

	CString strItemId;
	m_CEditItemId4.GetWindowText(strItemId);

	//ȷ����Ʒ�Ƿ����
	if(!strItemId.IsEmpty())
	{
		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			if(strItemId == TmpItemDef.ID)
			{
				CString tempName = TmpItemDef.Name;
				tempName.Replace("item_", "");

				m_CEditItemName4.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditItemName4.SetWindowText("");
		}
	}
	else
	{
		m_CEditItemName4.SetWindowText("");
	}
}


void CCBDlg::OnEnChangeEditItemId5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	POSITION pos;
	int i;

	CString strItemId;
	m_CEditItemId5.GetWindowText(strItemId);

	//ȷ����Ʒ�Ƿ����
	if(!strItemId.IsEmpty())
	{
		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			if(strItemId == TmpItemDef.ID)
			{
				CString tempName = TmpItemDef.Name;
				tempName.Replace("item_", "");

				m_CEditItemName5.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditItemName5.SetWindowText("");
		}
	}
	else
	{
		m_CEditItemName5.SetWindowText("");
	}
}


LRESULT CCBDlg::DoResetConfig(WPARAM wParam, LPARAM lParam)
{
	KillTimer(TIMER1);
	KillTimer(TIMER2);
	KillTimer(TIMER3);

	SetStateStatic(FALSE);
	DoButtonExe();
	return 0;
}