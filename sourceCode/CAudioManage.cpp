#include "CAudioManage.h"

CAudioManage* CAudioManage::s_pInstance;

CAudioManage::CAudioManage()
{
    Mix_OpenAudio(22050, AUDIO_S16, 2, (4096 / 2));
}

CAudioManage::~CAudioManage()
{
    Mix_CloseAudio();
}

bool CAudioManage::load(std::string fileName, std::string id, sound_type type)
{
    if (type == SOUND_MUSIC)
    {
        Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
        if (pMusic == 0)
        {
            std::cout << "Could not load music: ERROR - " << Mix_GetError() << std::endl;
            return false;
        }

        m_music[id] = pMusic;
        return true;
    }
    else if (type == SOUND_SFX)
    {
        Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
        if (pChunk == 0)
        {
            std::cout << "Could not load SFX: ERROR - " << Mix_GetError() << std::endl;
            return false;
        }

        m_sfxs[id] = pChunk;
        return true;
    }
    return false;
}

void CAudioManage::playMusic(std::string id, int loop)
{
    Mix_FadeInMusic(m_music[id], loop, 2000);
}

void CAudioManage::playSound(std::string id, int loop)
{
    Mix_PlayChannel(-1, m_sfxs[id], loop);
}

void CAudioManage::stopMusic(const int fade_out/* = 0 */) const
{
    if (Mix_PlayingMusic())
    {
        Mix_FadeOutMusic(fade_out);
    }
}

void CAudioManage::pauseMusic() const
{
    if (Mix_PlayingMusic())
    {
        Mix_PauseMusic();
    }
}

void CAudioManage::resumeMusic() const
{
    if (Mix_PausedMusic())
    {
        Mix_ResumeMusic();
    }
}

void CAudioManage::setMusicVolume(const int vol) const
{
    if (vol >= 0 && vol <= 128)
    {
        Mix_VolumeMusic(vol);
    }
}

void CAudioManage::setSoundVolume(const int vol) const
{
    if (vol >= 0 && vol <= 128)
    {
        Mix_Volume(-1, vol);
    }
}

void CAudioManage::setAllVolume(const int vol) const
{
    setMusicVolume(vol);
    setSoundVolume(vol);
}