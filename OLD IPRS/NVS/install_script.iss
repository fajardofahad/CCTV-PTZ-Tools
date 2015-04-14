;InnoSetupVersion=5.2.3

[Setup]
AppName=NVS CENTER
AppVerName=NVS CENTER 01.00.00.02
DefaultDirName=C:\Program Files\NVS CENTER
DefaultGroupName=NVS CENTER
OutputBaseFilename=NVS CENTER_V01.00.00.02
Compression=lzma
WizardImageFile=embedded\WizardImage.bmp
WizardSmallImageFile=embedded\WizardSmallImage.bmp

[Files]
Source: "{app}\NVS CENTER,1.exe"; DestDir: "{app}"; DestName: "NVS CENTER.exe"; Flags: ignoreversion 
Source: "{app}\alert.wav"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\CommonAudioDec.dll"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\CommonDevice.dll"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\CommonPlayer.dll"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\CommonVideoDec.dll"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\INNOVMonitorService.exe"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\LogManager.exe"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\NVS CENTER,2.exe"; DestDir: "{app}"; DestName: "NVS CENTER.exe"; Flags: ignoreversion 
Source: "{app}\Player.exe"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\RecordClientSDK.dll"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\RecordServerSDK.dll"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\RegOcx\LUSerParamX,1.ocx"; DestDir: "{app}\RegOcx"; DestName: "LUSerParamX.ocx"; Flags: regserver 
Source: "{app}\Decoders\Audio\G722Decoder.dll"; DestDir: "{app}\Decoders\Audio"; Flags: ignoreversion 
Source: "{app}\Decoders\Audio\G722Decoder.ilk"; DestDir: "{app}\Decoders\Audio"; Flags: ignoreversion 
Source: "{app}\Decoders\Audio\HisiADecoder.dll"; DestDir: "{app}\Decoders\Audio"; Flags: ignoreversion 
Source: "{app}\Decoders\Audio\HisiADecoder.ilk"; DestDir: "{app}\Decoders\Audio"; Flags: ignoreversion 
Source: "{app}\Decoders\Audio\MP3Decoder.dll"; DestDir: "{app}\Decoders\Audio"; Flags: ignoreversion 
Source: "{app}\Decoders\Audio\MP3Decoder.ilk"; DestDir: "{app}\Decoders\Audio"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\Hi264Decoder.dll"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\Hi264Decoder.ilk"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\Hi264Decoder.rar"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\MJPGDecoder.dll"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\MJPGDecoder.ilk"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\XvidDecoder.dll"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Decoders\Video\XvidDecoder.ilk"; DestDir: "{app}\Decoders\Video"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_en.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_en_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_en_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_off.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_on.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_tra.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_tra_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\alarm_tra_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\audio.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\audioen_disable.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\audioen_off.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\audioen_on.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\audio_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\audio_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\background.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\camerasel.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\camerasel_on.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\capbmp.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\capbmp_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\capbmp_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\cleanalarm.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\cleanalarm_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\cleanalarm_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\dislink.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\dislink_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\dislink_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emapcamalarm.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emapcamnomal.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_cam.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_cam_area.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_cam_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_en.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_en_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_en_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_output.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_output_area.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_output_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_preset.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_preset_area.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_sensor.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_sensor_area.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_sensor_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_tra.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_tra_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\emap_tra_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\facepic.ini"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\getaddr.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\getaddr_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\getaddr_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\LedOff.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\LedOn.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\limitation"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\localrecv.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\localrecv_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\localrecv_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\localrelay.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\localrelay_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\localrelay_on.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\lock_background.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\lock_cancel_in.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\lock_cancel_out.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\lock_ok_in.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\lock_ok_out.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\login_background.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\login_cancel_in.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\login_cancel_out.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\login_ok_in.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\login_ok_out.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\logout_background.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\logout_cancel_in.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\logout_cancel_out.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\logout_ok_in.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\logout_ok_out.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_en.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_en_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_en_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_tra.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_tra_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\loopview_tra_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mic.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mic_on.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode1.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode16.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode16_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode16_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode1_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode1_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode4.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode4_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode4_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode6.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode6_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode6_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode8.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode8_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode8_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode9.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode9_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mode9_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\modefull.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\modefull_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\modefull_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mp3talk.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mp3talk_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\mp3talk_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\page_left.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\page_left_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\page_left_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\page_right.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\page_right_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\page_right_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzauto.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzauto_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzauto_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzcall.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzcall_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzcall_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzctrlface.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzctrlface_en.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzctrlface_tra.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdevclose.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdevclose_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdevclose_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdevopen.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdevopen_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdevopen_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdown.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdown_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzdown_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzfocusadd.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzfocusadd_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzfocusadd_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzfocussub.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzfocussub_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzfocussub_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzirisadd.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzirisadd_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzirisadd_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzirissub.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzirissub_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzirissub_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzleft.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzleft_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzleft_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzpreset.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzpreset_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzpreset_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzright.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzright_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzright_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzspeed_blue.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzspeed_line.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzup.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzup_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzup_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzzoomadd.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzzoomadd_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzzoomadd_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzzoomsub.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzzoomsub_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptzzoomsub_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_loop_call_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_loop_call_on.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_loop_call_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_settext.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_settext_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_settext_dis_en.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_settext_en.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_settext_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_settext_push_en.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_setting_call.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_setting_call_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\ptz_setting_call_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_en.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_en_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_en_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_tra.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_tra_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\query_tra_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\record_off.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\record_on.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay1.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay1_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay1_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay2.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay2_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay2_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay3.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay3_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay3_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay4.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay4_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\relay4_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\remoterecv.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\remoterecv_dis.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\remoterecv_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\serverrecord_off.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\serverrecord_on.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\setaddr.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\setaddr_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\setaddr_push.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\tab.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\talk.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\talk_dis.bmp"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\Skin\blue\talk_push.BMP"; DestDir: "{app}\Skin\blue"; Flags: ignoreversion 
Source: "{app}\RegOcx\CamSearch.dll"; DestDir: "{app}\RegOcx"; Flags: ignoreversion 
Source: "{app}\RegOcx\hi_h264dec_w.dll"; DestDir: "{app}\RegOcx"; Flags: ignoreversion 
Source: "{app}\RegOcx\LUSerParamX,2.ocx"; DestDir: "{app}\RegOcx"; DestName: "LUSerParamX.ocx"; Flags: ignoreversion 
Source: "{app}\RegOcx\LUSerParamXEn.dll"; DestDir: "{app}\RegOcx"; Flags: ignoreversion 
Source: "{app}\RegOcx\NetClient.dll"; DestDir: "{app}\RegOcx"; Flags: ignoreversion 
Source: "{app}\RegOcx\PlayerSDK.dll"; DestDir: "{app}\RegOcx"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\CamSearch.dll"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\hi_h264dec_w.dll"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\LCDevice.dll"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\LUSerParamX.ocx"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\LUSerParamXEn.dll"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\NetClient.dll"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder1\PlayerSDK.dll"; DestDir: "{app}\Devices\encoder1"; Flags: ignoreversion 
Source: "{app}\Devices\encoder2\HHDevice.dll"; DestDir: "{app}\Devices\encoder2"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\addspeed.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\addspeed_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\addspeed_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\addspeed_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\background - 副本.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\background.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\calendarbtn.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\calendarbtn_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\calendarbtn_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\CalendarPanel.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera01.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera01_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera02.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera02_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera03.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera03_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera04.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Camera04_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Datebtn.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\Datebtn_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\exitapp.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\exitapp_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\exitapp_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\exitapp_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\facepic.ini"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\filelistbtn.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\filelistbtn_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\frameback.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\frameback_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\frameback_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\frameback_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\framefront.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\framefront_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\framefront_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\framefront_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\fullscreen.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\fullscreen_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\fullscreen_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextfile.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextfile_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextfile_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextfile_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextmonth.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextmonth_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextmonth_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextyear.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextyear_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\nextyear_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\openfile.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\openfile_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\openfile_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\openfile_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\pauseplay.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\pauseplay_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\pauseplay_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\pauseplay_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\premonth.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\premonth_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevfile.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevfile_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevfile_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevfile_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevmonth.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevmonth_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevmonth_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevyear.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevyear_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\prevyear_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\preyear.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\searchfile.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\searchfile_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\searchfile_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\snapshot.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\snapshot_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\snapshot_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\snapshot_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\startplay.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\startplay_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\startplay_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\startplay_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\stopplay.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\stopplay_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\stopplay_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\stopplay_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\subspeed.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\subspeed_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\subspeed_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\subspeed_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\timeslider_btn.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\timeslider_line.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\volumeslider_btn.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\volumeslider_line.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomin.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomin_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomin_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomin_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\ZoomOut.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomout_dis.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomout_over.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\PlayerSkin\zoomout_push.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
Source: "{app}\Language\Chinese(cn).ini"; DestDir: "{app}\Language"; Flags: ignoreversion 
Source: "{app}\Language\Chinese(TW).ini"; DestDir: "{app}\Language"; Flags: ignoreversion 
Source: "{app}\Language\English(US).ini"; DestDir: "{app}\Language"; Flags: ignoreversion 
Source: "{tmp}\odS.CollectionImage.bmp"; DestDir: "{tmp}"; Flags: deleteafterinstall dontcopy 
Source: "{app}\Readme.txt"; DestDir: "{app}"; Flags: ignoreversion 
Source: "{app}\Process.TKE1.exe"; DestDir: "{app}"; 

