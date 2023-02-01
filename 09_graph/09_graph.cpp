#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph<long> graph;

	graph.Add(6, { });
	graph.Add(4, { 6 });
	graph.Add(2, { 6, 4 });
	graph.Add(7, { 6, 2 });
	graph.Add(9, { 4 });
	graph.Add(0, { 2 });

	graph.Show();
}