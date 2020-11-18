#define MAX 100
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Graph
{
	int num_vertices; // number of vertices
	int adjacency_matrix[MAX][MAX]; // adjacency matrix
};Graph CreateGraphFromFile(string f);
