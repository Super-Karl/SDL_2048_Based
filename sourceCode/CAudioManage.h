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

    bool load(std::string fileName, std::string id, sound_type type);//��������

    /*
    * ��������
    * ��һ������Ϊ������id,��load����ʱ���õ�id
    * �ڶ�������Ϊ�Ƿ�ѭ������
    */
    void playSound(std::string id, int loop);

    /*
    * ֹͣ��������������Ϊ��fade_out��������������ͣ
    */
    void stopMusic(const int fade_out) const;

    /*
    * ��ͣ����
    */
    void pauseMusic() const;

    /*
    * ������������
    */
    void resumeMusic() const;

    /*
    * ������������
    */
    void setMusicVolume(const int vol) const;

    /*
    * ������������
    */
    void setSoundVolume(const int vol) const;

    /*
    * ������������
    */
    void setAllVolume(const int vol) const;

    /*
    * ������������һ������Ϊ����id,�ڶ�������Ϊ�Ƿ�ѭ������
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