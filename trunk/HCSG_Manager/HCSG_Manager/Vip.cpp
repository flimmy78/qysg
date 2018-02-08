// Vip.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HCSG_Manager.h"
#include "HCSG_ManagerDlg.h"
#include "Vip.h"
#include "afxdialogex.h"


// CVip �Ի���

IMPLEMENT_DYNAMIC(CVip, CDialogEx)

	CVip::CVip(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVip::IDD, pParent)
{

}

CVip::~CVip()
{
}

void CVip::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ACCOUNT, m_CListCtrlAccount);
	DDX_Control(pDX, IDC_LIST_VIP_ACC, m_CListCtrlVipAcc);
	DDX_Control(pDX, IDC_EDIT_ACC, m_CEditAcc);
	DDX_Control(pDX, IDC_COMBO_MODE, m_CComboBoxMode);
	DDX_Control(pDX, IDC_EDIT_POINT, m_CEditPoint);
	DDX_Control(pDX, IDC_EDIT_NOTE, m_CEditNote);
	DDX_Control(pDX, IDC_EDIT_POINT_1, m_CEditPoint1);
	DDX_Control(pDX, IDC_EDIT_NOTE_1, m_CEditNote1);
	DDX_Control(pDX, IDC_COMBO_VIP_CONFIG, m_CComboBoxVipConfig);
	DDX_Control(pDX, IDC_EDIT_VIP_POINT, m_CEditVipPoint);
	DDX_Control(pDX, IDC_EDIT_VIP_ACC, m_CEditVipAcc);
	DDX_Control(pDX, IDC_COMBO_VIP, m_CComboBoxVip);
	DDX_Control(pDX, IDC_STATIC_ACC_TOTAL, m_CStaticAccTotal);
	DDX_Control(pDX, IDC_EDIT_POINTS, m_CEditPoints);
	DDX_Control(pDX, IDC_EDIT_VIP_DATE, m_CEditVipDate);
	DDX_Control(pDX, IDC_LIST_ITEM, m_CListCtrlItem);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_ID, m_CEditVipItemId);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_ID2, m_CEditVipItemId2);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_ID3, m_CEditVipItemId3);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_ID4, m_CEditVipItemId4);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_ID5, m_CEditVipItemId5);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NAME, m_CEditVipItemName);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NAME2, m_CEditVipItemName2);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NAME3, m_CEditVipItemName3);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NAME4, m_CEditVipItemName4);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NAME5, m_CEditVipItemName5);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NUM, m_CEditVipItemNum);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NUM2, m_CEditVipItemNum2);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NUM3, m_CEditVipItemNum3);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NUM4, m_CEditVipItemNum4);
	DDX_Control(pDX, IDC_EDIT_VIP_ITEM_NUM5, m_CEditVipItemNum5);
	DDX_Control(pDX, IDC_EDIT_FIND_ITEM, m_CEditFindItem);
	DDX_Control(pDX, IDC_EDIT_FIND_ACC, m_CEditFindAcc);
}


BEGIN_MESSAGE_MAP(CVip, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CVip::OnBnClickedButtonUpdate)
	ON_CBN_SELCHANGE(IDC_COMBO_VIP_CONFIG, &CVip::OnCbnSelchangeComboVipConfig)
	ON_BN_CLICKED(ID_SAVE, &CVip::OnBnClickedSave)
	ON_NOTIFY(NM_CLICK, IDC_LIST_ACCOUNT, &CVip::OnNMClickListAccount)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE, &CVip::OnCbnSelchangeComboMode)
	ON_BN_CLICKED(ID_SEND, &CVip::OnBnClickedSend)
	ON_BN_CLICKED(ID_ADD_VIP, &CVip::OnBnClickedAddVip)
	ON_BN_CLICKED(ID_DELETE_VIP, &CVip::OnBnClickedDeleteVip)
	ON_WM_TIMER()
	ON_EN_CHANGE(IDC_EDIT_ACC, &CVip::OnEnChangeEditAcc)
	ON_EN_CHANGE(IDC_EDIT_VIP_ITEM_ID, &CVip::OnEnChangeEditVipItemId)
	ON_EN_CHANGE(IDC_EDIT_VIP_ITEM_ID2, &CVip::OnEnChangeEditVipItemId2)
	ON_EN_CHANGE(IDC_EDIT_VIP_ITEM_ID3, &CVip::OnEnChangeEditVipItemId3)
	ON_EN_CHANGE(IDC_EDIT_VIP_ITEM_ID4, &CVip::OnEnChangeEditVipItemId4)
	ON_EN_CHANGE(IDC_EDIT_VIP_ITEM_ID5, &CVip::OnEnChangeEditVipItemId5)
	ON_NOTIFY(NM_CLICK, IDC_LIST_ITEM, &CVip::OnNMClickListItem)
	ON_BN_CLICKED(IDC_BUTTON_FIND_ITEM, &CVip::OnBnClickedButtonFindItem)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ITEM, &CVip::OnBnClickedButtonFindNextItem)
	ON_EN_CHANGE(IDC_EDIT_FIND_ACC, &CVip::OnEnChangeEditFindAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ACC, &CVip::OnBnClickedButtonFindNextAcc)
	ON_EN_CHANGE(IDC_EDIT_FIND_ITEM, &CVip::OnEnChangeEditFindItem)
END_MESSAGE_MAP()


// CVip ��Ϣ�������


