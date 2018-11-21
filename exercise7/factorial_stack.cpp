#include <iostream>
#include <stack>
using namespace std;

unsigned factorial (unsigned number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    return number * factorial (number - 1);
}

unsigned factIter (unsigned number)
{
    stack<unsigned> st;
    st.push(number);
    unsigned product = 1;
    while (!st.empty())
    {
        unsigned current = st.top();
        cout << "current: " << current << endl;
        product *= current;
        st.pop();
        if (current != 1 && current != 0)
        {
            st.push(current - 1);
        }
    }
    return product;
}

int main()
{

    return 0;
}
