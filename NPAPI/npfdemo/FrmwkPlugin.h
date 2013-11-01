// 本文件是基于NPAPI插件开发框架开发插件的必要文件之一，开发插件主要修改本文件及对应的cpp文件，可自由免费使用，修改。
// 如您对本文件有任何意见或改进建议，请联系我。如您对本文件及本文件相关的文件进行了修改请发送一份给我。
// by: JumuFENG
// email: zhcbfly@qq.com
// blog:  http://blog.csdn.net/z6482
#pragma once
#include "npfrmwkbase.h"
class CFrmwkPlugin :
	public nsPluginInstanceBase
{
public:
	CFrmwkPlugin(NPP pNPInstance);
	~CFrmwkPlugin();

	NPBool init(NPWindow* pNPWindow); 
	void shut();
	NPBool isInitialized();

private:
	NPP m_pNPInstance;
	NPBool m_bInitialized;

};
