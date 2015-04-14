echo off
echo Innoview IE Pack!Please close all IE browser, then continue...
pause
copy NetViewX.ocx %windir%\system32
copy NetClient.dll %windir%\system32
copy hi_h264dec.dll %windir%\system32
copy NetViewX.inf %windir%\system32
copy hi_h264dec_w.dll %windir%\system32
chdir /D %windir%\system32
regsvr32 NetViewX.ocx
pause