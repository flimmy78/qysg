// CwarPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include <afxdb.h>
#include "HCSG_Manager.h"
#include "CwarOrgDlg.h"
#include "afxdialogex.h"

CList <CwarAwards, CwarAwards&> LCwarAwards;

// CCwarPlayerDlg �Ի���

IMPLEMENT_DYNAMIC(CCwarOrgDlg, CDialogEx)

	CCwarOrgDlg::CCwarOrgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCwarOrgDlg::IDD, pParent)
{
	ExeStart = FALSE;
}

CCwarOrgDlg::~CCwarOrgDlg()
{
}

void CCwarOrgDlg::DoDataExchange(CDataExchange* pDX)
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
	DDX_Control(pDX, IDC_COMBO_STAGE, m_CComboBoxStage);
	DDX_Control(pDX, IDC_EDIT_CHECK_TIME, m_CEditChkTime);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_CComboBoxType);
}


BEGIN_MESSAGE_MAP(CCwarOrgDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FIND_ACC, &CCwarOrgDlg::OnBnClickedButtonFindAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ACC, &CCwarOrgDlg::OnBnClickedButtonFindNextAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_ITEM, &CCwarOrgDlg::OnBnClickedButtonFindItem)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ITEM, &CCwarOrgDlg::OnBnClickedButtonFindNextItem)
	ON_BN_CLICKED(IDC_BUTTON_ADD_CONFIG, &CCwarOrgDlg::OnBnClickedButtonAddConfig)
	ON_BN_CLICKED(IDC_BUTTON_DEL_CONFIG, &CCwarOrgDlg::OnBnClickedButtonDelConfig)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CONFIG, &CCwarOrgDlg::OnBnClickedButtonSaveConfig)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_CONFIG, &CCwarOrgDlg::OnBnClickedButtonLoadConfig)
	ON_BN_CLICKED(IDC_BUTTON_EXE, &CCwarOrgDlg::OnBnClickedButtonExe)
	ON_BN_CLICKED(IDC_BUTTON_ADDTOSWAP, &CCwarOrgDlg::OnBnClickedButtonAddtoswap)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CCwarOrgDlg::OnBnClickedButtonInit)
	ON_WM_TIMER()
	ON_CBN_EDITCHANGE(IDC_COMBO_STAGE, &CCwarOrgDlg::OnCbnEditchangeComboStage)
	ON_MESSAGE(WM_SAVECWARORGAWARDS, DoSaveConfig)
	ON_MESSAGE(WM_CWARORGRESET, DoResetConfig)
	ON_EN_CHANGE(IDC_EDIT_CHECK_TIME, &CCwarOrgDlg::OnEnChangeEditCheckTime)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID, &CCwarOrgDlg::OnEnChangeEditItemId)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID2, &CCwarOrgDlg::OnEnChangeEditItemId2)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID3, &CCwarOrgDlg::OnEnChangeEditItemId3)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID4, &CCwarOrgDlg::OnEnChangeEditItemId4)
	ON_EN_CHANGE(IDC_EDIT_ITEM_ID5, &CCwarOrgDlg::OnEnChangeEditItemId5)
END_MESSAGE_MAP()

// CCwarPlayerDlg ��Ϣ�������


