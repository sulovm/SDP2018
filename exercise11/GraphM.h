#ifndef GRAPHM_H_INCLUDED
#define GRAPHM_H_INCLUDED

template <typename T>
class GraphM
{
    static const int MAX = 10;

    T vertexes[MAX];
    int matrix[MAX][MAX];

    int vertexCount;
public:
    GraphM();

    void addVertex(const T& vID);
    void addEdge(const T& firstID, const T& lastID);
    void removeEdge(const T& beginID, const T& engID);
    //no remove vertex - it will become too complicated
    void print();
private:
    int findVertexIndex(const T& vID);
};

template <typename T>
GraphM<T>::GraphM(): vertexCount(0)
{
    //initialize the matrix with 0s
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

template <typename T>
void GraphM<T>::addVertex(const T& vID)
{
    if (vertexCount >= MAX)
    {
        //no space - error handling or do nothing
        return;
    }

    if (findVertexIndex(vID) != -1)
    {
        //there is already a vertex with this ID
        //error handling or do nothing
        return;
    }

    vertexes[vertexCount] = vID;
    vertexCount++;
}

template <typename T>
void GraphM<T>::addEdge(const T& beginID, const T& endID)
{
    int indexBegin = findVertexIndex(beginID);

    if (indexBegin == -1)
    {
        //no vertex with ID == beginID
        indexBegin = vertexCount;
        vertexes[indexBegin] = beginID;
        vertexCount++;
    }

    int indexEnd = findVertexIndex(endID);

    if (indexEnd == -1)
    {
        //no vertex with ID == endID
        indexEnd = vertexCount;
        vertexes[indexEnd] = endID;
        vertexCount++;
    }

    if (matrix[indexBegin][indexEnd] == 1)
    {
        //such an edge already exists
        //error handling or do nothing
        return;
    }

    matrix[indexBegin][indexEnd] = 1;
}

template <typename T>
void GraphM<T>::removeEdge(const T& beginID, const T& endID)
{
    int indexBegin = findVertexIndex(beginID);
    int indexEnd = findVertexIndex(endID);

    if (indexBegin == -1 || indexEnd == -1)
    {
        //at least one of the vertexes does not exist
        //error handling or do nothing
        return;
    }

    if (matrix[indexBegin][indexEnd] == 0)
    {
        //no such edge
        //error handling or do nothing
        return;
    }

    matrix[indexBegin][indexEnd] = 0;
}

template <typename T>
int GraphM<T>::findVertexIndex(const T& vID)
{
    for (int i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == vID)
        {
            return i;
        }
    }

    return -1; //the vertex is not found
}

template <typename T>
void GraphM<T>::print()
{
    std::cout << "Vertexes: ";

    for (int i = 0; i < vertexCount; i++)
    {
        std::cout << vertexes[i] << " ";
    }

    std::cout << "\nMatrix:\n";

    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

#endif // GRAPHM_H_INCLUDED
