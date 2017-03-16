#include "file.h"

FileComponent* File::clone()
{
	return new File(*this);
}

File::~File()
{
	std::cout << "The file " << getName() << " has been deleted.\n";
}