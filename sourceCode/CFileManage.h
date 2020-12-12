#pragma once
#include "iostream"
#include "fstream"
#include "string"

class CFileManage
{
public:
	static CFileManage* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new CFileManage();
		}
		return s_pInstance;
	}
	/*
	* ���ļ��ж�ȡһ���ַ��������ظ��ַ���
	*/
	std::string readin();
	/*
	* д���ַ��������ַ���д�뵽�ļ���
	*/
	void write(std::string words);
private:
	static CFileManage* s_pInstance;
};