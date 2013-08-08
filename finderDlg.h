// finderDlg.h : header file
//

#if !defined(AFX_FINDERDLG_H__CA809C97_7834_4C59_910E_6C3A3114A5B9__INCLUDED_)
#define AFX_FINDERDLG_H__CA809C97_7834_4C59_910E_6C3A3114A5B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "Searcher.h"
#include "TxtFile.h"

/////////////////////////////////////////////////////////////////////////////
// CFinderDlg dialog

enum searchStatus{SS_BEFORE, SS_FIND, SS_AFTER};

class CFinderDlg : public CDialog
{
	//thread
	CString m_lastestPathFile;
	CWinThread* pThread;
	static UINT thread_find(LPVOID param);
	void ExecThread();

	searchStatus ssStatus;
 	std::vector<CString> m_listPathName;//¦Cªí
	std::vector<CString> m_listTargetFiles;

	void AddFileList(const CString& );
	void AddFoldersList(const CString& );
	BOOL IsLastestFile(const CString& );
	BOOL IsNotYetFnd(const BOOL&, const CString&);
	BOOL IsInLastestPath(const CString& theFind);
	void InitLastPath();

// Construction
public:
	void SetLastPathFile(const CString& pathFile);
	void findIt(const CString&, const CString&);
	CFinderDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFinderDlg)
	enum { IDD = IDD_FINDER_DIALOG };
	CStatic	m_showPath;
	CListBox	m_listShowFolders;
	CListBox	m_listShowFiles;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFinderDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDERDLG_H__CA809C97_7834_4C59_910E_6C3A3114A5B9__INCLUDED_)
