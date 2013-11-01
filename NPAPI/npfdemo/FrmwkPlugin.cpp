// 本文件是基于NPAPI插件开发框架开发插件的必要文件之一，开发插件主要修改本文件及对应的头文件，可自由免费使用，修改。
// 如您对本文件有任何意见或改进建议，请联系我。如您对本文件及本文件相关的文件进行了修改请发送一份给我。
// by: JumuFENG
// email: zhcbfly@qq.com
// blog:  http://blog.csdn.net/z6482

#include "FrmwkPlugin.h"

#define PLUGIN_VERSION     "1.0.0.1"
#define MIME_TYPES_HANDLED  "application/x-frmwk-demo"
#define PLUGIN_NAME         "Test Plug-in"
#define MIME_TYPES_DESCRIPTION  MIME_TYPES_HANDLED"::"PLUGIN_NAME
#define PLUGIN_DESCRIPTION  PLUGIN_NAME " (demo plugin for our own NPAPI framework)" 

#ifdef XP_UNIX
char* nsPluginInstanceBase::GetPluginVersion()
{
	return PLUGIN_VERSION;
}

NP_EXPORT(NPError) nsPluginInstanceBase::NS_GetValue(NPPVariable aVariable, void *aValue)
{
	switch (aVariable) {
	case NPPVpluginNameString:
		*((char**)aValue) = PLUGIN_NAME;
		break;
	case NPPVpluginDescriptionString:
		*((char**)aValue) = PLUGIN_DESCRIPTION;
		break;
	default:
		return NPERR_INVALID_PARAM;
		break;
	}
	return NPERR_NO_ERROR;
}
#endif

#if defined(XP_UNIX)
NP_EXPORT(const char*) nsPluginInstanceBase::GetMIMEDescription()
#elif defined(XP_WIN) || defined(XP_OS2)
const char* nsPluginInstanceBase::GetMIMEDescription()
#endif
{
	return MIME_TYPES_HANDLED;
}

NPError nsPluginInstanceBase::PluginInitialize()
{
	return NPERR_NO_ERROR;
}

void nsPluginInstanceBase::PluginShutdown()
{
}

nsPluginInstanceBase * nsPluginInstanceBase::NewPluginInstance(nsPluginCreateData * aCreateDataStruct)
{
	if(!aCreateDataStruct)
		return NULL;

	CFrmwkPlugin * plugin = new CFrmwkPlugin(aCreateDataStruct->instance);
	return plugin;
}

void nsPluginInstanceBase::DestroyPluginInstance(nsPluginInstanceBase * aPlugin)
{
	if(aPlugin)
		delete (CFrmwkPlugin *)aPlugin;
}


CFrmwkPlugin::CFrmwkPlugin(NPP npp):nsPluginInstanceBase(),
	m_pNPInstance(npp),
	m_bInitialized(FALSE)
{

}

NPBool CFrmwkPlugin::init(NPWindow* pNPWindow)
{
	m_bInitialized = TRUE;
	return TRUE;
}

void CFrmwkPlugin::shut()
{
	m_bInitialized = FALSE;
}

NPBool CFrmwkPlugin::isInitialized()
{
	return m_bInitialized;
}

CFrmwkPlugin::~CFrmwkPlugin()
{

}