BOOL CCwarOrgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_CListCtrlAcc.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlAcc.InsertColumn(0, _T("����"), LVCFMT_LEFT, 60);
	m_CListCtrlAcc.InsertColumn(1, _T("�ų��ʺ�"), LVCFMT_LEFT, 60);
	m_CListCtrlAcc.InsertColumn(2, _T("�ų�����"), LVCFMT_LEFT, 60);//������
	m_CListCtrlAcc.InsertColumn(3, _T("ռ��ǳ�"), LVCFMT_LEFT, 60);
	m_CListCtrlAcc.InsertColumn(4, _T("�콱����"), LVCFMT_LEFT, 50);

	m_CListCtrlItem.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlItem.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 40);//������
	m_CListCtrlItem.InsertColumn(1, _T("��Ʒ����"), LVCFMT_LEFT, 190);

	m_CListCtrlConfig.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlConfig.InsertColumn(0, _T("������"), LVCFMT_LEFT, 60);//������
	m_CListCtrlConfig.InsertColumn(1, _T("����ID"), LVCFMT_LEFT, 60);
	m_CListCtrlConfig.InsertColumn(2, _T("��������"), LVCFMT_LEFT, 60);

	CString strTemp;
	for(int i=0;i<5;i++)
	{
		strTemp.Format("��ƷID%d", i+1);
		m_CListCtrlConfig.InsertColumn(3*i+3, strTemp, LVCFMT_LEFT, 55);
		strTemp.Format("��Ʒ��%d", i+1);
		m_CListCtrlConfig.InsertColumn(3*i+4, strTemp, LVCFMT_LEFT, 100);  // ������Ʒ
		strTemp.Format("����%d", i+1);
		m_CListCtrlConfig.InsertColumn(3*i+5, strTemp, LVCFMT_LEFT, 45);
	}

	m_CEditItemNum.SetWindowText("1");
	m_CEditItemNum2.SetWindowText("1");
	m_CEditItemNum3.SetWindowText("1");
	m_CEditItemNum4.SetWindowText("1");
	m_CEditItemNum5.SetWindowText("1");

	m_CComboBoxCfgID.SetCurSel(0);

	m_CListCtrlAcc.DeleteAllItems();
	try
	{
	SetStateStatic(FALSE);
	m_CEditChkTime.SetWindowText(Common::m_CWarAwardsChkTime);
	OnBnClickedButtonInit();

	CString strFilePath="";
	::GetCurrentDirectory(1024,strFilePath.GetBuffer(1024));
	strFilePath.ReleaseBuffer();
	strFilePath += "\\Profile\\AwardsConfig.xls";
	DoLoadConfig(strFilePath);

	OnBnClickedButtonExe();

	}
	catch (_com_error e)
	{
		CString errormessage;
		errormessage.Format("������Ϣ:%s",e.ErrorMessage());
		Common::Log(Error ,errormessage);
		return FALSE;

	}

	BOOL IsCWarRunning = FALSE;

	return TRUE;  // return TRUE unless you set the focus to a control
}


