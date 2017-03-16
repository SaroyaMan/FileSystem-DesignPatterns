#include <iostream>
#include <sstream>
#include "filesys.h"
#include <ctime>
using namespace std;
//All rights reserved to ®Yoav Saroya - 304835887

/* This software is written by Yoav Saroya.
 * The patterns i used:
 * Singletone - there is only one object of FileSystem and the nested class Menu.
 * Prototype - we want to easly duplicate directories/files.
 * Composite - Directory and File has the same functional
 * Builder - we want to create complex object easly - HTMLFile and TXTFile.
 */

int main(int argc, char** argv)
{
	FileSystem::Menu& m = FileSystem::Menu::getMenu();
	m.start();
	return 0;
}
