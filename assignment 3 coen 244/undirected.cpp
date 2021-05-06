//////////////////////////////////////////
// Name: Omar Mahmoud	and Aly Hussein //
// SID: 40158127   and 40167083        // 
// final project                      //
// Section: COEN 244-D				 //
// Dr: Yan Liu		21-04-2021		//
//////////////////////////////////////
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "undirected.h"
#include <string>
#include <iostream>
#include <stack>

// does nothing but calls the graph constructor
undirected::undirected() : Graph()
{

}

// does nothing but calls the graph destructor
undirected::~undirected()
{

}

// copy constructor
undirected::undirected(undirected& other) : Graph(other)
{

}

// another constructor
undirected::undirected(vertex* vA, int vSize, edge* eA, int eSize)
{
	vertexCounter = vSize;
	edgeCounter = eSize;

	vArray = new vertex[max];
	eArray = new edge[max];

	for (int i = 0; i < vertexCounter; i++)
	{
		vArray[i].setID(vA[i].getID());
		vArray[i].setValue(vA[i].getValue());
	}



	for (int i = 0; i < edgeCounter; i++)
	{
		eArray[i].setEndingVertex(eA[i].getEndingVertex());
		eArray[i].setStartingVertex(eA[i].getStartingVertex());
		eArray[i].setWeight(eA[i].getWeight());
	}




}

bool undirected::addVertex(vertex& v)
{

	for (int i = 0; i < vertexCounter; i++)
	{
		if (vArray[i].getID() == v.getID())
			return false;
	}

	if (vertexCounter < max)
	{
		vArray[vertexCounter] = v;
		vertexCounter++;
		return true;
	}
	else
		return false;

}

// adding array of vertices
bool undirected::addVertices(vertex* givenvArray, int sizeOfGiven)
{
	if ((vertexCounter + sizeOfGiven) > max)
	{
		return false;
	}

	for (int i = 0; i < vertexCounter; i++)
	{
		for (int j = 0; j < sizeOfGiven; j++)
		{
			if (vArray[i].getID() == givenvArray[j].getID())
				return false;
		}
	}


	if ((vertexCounter + sizeOfGiven) < max)
	{
		for (int i = vertexCounter, j = 0; j < sizeOfGiven; i++, j++)
		{
			vArray[i] = givenvArray[j];
			vertexCounter++;
		}
		return true;
	}


}

//removing a vertex, the edges that has connection with this vertex need to be removed;
bool undirected::removeVertex(vertex& v)
{
	for (int i = 0; i < vertexCounter; i++)
	{
		if (vArray[i].getID() == v.getID())
		{
			vertexCounter--;

			for (int j = i; j < vertexCounter; j++)
			{
				vArray[j] = vArray[j + 1];
			}
			for (int s = 0; s < edgeCounter; s++)
			{
				if (eArray[s].getEndingVertex().getID() == v.getID())
				{
					edgeCounter--;

					for (int j = s; j < edgeCounter; j++)
					{
						eArray[j] = eArray[j + 1];
					}
				}
				if (eArray[s].getStartingVertex().getID() == v.getID())
				{
					edgeCounter--;

					for (int j = s; j < edgeCounter; j++)
					{
						eArray[j] = eArray[j + 1];
					}
				}

			}
			return true;
		}
	}
	return false;
}

//adding an edge to the graph
bool undirected::addEdge(edge& e)
{
	for (int i = 0; i < edgeCounter; i++)
	{
		if ((eArray[i].getStartingVertex().getID() == e.getStartingVertex().getID()) && (eArray[i].getEndingVertex().getID() == e.getEndingVertex().getID()))
			return false;
	}

	if (edgeCounter < max)
	{
		eArray[edgeCounter] = e;
		edgeCounter++;
		return true;
	}
	else
		return false;
}

// define your own format of a string representation of the graph.
std::string undirected::toString() const
{
	std::string outputString = "";

	for (int j = 0; j < edgeCounter; j++)
	{
		outputString += eArray[j].getStartingVertex().getValue() + "---" + eArray[j].getEndingVertex().getValue() + "\n";
	}

	return outputString;
}


//removing an edge
bool undirected::removeEdge(edge& e)
{
	for (int i = 0; i < edgeCounter; i++)
	{
		if ((eArray[i].getStartingVertex().getID() == e.getStartingVertex().getID()) && (eArray[i].getEndingVertex().getID() == e.getEndingVertex().getID()))
		{
			for (int s = i; s < edgeCounter; s++)
			{
				eArray[s] = eArray[s + 1];
			}
			edgeCounter--;
			return true;
		}
	}

	return false;
}


//search for vertex
bool undirected::searchVertex(vertex& v)
{
	for (int i = 0; i < vertexCounter; i++)
	{
		if (vArray[i].getID() == v.getID())
		{
			return true;
		}
	}

	return false;
}