void CCwarOrgDlg::SetStateStatic(BOOL IsStart)
{
	if(IsStart)
	{
		CString strResult;
		strResult = "��ս�����У�";
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
		strResult = "��սδ��ʼ��";
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


void CCwarOrgDlg::GetOrganize()
{
	CString strPathName;
	CList <AccAttr, AccAttr&> *LCurAccAttr = &Common::LAccAttr;
	CList <OrganizeAttr, OrganizeAttr&> *LCurOrganizeAttr = &Common::LOrganizeAttr;
	CList <StageDef, StageDef&> *LCurStageDef = &Common::LStageDef;
	int ret = 0;
	int i;
	POSITION pos, pos2;
	CString AwardsStages = "|";  //���ӳ����б�

	//����ܼ��ӵĳ����б�
	int iRowCountConfig = m_CListCtrlConfig.GetItemCount();
	for(int i=0;i<iRowCountConfig;i++)
	{
		if(m_CListCtrlConfig.GetItemText(i,2) == "ʱ�佱��")
		{
			CString strTemp = "";
			strTemp = m_CListCtrlConfig.GetItemText(i,0);
			AwardsStages += strTemp + "|";
		}		
	}

	Common::GetOrganizeAttr();

	pos = LCurOrganizeAttr->GetHeadPosition();
	for (i=0;i < LCurOrganizeAttr->GetCount();i++)
	{
		struct OrganizeAttr TmpOrganizeAttr = LCurOrganizeAttr->GetNext(pos);  //��õ�ǰ���ŵ�����
		struct CwarAwards TmpCwarAwards;

		pos2 = LCurStageDef->GetHeadPosition();   // ͨ����ͼID��õ�ͼ���ƣ������ͼ��ӳ��н��жԱ�
		for (int j=0;j < LCurStageDef->GetCount();j++)
		{
			struct StageDef TmpStageDef = LCurStageDef->GetNext(pos2);
			if(0 == strcmp(TmpStageDef.ID, Common::convert(TmpOrganizeAttr.StageId)))
			{
				TmpStageDef.Name.Replace("city_", "");
				TmpCwarAwards.StageName = Common::Big2GB((LPSTR)(LPCTSTR)TmpStageDef.Name);
			}
		}

		if(AwardsStages.Find("|" + TmpCwarAwards.StageName + "|") == -1)  //������ռ���в��ڽ�����Χ
			continue;

		TmpCwarAwards.OrganizeName = TmpOrganizeAttr.OrganizeName;
		TmpCwarAwards.OrganizeNameOfLeaderZh = TmpOrganizeAttr.OrganizeLeaderZh;
		pos2 = LCurAccAttr->GetHeadPosition();
		for (int j=0;j < LCurAccAttr->GetCount();j++)
		{
			struct AccAttr TmpAccAttr = LCurAccAttr->GetNext(pos2);
			if(0 == strcmp(TmpAccAttr.Name, TmpOrganizeAttr.OrganizeLeaderZh))
				TmpCwarAwards.OrganizeAccountOfLeaderZh = TmpAccAttr.Account;
		}
		TmpCwarAwards.AwardsTimes = 1;

		BOOL IsFound = FALSE;
		pos2 = LCwarAwards.GetHeadPosition();
		for (int j=0;j < LCwarAwards.GetCount();j++)
		{
			POSITION tmpPos = pos2;
			struct CwarAwards CwarAwardsOld = LCwarAwards.GetNext(pos2);
			if(0 == strcmp(CwarAwardsOld.StageName, TmpCwarAwards.StageName)
				&& 0 == strcmp(CwarAwardsOld.OrganizeName, TmpCwarAwards.OrganizeName))
			{
				CwarAwardsOld.AwardsTimes += TmpCwarAwards.AwardsTimes;
				CwarAwardsOld.OrganizeNameOfLeaderZh = TmpCwarAwards.OrganizeNameOfLeaderZh;
				CwarAwardsOld.OrganizeAccountOfLeaderZh = TmpCwarAwards.OrganizeAccountOfLeaderZh;

				LCwarAwards.SetAt(tmpPos, CwarAwardsOld);
				IsFound = TRUE;
			}
		}
		if(!IsFound)
			LCwarAwards.AddTail(TmpCwarAwards);
	}

	//��ʾ�����б�
	m_CListCtrlAcc.DeleteAllItems();
	pos = LCwarAwards.GetHeadPosition();
	for (int i=0;i < LCwarAwards.GetCount();i++)
	{
		struct CwarAwards TmpCwarAwards = LCwarAwards.GetNext(pos);
		int nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
		int nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));
		m_CListCtrlAcc.SetItemText(nItem, 0, _T(Common::Big2GB((LPSTR)(LPCTSTR)TmpCwarAwards.OrganizeName)));	
		m_CListCtrlAcc.SetItemText(nItem, 1, _T(TmpCwarAwards.OrganizeAccountOfLeaderZh));
		m_CListCtrlAcc.SetItemText(nItem, 2, _T(Common::Big2GB((LPSTR)(LPCTSTR)TmpCwarAwards.OrganizeNameOfLeaderZh)));
		m_CListCtrlAcc.SetItemText(nItem, 3, TmpCwarAwards.StageName);
		m_CListCtrlAcc.SetItemText(nItem, 4, _T(Common::convert(TmpCwarAwards.AwardsTimes)));
	}
}


void CCwarOrgDlg::OnBnClickedButtonFindAcc()
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


void CCwarOrgDlg::OnBnClickedButtonFindNextAcc()
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


void CCwarOrgDlg::OnBnClickedButtonFindItem()
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


void CCwarOrgDlg::OnBnClickedButtonFindNextItem()
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


