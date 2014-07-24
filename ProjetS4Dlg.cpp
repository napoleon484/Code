// ProjetS4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProjetS4.h"
#include "ProjetS4Dlg.h"
#include <direct.h>


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
// CProjetS4Dlg dialog

//------------------------------------------
//
// Ajout de l'initialisation du drapeau de présence d'image à l'écran à la
// 	création de l'objet dialogue
//
//------------------------------------------


CProjetS4Dlg::CProjetS4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProjetS4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProjetS4Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

   // Initialisation du drapeau de lecture de l'image
   
	m_LoadedBitmap = 0;
}

void CProjetS4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProjetS4Dlg)
	DDX_Control(pDX, IDC_GRIS, m_ValeurGris);
	DDX_Control(pDX, IDC_FILENAME, m_Lire);
	DDX_Control(pDX, IDC_FILENAME2, m_LireTraj);
	DDX_Control(pDX, IDC_IMAGE, m_Image);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProjetS4Dlg, CDialog)
	//{{AFX_MSG_MAP(CProjetS4Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PARCOURIR, OnParcourir)
	ON_BN_CLICKED(IDC_AFFICHER, OnAfficher)
	ON_BN_CLICKED(IDC_SAUVEGARDE, OnSauvegarde)
	ON_BN_CLICKED(IDC_PROCEDE, OnProcede)
	ON_BN_CLICKED(IDC_GETPICT, OnGetpict)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_PARCOURIR2, &CProjetS4Dlg::OnParcourirTraj)
	ON_BN_CLICKED(IDC_AFFICHER2, &CProjetS4Dlg::OnAfficherTraj)
	ON_BN_CLICKED(IDC_BUTTON4, &CProjetS4Dlg::afficherDebuiter)
	ON_BN_CLICKED(IDC_BUTTON5, &CProjetS4Dlg::OnAffcherMarq)
	ON_BN_CLICKED(IDC_BUTTON6, &CProjetS4Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjetS4Dlg message handlers

BOOL CProjetS4Dlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjetS4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

//------------------------------------------
//
// Méthode générée par l'environnement. Elle est appelée lorsqu'il
//	est nécessaire de redessiner la fenêtre. L'ensemble des objets
//	" standards " de MS-Windows ont leur propre " OnPaint " par 
//	contre, pour le rectangle image, il faut ajouter notre propre 
//	code pour  l'affichage du bitmap lu.
//
//------------------------------------------

void CProjetS4Dlg::OnPaint() 
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

		//-------------------------------------------------
		// Ajout d'une fonction d'affichage de l'image

		CRect rect;
		m_Image.GetClientRect(&rect);
		CDC *DC = m_Image.GetDC();
		int width = rect.Width();
		int height = rect.Height();
		DC->BitBlt(0,0,width,height,&m_BitmapCDC,0,0,SRCCOPY);

		//-------------------------------------------------

		CDialog::OnPaint();

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProjetS4Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//------------------------------------------
//
// Lorsque l'utilisateur appuie sur le bouton " Parcourir ", cette
//	méthode est appelée. Elle utilise l'information déjà inscrite 
//	dans le champ " Choisir une image : " et y replace la nouvelle 
//	sélection de l'utilisateur en terminant. 
//
// L'utilisation de l'objet CFileDialog permet l'accès à la fenêtre 
//	" standard " de MS-Windows pour la recherche de fichier.
//
// Notez qu'un filtre est ajouté pour faciliter la recherche des 
//	" .BMP ".
//
//	Le squelette de cette méthode est généré par MS-VS.
//
//------------------------------------------


void CProjetS4Dlg::OnParcourir() 
{
	CString OpenFilter, ActualName;

	OpenFilter = "Bit map (*.bmp)|*.bmp||";

	m_Lire.GetWindowText(ActualName);

	if (ActualName.Right(1) == "\\")
		ActualName = ActualName + "*.bmp";

	if (ActualName.Right(1) == ":")
		ActualName = ActualName + "\\*.bmp";

	CFileDialog FileOpenDialog(
      TRUE,						// Ceci demande l'utilisation d'un 
								//	dialogue de lecture
      NULL,
      ActualName,
      OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST,
      OpenFilter,  
      AfxGetMainWnd()); 

	if(FileOpenDialog.DoModal()!=IDCANCEL)
		m_Lire.SetWindowText(FileOpenDialog.GetPathName());
	else
		AfxMessageBox("failed : " + ActualName);
}

//-------------------------------------------------
// Lecture de l'entête du fichier image pour s'assurer du contenu, 
// du format et des dimensions
               
//------------------------------------------
//
// Cette méthode est utilisée par la méthode " OnAfficher " pour 
//	permettre de lire les en-têtes du bitmap et aussi vérifier
//	l'existence du fichier (reçu en paramêtre) et qu'il est bien un 
//	bitmap.
//
// En sortie de cette méthode les membres m_bmfh et m_bmih contiennent
//	 les informations
//
// Retourne 0 si le fichier est valide, 1 si on a une erreur, 
//	2 si ce n'est pas un BMP
//
// À noter une correction à m_bmih.biSizeImage si elle contient une 
//	valeur de 0. Certains logiciels ne fournissent pas cette valeur 
//	puisqu'elle peut être calculée avec les autres paramètres de 
//	l'en-tête. Par contre, pour le présent logiciel, cette valeur 
//	est utilisée pour l'écriture de l'image et doit être valide.
//
//------------------------------------------


int CProjetS4Dlg::LoadBitmapHeader (LPCTSTR lpszFileName)
{

	CFile file;

	if (!file.Open(lpszFileName, CFile::modeRead))
		return 1;  	//Erreur d'ouverture
	
//------------------------------------------
	// Lecture des en-têtes
	file.Read ((char*)&m_bmfh,sizeof (BITMAPFILEHEADER));
	file.Read ((char*)&m_bmih,sizeof (BITMAPINFOHEADER));

	file.Close();


//------------------------------------------
// Valide la signature du fichier
	if (m_bmfh.bfType!='MB') return 2;		// Le fichier n'est pas un BMP

	if (m_bmih.biSizeImage == 0)
	{
		m_bmih.biSizeImage=(DWORD)m_bmih.biWidth * m_bmih.biBitCount; // octets par lignes
		m_bmih.biSizeImage=(((m_bmih.biSizeImage) + 31) / 32) * 4;    // Alignement DWORD
		m_bmih.biSizeImage*=m_bmih.biHeight;                          // Espace requis pour l'ensemble de l'image (en octets)
	}

	return 0;
}


//------------------------------------------
//
// Cette méthode est appelée lorsque l'utilisateur appuie sur
//	" Afficher ". Elle effectue la lecture et l'affichage du bitmap
//	 à l'écran dans le rectangle m_Image.
//
//  Affiche une erreur si le fichier n'est pas lu
//
//	Le squelette de cette méthode est généré par MS-VS.
//
//------------------------------------------
		

void CProjetS4Dlg::OnAfficher() 
{
	CString ActualName;

	m_Lire.GetWindowText(ActualName);  // Lecture du nom du fichier m_Lire

	if (!LireAfficherImage(ActualName))
			AfxMessageBox("Impossible d'ouvrir le fichier ou fichier invalide");

}


//------------------------------------------
//
// Cette méthode est appelé losque l'utilisateur appuie sur " Sauvegarde ". 
//	Le squelette de cette méthode est généré par MS-VS.
//
// La lecture d'un bitmap est assez simple puisque MS-Windows fournit
//	des fonctions pour effectuer cette tâche. Par contre, l'écriture
//	est plus complexe. Puisque ce logiciel utilise et modifie l'image 
//	directement à l'écran, il faut l'extraire et reformater le tout 
//	pour regénérer un fichier valide.
//
// Ici aussi on utilise un CFileDialog pour choisir le fichier destination.
//
//------------------------------------------


void CProjetS4Dlg::OnSauvegarde() 
{
	CString OpenFilter, ActualName;

	if (!m_LoadedBitmap)
	{
		AfxMessageBox("Aucun Bitmap disponible");

		return;
	}

//------------------------------------------
// Création d'un filtre appel et création du dialogue. 

	OpenFilter = "Bit map (*.bmp)|*.bmp||";

	m_Lire.GetWindowText(ActualName);

	if (ActualName.Right(1) == "\\")
		ActualName = ActualName + "*.bmp";

	if (ActualName.Right(1) == ":")
		ActualName = ActualName + "\\*.bmp";


	CFileDialog FileOpenDialog(
       FALSE, 					// Ceci demande l'utilisation d'un 
								//	dialogue d'écriture (notez le
								//	OFN_OVERWRITEPROMPT plus loin)

      NULL,
      ActualName,
      OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_PATHMUSTEXIST,
      OpenFilter,   
      AfxGetMainWnd());  

	if(FileOpenDialog.DoModal()!=IDCANCEL)
	{
		CFile file;
		BITMAPINFO bi;
		BYTE *buffer;

		if (!file.Open(FileOpenDialog.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
			return; 		//Erreur d'ouverture du fichier


//------------------------------------------
// Évaluation de la dimension du tableau des assignations des couleurs des
//	" pixels " de l'image. Notez le cas	particulier des couleurs 24 bits. 
	
		bi.bmiHeader = m_bmih;

		int biColorSize=0;

		if (m_bmih.biBitCount!=24) biColorSize=(1<<m_bmih.biBitCount);

		biColorSize*=sizeof(RGBQUAD);

//------------------------------------------
// Création d'un tampon pour recevoir l'image. 
//
// Ce tampon va aussi contenir le deuxième en-tête.

		buffer = new BYTE[m_bmfh.bfSize];

//------------------------------------------
// Ajout du deuxième en-tête au début du tampon.


		*(BITMAPINFOHEADER *)buffer = m_bmih;

		GetDIBits(m_BitmapCDC,(HBITMAP)m_Bitmap.GetSafeHandle(),0L,
				m_bmih.biHeight,

								// Ici on a une astuce pour permettre de lire
								// 	l'image et de conserver les positions des 
								//	octets ainsi que l'information sur les 
								//	couleurs en même temps.
								//
								// L'écriture de l'image va commencer après
								// 	l'information d'en-tête et l'espace 
								//	réservée pour la table des couleurs.

				(LPSTR)buffer+m_bmih.biSize + biColorSize, 

								// Le début du tampon contient l'en-tête de 
								//	structure BITMAPINFOHEADER. Cet 
								//	information est un élément de la 
								//	structure BITMAPINFO qui ajoute le 
								//	tableau des couleurs à utiliser pour 
								//	l'affichage de l'image. Cette section
								//	sera réécite par " GetDIBits " qui va 
								//	permettre d'inscrire les informations 
								//	dans notre fichier.

				 (BITMAPINFO *)buffer,		

				(DWORD) DIB_RGB_COLORS);

//------------------------------------------
// Écriture du premier en-tête (qui est le même que l'image d'origine)
//	ainsi que le tampons contenant le deuxième en-tête, le tableau des couleurs
// 	et l'image.

		file.Write ((char*)&m_bmfh,sizeof (BITMAPFILEHEADER));
		
// Dans la situation présente, le buffer contient aussi la palette (voir (LPSTR) dans le GetDIBIts)

		file.Write (buffer,m_bmfh.bfSize);

		file.Close();		// Fermeture du fichier

		delete buffer;		// Destruction du tampon

	}
	else
		AfxMessageBox("Échec : " + ActualName);
	
}


//------------------------------------------
//
// Fonction qui s'assurer que les couleurs sont conservé sur un octet même
// 	si les calculs s'effectue avec un " int "
//
//------------------------------------------

int ValidePixel(int x)
{
	if (x > 255) return 255;
	if (x < 0) return 0;
	return x;
}


//------------------------------------------
//
// Modifie le niveau de gris de l'image à l'écran. Il est important de noter
//	que l'image est édité directement dans l'écran et non dans un tampon
//	interne. Cette aproche est un simplification interessante au niveau du
// 	développement du code.
//
// Reçoit le niveau de gris à affecter aux pixels.
//
// À la fin, cette méthode demande un réaffichage du dialogue.
//
//------------------------------------------

void CProjetS4Dlg::ModifieGris(int niveau)
{

	int i,j;
	int red,green,blue;		// Pour permettre les calculs sur les 3 
							//	couleurs de bases d'un pixel


	COLORREF pixel;			// Pour permettre la lecture d'un pixel de
							//	l'écran

	for (i=0; i<m_bmih.biWidth;i++)
	{
		for (j=0; j<m_bmih.biHeight;j++)
		{

			// Lecture d'un pixel

			pixel = m_BitmapCDC.GetPixel(i,j); 		

			// Modification des 3 couleurs avec protection contre la

			red = ValidePixel(GetRValue(pixel) + niveau);
			green = ValidePixel(GetGValue(pixel) + niveau);
			blue = ValidePixel(GetBValue(pixel) + niveau);

			// Écriture d'un pixel

			m_BitmapCDC.SetPixel(i,j,RGB(red,green,blue));

		}
	
	}

	OnPaint();		// Rafraichissement de l'image

}


//------------------------------------------
//
// Procède à la modification de l'image. Après validation de l'image
// 	et lecture/validation du niveau de gris, cette méthode appelle la 
//	méthode " ModifieGris " pour effectuer le travail
//
//	Le squelette de cette méthode est généré par MS-VS.
//
//------------------------------------------


void CProjetS4Dlg::OnProcede() 
{
	CString Valeur;
	int changement;

	if (!m_LoadedBitmap)
	{
		AfxMessageBox("Aucun Bitmap disponible");

		return;
	}

	m_ValeurGris.GetWindowText(Valeur);

	changement = atoi(Valeur);

	if (changement < -100)
		AfxMessageBox("Minimum -100");	
	else
		if (changement > 100)
		   AfxMessageBox("Maxmimum 100");
		else
		   ModifieGris(changement);
}

//-------------------------------------------------
//
// Action relié à la demande de prise d'image par la caméra. Une erreur est
// affichée s'il n'est pas possible de créer le fichier de demande.
//
// Notez que la fonction attendra indéfiniement pour obtenir l'image.
//
//-------------------------------------------------

void CProjetS4Dlg::OnGetpict() 
{
		CFile file;

		if (!file.Open("c:/TransImage/GetPict.txt", CFile::modeCreate | CFile::modeWrite))
			{
			AfxMessageBox("Erreur génération du fichier de demande");
			return;
			}
	
		file.Close();

		/* Permet d'attendre sans compromettre les autres applications */

		while ( !LireAfficherImage("c:/TransImage/Image_Recu.bmp") ) 
			{ 
			  MSG msg;
			  ( ::PeekMessage( &msg, NULL, 0, 0, PM_NOREMOVE ) ) ;
			}
			
	remove("c:/TransImage/Image_Recu.bmp");
}

		//-------------------------------------------------
		// Outil pour lire une image selon le nom de fichier demandé. Demande un 
        // rafraichissement de l'image lorsque réussie

BOOL CProjetS4Dlg::LireAfficherImage(LPCTSTR lpszFileName)
{
	CPaintDC cdc(this);
	HBITMAP BitmapHandle;

	m_LoadedBitmap = 0;			// Drapeau remis à 0 pour indiquer
								//	qu'il n'y a plus d'image 
								//	valide à l'écran
								
	if (LoadBitmapHeader(lpszFileName) != 0)
	{
		return FALSE;   // Retourne FALSE si l'image n'est pas lue
	}
	
	Invalidate(TRUE);				// Demande un réaffichage du dialogue
									//	en indiquant que le contenu n'est
									//	plus valide
	UpdateWindow();

	m_BitmapCDC.DeleteDC();			// Efface l'ancien contexte du bitmap

	m_BitmapCDC.CreateCompatibleDC(m_Image.GetDC());   // Crée un nouvel espace 
                        													   //   pour la nouvelle image

//------------------------------------------
// Cette fonction de la librairie standard lie directement le bitmap d'un
//	fichier et retourne une référence sur l'image en mémoire si il y a succès
//------------------------------------------
  
  BitmapHandle = (HBITMAP)::LoadImage(NULL,LPCTSTR(lpszFileName),IMAGE_BITMAP,0,0,LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		
	if (BitmapHandle !=0)  					// Non NULL si la lecture a réussie
	{
		m_Bitmap.Detach();					// Efface l'ancien bitmap
		m_Bitmap.Attach(BitmapHandle);		// Conserve la nouvelle référence
		m_BitmapCDC.SelectObject(m_Bitmap); // Assigne l'image au rectangle
		m_LoadedBitmap = 1;					// Indique qu'une image est
											//	affichée
	}

	OnPaint();						// Force le réaffichage du dialogue
									//	(et de l'image)

return TRUE;  // retourne TRUE si la lecture est un succès
}


void CProjetS4Dlg::OnParcourirTraj()
{
	CString OpenFilter, ActualName;

	OpenFilter = "bin (*.bin)|*.bin||";

	m_LireTraj.GetWindowText(ActualName);

	if (ActualName.Right(1) == "\\")
		ActualName = ActualName + "*.bin";

	if (ActualName.Right(1) == ":")
		ActualName = ActualName + "\\*.bin";

	CFileDialog FileOpenDialog(
		TRUE,						// Ceci demande l'utilisation d'un 
									//	dialogue de lecture
		NULL,
		ActualName,
		OFN_HIDEREADONLY|OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST,
		OpenFilter,  
		AfxGetMainWnd()); 

	if(FileOpenDialog.DoModal()!=IDCANCEL)
		m_LireTraj.SetWindowText(FileOpenDialog.GetPathName());
	else
		AfxMessageBox("failed : " + ActualName);
}


void CProjetS4Dlg::OnAfficherTraj()
{
	// TODO: Add your control notification handler code here
}

// Affiche limage debruiter
void CProjetS4Dlg::afficherDebuiter()
{
	CString ActualName;
	char cCurrentPath[FILENAME_MAX];

	_getcwd(cCurrentPath, sizeof(cCurrentPath));
	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	ActualName = cCurrentPath;
	ActualName = ActualName + "\\Image_Orig2.bmp";
	if (!LireAfficherImage(ActualName))
		AfxMessageBox("Impossible d'ouvrir le fichier ou fichier invalide");
}


void CProjetS4Dlg::OnAffcherMarq()
{
	CString ActualName;
	char cCurrentPath[FILENAME_MAX];

	_getcwd(cCurrentPath, sizeof(cCurrentPath));
	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

	ActualName = cCurrentPath;
	ActualName = ActualName + "\\Image_Marq.bmp";
	if (!LireAfficherImage(ActualName))
		AfxMessageBox("Impossible d'ouvrir le fichier ou fichier invalide");
}


void CProjetS4Dlg::OnBnClickedButton6()
{
	float sensors[5];
	grue->GetSensor(sensors);
	float x = sensors[0];
	float y = sensors[1];
	float r = sensors[2];
	float beta = sensors[3];
	float alpha = sensors[4];
}