//search for edge 
bool undirected::searchEdge(edge& e)
{
	for (int i = 0; i < edgeCounter; i++)
	{
		if ((eArray[i].getStartingVertex().getID() == e.getStartingVertex().getID()) && (eArray[i].getEndingVertex().getID() == e.getEndingVertex().getID()))
		{
			return true;
		}
	}

	return false;
}

//remove all the vertices and edges;
void undirected::clean()
{
	vertex* cleanv = new vertex[max];

	for (int i = 0; i < vertexCounter; i++)
	{
		vArray[i] = cleanv[i];
	}

	edge* cleane = new edge[max];

	for (int i = 0; i < edgeCounter; i++)
	{
		eArray[i] = cleane[i];
	}

	vertexCounter = 0;
	edgeCounter = 0;
}

// Returns true if G1 & G2 have the exact same vertices and edges and weights
bool undirected::operator==(const undirected& G2)
{
	if (vertexCounter != G2.vertexCounter || edgeCounter != G2.edgeCounter)
		return false;
	else
	{
		for (int i = 0; i < vertexCounter; i++)
		{
			if (vArray[i].getID() != G2.vArray[i].getID())
			{
				return false;
			}
		}

		for (int i = 0; i < edgeCounter; i++)
		{
			if ((eArray[i].getStartingVertex().getID() != G2.eArray[i].getStartingVertex().getID()) || (eArray[i].getEndingVertex().getID() != G2.eArray[i].getEndingVertex().getID()))
				return false;
		}
	}

	for (int i = 0; i < edgeCounter; i++)
	{
		if (eArray[i].getWeight() != G2.eArray[i].getWeight())
			return false;
	}


	return true;

}

//assigns graph 2 to graph 1
undirected& undirected::operator=(const undirected& G2)
{
	for (int i = 0; i < G2.vertexCounter; i++)
	{
		vArray[i].setValue(G2.vArray[i].getValue());
		vertexCounter++;
		vArray[i].setID(G2.vArray[i].getID());

	}

	for (int i = 0; i < G2.edgeCounter; i++)
	{
		eArray[i].setEndingVertex(G2.eArray[i].getEndingVertex());
		eArray[i].setStartingVertex(G2.eArray[i].getStartingVertex());
		eArray[i].setWeight(G2.eArray[i].getWeight());
		edgeCounter++;
	}
	return *this;
}

// increases wieghts of all edges by one  prefix
void undirected::operator++()
{
	for (int i = 0; i < edgeCounter; i++)
	{
		eArray[i].setWeight(eArray[i].getWeight() + 1);
	}
}

//increases weights of all edges by one postfix
void undirected::operator++(int)
{
	for (int i = 0; i < edgeCounter; i++)
	{
		eArray[i].setWeight(eArray[i].getWeight() + 1);
	}
}

// returns the total of 2 graphs
undirected& undirected::operator+(undirected& G2)
{
	undirected* sum = new undirected;

	for (int i = 0; i < vertexCounter; i++)
	{
		sum->vArray[i] = vArray[i];
		sum->vertexCounter++;
	}

	for (int i = sum->vertexCounter, j = 0; j < G2.vertexCounter; j++, i++)
	{
		sum->vArray[i] = G2.vArray[j];
		sum->vertexCounter++;
	}


	for (int i = 0; i < edgeCounter; i++)
	{
		sum->eArray[i] = eArray[i];
		sum->edgeCounter++;
	}
	for (int i = sum->edgeCounter, j = 0; j < G2.edgeCounter; i++, j++)
	{
		sum->eArray[i] = G2.eArray[j];
		sum->edgeCounter++;
	}

	return *sum;

}

//returns true if total edge weights is greater on the left side;
bool undirected::operator>(undirected& G2)
{
	int weightLeft = 0;
	int weightRight = 0;

	for (int i = 0; i < edgeCounter; i++)
	{
		weightLeft += eArray[i].getWeight();
	}

	for (int i = 0; i < G2.edgeCounter; i++)
	{
		weightRight += G2.eArray[i].getWeight();
	}

	if (weightLeft > weightRight)
		return true;
	else
		return false;
}

//returns a the printed graph to the output stream
std::ostream& operator<<(std::ostream& out, const undirected& Graph)
{
	out << Graph.toString();

	return out;
}

//prints values of vertices
void undirected::printv()
{
	for (int i = 0; i < vertexCounter; i++)
	{
		std::cout << vArray[i].getValue() << " ";
	}
	std::cout << std::endl;
}



// this function takes a vertex as an argument and gives true if the vertex is in the graph
bool undirected::vertexSearch(vertex& v)
{
	for (int i = 0; i < vertexCounter; i++)
	{
		if (vArray[i].getID() == v.getID())
		{
			return true;
		}
	}

	return false;
}