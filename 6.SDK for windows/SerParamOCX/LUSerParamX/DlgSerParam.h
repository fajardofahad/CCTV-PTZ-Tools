#if !defined(AFX_DLGSERPARAM_H__4C8202E0_BC44_4E36_B582_5D1F12D6AB18__INCLUDED_)
#define AFX_DLGSERPARAM_H__4C8202E0_BC44_4E36_B582_5D1F12D6AB18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSerParam.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSerParam dialog
#include "DlgSerGogal.h"
#include "DlgSerNet.h"
#include "DlgSerUser.h"
#include "DlgChanEnc.h"
#include "DlgChOSD.h"
#include "DlgCHMotionArea.h"
#include "DlgChMotionTime.h"
#include "DlgChRecvTime.h"
#include "DlgChVMask.h"
#include "DlgChVParam.h"
#include "DlgCHVHide.h"
#include "DlgCHVLost.h"
#include "DlgCHJpegParam.h"
#include "DlgChPtz.h"
#include "DlgAlarm.h"
#include "DlgSerDisk.h"
#include "DlgSerSave.h"
#include "DlgCHAudioParam.h"
#include "DlgWireless.h"
#include "DlgHumitureParam.h"
#include "DlgExAlarmParam.h"

class CDlgSerParam : public CDialog
{
// Construction
public:
	CString m_sername;
	CString m_serurl;
	WORD    m_serport;
	CString m_username,m_password;

	int m_chs,m_alarmins,m_alarmouts;
	CDlgSerParam(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSerParam)
	enum { IDD = IDD_DLG_PARAM };
	CStatic	m_txtMsginfo;
	CTreeCtrl	m_treefun;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSerParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CWnd *m_curdlg;
	int   m_curchno;
	CDlgSerGogal m_dlgSerGogal;
	CDlgSerNet   m_dlgSerNet;
	CDlgSerUser  m_dlgSerUser;
	CDlgChanEnc  m_dlgChanEnc;
	CDlgChOSD    m_dlgChanOSD;
	CDlgCHMotionArea m_dlgChMArea;
	CDlgChMotionTime m_dlgChMTime;
	CDlgChRecvTime   m_dlgChRecTime;
	CDlgChVMask      m_dlgChVMask;
	CDlgChVParam	 m_dlgChVParam;
	CDlgCHVHide      m_dlgChVHide;
	CDlgCHVLost      m_dlgChVLost;
	CDlgCHJpegParam  m_dlgChJpeg;
	CDlgChPtz        m_dlgChPtz;
	CDlgAlarm        m_dlgAlarm;
	CDlgSerDisk		 m_dlgSerDisk;
	CDlgSerSave      m_dlgSerSave;
	CDlgCHAudioParam m_dlgAudioParam;
	CDlgWireless     m_dlgwireless;
	CDlgHumitureParam	m_dlghumitureparam;
	CDlgExAlarmParam    m_dlgexalarmparam;
	// Generated message map functions
	//{{AFX_MSG(CDlgSerParam)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnDblclkTreefun(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTreefun(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitTree();
	void CreateAllDlg();
	void DeleteAllDlg();
	LRESULT OnDlgInit(WPARAM wParam,LPARAM lParam);
	LRESULT OnLogMsg(WPARAM wParam,LPARAM lParam);
public:
	int   m_dlgnums;
	CWnd *m_dlglist[30];
	LONG m_hParam;
	HANDLE m_hThread;
public:
	int ReadParam(int opt,int ch,void *param1,void *param2,void *param3);
	int SaveParam(int opt,int ch,void *param1,void *param2,void *param3);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSERPARAM_H__4C8202E0_BC44_4E36_B582_5D1F12D6AB18__INCLUDED_)
