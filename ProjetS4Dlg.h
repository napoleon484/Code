// ProjetS4Dlg.h : header file
//


#if !defined(AFX_PROJETS4DLG_H__356A7BC6_7862_445C_8EB8_37788183F798__INCLUDED_)
#define AFX_PROJETS4DLG_H__356A7BC6_7862_445C_8EB8_37788183F798__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "grue.h"
#include "mockgrue.h"

/////////////////////////////////////////////////////////////////////////////
// CProjetS4Dlg dialog

class CProjetS4Dlg : public CDialog
{
// Construction
public:
	CProjetS4Dlg(CWnd* pParent = NULL);	// standard constructor
		
//------------------------------------------
// La section suivante est g�n�r�e par MS Visual Studio. Elle est
//	 pr�sent�e ici pour d�finir les champs qui seront utilis�s
//	 dans le code.
//		CEdit	m_ValeurGris;		Contient la valeur entr�e dans
//										la case de changement de
//										niveau de gris.
//		CEdit	m_Lire; 			Contient le nom du fichier �
//										lire (mis � jour par le 
//										bouton parcourir)
//		CStatic	m_Image;			Permet l'acc�s au rectangle
//										d'affichage de l'image


// Dialog Data
	//{{AFX_DATA(CProjetS4Dlg)
	enum { IDD = IDD_PROJETS4_DIALOG };
	CEdit	m_ValeurGris;
	CEdit	m_Lire;
	CEdit	m_LireTraj;
	float	m_SensorX;
	float	m_SensorY;
	float	m_SensorR;
	float	m_SensorBeta;
	float	m_SensorAlpha;
	CStatic	m_Image;
	CLASS_CRANE *grue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjetS4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	//------------------------------------------
	//	Ajout de membres internes pour la gestion 
	//	de l'image

	CBitmap m_Bitmap;		// Concerve les �l�ments du bitmap

	CDC m_BitmapCDC;		// Conserve le contexte du
							//	 bitmap utilis�

	int m_LoadedBitmap;		// Drapeau pour indiquer la 
							//	pr�sence d'une image � 
							//	l'�cran

	BITMAPFILEHEADER m_bmfh;	// Ent�te du fichier bitmap
								// 	lue ou � �crire

	BITMAPINFOHEADER m_bmih;	// Description du bitmap
								// 	lue ou � �crire

	//------------------------------------------
	// M�thode pour lire l'ent�te du bitmap

	int LoadBitmapHeader (LPCTSTR lpszFileName);

	//------------------------------------------
	// M�thode pour modifier les niveau de gris de l'image affich�e

  void ModifieGris(int niveau);
  
  
	//------------------------------------------
	// M�thode pour lire le fichier bitmap indiqu�

  BOOL LireAfficherImage(LPCTSTR lpszFileName);

	//------------------------------------------


	// Generated message map functions
	//{{AFX_MSG(CProjetS4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnParcourir();
	afx_msg void OnAfficher();
	afx_msg void OnSauvegarde();
	afx_msg void OnReleasedcaptureSlidegris(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeGris();
	afx_msg void OnProcede();
	afx_msg void OnGetpict();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnParcourirTraj();
	afx_msg void OnAfficherTraj();
	afx_msg void afficherDebuiter();
	afx_msg void OnAffcherMarq();
	afx_msg void OnBnClickedButton6();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJETS4DLG_H__356A7BC6_7862_445C_8EB8_37788183F798__INCLUDED_)
