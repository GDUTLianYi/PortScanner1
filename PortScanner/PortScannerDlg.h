
// PortScannerDlg.h : ͷ�ļ�
//

#pragma once

   

// CPortScannerDlg �Ի���
class CPortScannerDlg : public CDialogEx
{
// ����
public:
	CPortScannerDlg(CWnd* pParent = NULL);	// ��׼���캯��

	struct mypack {
		CString IP;
		UINT port;
		int time;
	};
	
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangeComboThread();
};
