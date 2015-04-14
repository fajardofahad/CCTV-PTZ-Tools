echo off
echo Uninstall Innoview IE Pack!Please close all IE browser, then continue...
pause
del  %windir%\system32\NetClient.dll
del  %windir%\system32\hi_h264dec.dll
del  %windir%\system32\hi_h264dec_w.dll
regsvr32 /u NetViewX.ocx
pause