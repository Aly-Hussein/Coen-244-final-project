//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////

#ifndef __graph
#define __graph
#include "vertex.h"
#include "edge.h"
#include <string>
#include<iostream>


class Graph {
public:

	// default constructor
	Graph()
	{
		vArray = new vertex[max];
		eArray = new edge[max];
		vertexCounter = edgeCounter = 0;
	}

	Graph(Graph& other)
	{
		vertexCounter = other.vertexCounter;

		vArray = new vertex[max];

		for (int i = 0; i < vertexCounter; i++)
		{
			vArray[i].setID(other.vArray[i].getID());
			vArray[i].setValue(other.vArray[i].getValue());
		}

		edgeCounter = other.edgeCounter;

		eArray = new edge[max];

		for (int i = 0; i < edgeCounter; i++)
		{
			eArray[i].setEndingVertex(other.eArray[i].getEndingVertex());
			eArray[i].setStartingVertex(other.eArray[i].getStartingVertex());
			eArray[i].setWeight(other.eArray[i].getWeight());
		}

	}

		// destructor
	virtual ~Graph()
	{
		delete[] vArray;
		delete[] eArray;
	}

	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(vertex& v) = 0;

	// adding array of vertices
	virtual bool addVertices(vertex* givenvArray, int sizeOfGiven ) = 0;

	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(vertex &v) = 0;

	//insert edge in the graph
	virtual bool addEdge(edge& e) = 0;

	//remove a edge; as a result, some node may remain as orphan.
	// remove the edge
	virtual bool removeEdge(edge& e) = 0;

	// return bool if a vertex exists in a graph;
	virtual bool searchVertex( vertex& v) = 0;

	// return bool if a Edge exists in a graph;
	virtual bool searchEdge( edge& e) = 0;

	// define your own format of a string representation of the graph.
	virtual std::string toString() const=0;

	//remove all the vertices and edges;
	virtual void clean() = 0;

	

	// this function takes a vertex as an argument and gives true if the vertex is in the graph
	virtual bool vertexSearch(vertex&) = 0;

protected:

	// vertex and edge counter keep track of number of vertices/edges in the arrays
	vertex* vArray;
	edge* eArray;
	int vertexCounter;
	int edgeCounter;

	// maximum number of edges and vertices in the arrays
	int max = 100;
};







#endif
