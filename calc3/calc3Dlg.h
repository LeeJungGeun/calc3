
// calc3Dlg.h : ��� ����
//

#pragma once


// Ccalc3Dlg ��ȭ ����
class Ccalc3Dlg : public CDialogEx
{
// �����Դϴ�.
private:
	char m_operater_flag = 0; //�����ȣ
	char m_step = 0; //������ Ȯ��
	int m_count = 0; //������ ī��Ʈ���� 
	double m_value = 0; //���ڰ� ����
public:
	void M_Operate(double m_vaule_two);
	Ccalc3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDivi();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedClear();
};

