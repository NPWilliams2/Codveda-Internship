#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "FileManager.h"

using namespace std;
namespace fs = filesystem;

FileManager::FileManager()
{
	folderPath = "Files";

	if (!fs::exists(folderPath))
	{
		fs::create_directory(folderPath);
	}
}

string FileManager::getFullPath(const string& fileName)
{
	return folderPath + "/" + fileName + ".txt";
}

void FileManager::createFile()
{
	string fileName;
	string content;
	string line;

	cout << "\n===== Create File =====" << endl;
	cout << "Enter file name without extension: ";
	getline(cin, fileName);

	string filePath = getFullPath(fileName);

	if (fs::exists(filePath))
	{
		cout << "Error: file already exists" << endl;
		return;
	}

	cout << "Enter file content. Type END on a new line to finish:" << endl;

	while (true)
	{
		getline(cin, line);

		if (line == "END")
		{
			break;
		}

		content += line + "\n";
	}

	ofstream file(filePath);

	if (!file)
	{
		cout << "Error: Could nor create file" << endl;
		return;
	}

	file << content;
	file.close();

	cout << "File created successfully" << endl;
	
}

void FileManager::viewFile()
{
	string fileName;
	string line;

	cout << "\n===== View File =====" << endl;
	cout << "Enter file name without extension: ";
	getline(cin, fileName);

	string filePath = getFullPath(fileName);

	if (!fs::exists(filePath))
	{
		cout << "Error: File not found" << endl;
		return;
	}

	ifstream file(filePath);

	if (!file)
	{
		cout << "Error: Could not open file" << endl;
		return;
	}

	cout << "\n===== File Content =====" << endl;

	while (getline(file, line))
	{
		cout << line << endl;
	}

	file.close();
}

void FileManager::renameFile()
{
	string oldName;
	string newName;

	cout << "\n===== Rename File =====" << endl;
	cout << "Enter current file name without extension: ";
	getline(cin, oldName);

	string oldPath = getFullPath(oldName);

	if (!fs::exists(oldPath))
	{
		cout << "Error: file not found" << endl;
		return;
	}

	cout << "Enter new file name without extension: ";
	getline(cin, newName);

	string newPath = getFullPath(newName);

	if (fs::exists(newPath))
	{
		cout << "Error: This file name already exists" << endl;
		return;
	}

	fs::rename(oldPath, newPath);

	cout << "File renamed successfully" << endl;
}

void FileManager::deleteFile()
{
	string fileName;

	cout << "\n===== Delete File =====" << endl;
	cout << "Enter file name without extension: ";
	getline(cin, fileName);

	string filePath = getFullPath(fileName);

	if (!fs::exists(filePath))
	{
		cout << "Error: File not found" << endl;
		return;
	}

	fs::remove(filePath);

	cout << "File deleted successfully" << endl;
}

void FileManager::listFiles()
{
	cout << "\n===== Files =====" << endl;
	
	bool foundFile = false;

	for (const auto& entry : fs::directory_iterator(folderPath))
	{
		if (entry.is_regular_file())
		{
			fileInfo file;

			file.fileName = entry.path().filename().string();
			file.filePath = entry.path().string();

			fileInfo* filePointer = &file;

			cout << "File Name	: " << filePointer->fileName << endl;
			cout << "Location	: " << filePointer->filePath << endl;
			cout << endl;

			foundFile = true;
		}
	}

	if (!foundFile)
	{
		cout << "No files found" << endl;
	}
}