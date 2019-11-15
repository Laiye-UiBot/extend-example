//����ļ�һ�㲻��Ҫ���޸ģ��뱣���������ݲ���

#include "luaclib.h"

#undef  EXTERN_DEF
#define EXTERN_DEF

#include "lua_api.h"
#include "lua_api_get.hpp"

#define _GENERATE_NAME(s)     luaopen_##s
#define GENERATE_NAME(s)      _GENERATE_NAME(s)

extern struct luaL_Reg module_name[];

DLLEXPORT int GENERATE_NAME(PROJECT_NAME)(lua_State *L) 
{     
	InitLuaApi();
	luaL_newlib(L, (const luaL_Reg *)module_name);
	return 1; 
}
