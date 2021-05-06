//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////
#ifndef DAG__
#define DAG__
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include <string>
#include<iostream>
class DAG : public Graph
{
public:

	// default constructor
	DAG();

	// destructor
	virtual ~DAG();

	//copy constructor
	DAG(DAG&);

	// another constructor
	DAG(vertex*, int,  edge*, int);

	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(vertex& v);

	// adding array of vertices
	virtual bool addVertices(vertex* givenvArray, int sizeOfGiven);

	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex( vertex &v);

	//adding an edge to the graph
	virtual bool addEdge(edge& e);

	// define your own format of a string representation of the graph.
	// this function doesn't include orphan vertices in the graph.
	virtual std::string toString() const;

	//remove a edge; as a result, some node may remain as orphan.
	// remove the edge
	virtual bool removeEdge(edge& e);

	// return true if a vertex exists in a graph;
	virtual bool searchVertex( vertex& v);

	//return true if an edge exists in the graph
	virtual bool searchEdge( edge& e);

	//remove all the vertices and edges;
	virtual void clean();

	// Returns true if G1 & G2 have the exact same vertices and edges and weight
	 bool operator==( const DAG& );

	 //assigns graph 2 to graph 1
	 DAG& operator=(const DAG&);

	 //increases weights of all edges by one prefix
	 void operator++();

	 //increases weights of all edges by one postfix
	 void operator++(int);

	 // returns the total of 2 graphs
	 DAG& operator+(DAG&);

	 //returns true if total edge weights is greater on the left side;
	 bool operator>(DAG&);

	 //returns a the printed graph to the output stream
	 friend std::ostream& operator<<(std::ostream&, const DAG&);

	 //prints values of vertices
	 void printv();

	 // this function takes in a starting vertex as argument and lists the path that it leads to 
	 bool leadingPath(vertex&);

	 // this function takes a vertex as an argument and gives true if the vertex is in the graph
	 virtual bool vertexSearch(vertex&);


	 

};
#endif