void CCwarOrgDlg::OnBnClickedButtonAddConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strCityName, strCityId, strType;
	CString strItem, strNum, strItem2, strNum2, strItem3, strNum3, strItem4, strNum4, strItem5, strNum5;
	CString strItemName, strItemName2, strItemName3, strItemName4, strItemName5;

	// ������
	m_CComboBoxStage.GetWindowTextA(strCityName);
	// ����
	m_CComboBoxType.GetWindowTextA(strType);

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

	//if(strCityName.IsEmpty()){	strCityId = "";}
	if(strItem.IsEmpty()){	strItemName = ""; strNum = "";}
	if(strItem2.IsEmpty()){	strItemName2 = ""; strNum2 = "";}
	if(strItem3.IsEmpty()){	strItemName3 = ""; strNum3 = "";}
	if(strItem4.IsEmpty()){	strItemName4 = ""; strNum4 = "";}
	if(strItem5.IsEmpty()){	strItemName5 = ""; strNum5 = "";}

	if(strCityName.IsEmpty() || strType.IsEmpty() || (strItem.IsEmpty() && strItem2.IsEmpty() 
		&& strItem3.IsEmpty() && strItem4.IsEmpty() && strItem5.IsEmpty()))
		return;

	int nrow = m_CListCtrlConfig.GetItemCount();//ȡ����
	int nItem = m_CListCtrlConfig.InsertItem(nrow+1, _T(""));
	m_CListCtrlConfig.SetItemText(nItem, 0, strCityName);
	m_CListCtrlConfig.SetItemText(nItem, 2, strType);
	m_CListCtrlConfig.SetItemText(nItem, 3, strItem);
	m_CListCtrlConfig.SetItemText(nItem, 4, strItemName);
	m_CListCtrlConfig.SetItemText(nItem, 5, strNum);
	m_CListCtrlConfig.SetItemText(nItem, 6, strItem2);
	m_CListCtrlConfig.SetItemText(nItem, 7, strItemName2);
	m_CListCtrlConfig.SetItemText(nItem, 8, strNum2);
	m_CListCtrlConfig.SetItemText(nItem, 9, strItem3);
	m_CListCtrlConfig.SetItemText(nItem, 10, strItemName3);
	m_CListCtrlConfig.SetItemText(nItem, 11, strNum3);
	m_CListCtrlConfig.SetItemText(nItem, 12, strItem4);
	m_CListCtrlConfig.SetItemText(nItem, 13, strItemName4);
	m_CListCtrlConfig.SetItemText(nItem, 14, strNum4);
	m_CListCtrlConfig.SetItemText(nItem, 15, strItem5);
	m_CListCtrlConfig.SetItemText(nItem, 16, strItemName5);
	m_CListCtrlConfig.SetItemText(nItem, 17, strNum5);

	OnBnClickedButtonSaveConfig();
}


void CCwarOrgDlg::OnBnClickedButtonDelConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ListIndex  = m_CListCtrlConfig.GetSelectionMark();
	if(ListIndex == -1) return;
	m_CListCtrlConfig.DeleteItem(ListIndex);//ɾ��ѡ����

	OnBnClickedButtonSaveConfig();
}


void CCwarOrgDlg::OnBnClickedButtonSaveConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if ( m_CListCtrlConfig.GetItemCount()<= 0 )
	{
		Common::Log(Info, "�б���û�м�¼��Ҫ���棡");
		return;
	}
	Common::SaveAwardsConfig();
}


LRESULT CCwarOrgDlg::DoSaveConfig(WPARAM wParam, LPARAM lParam)
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
			sSql = " CREATE TABLE ��սռ�ǽ��� ( ";
			strInsert = " INSERT INTO ��սռ�ǽ��� ( " ;
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
		Common::Log(Info, "�����սռ�ǽ������óɹ���");
	}
	CATCH_ALL(e)
	{
		//�������ͺܶ࣬������Ҫ���б���
		Common::Log(Error, "��սռ�Ǿ��Ž������ñ���ʧ�ܡ�");
	}
	END_CATCH_ALL;

	return 0;
}


void CCwarOrgDlg::OnBnClickedButtonLoadConfig()
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

	if(DoLoadConfig(strFilePath))
		MessageBox("������Ϣ�ɹ�����ϵͳ!","����ɹ�");
	else
		MessageBox("������Ϣ����ϵͳʧ��!","����ʧ��");
}


