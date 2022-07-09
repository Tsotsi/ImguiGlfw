#ifndef LUAJIT_VM
#define LUAJIT_VM

#include <iostream>
#include <lua.hpp>

static void close_state(lua_State **L) { lua_close(*L); }
#define cleanup(x) __attribute__((cleanup(x)))
#define auto_lclose cleanup(close_state)

struct Vm
{
    lua_State *L;
} vm;
void vm_init()
{
    vm.L = NULL;
}
void vm_open()
{
    vm.L = lua_open();
    luaL_openlibs(vm.L);
    // luaL_openlib(vm.L, "io");
}

void vm_run()
{
    luaL_loadstring(vm.L, "io.stdout:write('hello world from lua vm!\\n')");
    lua_pcall(vm.L, 0, 0, 0);

#ifdef _MY_LUA_FILE
    luaL_loadfile(vm.L, _MY_LUA_FILE);
    std::cout << "try load " << _MY_LUA_FILE << std::endl;
    lua_pcall(vm.L, 0, 0, 0);
#else
    std::cout << "error: can't found _MY_LUA_FILE" << std::endl;
#endif
   
}

void vm_close()
{
    lua_close(vm.L);
}
#endif