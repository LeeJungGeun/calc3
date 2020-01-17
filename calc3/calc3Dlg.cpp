
// calc3Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "calc3.h"
#include "calc3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccalc3Dlg ��ȭ ����



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


// Ccalc3Dlg �޽��� ó����

BOOL Ccalc3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Ccalc3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Ccalc3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL Ccalc3Dlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (B_Number0 <= wParam&&wParam <= B_Number9) //�ַ��Ž���� �� Resource.h �� ���ڹ�ư ��ũ�� Ȯ��
	{
		CString str, number_str, str2; //���ڿ�
		number_str.Format(L"%d", wParam - B_Number0); //����'0'�� �������� ��´�

		if (m_step == 0) //�����ڰ� ������ �ʾ������
		{
			GetDlgItemText(Print_Edit, str2); //����Ʈ�� �ԷµȰ��� str������ ����
		}
		else if (m_step == 1)
		{
			GetDlgItemText(Print_Edit, str);
			m_step = 0;
			m_value = _wtof(str);
		}
		SetDlgItemText(Print_Edit, str2 + number_str); //str�� ����� ���� ���ڰ��� ���� ���
	}
	return CDialogEx::OnCommand(wParam, lParam);

}


void Ccalc3Dlg::OnBnClickedPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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