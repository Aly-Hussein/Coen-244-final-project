//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////
#ifndef __Vertex
#define __Vertex
#include <string>



class vertex
{

public:
	// default constructor
	vertex();

	// copy constructor
	vertex(vertex&);

	// another constructor
	vertex(int, std::string);

	// destructor
	~vertex();

	// Accessing functions
	void setID(int);

	int getID();

	void setValue(std::string);

	std::string getValue();


private:
	int id;
	std::string value;
};


#endif
