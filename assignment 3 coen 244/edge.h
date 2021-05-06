//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////

#ifndef __edge
#define __edge
#include "vertex.h"

class edge
{

private:
	// the weight of an edge is similar to the size of an arrow .. in different applications it may have different defenitions or meanings
	int weight;

	// the starting vertex is the vertex where the edge originates from or starts from 
	vertex startingVertex;

	// the endign vertex is the vertex where the edge is pointing at or heading to or leads to 
	vertex endingVertex;

public:
	// default constructor
	edge();

	//copy constructor
	edge(edge&);

	// another constructor
	edge(int, vertex&, vertex&);

	// destructor
	~edge();

	//Accessing functions;

	void setWeight(int);
	int getWeight();
	void setStartingVertex(vertex&);
	vertex& getStartingVertex();
	void setEndingVertex(vertex&);
	vertex& getEndingVertex();



};
#endif
