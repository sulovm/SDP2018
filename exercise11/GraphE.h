#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <vector>
#include "commonVector.h"

template <typename T>
class GraphE
{
    std::vector<T> vertexes;
    std::vector< std::pair<T, T> > edges;
public:
    void addVertex(const T& vID);
    void addEdge(const T& firstID, const T& lastID);
    void addEdgeDirectly(const T& beginID, const T& endID);
    void removeEdge(const T& beginID, const T& engID);
    void removeVertex(const T& vertexID);
    void print();
};

template <typename T>
void GraphE<T>::addVertex(const T& vID)
{
    //If no such vertex, add it to the vector of vertexes
    if (std::find(vertexes.begin(), vertexes.end(), vID) == vertexes.end())
    {
        vertexes.push_back(vID);
    }
//    else //optional
//    {
//        //error message (or similar handling)
//    }
}

template <typename T>
void GraphE<T>::addEdge(const T& beginID, const T& endID)
{
//  if there is no vertex with the given beginning ID, add it to the vector of vertexes
    if (std::find(vertexes.begin(), vertexes.end(), beginID) == vertexes.end())
    {
        vertexes.push_back(beginID);
    }

//  if there is no vertex with the given ending ID, add it to the vector of vertexes
    if (std::find(vertexes.begin(), vertexes.end(), endID) == vertexes.end())
    {
        vertexes.push_back(endID);
    }

//  if there is no edge with the given beginning and ending ID, add it to the vector of edges
    std::pair<T, T> edge(beginID, endID);

    if (std::find(edges.begin(), edges.end(), edge) == edges.end()) //equal to end - no such element!
    {
        edges.push_back(edge);
    }
//    else //optional
//    {
//        //error message (or similar handling)
//    }
}

template <typename T>
void GraphE<T>::removeEdge(const T& beginID, const T& endID)
{
    //  if there is an edge with the given beginning and ending ID, remove it from the vector of edges
    std::pair<T, T> p = std::make_pair(beginID, endID);

    typename std::vector< std::pair<T, T> >::iterator iter =
        std::find(edges.begin(), edges.end(), p);

    if (iter != edges.end()) //different from end - there is such an element!
    {
        edges.erase(iter);
    }
}

template <typename T>
void GraphE<T>::removeVertex(const T& vID)
{
    removeValueFromVector(vertexes, vID);

    //Now we have to remove all edges which start or end in the removed vertex
    typename std::vector< std::pair<T, T> >::iterator iter = edges.begin();

    while (iter != edges.end())
    {
        if ((*iter).first == vID || (*iter).second == vID)
        {
            iter = edges.erase(iter); //erase returns an iterator pointing to the element after the deleted one
        }
        else
        {
            iter++; //we should increase the iterator only if the current element has not been deleted
        }
    }

    //this solution is not very efficient; it would be better with more advanced functions such as std::remove_if
}

template <typename T>
void GraphE<T>::print()
{
    std::cout << "Vertexes: "<< vertexes << std::endl;
    std::cout << "\nEdges: " << edges << std::endl;
}

#endif // GRAPHE_H_INCLUDED
