// ���ļ��ǻ���NPAPI���������ܿ�������ı�Ҫ�ļ�֮һ�����������Ҫ�޸ı��ļ�����Ӧ��cpp�ļ������������ʹ�ã��޸ġ�
// �����Ա��ļ����κ������Ľ����飬����ϵ�ҡ������Ա��ļ������ļ���ص��ļ��������޸��뷢��һ�ݸ��ҡ�
// by: JumuFENG
// email: zhcbfly@qq.com
// blog:  http://blog.csdn.net/z6482
#pragma once
#include "npfrmwkbase.h"
#include <string>
//#include "boost/lexical_cast.hpp"
using namespace std;

class CPlugin :
	public nsPluginInstanceBase
{
public:
	CPlugin(NPP pNPInstance);
	~CPlugin();

	NPBool init(NPWindow* pNPWindow); 
	void shut();
	NPBool isInitialized();
#ifdef ENABLE_SCRIPT_OBJECT
	NPObject* m_pScriptableObject;
	NPObject* m_jsObj;
	//for scriptable plugins
	
    virtual NPObject *GetScriptableObject();
#endif //ENABLE_SCRIPT_OBJECT

private:
	NPP m_pNPInstance;
	NPBool m_bInitialized;

};

#ifdef ENABLE_SCRIPT_OBJECT
class CScriptObject:
	public nsScriptObjectBase
{
private:
	int m_vfoo;
	std::string m_str;

public:
	static NPIdentifier bar_id;
	static NPIdentifier func_id;
	static NPObject *sWindowObj;
	static NPIdentifier foo_id;
	static NPIdentifier str_id;
	static NPIdentifier i2ifunc_id;
	static NPIdentifier s2sfunc_id;
	static NPIdentifier jsfunc_id;

	CScriptObject(NPP npp):nsScriptObjectBase(npp),m_vfoo(0),m_str(""){}
	~CScriptObject(){};

	virtual bool HasProperty(NPIdentifier name);
	virtual bool HasMethod(NPIdentifier name);
	virtual bool GetProperty(NPIdentifier name, NPVariant *result);
	virtual bool SetProperty(NPIdentifier name, const NPVariant *value);
	virtual bool Invoke(NPIdentifier name, const NPVariant *args, uint32_t argCount, NPVariant *result);
	virtual bool InvokeDefault(const NPVariant *args, uint32_t argCount, NPVariant *result);
};
#endif //ENABLE_SCRIPT_OBJECT
