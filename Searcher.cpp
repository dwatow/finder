// Searcher.cpp: implementation of the CSearcher class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "finder.h"
#include "Searcher.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSearcher::CSearcher()
{

}

CSearcher::~CSearcher()
{

}

BOOL CSearcher::IsSomeThingInPath(const CString& dirPath, const CString& fullFileName)
{
	CString searchPathName;
    searchPathName.Format("%s\\%s", dirPath, "*.*");  // search all
	
	return FindFile(searchPathName);
}

BOOL CSearcher::IsTheSameSubFileName(CString fullFileName)
{
	CString PathFileName = GetFilePath();
	if (fullFileName.Find("*.*") != -1)
		return TRUE;
	else
	{
		GetFilePath().MakeLower();
		fullFileName.MakeLower();
		

// 		strFileName = tempFind.GetFileName();
// 		nIndex = strFileName.ReverseFind('.');	     
// 		strSuffix = strFileName.Mid(nIndex+1);
// 		strSuffix.MakeUpper();

		CString subFileName1 = fullFileName.Mid(fullFileName.ReverseFind('.')+1);
		CString subFileName2 = PathFileName.Mid(PathFileName.ReverseFind('.')+1);


		
		return (subFileName1 == subFileName2)?TRUE : FALSE;
	}
}