[Registry]
Root: HKCR; Subkey: ".asf file\DefaultIcon"; ValueType: String; ValueData: "{app}\Player.exe"; Flags: uninsdeletekey 
Root: HKCR; Subkey: ".asf file\shell\open\command"; ValueType: String; ValueData: "{app}\Player.exe %1"; Tasks: "Associate"; Flags: uninsdeletekey 
Root: HKCR; Subkey: ".asf"; ValueType: String; ValueData: ".asf file"; Tasks: "Associate"; 

[Run]
Filename: "{app}\NVS CENTER.exe"; Description: "{cm:LaunchProgram,NVS CENTER}"; 
Filename: "{app}\Readme.txt"; Description: "{cm:ISL_CM_ViewReadme}"; 

[Icons]
Name: "{group}\NVS CENTER"; Filename: "{app}\NVS CENTER.exe"; WorkingDir: "{app}"; 
Name: "{group}\Player"; Filename: "{app}\Player.exe"; WorkingDir: "{app}"; 
Name: "{group}\{cm:UninstallProgram,NVS CENTER}"; Filename: "{uninstallexe}"; WorkingDir: "{app}"; 
Name: "{commondesktop}\NVS CENTER"; Filename: "{app}\NVS CENTER.exe"; WorkingDir: "{app}"; Tasks: "desktopicon"; 
Name: "{commondesktop}\Player"; Filename: "{app}\Player.exe"; WorkingDir: "{app}"; Tasks: "playericon"; 
Name: "{userappdata}\Microsoft\internet Explorer\Quick Launch\NVS CENTER"; Filename: "{app}\NVS CENTER.exe"; WorkingDir: "{app}"; Tasks: "quicklaunchicon"; 
Name: "{commonstartup}\NVS CENTER"; Filename: "{app}\NVS CENTER.exe"; WorkingDir: "{app}"; Tasks: "StartupWithWin"; 

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; 
Name: "playericon"; Description: "{cm:ISL_CM_CreatePlayerIcon}"; GroupDescription: "{cm:AdditionalIcons}"; 
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; 
Name: "startupwithwin"; Description: "{cm:ISL_CM_StartWithWindows}"; GroupDescription: "{cm:ISL_CM_AddStartupOption}"; 
Name: "associate"; Description: "{cm:ISL_CM_VideoPlayerAssociate}"; GroupDescription: "{cm:ISL_CM_FileAssociate}"; 

