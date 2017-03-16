#ifndef directory_h
#define directory_h
#include <list>
#include "file.h"

class Directory: public FileComponent
{
private:
	std::list<FileComponent*> files;

public:
	~Directory();
	Directory(std::string n = "noname"): FileComponent(n) {}
	Directory(const Directory& d) {};
	Directory* operator=(const Directory& d) {};
	void addFile(FileComponent* f);
	void removeFile(FileComponent* f);
	virtual void print(std::ostream& os = std::cout);
	std::list<FileComponent*> getFiles() const { return files; }
	virtual FileComponent* clone();
};

#endif // !directory_h
