
// PortScannerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PortScanner.h"
#include "PortScannerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPortScannerDlg �Ի���



CPortScannerDlg::CPortScannerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PORTSCANNER_DIALOG, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPortScannerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPortScannerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DO, &CPortScannerDlg::OnBnClickedButtonDo)
	ON_BN_CLICKED(IDC_BUTTON1, &CPortScannerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CPortScannerDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CPortScannerDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPortScannerDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO_THREAD, &CPortScannerDlg::OnCbnSelchangeComboThread)
	ON_BN_CLICKED(IDC_BUTTON_EXCEL, &CPortScannerDlg::OnBnClickedButtonExcel)
	ON_BN_CLICKED(IDC_BUTTON4, &CPortScannerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CPortScannerDlg ��Ϣ�������

BOOL CPortScannerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	CIPAddressCtrl *pIP;
	CListCtrl *pList;
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	pIP=(CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS);
	pList = (CListCtrl*)GetDlgItem(IDC_LIST_PORT);
	pList->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	pList->InsertColumn(0, "IP��ַ", 0, 180);
	pList->InsertColumn(1, "�˿ڵ�ַ", 0, 120);

	CComboBox* pComb = (CComboBox*)GetDlgItem(IDC_COMBO1);

	pComb->AddString("500");
	pComb->AddString("800");
	pComb->AddString("1000");
	pComb->AddString("1200");
	pComb->AddString("1400");
	pComb->AddString("5000");
	pComb->SetCurSel(3);
	CComboBox* pCombThread = (CComboBox*)GetDlgItem(IDC_COMBO_THREAD);
	pCombThread->AddString("32");
	pCombThread->AddString("64");
	pCombThread->AddString("128");
	pCombThread->AddString("256");
	pCombThread->AddString("512");
	pCombThread->AddString("1024");
	pCombThread->AddString("2048");
	pCombThread->SetCurSel(3);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPortScannerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPortScannerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPortScannerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






DWORD WINAPI ThreadFunc(LPVOID pParam) {

	//int n = *((int*)pParam);
	//int port = *((UINT*)pParam) ;
	//	CString str; str.Format("%d", x);
	//	AfxMessageBox(str);
	//n = 15;
	//	Sleep(9000);
	struct mypack {
		CString IP;
		UINT port;
		int time;
	};
	mypack pack = *((mypack*)pParam);
	//return 0;
	int time, ms, s;
	time = pack.time;	s = time / 1000;	ms = time % 1000;

	/*��ȡĿ������IP��ַ*/
	CString IP = pack.IP; UINT port = pack.port;
	//IP = "10.21.32.111";

	int err;
	WSADATA wsd;
	SOCKET cClient;
	int ret;
	struct sockaddr_in server;
	hostent *host = NULL;

	/*����Ŀ���������ݽṹ*/
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IP);
	if (server.sin_addr.s_addr == INADDR_NONE) { return 0; }





	/*
	if (i % 100 == 0) {
	CString str;
	str.Format("%u", i);
	AfxMessageBox(str);
	}
	*/

	server.sin_port = htons(port);
	if (WSAStartup(MAKEWORD(2, 0), &wsd)) { return 0; }
	cClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (cClient == INVALID_SOCKET) { return 0; }
	//set Recv and Send time out
	DWORD TimeOut = 3000; //���÷��ͳ�ʱ6��
	if (::setsockopt(cClient, SOL_SOCKET, SO_SNDTIMEO, (char *)&TimeOut, sizeof(TimeOut)) == SOCKET_ERROR) {
		//continue;
		return 0;
	}
	TimeOut = 3000;//���ý��ճ�ʱ6��
	if (::setsockopt(cClient, SOL_SOCKET, SO_RCVTIMEO, (char *)&TimeOut, sizeof(TimeOut)) == SOCKET_ERROR) {
		return 0;
	}
	//���÷�������ʽ����
	unsigned long ul = 1;
	ret = ioctlsocket(cClient, FIONBIO, (unsigned long*)&ul);
	if (ret == SOCKET_ERROR)	return 0;

	//����
	connect(cClient, (const struct sockaddr *)&server, sizeof(server)); //��������
																		//select ģ�ͣ������ó�ʱ
	struct timeval timeout;
	fd_set r;
	FD_ZERO(&r);
	FD_SET(cClient, &r);
	timeout.tv_sec = s; //���ó�ʱʱ��Ϊ1��
	timeout.tv_usec = ms;
	ret = select(0, 0, &r, 0, &timeout);

	if (ret <= 0)
	{
		((mypack*)pParam)->port = 0;
	}
	else {
		
	}
	::closesocket(cClient);

	//AfxMessageBox("��ѯ���");
	return 0;
}



