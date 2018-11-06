#include <iostream>
#include "LListIter.h"
using namespace std;

template <typename T, typename U>
LListIter<U> map(LListIter<T> inputList, U (*mapping_func)(T input))
{
    LListIter<U> resultList;

    typename LListIter<T>::Iterator i = inputList.begin();
    while (i != inputList.end())
    {

        T t = *i;
        U u = mapping_func(t);
        resultList.toEnd(u);
        //resultList.toEnd(mapping_func(*i));
        i++;
    }
    //for the last one, which is excluded by the previous loop
    resultList.toEnd(mapping_func(*inputList.end()));

    return resultList;
}

template <typename T, typename U>
U reduce(LListIter<T> inputList, void (*reducing_func)(U& result, T input), U initial_value)
{
    U result = initial_value;

    typename LListIter<T>::Iterator i = inputList.begin();
    while (i != inputList.end())
    {
        reducing_func(result, *i);
        //result = reducing_func(result, *i);
        i++;
    }
    //for the last one, which is excluded by the previous loop
    reducing_func(result, *inputList.end());

    return result;
}

template <typename T>
LListIter<T> filter(LListIter<T> inputList, bool (*filtering_func)(T input))
{
    LListIter<T> resultList;

    typename LListIter<T>::Iterator i = inputList.begin();
    while (i != inputList.end())
    {
        if (filtering_func(*i) == true)
        {
            resultList.toEnd(*i);
        }
        i++;
    };
    //for the last one, which is excluded by the previous loop
    if (filtering_func(*inputList.end()) == true)
    {
        resultList.toEnd(*inputList.end());
    }

    return resultList;
}

int square(int x)
{
    return x * x;
}

bool moreThanTen(int x)
{
    return x > 10;
}

void add(int& sum, int x)
{
    sum += x;
}

int main()
{
    LListIter<int> l;
    l.toEnd(12);
    l.toEnd(1);
    l.toEnd(7);
    l.toEnd(15);
    l.toEnd(28);
    l.toEnd(5);
    l.toEnd(3);
    l.toEnd(54);
    l.toEnd(11);

    cout << "original list:\n";
    cout << l << endl;

    LListIter<int> l_squares = map(l, square);

    cout << "list of squares:\n";
    cout << l_squares << endl;

    int sum = reduce(l, add, 0);

    cout << "sum of the elements:\n";
    cout << sum << endl;

    LListIter<int> l_more_than_10 = filter(l, moreThanTen);

    cout << "only greater than 10:\n";
    cout << l_more_than_10 << endl;

    return 0;
}
