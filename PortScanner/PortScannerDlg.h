
// PortScannerDlg.h : 头文件
//

#pragma once

   

// CPortScannerDlg 对话框
class CPortScannerDlg : public CDialogEx
{
// 构造
public:
	CPortScannerDlg(CWnd* pParent = NULL);	// 标准构造函数
	//自定义数据包
	struct mypack {
		CString IP;
		UINT port;
		int time;
	};
	CListCtrl m_list;    
	CIPAddressCtrl m_IP1, m_IP2;
	CComboBox m_CombTime ,m_CombThread;
	CProgressCtrl m_Progress;
	BYTE f[4] = { 0 }, g[4] = { 0 };
	const static int size = 8199;
	DWORD exitCode[size];
	DWORD threadId[size];
	HANDLE hThrds[size];
	UINT port[size];
	mypack pack[size];
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
	afx_msg void OnBnClickedButton1();  //对应于扫描特定端口功能的实现
	afx_msg void OnBnClickedButton2();  //对应于扫描常用端口功能的实现
	afx_msg void OnEnChangeEdit1();      //对应于特定端口输入框
	afx_msg void OnBnClickedButton3();   //对应于扫描常用端口功能的实现
	afx_msg void OnCbnSelchangeComboThread(); //对应于线程列表框
	afx_msg void OnBnClickedButtonExcel(); //对应于另存为
	afx_msg void OnBnClickedButton4();
	afx_msg void OnDestroy();
};
