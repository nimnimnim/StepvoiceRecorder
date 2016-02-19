#include "stdafx.h"
#include "NagScreenDlg.h"
#include "EnterCodeDlg.h"
#include "FileUtils.h"
#include "version.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CNagScreenDlg, CDialog)
	ON_BN_CLICKED(IDC_ENTERCODE, OnEntercode)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

CNagScreenDlg::CNagScreenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNagScreenDlg::IDD, pParent)
{
	m_boldFont.CreateFont(12, 0, 0, 0, FW_BOLD,  0, 0, 0, 0, 0, 0, 0, 0,
		_T("MS Sans Serif"));
}
//---------------------------------------------------------------------------

BOOL CNagScreenDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetIcon(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME)), TRUE); 

	m_wndOrder.SubclassDlgItem(IDC_GETNOW, this);
	m_wndOrder.SetUrl("http://stepvoice.com/order.shtml");

	CString version(STRFILEVER);
	CString mainVer;
	mainVer = version.Left(version.ReverseFind(_T('.')));
	mainVer = mainVer.Left(mainVer.ReverseFind(_T('.')));
	SetWindowText(_T("Stepvoice Recorder ") + mainVer);

	return TRUE;
}
//---------------------------------------------------------------------------

HBRUSH CNagScreenDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (pWnd->m_hWnd == GetDlgItem(IDC_THANKYOU)->m_hWnd)
		pDC->SelectObject(&m_boldFont);

	//else if (pWnd->m_hWnd == GetDlgItem(IDC_UNREGNOTICE)->m_hWnd) {
	//	pDC->SelectObject(&m_BoldFont);
	//	pDC->SetTextColor(RGB(150, 0, 0));
	//}

	return hbr;
}
//---------------------------------------------------------------------------

void CNagScreenDlg::OnEntercode() 
{
	CEnterCodeDlg dlg;
	if (dlg.DoModal() == IDOK)
	{	
		// Exit code as IDOK - to make an error and quit current instance.
		PostMessage(WM_COMMAND, IDOK, (LPARAM)GetDlgItem(IDCANCEL)->m_hWnd);

		const CString programPath = FileUtils::GetProgramPath();
		ShellExecute(::GetDesktopWindow(), _T("open"), programPath, NULL, NULL, SW_SHOW);
	}
}
//---------------------------------------------------------------------------