BOOL CVip::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_CListCtrlVipAcc.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlVipAcc.InsertColumn(0, _T("�ʺ�"), LVCFMT_LEFT, 60);
	m_CListCtrlVipAcc.InsertColumn(1, _T("����"), LVCFMT_LEFT, 60);//������
	m_CListCtrlVipAcc.InsertColumn(2, _T("����"), LVCFMT_LEFT, 60);//������
	m_CListCtrlVipAcc.InsertColumn(3, _T("����"), LVCFMT_LEFT, 60);//������
	m_CListCtrlVipAcc.InsertColumn(4, _T("��Ʒһ"), LVCFMT_LEFT, 80);//������
	m_CListCtrlVipAcc.InsertColumn(5, _T("��Ʒ��"), LVCFMT_LEFT, 80);//������
	m_CListCtrlVipAcc.InsertColumn(6, _T("��Ʒ��"), LVCFMT_LEFT, 80);//������
	m_CListCtrlVipAcc.InsertColumn(7, _T("��Ʒ��"), LVCFMT_LEFT, 80);//������
	m_CListCtrlVipAcc.InsertColumn(8, _T("��Ʒ��"), LVCFMT_LEFT, 80);//������

	m_CListCtrlAccount.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlAccount.InsertColumn(0, _T("ע���ʺ�"), LVCFMT_LEFT, 95);
	m_CListCtrlAccount.InsertColumn(1, _T("��ɫ����"), LVCFMT_LEFT, 95);
	m_CListCtrlAccount.InsertColumn(2, _T("���"), LVCFMT_LEFT, 50);//������
	m_CListCtrlAccount.InsertColumn(3, _T("Ȩ��"), LVCFMT_LEFT, 50);//������
	m_CListCtrlAccount.InsertColumn(4, _T("���ҵ�"), LVCFMT_LEFT, 70);
	m_CListCtrlAccount.InsertColumn(5, _T("��¼IP"), LVCFMT_LEFT, 80);

	m_CListCtrlItem.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);
	m_CListCtrlItem.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 30);//������
	m_CListCtrlItem.InsertColumn(1, _T("��Ʒ����"), LVCFMT_LEFT, 100);

	m_CComboBoxMode.SetCurSel(0);
	nMode = 0;
	m_CComboBoxVip.SetCurSel(0);
	m_CComboBoxVipConfig.SetCurSel(0);
	OnCbnSelchangeComboVipConfig();

	m_CEditPoint.SetWindowText("1000");
	m_CEditPoint1.SetWindowText("0");

	m_CEditNote.SetWindowText("1");
	m_CEditNote1.SetWindowText("0");

	UpdataAcc();

	OnCbnSelchangeComboMode();
	
	InitItemDef();

	SetTimer(TIMER1, 10 * 1000, 0);

	m_CEditVipDate.SetWindowText("7");

	ReadVipList();

	return TRUE;  // return TRUE unless you set the focus to a control
}


void CVip::ReadVipList()
{
	CString des="";
	CString StrValue;
	int nVipNum = 0;
	CString strAccount, strVipType, strDate, strPoints;
	CString Key;
	CString temp;
	CString strItemTemp;
	CStringArray strItems;
	int nItem = 0;

	m_CListCtrlVipAcc.DeleteAllItems();
	::GetCurrentDirectory(1024,des.GetBuffer(1024));
	des.ReleaseBuffer();
	des += CONFIG_FILE_PATH;
	des += CONFIG_FILE;

	WaitForSingleObject(Common::hMutex,INFINITE);  // ������
	GetPrivateProfileString("VIPLIST","NUM","",StrValue.GetBuffer(128),128,des);
	ReleaseMutex(Common::hMutex);
	nVipNum = _ttoi(StrValue);
	StrValue.ReleaseBuffer();

	for(int i=0;i < nVipNum;i++)
	{
		CStringArray tempArray;
		Key.Format("VIP-%d", i);
		WaitForSingleObject(Common::hMutex,INFINITE);  // ������
		GetPrivateProfileString("VIPLIST",Key,"",StrValue.GetBuffer(128),128,des);
		ReleaseMutex(Common::hMutex);
		temp = StrValue;
		StrValue.ReleaseBuffer();

		if(temp.IsEmpty()) 
			continue;

		Common::CStringGap(temp, &tempArray,"","#");
		strAccount = tempArray[0];
		strVipType = tempArray[1];
		strDate = tempArray[2];

		//ȷ��VIP����
		char num = strVipType.GetAt(4);
		int index = atoi(&num) - 1;
		CStringArray strTemp; 
		Common::CStringGap(Common::VipAwardsPoints[index],&strTemp,"","#");
		strPoints = strTemp[0];
		strItems.RemoveAll();
		if(strTemp.GetCount() >= 4)
		{
			strItemTemp = strTemp[2] + "x" + strTemp[3];
			strItems.Add(strItemTemp);
		}
		if(strTemp.GetCount() >= 7)
		{
			strItemTemp = strTemp[5] + "x" + strTemp[6];
			strItems.Add(strItemTemp);
		}
		if(strTemp.GetCount() >= 10)
		{
			strItemTemp = strTemp[8] + "x" + strTemp[9];
			strItems.Add(strItemTemp);
		}
		if(strTemp.GetCount() >= 13)
		{
			strItemTemp = strTemp[11] + "x" + strTemp[12];
			strItems.Add(strItemTemp);
		}
		if(strTemp.GetCount() >= 16)
		{
			strItemTemp = strTemp[14] + "x" + strTemp[15];
			strItems.Add(strItemTemp);
		}

		m_CListCtrlVipAcc.InsertItem(nItem, _T(""));
		m_CListCtrlVipAcc.SetItemText(nItem, 0, strAccount);
		m_CListCtrlVipAcc.SetItemText(nItem, 1, strVipType);
		m_CListCtrlVipAcc.SetItemText(nItem, 2, strDate);
		m_CListCtrlVipAcc.SetItemText(nItem, 3, strPoints);
		for(int j=0; j < strItems.GetCount(); j++)
			m_CListCtrlVipAcc.SetItemText(nItem, 4+j, strItems[j]);

		nItem++;
	}
}


void CVip::InitItemDef()
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


