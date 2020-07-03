// polyfit1_0.h : main header file for the POLYFIT1_0 application
//

#if !defined(AFX_POLYFIT1_0_H__5E76A887_93C9_44D2_8EBB_428331D7443D__INCLUDED_)
#define AFX_POLYFIT1_0_H__5E76A887_93C9_44D2_8EBB_428331D7443D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPolyfit1_0App:
// See polyfit1_0.cpp for the implementation of this class
//

class CPolyfit1_0App : public CWinApp
{
public:
	CPolyfit1_0App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolyfit1_0App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPolyfit1_0App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYFIT1_0_H__5E76A887_93C9_44D2_8EBB_428331D7443D__INCLUDED_)
