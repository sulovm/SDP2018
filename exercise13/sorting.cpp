#include <iostream>
#include <vector>
#include <queue>

template <typename T>
std::ostream& operator <<(std::ostream& out, const std::vector<T>& v)
{
    if (v.empty() == true)
    {
        out << "[]";
        return out;
    }

    out << "[";

    auto iter = v.begin();
    auto iterAtLast = v.end() - 1;
    for (; iter != iterAtLast; iter++) //to exclude the last element
    {
        out << *iter << ";";
    }
    out << *iterAtLast << "]";
    return out;
}

template <typename T>
void quickSort(std::vector<T>& v)
{
    if (v.empty() == true)
    {
        //if empty - nothing to do
        return;
    }

    if (v.size() == 1)
    {
        //if only 1 element, it is sorted
        //nothing to do
        return;
    }

    if (v.size() == 2)
    {
        //if only 2 elements - put them into order
        if (v[0] > v[1])
        {
            std::swap(v[0], v[1]);
        }
        return;
    }

    T pivot = v[0];

    //split the vector into 2 vectors - one with the elements lesser than the pivot
    //and one with the elements greater than the pivot

    std::vector<T> lesserThanPivot;
    std::vector<T> greaterThanPivot;

    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        if (*iter < pivot)
        {
            lesserThanPivot.push_back(*iter);
        }
        else if (*iter > pivot)
        {
            greaterThanPivot.push_back(*iter);
        }
    }

    //now sort the two vectors
    quickSort(lesserThanPivot);
    quickSort(greaterThanPivot);

    //clear and fill the original vector with the two already sorted vectors
    v.clear();

    v.insert(v.end(), lesserThanPivot.begin(), lesserThanPivot.end());

    v.push_back(pivot);

    v.insert(v.end(), greaterThanPivot.begin(), greaterThanPivot.end());
}

template <typename T>
std::queue<T> makeQueueFromVector(const std::vector<T>& v)
{
    std::queue<T> result;

    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        result.push(*iter);
    }

    return result;
}

template <typename T>
std::vector<T> mergeSorted(const std::vector<T>& v1, const std::vector<T>& v2)
{
    std::queue<T> q1 = makeQueueFromVector(v1);
    std::queue<T> q2 = makeQueueFromVector(v2);

    std::vector<T> result;

    while (q1.empty() == false && q2.empty() == false)
    {
        if (q1.front() < q2.front())
        {
            result.push_back(q1.front());
            q1.pop();
        }
        else  //successfully handles the case when the two fronts are equals
        {
            result.push_back(q2.front());
            q2.pop();
        }
    }

    //we will enter in only one of the two whiles below (because of the while above)
    while (q1.empty() == false)
    {
        result.push_back(q1.front());
        q1.pop();
    }

    while (q2.empty() == false)
    {
        result.push_back(q2.front());
        q2.pop();
    }

    return result;
}

template <typename T>
void mergeSort(std::vector<T>& v)
{
    if (v.empty() == true)
    {
        //if empty - nothing to do
        return;
    }

    if (v.size() == 1)
    {
        //if only 1 element, it is sorted
        //nothing to do
        return;
    }

    if (v.size() == 2)
    {
        //if only 2 elements - put them into order
        if (v[0] > v[1])
        {
            std::swap(v[0], v[1]);
        }
        return;
    }

    //split the vector into two halfs
    auto iterMiddle = v.begin() + v.size() / 2; //iterator pointing at the middle element

    std::vector<T> firstHalf(v.begin(), iterMiddle);
    std::vector<T> secondHalf(iterMiddle, v.end());

    //sort each half (recursively)
    mergeSort(firstHalf);
    mergeSort(secondHalf);

    //clear the original vector and merge the two sorted vectors into it keeping it sorted
    v.clear();

    v = mergeSorted(firstHalf, secondHalf);
}

int main()
{
    std::vector<int> v = {7, 3, 5, 1, 14, 6, 23, 22, 2, 17};
    std::vector<int> v1 = v;

    std::cout << "Original vector: " << v << std::endl;

    quickSort(v);

    std::cout << "Sorted by Quicksort: " << v << std::endl;

    std::cout << std::endl;

    std::cout << "Original vector: " << v1 << std::endl;

    mergeSort(v1);

    std::cout << "Sorted by Mergesort: " << v1 << std::endl;

    return 0;
}
