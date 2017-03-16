#ifndef textfilebuilder_h
#define textfilebuilder_h
#include "filebuilder.h"


class TextFileBuilder : public FileBuilder
{
public:
	inline TextFileBuilder(string strFileName);
	virtual inline void buildNextRow(string strRow);
};


TextFileBuilder::TextFileBuilder(string strFileName)
	: FileBuilder(strFileName.append(".txt"))
{}


void TextFileBuilder::buildNextRow(string strRow)
{
	FileBuilder::buildNextRow(strRow.append("\n"));
}

#endif