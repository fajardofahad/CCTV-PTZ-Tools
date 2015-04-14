// DlgSerParam.cpp : implementation file
//

#include "stdafx.h"
#include "LUSerParamX.h"
#include "DlgSerParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSerParam dialog
CDlgSerParam *g_SerParam = NULL;

static UINT CALLBACK threadParam(CDlgSerParam *pDlg);

#define SETDLGLIST(dlg) {m_dlglist[m_dlgnums] = dlg; m_dlgnums ++;}
CDlgSerParam::CDlgSerParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSerParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSerParam)
	//}}AFX_DATA_INIT
	m_chs = 4;
	m_alarmins = 4;
	m_alarmouts= 4;
	m_curdlg = NULL;
	m_curchno = -1;
	m_hParam  = -1;
	m_hThread = NULL;

	m_dlgnums = 0;
	g_SerParam = this;
}


void CDlgSerParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSerParam)
	DDX_Control(pDX, IDC_STATIC_INFO, m_txtMsginfo);
	DDX_Control(pDX, IDC_TREEFUN, m_treefun);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSerParam, CDialog)
	//{{AFX_MSG_MAP(CDlgSerParam)
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_TREEFUN, OnDblclkTreefun)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREEFUN, OnSelchangedTreefun)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
	ON_MESSAGE(DLGLOADPARAM_MSG,OnDlgInit)
	ON_MESSAGE(DLGPARM_LOGINMSG,OnLogMsg)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSerParam message handlers

BOOL CDlgSerParam::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	PostMessage(DLGLOADPARAM_MSG,0,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSerParam::InitTree()
{
	int i;
	// TODO: Add extra initialization here
	HTREEITEM hItemPare,hItemSub,hItemThrd;
	CString strinfo,strtmp;

	strinfo.LoadString(IDS_STRING201);
	hItemPare = m_treefun.InsertItem(strinfo,0,0,NULL);
	m_treefun.SetItemData(hItemPare,0);

	strinfo.LoadString(IDS_STRING203);
	hItemSub = m_treefun.InsertItem(strinfo,0,0,hItemPare);
	m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgSerGogal);

	strinfo.LoadString(IDS_STRING202);
	hItemSub = m_treefun.InsertItem(strinfo,0,0,hItemPare);
	m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgSerNet);

	strinfo.LoadString(IDS_STRING285);
	hItemSub = m_treefun.InsertItem(strinfo,0,0,hItemPare);
	m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgwireless);
	strinfo.LoadString(IDS_STRING217);
	hItemSub = m_treefun.InsertItem(strinfo,0,0,hItemPare);
	m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgSerUser);

	strinfo.LoadString(IDS_STRING222);
	hItemSub = m_treefun.InsertItem(strinfo,0,0,hItemPare);
	m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgSerSave);

	m_treefun.Expand(hItemPare,TVE_EXPAND);

	strinfo.LoadString(IDS_STRING206);
	hItemPare = m_treefun.InsertItem(strinfo,0,0,NULL);
	m_treefun.SetItemData(hItemPare,0);

	for(i=0;i<m_chs;i++)
	{
		if(m_chs > 1)
		{
			strtmp.LoadString(IDS_STRING205);
			strinfo.Format(strtmp,i+1);
			hItemSub = m_treefun.InsertItem(strinfo,0,0,hItemPare);
			m_treefun.SetItemData(hItemSub,0);
		}
		else
		{
			hItemSub = hItemPare;
		}

		strinfo.LoadString(IDS_STRING207);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChanEnc);

		strinfo.LoadString(IDS_STRING208);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChMArea);

		strinfo.LoadString(IDS_STRING221);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChMTime);

		strinfo.LoadString(IDS_STRING209);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChanOSD);

		strinfo.LoadString(IDS_STRING210);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChRecTime);

		strinfo.LoadString(IDS_STRING212);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChVParam);

		strinfo.LoadString(IDS_STRING213);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChVMask);

		strinfo.LoadString(IDS_STRING214);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChVHide);

		strinfo.LoadString(IDS_STRING215);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChVLost);

		strinfo.LoadString(IDS_STRING216);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgChJpeg);
		strinfo.LoadString(IDS_STRING280);
		hItemThrd = m_treefun.InsertItem(strinfo,i,0,hItemSub);
		m_treefun.SetItemData(hItemThrd,(DWORD)&m_dlgAudioParam);
		
	}
	m_treefun.Expand(hItemPare,TVE_EXPAND);


	strinfo.LoadString(IDS_STRING204);
	hItemPare = m_treefun.InsertItem(strinfo,0,0,NULL);
	m_treefun.SetItemData(hItemPare,0);
	for(i=0;i<m_chs;i++)
	{
		strtmp.LoadString(IDS_STRING205);
		strinfo.Format(strtmp,i+1);
		hItemSub = m_treefun.InsertItem(strinfo,i,0,hItemPare);
		m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgChPtz);
	}
	m_treefun.Expand(hItemPare,TVE_EXPAND);

	strinfo.LoadString(IDS_STRING218);
	hItemPare = m_treefun.InsertItem(strinfo,0,0,NULL);
	m_treefun.SetItemData(hItemPare,0);
	for(i=0;i<m_alarmins;i++)
	{
		strtmp.LoadString(IDS_STRING219);
		strinfo.Format(strtmp,i+1);
		hItemSub = m_treefun.InsertItem(strinfo,i,0,hItemPare);
		m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgAlarm);
	}
	m_treefun.Expand(hItemPare,TVE_EXPAND);

	strinfo.LoadString(IDS_STRING288);
	hItemPare = m_treefun.InsertItem(strinfo,0,0,NULL);
	m_treefun.SetItemData(hItemPare,0);
	{
		strinfo.LoadString(IDS_STRING289);
		hItemSub = m_treefun.InsertItem(strinfo,i,0,hItemPare);
		m_treefun.SetItemData(hItemSub,(DWORD)&m_dlgexalarmparam);
		strinfo.LoadString(IDS_STRING290);
		hItemSub = m_treefun.InsertItem(strinfo,i,0,hItemPare);
		m_treefun.SetItemData(hItemSub,(DWORD)&m_dlghumitureparam);
	}
	m_treefun.Expand(hItemPare,TVE_EXPAND);

	strinfo.LoadString(IDS_STRING220);
	hItemPare = m_treefun.InsertItem(strinfo,0,0,NULL);
	m_treefun.SetItemData(hItemPare,(DWORD)&m_dlgSerDisk);
}

