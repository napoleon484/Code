// ProjetS4.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ProjetS4.h"
#include "ProjetS4Dlg.h"
#include <math.h>
#include "craneexports.h"
#include "matrix.h"
#include "mockgrue.h"
#include "grue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




/////////////////////////////////////////////////////////////////////////////
// CProjetS4App

BEGIN_MESSAGE_MAP(CProjetS4App, CWinApp)
	//{{AFX_MSG_MAP(CProjetS4App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjetS4App construction

CProjetS4App::CProjetS4App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CProjetS4App object

CProjetS4App theApp;

/////////////////////////////////////////////////////////////////////////////
// CProjetS4App initialization

BOOL CProjetS4App::InitInstance()
{
	CLASS_CRANE grue;	//Ne pas creer dautre instance de la grue
	CProjetS4Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
