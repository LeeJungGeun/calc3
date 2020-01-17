
// calc3Dlg.h : 헤더 파일
//

#pragma once


// Ccalc3Dlg 대화 상자
class Ccalc3Dlg : public CDialogEx
{
// 생성입니다.
private:
	char m_operater_flag = 0; //연산기호
	char m_step = 0; //연산자 확인
	int m_count = 0; //연산자 카운트변수 
	double m_value = 0; //숫자값 저장
public:
	void M_Operate(double m_vaule_two);
	Ccalc3Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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

