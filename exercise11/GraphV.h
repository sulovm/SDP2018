#ifndef GRAPHV_H_INCLUDED
#define GRAPHV_H_INCLUDED

#include <vector>
#include "commonVector.h"

template <typename T>
struct Node
{
    T vertexID;
    std::vector<T> adjacentVertexes;

    Node(T vID): vertexID(vID) {}

    bool operator == (const Node& other)  //for the std::find function
    {
        return vertexID == other.vertexID;
    }
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Node<T>& node)
{
    out << node.vertexID << " -> " << node.adjacentVertexes;
}

template <typename T>
class GraphV
{
    std::vector< Node<T> > vertexes;
public:
    void addVertex(const T& vID);
    void addEdge(const T& beginID, const T& endID);
    void removeEdge(const T& beginID, const T& engID);
    void removeVertex(const T& vertexID);
    void print();
};

template <typename T>
void GraphV<T>::addVertex(const T& vID)
{
    Node<T> node(vID);

    //search for the given node
    typename std::vector<Node <T> >::iterator iter = std::find(vertexes.begin(), vertexes.end(), node);

    //if there is no such vertex, add it to the vector
    if (iter == vertexes.end())
    {
        vertexes.push_back(node);
    }
//    else //optional
//    {
//        //error message (or similar handling)
//    }
}

template <typename T>
void GraphV<T>::addEdge(const T& beginID, const T& endID)
{
    Node<T> beginNode(beginID); //for the searching
    Node<T> endNode(endID);     //for the searching

    //search for the beginning node
    typename std::vector<Node <T> >::iterator iter = std::find(vertexes.begin(), vertexes.end(), beginNode);

    if (iter == vertexes.end())
    {
        //there is no vertex with the given beginning ID -
        //add such node and add the given ending ID to its vector of adjacent vertexes
        beginNode.adjacentVertexes.push_back(endID);
        vertexes.push_back(beginNode);
    }
    else
    {
        //vertex with the given beginning ID is found -
        //add the given ending ID to its vector of adjacent vertexes
        (*iter).adjacentVertexes.push_back(endID);
    }

    //if there is no node for the given ending ID, we should add it to the vector of vertexes
    iter = std::find(vertexes.begin(), vertexes.end(), endNode);
    if (iter == vertexes.end())
    {
        vertexes.push_back(endNode);
    }
}

template <typename T>
void GraphV<T>::removeEdge(const T& beginID, const T& endID)
{
    //search for the beginning node
    typename std::vector<Node <T> >::iterator iter = std::find(vertexes.begin(), vertexes.end(), Node<T>(beginID));
    if (iter == vertexes.end())
    {
        //no vertex with the given beginning ID - raise error or do nothing, just return
        return;
    }

    //if such vertex is found, remove the given ending ID from its vector of adjacent vertexes
    typename std::vector<T>::iterator iterAdjacent =
        std::find((*iter).adjacentVertexes.begin(), (*iter).adjacentVertexes.end(), endID);

    if (iterAdjacent == (*iter).adjacentVertexes.end())
    {
        //no vertex with the given ending ID is found amongst the adjacent vertexes of the current one -
        //raise error or do nothing, just return
        return;
    }

    //if such adjacent vertex is found, remove it
    (*iter).adjacentVertexes.erase(iterAdjacent);
}

template <typename T>
void GraphV<T>::removeVertex(const T& vertexID)
{
    //search for the node
    typename std::vector<Node <T> >::iterator iter = std::find(vertexes.begin(), vertexes.end(), Node<T>(vertexID));

    if (iter == vertexes.end())
    {
        //no such vertex - raise error or do nothing, just return
        return;
    }

    //there is such vertex - remove it
    vertexes.erase(iter);

    //then remove the given ID from all vertexes' vectors with adjacent vertexes
    for (iter = vertexes.begin(); iter != vertexes.end(); iter++)
    {
        removeValueFromVector((*iter).adjacentVertexes, vertexID);
    }
}

template <typename T>
void GraphV<T>::print()
{
    typename std::vector<Node <T> >::iterator iter;

    for (iter = vertexes.begin(); iter != vertexes.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
}


#endif // GRAPHV_H_INCLUDED