void CDlgSerParam::CreateAllDlg()
{
	CWnd *pBase = GetDlgItem(IDC_STATIC_DLG);
	CRect rectdlg;
	pBase->GetClientRect(&rectdlg);
	rectdlg.top += 8;
	rectdlg.bottom -= 4;
	rectdlg.left += 2;
	rectdlg.right -= 3;
	m_dlgSerGogal.Create(IDD_DLG_SERGOBAL,pBase);
	m_dlgSerGogal.ShowWindow(SW_HIDE);
	m_dlgSerGogal.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgSerGogal);

	m_dlgSerNet.Create(IDD_DLG_SERNET,pBase);
	m_dlgSerNet.ShowWindow(SW_HIDE);
	m_dlgSerNet.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgSerNet);

	m_dlgwireless.Create(IDD_DLG_WIRELESS,pBase);
	m_dlgwireless.ShowWindow(SW_HIDE);
	m_dlgwireless.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgwireless);

	m_dlgSerUser.Create(IDD_DLG_SERUSER,pBase);
	m_dlgSerUser.ShowWindow(SW_HIDE);
	m_dlgSerUser.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgSerUser);

	m_dlgSerSave.Create(IDD_DLG_SERSAVE,pBase);
	m_dlgSerSave.ShowWindow(SW_HIDE);
	m_dlgSerSave.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgSerSave);

	m_dlgChanEnc.Create(IDD_DLG_CHENCPARAM,pBase);
	m_dlgChanEnc.ShowWindow(SW_HIDE);
	m_dlgChanEnc.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChanEnc);

	m_dlgChanOSD.Create(IDD_DLG_CHOSD,pBase);
	m_dlgChanOSD.ShowWindow(SW_HIDE);
	m_dlgChanOSD.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChanOSD);

	m_dlgChMArea.Create(IDD_DLG_CHMOTIONAREA,pBase);
	m_dlgChMArea.ShowWindow(SW_HIDE);
	m_dlgChMArea.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChMArea);

	m_dlgChMTime.Create(IDD_DLG_CHMOTIONTIME,pBase);
	m_dlgChMTime.ShowWindow(SW_HIDE);
	m_dlgChMTime.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChMTime);

	m_dlgChRecTime.Create(IDD_DLG_CHRECVTIME,pBase);
	m_dlgChRecTime.ShowWindow(SW_HIDE);
	m_dlgChRecTime.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChRecTime);

	m_dlgChVMask.Create(IDD_DLG_CHVMASK,pBase);
	m_dlgChVMask.ShowWindow(SW_HIDE);
	m_dlgChVMask.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChVMask);

	m_dlgChVParam.Create(IDD_DLG_CHVPARAM,pBase);
	m_dlgChVParam.ShowWindow(SW_HIDE);
	m_dlgChVParam.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChVParam);

	m_dlgChVHide.Create(IDD_DLG_CHVHIDE,pBase);
	m_dlgChVHide.ShowWindow(SW_HIDE);
	m_dlgChVHide.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChVHide);

	m_dlgChVLost.Create(IDD_DLG_CHVLOST,pBase);
	m_dlgChVLost.ShowWindow(SW_HIDE);
	m_dlgChVLost.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChVLost);

	m_dlgChJpeg.Create(IDD_DLG_CHJPEGPARA,pBase);
	m_dlgChJpeg.ShowWindow(SW_HIDE);
	m_dlgChJpeg.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChJpeg);

	m_dlgChPtz.Create(IDD_DLG_CHPTZ,pBase);
	m_dlgChPtz.ShowWindow(SW_HIDE);
	m_dlgChPtz.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgChPtz);

	m_dlgAlarm.Create(IDD_DLG_ALARM,pBase);
	m_dlgAlarm.ShowWindow(SW_HIDE);
	m_dlgAlarm.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgAlarm);

	m_dlgSerDisk.Create(IDD_DLG_SERDISK,pBase);
	m_dlgSerDisk.ShowWindow(SW_HIDE);
	m_dlgSerDisk.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgSerDisk);

	m_dlgAudioParam.Create(IDD_DLG_AUDIOPARAM,pBase);
	m_dlgAudioParam.ShowWindow(SW_HIDE);
	m_dlgAudioParam.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgAudioParam);

	m_dlgexalarmparam.Create(IDD_DLG_EXALARMPARAM,pBase);
	m_dlgexalarmparam.ShowWindow(SW_HIDE);
	m_dlgexalarmparam.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlgexalarmparam);

	m_dlghumitureparam.Create(IDD_DLG_HUMITUREPRAM,pBase);
	m_dlghumitureparam.ShowWindow(SW_HIDE);
	m_dlghumitureparam.MoveWindow(&rectdlg);
	SETDLGLIST(&m_dlghumitureparam);
}

