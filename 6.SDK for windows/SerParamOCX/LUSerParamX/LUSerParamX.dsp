# Microsoft Developer Studio Project File - Name="LUSerParamX" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=LUSerParamX - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LUSerParamX.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LUSerParamX.mak" CFG="LUSerParamX - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LUSerParamX - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "LUSerParamX - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LUSerParamX - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obj"
# PROP Intermediate_Dir "../obj"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../commh/AppSysBaseCfg" /I "../../../../commh/NetCommdef" /I "../../../sdkh" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "L_IMPL_OBJECTSAFETY" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"../bin/LUSerParamX.ocx"
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\../obj
TargetPath=\Flatfish_ipcam_v60\host\NetSDK\SDK_PACK_EN\SerParamOCX\bin\LUSerParamX.ocx
InputPath=\Flatfish_ipcam_v60\host\NetSDK\SDK_PACK_EN\SerParamOCX\bin\LUSerParamX.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "LUSerParamX - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Ext "ocx"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../obj"
# PROP Intermediate_Dir "../obj"
# PROP Target_Ext "ocx"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../commh/AppSysBaseCfg" /I "../../../../commh/NetCommdef" /I "../../../sdkh" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "L_IMPL_OBJECTSAFETY" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../bin/LUSerParamX.ocx" /pdbtype:sept
# Begin Custom Build - Registering ActiveX Control...
OutDir=.\../obj
TargetPath=\Flatfish_ipcam_v60\host\NetSDK\SDK_PACK_EN\SerParamOCX\bin\LUSerParamX.ocx
InputPath=\Flatfish_ipcam_v60\host\NetSDK\SDK_PACK_EN\SerParamOCX\bin\LUSerParamX.ocx
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "LUSerParamX - Win32 Release"
# Name "LUSerParamX - Win32 Debug"
# Begin Group "OCXSer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LUSerParamX.cpp
# End Source File
# Begin Source File

SOURCE=.\LUSerParamX.def
# End Source File
# Begin Source File

SOURCE=.\LUSerParamX.h
# End Source File
# Begin Source File

SOURCE=.\LUSerParamX.odl
# End Source File
# Begin Source File

SOURCE=.\LUSerParamX.rc
# End Source File
# Begin Source File

SOURCE=.\LUSerParamXCtl.cpp
# End Source File
# Begin Source File

SOURCE=.\LUSerParamXCtl.h
# End Source File
# Begin Source File

SOURCE=.\LUSerParamXPpg.cpp
# End Source File
# Begin Source File

SOURCE=.\LUSerParamXPpg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Param"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\DlgAlarm.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgAlarm.h
# End Source File
# Begin Source File

SOURCE=.\DlgChanEnc.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChanEnc.h
# End Source File
# Begin Source File

SOURCE=.\DlgCHAudioParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCHAudioParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgCHJpegParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCHJpegParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgCHMotionArea.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCHMotionArea.h
# End Source File
# Begin Source File

SOURCE=.\DlgChMotionTime.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChMotionTime.h
# End Source File
# Begin Source File

SOURCE=.\DlgChOSD.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChOSD.h
# End Source File
# Begin Source File

SOURCE=.\DlgChPtz.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChPtz.h
# End Source File
# Begin Source File

SOURCE=.\DlgChRecvTime.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChRecvTime.h
# End Source File
# Begin Source File

SOURCE=.\DlgCHVHide.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCHVHide.h
# End Source File
# Begin Source File

SOURCE=.\DlgCHVLost.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCHVLost.h
# End Source File
# Begin Source File

SOURCE=.\DlgChVMask.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChVMask.h
# End Source File
# Begin Source File

SOURCE=.\DlgChVParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChVParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgExAlarmParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgExAlarmParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgFormatPro.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFormatPro.h
# End Source File
# Begin Source File

SOURCE=.\DlgHumitureParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgHumitureParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerDisk.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerGogal.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerGogal.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerNet.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerNet.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerParam.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerParam.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerSave.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerSave.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerUpdate.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerUpdate.h
# End Source File
# Begin Source File

SOURCE=.\DlgSerUser.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSerUser.h
# End Source File
# Begin Source File

SOURCE=.\DlgWireless.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgWireless.h
# End Source File
# Begin Source File

SOURCE=.\MotionArea.cpp
# End Source File
# Begin Source File

SOURCE=.\MotionArea.h
# End Source File
# End Group
# Begin Group "lib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\launet.h
# End Source File
# Begin Source File

SOURCE=.\VSNETStructDef.h
# End Source File
# Begin Source File

SOURCE=.\NetClient.lib
# End Source File
# End Group
# End Target
# End Project
