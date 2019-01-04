#ifndef COMMONVECTOR_H_INCLUDED
#define COMMONVECTOR_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream& operator << (std::ostream& out, const std::pair<T, T>& p)
{
    out << "(" << p.first << ";" << p.second << ")";
}

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v)
{
    int sizeOfVector = v.size();

    if (sizeOfVector == 0)
    {
        out << "[]";
        return out;
    }

    out << "[";

    for (int i = 0; i < sizeOfVector - 1; i++)
    {
        out << v[i] << ";";
    }

    out << v[sizeOfVector - 1] << "]";
}

template<typename T>
bool vectorContainsValue(std::vector<T>& v, const T& value)
{
    typename std::vector<T>::iterator iter = std::find(v.begin(), v.end(), value);

    return iter != v.end();

    //return std::find(v.begin(), v.end(), value) != v.end(); - shortened statement
}

template<typename T>
void removeValueFromVector(std::vector<T>& v, const T& value)
{
    // https://www.fluentcpp.com/2018/09/14/how-to-remove-elements-from-a-sequence-container/

    //std::remove removes the elements and shifts the remaining to the left but does not change the size of the vector
    //unspecified elements (as many as the elements removed) remain at the end of the vector
    //std::remove also returns an iterator to the new past-the-end element - right after the last non-removed element
    //that's why we use std::vector::erase to delete the unspecified elements at the end of the vector

    //example: we have vector: 1, 2, 1, 3, 1, 4; we remove 1; new content: 2, 3, 4, ?, ?, ?;
    //std::remove has returned an iterator pointing at the first '?'
    //with std::vector::erase we completely delete the '?' elements (thus updating the size)

    typename std::vector<T>::iterator newEndIter = std::remove(begin(v), end(v), value);
    v.erase(newEndIter, end(v));
//    v.erase(std::remove(begin(v), end(v), value), end(v)); - shortened statement
}

#endif // COMMONVECTOR_H_INCLUDED