void CDlgSerParam::DeleteAllDlg()
{
}

void CDlgSerParam::OnDestroy() 
{
	if(m_hParam != -1)
	{
		VSNET_ClientMessageClose(m_hParam);
		m_hParam = -1;
	}
	if(m_hThread)
	{
		WaitForSingleObject(m_hThread,-1);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}
	DeleteAllDlg();
	CDialog::OnDestroy();	
}

void CDlgSerParam::OnDblclkTreefun(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
}

void CDlgSerParam::OnSelchangedTreefun(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	CWnd *pSetDlg = NULL;
	int nimageno,nselimageno;
	HTREEITEM pItem = m_treefun.GetSelectedItem();
	if(pItem == NULL) goto err_exit;
	pSetDlg = (CWnd*)m_treefun.GetItemData(pItem);
	if(pSetDlg == NULL) goto err_exit;

	m_treefun.GetItemImage(pItem,nimageno,nselimageno);

	if(m_curdlg)
	{
		if(pSetDlg == m_curdlg && m_curchno == nimageno)
			return;
		m_curdlg->PostMessage(DLGFREEPARAM_MSG,0,0);
		m_curdlg->ShowWindow(SW_HIDE);
	}
	//TRACE("chno : %d\n",nimageno);
	m_txtMsginfo.SetWindowText("");
	m_curdlg = pSetDlg;
	pSetDlg->PostMessage(DLGLOADPARAM_MSG,0,nimageno);
	pSetDlg->ShowWindow(SW_SHOW);
	*pResult = 0;
	return;
err_exit:
	m_txtMsginfo.SetWindowText("");
	if(m_curdlg)
	{
		m_curdlg->PostMessage(DLGFREEPARAM_MSG,0,0);
		m_curdlg->ShowWindow(SW_HIDE);
		m_curdlg = NULL;
		Invalidate();
	}
	*pResult = 0;
}

