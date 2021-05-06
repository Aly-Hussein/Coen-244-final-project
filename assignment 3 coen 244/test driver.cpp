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
#include "graph.h"
#include "DAG.h"
#include "undirected.h"


using namespace std;


void dagTest()
{
	cout << "START OF DAG TEST:" << endl;

	// creating 6 nodes
	vertex v1(3, "sun");
	vertex v2(5, "grass");
	vertex v3(7, "grasshopper");
	vertex v4(9, "bird");
	vertex v5(10, "snake");
	vertex v6(13, "fox");

	// creating 5 edges to conncect these nodes
	edge e2(1, v1, v2);
	edge e3(1, v2, v3);
	edge e4(1, v3, v4);
	edge e5(1, v4, v5);
	edge e6(1, v5, v6);

	//putting 5 edges in an array
	edge eArray1[5];

	eArray1[0] = e2;
	eArray1[1] = e3;
	eArray1[2] = e4;
	eArray1[3] = e5;
	eArray1[4] = e6;

	//putting 5 nodes in an array
	vertex vArray1[5];

	vArray1[0] = v2;
	vArray1[1] = v3;
	vArray1[2] = v4;
	vArray1[3] = v5;
	vArray1[4] = v6;

	// default constructor called
	DAG foodChain;

	

	//testing add vertex function
	cout<< "\n" << (foodChain.addVertex(v1)?"vertex added successfully":"vertex not added since graph is full or bertex already exists in grapgh")<<endl;

	//testing add vertices function
	cout << "\n" << (foodChain.addVertices(vArray1,5) ? "vertices added successfully" 
		: "vertices not added since the amout of vertices in the array cannot all be held in the graph or the array has a vertex already in the graph")<<endl;


	// testing add edge function
	cout << (foodChain.addEdge(e2) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e3) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e4) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e5) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e6) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;

	// testing tostring function
	cout<< "\n" << foodChain.toString();

	foodChain.removeVertex(v1);


	//testing remove vertex function
	cout << "\n" << (foodChain.removeVertex(v2) ? "vertex removed successfully" : "vertex not found so not removed") << endl;


	// testing that the edges involved with the vertices' removed are also removed .. if they are removed as well then the to string will not include them
	cout << "\n" << foodChain.toString();

	// testing search vertex
	cout << "\n" << (foodChain.searchVertex(v1) ? "vertex exists" : "vertex doesn't exist") << endl;

	// testing search edge it is false because we removed v1 and v2 and e2 was the link between them so it is removed with them
	cout << "\n" << (foodChain.searchEdge(e2) ? "edge exists" : "edge doesn't exist") << endl;

	// testing the == operator ... since I have done the same functions to foodChain1 they must be equal
	DAG foodChain1;


	foodChain1.addVertex(v1);
	foodChain1.addVertices(vArray1, 5);
	foodChain1.addEdge(e2);
	foodChain1.addEdge(e3);
	foodChain1.addEdge(e4);
	foodChain1.addEdge(e5);
	foodChain1.addEdge(e6);
	foodChain1.removeVertex(v2);
	foodChain1.removeVertex(v1);

