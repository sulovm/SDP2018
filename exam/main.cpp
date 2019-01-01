#include <iostream>

#include "deque.h"
#include "LListIter.h"
#include "Vector.h"
using namespace std;

int main()
{
    Deque<int> deq;
    cout << deq << endl; //empty
    deq.pushBack(5);
    cout << deq << endl; //5
    deq.pushBack(11);
    cout << deq << endl; //5 11
    deq.pushBack(2);
    cout << deq << endl; //5 11 2

    int removed;
    deq.popFront(removed);
    cout << "Removed: " << removed << endl; //5
    cout << deq << endl; //11 2

    deq.pushFront(16);
    cout << deq << endl; //16 11 2
    deq.pushFront(22);
    cout << deq << endl; //22 16 11 2

    Deque<int> deqq = deq;

    cout << "Front: " << deq.getFront() << endl; //22
    cout << deq << endl; //22 16 11 2

    deq.popBack(removed);
    deq.popBack(removed);
    cout << "Removed: " << removed << endl; //11

    cout << deq << endl; //22 16

    cout << "Front: " << deq.getFront() << endl; //22
    cout << deq << endl; //22 16

    deq.pushBack(3);
    cout << deq << endl; //22 16 3
    cout << boolalpha << deq.isEmpty() << endl; //false

    cout << "=================================================\n";

    Deque<int> deq1;
    deq1.pushBack(1);
    deq1.pushBack(2);
    deq1.pushBack(3);
    deq1.pushBack(4);
    cout << deq1 << endl; //1 2 3 4

    Deque<int> deq2;
    deq2.pushFront(234);
    deq2.pushFront(100);
    cout << deq2 << endl; //100 234

    deqq.pushBack(54);
    cout << deqq << endl; //22 16 11 2 54

    //Task 2
    LListIter <Deque <int> > ldeq;
    ldeq.toEnd(deq);
    ldeq.toEnd(deq1);
    ldeq.toEnd(deq2);
    ldeq.toEnd(deqq);
    cout << ldeq << endl;
    ldeq.sort();
    cout << ldeq << endl;

    //Task 3 (bonus)
    Vector<int> v;
    LListIter <Deque <int> >::Iterator iter;
    for (iter = ldeq.begin(); iter != ldeq.end(); iter++)
    {
        int frontElem = (*iter).getFront();
        int rearElem = (*iter).getBack();
        double avg = (frontElem + rearElem) / 2.0;

        if (frontElem < avg)
        {
            v.pushBack(frontElem);
        }
        else
        {
            v.pushBack(rearElem);
        }
    }

    //the last one
    iter = ldeq.end();
    int frontElem = (*iter).getFront();
    int rearElem = (*iter).getBack();
    double avg = (frontElem + rearElem) / 2.0;

    if (frontElem < avg)
    {
        v.pushBack(frontElem);
    }
    else
    {
        v.pushBack(rearElem);
    }

    cout << v << endl;

    return 0;
}