void CVip::UpdataAcc()
{
	POSITION pos, pos2;
	struct AccAttr TmpAccAttr;
	CList <AccAttr, AccAttr&> *LCurAccAttr = &Common::LAccAttr;
	CList <GameAcc, GameAcc&> *LCurGameAcc = &Common::LGameAcc;
	m_CListCtrlAccount.DeleteAllItems();

	pos = LCurGameAcc->GetHeadPosition();
	for(int i=0;i < LCurGameAcc->GetCount();i++)
	{
		GameAcc TmpGameAcc = LCurGameAcc->GetNext(pos);
		CString AccountID = TmpGameAcc.account;

		int nrow = m_CListCtrlAccount.GetItemCount();//ȡ����
		int nItem = m_CListCtrlAccount.InsertItem(nrow+1, _T(""));
		m_CListCtrlAccount.SetItemText(nItem, 0, AccountID);

		pos2 = LCurAccAttr->GetHeadPosition();
		for (int j=0;j < LCurAccAttr->GetCount();j++)
		{
			TmpAccAttr = LCurAccAttr->GetNext(pos2);
			if(0 == strcmp(TmpAccAttr.Account, AccountID))
				m_CListCtrlAccount.SetItemText(nItem, 1, _T(Common::Big2GB(TmpAccAttr.Name)));
		}

		m_CListCtrlAccount.SetItemText(nItem, 2, TmpGameAcc.enable);
		m_CListCtrlAccount.SetItemText(nItem, 3, TmpGameAcc.privilege);
		m_CListCtrlAccount.SetItemText(nItem, 4, TmpGameAcc.point);
		m_CListCtrlAccount.SetItemText(nItem, 5, TmpGameAcc.ip);
	}

	m_CStaticAccTotal.SetWindowText(Common::convert(m_CListCtrlAccount.GetItemCount()));
}


void CVip::OnBnClickedButtonUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Common::GetGameAccFormDB();
	Common::GetAccAttr();
	UpdataAcc();
}


void CVip::OnCbnSelchangeComboVipConfig()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = m_CComboBoxVipConfig.GetCurSel();

	//ȷ��VIP����
	CStringArray strTemp; 
	Common::CStringGap(Common::VipAwardsPoints[nIndex],&strTemp,"","#");
	m_CEditVipPoint.SetWindowText(strTemp[0]);

	m_CEditVipItemId.SetWindowText("");
	m_CEditVipItemId2.SetWindowText("");
	m_CEditVipItemId3.SetWindowText("");
	m_CEditVipItemId4.SetWindowText("");
	m_CEditVipItemId5.SetWindowText("");

	m_CEditVipItemName.SetWindowText("");
	m_CEditVipItemName2.SetWindowText("");
	m_CEditVipItemName3.SetWindowText("");
	m_CEditVipItemName4.SetWindowText("");
	m_CEditVipItemName5.SetWindowText("");

	m_CEditVipItemNum.SetWindowText("");
	m_CEditVipItemNum2.SetWindowText("");
	m_CEditVipItemNum3.SetWindowText("");
	m_CEditVipItemNum4.SetWindowText("");
	m_CEditVipItemNum5.SetWindowText("");

	if(strTemp.GetCount() >= 4)
	{
		m_CEditVipItemId.SetWindowText(strTemp[1]);
		m_CEditVipItemName.SetWindowText(strTemp[2]);
		m_CEditVipItemNum.SetWindowText(strTemp[3]);
	}
	if(strTemp.GetCount() >= 7)
	{
		m_CEditVipItemId2.SetWindowText(strTemp[4]);
		m_CEditVipItemName2.SetWindowText(strTemp[5]);
		m_CEditVipItemNum2.SetWindowText(strTemp[6]);
	}
	if(strTemp.GetCount() >= 10)
	{
		m_CEditVipItemId3.SetWindowText(strTemp[7]);
		m_CEditVipItemName3.SetWindowText(strTemp[8]);
		m_CEditVipItemNum3.SetWindowText(strTemp[9]);
	}
	if(strTemp.GetCount() >= 13)
	{
		m_CEditVipItemId4.SetWindowText(strTemp[10]);
		m_CEditVipItemName4.SetWindowText(strTemp[11]);
		m_CEditVipItemNum4.SetWindowText(strTemp[12]);
	}
	if(strTemp.GetCount() >= 16)
	{
		m_CEditVipItemId5.SetWindowText(strTemp[13]);
		m_CEditVipItemName5.SetWindowText(strTemp[14]);
		m_CEditVipItemNum5.SetWindowText(strTemp[15]);
	}
}


