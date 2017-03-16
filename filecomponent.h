#ifndef filecomponent_h
#define filecomponent_h
#include <iostream>
#include <string>
#include <ctime>
class FileComponent
{
protected:
	static int numOfFiles;
	int id;
	std::string name;
	std::string timeCreated;
public:
	FileComponent(std::string n = "noname");
	FileComponent(const FileComponent& fc);
	virtual ~FileComponent() {};
	FileComponent& operator=(const FileComponent& fc) {}
	virtual FileComponent* clone() = 0;
	virtual void print(std::ostream& os = std::cout);
	std::string getName() const { return name; }
	int getId() const { return id; }
	std::string getTimeCreated() const { return timeCreated; }
	static int getNumOfFiles() { return numOfFiles; }
};
#endif // !filecomponent_h
