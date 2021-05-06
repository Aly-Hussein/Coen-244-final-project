//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////
#include "vertex.h"
#include <iostream>

//copy constructor
vertex::vertex(vertex& other)
{
	id = other.id;
	value = other.value;
}

//default constructor initializes value and id to nothing
vertex::vertex()
{
	id = 0;

	value = "";
}

// other constructor initialzes value and id with given values
vertex::vertex(int givenID, std::string givenValue)
{

	id = givenID;

	value = givenValue;

}

// destructor does nothing
vertex::~vertex() 
{

}

// setId sets id to given id
void vertex::setID(int givenID)
{
	id = givenID;
}

//getID returns the id
int vertex::getID()
{
	return id;
}

//setValue sets value to given value
void vertex::setValue(std::string givenValue)
{
	value = givenValue;
}

//getValue returns the value
std::string vertex::getValue()
{
	return value;
}