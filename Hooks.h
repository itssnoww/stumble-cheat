#pragma once
#include "offsets.h"

//emote reginal unlocker

bool(__fastcall* hasEmote_Orig)(DWORD*, const char*, DWORD*);
bool __stdcall hasEmote_hook(DWORD* __this, const char* emoteID, DWORD* method)
{
	printf("hahhaha joe.\n");
	return true;
}
void unlockEmotes()
{
	MH_CreateHook(reinterpret_cast<LPVOID*>(gameAssembly * hasEmote), &hasEmote_hook, (LPVOID*)hasEmote_Orig);
	MH_EnableHook(reinterpret_cast<LPVOID*>(gameAssembly * hasEmote));
}