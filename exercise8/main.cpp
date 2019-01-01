#include <iostream>
#include "PriorityQueue.h"
using namespace std;

int main()
{
    PriorityQueue<int> pq;

    pq.push(5);
    cout << pq; //5
    pq.push(16);
    cout << pq; //16 5
    pq.push(14);
    pq.push(22);
    pq.push(7);
    pq.push(11);
    pq.push(3);
    cout << pq;
    cout << "Size: " << pq.getSize() << endl; //7

    PriorityQueue<int> pq1 = pq;
    cout << "Size of the new PQ: " << pq1.getSize() << endl; //7

    cout << "Top: " << pq.top() << endl; //22
    pq.pop();
    cout << "Top: " << pq.top() << endl; //16
    pq.pop();
    cout << "Top: " << pq.top() << endl; //14
    pq.pop();
    cout << "Top: " << pq.top() << endl; //11
    pq.pop();
    cout << "Top: " << pq.top() << endl; //7
    pq.pop();
    cout << pq; //5 3

    cout << "Empty? " << boolalpha << pq.isEmpty() << endl; //false
    cout << "Size: " << pq.getSize() << endl; //2

    pq = pq1;
    cout << "Top: " << pq.top() << endl; //22
    pq.pop();
    cout << "Size: " << pq.getSize() << endl; //6

    return 0;
}