LRESULT CDlgSerParam::OnDlgInit(WPARAM wParam,LPARAM lParam)
{
	CString strmsg;
	UINT ID;
	strmsg.LoadString(IDS_STRING223);
	m_txtMsginfo.SetWindowText(strmsg);

	CreateAllDlg();

	m_hThread = (HANDLE)_beginthreadex(NULL,1024 * 10,
		(unsigned (__stdcall *) (void *))&threadParam,
		this,0,&ID);
	return 0;
}

LRESULT CDlgSerParam::OnLogMsg(WPARAM wParam,LPARAM lParam)
{
	CString strmsg;
	switch(lParam)
	{
	case LOGIN_FAILED:
		strmsg.LoadString(IDS_STRING224);
		m_txtMsginfo.SetWindowText(strmsg);
		strmsg.LoadString(IDS_STRING225);
		AfxMessageBox(IDS_STRING225);
		CDialog::OnCancel();
		return 0;
	case LOGIN_OK:
		strmsg.LoadString(IDS_STRING226);
		m_txtMsginfo.SetWindowText(strmsg);
		break;
	case LOGIN_USERERRNO:
		strmsg.LoadString(IDS_STRING227);
		m_txtMsginfo.SetWindowText(strmsg);
		AfxMessageBox(IDS_STRING225);
		CDialog::OnCancel();
		return 0;
	case LOGIN_USEROK:
		InitTree();
		strmsg.LoadString(IDS_STRING228);
		m_txtMsginfo.SetWindowText(strmsg);
		GetDlgItem(IDC_TREEFUN)->EnableWindow(TRUE);
		for(int i=0;i<m_dlgnums;i++)
		{
			m_dlglist[i]->PostMessage(DLGPRAM_INITMSG,0,0);
		}
		break;
	}
	return 0;
}

static UINT CALLBACK threadParam(CDlgSerParam *pDlg)
{
	int iRet;
	Sleep(300);
	pDlg->m_hParam = VSNET_ClientMessageOpen((char*)((const char*)pDlg->m_sername),
		(char*)((const char*)pDlg->m_serurl),
		(char*)((const char*)pDlg->m_username),(char*)((const char*)pDlg->m_password),
		pDlg->m_serport);
	if(pDlg->m_hParam == -1)
	{
		pDlg->PostMessage(DLGPARM_LOGINMSG,0,LOGIN_FAILED);
		return -1;
	}
	pDlg->PostMessage(DLGPARM_LOGINMSG,0,LOGIN_OK);
	iRet = VSNET_ClientMessageOpt(pDlg->m_hParam,MESSAGE_CMD_AFFIRMUSER,0,NULL,NULL,NULL);
	if(iRet != 0)
	{
		pDlg->PostMessage(DLGPARM_LOGINMSG,0,LOGIN_USERERRNO);
		return -1;
	}
	iRet = VSNET_ClientMessageOpt(pDlg->m_hParam,MESSAGE_SERVERCHS,0,&pDlg->m_chs,&pDlg->m_alarmins,&pDlg->m_alarmouts);
	if(!iRet)
	{
		pDlg->PostMessage(DLGPARM_LOGINMSG,0,LOGIN_USERERRNO);
		return -1;
	}
	pDlg->PostMessage(DLGPARM_LOGINMSG,0,LOGIN_USEROK);
	return 0;
}

int CDlgSerParam::ReadParam(int opt,int ch,void *param1,void *param2,void *param3)
{
	CString strmsg;
	strmsg.LoadString(IDS_STRING229);
	m_txtMsginfo.SetWindowText(strmsg);
	Invalidate();
	return VSNET_ClientMessageOpt(m_hParam,opt,ch,param1,param2,param3);
}

int CDlgSerParam::SaveParam(int opt,int ch,void *param1,void *param2,void *param3)
{
	CString strmsg;
	strmsg.LoadString(IDS_STRING230);
	m_txtMsginfo.SetWindowText(strmsg);
	Invalidate();
	return VSNET_ClientMessageOpt(m_hParam,opt,ch,param1,param2,param3);
}

void CDlgSerParam::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
}