BOOL CCwarOrgDlg::DoLoadConfig(CString strFilePath)
{
	//�ж��ļ��Ƿ��Ѿ����ڣ���������ļ�
	DWORD dwRe = GetFileAttributes(strFilePath);
	if ( dwRe != (DWORD)-1 )
	{
		//ShellExecute(NULL, NULL, strFilePath, NULL, NULL, SW_RESTORE); 
	}
	else return FALSE;
	CDatabase db;//���ݿ����Ҫ����ͷ�ļ� #include <afxdb.h>
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // Excel����
	CString sSql,arr[18];
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
	sSql.Format("SELECT ������ , ����ID , �������� , ��ƷID1 , ��Ʒ��1 , ����1 , ��ƷID2 , ��Ʒ��2 , ����2 ,"
		" ��ƷID3 , ��Ʒ��3 , ����3 , ��ƷID4 , ��Ʒ��4 , ����4 , ��ƷID5 , ��Ʒ��5 , ����5 FROM ��սռ�ǽ���");
	pset.Open(CRecordset::forwardOnly,sSql,CRecordset::readOnly);
	while(!pset.IsEOF())
	{
		pset.GetFieldValue("������",arr[0]);//ǰ���ֶα�������е���ͬ���������
		pset.GetFieldValue("����ID",arr[1]);
		pset.GetFieldValue("��������",arr[2]);

		pset.GetFieldValue("��ƷID1",arr[3]);
		pset.GetFieldValue("��Ʒ��1",arr[4]);
		pset.GetFieldValue("����1",arr[5]);

		pset.GetFieldValue("��ƷID2",arr[6]);
		pset.GetFieldValue("��Ʒ��2",arr[7]);
		pset.GetFieldValue("����2",arr[8]);

		pset.GetFieldValue("��ƷID3",arr[9]);
		pset.GetFieldValue("��Ʒ��3",arr[10]);
		pset.GetFieldValue("����3",arr[11]);

		pset.GetFieldValue("��ƷID4",arr[12]);
		pset.GetFieldValue("��Ʒ��4",arr[13]);
		pset.GetFieldValue("����4",arr[14]);

		pset.GetFieldValue("��ƷID5",arr[15]);
		pset.GetFieldValue("��Ʒ��5",arr[16]);
		pset.GetFieldValue("����5",arr[17]);

		int nItem = m_CListCtrlConfig.GetItemCount();//���뵽ListCtrl��
		int count = m_CListCtrlConfig.InsertItem(nItem,arr[0]);
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
		m_CListCtrlConfig.SetItemText(count,17,arr[17]);

		pset.MoveNext();
	}
	db.Close();
	return TRUE;
}


void CCwarOrgDlg::StartTimer(CStringArray *StartTimes)
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
		Common::Log(Info, "�´ι�սʱ�䣺" + strWarStartTime);
		int  tmp_h, tmp_mm;
		sscanf_s(strWarStartTime.GetBuffer(strWarStartTime.GetLength()),
			"%d:%d", &tmp_h, &tmp_mm); 
		CTime WarStartTime(y, m, d, tmp_h, tmp_mm, 0);
		CTimeSpan DelayTime = WarStartTime - CurTime;
		SetTimer(TIMER1, (UINT)DelayTime.GetTotalSeconds() * 1000, 0);
		//SetTimer(TIMER1, 10 * 1000, 0); // for test
	}
	else
	{
		enHandle = FALSE;  
		//enHandle = TRUE; // for test
		CTime WarStartTime(y, m, d+1, 0, 0, 0);
		CTimeSpan DelayTime = WarStartTime - CurTime;
		SetTimer(TIMER1, (UINT)DelayTime.GetTotalSeconds() * 1000, 0);
		//SetTimer(TIMER1, 3 * 1000, 0); // for test
	}

}


void CCwarOrgDlg::DoButtonExe()
{
	ServerConfigTime *CurTimeForCwar = &Common::TimeForCwar;
	CTime CurTime = CTime::GetCurrentTime();
	int DayOfWeek = CurTime.GetDayOfWeek(); //��ȡ���ڼ���ע��1Ϊ�����죬7Ϊ������
	switch (DayOfWeek)
	{
	case 1:
		{
			StartTimer(&CurTimeForCwar->SunStartTimes);
			break;
		}
	case 2:
		{
			StartTimer(&CurTimeForCwar->ModStartTimes);
			break;
		}
	case 3:
		{
			StartTimer(&CurTimeForCwar->TuseStartTimes);
			break;
		}
	case 4:
		{
			StartTimer(&CurTimeForCwar->WedStartTimes);
			break;
		}
	case 5:
		{
			StartTimer(&CurTimeForCwar->ThursStartTimes);
			break;
		}

	case 6:
		{
			StartTimer(&CurTimeForCwar->FriStartTimes);
			break;
		}
	case 7:
		{
			StartTimer(&CurTimeForCwar->SatStartTimes);
			break;
		}
	default:
		break;
	}
}


