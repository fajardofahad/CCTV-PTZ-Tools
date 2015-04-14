#if !defined(AFX_DLGCHANENC_H__D5D0C584_85D0_4215_BE73_C90ACD5161DA__INCLUDED_)
#define AFX_DLGCHANENC_H__D5D0C584_85D0_4215_BE73_C90ACD5161DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChanEnc.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChanEnc dialog

class CDlgChanEnc : public CDialog
{
// Construction
public:
	CDlgChanEnc(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChanEnc)
	enum { IDD = IDD_DLG_CHENCPARAM };
	int		m_imageformat;
	int		m_streamtype;
	int		m_ikeyinterval;
	int		m_samplerate;
	int		m_audiobits;
	int		m_framerate;
	int		m_minqueue;
	int		m_maxqueue;
	int		m_maxbits;
	int		m_bitstype;
	int		m_subbitstype;
	int		m_subframerate;
	int		m_subikeyinterval;
	int		m_subimagformat;
	int		m_submaxqueue;
	int		m_submaxrate;
	int		m_subminqueue;
	int		m_substreamtype;
	int		m_alarmdelay;
	int		m_prerecodetime;
	int		m_videooffset;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChanEnc)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_ch;
	int m_type;
	CHANNELPARAM   m_chanpara;
	CHANNELPARAMEX m_chanparaex;
	VSSUBCHANPARAM m_subchparam;
	VSNETVIDEOOFFSET m_videooffsetparam;
	// Generated message map functions
	//{{AFX_MSG(CDlgChanEnc)
	afx_msg void OnBtnGet();
	afx_msg void OnBtnSet();
	afx_msg void OnBtnGet2();
	afx_msg void OnBtnSet2();
	afx_msg void OnBtnCopy1();
	afx_msg void OnBtnCopy2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	void GetParam(int enctype); //0:all,1:main;2:sub
	BOOL UpdateMainParam();
	BOOL UpdateSubParam();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnDlgFirst(WPARAM wParam,LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHANENC_H__D5D0C584_85D0_4215_BE73_C90ACD5161DA__INCLUDED_)
