#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// LogDlg �Ի���

class CLogDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogDlg)

public:
	CLogDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLogDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_CComboBoxLogLevel;
	CEdit m_CEditLogPath;
	CRichEditCtrl m_CRichEditCtrlLog;
	virtual BOOL OnInitDialog();

	CString LogDirPath;

	LRESULT PrintMsg(WPARAM wParam, LPARAM lParam);
	void DoPrintMsg(CString csprint);
	void SaveLogs(CString ctime, CString csmsg);

	afx_msg void OnCbnSelchangeComboLogLevel();
	afx_msg void OnBnClickedClear();
};
