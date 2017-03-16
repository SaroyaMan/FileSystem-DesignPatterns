#ifndef htmlfilebuilder_h
#define htmlfilebuilder_h
#include <sstream>
#include "filebuilder.h"


class HTMLFileBuilder : public FileBuilder
{
public:
	inline HTMLFileBuilder(string strFileName);
	virtual inline void buildNextRow(string strRow);
	virtual inline void closeFile();
};


HTMLFileBuilder::HTMLFileBuilder(string strFileName)
	: FileBuilder(strFileName.append(".html"))
{
	FileBuilder::buildNextRow("<HTML>\n<BODY>\n");
}


void HTMLFileBuilder::buildNextRow(string strRow)
{
	stringstream ss;
	for (int i = 0; i < strRow.size()-1; i++)
	{
		if (strRow[i] == '\n')
		{
			ss << "<br>\n";
		}
		else if (strRow[i] == ' ')
		{
			ss << "&nbsp;";
		}
		else ss << strRow[i];
	}
	ss << "<br>\n";
	FileBuilder::buildNextRow(ss.str());
}


void HTMLFileBuilder::closeFile()
{
	FileBuilder::buildNextRow("</BODY>\n</HTML>");
	FileBuilder::closeFile();
}
#endif