
// KeyScript.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKeyScriptApp: 
// �йش����ʵ�֣������ KeyScript.cpp
//

class CKeyScriptApp : public CWinApp
{
public:
	CKeyScriptApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CKeyScriptApp theApp;