void CPortScannerDlg::OnBnClickedButton2()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST_PORT);
	int nCount = pList->GetItemCount();
	// Delete all of the items from the list view control.
	for (int i = 0; i < nCount; i++)
	{
		pList->DeleteItem(0);
	}


	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CIPAddressCtrl *pIP = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS);
	CIPAddressCtrl *pIP1 = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1);
	BYTE f[4] = { 10,21,32,111 }, g[4] = { 10,21,32,111 };
	pIP->GetAddress(f[0], f[1], f[2], f[3]);
	pIP1->GetAddress(g[0], g[1], g[2], g[3]);

	int range = 1;
	for (int r = 0; r < 4; r++)
		range *= (g[r] - f[r] + 1);

	CProgressCtrl *cpc = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	cpc->SetRange(0, range);
	cpc->SetPos(0);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString str; pEdit->GetWindowTextA(str);
	int tmpxx = _ttoi(str);
	UINT goalPort = tmpxx;
	CComboBox* pComb = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pComb->GetWindowTextA(str);
	int usetime= _ttoi(str);

	const int size = 9999;
	const UINT one = 256;
	DWORD exitCode[size];
	DWORD threadId[size];
	HANDLE hThrds[size];
	UINT port[size];
	mypack pack[size];
	CString res;
	//UINT x = 6434;
	
	int cnt = 0;
	for (int f0 = f[0]; f0 <= g[0]; f0++) {
		for (int f1 = f[1]; f1 <= g[1]; f1++) {
			for (int f2 = f[2]; f2 <= g[2]; f2++) {
				
				for (int f3 = f[3]; f3 <= g[3]; f3++) {
					
					pack[f3].IP.Format("%d.%d.%d.%d", f0, f1, f2, f3);
					//pack[f3].IP = "10.21.32.111";
					pack[f3].port = goalPort;
					pack[f3].time = usetime;
					hThrds[f3] = CreateThread(NULL, 0, ThreadFunc, &pack[f3], 0, &threadId[f3]);
					
				}
				
				for (;;)
				{
					int flag = 1;

					printf("Press any key to exit..\n");
					//getch();
					for (int f3 = f[3]; f3 <=g[3]; f3++) {
						GetExitCodeThread(hThrds[f3], &exitCode[f3]);
						if (exitCode[f3] == STILL_ACTIVE) {
							flag = 0;
							break;
						}
					}

					if (flag == 0) {
						Sleep(1000);
					}
					else {
						break;
					}
				}
				for (int f3 = f[3]; f3 <= g[3]; f3++) {
					
					if (pack[f3].port != 0) {
						//CString  tmp;
						//tmp.Format(" %d", pack[f3].port);
						//res.Append(tmp);
						int ncount = pList->GetItemCount();
						pList->InsertItem(ncount, pack[f3].IP);
						CString sport; sport.Format("%d", pack[f3].port);
						pList->SetItemText(ncount, 1, sport);
					}
				}
				cpc->SetPos(range);
				UpdateWindow();
			}
		}
	}

	
	AfxMessageBox("ִ�н���");
}
void CPortScannerDlg::OnBnClickedButton1()
{
	
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST_PORT);
	int nCount = pList->GetItemCount();
	// Delete all of the items from the list view control.
	for (int i = 0; i < nCount; i++)
	{
		pList->DeleteItem(0);
	}
	CIPAddressCtrl *pIP = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS);
	CIPAddressCtrl *pIP1 = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1);
	BYTE f[4] = { 10,21,32,111 }, g[4] = { 10,21,32,111 };
	pIP->GetAddress(f[0], f[1], f[2], f[3]);
	pIP1->GetAddress(g[0], g[1], g[2], g[3]);
	int range = 1;
	for (int r = 0; r < 4; r++)
		range *= (g[r] - f[r] + 1);
	
	CProgressCtrl *cpc = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	cpc->SetRange(0, range);
	cpc->SetPos(0);
	CString str; 
	CComboBox* pComb = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pComb->GetWindowTextA(str);
	int usetime = _ttoi(str);

	const int size = 9999;
	const UINT one = 256;
	DWORD exitCode[size];
	DWORD threadId[size];
	HANDLE hThrds[size];
	UINT port[size];
	mypack pack[size];
	CString res;
	int cnt = 0;
	for (int f0 = f[0]; f0 <= g[0]; f0++) {
		for (int f1 = f[1]; f1 <= g[1]; f1++) {
			for (int f2 = f[2]; f2 <= g[2]; f2++) {

				for (int f3 = f[3]; f3 <= g[3]; f3++) {
					
					CString szIP;

					szIP.Format("%d.%d.%d.%d", f0, f1, f2, f3);
					//szIP = "10.21.32.111";
					for (int p = 0; p <= 1024; p++) {

						pack[p].port = p;
						pack[p].time = usetime;
						pack[p].IP = szIP;

						hThrds[p] = CreateThread(NULL, 0, ThreadFunc, &pack[p], 0, &threadId[p]);
					}
					for (;;)
					{
						int flag = 1;

						printf("Press any key to exit..\n");
						//getch();
						for (int p = 0; p <= 1024; p++) {
							GetExitCodeThread(hThrds[p], &exitCode[p]);
							if (exitCode[p] == STILL_ACTIVE) {
								flag = 0;
								break;
							}
						}

						if (flag == 0) {
							Sleep(1000);
						}
						else {
							break;
						}
					}
					for (int p = 0; p <= 1024; p++) {

						if (pack[p].port != 0) {
							//	CString  tmp;
							//	tmp.Format(" %d", pack[p].port);
							//	res.Append(tmp);
							int ncount = pList->GetItemCount();
							pList->InsertItem(ncount, pack[p].IP);
							CString sport; sport.Format("%d", pack[p].port);
							pList->SetItemText(ncount, 1, sport);
						}
						
					}
					cpc->SetPos(++cnt);
					UpdateWindow();
				}
			}
		}
	}


	AfxMessageBox("ִ�н���");
}
//#include "afxsock.h"
void CPortScannerDlg::OnBnClickedButtonDo()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST_PORT);
	int nCount = pList->GetItemCount();
	// Delete all of the items from the list view control.
	for (int i = 0; i < nCount; i++)
	{
		pList->DeleteItem(0);
	}
	CIPAddressCtrl *pIP = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS);
	CIPAddressCtrl *pIP1 = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1);
	BYTE f[4] = { 10,21,32,111 }, g[4] = { 10,21,32,111 };
	pIP->GetAddress(f[0], f[1], f[2], f[3]);
	pIP1->GetAddress(g[0], g[1], g[2], g[3]);

	int range = 1;
	for (int r = 0; r < 4; r++)
		range *= (g[r] - f[r] + 1);

	CProgressCtrl *cpc = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	cpc->SetRange(0, range*64);
	cpc->SetPos(0);
	CString str; 
	CComboBox* pComb = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pComb->GetWindowTextA(str);
	int usetime = _ttoi(str);

	const int size = 9999;
	const UINT one = 256;
	DWORD exitCode[size];
	DWORD threadId[size];
	HANDLE hThrds[size];
	UINT port[size];
	mypack pack[size];
	CString res;

	int cnt = 0;
	for (int f0 = f[0]; f0 <= g[0]; f0++) {
		for (int f1 = f[1]; f1 <= g[1]; f1++) {
			for (int f2 = f[2]; f2 <= g[2]; f2++) {

				for (int f3 = f[3]; f3 <= g[3]; f3++) {

					CString szIP;

					szIP.Format("%d.%d.%d.%d", f0, f1, f2, f3);
					//szIP = �ϵ�"10.21.32.111";
					for (int j = 0; j < 64; j++) {
						for (int p = 0; p < 1024; p++) {

							pack[p].port = p+1024*j;
							pack[p].time = usetime;
							pack[p].IP = szIP;
						
							hThrds[p] = CreateThread(NULL, 0, ThreadFunc, &pack[p], 0, &threadId[p]);
						}
						for (;;)
						{
							int flag = 1;

							printf("Press any key to exit..\n");
							//getch();
							for (int p = 0; p < 1024; p++) {
								GetExitCodeThread(hThrds[p], &exitCode[p]);
								if (exitCode[p] == STILL_ACTIVE) {
									flag = 0;
									break;
								}
							}

							if (flag == 0) {
								Sleep(1000);
							}
							else {
								break;
							}
						}
						for (int p = 0; p < 1024; p++) {

							if (pack[p].port != 0) {
								//CString  tmp;
								//tmp.Format(" %d", pack[p].port);
								//res.Append(tmp);
								int ncount = pList->GetItemCount();
								pList->InsertItem(ncount, pack[p].IP);
								CString sport; sport.Format("%d", pack[p].port);
								pList->SetItemText(ncount, 1, sport);
							}
						}
						cpc->SetPos(++cnt);
						UpdateWindow();
					}
				
				}
			}
		}
	}


	AfxMessageBox("ִ�н���");
}