// the actual test .. must be equal
	cout << "\n"<<(foodChain == foodChain1 ? "the graphs are equal" : "the graphs are not equal") << endl;

	// testing the ++ operator (prefix)
	++foodChain;
	
	// now since foodchain has more total weight they are not equal
	cout << "\n" << (foodChain == foodChain1 ? "the graphs are equal" : "the graphs are not equal") << endl;

	// testing the ++ operator (postfix)
	foodChain1++;

	// now since we increased the weight of foodChain1 they should be equal again
	cout << "\n" << (foodChain == foodChain1 ? "the graphs are equal" : "the graphs are not equal") << endl;

	// testing the + operator ... this should print the same graph twice since the 2 graphs are equal
	DAG sum;

	sum=foodChain + foodChain1;

	cout << "\n" << sum;

	//testing the > operator .. should be false since they are equal
	cout << "\n" << (foodChain > foodChain1 ? "foodChain has greater total weight than foodChain1" :
		"foodChain doesn't have greater total weight than foodChain1") << endl;

	// testing the << operator which should call the tostring function
	cout << "\n" << foodChain1;

	// testing the = operator
	DAG foodChain2;

		foodChain2 = foodChain;

	// should be equal since = is used
	cout << "\n" << (foodChain == foodChain2 ? "the graphs are equal" : "the graphs are not equal") << endl;

	// testing the clean function
	foodChain.clean();

	// should not print anything since the graph is cleaned
	cout << foodChain;
	

	// copy constructor test

	DAG copy(foodChain2);

	cout << copy;

	// testing constructor with arguments
	DAG argument(vArray1, 5, eArray1, 5);

	cout << "\n" << argument<<endl;


	// testing leadingPath function
	argument.leadingPath(v4);

	// testing vertexSearch 
	cout << "\nthe given vertex " << (argument.vertexSearch(v4) ? "exists":"doesn't exist")<< " in the graph" << endl;

	
}
void polyphormismTest() {


	// creating 6 nodes
	vertex v1(3, "sun");
	vertex v2(5, "grass");
	vertex v3(7, "grasshopper");
	vertex v4(9, "bird");
	vertex v5(10, "snake");
	vertex v6(13, "fox");

	// creating 5 edges to conncect these nodes
	edge e2(1, v1, v2);
	edge e3(1, v2, v3);
	edge e4(1, v3, v4);
	edge e5(1, v4, v5);
	edge e6(1, v5, v6);

	//putting 5 edges in an array
	edge eArray1[5];

	eArray1[0] = e2;
	eArray1[1] = e3;
	eArray1[2] = e4;
	eArray1[3] = e5;
	eArray1[4] = e6;

	//putting 5 nodes in an array
	vertex vArray1[5];

	vArray1[0] = v2;
	vArray1[1] = v3;
	vArray1[2] = v4;
	vArray1[3] = v5;
	vArray1[4] = v6;

	// default constructor called
	Graph* foodChain=new DAG(vArray1, 5, eArray1, 5);

	//creating vertices
	vertex v11(001, "Ahmad");
	vertex v21(002, "Aly");
	vertex v31(003, "Omar");
	vertex v41(004, "Khaled");
	vertex v51(005, "odai");

	//creating edges
	edge e11(3, v11, v21);
	edge e21(3, v21, v31);
	edge e31(3, v31, v41);
	edge e41(3, v21, v51);
	edge e51(3, v31, v51);


	//putting 5 edges in an array
	edge eArray11[5];

	eArray11[0] = e11;
	eArray11[1] = e21;
	eArray11[2] = e31;
	eArray11[3] = e41;
	eArray11[4] = e51;

	//putting 5 nodes in an array
	vertex vArray11[5];

	vArray11[0] = v11;
	vArray11[1] = v21;
	vArray11[2] = v31;
	vArray11[3] = v41;
	vArray11[4] = v51;


	// testing default constructor 
	Graph* socialNetwork1 =new  undirected(vArray11, 5, eArray11, 5);

	cout << socialNetwork1->toString() << endl << foodChain->toString();
}

void presentation()
{

	// creating 6 nodes
	vertex v1(3, "sun");
	vertex v2(5, "grass");
	vertex v3(7, "grasshopper");
	vertex v4(9, "bird");
	vertex v5(10, "snake");
	vertex v6(13, "fox");

	// creating 5 edges to conncect these nodes
	edge e2(1, v1, v2);
	edge e3(1, v2, v3);
	edge e4(1, v3, v4);
	edge e5(1, v4, v5);
	edge e6(1, v5, v6);

	//putting 5 edges in an array
	edge eArray1[5];

	eArray1[0] = e2;
	eArray1[1] = e3;
	eArray1[2] = e4;
	eArray1[3] = e5;
	eArray1[4] = e6;

	//putting 5 nodes in an array
	vertex vArray1[5];

	vArray1[0] = v2;
	vArray1[1] = v3;
	vArray1[2] = v4;
	vArray1[3] = v5;
	vArray1[4] = v6;

	// default constructor called
	DAG foodChain;



	//testing add vertex function
	cout << "\n" << (foodChain.addVertex(v1) ? "vertex added successfully" : "vertex not added since graph is full or bertex already exists in grapgh") << endl;

	//testing add vertices function
	cout << "\n" << (foodChain.addVertices(vArray1, 5) ? "vertices added successfully" : "vertices not added since the amout of vertices in the array cannot all be held in the graph or the array has a vertex already in the graph") << endl;


	// testing add edge function
	cout << (foodChain.addEdge(e2) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e3) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e4) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e5) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << (foodChain.addEdge(e6) ? "edge added successfully" : "edge not added since graph is full or edge already inside") << endl;
	cout << endl;


	cout << foodChain;


	foodChain.clean();


	cout << foodChain;


}

