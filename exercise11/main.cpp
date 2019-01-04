#include <iostream>

#include "GraphV.h"
#include "GraphE.h"
#include "GraphM.h"

using namespace std;

int main()
{
    std::cout << "\n==========================\n\nVector of vectors:\n\n";

    GraphV<int> gv;

    gv.addVertex(1);
    gv.addVertex(2);
    gv.addVertex(3);

    gv.addEdge(1,2);
    gv.addEdge(1,3);

    gv.addEdge(2,3);

    gv.addEdge(3,2);
    gv.print();

    std::cout << "\nCopy of the original graph:\n\n";
    GraphV<int> gv1 = gv;
    gv1.print();

    std::cout << "\nOriginal graph after deletion of the edge (2, 3):\n\n";
    gv.removeEdge(2, 3);
    gv.print();

    std::cout << "\nModified graph after adding of the edge (1, 4):\n\n";
    gv.addEdge(1, 4);
    gv.print();

    std::cout << "\nOriginal graph after deletion of the vertex 3:\n\n";
    gv1.removeVertex(3);
    gv1.print();

    std::cout << "\nModified graph after adding of the edge (5,6):\n\n";
    gv1.addEdge(5,6);
    gv1.print();

    //=====================================================================
    std::cout << "\n==========================\n\nVector of edges:\n\n";

    GraphE<int> ge;

    ge.addVertex(1);
    ge.addVertex(2);
    ge.addVertex(3);

    ge.addEdge(1,2);
    ge.addEdge(1,3);

    ge.addEdge(2,3);

    ge.addEdge(3,2);
    ge.print();

    std::cout << "\nCopy of the original graph:\n\n";
    GraphE<int> ge1 = ge;
    ge1.print();

    std::cout << "\nOriginal graph after deletion of the edge (2, 3):\n\n";
    ge.removeEdge(2, 3);
    ge.print();

    std::cout << "\nModified graph after adding of the edge (1, 4):\n\n";
    ge.addEdge(1, 4);
    ge.print();

    std::cout << "\nOriginal graph after deletion of the vertex 3:\n\n";
    ge1.removeVertex(3);
    ge1.print();

    std::cout << "\nModified graph after adding of the edge (5,6):\n\n";
    ge1.addEdge(5,6);
    ge1.print();

    //=====================================================

    std::cout << "\n==========================\n\nMatrix\n\n";

    GraphM<int> gm;

    gm.addVertex(1);
    gm.addVertex(2);
    gm.addVertex(3);

    gm.addEdge(1,2);
    gm.addEdge(1,3);

    gm.addEdge(2,3);

    gm.addEdge(3,2);
    gm.print();

    std::cout << "\nCopy of the original graph:\n\n";
    GraphM<int> gm1 = gm;
    gm1.print();

    std::cout << "\nOriginal graph after deletion of the edge (2, 3):\n\n";
    gm.removeEdge(2, 3);
    gm.print();

    std::cout << "\nModified graph after adding of the edge (1, 4):\n\n";
    gm.addEdge(1, 4);
    gm.print();

    std::cout << "\nModified graph after adding of the edge (5,6):\n\n";
    gm1.addEdge(5,6);
    gm1.print();

    return 0;
}
