// 本文件是NPAPI插件开发框架文件之一，本文件可自由免费使用，修改。
// 如您对本文件有任何意见或改进建议，请联系我。如您对本文件及本文件相关的文件进行了修改请发送一份给我。
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
//借助Dbgview.exe可以查看调试输出信息，在插件加载时崩溃的情况下有用
void inline NP_OUTPUT_DBG_STRING(string str)
{
#if defined(XP_WIN) && defined(_DEBUG)
	OutputDebugString(str.c_str());
#endif
}

//以后根据需要可以重载这些函数以支持更多变量及变量类型
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
