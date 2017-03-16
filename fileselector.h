#ifndef fileselector_h
#define fileselector_h
#include "filedirector.h"
#include "htmlfilebuilder.h"
#include "textfilebuilder.h"

typedef enum FILE_TYPER { TEXT, HTML }F_TYPE;

class FileSelector
{
public:
	inline FileSelector();
	inline ~FileSelector();
	inline void produce(F_TYPE ft, string text);

private:
	FileDirector fd;
	TextFileBuilder* ptxtfb;
	HTMLFileBuilder* phtmlfb;
};


FileSelector::FileSelector()
	: ptxtfb(new TextFileBuilder("my_filesystem")),
	phtmlfb(new HTMLFileBuilder("my_filesystem"))
{}


FileSelector::~FileSelector()
{
	delete ptxtfb;
	delete phtmlfb;
}


void FileSelector::produce(F_TYPE ft, string text)
{
	switch (ft)
	{
	case TEXT: fd.setBuilder(ptxtfb);  break;
	case HTML: fd.setBuilder(phtmlfb); break;
	}

	fd.construct(text);
}
#endif