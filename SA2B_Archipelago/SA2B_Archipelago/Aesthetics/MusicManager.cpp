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
__declspec(naked) void PlayShuffledMusic() {
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

void MusicManager::OnInitFunction(const char* path, const HelperFunctions& helperFunctions)
{
	_helperFunctions = &helperFunctions;

    WriteJump((void*)0x442CF0, PlayShuffledMusic);
}

void MusicManager::SetMusicMap(std::map<int, int> map)
{
    this->_MusicMap = map;
}

void MusicManager::SetMusicShuffle(int shuffleType)
{
    this->_ShuffleType = (MusicShuffleType)shuffleType;
}
