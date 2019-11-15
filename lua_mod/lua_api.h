//This file is AUTOMATIC generated from LUA source code
//Do NOT manually modify!

#include <stdarg.h>
#include <stdio.h>
#include "luaconf.h"
/*
** $Id: lua.h,v 1.332 2016/12/22 15:51:20 roberto Exp $
** Lua - A Scripting Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
*/


#ifndef lua_h
#define lua_h





#define LUA_VERSION_MAJOR	"5"
#define LUA_VERSION_MINOR	"3"
#define LUA_VERSION_NUM		503
#define LUA_VERSION_RELEASE	"4"

#define LUA_VERSION	"Lua " LUA_VERSION_MAJOR "." LUA_VERSION_MINOR
#define LUA_RELEASE	LUA_VERSION "." LUA_VERSION_RELEASE
#define LUA_COPYRIGHT	LUA_RELEASE "  Copyright (C) 1994-2017 Lua.org, PUC-Rio"
#define LUA_AUTHORS	"R. Ierusalimschy, L. H. de Figueiredo, W. Celes"


/* mark for precompiled code ('<esc>Lua') */
#define LUA_SIGNATURE	"\x1bLua"

/* option for multiple returns in 'lua_pcall' and 'lua_call' */
#define LUA_MULTRET	(-1)


/*
** Pseudo-indices
** (-LUAI_MAXSTACK is the minimum valid index; we keep some free empty
** space after that to help overflow detection)
*/
#define LUA_REGISTRYINDEX	(-LUAI_MAXSTACK - 1000)
#define lua_upvalueindex(i)	(LUA_REGISTRYINDEX - (i))


/* thread status */
#define LUA_OK		0
#define LUA_YIELD	1
#define LUA_ERRRUN	2
#define LUA_ERRSYNTAX	3
#define LUA_ERRMEM	4
#define LUA_ERRGCMM	5
#define LUA_ERRERR	6


typedef struct lua_State lua_State;


/*
** basic types
*/
#define LUA_TNONE		(-1)

#define LUA_TNIL		0
#define LUA_TBOOLEAN		1
#define LUA_TLIGHTUSERDATA	2
#define LUA_TNUMBER		3
#define LUA_TSTRING		4
#define LUA_TTABLE		5
#define LUA_TFUNCTION		6
#define LUA_TUSERDATA		7
#define LUA_TTHREAD		8

#define LUA_NUMTAGS		9



/* minimum Lua stack available to a C function */
#define LUA_MINSTACK	20


/* predefined values in the registry */
#define LUA_RIDX_MAINTHREAD	1
#define LUA_RIDX_GLOBALS	2
#define LUA_RIDX_LAST		LUA_RIDX_GLOBALS


/* type of numbers in Lua */
typedef LUA_NUMBER lua_Number;


/* type for integer functions */
typedef LUA_INTEGER lua_Integer;

/* unsigned integer type */
typedef LUA_UNSIGNED lua_Unsigned;

/* type for continuation-function contexts */
typedef LUA_KCONTEXT lua_KContext;


/*
** Type for C functions registered with Lua
*/
typedef int (*lua_CFunction) (lua_State *L);

/*
** Type for continuation functions
*/
typedef int (*lua_KFunction) (lua_State *L, int status, lua_KContext ctx);


/*
** Type for functions that read/write blocks when loading/dumping Lua chunks
*/
typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer) (lua_State *L, const void *p, size_t sz, void *ud);


/*
** Type for memory-allocation functions
*/
typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);



/*
** generic extra include file
*/
#if defined(LUA_USER_H)
#endif


/*
** RCS ident string
*/
extern const char lua_ident[];


/*
** state manipulation
*/
EXTERN_DEF lua_State *(*lua_newstate) (lua_Alloc f, void *ud);
EXTERN_DEF void       (*lua_close) (lua_State *L);
EXTERN_DEF lua_State *(*lua_newthread) (lua_State *L);

EXTERN_DEF lua_CFunction (*lua_atpanic) (lua_State *L, lua_CFunction panicf);


EXTERN_DEF const lua_Number *(*lua_version) (lua_State *L);


