// ItemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HCSG_Manager.h"
#include "ItemDlg.h"
#include "afxdialogex.h"

#include <shlwapi.h>
#pragma comment(lib,"Shlwapi.lib") 

// CItemDlg �Ի���

IMPLEMENT_DYNAMIC(CItemDlg, CDialogEx)

	CItemDlg::CItemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CItemDlg::IDD, pParent)
{

}

CItemDlg::~CItemDlg()
{
}

void CItemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ACC, m_CListCtrlAcc);
	DDX_Control(pDX, IDC_EDIT_FIND_ACC, m_CEditFindAcc);
	DDX_Control(pDX, IDC_STATIC_ACC_TOTAL, m_CStaticAccTotal);
}


BEGIN_MESSAGE_MAP(CItemDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_FIND_ACC, &CItemDlg::OnEnChangeEditFindAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ACC, &CItemDlg::OnBnClickedButtonFindNextAcc)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CItemDlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CItemDlg::OnBnClickedButtonOutput)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CItemDlg ��Ϣ�������


BOOL CItemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int i;

	m_CListCtrlAcc.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlAcc.InsertColumn(0, _T("ע���ʺ�"), LVCFMT_LEFT, 60);//������
	m_CListCtrlAcc.InsertColumn(1, _T("��ɫ����"), LVCFMT_LEFT, 100);
	m_CListCtrlAcc.InsertColumn(2, _T("�ʽ�"), LVCFMT_LEFT, 60);

	CString strTemp = "";
	for(i=3;i<83;i++)
	{
		strTemp.Format("��%d��", i-2);
		m_CListCtrlAcc.InsertColumn(i, strTemp, LVCFMT_LEFT, 130);
	}

	//Common::GetSaveItems();

	//SetTimer(TIMER1, 10*1000,0);  //ȫ�ֶ��������Զ�������

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CItemDlg::InitItemList()
{
	POSITION pos, pos2, pos3;
	struct AccAttr TmpAccAttr;
	CList <AccAttr, AccAttr&> *LCurAccAttr = &Common::LAccAttr;
	CList <SaveItems, SaveItems&> *LCurSaveItems = &Common::LSaveItems;
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	struct SaveItems TmpSaveItems;
	int i, j, k;
	CString strAccName, strAccount, strGold, strItemId, strItemNum;
	int nIndex = 0;
	int nrow, nItem;
	unsigned __int32  LastTimeStamp = 0;

	m_CListCtrlAcc.DeleteAllItems();

	pos = LCurSaveItems->GetHeadPosition();
	for(i=0;i < LCurSaveItems->GetCount();i++)
	{
		TmpSaveItems = LCurSaveItems->GetNext(pos);

		// ��һ����ɫ
		strAccName = "";
		strAccount = "";
		LastTimeStamp = 0;
		for(j=0;j<80;j++)
		{
			if(strlen(TmpSaveItems.Player_1[j].PlayerName) == 0)
				continue;


			if(TmpSaveItems.Player_1[j].TimeStamp > LastTimeStamp)
			{
				if(LastTimeStamp == 0)
				{
					nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
					nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));
				}

				LastTimeStamp = TmpSaveItems.Player_1[j].TimeStamp;

				strAccName.Format("%s", TmpSaveItems.Player_1[j].PlayerName);

				pos2 = LCurAccAttr->GetHeadPosition();
				for (k=0;k < LCurAccAttr->GetCount();k++)
				{
					TmpAccAttr = LCurAccAttr->GetNext(pos2);
					if(0 == strcmp(TmpAccAttr.Name, strAccName))
					{
						strGold = Common::convert(TmpAccAttr.Gold);
						strAccount.Format("%s", TmpAccAttr.Account);
						break;
					}
				}
			}

			strItemId.Format("%d", TmpSaveItems.Player_1[j].ItemId);
			nIndex = TmpSaveItems.Player_1[j].ItemNum;
			strItemNum.Format("%d", nIndex);
			pos3 = LCurItemDef->GetHeadPosition();
			for (k=0;k < LCurItemDef->GetCount();k++)
			{
				TmpItemDef = LCurItemDef->GetNext(pos3);

				if(strItemId == TmpItemDef.ID)
				{
					CString tempName = strItemId + "-" +TmpItemDef.Name + "x" + strItemNum;
					tempName.Replace("item_", "");

					m_CListCtrlAcc.SetItemText(nItem, j+3, _T(Common::Big2GB((LPSTR)(LPCTSTR)tempName)));
					break;
				}
			}				
		}
		if(!strAccName.IsEmpty())
		{
			m_CListCtrlAcc.SetItemText(nItem, 0, strAccount);
			m_CListCtrlAcc.SetItemText(nItem, 1, Common::Big2GB((LPSTR)(LPCTSTR)strAccName));
			m_CListCtrlAcc.SetItemText(nItem, 2, strGold);
		}

		// �ڶ�����ɫ
		strAccName = "";
		strAccount = "";
		LastTimeStamp = 0;
		for(j=0;j<80;j++)
		{
			if(strlen(TmpSaveItems.Player_2[j].PlayerName) == 0)
				continue;

			if(TmpSaveItems.Player_2[j].TimeStamp > LastTimeStamp)
			{
				if(LastTimeStamp == 0)
				{
					nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
					nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));
				}

				LastTimeStamp = TmpSaveItems.Player_2[j].TimeStamp;

				strAccName.Format("%s", TmpSaveItems.Player_2[j].PlayerName);

				pos2 = LCurAccAttr->GetHeadPosition();
				for (k=0;k < LCurAccAttr->GetCount();k++)
				{
					TmpAccAttr = LCurAccAttr->GetNext(pos2);
					if(0 == strcmp(TmpAccAttr.Name, strAccName))
					{
						strGold = Common::convert(TmpAccAttr.Gold);
						strAccount.Format("%s", TmpAccAttr.Account);
						break;
					}
				}
			}

			strItemId.Format("%d", TmpSaveItems.Player_2[j].ItemId);
			nIndex = TmpSaveItems.Player_2[j].ItemNum;
			strItemNum.Format("%d", nIndex);
			pos3 = LCurItemDef->GetHeadPosition();
			for (k=0;k < LCurItemDef->GetCount();k++)
			{
				TmpItemDef = LCurItemDef->GetNext(pos3);

				if(strItemId == TmpItemDef.ID)
				{
					CString tempName = strItemId + "-" +TmpItemDef.Name + "x" + strItemNum;
					tempName.Replace("item_", "");

					m_CListCtrlAcc.SetItemText(nItem, j+3, _T(Common::Big2GB((LPSTR)(LPCTSTR)tempName)));
					break;
				}
			}				
		}
		if(!strAccName.IsEmpty())
		{
			m_CListCtrlAcc.SetItemText(nItem, 0, strAccount);
			m_CListCtrlAcc.SetItemText(nItem, 1, Common::Big2GB((LPSTR)(LPCTSTR)strAccName));
			m_CListCtrlAcc.SetItemText(nItem, 2, strGold);
		}

		// ��������ɫ
		strAccName = "";
		strAccount = "";
		LastTimeStamp = 0;
		for(j=0;j<80;j++)
		{
			if(strlen(TmpSaveItems.Player_3[j].PlayerName) == 0)
				continue;

			if(TmpSaveItems.Player_3[j].TimeStamp > LastTimeStamp)
			{
				if(LastTimeStamp == 0)
				{
					nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
					nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));
				}

				LastTimeStamp = TmpSaveItems.Player_3[j].TimeStamp;

				strAccName.Format("%s", TmpSaveItems.Player_3[j].PlayerName);

				pos2 = LCurAccAttr->GetHeadPosition();
				for (k=0;k < LCurAccAttr->GetCount();k++)
				{
					TmpAccAttr = LCurAccAttr->GetNext(pos2);
					if(0 == strcmp(TmpAccAttr.Name, strAccName))
					{
						strGold = Common::convert(TmpAccAttr.Gold);
						strAccount.Format("%s", TmpAccAttr.Account);
						break;
					}
				}
			}

			strItemId.Format("%d", TmpSaveItems.Player_3[j].ItemId);
			nIndex = TmpSaveItems.Player_3[j].ItemNum;
			strItemNum.Format("%d", nIndex);
			pos3 = LCurItemDef->GetHeadPosition();
			for (k=0;k < LCurItemDef->GetCount();k++)
			{
				TmpItemDef = LCurItemDef->GetNext(pos3);

				if(strItemId == TmpItemDef.ID)
				{
					CString tempName = strItemId + "-" +TmpItemDef.Name + "x" + strItemNum;
					tempName.Replace("item_", "");

					m_CListCtrlAcc.SetItemText(nItem, j+3, _T(Common::Big2GB((LPSTR)(LPCTSTR)tempName)));
					break;
				}
			}				
		}
		if(!strAccName.IsEmpty())
		{
			m_CListCtrlAcc.SetItemText(nItem, 0, strAccount);
			m_CListCtrlAcc.SetItemText(nItem, 1, Common::Big2GB((LPSTR)(LPCTSTR)strAccName));
			m_CListCtrlAcc.SetItemText(nItem, 2, strGold);
		}
	}

	m_CStaticAccTotal.SetWindowText(Common::convert(m_CListCtrlAcc.GetItemCount()));
}

