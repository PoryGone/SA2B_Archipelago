#include "../pch.h"
#include "MusicManager.h"

#include "../Utilities/MessageQueue.h"

#include "../ModLoader/MemAccess.h"
#include <map>
#include <algorithm>
#include <iterator>

static int MusicIndex = 0;

static char* __cdecl GetShuffledTrack(char* song) 
{
    MusicManager * musicMan = &MusicManager::getInstance();

    int index = 0;
    while (index < musicMan->_AllMusicNames.size())
    {
        if (strcmp(musicMan->_AllMusicNames[index], song) == 0)
        {
            if (musicMan->_MusicMap.find(index) == musicMan->_MusicMap.end())
            {
                return song;
            }

            int newIndex = musicMan->_MusicMap.at(index);

            if (newIndex >= 100)
            {
                newIndex -= 100;
                return (char*)musicMan->_AllSADXMusicNames[newIndex];
            }
            else
            {
                return (char*)musicMan->_AllMusicNames[newIndex];
            }
        }

        index++;
    }

    return song;
}

static const int MusicJumpBackAddress = 0x442CF5;
__declspec(naked) void PlayShuffledMusic()
{
    __asm
    {
        push edi
        call GetShuffledTrack
        add esp, 4
        mov edi, eax
        mov EAX, [0x01A55998]
        jmp MusicJumpBackAddress
    }
}

static int __cdecl GetShuffledVoice(int inVoice)
{
    MusicManager* musicMan = &MusicManager::getInstance();

    if (musicMan == NULL || musicMan->_VoiceMap.size() == 0 || inVoice == 705)
    {
        return inVoice;
    }

    int index = 0;
    while (index < musicMan->_ShuffledVoiceIDs.size())
    {
        if (inVoice == musicMan->_ShuffledVoiceIDs[index])
        {
            if (musicMan->_VoiceMap.find(index) == musicMan->_VoiceMap.end())
            {
                return inVoice;
            }

            int newIndex = musicMan->_VoiceMap.at(index);

            return musicMan->_ShuffledVoiceIDs[newIndex];
        }

        index++;
    }

    return inVoice;
}

static const int VoiceJumpBackAddress = 0x44313D;
__declspec(naked) void PlayShuffledVoice()
{
    __asm
    {
        mov eax, [esp + 4]
        push edx
        push eax
        call GetShuffledVoice
        add esp, 4
        pop edx
        mov [esp + 4], eax
        jmp VoiceJumpBackAddress
    }
}

static const void* const PlayUnshuffledVoicePtr = (void*)0x44313D;
int PlayUnshuffledVoice(int idk, int num)
{
    signed int result;
    __asm
    {
        push[num]
        mov edx, [idk]
        call PlayUnshuffledVoicePtr
        add esp, 4
        mov result, eax
    }
    return result;
}

void MusicManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    WriteJump((void*)0x442CF0, PlayShuffledMusic);
    WriteJump((void*)0x443130, PlayShuffledVoice);
}

void MusicManager::SetMusicMap(std::map<int, int> map)
{
    this->_MusicMap = map;
}

void MusicManager::SetVoiceMap(std::map<int, int> map)
{
    this->_VoiceMap = map;
}

void MusicManager::SetMusicShuffle(int shuffleType)
{
    this->_ShuffleType = (MusicShuffleType)shuffleType;
}

void MusicManager::SetNarrator(int narrator)
{
    CurrentTheme = (char)narrator;
}