void CVip::OnBnClickedSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	struct ItemDef TmpItemDef;
	CList <ItemDef, ItemDef&> *LCurItemDef = &Common::LItemDef;
	POSITION pos;
	int i;

	int nIndex = m_CComboBoxVipConfig.GetCurSel();
	CString VipAwardsTemp;
	CString strPoint;
	CString strItemId, strItemId2, strItemId3, strItemId4, strItemId5;
	CString strItemName, strItemName2, strItemName3, strItemName4, strItemName5;
	CString strItemNum, strItemNum2, strItemNum3, strItemNum4, strItemNum5;
	m_CEditVipPoint.GetWindowText(strPoint);
	m_CEditVipItemId.GetWindowText(strItemId);
	m_CEditVipItemId2.GetWindowText(strItemId2);
	m_CEditVipItemId3.GetWindowText(strItemId3);
	m_CEditVipItemId4.GetWindowText(strItemId4);
	m_CEditVipItemId5.GetWindowText(strItemId5);
	m_CEditVipItemName.GetWindowText(strItemName);
	m_CEditVipItemName2.GetWindowText(strItemName2);
	m_CEditVipItemName3.GetWindowText(strItemName3);
	m_CEditVipItemName4.GetWindowText(strItemName4);
	m_CEditVipItemName5.GetWindowText(strItemName5);
	m_CEditVipItemNum.GetWindowText(strItemNum);
	m_CEditVipItemNum2.GetWindowText(strItemNum2);
	m_CEditVipItemNum3.GetWindowText(strItemNum3);
	m_CEditVipItemNum4.GetWindowText(strItemNum4);
	m_CEditVipItemNum5.GetWindowText(strItemNum5);

	if(strPoint.IsEmpty())  strPoint = "0";
	if(strItemId.IsEmpty()) {strItemName = ""; strItemNum = "";}
	if(strItemId2.IsEmpty()) {strItemName2 = ""; strItemNum2 = "";}
	if(strItemId3.IsEmpty()) {strItemName3 = ""; strItemNum3 = "";}
	if(strItemId4.IsEmpty()) {strItemName4 = ""; strItemNum4 = "";}
	if(strItemId5.IsEmpty()) {strItemName5 = ""; strItemNum5 = "";}

	VipAwardsTemp = strPoint;

	//ȷ����Ʒһ�Ƿ����
	if(!strItemId.IsEmpty())
	{
		CString strItemIdTemp = strItemId;
		CString strItemNameTemp = strItemName;
		CString strItemNumTemp = strItemNum;

		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			CString tempName = TmpItemDef.Name;
			tempName.Replace("item_", "");

			if(strItemIdTemp == TmpItemDef.ID && strItemNameTemp == Common::Big2GB((LPSTR)(LPCTSTR)tempName))
				break;
		}

		if(i >= LCurItemDef->GetCount())
		{
			AfxMessageBox("�趨����Ʒ�����ڣ��޷���������");
			return;
		}

		if(!strItemNumTemp.IsEmpty() && _ttoi(strItemNumTemp) > 0)
		{
			VipAwardsTemp += "#" + strItemIdTemp + "#" + strItemNameTemp + "#" + strItemNumTemp;
		}
	}

	//ȷ����Ʒ���Ƿ����
	if(!strItemId2.IsEmpty())
	{
		CString strItemIdTemp = strItemId2;
		CString strItemNameTemp = strItemName2;
		CString strItemNumTemp = strItemNum2;

		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			CString tempName = TmpItemDef.Name;
			tempName.Replace("item_", "");

			if(strItemIdTemp == TmpItemDef.ID && strItemNameTemp == Common::Big2GB((LPSTR)(LPCTSTR)tempName))
				break;
		}

		if(i >= LCurItemDef->GetCount())
		{
			AfxMessageBox("�趨����Ʒ�����ڣ��޷���������");
			return;
		}

		if(!strItemNumTemp.IsEmpty() && _ttoi(strItemNumTemp) > 0)
		{
			VipAwardsTemp += "#" + strItemIdTemp + "#" + strItemNameTemp + "#" + strItemNumTemp;
		}
	}

	//ȷ����Ʒ���Ƿ����
	if(!strItemId3.IsEmpty())
	{
		CString strItemIdTemp = strItemId3;
		CString strItemNameTemp = strItemName3;
		CString strItemNumTemp = strItemNum3;

		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			CString tempName = TmpItemDef.Name;
			tempName.Replace("item_", "");

			if(strItemIdTemp == TmpItemDef.ID && strItemNameTemp == Common::Big2GB((LPSTR)(LPCTSTR)tempName))
				break;
		}

		if(i >= LCurItemDef->GetCount())
		{
			AfxMessageBox("�趨����Ʒ�����ڣ��޷���������");
			return;
		}

		if(!strItemNumTemp.IsEmpty() && _ttoi(strItemNumTemp) > 0)
		{
			VipAwardsTemp += "#" + strItemIdTemp + "#" + strItemNameTemp + "#" + strItemNumTemp;
		}
	}

	//ȷ����Ʒ���Ƿ����
	if(!strItemId4.IsEmpty())
	{
		CString strItemIdTemp = strItemId4;
		CString strItemNameTemp = strItemName4;
		CString strItemNumTemp = strItemNum4;

		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			CString tempName = TmpItemDef.Name;
			tempName.Replace("item_", "");

			if(strItemIdTemp == TmpItemDef.ID && strItemNameTemp == Common::Big2GB((LPSTR)(LPCTSTR)tempName))
				break;
		}

		if(i >= LCurItemDef->GetCount())
		{
			AfxMessageBox("�趨����Ʒ�����ڣ��޷���������");
			return;
		}

		if(!strItemNumTemp.IsEmpty() && _ttoi(strItemNumTemp) > 0)
		{
			VipAwardsTemp += "#" + strItemIdTemp + "#" + strItemNameTemp + "#" + strItemNumTemp;
		}
	}

	//ȷ����Ʒ���Ƿ����
	if(!strItemId5.IsEmpty())
	{
		CString strItemIdTemp = strItemId5;
		CString strItemNameTemp = strItemName5;
		CString strItemNumTemp = strItemNum5;

		pos = LCurItemDef->GetHeadPosition();
		for (i=0;i < LCurItemDef->GetCount();i++)
		{
			TmpItemDef = LCurItemDef->GetNext(pos);

			CString tempName = TmpItemDef.Name;
			tempName.Replace("item_", "");

			if(strItemIdTemp == TmpItemDef.ID && strItemNameTemp == Common::Big2GB((LPSTR)(LPCTSTR)tempName))
				break;
		}

		if(i >= LCurItemDef->GetCount())
		{
			AfxMessageBox("�趨����Ʒ�����ڣ��޷���������");
			return;
		}

		if(!strItemNumTemp.IsEmpty() && _ttoi(strItemNumTemp) > 0)
		{
			VipAwardsTemp += "#" + strItemIdTemp + "#" + strItemNameTemp + "#" + strItemNumTemp;
		}
	}

	Common::VipAwardsPoints[nIndex] = VipAwardsTemp;
	Common::SaveConfig();

	// ˢ��VIP�б�����
	ReadVipList();
}


void CVip::OnNMClickListAccount(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int ListIndex = m_CListCtrlAccount.GetSelectionMark();
	if(ListIndex == -1) return;
	m_CEditAcc.SetWindowText(m_CListCtrlAccount.GetItemText(ListIndex, 0));
	m_CEditPoints.SetWindowText(m_CListCtrlAccount.GetItemText(ListIndex, 4));
	m_CEditVipAcc.SetWindowText(m_CListCtrlAccount.GetItemText(ListIndex, 0));
}


void CVip::OnCbnSelchangeComboMode()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = m_CComboBoxMode.GetCurSel();
	if(0 == nIndex)
	{
		m_CEditPoint.SetReadOnly(FALSE);
		m_CEditPoint1.SetReadOnly(FALSE);
		m_CEditNote.SetReadOnly(TRUE);
		m_CEditNote1.SetReadOnly(TRUE);
		nMode = 0;
	}
	else if (1 == nIndex)
	{
		m_CEditNote.SetReadOnly(FALSE);
		m_CEditNote1.SetReadOnly(FALSE);
		m_CEditPoint.SetReadOnly(TRUE);
		m_CEditPoint1.SetReadOnly(TRUE);
		nMode = 1;
	}
}


