// GraphWithSTL.cpp
// Graph with adjacency list implementation using STL.
//

#include <iostream>
#include <vector>

struct Edge
{
    int src;
    int dest;
};

class Graph
{
public:
    // Constructor.
    Graph(std::vector<Edge> const &edges, int N)
    {
        // Resize the vector as per the length.
        adjList.resize(N);

        for (auto& edge : edges)
        {
            // Insert at the end.
            adjList[edge.src].push_back(edge.dest);
        }
    }

    // Print the adjacency list.
    void PrintGraph()
    {
        for (uint16_t i = 0; i < adjList.size(); ++i)
        {
            std::cout << i << "------->";

            // print all the adjacent verticies.
            for (auto adjEdge : adjList[i])
            {
                std::cout << adjEdge << " ";
            }

            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> adjList;
};


int main()
{
    std::vector<int> a(20);

    for (int i = 0; i < 20; ++i)
    {
        a.push_back(i);
    }

    a.resize(25);

    for (int i = 20; i < 25; ++i)
    {
        a.push_back(i*2);
    }

    /*

    // Vector of the graph edges.
    std::vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1},
        {3, 2}, {4, 5}, {5, 4}
    };

    int N = 6;
    
    // Construct graph.
    Graph graph(edges, N);

    // Print the graph.
    graph.PrintGraph();
    */

    return 0;

}
