#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CPlayerListDlg �Ի���

class CPlayerListDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayerListDlg)

public:
	CPlayerListDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPlayerListDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_PLAYERLIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_CListCtrlAcc;
	CEdit m_CEditFindAcc;
	afx_msg void OnEnChangeEditFindAcc();
	afx_msg void OnBnClickedButtonFindNextAcc();
	afx_msg void OnBnClickedButtonUpdate();
	CStatic m_CStaticAccTotal;
	virtual BOOL OnInitDialog();
};