void CVip::OnBnClickedSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;
	POSITION pos;
	CList <GameAcc, GameAcc&> *LCurGameAcc = &Common::LGameAcc;
	CString strAccount;
	m_CEditAcc.GetWindowText(strAccount);
	// ȷ���ʺ��Ƿ����
	pos = LCurGameAcc->GetHeadPosition();
	for(i=0;i < LCurGameAcc->GetCount();i++)
	{
		GameAcc TmpGameAcc = LCurGameAcc->GetNext(pos);
		CString AccountID = TmpGameAcc.account;

		if(AccountID == strAccount)
		{
			break;
		}
	}
	if(i >= LCurGameAcc->GetCount())
	{
		AfxMessageBox("�ʺŲ����ڣ��޷���ֵ��");
		return;
	}

	if(0 == nMode)
	{
		if(Common::m_pConnection == NULL)
		{
			Common::Log(Info, "���ݿ�δ����");
			return;
		}

		CString strPoint, strPoint1, AccCurPoints;
		int nTotalPoints = 0, nAddPoints = 0;
		m_CEditPoint.GetWindowText(strPoint);
		m_CEditPoint1.GetWindowText(strPoint1);
		nTotalPoints = _ttoi(strPoint) + _ttoi(strPoint1);
		nAddPoints = nTotalPoints;

		if(nTotalPoints <= 0)
			return;

		CString tmp22;
		tmp22.Format("�Ƿ���%s����%d�������ң�", strAccount, nAddPoints);
		if (IDYES != AfxMessageBox(tmp22 , MB_YESNO))
			return;

		m_CEditPoints.GetWindowText(AccCurPoints);
		nTotalPoints += _ttoi(AccCurPoints);

		if(Common::AddPoints(nAddPoints, strAccount, "�ֶ�����") == "ת�̳Ǵ��ҳɹ�")
		{
			tmp22.Format("��%s����%d�������ҳɹ�����ע����գ�", strAccount, nTotalPoints);
			Common::Log(Info, tmp22);
			AfxMessageBox(tmp22);			
		}
		else
		{
			Common::Log(Error, "���ҷ���ʧ��");
			AfxMessageBox("���ҷ���ʧ��");
			return;
		}

		m_CEditPoints.SetWindowText(Common::convert(nTotalPoints));
		Common::GetGameAccFormDB();
		UpdataAcc();
	}
	else if(1 == nMode)
	{
		if(Common::m_pConnXb == NULL)
		{
			Common::Log(Info, "���ݿ�δ����");
			return;
		}

		CString strNote, strNote1;
		int nTotalNote = 0;
		m_CEditNote.GetWindowText(strNote);
		m_CEditNote1.GetWindowText(strNote1);
		nTotalNote = _ttoi(strNote) + _ttoi(strNote1);

		if(nTotalNote <= 0)
			return;

		CString tmp22;
		tmp22.Format("�Ƿ���%s����%d����Ʊ��", strAccount, nTotalNote);
		if (IDYES != AfxMessageBox(tmp22, MB_YESNO) )
			return;
		CStringArray ItemList;
		ItemList.Add("5090");
		ItemList.Add(Common::convert(nTotalNote));
		if(!Common::SendXubao(strAccount, &ItemList))
		{
			Common::Log(Error, "������Ʊʧ��");
			AfxMessageBox("������Ʊʧ��");
			return;
		}
		else
		{
			tmp22.Format("��%s����%d����Ʊ�ɹ�����֪ͨȥ����ʹ���ȡ��", strAccount, nTotalNote);
			Common::Log(Info, tmp22);
			AfxMessageBox(tmp22);
		}
	}
}


void CVip::OnBnClickedAddVip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strAccount, strVipType, strDate, strPoints;
	CString strItemTemp;
	CStringArray strItems;
	BOOL bFound = FALSE;
	int i,j;
	m_CComboBoxVip.GetWindowText(strVipType);
	m_CEditVipAcc.GetWindowTextA(strAccount);
	m_CEditVipDate.GetWindowText(strDate);

	if(strAccount.IsEmpty())
		return;

	//ȷ��VIP����
	char num = strVipType.GetAt(4);
	int index = atoi(&num) - 1;
	CStringArray strTemp; 
	Common::CStringGap(Common::VipAwardsPoints[index],&strTemp,"","#");
	strPoints = strTemp[0];
	strItems.RemoveAll();
	if(strTemp.GetCount() >= 4)
	{
		strItemTemp = strTemp[2] + "x" + strTemp[3];
		strItems.Add(strItemTemp);
	}
	if(strTemp.GetCount() >= 7)
	{
		strItemTemp = strTemp[5] + "x" + strTemp[6];
		strItems.Add(strItemTemp);
	}
	if(strTemp.GetCount() >= 10)
	{
		strItemTemp = strTemp[8] + "x" + strTemp[9];
		strItems.Add(strItemTemp);
	}
	if(strTemp.GetCount() >= 13)
	{
		strItemTemp = strTemp[11] + "x" + strTemp[12];
		strItems.Add(strItemTemp);
	}
	if(strTemp.GetCount() >= 16)
	{
		strItemTemp = strTemp[14] + "x" + strTemp[15];
		strItems.Add(strItemTemp);
	}


	int nrow = m_CListCtrlVipAcc.GetItemCount();//ȡ����
	for(i=0; i< nrow; i++)
	{
		CString temp;
		temp = m_CListCtrlVipAcc.GetItemText(i, 0);
		if(strAccount.Compare(temp) == 0)
		{
			bFound = TRUE;
			break;
		}
	}
	if(bFound)
	{
		m_CListCtrlVipAcc.SetItemText(i, 1, strVipType);
		m_CListCtrlVipAcc.SetItemText(i, 2, strDate);
		m_CListCtrlVipAcc.SetItemText(i, 3, strPoints);
		for(j=0; j < strItems.GetCount(); j++)
			m_CListCtrlVipAcc.SetItemText(i, 4+j, strItems[j]);
	}
	else
	{
		int nItem = m_CListCtrlVipAcc.InsertItem(nrow+1, _T(""));

		m_CListCtrlVipAcc.SetItemText(nItem, 0, strAccount);
		m_CListCtrlVipAcc.SetItemText(nItem, 1, strVipType);
		m_CListCtrlVipAcc.SetItemText(nItem, 2, strDate);
		m_CListCtrlVipAcc.SetItemText(nItem, 3, strPoints);
		for(j=0; j < strItems.GetCount(); j++)
			m_CListCtrlVipAcc.SetItemText(nItem, 4+j, strItems[j]);
	}

	CString Key;
	CString StrValue;
	CString des="";
	::GetCurrentDirectory(1024,des.GetBuffer(1024));
	des.ReleaseBuffer();
	des += CONFIG_FILE_PATH;
	des += CONFIG_FILE;
	nrow = m_CListCtrlVipAcc.GetItemCount();//ȡ����
	WaitForSingleObject(Common::hMutex,INFINITE);  // ������
	WritePrivateProfileString("VIPLIST","NUM",Common::convert(nrow),des);
	ReleaseMutex(Common::hMutex);
	for(i=0; i< nrow; i++)
	{
		strAccount = m_CListCtrlVipAcc.GetItemText(i, 0);
		strVipType = m_CListCtrlVipAcc.GetItemText(i, 1);
		strDate = m_CListCtrlVipAcc.GetItemText(i, 2);
		Key.Format("VIP-%d", i);
		StrValue = strAccount + "#" + strVipType + "#" + strDate;
		WaitForSingleObject(Common::hMutex,INFINITE);  // ������
		WritePrivateProfileString("VIPLIST",Key,StrValue,des);
		ReleaseMutex(Common::hMutex);
	}
}