void CCwarOrgDlg::OnBnClickedButtonExe()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	DoButtonExe();
	if(ExeStart)
	{
		GetDlgItem(IDC_BUTTON_EXE)->SetWindowText("�����Զ�ģʽ");
		Common::Log(Info, "��ս����ռ�ǽ������ֹͣ");
		ExeStart = FALSE;
	}
	else
	{
		GetDlgItem(IDC_BUTTON_EXE)->SetWindowText("ֹͣ�Զ�ģʽ");
		Common::Log(Info, "��ս����ռ�ǽ�����⿪ʼ");
		ExeStart = TRUE;
	}
}


void CCwarOrgDlg::OnBnClickedButtonAddtoswap()
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


void CCwarOrgDlg::OnBnClickedButtonInit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	struct StageDef TmpStageDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	CList <StageDef, StageDef&> *LCurStageDef = &Common::LStageDef;
	int ret = 0;
	POSITION pos;

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

	//��ʼ�������б�
	pos = LCurStageDef->GetHeadPosition();
	for (int i=0;i < LCurStageDef->GetCount();i++)
	{
		TmpStageDef = LCurStageDef->GetNext(pos);
		CString tempName = TmpStageDef.Name;
		tempName.Replace("city_", "");
		m_CComboBoxStage.AddString(_T(Common::Big2GB((LPSTR)(LPCTSTR)tempName)));
	}

	m_CComboBoxStage.SetCurSel(1);
}


void CCwarOrgDlg::OnTimer(UINT_PTR nIDEvent)
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
			IsCWarRunning = TRUE;
			SetStateStatic(TRUE);
			m_CListCtrlAcc.DeleteAllItems();
			KillTimer(TIMER1);
			SetTimer(TIMER2, _ttoi(Common::TimeForCwar.Period) * 60 * 1000 - 10*1000, 0); //��ǰ10�����

			//SetTimer(TIMER2, 2 * 60 * 1000 - 10*1000, 0); // for test 

			CString strValue;
			m_CEditChkTime.GetWindowText(strValue);
			SetTimer(TIMER3, _ttoi(strValue) * 60 * 1000, 0); 
			//SetTimer(TIMER3, 30 * 1000 * 1, 0);  // for test
			LCwarAwards.RemoveAll();
			Common::Log(Info, "���Ž������ -- ��ս��ʼ��");
			break;
		}
	case TIMER2:
		{
			IsCWarRunning = FALSE;			
			SetStateStatic(FALSE);
			KillTimer(TIMER2);
			Common::Log(Info, "���Ž������ -- ��ս������");
			SetTimer(TIMER4, 1 * 60 * 1000, 0);  // �ӳ�1���ӷ���ռ�ǽ���
			PaymentOfAwards();
			break;
		}
	case TIMER3:
		{
			if(IsCWarRunning)
			{
				KillTimer(TIMER3);
				GetOrganize();			

				CString strValue;
				m_CEditChkTime.GetWindowText(strValue);
				SetTimer(TIMER3, _ttoi(strValue) * 60 * 1000, 0);
				//SetTimer(TIMER3, 30 * 1000 * 1, 0);  // for test
			}
			else
			{
				KillTimer(TIMER3);
			}
			break;
		}
	case TIMER4:
		{
			KillTimer(TIMER4);
			PaymentOfAwards_1();
			DoButtonExe();
			LCwarAwards.RemoveAll();

			break;
		}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

