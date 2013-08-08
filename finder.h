// finder.h : main header file for the FINDER application
//

#if !defined(AFX_FINDER_H__CE9467E7_1465_49CB_93D9_D8BE40CFCEF2__INCLUDED_)
#define AFX_FINDER_H__CE9467E7_1465_49CB_93D9_D8BE40CFCEF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFinderApp:
// See finder.cpp for the implementation of this class
//

class CFinderApp : public CWinApp
{
public:
	CFinderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFinderApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDER_H__CE9467E7_1465_49CB_93D9_D8BE40CFCEF2__INCLUDED_)
