// Searcher.h: interface for the CSearcher class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEARCHER_H__DED71BA2_A86F_4F0D_9720_D54586C67A5C__INCLUDED_)
#define AFX_SEARCHER_H__DED71BA2_A86F_4F0D_9720_D54586C67A5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSearcher : public CFileFind
{
	CString lastPathName;
public:
	BOOL Find();
	BOOL IsSomeThingInPath(const CString& dirPath, const CString& fullFileName);
	BOOL IsTheSameSubFileName(CString fullFileName);
	CSearcher();
	virtual ~CSearcher();

};

#endif // !defined(AFX_SEARCHER_H__DED71BA2_A86F_4F0D_9720_D54586C67A5C__INCLUDED_)