/* ʱ�佱�� */
void CCwarOrgDlg::PaymentOfAwards()
{
	if(!Common::SanGuoServerIsRuning)
		return;

	int iColumnNumAcc,iRowCountAcc;
	int iColumnNumConfig,iRowCountConfig;
	CString strAccount, strItem, strNum, strItem2, strNum2, strItem3, strNum3, strItem4, strNum4, strItem5, strNum5;

	Common::Log(Info, "��ս����<ʱ��>�������ſ�ʼ");
	iColumnNumAcc = m_CListCtrlAcc.GetHeaderCtrl()->GetItemCount();
	iRowCountAcc = m_CListCtrlAcc.GetItemCount();

	iColumnNumConfig = m_CListCtrlConfig.GetHeaderCtrl()->GetItemCount();
	iRowCountConfig = m_CListCtrlConfig.GetItemCount();

	for(int i = 0; i < iRowCountAcc; i++)
	{
		CString StageName, AwardsTimes;
		strAccount = m_CListCtrlAcc.GetItemText(i, 1); // ����ų���ɫ�˻�
		StageName = m_CListCtrlAcc.GetItemText(i, 3); // ���ռ���������
		AwardsTimes = m_CListCtrlAcc.GetItemText(i, 4); // ��ý�������

		for (int j=0 ; j<iRowCountConfig ; j++ )
		{
			CString strCityName, strType;
			strCityName = m_CListCtrlConfig.GetItemText(j,0);  //������������
			strType = m_CListCtrlConfig.GetItemText(j,2);  //������������
			if(StageName == strCityName && strType == "ʱ�佱��") //ƥ��ɹ�
			{
				strItem = m_CListCtrlConfig.GetItemText(j,3);
				strNum = m_CListCtrlConfig.GetItemText(j,5);

				strItem2 = m_CListCtrlConfig.GetItemText(j,6);
				strNum2 = m_CListCtrlConfig.GetItemText(j,8);

				strItem3 = m_CListCtrlConfig.GetItemText(j,9);
				strNum3 = m_CListCtrlConfig.GetItemText(j,11);

				strItem4 = m_CListCtrlConfig.GetItemText(j,12);
				strNum4 = m_CListCtrlConfig.GetItemText(j,14);

				strItem5 = m_CListCtrlConfig.GetItemText(j,15);
				strNum5 = m_CListCtrlConfig.GetItemText(j,17);

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

				int i = _ttoi(AwardsTimes);
				for(;i>0;i--)
				{
					if(!Common::SendXubao(strAccount, &ItemList))
					{
						Common::Log(Error, "���Ź�ս����<ʱ��>����ʧ��");
					}
				}
			}
		}
	}
	Common::Log(Info, "��ս����<ʱ��>�������Ž���");
}


