#include "CFileManage.h"

CFileManage* CFileManage::s_pInstance = NULL;

std::string CFileManage::readin()
{
	std::ifstream fin;
	fin.open("data.data");
	if (!fin.is_open())
	{
		std::cout << "打开文件失败" << std::endl;
		return "0";
	}
	std::string temp;
	fin >> temp;
	fin.close();
	return temp;
}

void CFileManage::write(std::string words)
{
	std::ofstream fout;
	fout.open("data.data");
	if (fout.is_open())
	{
		fout << words;
		fout.close();
	}
	else
	{
		std::cout << "文件写入失败";
	}
}
