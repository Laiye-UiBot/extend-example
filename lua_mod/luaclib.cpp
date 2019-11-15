#include "luaclib.h"
#include "lua_api.h"

//在编写您的插件之前，请将默认的插件名“LuaPlugin”改为其他名字。
//在Visual Studio左边栏选择名为“LuaPlugin”的项目，按F2键即可改名


//您可以在这里增加插件函数，函数类型必须是 static int (lua_State *L)
//下面有两个插件函数的使用范例


//您可以在lua中这样调用下面的两个函数(其中的LuaPlugin要换成自己的插件名字)
//package.cpath = "./plugin/?.so"  
//plugin = require "LuaPlugin"
//print plugin.add(123,456)
//print plugin.strcat("123","456")

//您也可以在脚本中直接调用下面的两个函数(其中的LuaPlugin要换成自己的插件名字)
//Import LuaPlugin
//TracePrint LuaPlugin.add(123,456)
//TracePrint LuaPlugin.strcat("abc","def")


static int add(lua_State *L)
{
	auto param1 = lua_tonumber(L, 1);		//取得第一个参数，类型为数值型
	auto param2 = lua_tonumber(L, 2);		//取得第二个参数，类型为数值型
	lua_pushnumber(L, param1 + param2);		//将两个参数之和作为返回值
	return 1;								//返回1表示有一个返回值
}

static int strcat(lua_State *L) 
{     
	auto param1 = lua_tostring(L, 1);		//取得第一个参数，类型为字符串型
	auto param2 = lua_tostring(L, 2);		//取得第一个参数，类型为字符串型

	//将两个字符串连接起来
	auto result_len = strlen(param1) + strlen(param2) + 1;
	char* result = new char[result_len];

	strcpy(result, param1);
	strcat(result, param2);

	//将连接结果作为返回值
	lua_pushstring(L, result);

	delete result;

	return 1;								//返回1表示有一个返回值
}

//每增加一个插件函数，请仿照示例，在此表中增加一行

struct luaL_Reg module_name[] = 
{
	{ "add", add },
	{ "strcat", strcat },
	{ NULL, NULL }
};