/*
int err=99;
int n = 5;
CWinThread *pThread = AfxBeginThread(ThreadFunc, &n);
DWORD dwExitCode = 9;
bool res = GetExitCodeThread(pThread->m_hThread, &dwExitCode);
err = GetLastError();
//waitforsingleobject(hThread, timeout)
//	WaitForSingleObject();
while (dwExitCode==STILL_ACTIVE) {
Sleep(1000);
res=GetExitCodeThread(pThread->m_hThread, &dwExitCode);
}
AfxMessageBox("OK");
*/

void CPortScannerDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




/*

CSocket con_socket;
UINT con_port=-1;
for (UINT i = 65535; i >=1; i--) {
if (con_socket.Create(i, SOCK_STREAM)) {
con_port = i;
break;
}
}

if (con_port==-1){
AfxMessageBox("con_socket����ʧ��");
return;
}
/*if (con_socket.Connect(IP, 1)) {
int ncount = pList->GetItemCount();
pList->InsertItem(ncount, IP);
CString port; port.Format("%d", 135);
pList->SetItemText(ncount, 1, port);
con_socket.Close();
if (!con_socket.Create(con_port, SOCK_STREAM)){
err = GetLastError();
AfxMessageBox("ѭ����con_socket����ʧ��");
}
}
*/


