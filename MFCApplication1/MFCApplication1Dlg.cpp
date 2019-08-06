
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	SetBackgroundColor(RGB(168, 168, 0));

	m_image.Load(L"test.png");

	CRect win_rect, client_rect;
	GetWindowRect(win_rect);
	GetClientRect(client_rect);

	m_cx_margin = win_rect.Width() - client_rect.Width() + 4;
	m_cy_margin = win_rect.Height() - client_rect.Height() + 4;

	GetDlgItem(IDC_BUTTON2)->GetWindowRect(win_rect);
	ScreenToClient(win_rect);

	m_top_margin = win_rect.bottom;

	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level+m_cx_margin, m_image.GetHeight()*m_zoom_level+m_cy_margin + m_top_margin, SWP_NOMOVE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위 디바이스 컨텍스트입니다.

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// 그냥 출력
		//m_image.Draw(dc, 0, 0);

		// 2배 출력
		m_image.Draw(dc, 2, 2+ m_top_margin, m_image.GetWidth()*m_zoom_level, m_image.GetHeight()*m_zoom_level);

		// CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton2()
{
	m_zoom_level = 2;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin + m_top_margin, SWP_NOMOVE);

	Invalidate();
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	m_zoom_level = 4;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin + m_top_margin, SWP_NOMOVE);

	Invalidate();
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	m_zoom_level = 8;
	SetWindowPos(NULL, 0, 0, m_image.GetWidth()*m_zoom_level + m_cx_margin, m_image.GetHeight()*m_zoom_level + m_cy_margin + m_top_margin, SWP_NOMOVE);

	Invalidate();
}
