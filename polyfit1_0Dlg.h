// polyfit1_0Dlg.h : header file
//

#if !defined(AFX_POLYFIT1_0DLG_H__2D8C31E0_A6E8_4649_8511_725A771C1239__INCLUDED_)
#define AFX_POLYFIT1_0DLG_H__2D8C31E0_A6E8_4649_8511_725A771C1239__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPolyfit1_0Dlg dialog

class CPolyfit1_0Dlg : public CDialog
{
// Construction
public:
	CPolyfit1_0Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPolyfit1_0Dlg)
	enum { IDD = IDD_POLYFIT1_0_DIALOG };
	CListBox	m_l;
	double	m_x;
	double	m_y;
	double	m_order;
	CString	m_rtn;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolyfit1_0Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPolyfit1_0Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYFIT1_0DLG_H__2D8C31E0_A6E8_4649_8511_725A771C1239__INCLUDED_)