void CVip::OnBnClickedDeleteVip()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ListIndex  = m_CListCtrlVipAcc.GetSelectionMark();
	if(ListIndex == -1) return;
	m_CListCtrlVipAcc.DeleteItem(ListIndex);//ɾ��ѡ����

	CString strAccount, strVipType, strDate, strPoints;
	CString Key;
	CString StrValue;
	int i;
	CString des="";
	::GetCurrentDirectory(1024,des.GetBuffer(1024));
	des.ReleaseBuffer();
	des += CONFIG_FILE_PATH;
	des += CONFIG_FILE;
	int nrow = m_CListCtrlVipAcc.GetItemCount();//ȡ����
	WaitForSingleObject(Common::hMutex,INFINITE);  // ������
	WritePrivateProfileString("VIPLIST","NUM",Common::convert(nrow),des);
	for(i=0; i< nrow; i++)
	{
		strAccount = m_CListCtrlVipAcc.GetItemText(i, 0);
		strVipType = m_CListCtrlVipAcc.GetItemText(i, 1);
		strDate = m_CListCtrlVipAcc.GetItemText(i, 2);
		Key.Format("VIP-%d", i);
		StrValue = strAccount + "#" + strVipType + "#" + strDate;
		WaitForSingleObject(Common::hMutex,INFINITE);  // ������
		WritePrivateProfileString("VIPLIST",Key,StrValue,des);
		ReleaseMutex(Common::hMutex);
	}

	Key.Format("VIP-%d", i);  //delete VIP
	StrValue = "";
	WaitForSingleObject(Common::hMutex,INFINITE);  // ������
	WritePrivateProfileString("VIPLIST",Key,StrValue,des);
	ReleaseMutex(Common::hMutex);
}