[CustomMessages]
english.NameAndVersion=%1 version %2
english.AdditionalIcons=Additional icons:
english.CreateDesktopIcon=Create a &desktop icon
english.CreateQuickLaunchIcon=Create a &Quick Launch icon
english.ProgramOnTheWeb=%1 on the Web
english.UninstallProgram=Uninstall %1
english.LaunchProgram=Launch %1
english.AssocFileExtension=&Associate %1 with the %2 file extension
english.AssocingFileExtension=Associating %1 with the %2 file extension...
english.ISL_CM_Uninstall=Uninstall
english.ISL_CM_Repair=Repair
english.ISL_CM_Failed=Failed
english.ISL_CM_ViewReadme=View Readme.txt
english.ISL_CM_StartWithWindows=&Startup with windows
english.ISL_CM_AddStartupOption=Add Startup Option:
english.ISL_CM_DetectInstalled=Detected This Programme Is Already Installed
english.ISL_CM_RetryInstall=Do you want to reinstall this program?
english.ISL_CM_BeingExitSetupWizard=Being Exit Setup Wizard
english.ISL_CM_TryKillProcessFailed=Fail to kill this follwing process : 
english.ISL_CM_WhetherKeepProfileAndLog=Whether or not to keep user profile and log? It is recommended that you keep them!
english.ISL_CM_Install=&Install
english.ISL_CM_BtnRepair=&Repair
english.ISL_CM_UninstallWithSpaces= Uninstall
english.ISL_CM_RepairWithSpaces= Repair
english.ISL_CM_Description=Description
english.ISL_CM_DescriptionWithSpaces=Description
english.ISL_CM_DestinationFolder=Destination Folder
english.ISL_CM_FileAssociate=File Associate
english.ISL_CM_PageNameLabelRepairing=Repairing
english.ISL_CM_SILangComboTitle=Software Interface Language:
english.ISL_CM_taskkillExeLost=taskkill.exe is lost in your windows OS, so cannot end the process
english.ISL_CM_SelectTasksInnerLabel_Install=Select the additional tasks while installing, to install, please click "Install".
english.ISL_CM_SelectTasksInnerLabel_Repair=Select the additional tasks while repairing, to rapair, please click "Repair".
english.ISL_CM_SelectDirInnerLabel=To select a different install folder, click Browse.To continue, please click Next.
english.ISL_CM_DescContent_Detectpage_Unins=Software params will be kept.
english.ISL_CM_UninsVerByInstallshield=Uninstall the version published by InstallShiled
english.ISL_CM_ComponentMySQL=MySQL Database
english.ISL_CM_CommentCoponentServer=Server:%nService for client and record%n%n
english.ISL_CM_CommentCoponentClient=Client:%nVideo view and manage devices%n%n
english.ISL_CM_CommentCoponentMySQL=MySQL Database:%nInstall MySQL service
english.ISL_CM_RegServer=Register server...
english.ISL_CM_SoftDefinePageA=Software Define
english.ISL_CM_SoftDefinePageB=How to define your software
english.ISL_CM_SoftDefinePageC=Please input these information, continue to click Next.
english.ISL_CM_SelectMySQLPort=MySQL Port:
chinese.NameAndVersion=%1 版本 %2
chinese.AdditionalIcons=附加图标：
chinese.CreateDesktopIcon=创建桌面图标(&D)
chinese.CreateQuickLaunchIcon=创建快速启动栏图标(&Q)
chinese.ProgramOnTheWeb=%1 网站
chinese.UninstallProgram=卸载 %1
chinese.LaunchProgram=运行 %1
chinese.AssocFileExtension=将 %1 与 %2 文件扩展名关联(&A)
chinese.AssocingFileExtension=正在将 %1 与 %2 文件扩展名关联...
chinese.ISL_CM_Uninstall=卸载
chinese.ISL_CM_Repair=修复
chinese.ISL_CM_Failed=失败
chinese.ISL_CM_ViewReadme=查阅 版本更新
chinese.ISL_CM_StartWithWindows=开机时自动启动(&S)
chinese.ISL_CM_AddStartupOption=添加启动选项：
chinese.ISL_CM_DetectInstalled=检测到此软件已被安装
chinese.ISL_CM_RetryInstall=您要尝试重新安装？
chinese.ISL_CM_BeingExitSetupWizard=即将退出安装向导
chinese.ISL_CM_TryKillProcessFailed=无法结束以下进程：
chinese.ISL_CM_WhetherKeepProfileAndLog=是否保留用户配置和日志？建议您予以保留！
chinese.ISL_CM_Install=安装(&I)
chinese.ISL_CM_BtnRepair=修复(&R)
chinese.ISL_CM_UninstallWithSpaces=卸   载
chinese.ISL_CM_RepairWithSpaces=修   复
chinese.ISL_CM_Description=描述
chinese.ISL_CM_DescriptionWithSpaces=描 述
chinese.ISL_CM_DestinationFolder=目标文件夹
chinese.ISL_CM_FileAssociate=文件关联：
chinese.ISL_CM_PageNameLabelRepairing=正在修复
chinese.ISL_CM_SILangComboTitle=软件界面语言：
chinese.ISL_CM_taskkillExeLost=您的Windows系统中taskkill.exe丢失，导致无法结束进程
chinese.ISL_CM_SelectTasksInnerLabel_Install=请选择安装期间要执行的附加任务，开始安装，请点击“安装”。
chinese.ISL_CM_SelectTasksInnerLabel_Repair=请选择修复期间要执行的附加任务，开始修复，请点击“修复”。
chinese.ISL_CM_SelectDirInnerLabel=想选择不同的安装目录，请单击“浏览”。继续，请单击“下一步”。
chinese.ISL_CM_UninsVerByInstallshield=卸载 由InstallShiled 发布的版本
chinese.ISL_CM_ComponentMySQL=MySQL 数据库
chinese.ISL_CM_CommentCoponentServer=服务器:%n为客户端提供服务和录像%n%n
chinese.ISL_CM_CommentCoponentClient=客户端:%n视频预览和管理设备%n%n
chinese.ISL_CM_CommentCoponentMySQL=MySQL数据库:%n安装MySQL客户服务
chinese.ISL_CM_RegServer=注册服务器...
chinese.ISL_CM_SoftDefinePageA=软件预设
chinese.ISL_CM_SoftDefinePageB=如何定制即将安装的软件？
chinese.ISL_CM_SoftDefinePageC=请指定下列信息，然后单击下一步。
chinese.ISL_CM_SelectMySQLPort=MySQL 使用的端口：
chinTra.NameAndVersion=%1 セ %2
chinTra.AdditionalIcons=瓜ボ:
chinTra.CreateDesktopIcon=ミ瓜ボ(&D)
chinTra.CreateQuickLaunchIcon=ミе硉币笆瓜ボ(&Q)
chinTra.ProgramOnTheWeb=%1 呼
chinTra.UninstallProgram=秆埃杆 %1
chinTra.LaunchProgram=币笆 %1
chinTra.AssocFileExtension=盢 %1 籔郎捌郎 %2 玻ネ闽羛(&A)
chinTra.AssocingFileExtension=タ盢 %1 籔郎捌郎 %2 玻ネ闽羛...
chinTra.ISL_CM_Uninstall=簿埃
chinTra.ISL_CM_Repair=確
chinTra.ISL_CM_Failed=ア毖
chinTra.ISL_CM_ViewReadme=綷弄 セ穝
chinTra.ISL_CM_StartWithWindows=秨诀笆币笆(&S)
chinTra.ISL_CM_AddStartupOption=睰币笆匡兜
chinTra.ISL_CM_DetectInstalled=浪代祘Α砆杆
chinTra.ISL_CM_RetryInstall=眤璶沽刚穝杆
chinTra.ISL_CM_BeingExitSetupWizard=盢癶杆祘Α
chinTra.ISL_CM_TryKillProcessFailed=礚猭挡秈祘
chinTra.ISL_CM_WhetherKeepProfileAndLog=琌玂痙ノめ皌竚㎝らв某眤ぉ玂痙
chinTra.ISL_CM_Install=杆(&I)
chinTra.ISL_CM_BtnRepair=確(&R)
chinTra.ISL_CM_UninstallWithSpaces=簿   埃
chinTra.ISL_CM_RepairWithSpaces=   確
chinTra.ISL_CM_Description=磞瓃
chinTra.ISL_CM_DescriptionWithSpaces=磞 瓃
chinTra.ISL_CM_DestinationFolder=ヘ戈Ж
chinTra.ISL_CM_FileAssociate=郎闽羛
chinTra.ISL_CM_PageNameLabelRepairing=タ確
chinTra.ISL_CM_SILangComboTitle=硁砰粂ē
chinTra.ISL_CM_taskkillExeLost=眤Windows╰参いtaskkill.exe框ア旧璓礚猭挡秈祘
chinTra.ISL_CM_SelectTasksInnerLabel_Install=叫匡拒杆戳丁璶磅︽秨﹍杆叫翴阑¨杆〃
chinTra.ISL_CM_SelectTasksInnerLabel_Repair=叫匡拒確戳丁璶磅︽秨﹍確叫翴阑¨確〃
chinTra.ISL_CM_SelectDirInnerLabel=稱匡拒ヘ戈Ж叫虫阑¨聅凝〃膥尿叫虫阑¨˙〃
chinTra.ISL_CM_UninsVerByInstallshield=簿埃 パInstallShiled 祇ガセ
chinTra.ISL_CM_ComponentMySQL=MySQL 计沮畐
chinTra.ISL_CM_CommentCoponentServer=狝叭竟:%nめ狠矗ㄑ狝叭㎝魁钩%n%n
chinTra.ISL_CM_CommentCoponentClient=め狠:%n跌繵箇凝㎝恨瞶砞称%n%n
chinTra.ISL_CM_CommentCoponentMySQL=MySQL计沮畐:%n杆MySQLめ狝叭
chinTra.ISL_CM_RegServer=猔狝叭竟...
chinTra.ISL_CM_SoftDefinePageA=硁ン箇砞
chinTra.ISL_CM_SoftDefinePageB=﹚盢杆硁ン
chinTra.ISL_CM_SoftDefinePageC=叫﹚獺礛虫阑˙
chinTra.ISL_CM_SelectMySQLPort=MySQL ㄏノ狠:
chinese.ISL_CM_DetectedIWCRunningSetupWizardCannotGo=检测到NVS CENTER正在运行！ 安装向导无法继续，请关闭该程序后点击“重试”，退出安装向导请点击“退出”。
chinese.ISL_CM_RepairWindowTitle=NVS CENTER 01.00.00.02 修复
chinese.ISL_CM_UninsWindowTitle=NVS CENTER 01.00.00.02 卸载
chinese.ISL_CM_CreatePlayerIcon=创建Player桌面图标(&P)
chinese.ISL_CM_VideoPlayerAssociate=将.asf文件关联到Player(&V)
chinese.ISL_CM_FinishedHeadingLabel_Install=安装完成
chinese.ISL_CM_FinishedHeadingLabel_Repair=修复完成
chinese.ISL_CM_DescContent_Detectpage_Unins=NVS CENTER 的配置参数将会保留。
chinese.ISL_CM_DescContent_Detectpage_Repair=覆盖安装此电脑上已存在的 NVS CENTER ，并更新程序到版本：01.00.00.02。
chinese.ISL_CM_TwoVerInstalled=当前电脑上存在两个不同版本的NVS CENTER
chinese.ISL_CM_OneVerInstalled=当前电脑上存在一个 NVS CENTER
chinese.ISL_CM_OneInstallshieldVerInstalled=当前电脑上存在一个由Installshield发布的 NVS CENTER，无法“修复”
chinese.ISL_CM_ErrorOnInsertCopyoutRegValue=尝试插入以下注册表项到 HKEY_LOCAL_MACHINE\Software\NVS CENTER_CopyOutInfo 时发生错误 ：
chinese.ISL_CM_AppAlreadyInstalledPlsSelectOperation=NVS CENTER已经安装，请选择如何操作
chinTra.ISL_CM_DetectedIWCRunningSetupWizardCannotGo=浪代NVS CENTERタ笲︽ 杆旧礚猭膥尿叫闽超赣祘翴阑¨刚〃癶杆旧叫翴阑¨〃
chinTra.ISL_CM_RepairWindowTitle=NVS CENTER 01.00.00.02 確
chinTra.ISL_CM_UninsWindowTitle=NVS CENTER 01.00.00.02 簿埃
chinTra.ISL_CM_CreatePlayerIcon=ミPlayer瓜ボ(&P)
chinTra.ISL_CM_VideoPlayerAssociate=盢.asf郎闽羛Player(&V)
chinTra.ISL_CM_FinishedHeadingLabel_Install=杆ЧΘ
chinTra.ISL_CM_FinishedHeadingLabel_Repair=確ЧΘ
chinTra.ISL_CM_DescContent_Detectpage_Unins=NVS CENTER 皌竚把计盢穦玂痙
chinTra.ISL_CM_DescContent_Detectpage_Repair=滦籠杆筿福 NVS CENTER 穝祘セ01.00.00.02
chinTra.ISL_CM_TwoVerInstalled=讽玡筿福ㄢぃセNVS CENTER
chinTra.ISL_CM_OneVerInstalled=讽玡筿福 NVS CENTER
chinTra.ISL_CM_OneInstallshieldVerInstalled=讽玡筿福パInstallshield祇ガ NVS CENTER礚猭¨確〃
chinTra.ISL_CM_ErrorOnInsertCopyoutRegValue=沽刚ミ祅魁龄 HKEY_LOCAL_MACHINE\Software\NVS CENTER_CopyOutInfo 祇ネ岿粇 
chinTra.ISL_CM_AppAlreadyInstalledPlsSelectOperation=NVS CENTER竒杆叫匡拒巨
english.ISL_CM_DetectedIWCRunningSetupWizardCannotGo=Detected NVS CENTER is running! Setup wizard cannot go,please end it and click Retry, or click Exit to exit.
english.ISL_CM_RepairWindowTitle=NVS CENTER 01.00.00.02 Repair
english.ISL_CM_UninsWindowTitle=NVS CENTER 01.00.00.02 Uninstall
english.ISL_CM_CreatePlayerIcon=Create Player desktop icon(&P)
english.ISL_CM_VideoPlayerAssociate=Associate .asf file to Player(&V)
english.ISL_CM_FinishedHeadingLabel_Install=Completing Setup
english.ISL_CM_FinishedHeadingLabel_Repair=Completing Repair
english.ISL_CM_DescContent_Detectpage_Repair=To replace NVS CENTER exists in your computer, and update it to version: 01.00.00.02.
english.ISL_CM_TwoVerInstalled=Two versions of NVS CENTER are installed
english.ISL_CM_OneVerInstalled=There is one NVS CENTER in this computer
english.ISL_CM_OneInstallshieldVerInstalled=There is one NVS CENTER published by Installshield in this computer, Repair function is disable
english.ISL_CM_ErrorOnInsertCopyoutRegValue=Error happened trying to insert this following registry value to HKEY_LOCAL_MACHINE\Software\NVS CENTER_CopyOutInfo, but setup could go on :
english.ISL_CM_AppAlreadyInstalledPlsSelectOperation=NVS CENTER is already installed, please select operation

[Languages]
; These files are stubs
; To achieve better results after recompilation, use the real language files
Name: "english"; MessagesFile: "embedded\english.isl"; LicenseFile: "embedded\englishLicense.txt"; 
Name: "chinese"; MessagesFile: "embedded\chinese.isl"; LicenseFile: "embedded\chineseLicense.txt"; 
Name: "chinTra"; MessagesFile: "embedded\chinTra.isl"; LicenseFile: "embedded\chinTraLicense.txt"; 
