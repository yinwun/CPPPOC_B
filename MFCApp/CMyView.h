#pragma once



// CMyView 窗体视图

class CMyView : public CFormView
{
	DECLARE_DYNCREATE(CMyView)

protected:
	CMyView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPP_DIALOG };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* pDC);
};