/*
** basic stack manipulation
*/
EXTERN_DEF int   (*lua_absindex) (lua_State *L, int idx);
EXTERN_DEF int   (*lua_gettop) (lua_State *L);
EXTERN_DEF void  (*lua_settop) (lua_State *L, int idx);
EXTERN_DEF void  (*lua_pushvalue) (lua_State *L, int idx);
EXTERN_DEF void  (*lua_rotate) (lua_State *L, int idx, int n);
EXTERN_DEF void  (*lua_copy) (lua_State *L, int fromidx, int toidx);
EXTERN_DEF int   (*lua_checkstack) (lua_State *L, int n);

EXTERN_DEF void  (*lua_xmove) (lua_State *from, lua_State *to, int n);


/*
** access functions (stack -> C)
*/

EXTERN_DEF int             (*lua_isnumber) (lua_State *L, int idx);
EXTERN_DEF int             (*lua_isstring) (lua_State *L, int idx);
EXTERN_DEF int             (*lua_iscfunction) (lua_State *L, int idx);
EXTERN_DEF int             (*lua_isinteger) (lua_State *L, int idx);
EXTERN_DEF int             (*lua_isuserdata) (lua_State *L, int idx);
EXTERN_DEF int             (*lua_type) (lua_State *L, int idx);
EXTERN_DEF const char     *(*lua_typename) (lua_State *L, int tp);

EXTERN_DEF lua_Number      (*lua_tonumberx) (lua_State *L, int idx, int *isnum);
EXTERN_DEF lua_Integer     (*lua_tointegerx) (lua_State *L, int idx, int *isnum);
EXTERN_DEF int             (*lua_toboolean) (lua_State *L, int idx);
EXTERN_DEF const char     *(*lua_tolstring) (lua_State *L, int idx, size_t *len);
EXTERN_DEF size_t          (*lua_rawlen) (lua_State *L, int idx);
EXTERN_DEF lua_CFunction   (*lua_tocfunction) (lua_State *L, int idx);
EXTERN_DEF void	       *(*lua_touserdata) (lua_State *L, int idx);
EXTERN_DEF lua_State      *(*lua_tothread) (lua_State *L, int idx);
EXTERN_DEF const void     *(*lua_topointer) (lua_State *L, int idx);


/*
** Comparison and arithmetic functions
*/

#define LUA_OPADD	0	/* ORDER TM, ORDER OP */
#define LUA_OPSUB	1
#define LUA_OPMUL	2
#define LUA_OPMOD	3
#define LUA_OPPOW	4
#define LUA_OPDIV	5
#define LUA_OPIDIV	6
#define LUA_OPBAND	7
#define LUA_OPBOR	8
#define LUA_OPBXOR	9
#define LUA_OPSHL	10
#define LUA_OPSHR	11
#define LUA_OPUNM	12
#define LUA_OPBNOT	13

EXTERN_DEF void  (*lua_arith) (lua_State *L, int op);

#define LUA_OPEQ	0
#define LUA_OPLT	1
#define LUA_OPLE	2

EXTERN_DEF int   (*lua_rawequal) (lua_State *L, int idx1, int idx2);
EXTERN_DEF int   (*lua_compare) (lua_State *L, int idx1, int idx2, int op);


/*
** push functions (C -> stack)
*/
EXTERN_DEF void        (*lua_pushnil) (lua_State *L);
EXTERN_DEF void        (*lua_pushnumber) (lua_State *L, lua_Number n);
EXTERN_DEF void        (*lua_pushinteger) (lua_State *L, lua_Integer n);
EXTERN_DEF const char *(*lua_pushlstring) (lua_State *L, const char *s, size_t len);
EXTERN_DEF const char *(*lua_pushstring) (lua_State *L, const char *s);
EXTERN_DEF const char *(*lua_pushvfstring) (lua_State *L, const char *fmt,
                                                      va_list argp);
