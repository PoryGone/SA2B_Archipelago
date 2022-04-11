#include "../pch.h"
#include "MusicManager.h"

#include "../Utilities/MessageQueue.h"

#include "../ModLoader/MemAccess.h"
#include <map>
#include <algorithm>
#include <iterator>


static char* __cdecl GetShuffledTrack(char* song) 
{
    MusicManager * musicMan = &MusicManager::getInstance();

    switch (musicMan->_ShuffleType)
    {
        case MusicShuffleType::MST_Full:
        {
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

                    return (char*)musicMan->_AllMusicNames[newIndex];
                }

                index++;
            }

            return song;
        }
        case MusicShuffleType::MST_Levels:
        {
            int index = 0;
            while (index < musicMan->_LevelMusicNames.size())
            {
                if (strcmp(musicMan->_LevelMusicNames[index], song) == 0)
                {
                    if (musicMan->_MusicMap.find(index) == musicMan->_MusicMap.end())
                    {
                        return song;
                    }

                    int newIndex = musicMan->_MusicMap.at(index);

                    return (char*)musicMan->_LevelMusicNames[newIndex];
                }

                index++;
            }

            return song;
        }
        default:
        {
            return song;
        }
    }
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
