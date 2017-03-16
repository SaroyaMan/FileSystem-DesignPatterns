#include "directory.h"

Directory::~Directory()
{
	std::cout << "the directory "<<getName()<<" has been deleted\n";
	for (std::list<FileComponent*>::iterator it = files.begin(); it != files.end(); it++)
	{
		if (*it)
		{
			(*it)->~FileComponent();
		}
	}
}

void Directory::addFile(FileComponent* f)
{
	files.push_back(f);
}

void Directory::removeFile(FileComponent* f)
{
	if (f == 0) return;
	for (std::list<FileComponent*>::iterator it = files.begin(); it != files.end(); it++)
	{
		if ((*it)->getId() == f->getId())
		{
			delete f;
			files.erase(it);
			return;
		}
		if (Directory* d = dynamic_cast<Directory*>(*it))
		{
			d->removeFile(f);
		}
	}
}

void Directory::print(std::ostream& os)
{
	static int j = 0;
	os << "#DIR=" << getName() << " id=" << getId() << " time created:"<<timeCreated<<"#\n";
	for (std::list<FileComponent*>::iterator it = files.begin(); it != files.end(); it++)
	{
		if (*it)
		{
			j += 4;
			for (int k = 0; k < j; k++) os << " ";
			(*it)->print(os);
			j -= 4;
		}
	}
}

FileComponent* Directory::clone()
{
	Directory* d = new Directory(getName());
	for (std::list<FileComponent*>::const_iterator it = files.begin(); it != files.end(); it++)
	{
			d->addFile((*it)->clone());
	}
	return d;
}