void CVip::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nIDEvent){
	case TIMER1:
		{
			KillTimer(TIMER1);
			SetTimer(TIMER1, 60*60*1000, 0); // ÿ1��Сʱ����Ƿ���Ҫ���Ž���
			CTime CurTime = CTime::GetCurrentTime();
			int h=CurTime.GetHour(); //��ȡ��ǰΪ��ʱ

			if(0 == h)  // ��㷢��VIP����
				SendPointToVip();
			break;
		}
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CVip::SendPointToVip()
{
	int i, j;
	CString strInsert;
	CString SQLInSertCmd;
	_variant_t strValue;
	CString strAccount, strVipType, strDate, strPoints, AccCurPoints, strItemName;
	int nTotalPoints = 0, nSendPoint = 0;
	_variant_t RecordsAffected;
	POSITION pos;
	CList <GameAcc, GameAcc&> *LCurGameAcc = &Common::LGameAcc;
	CStringArray strItems;

	Common::Log(Info, "��ʼ����VIP���Һ���Ʒ��");

	CString Key;
	CString StrValue;
	CString des="";
	::GetCurrentDirectory(1024,des.GetBuffer(1024));
	des.ReleaseBuffer();
	des += CONFIG_FILE_PATH;
	des += CONFIG_FILE;

	int nrow = m_CListCtrlVipAcc.GetItemCount();//ȡ����
	for(i=0; i< nrow; i++)
	{
		strAccount = m_CListCtrlVipAcc.GetItemText(i, 0);
		// ȷ���ʺ��Ƿ����
		pos = LCurGameAcc->GetHeadPosition();
		for(j=0;j < LCurGameAcc->GetCount();j++)
		{
			GameAcc TmpGameAcc = LCurGameAcc->GetNext(pos);
			CString AccountID = TmpGameAcc.account;

			if(AccountID == strAccount)
			{
				break;
			}
		}
		if(j >= LCurGameAcc->GetCount())
		{
			Common::Log(Error, "�ʺŲ����ڣ��޷����ţ�ID: " + strAccount);
			continue;
		}

		strVipType = m_CListCtrlVipAcc.GetItemText(i, 1);
		strDate = m_CListCtrlVipAcc.GetItemText(i, 2);
		strPoints = m_CListCtrlVipAcc.GetItemText(i, 3);
		strItemName = m_CListCtrlVipAcc.GetItemText(i, 4);

		if(_ttoi(strDate) <= 0) continue;

		//ȷ��VIP����
		char num = strVipType.GetAt(4);
		int index = atoi(&num) - 1;
		CStringArray strTemp; 
		Common::CStringGap(Common::VipAwardsPoints[index],&strTemp,"","#");
		nSendPoint = _ttoi(strTemp[0]);  //�����Ҫ���ŵĵ���
		strItems.RemoveAll();
		if(strTemp.GetCount() >= 4)
		{
			strItems.Add(strTemp[1]);
			strItems.Add(strTemp[3]);
		}
		if(strTemp.GetCount() >= 7)
		{
			strItems.Add(strTemp[4]);
			strItems.Add(strTemp[6]);
		}
		if(strTemp.GetCount() >= 10)
		{
			strItems.Add(strTemp[7]);
			strItems.Add(strTemp[9]);
		}
		if(strTemp.GetCount() >= 13)
		{
			strItems.Add(strTemp[10]);
			strItems.Add(strTemp[12]);
		}
		if(strTemp.GetCount() >= 16)
		{
			strItems.Add(strTemp[13]);
			strItems.Add(strTemp[15]);
		}

		if(nSendPoint > 0)
		{
			if(Common::m_pConnection == NULL)
			{
				Common::Log(Info, "���ݿ�δ����");
				return;
			}
// 			strInsert.Format("SELECT point from game_acc where account='%s'", strAccount);
// 			SQLInSertCmd = strInsert;
// 			_variant_t sql;
// 			sql = SQLInSertCmd;
// 			try
// 			{
// 				Common::m_pRecordset = Common::m_pConnection->Execute((_bstr_t)sql, &RecordsAffected, adCmdText);
// 				if(!SUCCEEDED(Common::m_pRecordset))
// 				{
// 					continue;
// 				}
// 			}
// 			catch(_com_error &e) 
// 			{ 
// 				Common::Log(Info, (LPCSTR)(e.Description())); 
// 				continue;
// 			}
// 
// 			strValue = Common::m_pRecordset->GetCollect("point");
// 			AccCurPoints = (strValue.vt != VT_NULL) ? strValue : "0";
// 
// 			nTotalPoints = nSendPoint + _ttoi(AccCurPoints);

			if(Common::AddPoints(nSendPoint, strAccount, "VIP�û�����") == "ת�̳Ǵ��ҳɹ�")
			{
				CString tmp22;
				tmp22.Format("��%s����%d���ҳɹ���", strAccount, nSendPoint);
				Common::Log(Info, tmp22);
			}
			else
			{				
				Common::Log(Error, "VIP���ҷ���ʧ��");
				continue;
			}
		}

		if(strItems.GetCount() > 0)
		{
			if(Common::m_pConnXb == NULL)
			{
				Common::Log(Info, "���ݿ�δ����");
				return;
			}

			CStringArray ItemList;
			for(j=0; j < strItems.GetCount();)
			{
				ItemList.Add(strItems[j++]);   // ���ID��
				ItemList.Add(strItems[j++]);   // �������
			}			
			if(!Common::SendXubao(strAccount, &ItemList))
			{
				Common::Log(Error, "����VIP��Ʒʧ��");
				continue;;
			}
			else
			{
				CString tmp22;
				tmp22.Format("��%s����VIP��Ʒ�ɹ�����֪ͨȥ����ʹ���ȡ��", strAccount);
				Common::Log(Info, tmp22);
			}
		}
		
		CString tt;
		tt.Format("%d", _ttoi(strDate) - 1);
		m_CListCtrlVipAcc.SetItemText(i, 2, tt);

		Key.Format("VIP-%d", i);
		StrValue = strAccount + "#" + strVipType + "#" + tt;
		WaitForSingleObject(Common::hMutex,INFINITE);  // ������
		WritePrivateProfileString("VIPLIST",Key,StrValue,des);
		ReleaseMutex(Common::hMutex);
	}

	nrow = m_CListCtrlVipAcc.GetItemCount();//ȡ����
	for(i=nrow-1; i>=0; i--)
	{
		strDate = m_CListCtrlVipAcc.GetItemText(i, 2);
		if(strDate == "0")
		{
			m_CListCtrlVipAcc.DeleteItem(i);
			Key.Format("VIP-%d", i);
			StrValue = "";
			WaitForSingleObject(Common::hMutex,INFINITE);  // ������
			WritePrivateProfileString("VIPLIST",Key,StrValue,des);	
			ReleaseMutex(Common::hMutex);
			m_CListCtrlVipAcc.DeleteItem(i);
		}
	}

	ReadVipList();

	nrow = m_CListCtrlVipAcc.GetItemCount();//ȡ����
	WaitForSingleObject(Common::hMutex,INFINITE);  // ������
	WritePrivateProfileString("VIPLIST","NUM",Common::convert(nrow),des);
	ReleaseMutex(Common::hMutex);
	m_CListCtrlVipAcc.DeleteItem(i);
	for(i=0; i< nrow; i++)
	{
		strAccount = m_CListCtrlVipAcc.GetItemText(i, 0);
		strVipType = m_CListCtrlVipAcc.GetItemText(i, 1);
		strDate = m_CListCtrlVipAcc.GetItemText(i, 2);
		strPoints = m_CListCtrlVipAcc.GetItemText(i, 3);
		strItemName = m_CListCtrlVipAcc.GetItemText(i, 4);
		Key.Format("VIP-%d", i);
		StrValue = strAccount + "#" + strVipType + "#" + strDate;
		WaitForSingleObject(Common::hMutex,INFINITE);  // ������
		WritePrivateProfileString("VIPLIST",Key,StrValue,des);
		ReleaseMutex(Common::hMutex);
	}
	OnBnClickedButtonUpdate();
	OnEnChangeEditAcc();

	Common::Log(Info, "����VIP���Һ���Ʒ������");
}


void CVip::OnEnChangeEditAcc()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int i;
	POSITION pos;
	CList <GameAcc, GameAcc&> *LCurGameAcc = &Common::LGameAcc;
	CString strEnter;

	m_CEditAcc.GetWindowText(strEnter);

	pos = LCurGameAcc->GetHeadPosition();
	for(i=0;i < LCurGameAcc->GetCount();i++)
	{
		GameAcc TmpGameAcc = LCurGameAcc->GetNext(pos);
		CString AccountID = TmpGameAcc.account;

		if(AccountID == strEnter)
		{
			m_CEditPoints.SetWindowText(TmpGameAcc.point);
			break;
		}
	}
	if(i >= LCurGameAcc->GetCount())
	{
		m_CEditPoints.SetWindowText("0");
	}
}


