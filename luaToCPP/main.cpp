#include<iostream>  
using namespace std;
#include <stdio.h>

extern "C"{
#include "../luaLib/lua.h" 
#include "../luaLib/lualib.h"  
#include "../luaLib/lauxlib.h"
}



// 求平均，供lua脚本调用 
static int average(lua_State *L)	
{
	//返回栈中元素的个数  
	int n = lua_gettop(L);
	double sum = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (!lua_isnumber(L, i))
		{
			lua_pushstring(L, "Incorrect argument to 'average'");
			lua_error(L);
		}
		sum += lua_tonumber(L, i);
	}

	/* push the average */
	lua_pushnumber(L, sum / n);

	/* push the sum */
	lua_pushnumber(L, sum);

	/* return the number of results */
	return 2;
}

void luaCallCpp()
{
	printf("luaCallCpp test begin..\r\n");

	/* initialize Lua */
	lua_State *L = luaL_newstate();

	/* load Lua libraries */
	luaL_openlibs(L);

	/* register our function */
	lua_register(L, "average", average);

	/* run the script */
	luaL_dofile(L, "../luaScripts/luaCallCpp.lua");

	/* cleanup Lua */
	lua_close(L);
	getchar();
}

void cppCallLua()
{
	printf("cppCallLua test begin..\r\n");

	/* initialize Lua */
	lua_State *L = luaL_newstate();

	/* load Lua libraries */
	luaL_openlibs(L);

	//luaL_loadfile(L, "../luaScripts/cppCallLua.lua");
	//lua_pcall(L, 0, 0, 0);
	luaL_dofile(L, "../luaScripts/cppCallLua.lua");

	lua_getglobal(L, "printHelloWorld");
	lua_pcall(L, 0, 0, 0);

	lua_getglobal(L, "printHelloSomebody");
	lua_pushstring(L, "itol");
	lua_pcall(L, 1, 0, 0);	// 1参数0返回值
	
	lua_getglobal(L, "sortNum");
	lua_pushinteger(L, 3);
	lua_pushinteger(L, 5);
	lua_pcall(L, 2, 2, 0);	// 2参数2返回值 
	int n1 = lua_tointeger(L, -1);
	int n2 = lua_tointeger(L, -2);
	printf("n1 = %d; n2 = %d", n1, n2);

	/* cleanup Lua */
	lua_close(L);
	getchar();
}

void main()
{
	//luaCallCpp();
	cppCallLua();
}