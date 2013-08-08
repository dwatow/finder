// finderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "finder.h"
#include "finderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinderDlg dialog

CFinderDlg::CFinderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFinderDlg::IDD, pParent), ssStatus(SS_BEFORE)
{
	//{{AFX_DATA_INIT(CFinderDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFinderDlg)
	DDX_Control(pDX, IDC_STATIC_SHOWNOW, m_showPath);
	DDX_Control(pDX, IDC_LIST1, m_listShowFolders);
	DDX_Control(pDX, IDC_LIST2, m_listShowFiles);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFinderDlg, CDialog)
	//{{AFX_MSG_MAP(CFinderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinderDlg message handlers

BOOL CFinderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
// 	m_listPathName.clear();
 	ExecThread();

//	InitLastPath();
//	SetLastPathFile("C:\\altera\\81\\ip\\altera\\ddr_ddr2_sdram\\constraints\\dat\\ep2s30_f672_nondqs_nonmig_x8_floorplan_v00.dat");
//	findIt("C:\\", "*.*");


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFinderDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFinderDlg::ExecThread()
{
	//creat a thread
	pThread = AfxBeginThread(thread_find, (LPVOID) this);
}

UINT CFinderDlg::thread_find(LPVOID param)
{
	CFinderDlg* pDlg = (CFinderDlg*)param;

	const CString filetype("*.doc");  //target file
   	pDlg->InitLastPath();
	pDlg->findIt("C:\\", filetype);
	pDlg->findIt("D:\\", filetype);
	pDlg->findIt("E:\\", filetype);

	return 0;
}

void CFinderDlg::InitLastPath()
{
	std::vector<CString> lastest;
	CTxtFile report;
	CFileException fx;
	if (report.Open("C:\\lastest.txt", fx))
	{
		report.oTxtData(lastest);
		report.Close();
		m_lastestPathFile.Format("%s", lastest.at(0));
		m_lastestPathFile.TrimRight();
	}
	else
		m_lastestPathFile = "";
}

void CFinderDlg::findIt(const CString& dirPath, const CString& fullFileName)
{
	CSearcher finder;
	std::vector<CString> listFolde;

	CString temp;
    BOOL bExist = finder.IsSomeThingInPath(dirPath, fullFileName);
	while (bExist) 
	{
		bExist = finder.FindNextFile();
		m_showPath.SetWindowText(finder.GetFilePath());  //show it

		temp = finder.GetFilePath();

// 		temp.Format("%s]\n%s\n%d", finder.GetFilePath(), m_lastestPathFile, ssStatus);
// 		MessageBox(temp);
		if (IsLastestFile(finder.GetFilePath()))//是否是這個檔案
			ssStatus = SS_AFTER;
		
		if (IsNotYetFnd(finder.IsDots(), finder.GetFilePath()))
			continue;

		if (finder.IsDirectory())  //找目錄
		{
			//是這個目錄 或者 已經找到了
			if ( IsInLastestPath(finder.GetFilePath()) || (ssStatus == SS_AFTER))
			{
				AddFoldersList(finder.GetFilePath());
				findIt(finder.GetFilePath(), fullFileName);
			}
			else 
				continue;
		}
		else if (finder.IsTheSameSubFileName(fullFileName))  //找檔案
			AddFileList(finder.GetFilePath());
		else
			ASSERT(0);
	}
    finder.Close();
}

BOOL CFinderDlg::IsLastestFile(const CString& theFind)
{
	return ( (m_lastestPathFile == theFind) || (m_lastestPathFile.IsEmpty()) ) ? TRUE : FALSE;
}

BOOL CFinderDlg::IsNotYetFnd(const BOOL& IsDot, const CString& theFind)
{
	return ( IsDot && !IsInLastestPath(theFind) ) ? TRUE : FALSE;
}

BOOL CFinderDlg::IsInLastestPath(const CString& theFind)
{
	return ( (ssStatus == SS_BEFORE) && (m_lastestPathFile.Find(theFind) != -1) ) ? TRUE : FALSE;
}

void CFinderDlg::AddFileList(const CString& filePath)
{
	m_listShowFiles.AddString(filePath);
 	m_listPathName.push_back(filePath);
	m_listShowFiles.SetTopIndex(m_listShowFiles.GetCount()-1);
}

void CFinderDlg::AddFoldersList(const CString& filePath)
{
	m_listTargetFiles.push_back(filePath+"\n");
	m_listShowFolders.AddString(filePath);
	m_listShowFolders.SetTopIndex(m_listShowFolders.GetCount()-1);
}

void CFinderDlg::SetLastPathFile(const CString& pathFile)
{
	m_lastestPathFile = pathFile;
}

void CFinderDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
// 	AfxMessageBox("請按「確定」繼續刪除。");

	if (m_listPathName.size())
	{
		std::vector<CString> lastest;
		lastest.push_back(*m_listPathName.rbegin());
		CTxtFile report1;
		CFileException fx1;
		report1.Save("C:\\lastest.txt", fx1);
		report1.iTxtData(lastest);
		report1.Close();
	}

	std::vector<CString> inputFiles;
	CTxtFile report2;
	CFileException fx2;
// 	report2.oTxtData(inputFiles);
// 	report2.Open("C:\\targetFiles.txt", fx2);
// 	report2.Close();

	if (m_listTargetFiles.size())
	{
// 		targetFiles.push_back(*m_listTargetFiles.rbegin());


		inputFiles.insert(inputFiles.end(), m_listTargetFiles.begin(), m_listTargetFiles.end());

		CTxtFile report3;
		CFileException fx3;
		report3.Save("C:\\targetFiles.txt", fx3);
		report3.iTxtData(inputFiles);
		report3.Close();
	}
	CDialog::OnClose();
}

