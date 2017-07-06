
// PortScannerDlg.h : 头文件
//

#pragma once

   

// CPortScannerDlg 对话框
class CPortScannerDlg : public CDialogEx
{
// 构造
public:
	CPortScannerDlg(CWnd* pParent = NULL);	// 标准构造函数

	struct mypack {
		CString IP;
		UINT port;
		int time;
	};
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PORTSCANNER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonDo();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangeComboThread();
	afx_msg void OnBnClickedButtonExcel();
	afx_msg void OnBnClickedButton4();
};
