#pragma once

#include "SDL_mixer.h"

#include <iostream>
#include <map>
#include <string>

enum sound_type
{
    SOUND_MUSIC = 0,
    SOUND_SFX = 1
};

class CAudioManage
{
public:

    static CAudioManage* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new CAudioManage();
            return s_pInstance;
        }
        return s_pInstance;
    }

    bool load(std::string fileName, std::string id, sound_type type);//加载音乐

    /*
    * 播放声音
    * 第一个参数为声音的id,即load加载时设置的id
    * 第二个参数为是否循环播放
    */
    void playSound(std::string id, int loop);

    /*
    * 停止播放声音，参数为在fade_out毫秒内声音逐渐消停
    */
    void stopMusic(const int fade_out) const;

    /*
    * 暂停声音
    */
    void pauseMusic() const;

    /*
    * 继续播放声音
    */
    void resumeMusic() const;

    /*
    * 设置音乐音量
    */
    void setMusicVolume(const int vol) const;

    /*
    * 设置声音音量
    */
    void setSoundVolume(const int vol) const;

    /*
    * 设置所有音量
    */
    void setAllVolume(const int vol) const;

    /*
    * 播放声音，第一个参数为声音id,第二个参数为是否循环播放
    */
    void playMusic(std::string id, int loop);

private:

    static CAudioManage* s_pInstance;

    std::map<std::string, Mix_Chunk*> m_sfxs;
    std::map<std::string, Mix_Music*> m_music;

    CAudioManage();
    ~CAudioManage();

    CAudioManage(const CAudioManage&);
    CAudioManage& operator=(const CAudioManage&);
};