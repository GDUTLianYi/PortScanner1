
// PortScanner.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPortScannerApp: 
// �йش����ʵ�֣������ PortScanner.cpp
//


class CPortScannerApp : public CWinApp
{
public:
	CPortScannerApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPortScannerApp theApp;