void CItemDlg::OnEnChangeEditFindAcc()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

	m_CEditFindAcc.SetFocus();

}


void CItemDlg::OnBnClickedButtonFindNextAcc()
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
		for ( int i=0 ; i<2 ; i++ )  // ֻ�����˻����ͽ�ɫ��
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


void CItemDlg::OnBnClickedButtonUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Common::GetSaveItems();
	InitItemList();
}


void CItemDlg::OnBnClickedButtonOutput()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i, j;
	CString strAccount, strAccName, strGold, strItemList;

	CString cdtime;
	CString strDate;
	CTime m_time;
	m_time = CTime::GetCurrentTime();
	strDate = m_time.Format(_T("%Y-%m-%d"));
	cdtime = m_time.Format(_T("%Y-%m-%d-%H-%M-%S"));

	CString StrValue;
	CString strPathName="";
	CString strPath="";
	::GetCurrentDirectory(1024,strPathName.GetBuffer(1024));
	strPathName.ReleaseBuffer();
	strPath = strPathName + "\\"+ strDate;
	strPathName += "\\"+ strDate + "\\�����б�-" + cdtime +".TXT";

	if (!PathIsDirectory(strPath))
	{
		if (!CreateDirectory(strPath, NULL ) ) 
		{
			Common::Log(Error, strPath + "�ļ��д���ʧ��");
		}
	}

	DWORD dwRe = GetFileAttributes(strPathName);
	if ( dwRe != (DWORD)-1 )
	{
		DeleteFile(strPathName);
	}

	//���ļ�
	CStdioFile StdFile;
	StdFile.Open(strPathName,CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone);

	int nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
	for(i = 0; i < nrow; i++)
	{
		strAccount = m_CListCtrlAcc.GetItemText(i, 0);
		strAccName = m_CListCtrlAcc.GetItemText(i, 1);
		strGold = m_CListCtrlAcc.GetItemText(i, 2);
		strItemList = "";
		for(j=3;j<83;j++)
		{
			CString tmp11 = m_CListCtrlAcc.GetItemText(i, j);
			if(!tmp11.IsEmpty())
				strItemList += tmp11 + "  ";
		}

		CString strTemp = "���˻�����" + strAccount + " ��ɫ����" + strAccName + " �ʽ�" + strGold + "��\n������Ʒ�б�" + strItemList + "\n\n";
		StdFile.WriteString(strTemp);
	}

	StdFile.Close();

	Common::Log(Info, "�б������ɣ�");
}


void CItemDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent){
	case TIMER1:
		{
			KillTimer(TIMER1);
			SetTimer(TIMER1, 60*60*1000, 0); // ÿ1��Сʱ���һ�α�������
			CTime CurTime = CTime::GetCurrentTime();
			Common::GetSaveItems();
			InitItemList();
			OnBnClickedButtonOutput();
			break;
		}
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
