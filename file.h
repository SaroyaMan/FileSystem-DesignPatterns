#ifndef file_h
#define file_h
#include "filecomponent.h"

class File: public FileComponent
{
private:

public:
	File(std::string n) : FileComponent(n) { }
	virtual ~File();
	File(const File& f) : FileComponent(f.getName()) { }
	File& operator=(const File& f) {};
	virtual FileComponent* clone();
};

#endif // !file_h
