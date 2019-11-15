#include "luaclib.h"
#include "lua_api.h"

//�ڱ�д���Ĳ��֮ǰ���뽫Ĭ�ϵĲ������LuaPlugin����Ϊ�������֡�
//��Visual Studio�����ѡ����Ϊ��LuaPlugin������Ŀ����F2�����ɸ���


//���������������Ӳ���������������ͱ����� static int (lua_State *L)
//�������������������ʹ�÷���


//��������lua�����������������������(���е�LuaPluginҪ�����Լ��Ĳ������)
//package.cpath = "./plugin/?.so"  
//plugin = require "LuaPlugin"
//print plugin.add(123,456)
//print plugin.strcat("123","456")

//��Ҳ�����ڽű���ֱ�ӵ����������������(���е�LuaPluginҪ�����Լ��Ĳ������)
//Import LuaPlugin
//TracePrint LuaPlugin.add(123,456)
//TracePrint LuaPlugin.strcat("abc","def")


static int add(lua_State *L)
{
	auto param1 = lua_tonumber(L, 1);		//ȡ�õ�һ������������Ϊ��ֵ��
	auto param2 = lua_tonumber(L, 2);		//ȡ�õڶ�������������Ϊ��ֵ��
	lua_pushnumber(L, param1 + param2);		//����������֮����Ϊ����ֵ
	return 1;								//����1��ʾ��һ������ֵ
}

static int strcat(lua_State *L) 
{     
	auto param1 = lua_tostring(L, 1);		//ȡ�õ�һ������������Ϊ�ַ�����
	auto param2 = lua_tostring(L, 2);		//ȡ�õ�һ������������Ϊ�ַ�����

	//�������ַ�����������
	auto result_len = strlen(param1) + strlen(param2) + 1;
	char* result = new char[result_len];

	strcpy(result, param1);
	strcat(result, param2);

	//�����ӽ����Ϊ����ֵ
	lua_pushstring(L, result);

	delete result;

	return 1;								//����1��ʾ��һ������ֵ
}

//ÿ����һ����������������ʾ�����ڴ˱�������һ��

struct luaL_Reg module_name[] = 
{
	{ "add", add },
	{ "strcat", strcat },
	{ NULL, NULL }
};