/*if (con_socket.Connect(IP, 445)) {
int ncount = pList->GetItemCount();
pList->InsertItem(ncount, IP);
CString port; port.Format("%d", 445);
pList->SetItemText(ncount, 1, port);
con_socket.Close();
}*/
//int  nNetTimeout = 10;//1��
//setsockopt(con_socket,SOL_SOCKET, SO_SNDTIMEO,(char *)&nNetTimeout, sizeof(int));


/*	BOOL bConditionalAccept = TRUE;
setsockopt(con_socket, SOL_SOCKET, SO_CONDITIONAL_ACCEPT, (const char*)&bConditionalAccept, sizeof(BOOL));
int nTime=1;//�����ó���
err=setsockopt(con_socket,SOL_SOCKET,SO_SNDTIMEO,(const char *)&nTime,sizeof(nTime));
for (int i = 1; i <=65535; i++) {
if (i % 10000 == 0) {
//	AfxMessageBox("hahah");
}
if (con_socket.Connect(IP, i)) {
int ncount = pList->GetItemCount();
pList->InsertItem(ncount, IP);
CString port; port.Format("%d", i);
pList->SetItemText(ncount, 1, port);
con_socket.Close();
}
else {

}
}
AfxMessageBox("ok");
*/

void CPortScannerDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST_PORT);
	int nCount = pList->GetItemCount();
	// Delete all of the items from the list view control.
	for (int i = 0; i < nCount; i++)
	{
		pList->DeleteItem(0);
	}
	CIPAddressCtrl *pIP = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS);
	CIPAddressCtrl *pIP1 = (CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1);
	BYTE f[4] = { 10,21,32,111 }, g[4] = { 10,21,32,111 };
	pIP->GetAddress(f[0], f[1], f[2], f[3]);
	pIP1->GetAddress(g[0], g[1], g[2], g[3]);

	int range = 1;
	for (int r = 0; r < 4; r++)
		range *= (g[r] - f[r] + 1);

	CProgressCtrl *cpc = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS1);
	cpc->SetRange(0, range * 64*4);
	cpc->SetPos(0);
	CString str;
	CComboBox* pComb = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pComb->GetWindowTextA(str);
	int usetime = _ttoi(str);
	CComboBox* pCombThread = (CComboBox*)GetDlgItem(IDC_COMBO_THREAD);
	pComb->GetWindowTextA(str);
	int col = _ttoi(str);
	
	const int size = 9999;
	const UINT one = 256;
	DWORD exitCode[size];
	DWORD threadId[size];
	HANDLE hThrds[size];
	UINT port[size];
	mypack pack[size];
	CString res;

	int cnt = 0;
	for (int f0 = f[0]; f0 <= g[0]; f0++) {
		for (int f1 = f[1]; f1 <= g[1]; f1++) {
			for (int f2 = f[2]; f2 <= g[2]; f2++) {

				for (int f3 = f[3]; f3 <= g[3]; f3++) {

					CString szIP;

					szIP.Format("%d.%d.%d.%d", f0, f1, f2, f3);
					//szIP = "10.21.32.111";
				
					for (int j = 0; j < 64*4; j++) {
						for (int p = 0; p < col; p++) {

							pack[p].port = p +col * j;
							pack[p].time = usetime;
							pack[p].IP = szIP;

							hThrds[p] = CreateThread(NULL, 0, ThreadFunc, &pack[p], 0, &threadId[p]);
						}
						for (;;)
						{
							int flag = 1;

							printf("Press any key to exit..\n");
							//getch();
							for (int p = 0; p < col; p++) {
								GetExitCodeThread(hThrds[p], &exitCode[p]);
								if (exitCode[p] == STILL_ACTIVE) {
									flag = 0;
									break;
								}
							}

							if (flag == 0) {
								Sleep(1000);
							}
							else {
								break;
							}
						}
						for (int p = 0; p < col; p++) {

							if (pack[p].port != 0) {
								//CString  tmp;
								//tmp.Format(" %d", pack[p].port);
								//res.Append(tmp);
								int ncount = pList->GetItemCount();
								pList->InsertItem(ncount, pack[p].IP);
								CString sport; sport.Format("%d", pack[p].port);
								pList->SetItemText(ncount, 1, sport);
							}
						}
						cpc->SetPos(++cnt);
						UpdateWindow();
					}

				}
			}
		}
	}


	AfxMessageBox("ִ�н���");
}


