5// CMyView.cpp: 实现文件
//

#include "pch.h"
#include "MFCApp.h"
#include "CMyView.h"


// CMyView

IMPLEMENT_DYNCREATE(CMyView, CFormView)

CMyView::CMyView()
	: CFormView(IDD_MFCAPP_DIALOG)
{

}

CMyView::~CMyView()
{
}

void CMyView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyView, CFormView)
END_MESSAGE_MAP()


// CMyView 诊断

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG



// CMyView 消息处理程序


void CMyView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	CString str = _T("hello world!");
	pDC->DrawText(str, CRect(100, 10, 400, 400), DT_SINGLELINE | DT_LEFT | DT_VCENTER);
}
