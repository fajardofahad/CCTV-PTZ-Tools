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
Source: "{app}\PlayerSkin\background - ����.bmp"; DestDir: "{app}\PlayerSkin"; Flags: ignoreversion 
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
chinese.NameAndVersion=%1 �汾 %2
chinese.AdditionalIcons=����ͼ�꣺
chinese.CreateDesktopIcon=��������ͼ��(&D)
chinese.CreateQuickLaunchIcon=��������������ͼ��(&Q)
chinese.ProgramOnTheWeb=%1 ��վ
chinese.UninstallProgram=ж�� %1
chinese.LaunchProgram=���� %1
chinese.AssocFileExtension=�� %1 �� %2 �ļ���չ������(&A)
chinese.AssocingFileExtension=���ڽ� %1 �� %2 �ļ���չ������...
chinese.ISL_CM_Uninstall=ж��
chinese.ISL_CM_Repair=�޸�
chinese.ISL_CM_Failed=ʧ��
chinese.ISL_CM_ViewReadme=���� �汾����
chinese.ISL_CM_StartWithWindows=����ʱ�Զ�����(&S)
chinese.ISL_CM_AddStartupOption=�������ѡ�
chinese.ISL_CM_DetectInstalled=��⵽������ѱ���װ
chinese.ISL_CM_RetryInstall=��Ҫ�������°�װ��
chinese.ISL_CM_BeingExitSetupWizard=�����˳���װ��
chinese.ISL_CM_TryKillProcessFailed=�޷��������½��̣�
chinese.ISL_CM_WhetherKeepProfileAndLog=�Ƿ����û����ú���־�����������Ա�����
chinese.ISL_CM_Install=��װ(&I)
chinese.ISL_CM_BtnRepair=�޸�(&R)
chinese.ISL_CM_UninstallWithSpaces=ж   ��
chinese.ISL_CM_RepairWithSpaces=��   ��
chinese.ISL_CM_Description=����
chinese.ISL_CM_DescriptionWithSpaces=�� ��
chinese.ISL_CM_DestinationFolder=Ŀ���ļ���
chinese.ISL_CM_FileAssociate=�ļ�������
chinese.ISL_CM_PageNameLabelRepairing=�����޸�
chinese.ISL_CM_SILangComboTitle=����������ԣ�
chinese.ISL_CM_taskkillExeLost=����Windowsϵͳ��taskkill.exe��ʧ�������޷���������
chinese.ISL_CM_SelectTasksInnerLabel_Install=��ѡ��װ�ڼ�Ҫִ�еĸ������񣬿�ʼ��װ����������װ����
chinese.ISL_CM_SelectTasksInnerLabel_Repair=��ѡ���޸��ڼ�Ҫִ�еĸ������񣬿�ʼ�޸����������޸�����
chinese.ISL_CM_SelectDirInnerLabel=��ѡ��ͬ�İ�װĿ¼���뵥������������������뵥������һ������
chinese.ISL_CM_UninsVerByInstallshield=ж�� ��InstallShiled �����İ汾
chinese.ISL_CM_ComponentMySQL=MySQL ���ݿ�
chinese.ISL_CM_CommentCoponentServer=������:%nΪ�ͻ����ṩ�����¼��%n%n
chinese.ISL_CM_CommentCoponentClient=�ͻ���:%n��ƵԤ���͹����豸%n%n
chinese.ISL_CM_CommentCoponentMySQL=MySQL���ݿ�:%n��װMySQL�ͻ�����
chinese.ISL_CM_RegServer=ע�������...
chinese.ISL_CM_SoftDefinePageA=���Ԥ��
chinese.ISL_CM_SoftDefinePageB=��ζ��Ƽ�����װ�������
chinese.ISL_CM_SoftDefinePageC=��ָ��������Ϣ��Ȼ�󵥻���һ����
chinese.ISL_CM_SelectMySQLPort=MySQL ʹ�õĶ˿ڣ�
chinTra.NameAndVersion=%1 ���� %2
chinTra.AdditionalIcons=���[�ϥ�:
chinTra.CreateDesktopIcon=�إ߮ୱ�ϥ�(&D)
chinTra.CreateQuickLaunchIcon=�إߧֳt�Ұʹϥ�(&Q)
chinTra.ProgramOnTheWeb=%1 ������
chinTra.UninstallProgram=�Ѱ��w�� %1
chinTra.LaunchProgram=�Ұ� %1
chinTra.AssocFileExtension=�N %1 �P�ɮװ��ɦW %2 �������p(&A)
chinTra.AssocingFileExtension=���b�N %1 �P�ɮװ��ɦW %2 �������p...
chinTra.ISL_CM_Uninstall=����
chinTra.ISL_CM_Repair=�״_
chinTra.ISL_CM_Failed=����
chinTra.ISL_CM_ViewReadme=�\Ū ������s
chinTra.ISL_CM_StartWithWindows=�}���ɦ۰ʱҰ�(&S)
chinTra.ISL_CM_AddStartupOption=�K�[�Ұʿﶵ�G
chinTra.ISL_CM_DetectInstalled=�˴��즹�{���w�Q�w��
chinTra.ISL_CM_RetryInstall=�z�n���խ��s�w�ˡH
chinTra.ISL_CM_BeingExitSetupWizard=�Y�N�h�X�w�˵{��
chinTra.ISL_CM_TryKillProcessFailed=�L�k�����H�U�i�{�G
chinTra.ISL_CM_WhetherKeepProfileAndLog=�O�_�O�d�Τ�t�m�M��ӡH��ĳ�z���H�O�d�I
chinTra.ISL_CM_Install=�w��(&I)
chinTra.ISL_CM_BtnRepair=�״_(&R)
chinTra.ISL_CM_UninstallWithSpaces=��   ��
chinTra.ISL_CM_RepairWithSpaces=��   �_
chinTra.ISL_CM_Description=�y�z
chinTra.ISL_CM_DescriptionWithSpaces=�y �z
chinTra.ISL_CM_DestinationFolder=�ت���Ƨ�
chinTra.ISL_CM_FileAssociate=�ɮ����p�G
chinTra.ISL_CM_PageNameLabelRepairing=���b�״_
chinTra.ISL_CM_SILangComboTitle=�n��ɭ��y���G
chinTra.ISL_CM_taskkillExeLost=�z��Windows�t�Τ�taskkill.exe�򥢡A�ɭP�L�k�����i�{
chinTra.ISL_CM_SelectTasksInnerLabel_Install=�п�ܦw�˴����n���檺���[�u�@�A�}�l�w�ˡA���I�����w�ˡ��C
chinTra.ISL_CM_SelectTasksInnerLabel_Repair=�п�ܭ״_�����n���檺���[�u�@�A�}�l�״_�A���I�����״_���C
chinTra.ISL_CM_SelectDirInnerLabel=�Q��ܥt�@�ӥت���Ƨ��A�г������s�����C�~��A�г������U�@�B���C
chinTra.ISL_CM_UninsVerByInstallshield=���� ��InstallShiled �o��������
chinTra.ISL_CM_ComponentMySQL=MySQL �ƾڮw
chinTra.ISL_CM_CommentCoponentServer=�A�Ⱦ�:%n���Ȥ�ݴ��ѪA�ȩM����%n%n
chinTra.ISL_CM_CommentCoponentClient=�Ȥ��:%n���W�w���M�޲z�]��%n%n
chinTra.ISL_CM_CommentCoponentMySQL=MySQL�ƾڮw:%n�w��MySQL�Ȥ�A��
chinTra.ISL_CM_RegServer=�`�U�A�Ⱦ�...
chinTra.ISL_CM_SoftDefinePageA=�n��w�]
chinTra.ISL_CM_SoftDefinePageB=�p��w��Y�N�w�˪��n��H
chinTra.ISL_CM_SoftDefinePageC=�Ы��w�U�C�H���A�M�Z�����U�@�B�C
chinTra.ISL_CM_SelectMySQLPort=MySQL �ϥΪ��ݤf:
chinese.ISL_CM_DetectedIWCRunningSetupWizardCannotGo=��⵽NVS CENTER�������У� ��װ���޷���������رոó�����������ԡ����˳���װ���������˳�����
chinese.ISL_CM_RepairWindowTitle=NVS CENTER 01.00.00.02 �޸�
chinese.ISL_CM_UninsWindowTitle=NVS CENTER 01.00.00.02 ж��
chinese.ISL_CM_CreatePlayerIcon=����Player����ͼ��(&P)
chinese.ISL_CM_VideoPlayerAssociate=��.asf�ļ�������Player(&V)
chinese.ISL_CM_FinishedHeadingLabel_Install=��װ���
chinese.ISL_CM_FinishedHeadingLabel_Repair=�޸����
chinese.ISL_CM_DescContent_Detectpage_Unins=NVS CENTER �����ò������ᱣ����
chinese.ISL_CM_DescContent_Detectpage_Repair=���ǰ�װ�˵������Ѵ��ڵ� NVS CENTER �������³��򵽰汾��01.00.00.02��
chinese.ISL_CM_TwoVerInstalled=��ǰ�����ϴ���������ͬ�汾��NVS CENTER
chinese.ISL_CM_OneVerInstalled=��ǰ�����ϴ���һ�� NVS CENTER
chinese.ISL_CM_OneInstallshieldVerInstalled=��ǰ�����ϴ���һ����Installshield������ NVS CENTER���޷����޸���
chinese.ISL_CM_ErrorOnInsertCopyoutRegValue=���Բ�������ע���� HKEY_LOCAL_MACHINE\Software\NVS CENTER_CopyOutInfo ʱ�������� ��
chinese.ISL_CM_AppAlreadyInstalledPlsSelectOperation=NVS CENTER�Ѿ���װ����ѡ����β���
chinTra.ISL_CM_DetectedIWCRunningSetupWizardCannotGo=�˴���NVS CENTER���b�B��I �w�˦V�ɵL�k�~��A�������ӵ{�ǦZ�I�������ա��A�h�X�w�˦V�ɽ��I�����������C
chinTra.ISL_CM_RepairWindowTitle=NVS CENTER 01.00.00.02 �״_
chinTra.ISL_CM_UninsWindowTitle=NVS CENTER 01.00.00.02 ����
chinTra.ISL_CM_CreatePlayerIcon=�إ�Player�ୱ�ϥ�(&P)
chinTra.ISL_CM_VideoPlayerAssociate=�N.asf�ɮ����p��Player(&V)
chinTra.ISL_CM_FinishedHeadingLabel_Install=�w�˧���
chinTra.ISL_CM_FinishedHeadingLabel_Repair=�״_����
chinTra.ISL_CM_DescContent_Detectpage_Unins=NVS CENTER ���t�m�ѼƱN�|�O�d�C
chinTra.ISL_CM_DescContent_Detectpage_Repair=�л\�w�˦��q���W�w�s�b�� NVS CENTER �A�}��s�{�Ǩ쪩���G01.00.00.02�C
chinTra.ISL_CM_TwoVerInstalled=��e�q���W�s�b��Ӥ��P������NVS CENTER
chinTra.ISL_CM_OneVerInstalled=��e�q���W�s�b�@�� NVS CENTER
chinTra.ISL_CM_OneInstallshieldVerInstalled=��e�q���W�s�b�@�ӥ�Installshield�o���� NVS CENTER�A�L�k���״_��
chinTra.ISL_CM_ErrorOnInsertCopyoutRegValue=���իإߥH�U�n����� HKEY_LOCAL_MACHINE\Software\NVS CENTER_CopyOutInfo �ɵo�Ϳ��~ �G
chinTra.ISL_CM_AppAlreadyInstalledPlsSelectOperation=NVS CENTER�w�g�w�ˡA�п�ܦp��ާ@
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
