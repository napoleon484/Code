// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

// Modifiez les définitions suivantes si vous devez cibler une plate-forme avant celles spécifiées ci-dessous.
// Reportez-vous à MSDN pour obtenir les dernières informations sur les valeurs correspondantes pour les différentes plates-formes.
// This is used to 

#define USE_MOCK_CLASS
#ifdef USE_MOCK_CLASS
#define CLASS_CRANE MockGrue
#else 
#define CLASS_CRANE Grue
#endif 

#ifndef WINVER				// Autorise l'utilisation des fonctionnalités spécifiques à Windows XP ou version ultérieure.
#define WINVER 0x0501		// Attribuez la valeur appropriée à cet élément pour cibler d'autres versions de Windows.
#endif

#ifndef _WIN32_WINNT		// Autorise l'utilisation des fonctionnalités spécifiques à Windows XP ou version ultérieure.                   
#define _WIN32_WINNT 0x0501	// Attribuez la valeur appropriée à cet élément pour cibler d'autres versions de Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Autorise l'utilisation des fonctionnalités spécifiques à Windows 98 ou version ultérieure.
#define _WIN32_WINDOWS 0x0410 // Attribuez la valeur appropriée à cet élément pour cibler Windows Me ou version ultérieure.
#endif

#ifndef _WIN32_IE			// Autorise l'utilisation des fonctionnalités spécifiques à Internet Explorer 6.0 ou version ultérieure.
#define _WIN32_IE 0x0600	// Attribuez la valeur appropriée à cet élément pour cibler d'autres versions d'Internet Explorer.
#endif

#if !defined(AFX_STDAFX_H__8F6044F5_2C14_422D_AB98_551C21DEA298__INCLUDED_)
#define AFX_STDAFX_H__8F6044F5_2C14_422D_AB98_551C21DEA298__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include <afxmt.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__8F6044F5_2C14_422D_AB98_551C21DEA298__INCLUDED_)
