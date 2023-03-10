// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <MinHook.h>
#include <Windows.h>
#include <cstdio>
#include <cstdint>
#include "hooks.h"
void init()
{
    //creating console log 
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "W", stdout);
    
    //initiallizing minhook fr 
    MH_Initialize();

}
void main()
{
    init();
    unlockEmotes();
    printf("emote unlocker by ItsSnow#1660");

}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0,0,(LPTHREAD_START_ROUTINE)main,0,0,0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

