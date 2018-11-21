#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAZE_W 5
#define MAZE_H 5

int maze[MAZE_W][MAZE_H] = {0,1,0,0,0,
             	      		0,1,0,1,0,
			                0,1,0,1,0,
		                	0,0,0,1,0,
		                	1,1,1,1,0};
bool correct (int x, int y)
{
	return x >=0 && x < MAZE_W &&
	       y >=0 && y < MAZE_H &&
	       maze[x][y] == 0;
}
bool way (int x, int y, int targetX, int targetY)
{
	if (!correct (x,y))
		return false;

	if (x == targetX && y == targetY)
		return true;

	maze[x][y] = 2;

	return way (x,y-1,targetX,targetY) ||
		   way (x-1,y,targetX, targetY) ||
		   way (x+1,y,targetX,targetY) ||
		   way (x,y+1,targetX,targetY);
}

vector<pair<int, int> > findWayRec (int x, int y, int targetX, int targetY)
{
	vector<pair<int, int> > result;

	if (!correct (x,y))
		//return an empty path: no path exists
		return result;

	result.push_back (pair<int,int>(x,y));

	if (x == targetX && y == targetY)
		return result;

	maze[x][y] = 2;

	vector<pair<int, int> > nextSteps;

	nextSteps = findWayRec (x,y-1,targetX,targetY);
	if (nextSteps.size () == 0)
		nextSteps = findWayRec (x-1,y,targetX, targetY);
	if (nextSteps.size () == 0)
		nextSteps = findWayRec (x+1,y,targetX,targetY);
	if (nextSteps.size () == 0)
		nextSteps = findWayRec (x,y+1,targetX,targetY);

	if (nextSteps.size() > 0)
	{
		nextSteps.push_back (pair<int,int>(x,y));
		return nextSteps;
	}

	return nextSteps;
}

vector <pair <int, int> > shortest (int x, int y, int targetX, int targetY, vector <pair <int, int> > min)
{
	vector<pair<int, int> > result;

	if (!correct (x,y))
    {
        return min;
    }

	result.push_back (pair<int,int>(x,y));

	if (x == targetX && y == targetY)
    {
        if (result.size() < min.size()) min = result;
        return min;
    }

	maze[x][y] = 2;

	vector<pair<int, int> > nextSteps;

	nextSteps = shortest (x,y-1,targetX,targetY, min);
	if (nextSteps.size () == 0)
		nextSteps = shortest (x-1,y,targetX, targetY, min);
	if (nextSteps.size () == 0)
		nextSteps = shortest (x+1,y,targetX,targetY, min);
	if (nextSteps.size () == 0)
		nextSteps = shortest (x,y+1,targetX,targetY, min);

	if (nextSteps.size() > 0)
	{
		nextSteps.push_back (pair<int,int>(x,y));
		return nextSteps;
	}

	return nextSteps;
}

vector <pair <int, int> > shortestWay (int x, int y, int targetX, int targetY)
{
    vector <pair <int, int> > min = findWayRec (x, y, targetX, targetY);
    return shortest (x, y, targetX, targetY, min);
}

bool wayIter (int x, int y, int targetX, int targetY)
{

	stack<pair<int,int> >s;

	s.push (pair<int,int> (x,y));

	while (!s.empty() &&
		   (s.top().first != targetX ||
		   	s.top().second != targetY))
	{
		pair<int,int> current = s.top();
		s.pop();

		maze[current.first][current.second]=2;

		if (correct (current.first,current.second-1))
			s.push (pair<int,int> (current.first,current.second-1));
		if (correct (current.first-1,current.second))
			s.push (pair<int,int> (current.first-1,current.second));
		if (correct (current.first+1,current.second))
			s.push (pair<int,int> (current.first+1,current.second));
		if (correct (current.first,current.second+1))
			s.push (pair<int,int> (current.first,current.second+1));

	}

	return !s.empty();
}

void hanoi (int fromPile, int toPile, int tempPile, int k)
{

	if (k == 1)
	{
		cout << "Please move the top disk from " << fromPile << " to " << toPile << endl;
		return;
	}

	hanoi (fromPile,tempPile,toPile,k-1);
	hanoi (fromPile,toPile,tempPile,1);
	hanoi (tempPile,toPile,fromPile,k-1);

}

struct fourInts
{
    int first, second, third, k;
    fourInts (int f, int s, int t, int kk) : first(f), second(s), third(t), k(kk) {}
};

void hanoiIter (int fromPile, int toPile, int tempPile, int k)
{
    stack <fourInts> s;
    s.push (fourInts (fromPile, toPile, tempPile, k));

    while (!s.empty())
    {
        fourInts current = s.top();
        s.pop();

        if (current.k == 1) cout << "Please move the top disk from " << current.first << " to " << current.second << endl;
        else
        {
            s.push (fourInts (current.third, current.second, current.first, current.k - 1));
            s.push (fourInts (current.first, current.second, current.third, 1));
            s.push (fourInts (current.first, current.third, current.second, current.k - 1));
        }
    }
}

template <class T>
vector<T> tail (const vector<T> &v)
{
	vector<T> result = v;
	result.erase (result.begin());
	return result;
}

void printWay (const vector<pair<int, int> > &way)
{
	if (way.size() == 0) //(null? way)
		return;

	cout << "["
	     << way[0].first
	     << ","
	     << way[0].second
	     << "]"; //car way

	printWay (tail(way)); //cdr way
}

int main ()
{
    return 0;
}
