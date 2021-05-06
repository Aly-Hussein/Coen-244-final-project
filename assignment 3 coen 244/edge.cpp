//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////
#include <iostream>
#include "vertex.h"
#include "edge.h"

// default constructor initializes the weght to 0 and doesn't initialize the vertices
edge::edge()
{
	weight = 0;
}

//copy constructor
edge::edge(edge& other)
{
	setEndingVertex(other.endingVertex);
	setStartingVertex(other.startingVertex);
	setWeight(other.weight);
}

// another constructor initializes the weight and the vertices to the given values
edge::edge(int givenWeight, vertex&givenStart, vertex&givenEnd)
{
	weight = givenWeight;
	startingVertex = givenStart;
	endingVertex = givenEnd;
}

// destructor does nothing
edge::~edge()
{

}

//set weight sets the wight to the given value
void edge::setWeight(int givenWeight)
{
	weight = givenWeight;
}

// get weight returns the weight 
int edge::getWeight()
{
	return weight;
}

// set starting vertex sets the start of the edge to the given vertex
void edge::setStartingVertex(vertex&givenVertex)
{
	startingVertex = givenVertex;
}

// get starting vertex returns the start of the edge
vertex& edge::getStartingVertex()
{
	return startingVertex;
}

//set ending vertex sets the end of the edge to the given vertex
void edge::setEndingVertex(vertex& givenVertex)
{
	endingVertex = givenVertex;
}

//get ending vertex returns the end of the edge
vertex& edge::getEndingVertex()
{
	return endingVertex;
}