#ifndef __LAUCAMSEARCH_H__
#define __LAUCAMSEARCH_H__

#define CAMSEAR_APIIMPORT  extern "C"__declspec(dllexport)

//initialization, call this first
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Startup();
//clear up,call this when destroyed
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Cleanup();
/*Search camera.This function use multicast to search camera.
Parameters:
m_wait:   wait time,millisecond. 
notify£º  callback function when find a camera;
   Parameters:
   devtype:     device type£¬1£ºEncoder£¬2£ºDecoder;
   m_sername:   Server name;
   m_mac:       Mac address.A mark to find unique camera.Can not be changed.
   m_url:       IP  Address;
   m_webport£º  WEB port£»
   m_localport£ºData port;
   m_submask:   netmask;
   m_getway:    gateway;
   m_multiip£º  multicast address;
   m_dns:       DNS address;
   m_multiport: multicast port;
   channel:     channel number;
m_multiport:multicast port 
localurl: local address to bind. NULL is any.    
*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Searchcam(int m_wait,
					void(WINAPI *notify)(int devtype,char *m_sername,char *m_url,BYTE m_mac[6],WORD m_webport,WORD m_localport,
					char *m_submask,char *m_getway,char *m_multiip,char *m_dns,WORD m_multiport,int channel),char *localurl = NULL);

/*Search camera.This function use broadcast to search camera.not used now*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_Searchcam_old(int m_wait,
					void(WINAPI *notify)(int devtype,char *m_sername,char *m_url,BYTE m_mac[6],WORD m_webport,WORD m_localport,
					char *m_submask,char *m_getway,char *m_multiip,char *m_dns,WORD m_multiport,int channel),char *localurl = NULL);

/*
Set camera parameters:
m_mac:      MAC address,can not be changed,used to find unique camera.
m_sername:  server name
m_url:      IP address
m_submask:  netmask
m_getway:   gateway
m_multiip£º multicast address
m_dns:      DNS address
m_webport:  web port 
m_localport:data port
m_multiport:multicast port
localurl:   local address to bind. NULL is any.
*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_SearchSeturl(BYTE m_mac[6],char *m_sername,
													  char *m_url,char *m_submask,char *m_getway,char *m_multiip,char *m_dns,
													  WORD m_webport,WORD m_localport,WORD m_multiport,char *localurl = NULL);

/*
Reset server.
m_mac:      MAC address,can not be changed,used to find unique camera.
localurl:   local address to bind. NULL is any.
*/
CAMSEAR_APIIMPORT BOOL __stdcall CAMSEAR_SearchReset(BYTE m_mac[6],char *localurl = NULL);

/*Get Ethernet information
notify:  local ip address notify;
localip: local ip address;
*/
CAMSEAR_APIIMPORT int  __stdcall GetEthernetInfo(void(WINAPI *notify)(char *localip));
#endif//__LAUCAMSEARCH_H__
