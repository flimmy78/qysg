#pragma once
#include "afxwin.h"

// CItemDlg �Ի���

class CItemDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CItemDlg)

public:
	CItemDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CItemDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ITEMS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_CListCtrlAcc;
	CEdit m_CEditFindAcc;
	afx_msg void OnEnChangeEditFindAcc();
	afx_msg void OnBnClickedButtonFindNextAcc();
	afx_msg void OnBnClickedButtonUpdate();
	CStatic m_CStaticAccTotal;
	void InitItemList();
	afx_msg void OnBnClickedButtonOutput();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
