#pragma once
#include <string>

using namespace std;

struct fileInfo
{
	string fileName;
	string filePath;
};

class FileManager
{
private:
	string folderPath;

public:
	FileManager();

	void createFile();
	void viewFile();
	void renameFile();
	void deleteFile();
	void listFiles();

private:
	string getFullPath(const string& fileName);
};
