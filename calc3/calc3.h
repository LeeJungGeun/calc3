
// calc3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Ccalc3App:
// �� Ŭ������ ������ ���ؼ��� calc3.cpp�� �����Ͻʽÿ�.
//

class Ccalc3App : public CWinApp
{
public:
	Ccalc3App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Ccalc3App theApp;