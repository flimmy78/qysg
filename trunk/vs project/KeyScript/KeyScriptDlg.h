
// KeyScriptDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CKeyScriptDlg �Ի���
class CKeyScriptDlg : public CDialogEx
{
// ����
public:
	CKeyScriptDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_KEYSCRIPT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose();
	CComboBox m_CComboBoxProcess;
	afx_msg void OnBnClickedStart();
	CComboBox m_CComboBoxKey;
	CButton m_CButtonCrtl;
	afx_msg void OnBnClickedHide();

	CRect startRect;
	bool isMouseDown;
	CPoint startPoint;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCbnSelchangeComboKeys();
};
