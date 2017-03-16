#ifndef filedirector_h
#define filedirector_h
#include "filebuilder.h"


class FileDirector
{
public:
	inline void setBuilder(FileBuilder* pfbInit);
	inline void construct(string text);

private:
	FileBuilder* pfb;
};


void FileDirector::setBuilder(FileBuilder* pfbInit)
{
	pfb = pfbInit;
}


void FileDirector::construct(string text)
{
	pfb->buildNextRow(text);
	pfb->closeFile();
}


#endif