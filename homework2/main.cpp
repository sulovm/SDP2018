#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Trie.h"
using namespace std;

bool comparator (pair<string, int> p1, pair<string, int> p2) //for the sort
{
    return p1.second > p2.second;
}

//Task 2
void task2()
{
    Trie trie;
    cout << "Task 2:\nEnter text:\n";

    string word;
    while (cin>>word) //only words without white characters
    {
        trie.addWord(word);
    }

    vector<string> words = trie.getSuggestions("");
    vector <pair<string, int> > counted;
    int numberOfWords = words.size();
    for (int i = 0; i < numberOfWords; i++)
    {
        pair<string, int> p(words[i], trie.getValue(words[i]));
        counted.push_back(p);
    }
    cout << "All words:\n";
    for (int i = 0; i < numberOfWords; i++)
    {
        cout << counted[i].first << ": " << counted[i].second << endl;
    }

    sort(counted.begin(), counted.end(), comparator);

    int wantedNumberOfWords = (numberOfWords < 10 ? numberOfWords : 10);
    cout << "\nThe " << wantedNumberOfWords << " most common words:\n";
    for (int i = 0; i < wantedNumberOfWords; i++)
    {
        cout << counted[i].first << endl;
    }

}

int main()
{
    task2();
    return 0;
}
