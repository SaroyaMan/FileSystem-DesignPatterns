#include "filecomponent.h"

int FileComponent::numOfFiles = 0;


void FileComponent::print(std::ostream& os)
{
	 os << getName() << " id=" << getId() <<" time created: "<<timeCreated <<"\n";
}

FileComponent::FileComponent(std::string n) : name(n)
{
	id = numOfFiles++;

	/*getting the time created:*/
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", timeinfo);
	timeCreated = buffer;
}

FileComponent::FileComponent(const FileComponent& fc) : name(fc.getName())
{
	id = numOfFiles++;

	/*getting the time created:*/
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", timeinfo);
	timeCreated = buffer;
}