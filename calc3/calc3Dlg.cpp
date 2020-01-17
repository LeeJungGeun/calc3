
// calc3Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "calc3.h"
#include "calc3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccalc3Dlg 대화 상자



Ccalc3Dlg::Ccalc3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALC3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccalc3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ccalc3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Plus, &Ccalc3Dlg::OnBnClickedPlus)
	ON_BN_CLICKED(Minus, &Ccalc3Dlg::OnBnClickedMinus)
	ON_BN_CLICKED(Mult, &Ccalc3Dlg::OnBnClickedMult)
	ON_BN_CLICKED(Divi, &Ccalc3Dlg::OnBnClickedDivi)
	ON_BN_CLICKED(Equal, &Ccalc3Dlg::OnBnClickedEqual)
	ON_BN_CLICKED(Clear, &Ccalc3Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// Ccalc3Dlg 메시지 처리기

BOOL Ccalc3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Ccalc3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ccalc3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL Ccalc3Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (B_Number0 <= wParam&&wParam <= B_Number9) //솔루션탐색기 → Resource.h → 숫자버튼 매크로 확인
	{
		CString str, number_str, str2; //문자열
		number_str.Format(L"%d", wParam - B_Number0); //숫자'0'을 기준으로 잡는다

		if (m_step == 0) //연산자가 눌리지 않았을경우
		{
			GetDlgItemText(Print_Edit, str2); //에디트에 입력된값을 str변수에 저장
		}
		else if (m_step == 1)
		{
			GetDlgItemText(Print_Edit, str);
			m_step = 0;
			m_value = _wtof(str);
		}
		SetDlgItemText(Print_Edit, str2 + number_str); //str에 저장된 값에 숫자값을 더해 출력
	}
	return CDialogEx::OnCommand(wParam, lParam);

}


void Ccalc3Dlg::OnBnClickedPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;

	if (m_count == 1) {
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}
	m_operater_flag = 0;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '+');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void Ccalc3Dlg::OnBnClickedMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;

	if (m_count == 1) {
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}
	m_operater_flag = 1;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '-');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void Ccalc3Dlg::OnBnClickedMult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;

	if (m_count == 1) {
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}
	m_operater_flag = 2;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '*');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void Ccalc3Dlg::OnBnClickedDivi()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, str2, omg;

	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, omg);
	m_value_two = _wtof(omg);

	m_count++;

	if (m_count == 1) {
		m_value = m_value_two;
	}
	else
	{
		M_Operate(m_value_two);
	}
	m_operater_flag = 3;
	m_step = 1;

	GetDlgItemText(Print_Edit, str2);
	GetDlgItemText(Print_Edit2, str);
	SetDlgItemText(Print_Edit2, str + str2 + '/');

	omg.Format(L"%f", m_value);
	omg.TrimRight(L"0");
	omg.TrimRight(L".");
	SetDlgItemText(Print_Edit, omg);
}


void Ccalc3Dlg::OnBnClickedEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	double m_value_two = GetDlgItemInt(Print_Edit);
	GetDlgItemText(Print_Edit, str);
	m_value_two = _wtof(str);

	CEdit* pEdit2 = (CEdit*)GetDlgItem(Print_Edit2);
	pEdit2->SetWindowTextW(L" ");

	M_Operate(m_value_two);

	m_count = 0;

	str.Format(L"%f", m_value);
	str.TrimRight(L"0");
	str.TrimRight(L".");
	SetDlgItemText(Print_Edit, str);
}


void Ccalc3Dlg::OnBnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CEdit* pEdit = (CEdit*)GetDlgItem(Print_Edit);
	pEdit->SetWindowTextW(L" ");

	m_value = 0;
	m_step = 0;
	m_operater_flag = 0;

	UpdateData(FALSE);
}

void Ccalc3Dlg::M_Operate(double m_value_two)
{
	switch (m_operater_flag)
	{
	case 0 :
		m_value += m_value_two;
		break;
	case 1 :
		m_value -= m_value_two;
		break;
	case 2 :
		m_value *= m_value_two;
		break;
	case 3 :
		if (m_value_two != 0)
		{
			m_value /= m_value_two;
		}
		else
		{
			m_value = 0;
		}
		break;
	}
}