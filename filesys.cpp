#include "filesys.h"
FileSystem* FileSystem::fs = 0;
FileSystem::Menu* FileSystem::Menu::menu = 0;

list<FileComponent*> all;


FileSystem::FileSystem()
{
	root = new Directory("ROOT");
	all.push_back(root);
}

FileSystem::~FileSystem()
{
	if (fs) delete root;

}

FileSystem& FileSystem::getFileSystem()
{
	if (!fs)
	{
		fs = new FileSystem();
	}
	return *fs;
}

/*============Nested Class - the Menu==================*/

FileSystem::Menu& FileSystem::Menu::getMenu()
{
	if (!menu)
	{
		menu = new Menu();
	}
	return *menu;
}

void FileSystem::Menu::printMenu()
{
	cout << "Welcome to yoav's filesystem:\n" <<
		"Please select what you want to do:\n" <<
		"[0] Quit the program.\n" <<
		"[1] Create a new directory\n" <<
		"[2] Create a new file\n" <<
		"[3] Duplicate a file/directory\n" <<
		"[4] Delete a file/directory\n" <<
		"[5] View content of a file/directory\n" <<
		"[6] Print the FileSystem to external file\n" <<
		"[7] Print the FileSystem to terminal\n";
	cout << "          _._ \n"
		<< "LINUX's  /_ _`. \n"
		<< "Pinguin  (.X.)| \n"
		<< "         |\\_/'| \n"
		<< "        )____`\\ \\\n"
		<< "        //_V _\\ \\ \n"
		<< "      ((  |  `(_) \n"
		<< "     / \\> '   / \\ \n"
		<< "      \\  \\.__./  / \n"
		<< "       `-'    `-' \n"
		<< "Input:";
}

void FileSystem::Menu::selectOption()
{
	bool flag = true;
	string x;
	int index = 0;
	while (flag)
	{
		printMenu();
		while (true)
		{
			cin >> x;
			if (x == "0" || x == "1" || x == "2" || x == "3" || x == "4" 
				|| x == "5" || x == "6" || x=="7")
				break;
			cerr << "Your input is wrong! please try again:";
		}
		index = atoi(x.c_str());
		switch (index)
		{
		case 0:
			exitProgram();
			flag = false;
			break;

		case 1:
			createDir();
			break;

		case 2:
			createFile();
			break;

		case 3:
			duplicateFile();
			break;

		case 4:
			deleteFile();
			break;

		case 5:
			printSpecific();
			break;

		case 6:
			printDirsExternal();
			break;

		case 7:
			cout << "All the directories in your file system:\n";
			printDirs();
			echo();
			break;
		}
	}
}

void FileSystem::Menu::exitProgram()
{
	cout << "Thank you for using the system.\n";
	echo();
}

bool FileSystem::Menu::inRoot()
{
	string inp;
	cout << "Do you want to create the directory in a specific location?\n"
		<< "1) Yes\n2) No\n";
	while (true)
	{
		cin >> inp;
		if (inp == "1") return true;
		if (inp == "2") return false;
		cerr << "Your input is wrong! please try again!\n";
	}
}

void FileSystem::Menu::createDir()
{
	string inp;
	Directory* dir = 0;
	Directory* d = 0;
	cout << "Please select the name of the directory:";
	cin >> inp;
	bool flag = inRoot();
	if (!flag)
	{
		dir = parent.root;
		d = new Directory(inp);
		dir->addFile(d);
		all.push_back(d);
		cout << "The directory has been successfully added!\n";
	}
	else
	{
		if (dir = dynamic_cast<Directory*>(getDirectory()))
		{
			d = new Directory(inp);
			dir->addFile(d);
			all.push_back(d);
			cout << "The directory has been successfully added!\n";
		}
		else
		{
			cerr << "You should select a directory only!\n";
		}
	}
	echo();
}