/* ռ�ǽ��� */
void CCwarOrgDlg::PaymentOfAwards_1()
{
	if(!Common::SanGuoServerIsRuning)
		return;

	CString strAccount, strItem, strNum, strItem2, strNum2, strItem3, strNum3, strItem4, strNum4, strItem5, strNum5;

	Common::Log(Info, "��ս����<ռ��>�������ſ�ʼ");
	CString strPathName;
	CList <AccAttr, AccAttr&> *LCurAccAttr = &Common::LAccAttr;
	CList <OrganizeAttr, OrganizeAttr&> *LCurOrganizeAttr = &Common::LOrganizeAttr;
	CList <StageDef, StageDef&> *LCurStageDef = &Common::LStageDef;
	int ret = 0;
	POSITION pos, pos2;
	CString AwardsStages = "|";  //���ӳ����б�

	//����ܼ��ӵĳ����б�
	int iRowCountConfig = m_CListCtrlConfig.GetItemCount();
	for(int i=0;i<iRowCountConfig;i++)
	{
		if(m_CListCtrlConfig.GetItemText(i,2) == "ռ�ǽ���")
		{
			CString strTemp = "";
			strTemp = m_CListCtrlConfig.GetItemText(i,0);
			AwardsStages += strTemp + "|";
		}		
	}

	Common::GetOrganizeAttr();

	pos = LCurOrganizeAttr->GetHeadPosition();
	for (int i=0;i < LCurOrganizeAttr->GetCount();i++)
	{
		struct OrganizeAttr TmpOrganizeAttr = LCurOrganizeAttr->GetNext(pos);  //��õ�ǰ���ŵ�����
		struct CwarAwards TmpCwarAwards;

		pos2 = LCurStageDef->GetHeadPosition();   // ͨ����ͼID��õ�ͼ���ƣ������ͼ��ӳ��н��жԱ�
		for (int j=0;j < LCurStageDef->GetCount();j++)
		{
			struct StageDef TmpStageDef = LCurStageDef->GetNext(pos2);
			if(0 == strcmp(TmpStageDef.ID, Common::convert(TmpOrganizeAttr.StageId)))
			{
				TmpStageDef.Name.Replace("city_", "");
				TmpCwarAwards.StageName = Common::Big2GB((LPSTR)(LPCTSTR)TmpStageDef.Name);
			}
		}

		if(AwardsStages.Find("|" + TmpCwarAwards.StageName + "|") == -1)  //������ռ���в��ڽ�����Χ
			continue;

		TmpCwarAwards.OrganizeName = TmpOrganizeAttr.OrganizeName;
		TmpCwarAwards.OrganizeNameOfLeaderZh = TmpOrganizeAttr.OrganizeLeaderZh;
		pos2 = LCurAccAttr->GetHeadPosition();
		for (int j=0;j < LCurAccAttr->GetCount();j++)
		{
			struct AccAttr TmpAccAttr = LCurAccAttr->GetNext(pos2);
			if(0 == strcmp(TmpAccAttr.Name, TmpOrganizeAttr.OrganizeLeaderZh))
				TmpCwarAwards.OrganizeAccountOfLeaderZh = TmpAccAttr.Account;
		}
		TmpCwarAwards.AwardsTimes = 1;

		for (int j=0 ; j<iRowCountConfig ; j++ )
		{
			CString strCityName, strType;
			strCityName = m_CListCtrlConfig.GetItemText(j,0);  //������������
			strType = m_CListCtrlConfig.GetItemText(j,2);  
			if(TmpCwarAwards.StageName == strCityName && strType == "ռ�ǽ���") //ƥ��ɹ�
			{
				strItem = m_CListCtrlConfig.GetItemText(j,3);
				strNum = m_CListCtrlConfig.GetItemText(j,5);

				strItem2 = m_CListCtrlConfig.GetItemText(j,6);
				strNum2 = m_CListCtrlConfig.GetItemText(j,8);

				strItem3 = m_CListCtrlConfig.GetItemText(j,9);
				strNum3 = m_CListCtrlConfig.GetItemText(j,11);

				strItem4 = m_CListCtrlConfig.GetItemText(j,12);
				strNum4 = m_CListCtrlConfig.GetItemText(j,14);

				strItem5 = m_CListCtrlConfig.GetItemText(j,15);
				strNum5 = m_CListCtrlConfig.GetItemText(j,17);

				if(strItem.IsEmpty())	strNum = "";
				if(strItem2.IsEmpty())	strNum2 = "";
				if(strItem3.IsEmpty())	strNum3 = "";
				if(strItem4.IsEmpty())	strNum4 = "";
				if(strItem5.IsEmpty())	strNum5 = "";

				strAccount = TmpCwarAwards.OrganizeAccountOfLeaderZh;

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
					Common::Log(Error, "���Ź�ս����<ռ��>����ʧ��");
				}
			}
		}
	}

	Common::Log(Info, "��ս����<ռ��>�������Ž���");
}


void CCwarOrgDlg::OnCbnEditchangeComboStage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strEnter;
	m_CComboBoxStage.GetWindowText(strEnter);

	int nCount = m_CComboBoxStage.GetCount();
	for(int i = 0; i < nCount; i++)
	{
		CString strValue;
		m_CComboBoxStage.GetLBText(i,strValue);
		if(strstr(strValue, strEnter))
		{
			m_CComboBoxStage.SetCurSel(i);
			break;
		}
	}
}


void CCwarOrgDlg::OnEnChangeEditCheckTime()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_CEditChkTime.GetWindowText(Common::m_CWarAwardsChkTime);
	Common::SaveConfig();
}


void CCwarOrgDlg::OnEnChangeEditItemId()
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


void CCwarOrgDlg::OnEnChangeEditItemId2()
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


void CCwarOrgDlg::OnEnChangeEditItemId3()
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


void CCwarOrgDlg::OnEnChangeEditItemId4()
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


void CCwarOrgDlg::OnEnChangeEditItemId5()
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


LRESULT CCwarOrgDlg::DoResetConfig(WPARAM wParam, LPARAM lParam)
{
	KillTimer(TIMER1);
	KillTimer(TIMER2);
	KillTimer(TIMER3);
	KillTimer(TIMER4);

	SetStateStatic(FALSE);
	DoButtonExe();
	return 0;
}