void CPortScannerDlg::OnCbnSelchangeComboThread()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPortScannerDlg::OnBnClickedButtonExcel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fdlg(false,"xls",NULL);
	INT_PTR rt = fdlg.DoModal();
	CListCtrl *plist = (CListCtrl*)GetDlgItem(IDC_LIST_PORT);
	if (IDOK == rt) {
		CString path = fdlg.GetPathName();
		CString name = fdlg.GetFileName();
		//AfxMessageBox("����˱���");
		int ncount = plist->GetItemCount();
		CString str;
		for (int i = 0; i < ncount; i++) {
			CString tmp = plist->GetItemText(i, 0);
			str.Append(" " + tmp);
			tmp = plist->GetItemText(i,1);
			str.Append(" " + tmp);
		}
		CFile f; CFileException e;

		if (!f.Open(path, CFile::modeCreate | CFile::modeWrite, &e)) {
			AfxMessageBox("file could not be opened %d", e.m_cause);
			
		}
		else {
			char s[4096]="1233456789";
			//memcpy(s, str, str.GetLength());
			f.Write(s, sizeof s);
			f.Flush();
			f.Close();
		}
		//AfxMessageBox(str);
	}
	else if (IDCANCEL == rt) {
		AfxMessageBox("�����ȡ��");
	}
}


void CPortScannerDlg::OnBnClickedButton4()
{
	
}