void FileSystem::Menu::createFile()
{
	string inp;
	string end;
	int index = 0;
	Directory* dir = 0;
	cout << "Please select the name of the file:";
	cin >> inp;
	bool flag = inRoot();
	if (!flag) dir = parent.root;
	else dir = dynamic_cast<Directory*>(getDirectory());
	if (dir)
	{
		cout << "Please select the kind of the file:\n" <<
			"1. jpg\n2. zip\n3. exe\n4. txt\n5. bin\n6. csv\n7. pdf\n";

		while (true)
		{
			cin >> end;
			if (end == "1" || end == "2" || end == "3" || end == "4" ||
				end == "5" || end == "6" || end == "7")
				break;
			cerr << "Your input is wrong! please try again:";
		}

		index = atoi(end.c_str());
		switch (index)
		{
		case 1: end = ".jpg"; break;
		case 2: end = ".zip"; break;
		case 3: end = ".exe"; break;
		case 4: end = ".txt"; break;
		case 5: end = ".bin"; break;
		case 6: end = ".csv"; break;
		case 7: end = ".pdf"; break;
		}
		inp += end;
		cout << inp;
		File* d = new File(inp);
		dir->addFile(d);
		all.push_back(d);
		cout << " has been successfully added!\n";
	}
	else
	{
		cerr << "You sould select a directory only!\n";
	}
	echo();
}

void FileSystem::Menu::printDirs()
{
	parent.root->print();
}



FileComponent* FileSystem::Menu::getDirectory()
{
	string inp;
	int id = 0;
	FileComponent* fc = 0;
	Directory* d = 0;
	printDirs();
	cout << "Please choose the ID of the directory/file:";
	while (true)
	{
		cin >> inp;
		if (is_number(inp))
		{
			id = atoi(inp.c_str());
			if (fc = search(id))
			{
	//			fc = search(id);
	//			if (d = dynamic_cast<Directory*>(fc)) return d;
	//			break;
				return fc;
			}
		}
		cerr << "your input is wrong! please try again:";
	}
	return fc;
}

void FileSystem::Menu::duplicateFile()
{
	FileComponent* f = getDirectory();
	FileComponent* dup = 0;
	if (f == parent.root)
	{
		cerr << "You can't duplicate the ROOT directory!\n";
	}
	else if (!f) cerr << "The file has not been found.\n";
	else
	{
		dup = f->clone();
		parent.root->addFile(dup);
		assignAll(dup);
		cout << "The file/directory has been successfully duplicated.\n";
	}
	echo();
}

void FileSystem::Menu::deleteFile()
{
	FileComponent* f = getDirectory();
	if (f == parent.root)
	{
		cerr << "You can't delete the ROOT directory!\n";
	}
	else
	{
		clearAll(f);
		parent.root->removeFile(f);
	}
	echo();
}

FileComponent* FileSystem::Menu::search(int id)
{
	for (list<FileComponent*>::iterator i = all.begin(); i != all.end(); i++)
	{
		if (*i)
		{
			if ((*i)->getId() == id) return *i;
		}
	}
	return 0;
}

void FileSystem::Menu::printDirsExternal()
{
	FileSelector selector;
	stringstream ss;
	parent.root->print(ss);
	selector.produce(TEXT, ss.str());
	selector.produce(HTML, ss.str());
	cout << "The filesystem written into external files successfully.\n";
	echo();
}

void FileSystem::Menu::printSpecific()
{
	FileComponent* fc = getDirectory();
	system("cls || clear");
	cout << "===Printing the specific directory/file:===\n";
	fc->print();
	echo();
}

void FileSystem::Menu::echo()
{
	cout << "Please press ENTER to continue...";
	fflush(stdin);
	while (getchar() != '\n');
	system("cls || clear");
}

void clearAll(FileComponent* fc)
{
	if (fc == 0) return;
	all.remove(fc);
	Directory* d = dynamic_cast<Directory*>(fc);
	if (!d) return;
	if (d->getFiles().size() != 0)
		clearAll(*d->getFiles().begin()++);
}

void assignAll(FileComponent* fc)
{
	if (fc == 0) return;
	all.push_back(fc);
	Directory* d = dynamic_cast<Directory*>(fc);
	if (!d) return;
	if (d->getFiles().size() != 0)
		assignAll(*d->getFiles().begin()++);
}

bool is_number(const std::string& s)
{
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		if (!(isdigit(*it))) return false;
	}
	return true;
}
