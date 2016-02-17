#pragma once
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

/////////////////////////////////////////////////////////////////////////////

class CMP3_RecorderApp : public CWinApp
{
public:
	CMP3_RecorderApp();
	bool IsVistaOS() { return m_is_vista; }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMP3_RecorderApp)
public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

public:
	//{{AFX_MSG(CMP3_RecorderApp)
	afx_msg void OnAppAbout();
	afx_msg void OnHelpWww();
	afx_msg void OnHelpEmail();
	afx_msg void OnHelpDoc();
	afx_msg void OnHelpEntercode();
	afx_msg void OnHelpHowto();
	afx_msg void OnUpdateHelpEntercode(CCmdUI* pCmdUI);
	afx_msg void OnUpdateHelpHowto(CCmdUI* pCmdUI);
	afx_msg void OnHelpOrderOnline();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	bool IsNeedOneInstance();
	bool IsAlreadyRunning();
	static BOOL CALLBACK searcher(HWND hWnd, LPARAM lParam);
	void InitLogger();

private:
	bool m_is_vista;
	friend class RegistryConfig; //to access SetRegistryKey

public:
	virtual BOOL OnIdle(LONG lCount);
};
