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
	* 从文件中读取一个字符串，返回该字符串
	*/
	std::string readin();
	/*
	* 写入字符串，将字符串写入到文件中
	*/
	void write(std::string words);
private:
	static CFileManage* s_pInstance;
};