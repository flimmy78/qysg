
// HCSG_Manager.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Local_com.h"

#include "CwarPlayerDlg.h"
#include "CwarOrgDlg.h"
#include "LoginDlg.h"
#include "AttrDlg.h"
#include "CBDlg.h"
#include "XubaoDlg.h"
#include "LogDlg.h"
#include "Vip.h"
#include "PlayerListDlg.h"
#include "ItemDlg.h"
#include "StoreDlg.h"

// CHCSG_ManagerApp:
// �йش����ʵ�֣������ HCSG_Manager.cpp
//

class CHCSG_ManagerApp : public CWinApp
{
public:
	CHCSG_ManagerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHCSG_ManagerApp theApp;