#ifndef filesys_h
#define filesys_h
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "file.h"
#include "directory.h"
#include "fileselector.h"
using namespace std;

class FileSystem
{
private:
	static FileSystem* fs;
	FileSystem();
	Directory* root;

public:
	static FileSystem& getFileSystem();
	FileSystem(const FileSystem& fs) {};			//we dont want copy c'tor in singletone!
	FileSystem& operator=(const FileSystem& fs) {};//we dont want operator= in singletone!
	~FileSystem();

	class Menu
	{
	private:
		static Menu* menu;
		FileSystem& parent;  // Reference to parent
		void printMenu();
		void selectOption();
		void exitProgram();
		void createDir();
		void createFile();
		void printDirs();
		void echo();
		FileComponent* getDirectory();
		FileComponent* search(int id);
		void duplicateFile();
		void deleteFile();
		void printSpecific();
		void printDirsExternal();
		bool inRoot();
		Menu() : parent(FileSystem::getFileSystem()) {} // Initialise reference in constructor
	public:
		void start() { selectOption(); }
		static Menu& getMenu();
		Menu(const Menu& m) : parent(FileSystem::getFileSystem()) {*this = getMenu();} //we dont want copy c'tor in singletone!
		Menu& operator=(const Menu& m) {}	//we dont want operator= in singletone!
	};
};

void clearAll(FileComponent* fc);
void assignAll(FileComponent* fc);
bool is_number(const std::string& s);

#endif // !filesys_h
