// polyfit1_0Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "polyfit1_0.h"
#include "polyfit1_0Dlg.h"
#include "string"
#include "vector"
using std::vector;
using std::string;

// 本来想用vector, 懒23333
double arr_x[100];
double arr_y[100];
int cnt = 0;
double rtn[100];
int order = 2;
int polyfit(const double* const dependentValues,
            const double* const independentValues,
            unsigned int        countOfElements,
            unsigned int        order,
            double*             coefficients);

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
// CPolyfit1_0Dlg dialog

CPolyfit1_0Dlg::CPolyfit1_0Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPolyfit1_0Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPolyfit1_0Dlg)
	m_x = 0.0;
	m_y = 0.0;
	m_order = 0.0;
	m_rtn = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPolyfit1_0Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPolyfit1_0Dlg)
	DDX_Control(pDX, IDC_LIST1, m_l);
	DDX_Text(pDX, IDC_EDIT1, m_x);
	DDX_Text(pDX, IDC_EDIT2, m_y);
	DDX_Text(pDX, IDC_EDIT3, m_order);
	DDX_Text(pDX, IDC_EDIT4, m_rtn);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPolyfit1_0Dlg, CDialog)
	//{{AFX_MSG_MAP(CPolyfit1_0Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolyfit1_0Dlg message handlers

BOOL CPolyfit1_0Dlg::OnInitDialog()
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

void CPolyfit1_0Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPolyfit1_0Dlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPolyfit1_0Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPolyfit1_0Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
	CString m_dq;
	double x = m_x;
	double y = m_y;
	arr_x[cnt] = x;
	arr_y[cnt] = y;
	++cnt;
	char buf[200];
	sprintf(buf, "%.2f", x);
	string text = (string)buf + ", ";
	sprintf(buf, "%.2f", y);
	text = text + string(buf);
	m_dq = text.c_str();
	m_l.AddString(m_dq);
	UpdateData(0);
}

void CPolyfit1_0Dlg::OnButton2() 
{
	// 本来想写删除函数... 就需要重写一下顺序插入顺序删除, 懒233333
	// TODO: Add your control notification handler code here
	int n=m_l.GetCurSel();
	m_l.DeleteString(n);
}

void CPolyfit1_0Dlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(1);
    order = m_order;
	UpdateData(0);	
}

void CPolyfit1_0Dlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	polyfit(arr_x, arr_y, cnt, order, rtn);
	int len = order + 1;
	string tmp;
	char buf[200];
	for ( int i = 0; i < order; ++i )
	{
		sprintf(buf, "%.2f", rtn[i]);
		tmp = tmp + buf;
		tmp = tmp + "x^";
		sprintf(buf, "%d", order-i);
		tmp = tmp + buf;
		tmp = tmp + " + ";
	}
	sprintf(buf, "%.2f", rtn[i]);
	tmp = tmp + buf;

	UpdateData(1);
	m_rtn = tmp.c_str();
	UpdateData(0);	
}


// 拟合函数 
// 来自 https://github.com/natedomin/polyfit
int polyfit(const double* const dependentValues,
            const double* const independentValues,
            unsigned int        countOfElements,
            unsigned int        order,
            double*             coefficients)
{
    // Declarations...
    // ----------------------------------
    enum {maxOrder = 5};
    double B[maxOrder+1] = {0.0f};
    double P[((maxOrder+1) * 2)+1] = {0.0f};
    double A[(maxOrder + 1)*2*(maxOrder + 1)] = {0.0f};
    double x, y, powx;
    unsigned int ii, jj, kk;
    // Verify initial conditions....
    // ----------------------------------
    // This method requires that the countOfElements > 
    // (order+1) 
    if (countOfElements <= order)
        return -1;
    // This method has imposed an arbitrary bound of
    // order <= maxOrder.  Increase maxOrder if necessary.
    if (order > maxOrder)
        return -1;
    // Begin Code...
    // ----------------------------------
    // Identify the column vector
    for (ii = 0; ii < countOfElements; ii++)
    {
        x    = dependentValues[ii];
        y    = independentValues[ii];
        powx = 1;

        for (jj = 0; jj < (order + 1); jj++)
        {
            B[jj] = B[jj] + (y * powx);
            powx  = powx * x;
        }
    }
    // Initialize the PowX array
    P[0] = countOfElements;
    // Compute the sum of the Powers of X
    for (ii = 0; ii < countOfElements; ii++)
    {
        x    = dependentValues[ii];
        powx = dependentValues[ii];

        for (jj = 1; jj < ((2 * (order + 1)) + 1); jj++)
        {
            P[jj] = P[jj] + powx;
            powx  = powx * x;
        }
    }
    // Initialize the reduction matrix
    //
    for (ii = 0; ii < (order + 1); ii++)
    {
        for (jj = 0; jj < (order + 1); jj++)
        {
            A[(ii * (2 * (order + 1))) + jj] = P[ii+jj];
        }

        A[(ii*(2 * (order + 1))) + (ii + (order + 1))] = 1;
    }
    // Move the Identity matrix portion of the redux matrix
    // to the left side (find the inverse of the left side
    // of the redux matrix
    for (ii = 0; ii < (order + 1); ii++)
    {
        x = A[(ii * (2 * (order + 1))) + ii];
        if (x != 0)
        {
            for (kk = 0; kk < (2 * (order + 1)); kk++)
            {
                A[(ii * (2 * (order + 1))) + kk] = 
                    A[(ii * (2 * (order + 1))) + kk] / x;
            }
            for (jj = 0; jj < (order + 1); jj++)
            {
                if ((jj - ii) != 0)
                {
                    y = A[(jj * (2 * (order + 1))) + ii];
                    for (kk = 0; kk < (2 * (order + 1)); kk++)
                    {
                        A[(jj * (2 * (order + 1))) + kk] = 
                            A[(jj * (2 * (order + 1))) + kk] -
                            y * A[(ii * (2 * (order + 1))) + kk];
                    }
                }
            }
        }
        else
        {
            // Cannot work with singular matrices
            return -1;
        }
    }
    // Calculate and Identify the coefficients
    for (ii = 0; ii < (order + 1); ii++)
    {
        for (jj = 0; jj < (order + 1); jj++)
        {
            x = 0;
            for (kk = 0; kk < (order + 1); kk++)
            {
                x = x + (A[(ii * (2 * (order + 1))) + (kk + (order + 1))] *
                    B[kk]);
            }
            coefficients[ii] = x;
        }
    }
    return 0;
}