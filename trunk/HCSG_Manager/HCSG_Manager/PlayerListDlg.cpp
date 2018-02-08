// PlayerListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HCSG_Manager.h"
#include "PlayerListDlg.h"
#include "afxdialogex.h"


// CPlayerListDlg �Ի���

IMPLEMENT_DYNAMIC(CPlayerListDlg, CDialogEx)

CPlayerListDlg::CPlayerListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlayerListDlg::IDD, pParent)
{

}

CPlayerListDlg::~CPlayerListDlg()
{
}

void CPlayerListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ACC, m_CListCtrlAcc);
	DDX_Control(pDX, IDC_EDIT_FIND_ACC, m_CEditFindAcc);
	DDX_Control(pDX, IDC_STATIC_ACC_TOTAL, m_CStaticAccTotal);
}


BEGIN_MESSAGE_MAP(CPlayerListDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_FIND_ACC, &CPlayerListDlg::OnEnChangeEditFindAcc)
	ON_BN_CLICKED(IDC_BUTTON_FIND_NEXT_ACC, &CPlayerListDlg::OnBnClickedButtonFindNextAcc)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CPlayerListDlg::OnBnClickedButtonUpdate)
END_MESSAGE_MAP()


// CPlayerListDlg ��Ϣ�������



BOOL CPlayerListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
}

void CPlayerListDlg::OnEnChangeEditFindAcc()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CPlayerListDlg::OnBnClickedButtonFindNextAcc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPlayerListDlg::OnBnClickedButtonUpdate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
