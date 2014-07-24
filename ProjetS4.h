// ProjetS4.h : main header file for the PROJETS4 application
//

#if !defined(AFX_PROJETS4_H__FFE99E17_1916_44B0_812B_1EA4149798BE__INCLUDED_)
#define AFX_PROJETS4_H__FFE99E17_1916_44B0_812B_1EA4149798BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProjetS4App:
// See ProjetS4.cpp for the implementation of this class
//

class CProjetS4App : public CWinApp
{
public:
	CProjetS4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjetS4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProjetS4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJETS4_H__FFE99E17_1916_44B0_812B_1EA4149798BE__INCLUDED_)
