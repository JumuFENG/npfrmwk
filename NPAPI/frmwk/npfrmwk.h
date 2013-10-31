// ���ļ���NPAPI�����������ļ�֮һ�����ļ����������ʹ�ã��޸ġ�
// �����Ա��ļ����κ������Ľ����飬����ϵ�ҡ������Ա��ļ������ļ���ص��ļ��������޸��뷢��һ�ݸ��ҡ�
// by: JumuFENG
// email: zhcbfly@qq.com
// blog:  http://blog.csdn.net/z6482

#ifndef npfrm_h_
#define npfrm_h_

#include "mozilla-config.h"

#include "npapi.h"
#include "npfunctions.h"
#include "npruntime.h"
#include "nptypes.h"
#include <string>
#include <sstream>

#ifdef _UNICODE
typedef std::wstring string;
#else
typedef std::string string;
#endif

#ifdef XP_WIN
#include "windows.h"
#include "windowsx.h"
#endif

#ifdef XP_UNIX
#include <stdio.h>
#endif

#ifdef XP_MAC
#include <Carbon/Carbon.h>
#endif

#ifndef ARRAY_LENGTH
#define ARRAY_LENGTH(a) (sizeof(a)/sizeof(a[0]))
#endif

#ifndef HIBYTE
#define HIBYTE(i) (i >> 8)
#endif

#ifndef LOBYTE
#define LOBYTE(i) (i & 0xff)
#endif
//////////////////////////////////////////////////////////////////////////
//����Dbgview.exe���Բ鿴���������Ϣ���ڲ������ʱ���������������
void inline NP_OUTPUT_DBG_STRING(string str)
{
#if defined(XP_WIN) && defined(_DEBUG)
	OutputDebugString(str.c_str());
#endif
}

//�Ժ������Ҫ����������Щ������֧�ָ����������������
template <typename T>
void NP_OUTPUT_DBG_STRING(T t)
{
#ifdef _DEBUG
	std::stringstream ss;
	ss<<t;
	NP_OUTPUT_DBG_STRING(ss.str());
#endif
}

template <typename T>
void NP_OUTPUT_DBG_HEX(T t)
{
#ifdef _DEBUG
	std::stringstream ss;
	ss<<t;
	std::string str = ss.str();
	std::stringstream hexss;
	int len = str.length();
	for (int i= 0;i<len;++i)
	{
		hexss<<std::hex<<(unsigned)str[i]<<" "<<std::endl;
	}
	NP_OUTPUT_DBG_STRING(hexss.str());
#endif
}

#endif // npfrm_h_
