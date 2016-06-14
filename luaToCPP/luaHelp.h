/****************************************************************************************
****************                      Lua5.1�е�API����                    **************
*****************************************************************************************

lua_State* luaL_newstate()
Lua�ű��ı���ִ�����໥�����ģ��ڲ�ͬ���߳���ִ�С�ͨ��luaL_newstate()������������һ�������������ָ������ lua_State��
�����������Lua Api�����ĵ��ö���Ҫ��ָ����Ϊ��һ����������ָ��ĳ���������
lua_State* L = luaL_newstate();

-------------------------------------------------------------------------------------- -
void  lua_close(lua_State *L)
����ָ�� Lua ״̬���е����ж�������������ռ���ص�Ԫ�����Ļ�����������ǣ��������ͷ�״̬����ʹ�õ����ж�̬�ڴ档
��һЩƽ̨�ϣ�����Բ��ص��������������Ϊ���������������ʱ�����е���Դ����Ȼ���ͷŵ��ˡ�
��һ���棬�������еĳ��򣬱���һ����̨�������һ�� web ����������������Ҫ���ǵ�ʱ���Ӧ���ͷŵ����״̬�����������Ա���״̬�����ŵĹ���
lua_close(L);
-------------------------------------------------------------------------------------- -
lua_State* lua_newthread(lua_State *L)

-------------------------------------------------------------------------------------- -
int  lua_gettop(lua_State *L)
ȡ��ջ�ĸ߶�
for (int i = 0; i < 10; ++i)
	lua_pushnumber(L, i);
printf("%d", lua_gettop(L));		--> 10
-------------------------------------------------------------------------------------- -
void  lua_settop(lua_State *L, int idx)
����ջ�ĸ߶ȣ����֮ǰ��ջ���������õĸ��ߣ���ô�߳�����Ԫ�ػᱻ��������֮ѹ��nil�������С��
���⣬Lua�ṩ��һ���꣬������ջ�е���n��Ԫ�أ�#define lua_pop(L, n) lua_settop(L, -(n)-1)
for (int i = 0; i < 10; ++i)
	lua_pushnumber(L, i);
lua_settop(L, 5)
printf("%d", lua_gettop(L));		--> 5
-------------------------------------------------------------------------------------- -
void  lua_pushvalue(lua_State *L, int idx)
��ָ��������ֵ�ĸ���ѹ��ջ
for (int i = 1; i <= 3; ++i)
	lua_pushnumber(i);
ջ��Ԫ�أ����������ϣ� 1 2 3
lua_pushvalue(L, 2)
ջ��Ԫ�أ����������ϣ� 1 2 3 2
-------------------------------------------------------------------------------------- -
void  lua_remove(lua_State *L, int idx)
ɾ��ָ�������ϵ�Ԫ�أ�������λ��֮�ϵ�����Ԫ�������Բ���ȱ
for (int i = 1; i <= 3; ++i)
	lua_pushnumber(i);
ջ��Ԫ�أ����������ϣ� 1 2 3
lua_remove(L, 2)
ջ��Ԫ�أ����������ϣ� 1 3
-------------------------------------------------------------------------------------- -
void  lua_insert(lua_State *L, int idx)
��ָ��λ���ϵ�����Ԫ���Կ���һ���ռ�۵Ŀռ䣬Ȼ��ջ��Ԫ���Ƶ���λ��
for (int i = 1; i <= 5; ++i)
	lua_pushnumber(i);
ջ��Ԫ�أ����������ϣ� 1 2 3 4 5
lua_insert(L, 3)
ջ��Ԫ�أ����������ϣ� 1 2 5 4 3
-------------------------------------------------------------------------------------- -
void  lua_replace(lua_State *L, int idx)
����ջ����ֵ��������ֵ���õ�ָ�������ϣ����������ƶ��κζ���
for (int i = 1; i <= 5; ++i)
	lua_pushnumber(i);
ջ��Ԫ�أ����������ϣ� 1 2 3 4 5
lua_replace(L, 3)
ջ��Ԫ�أ����������ϣ� 1 2 5 4
-------------------------------------------------------------------------------------- -
int  lua_checkstack(lua_State *L, int sz)
����ջ�Ŀ��óߴ磬ջ��Ĭ�ϳߴ���20���˺�����ȷ����ջ�������� sz ����λ��������ܰѶ�ջ��չ����Ӧ�ĳߴ磬�������� false ��
���������Զ������С��ջ�������ջ�Ѿ�����Ҫ�Ĵ��ˣ���ô�ͷ������ﲻ������仯��
lua_checkstack(L, 100)
-------------------------------------------------------------------------------------- -
void  lua_xmove(lua_State* from, lua_State* to, int n)

//access functions (stack -> C)
int  lua_isnumber(lua_State *L, int idx)
int  lua_isstring(lua_State *L, int idx)
int  lua_iscfunction(lua_State *L, int idx)
int  lua_isuserdata(lua_State *L, int idx)

int  lua_isnil(lua_State *L, int idx);
int  lua_isboolean(lua_State *L, int idx);
int  lua_istable(lua_State *L, int idx);
int  lua_isfunction(lua_State *L, int idx);
int  lua_islightuserdata(lua_State *L, int idx);
�����ĸ���������һ��ͬ����ԭ��int lua_is*(lua_State *L, int index)��������ѯĳֵ�Ƿ���ת����ĳ�����͵�ֵ�������������֣�lua_isstring�������档
lua_pushnumber(L, 994);
lua_pushstring(L, "hello,lua");
lua_isnumber(L, 1)-->true
lua_isnumber(L, 2)-->false
lua_isstring(L, 1)-->true
δ��
-------------------------------------------------------------------------------------- -
int  lua_type(lua_State *L, int idx)
�õ�һ��Ԫ�ص����ͣ��������ͣ�����ֵ�������б�֮һ��

#define LUA_TNONE  (-1)

#define LUA_TNIL  0
#define LUA_TBOOLEAN  1
#define LUA_TLIGHTUSERDATA 2
#define LUA_TNUMBER  3
#define LUA_TSTRING  4
#define LUA_TTABLE  5
#define LUA_TFUNCTION  6
#define LUA_TUSERDATA  7
#define LUA_TTHREAD  8

lua_pushnumber(L, 55);
lua_type(L, 1)-->LUA_TNUMBER
-------------------------------------------------------------------------------------- -
const char* lua_typename(lua_State *L, int tp)
��һ�����ͱ���ת����������
lua_typename(L, 1)-->boolean
lua_typename(L, 3)-->number
-------------------------------------------------------------------------------------- -

int  lua_equal(lua_State *L, int idx1, int idx2)
������� Lua �� == ���������壬���� index1 �� index2 �е�ֵ��ͬ�Ļ������� 1 �����򷵻� 0 ������κ�һ��������ЧҲ�᷵�� 0��
lua_pushstring(L, "this");
lua_pushboolean(L, 1);
lua_pushboolean(L, 1);
lua_equal(L, -2, -3)		-->0
lua_equal(L, -1, -2)		-->1
lua_equal(L, -1, -10)		-->0
-------------------------------------------------------------------------------------- -
int  lua_rawequal(lua_State *L, int idx1, int idx2)
int  lua_lessthan(lua_State *L, int idx1, int idx2)


-------------------------------------------------------------------------------------- -
lua_Number  lua_tonumber(lua_State *L, int idx)
lua_Integer  lua_tointeger(lua_State *L, int idx)
int  lua_toboolean(lua_State *L, int idx)
const char*  lua_tolstring(lua_State *L, int idx, size_t *len)
�����ĸ���������һ��ԭ��lua_to*(lua_State *L, int idx)�����ڴ�ջ��ȡһ��ֵ�����ָ����Ԫ�ز�������ȷ�����ͣ�������Щ����Ҳ���������⣬
����������£�����lua_toboolean��lua_tonumber��lua_tointeger�᷵��0�����������᷵��NULL��ͨ����ʹ��lua_is*������ֻ���ڵ�������֮
����Է��ؽ���Ƿ�ΪNULL�Ϳ����ˡ�
lua_pushnumber(L, 100)
lua_tonumber(L, 1)			-->100
lua_pushinteger(L, 200)
lua_tointeger(L, -1)		-->200		// ע��idxΪ����ʾ�����ջ�׵�ƫ������Ϊ����ʾ�����ջ����ƫ��������-1��ʾջ��Ԫ�أ�
lua_pushboolean(L, 0)
lua_toboolean(L, -1)		-->false
lua_pushstring(L, "hello,lua")
lua_tolstring(L, -1, &len)	-->hello, lua
ע��len�Ǵ�����������ʾ�ַ����ĳ��ȣ��������Դ˲���������NULL
-------------------------------------------------------------------------------------- -
size_t  lua_objlen(lua_State *L, int idx)
����ֵ�ĳ��ȣ�������Ͳ���ȷ������0
lua_pushstring(L, "hello,lua")
lua_objlen(L, 1)			-->9
-------------------------------------------------------------------------------------- -
lua_CFunction lua_tocfunction(lua_State *L, int idx)
void*  lua_touserdata(lua_State *L, int idx)
lua_State* lua_tothread(lua_State *L, int idx)
const void* lua_topointer(lua_State *L, int idx)



//push functions (C -> stack)
void  lua_pushnil(lua_State *L)
void  lua_pushnumber(lua_State *L, lua_Number n)
void  lua_pushinteger(lua_State *L, lua_Integer n)
void  lua_pushlstring(lua_State *L, const char* s, size_t l)
void  lua_pushstring(lua_State *L, const char *s)
const char* lua_pushvfstring(lua_State *L, const char *fmt, va_list argp)
const char* lua_pushfstring(lua_State *L, const char *fmt, ...)
void  lua_pushcclosure(lua_State *L, lua_CFunction fn, int n)
void  lua_pushboolean(lua_State *L, void *b)
void  lua_pushlightuserdata(lua_State *L, void *p)
int   lua_pushthread(lua_State *L)


void  lua_gettable(lua_State *L, int idx)
-------------------------------------------------------------------------------------- -
void  lua_getfield(lua_State *L, int idx, const char *k)
�� t[k] ֵѹ���ջ������� t ��ָ��Ч���� index ָ���ֵ���� Lua �У�����������ܴ�����Ӧ "index" �¼���Ԫ����
lua_getglobal(L,"tbl");			// tb1 is a table
lua_getfield(L,-1,"name");
str = lua_tostring(L,-1);		-->str = tb1.name
-------------------------------------------------------------------------------------- -
void  lua_rawget(lua_State *L, int idx)
void  lua_rawgeti(lua_State *L, int idx, int n)
-------------------------------------------------------------------------------------- -
void  lua_createtable(lua_State *L, int narr, int nrec)
����һ���µĿ� table ѹ���ջ������� table ����Ԥ���� narr ��Ԫ�ص�����ռ��Լ� nrec ��Ԫ�صķ�����ռ䡣
������ȷ֪��������Ҫ���ٸ�Ԫ��ʱ��Ԥ����ͷǳ����á�����㲻֪��������ʹ�ú��� lua_newtable��
������ȱ
-------------------------------------------------------------------------------------- -
void*  lua_newuserdata(lua_State *L, size_t sz)
int   lua_getmetatable(lua_State *L, int objindex)
-------------------------------------------------------------------------------------- -
void  lua_getfenv(lua_State *L, int idx)

��������ֵ�Ļ�����ѹ���ջ
-------------------------------------------------------------------------------------- -
void  lua_settable(lua_State *L, int idx);
void  lua_setfield(lua_State *L, int idx, const char *k)
void  lua_rawset(lua_State *L, int idx)
void  lua_rawseti(lua_State *L, int idx, int n)
int   lua_setmetatable(lua_State *L, int objindex)
int   lua_setfenv(lua_State *L, int idx)


//'load' and 'call' functions (load and run lua code)
void  lua_call(lua_State *L, int nargs, int nresults);	//nargs���������� nresults����ֵ����
int   lua_pcall(lua_State *L, int nargs, int nresults, int errfunc)	//nargs���������� nresults����ֵ������ errfunc������ʱ�Ĵ���
-------------------------------------------------------------------------------------- -
int   lua_cpcall(lua_State *L, lua_CFunction func, void *ud)
�Ա���ģʽ���� C ���� func �� func ֻ���ܴӶ�ջ���õ�һ�����������ǰ����� ud �� light userdata�����д���ʱ�� lua_cpcall ���غ� lua_pcall ��ͬ�Ĵ�����룬����ջ�����´�����󣻷����������㣬�������޸Ķ�ջ�����д� func �ڷ��ص�ֵ���ᱻ�ӵ���
������ȱ
-------------------------------------------------------------------------------------- -
int   lua_load(lua_State *L, lua_Reader reader, void *dt, const char *chunkname);
-------------------------------------------------------------------------------------- -
int   lua_dump(lua_State *L, lua_Writer writer, void *data);
�Ѻ��� dump �ɶ����� chunk ����������ջ���� Lua ������������Ȼ���������Ķ����� chunk ��
���� dump �����Ķ������ٴμ��أ����صĽ�����൱��ԭ���ĺ�����
�����ڲ��� chunk ��ʱ��lua_dump ͨ�����ú��� writer ���μ� lua_Writer����д�����ݣ������ data �����ᱻ���� writer ��
���һ����д����(writer) ����ֵ����Ϊ��������ķ���ֵ���أ� 0 ��ʾû�д���
������������ Lua ���ص�����ջ��
������ȱ
-------------------------------------------------------------------------------------- -
int   lua_yield(lua_State *L, int nresults)
int   lua_resume(lua_State *L, int narg)
int   lua_status(lua_State *L)

-------------------------------------------------------------------------------------- -
int   lua_gc(lua_State *L, int what, int data)

���������ռ����� ���������������� what �����ֲ�ͬ������
* LUA_GCSTOP: ֹͣ�����ռ�����
* LUA_GCRESTART : ���������ռ�����
* LUA_GCCOLLECT : ����һ�������������ռ�ѭ����
* LUA_GCCOUNT : ���� Lua ʹ�õ��ڴ��������� K �ֽ�Ϊ��λ����
* LUA_GCCOUNTB : ���ص�ǰ�ڴ�ʹ�������� 1024 ��������
* LUA_GCSTEP : ����һ�����������ռ��������� data ���ƣ�Խ���ֵ��ζ��Խ�ಽ����������庬�壨�������ֱ�ʾ�˶��٣���δ��׼����
			   �����������������������ʵ���ԵĲ��� data ��ֵ�������һ��������һ�������ռ����ڣ����ط��� 1 ��
* LUA_GCSETPAUSE : �� data / 100 ����Ϊ garbage - collector pause ����ֵ������������ǰ��ֵ��
* LUA_GCSETSTEPMUL : �� arg / 100 ���ó� step multiplier ������������ǰ��ֵ��
-------------------------------------------------------------------------------------- -
int   lua_error(lua_State *L)
����һ�� Lua ���󡣴�����Ϣ��ʵ���Ͽ������κ����͵� Lua ֵ�����뱻����ջ���������������һ�γ���ת������������ٷ��ء����μ� luaL_error����
lua_pushstring(L, "one error");
lua_error(L);
printf("%s", "�����Ѿ�ִ�в�����");
-------------------------------------------------------------------------------------- -
int   lua_next(lua_State *L, int idx)
-------------------------------------------------------------------------------------- -
void  lua_concat(lua_State *L, int n)
����ջ���� n ��ֵ��Ȼ����Щֵ��ջ�����ѽ������ջ������� n Ϊ 1 ���������һ���ַ�������ջ�ϣ���������ʲô������������� n Ϊ 0 �������һ���մ��� 
�������� Lua �д���������ɣ�������԰������������ӵ��������ӣ���������������ʾ��
lua_pushstring(L, "this");
lua_pushboolean(L, 1);
lua_pushnumber(L, 9989);
lua_pushnumber(L, 1111);
lua_pushboolean(L, 0);
lua_pushstring(L, "���춼��С����");
lua_pushnumber(L, 1986);
lua_pushstring(L, "onebyone");		-->'this' 'true' '9989' '1111' 'false' '���춼��С����' '1986' 'onebyone'
lua_concat(L, 3);					-->'this' 'true' '9989' '1111' 'false' '���춼��С����1986onebyone'
-------------------------------------------------------------------------------------- -
lua_Alloc lua_getallocf(lua_State *L, void **ud)
���ظ���״̬�����ڴ��������������� ud ���� NULL ��Lua �ѵ��� lua_newstate ʱ������Ǹ�ָ����� *ud ��
-------------------------------------------------------------------------------------- -
void  lua_setallocf(lua_State *L, lua_Alloc f, void *ud)


//Functions to be called by the debuger in specific events
int   lua_getstack(lua_State *L, int level, lua_Debug *ar)
int   lua_getinfo(lua_State *L, const char *what, lua_Debug *ar)
const char* lua_getlocal(lua_State *L, const lua_Debug *ar, int n)
const char* lua_setlocal(lua_State *L, const lua_Debug *ar, int n)
const char* lua_getupvalue(lua_State *L, int funcindex, int n)
const char* lua_setupvalue(lua_State *L, int funcindex, int n)
int   lua_sethook(lua_State *L, lua_Hook func, int mask, int count);
lua_Hook lua_gethook(lua_State *L)
int   lua_gethookmask(lua_State *L)
int   lua_gethookcount(lua_State *L)

*******************************************************************************************/