void undirectedTest() {
	
	//creating vertices
	vertex v1(001, "Ahmad");
	vertex v2(002, "Aly");
	vertex v3(003, "Omar");
	vertex v4(004, "Khaled");
	vertex v5(005, "odai");

	//creating edges
	edge e1(3, v1, v2);
	edge e2(3, v2, v3);
	edge e3(3, v3, v4);
	edge e4(3, v2, v5);
	edge e5(3, v3, v5);


	//putting 5 edges in an array
	edge eArray1[5];

	eArray1[0] = e1;
	eArray1[1] = e2;
	eArray1[2] = e3;
	eArray1[3] = e4;
	eArray1[4] = e5;

	//putting 5 nodes in an array
	vertex vArray1[5];

	vArray1[0] = v1;
	vArray1[1] = v2;
	vArray1[2] = v3;
	vArray1[3] = v4;
	vArray1[4] = v5;
	

	// testing default constructor 
	undirected socialNetwork1;

	// testing constructor with parameters
	undirected socialNetwork2(vArray1,5,eArray1,5);

	// testing copy constructor
	undirected socialNetwork3(socialNetwork2);

	// adding vertices and an edge to test add functions
	socialNetwork1.addVertex(v1);
	socialNetwork1.addVertex(v2);
	socialNetwork1.addEdge(e1);

	// testing add functions and to string ... should print "Ahmad---Aly"
	cout << socialNetwork1.toString();

	// testing add vertices should print second option
	cout<< (socialNetwork1.addVertices(vArray1, 5)?"\nvertex array added successfully": "\narray not added successfully since the graph is full or the graph has vertices in common with th array") ;

	// removing edge and vertices to test remove functions
	socialNetwork1.removeEdge(e1);
	socialNetwork1.removeVertex(v2);
	socialNetwork1.removeVertex(v1);

	// testing remove functions and << operator .. should print nothing
	cout << socialNetwork1;

	// testing search functions
	cout << (socialNetwork2.searchEdge(e1) ? "\ne1 exists in this network" : "\ne1 doesn't exist in this network");
	cout << (socialNetwork2.searchVertex(v1) ? "\nv1 exists in this network" : "\nv1 doesn't exist in this network");


	// testing == operator and if copy constructor works properly they have to be equal
	cout<<(socialNetwork2 == socialNetwork3?"\nnetwork 2 and 3 are equal":"\nnetwork 2 and 3 are not equal");

	// increasing weights of edges in network 1
	socialNetwork2++;

	//testing > opertor and if ++ operator works network 2 should have greater weights
	cout << (socialNetwork2 > socialNetwork3 ? "\nnetwork 2 has more total weight" : "\nnetwork 2 has total weight less than or equal");

	// increasing weights of edges in network 3 prefix
	++socialNetwork3;

	//if prefix works they have to be equal
	cout << (socialNetwork2 == socialNetwork3 ? "\nnetwork 2 and 3 are equal" : "\nnetwork 2 and 3 are not equal");

	// applying = operator
	socialNetwork1 = socialNetwork2;

	// if = opertor is working network 1 and two have to be equal
	cout << (socialNetwork2 == socialNetwork1 ? "\nnetwork 2 and 1 are equal" : "\nnetwork 2 and 1 are not equal")<<endl;

	// this should print the relations of the network twice since that are equal
	// this is a test for the + operator
	cout << socialNetwork2 + socialNetwork1;

	// cleaning social network 2 so all edges and vertices are removed
	socialNetwork2.clean();

	// testing cleann adn vertex search this should give false since network2 is clean
	cout << (socialNetwork2.vertexSearch(v1) ? "\nv1 exists in the network":"\nv1 doesn't exist in the network")<<endl;

	

	
}
int main()
{
	

	//dagTest();

	//undirectedTest();

	//polyphormismTest();

	presentation();

	
}