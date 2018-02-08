// StoreDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HCSG_Manager.h"
#include "StoreDlg.h"
#include "afxdialogex.h"


// CStoreDlg �Ի���

IMPLEMENT_DYNAMIC(CStoreDlg, CDialogEx)

CStoreDlg::CStoreDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStoreDlg::IDD, pParent)
{

}

CStoreDlg::~CStoreDlg()
{
}

void CStoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ACC, m_CListCtrlAcc);
	DDX_Control(pDX, IDC_EDIT_FIND_ACC, m_CEditFindAcc);
	DDX_Control(pDX, IDC_STATIC_ACC_TOTAL, m_CStaticAccTotal);
}


BEGIN_MESSAGE_MAP(CStoreDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_FIND_ACC, &CStoreDlg::OnEnChangeEditFindAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ACC, &CStoreDlg::OnBnClickedButtonFindNextAcc)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CStoreDlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CStoreDlg::OnBnClickedButtonOutput)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CStoreDlg ��Ϣ�������


BOOL CStoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int i;

	m_CListCtrlAcc.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlAcc.InsertColumn(0, _T("ע���ʺ�"), LVCFMT_LEFT, 60);//������
	m_CListCtrlAcc.InsertColumn(1, _T("��ɫ����"), LVCFMT_LEFT, 100);
	m_CListCtrlAcc.InsertColumn(2, _T("���"), LVCFMT_LEFT, 60);

	CString strTemp = "";
	for(i=3;i<83;i++)
	{
		strTemp.Format("��%d��", i-2);
		m_CListCtrlAcc.InsertColumn(i, strTemp, LVCFMT_LEFT, 130);
	}

	//Common::GetSaveItems();

	//SetTimer(TIMER1, 30*1000,0); //ȫ�ֶ��������Զ�������

	return TRUE;  // return TRUE unless you set the focus to a control
}


void CStoreDlg::InitItemList()
{
	POSITION pos, pos2, pos3;
	struct AccAttr TmpAccAttr;
	CList <AccAttr, AccAttr&> *LCurAccAttr = &Common::LAccAttr;
	CList <SaveStores, SaveStores&> *LCurSaveStores = &Common::LSaveStores;
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	struct SaveStores TmpSaveStores;
	int i, j, k;
	CString strAccName, strAccount, strGold, strItemId, strItemNum;
	int nIndex = 0;
	int nrow=0, nItem=0;
	unsigned __int32  LastTimeStamp = 0;

	m_CListCtrlAcc.DeleteAllItems();

	pos = LCurSaveStores->GetHeadPosition();
	for(i=0;i < LCurSaveStores->GetCount();i++)
	{
		TmpSaveStores = LCurSaveStores->GetNext(pos);

		// ��һ����ɫ
		strAccName = "";
		strAccount = "";
		LastTimeStamp = 0;
		for(j=0;j<80;j++)
		{
			if(strlen(TmpSaveStores.Player_1[j].PlayerName) == 0)
				continue;

			if(TmpSaveStores.Player_1[j].TimeStamp > LastTimeStamp)
			{
				if(LastTimeStamp == 0)
				{
					nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
					nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));

					strGold.Format("%d", TmpSaveStores.Player_1_Money);
				}

				LastTimeStamp = TmpSaveStores.Player_1[j].TimeStamp;

				strAccName.Format("%s", TmpSaveStores.Player_1[j].PlayerName);

				pos2 = LCurAccAttr->GetHeadPosition();
				for (k=0;k < LCurAccAttr->GetCount();k++)
				{
					TmpAccAttr = LCurAccAttr->GetNext(pos2);
					if(0 == strcmp(TmpAccAttr.Name, strAccName))
					{
						strAccount.Format("%s", TmpAccAttr.Account);
						break;
					}
				}
			}

			strItemId.Format("%d", TmpSaveStores.Player_1[j].ItemId);
			nIndex = TmpSaveStores.Player_1[j].ItemNum;
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
			if(strlen(TmpSaveStores.Player_2[j].PlayerName) == 0)
				continue;

			if(TmpSaveStores.Player_2[j].TimeStamp > LastTimeStamp)
			{
				if(LastTimeStamp == 0)
				{
					nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
					nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));

					strGold.Format("%d", TmpSaveStores.Player_2_Money);
				}

				LastTimeStamp = TmpSaveStores.Player_2[j].TimeStamp;

				strAccName.Format("%s", TmpSaveStores.Player_2[j].PlayerName);

				pos2 = LCurAccAttr->GetHeadPosition();
				for (k=0;k < LCurAccAttr->GetCount();k++)
				{
					TmpAccAttr = LCurAccAttr->GetNext(pos2);
					if(0 == strcmp(TmpAccAttr.Name, strAccName))
					{
						strAccount.Format("%s", TmpAccAttr.Account);
						break;
					}
				}
			}

			strItemId.Format("%d", TmpSaveStores.Player_2[j].ItemId);
			nIndex = TmpSaveStores.Player_2[j].ItemNum;
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
			if(strlen(TmpSaveStores.Player_3[j].PlayerName) == 0)
				continue;

			if(TmpSaveStores.Player_3[j].TimeStamp > LastTimeStamp)
			{
				if(LastTimeStamp == 0)
				{
					nrow = m_CListCtrlAcc.GetItemCount();//ȡ����
					nItem = m_CListCtrlAcc.InsertItem(nrow+1, _T(""));

					strGold.Format("%d", TmpSaveStores.Player_3_Money);
				}

				LastTimeStamp = TmpSaveStores.Player_3[j].TimeStamp;

				strAccName.Format("%s", TmpSaveStores.Player_3[j].PlayerName);

				pos2 = LCurAccAttr->GetHeadPosition();
				for (k=0;k < LCurAccAttr->GetCount();k++)
				{
					TmpAccAttr = LCurAccAttr->GetNext(pos2);
					if(0 == strcmp(TmpAccAttr.Name, strAccName))
					{
						strAccount.Format("%s", TmpAccAttr.Account);
						break;
					}
				}
			}

			strItemId.Format("%d", TmpSaveStores.Player_3[j].ItemId);
			nIndex = TmpSaveStores.Player_3[j].ItemNum;
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


void CStoreDlg::OnEnChangeEditFindAcc()
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


void CStoreDlg::OnBnClickedButtonFindNextAcc()
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


void CStoreDlg::OnBnClickedButtonUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Common::GetSaveStores();
	InitItemList();
}


void CStoreDlg::OnBnClickedButtonOutput()
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
	strPathName += "\\"+ strDate + "\\�ֿ��б�-" + cdtime +".TXT";

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

		CString strTemp = "���˻�����" + strAccount + " ��ɫ����" + strAccName + " ��" + strGold + "��\n������Ʒ�б�" + strItemList + "\n\n";
		StdFile.WriteString(strTemp);
	}

	StdFile.Close();

	Common::Log(Info, "�б������ɣ�");
}


void CStoreDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent){
	case TIMER1:
		{
			KillTimer(TIMER1);
			SetTimer(TIMER1, 60*60*1000, 0); // ÿ1��Сʱ���һ�α�������
			CTime CurTime = CTime::GetCurrentTime();
			Common::GetSaveStores();
			InitItemList();
			OnBnClickedButtonOutput();
			break;
		}
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