void CVip::OnEnChangeEditVipItemId()
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
	m_CEditVipItemId.GetWindowText(strItemId);

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

				m_CEditVipItemName.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditVipItemName.SetWindowText("");
		}
	}
	else
	{
		m_CEditVipItemName.SetWindowText("");
	}
}


void CVip::OnEnChangeEditVipItemId2()
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
	m_CEditVipItemId2.GetWindowText(strItemId);

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

				m_CEditVipItemName2.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditVipItemName2.SetWindowText("");
		}
	}
	else
	{
		m_CEditVipItemName2.SetWindowText("");
	}
}


void CVip::OnEnChangeEditVipItemId3()
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
	m_CEditVipItemId3.GetWindowText(strItemId);

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

				m_CEditVipItemName3.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditVipItemName3.SetWindowText("");
		}
	}
	else
	{
		m_CEditVipItemName3.SetWindowText("");
	}
}


void CVip::OnEnChangeEditVipItemId4()
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
	m_CEditVipItemId4.GetWindowText(strItemId);

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

				m_CEditVipItemName4.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditVipItemName4.SetWindowText("");
		}
	}
	else
	{
		m_CEditVipItemName4.SetWindowText("");
	}
}


void CVip::OnEnChangeEditVipItemId5()
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
	m_CEditVipItemId5.GetWindowText(strItemId);

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

				m_CEditVipItemName5.SetWindowText(Common::Big2GB((LPSTR)(LPCTSTR)tempName));
				break;
			}
		}

		if(i >= LCurItemDef->GetCount())
		{
			m_CEditVipItemName5.SetWindowText("");
		}
	}
	else
	{
		m_CEditVipItemName5.SetWindowText("");
	}
}


void CVip::OnNMClickListItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CString strValue;

	int ListIndex = m_CListCtrlItem.GetSelectionMark();
	if(ListIndex == -1) return;

	m_CEditVipItemId.GetWindowText(strValue);
	if(strValue.IsEmpty())
		m_CEditVipItemId.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));

	m_CEditVipItemId2.GetWindowText(strValue);
	if(strValue.IsEmpty())
		m_CEditVipItemId2.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));

	m_CEditVipItemId3.GetWindowText(strValue);
	if(strValue.IsEmpty())
		m_CEditVipItemId3.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));

	m_CEditVipItemId4.GetWindowText(strValue);
	if(strValue.IsEmpty())
		m_CEditVipItemId4.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));

	m_CEditVipItemId5.GetWindowText(strValue);
	if(strValue.IsEmpty())
		m_CEditVipItemId5.SetWindowText(m_CListCtrlItem.GetItemText(ListIndex, 0));
}


void CVip::OnBnClickedButtonFindItem()
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


void CVip::OnBnClickedButtonFindNextItem()
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


void CVip::OnEnChangeEditFindAcc()
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

	iColumnNum = m_CListCtrlAccount.GetHeaderCtrl()->GetItemCount();
	iRowCount = m_CListCtrlAccount.GetItemCount();

	for (int j=0 ; j<iRowCount ; j++ )
	{
		memset(chTemp, 0 ,32);
		for ( int i=0 ; i<iColumnNum ; i++ )
		{
			m_CListCtrlAccount.GetItemText(j,i,chTemp, 32);
			if(strstr(chTemp,strKey))
			{
				ListIndex = j;
				goto BreakLoop;
			}
		}
	}
BreakLoop:
	m_CListCtrlAccount.SetFocus();  
	m_CListCtrlAccount.SetItemState(ListIndex, LVIS_SELECTED, LVIS_SELECTED);
	m_CListCtrlAccount.SetSelectionMark(ListIndex);
	m_CListCtrlAccount.EnsureVisible(ListIndex, FALSE);
	::SendMessage(m_CListCtrlAccount.m_hWnd,  LVM_SETEXTENDEDLISTVIEWSTYLE,  
		LVS_EX_FULLROWSELECT,  LVS_EX_FULLROWSELECT); 

	m_CEditFindAcc.SetFocus();
}


void CVip::OnBnClickedButtonFindNextAcc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strKey;
	int iColumnNum,iRowCount;
	char chTemp[32];
	int ListIndex = 0;
	int iCurListIndex  = m_CListCtrlAccount.GetSelectionMark();

	m_CEditFindAcc.GetWindowText(strKey);
	if(strKey.IsEmpty()) return;

	iColumnNum = m_CListCtrlAccount.GetHeaderCtrl()->GetItemCount();
	iRowCount = m_CListCtrlAccount.GetItemCount();

	int j = iCurListIndex + 1;
	do
	{
		memset(chTemp, 0 ,32);
		for ( int i=0 ; i<2 ; i++ )  // ֻ�����˻����ͽ�ɫ��
		{
			m_CListCtrlAccount.GetItemText(j,i,chTemp, 32);
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
	m_CListCtrlAccount.SetFocus();  
	m_CListCtrlAccount.SetItemState(ListIndex, LVIS_SELECTED, LVIS_SELECTED);
	m_CListCtrlAccount.SetSelectionMark(ListIndex);
	m_CListCtrlAccount.EnsureVisible(ListIndex, FALSE);
	::SendMessage(m_CListCtrlAccount.m_hWnd,  LVM_SETEXTENDEDLISTVIEWSTYLE,  
		LVS_EX_FULLROWSELECT,  LVS_EX_FULLROWSELECT); 
}


void CVip::OnEnChangeEditFindItem()
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

	m_CEditFindItem.SetFocus();
}
