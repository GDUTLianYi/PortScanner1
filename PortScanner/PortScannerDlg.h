
// PortScannerDlg.h : ͷ�ļ�
//

#pragma once

   

// CPortScannerDlg �Ի���
class CPortScannerDlg : public CDialogEx
{
// ����
public:
	CPortScannerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	//�Զ������ݰ�
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
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PORTSCANNER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonDo();
	afx_msg void OnBnClickedButton1();  //��Ӧ��ɨ���ض��˿ڹ��ܵ�ʵ��
	afx_msg void OnBnClickedButton2();  //��Ӧ��ɨ�賣�ö˿ڹ��ܵ�ʵ��
	afx_msg void OnEnChangeEdit1();      //��Ӧ���ض��˿������
	afx_msg void OnBnClickedButton3();   //��Ӧ��ɨ�賣�ö˿ڹ��ܵ�ʵ��
	afx_msg void OnCbnSelchangeComboThread(); //��Ӧ���߳��б��
	afx_msg void OnBnClickedButtonExcel(); //��Ӧ�����Ϊ
	afx_msg void OnBnClickedButton4();
	afx_msg void OnDestroy();
};
