// ���ļ��ǻ���NPAPI���������ܿ�������ı�Ҫ�ļ�֮һ�����������Ҫ�޸ı��ļ�����Ӧ��cpp�ļ������������ʹ�ã��޸ġ�
// �����Ա��ļ����κ������Ľ����飬����ϵ�ҡ������Ա��ļ������ļ���ص��ļ��������޸��뷢��һ�ݸ��ҡ�
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