EXTERN_DEF const char *(*lua_pushfstring) (lua_State *L, const char *fmt, ...);
EXTERN_DEF void  (*lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
EXTERN_DEF void  (*lua_pushboolean) (lua_State *L, int b);
EXTERN_DEF void  (*lua_pushlightuserdata) (lua_State *L, void *p);
EXTERN_DEF int   (*lua_pushthread) (lua_State *L);


/*
** get functions (Lua -> stack)
*/
EXTERN_DEF int (*lua_getglobal) (lua_State *L, const char *name);
EXTERN_DEF int (*lua_gettable) (lua_State *L, int idx);
EXTERN_DEF int (*lua_getfield) (lua_State *L, int idx, const char *k);
EXTERN_DEF int (*lua_geti) (lua_State *L, int idx, lua_Integer n);
EXTERN_DEF int (*lua_rawget) (lua_State *L, int idx);
EXTERN_DEF int (*lua_rawgeti) (lua_State *L, int idx, lua_Integer n);
EXTERN_DEF int (*lua_rawgetp) (lua_State *L, int idx, const void *p);

EXTERN_DEF void  (*lua_createtable) (lua_State *L, int narr, int nrec);
EXTERN_DEF void *(*lua_newuserdata) (lua_State *L, size_t sz);
EXTERN_DEF int   (*lua_getmetatable) (lua_State *L, int objindex);
EXTERN_DEF int  (*lua_getuservalue) (lua_State *L, int idx);


/*
** set functions (stack -> Lua)
*/
EXTERN_DEF void  (*lua_setglobal) (lua_State *L, const char *name);
EXTERN_DEF void  (*lua_settable) (lua_State *L, int idx);
EXTERN_DEF void  (*lua_setfield) (lua_State *L, int idx, const char *k);
EXTERN_DEF void  (*lua_seti) (lua_State *L, int idx, lua_Integer n);
EXTERN_DEF void  (*lua_rawset) (lua_State *L, int idx);
EXTERN_DEF void  (*lua_rawseti) (lua_State *L, int idx, lua_Integer n);
EXTERN_DEF void  (*lua_rawsetp) (lua_State *L, int idx, const void *p);
EXTERN_DEF int   (*lua_setmetatable) (lua_State *L, int objindex);
EXTERN_DEF void  (*lua_setuservalue) (lua_State *L, int idx);


/*
** 'load' and 'call' functions (load and run Lua code)
*/
EXTERN_DEF void  (*lua_callk) (lua_State *L, int nargs, int nresults,
                           lua_KContext ctx, lua_KFunction k);
#define lua_call(L,n,r)		lua_callk(L, (n), (r), 0, NULL)

EXTERN_DEF int   (*lua_pcallk) (lua_State *L, int nargs, int nresults, int errfunc,
                            lua_KContext ctx, lua_KFunction k);
#define lua_pcall(L,n,r,f)	lua_pcallk(L, (n), (r), (f), 0, NULL)

EXTERN_DEF int   (*lua_load) (lua_State *L, lua_Reader reader, void *dt,
                          const char *chunkname, const char *mode);

EXTERN_DEF int (*lua_dump) (lua_State *L, lua_Writer writer, void *data, int strip);


/*
** coroutine functions
*/
EXTERN_DEF int  (*lua_yieldk)     (lua_State *L, int nresults, lua_KContext ctx,
                               lua_KFunction k);
EXTERN_DEF int  (*lua_resume)     (lua_State *L, lua_State *from, int narg);
EXTERN_DEF int  (*lua_status)     (lua_State *L);
EXTERN_DEF int (*lua_isyieldable) (lua_State *L);

#define lua_yield(L,n)		lua_yieldk(L, (n), 0, NULL)


/*
** garbage-collection function and options
*/

#define LUA_GCSTOP		0
#define LUA_GCRESTART		1
#define LUA_GCCOLLECT		2
#define LUA_GCCOUNT		3
#define LUA_GCCOUNTB		4
#define LUA_GCSTEP		5
#define LUA_GCSETPAUSE		6
#define LUA_GCSETSTEPMUL	7
#define LUA_GCISRUNNING		9

EXTERN_DEF int (*lua_gc) (lua_State *L, int what, int data);


/*
** miscellaneous functions
*/

EXTERN_DEF int   (*lua_error) (lua_State *L);

EXTERN_DEF int   (*lua_next) (lua_State *L, int idx);

EXTERN_DEF void  (*lua_concat) (lua_State *L, int n);
EXTERN_DEF void  (*lua_len)    (lua_State *L, int idx);

EXTERN_DEF size_t   (*lua_stringtonumber) (lua_State *L, const char *s);

EXTERN_DEF lua_Alloc (*lua_getallocf) (lua_State *L, void **ud);
EXTERN_DEF void      (*lua_setallocf) (lua_State *L, lua_Alloc f, void *ud);



/*
** {==============================================================
** some useful macros
** ===============================================================
*/

#define lua_getextraspace(L)	((void *)((char *)(L) - LUA_EXTRASPACE))

#define lua_tonumber(L,i)	lua_tonumberx(L,(i),NULL)
#define lua_tointeger(L,i)	lua_tointegerx(L,(i),NULL)

#define lua_pop(L,n)		lua_settop(L, -(n)-1)

#define lua_newtable(L)		lua_createtable(L, 0, 0)

#define lua_register(L,n,f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)))

#define lua_pushcfunction(L,f)	lua_pushcclosure(L, (f), 0)

#define lua_isfunction(L,n)	(lua_type(L, (n)) == LUA_TFUNCTION)
#define lua_istable(L,n)	(lua_type(L, (n)) == LUA_TTABLE)
#define lua_islightuserdata(L,n)	(lua_type(L, (n)) == LUA_TLIGHTUSERDATA)
#define lua_isnil(L,n)		(lua_type(L, (n)) == LUA_TNIL)
#define lua_isboolean(L,n)	(lua_type(L, (n)) == LUA_TBOOLEAN)
#define lua_isthread(L,n)	(lua_type(L, (n)) == LUA_TTHREAD)
#define lua_isnone(L,n)		(lua_type(L, (n)) == LUA_TNONE)
#define lua_isnoneornil(L, n)	(lua_type(L, (n)) <= 0)

#define lua_pushliteral(L, s)	lua_pushstring(L, "" s)

#define lua_pushglobaltable(L)  \
	((void)lua_rawgeti(L, LUA_REGISTRYINDEX, LUA_RIDX_GLOBALS))

#define lua_tostring(L,i)	lua_tolstring(L, (i), NULL)


#define lua_insert(L,idx)	lua_rotate(L, (idx), 1)

#define lua_remove(L,idx)	(lua_rotate(L, (idx), -1), lua_pop(L, 1))

#define lua_replace(L,idx)	(lua_copy(L, -1, (idx)), lua_pop(L, 1))

/* }============================================================== */


/*
** {==============================================================
** compatibility macros for unsigned conversions
** ===============================================================
*/
#if defined(LUA_COMPAT_APIINTCASTS)

#define lua_pushunsigned(L,n)	lua_pushinteger(L, (lua_Integer)(n))
#define lua_tounsignedx(L,i,is)	((lua_Unsigned)lua_tointegerx(L,i,is))
#define lua_tounsigned(L,i)	lua_tounsignedx(L,(i),NULL)

#endif
/* }============================================================== */

/*
** {======================================================================
** Debug API
** =======================================================================
*/


/*
** Event codes
*/
#define LUA_HOOKCALL	0
#define LUA_HOOKRET	1
#define LUA_HOOKLINE	2
#define LUA_HOOKCOUNT	3
#define LUA_HOOKTAILCALL 4


/*
** Event masks
*/
#define LUA_MASKCALL	(1 << LUA_HOOKCALL)
#define LUA_MASKRET	(1 << LUA_HOOKRET)
#define LUA_MASKLINE	(1 << LUA_HOOKLINE)
#define LUA_MASKCOUNT	(1 << LUA_HOOKCOUNT)

typedef struct lua_Debug lua_Debug;  /* activation record */


/* Functions to be called by the debugger in specific events */
typedef void (*lua_Hook) (lua_State *L, lua_Debug *ar);


EXTERN_DEF int (*lua_getstack) (lua_State *L, int level, lua_Debug *ar);
EXTERN_DEF int (*lua_getinfo) (lua_State *L, const char *what, lua_Debug *ar);
EXTERN_DEF const char *(*lua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
EXTERN_DEF const char *(*lua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
EXTERN_DEF const char *(*lua_getupvalue) (lua_State *L, int funcindex, int n);
EXTERN_DEF const char *(*lua_setupvalue) (lua_State *L, int funcindex, int n);

EXTERN_DEF void *(*lua_upvalueid) (lua_State *L, int fidx, int n);
EXTERN_DEF void  (*lua_upvaluejoin) (lua_State *L, int fidx1, int n1,
                                               int fidx2, int n2);

EXTERN_DEF void (*lua_sethook) (lua_State *L, lua_Hook func, int mask, int count);
EXTERN_DEF lua_Hook (*lua_gethook) (lua_State *L);
EXTERN_DEF int (*lua_gethookmask) (lua_State *L);
EXTERN_DEF int (*lua_gethookcount) (lua_State *L);


struct lua_Debug {
  int event;
  const char *name;	/* (n) */
  const char *namewhat;	/* (n) 'global', 'local', 'field', 'method' */
  const char *what;	/* (S) 'Lua', 'C', 'main', 'tail' */
  const char *source;	/* (S) */
  int currentline;	/* (l) */
  int linedefined;	/* (S) */
  int lastlinedefined;	/* (S) */
  unsigned char nups;	/* (u) number of upvalues */
  unsigned char nparams;/* (u) number of parameters */
  char isvararg;        /* (u) */
  char istailcall;	/* (t) */
  char short_src[LUA_IDSIZE]; /* (S) */
  /* private part */
  struct CallInfo *i_ci;  /* active function */
};

/* }====================================================================== */


/******************************************************************************
* Copyright (C) 1994-2017 Lua.org, PUC-Rio.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************/


#endif
/*
** $Id: lauxlib.h,v 1.131 2016/12/06 14:54:31 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
*/


#ifndef lauxlib_h
#define lauxlib_h






/* extra error code for 'luaL_loadfilex' */
#define LUA_ERRFILE     (LUA_ERRERR+1)


/* key, in the registry, for table of loaded modules */
#define LUA_LOADED_TABLE	"_LOADED"


/* key, in the registry, for table of preloaded loaders */
#define LUA_PRELOAD_TABLE	"_PRELOAD"


typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;


#define LUAL_NUMSIZES	(sizeof(lua_Integer)*16 + sizeof(lua_Number))

EXTERN_DEF void (*luaL_checkversion_) (lua_State *L, lua_Number ver, size_t sz);
#define luaL_checkversion(L)  \
	  luaL_checkversion_(L, LUA_VERSION_NUM, LUAL_NUMSIZES)

EXTERN_DEF int (*luaL_getmetafield) (lua_State *L, int obj, const char *e);
EXTERN_DEF int (*luaL_callmeta) (lua_State *L, int obj, const char *e);
EXTERN_DEF const char *(*luaL_tolstring) (lua_State *L, int idx, size_t *len);
EXTERN_DEF int (*luaL_argerror) (lua_State *L, int arg, const char *extramsg);
EXTERN_DEF const char *(*luaL_checklstring) (lua_State *L, int arg,
                                                          size_t *l);
EXTERN_DEF const char *(*luaL_optlstring) (lua_State *L, int arg,
                                          const char *def, size_t *l);
EXTERN_DEF lua_Number (*luaL_checknumber) (lua_State *L, int arg);
EXTERN_DEF lua_Number (*luaL_optnumber) (lua_State *L, int arg, lua_Number def);

EXTERN_DEF lua_Integer (*luaL_checkinteger) (lua_State *L, int arg);
EXTERN_DEF lua_Integer (*luaL_optinteger) (lua_State *L, int arg,
                                          lua_Integer def);

EXTERN_DEF void (*luaL_checkstack) (lua_State *L, int sz, const char *msg);
EXTERN_DEF void (*luaL_checktype) (lua_State *L, int arg, int t);
EXTERN_DEF void (*luaL_checkany) (lua_State *L, int arg);

EXTERN_DEF int   (*luaL_newmetatable) (lua_State *L, const char *tname);
EXTERN_DEF void  (*luaL_setmetatable) (lua_State *L, const char *tname);
EXTERN_DEF void *(*luaL_testudata) (lua_State *L, int ud, const char *tname);
EXTERN_DEF void *(*luaL_checkudata) (lua_State *L, int ud, const char *tname);

EXTERN_DEF void (*luaL_where) (lua_State *L, int lvl);
EXTERN_DEF int (*luaL_error) (lua_State *L, const char *fmt, ...);

EXTERN_DEF int (*luaL_checkoption) (lua_State *L, int arg, const char *def,
                                   const char *const lst[]);

EXTERN_DEF int (*luaL_fileresult) (lua_State *L, int stat, const char *fname);
EXTERN_DEF int (*luaL_execresult) (lua_State *L, int stat);

/* predefined references */
#define LUA_NOREF       (-2)
#define LUA_REFNIL      (-1)

EXTERN_DEF int (*luaL_ref) (lua_State *L, int t);
EXTERN_DEF void (*luaL_unref) (lua_State *L, int t, int ref);

EXTERN_DEF int (*luaL_loadfilex) (lua_State *L, const char *filename,
                                               const char *mode);

#define luaL_loadfile(L,f)	luaL_loadfilex(L,f,NULL)

EXTERN_DEF int (*luaL_loadbufferx) (lua_State *L, const char *buff, size_t sz,
                                   const char *name, const char *mode);
EXTERN_DEF int (*luaL_loadstring) (lua_State *L, const char *s);

EXTERN_DEF lua_State *(*luaL_newstate) (void);

EXTERN_DEF lua_Integer (*luaL_len) (lua_State *L, int idx);

EXTERN_DEF const char *(*luaL_gsub) (lua_State *L, const char *s, const char *p,
                                                  const char *r);

EXTERN_DEF void (*luaL_setfuncs) (lua_State *L, const luaL_Reg *l, int nup);

EXTERN_DEF int (*luaL_getsubtable) (lua_State *L, int idx, const char *fname);

EXTERN_DEF void (*luaL_traceback) (lua_State *L, lua_State *L1,
                                  const char *msg, int level);

EXTERN_DEF void (*luaL_requiref) (lua_State *L, const char *modname,
                                 lua_CFunction openf, int glb);

/*
** ===============================================================
** some useful macros
** ===============================================================
*/


#define luaL_newlibtable(L,l)	\
  lua_createtable(L, 0, sizeof(l)/sizeof((l)[0]) - 1)

#define luaL_newlib(L,l)  \
  (luaL_checkversion(L), luaL_newlibtable(L,l), luaL_setfuncs(L,l,0))

#define luaL_argcheck(L, cond,arg,extramsg)	\
		((void)((cond) || luaL_argerror(L, (arg), (extramsg))))
#define luaL_checkstring(L,n)	(luaL_checklstring(L, (n), NULL))
#define luaL_optstring(L,n,d)	(luaL_optlstring(L, (n), (d), NULL))

#define luaL_typename(L,i)	lua_typename(L, lua_type(L,(i)))

#define luaL_dofile(L, fn) \
	(luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0))

#define luaL_dostring(L, s) \
	(luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0))

#define luaL_getmetatable(L,n)	(lua_getfield(L, LUA_REGISTRYINDEX, (n)))

#define luaL_opt(L,f,n,d)	(lua_isnoneornil(L,(n)) ? (d) : f(L,(n)))

#define luaL_loadbuffer(L,s,sz,n)	luaL_loadbufferx(L,s,sz,n,NULL)


/*
** {======================================================
** Generic Buffer manipulation
** =======================================================
*/

typedef struct luaL_Buffer {
  char *b;  /* buffer address */
  size_t size;  /* buffer size */
  size_t n;  /* number of characters in buffer */
  lua_State *L;
  char initb[LUAL_BUFFERSIZE];  /* initial buffer */
} luaL_Buffer;


#define luaL_addchar(B,c) \
  ((void)((B)->n < (B)->size || luaL_prepbuffsize((B), 1)), \
   ((B)->b[(B)->n++] = (c)))

#define luaL_addsize(B,s)	((B)->n += (s))

EXTERN_DEF void (*luaL_buffinit) (lua_State *L, luaL_Buffer *B);
EXTERN_DEF char *(*luaL_prepbuffsize) (luaL_Buffer *B, size_t sz);
EXTERN_DEF void (*luaL_addlstring) (luaL_Buffer *B, const char *s, size_t l);
EXTERN_DEF void (*luaL_addstring) (luaL_Buffer *B, const char *s);
EXTERN_DEF void (*luaL_addvalue) (luaL_Buffer *B);
EXTERN_DEF void (*luaL_pushresult) (luaL_Buffer *B);
EXTERN_DEF void (*luaL_pushresultsize) (luaL_Buffer *B, size_t sz);
EXTERN_DEF char *(*luaL_buffinitsize) (lua_State *L, luaL_Buffer *B, size_t sz);

#define luaL_prepbuffer(B)	luaL_prepbuffsize(B, LUAL_BUFFERSIZE)

/* }====================================================== */



/*
** {======================================================
** File handles for IO library
** =======================================================
*/

/*
** A file handle is a userdata with metatable 'LUA_FILEHANDLE' and
** initial structure 'luaL_Stream' (it may contain other fields
** after that initial structure).
*/

#define LUA_FILEHANDLE          "FILE*"


typedef struct luaL_Stream {
  FILE *f;  /* stream (NULL for incompletely created streams) */
  lua_CFunction closef;  /* to close stream (NULL for closed streams) */
} luaL_Stream;

/* }====================================================== */



/* compatibility with old module system */
#if defined(LUA_COMPAT_MODULE)

EXTERN_DEF void (*luaL_pushmodule) (lua_State *L, const char *modname,
                                   int sizehint);
EXTERN_DEF void (*luaL_openlib) (lua_State *L, const char *libname,
                                const luaL_Reg *l, int nup);

#define luaL_register(L,n,l)	(luaL_openlib(L,(n),(l),0))

#endif


/*
** {==================================================================
** "Abstraction Layer" for basic report of messages and errors
** ===================================================================
*/

/* print a string */
#if !defined(lua_writestring)
#define lua_writestring(s,l)   fwrite((s), sizeof(char), (l), stdout)
#endif

/* print a newline and flush the output */
#if !defined(lua_writeline)
#define lua_writeline()        (lua_writestring("\n", 1), fflush(stdout))
#endif

/* print an error message */
#if !defined(lua_writestringerror)
#define lua_writestringerror(s,p) \
        (fprintf(stderr, (s), (p)), fflush(stderr))
#endif

/* }================================================================== */


/*
** {============================================================
** Compatibility with deprecated conversions
** =============================================================
*/
#if defined(LUA_COMPAT_APIINTCASTS)

#define luaL_checkunsigned(L,a)	((lua_Unsigned)luaL_checkinteger(L,a))
#define luaL_optunsigned(L,a,d)	\
	((lua_Unsigned)luaL_optinteger(L,a,(lua_Integer)(d)))

#define luaL_checkint(L,n)	((int)luaL_checkinteger(L, (n)))
#define luaL_optint(L,n,d)	((int)luaL_optinteger(L, (n), (d)))

#define luaL_checklong(L,n)	((long)luaL_checkinteger(L, (n)))
#define luaL_optlong(L,n,d)	((long)luaL_optinteger(L, (n), (d)))

#endif
/* }============================================================ */



#endif


/*
** $Id: lualib.h,v 1.45 2017/01/12 17:14:26 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
*/


#ifndef lualib_h
#define lualib_h



/* version suffix for environment variable names */
#define LUA_VERSUFFIX          "_" LUA_VERSION_MAJOR "_" LUA_VERSION_MINOR


EXTERN_DEF int (*luaopen_base) (lua_State *L);

#define LUA_COLIBNAME	"coroutine"
EXTERN_DEF int (*luaopen_coroutine) (lua_State *L);

#define LUA_TABLIBNAME	"table"
EXTERN_DEF int (*luaopen_table) (lua_State *L);

#define LUA_IOLIBNAME	"io"
EXTERN_DEF int (*luaopen_io) (lua_State *L);

#define LUA_OSLIBNAME	"os"
EXTERN_DEF int (*luaopen_os) (lua_State *L);

#define LUA_STRLIBNAME	"string"
EXTERN_DEF int (*luaopen_string) (lua_State *L);

#define LUA_UTF8LIBNAME	"utf8"
EXTERN_DEF int (*luaopen_utf8) (lua_State *L);

#define LUA_BITLIBNAME	"bit32"
EXTERN_DEF int (*luaopen_bit32) (lua_State *L);

#define LUA_MATHLIBNAME	"math"
EXTERN_DEF int (*luaopen_math) (lua_State *L);

#define LUA_DBLIBNAME	"debug"
EXTERN_DEF int (*luaopen_debug) (lua_State *L);

#define LUA_LOADLIBNAME	"package"
EXTERN_DEF int (*luaopen_package) (lua_State *L);


/* open all previous libraries */
EXTERN_DEF void (*luaL_openlibs) (lua_State *L);



#if !defined(lua_assert)
#define lua_assert(x)	((void)0)
#endif


#endif
EXTERN_DEF const char* (*GetString)(const char *);
