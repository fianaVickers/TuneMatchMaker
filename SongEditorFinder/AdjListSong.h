//
// Created by fiana on 12/7/2021.
//

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>

// random generator function:
int myrandom(int i) { return std::rand() % i; }
using namespace std;
struct Song
{
private:
    string id;
    string name;
    string album;
    string albumId;
    string year;
    string release_date;
    int track_number;
    Song* next;
public:
    Song(string id, string name, string album, string albumId,
         string year, string release_date) {
        this->id = id;
        this->name = name;
        this->album = album;
        this->albumId = albumId;
        this->year = year;
        this->release_date = release_date;
        this->next = nullptr;
    }
    string get_id() { return id; };
    string get_name() { return name; };
    string get_album() { return album; };
    string get_albumId() { return albumId; };
    string get_year() { return year; };
    string get_release_date() { return release_date; };
    int get_track_number() { return track_number; };
    // Song* set_next(Song* next) { this->next = next; };
};

/*EDGE LIST CODE*/
// ***** EDGE LIST CODE *****

class EdgeList
{
private:
    set<vector<int>> edgeList; //The edgeList is a set of vectors containing 3 int values: to, from, weight
    vector<Song*> songList;
    int sourceIndex;
    int V;
    vector<Song*> likeMusic;
public:
    EdgeList(vector<Song*> list, string targetName);
    ~EdgeList();
    vector<Song*> get_songList();
    int get_V();
    int get_sourceIndex();
    void insertEdge(int from, int to, int weight);
    vector<int> getAdjacent(int index);
    map<int, struct Song *> traverse();
    vector<Song*> traverseOrder();
};

//Constructor of the EdgeList that searches for the targetName and builds a graph of all the songs of the target song artist
EdgeList::EdgeList(vector<Song*> list, string targetName)
{
    int index;
    for (int i = 0; i < list.size(); i++)
    {
        //Finding the searched song and storing its index
        if (list[i]->get_name() == targetName) {
            index = i;
        }
    }
    //Now, creating a graph of all songs of the same artist
    this->V = list.size();
    this->songList = list;
    this->sourceIndex = index;

    set<vector<int>> EdgeSet;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j) //Check to make sure we are not adding an edge from the song to itself
            {
                vector<int> newIndexes;
                newIndexes.push_back(i);
                newIndexes.push_back(j);

                //Creating the same pair but with the vertex inversed to test if the edge already exists
                vector<int> opposite;
                opposite.push_back(j);
                opposite.push_back(i);

                if (list[i]->get_album() == list[j]->get_album())
                {
                    newIndexes.push_back(1);
                    //Creating the same pair but with the vertex inversed to test if the edge already exists
                    opposite.push_back(1);

                    if (EdgeSet.find(opposite) == EdgeSet.end()) //If the does not already exist, add the edge
                        EdgeSet.insert(newIndexes);
                }
                else if (list[i]->get_album() != list[j]->get_album())
                {
                    newIndexes.push_back(2);
                    opposite.push_back(2);

                    if (EdgeSet.find(opposite) == EdgeSet.end()) //If the does not already exist, add the edge
                        EdgeSet.insert(newIndexes);
                }
            }
        }
    }

    this->edgeList = EdgeSet;
}

EdgeList::~EdgeList()
{

}
vector<Song*> EdgeList::get_songList()
{
    return songList;
}
int EdgeList::get_V()
{
    return V;
}
int EdgeList::get_sourceIndex()
{
    return sourceIndex;
}
void EdgeList::insertEdge(int from, int to, int weight)
{
    if (from != to)
    {
        vector<int> newIndexes;
        newIndexes.push_back(from);
        newIndexes.push_back(to);
        newIndexes.push_back(weight);

        vector<int> opposite;
        opposite.push_back(to);
        opposite.push_back(from);
        opposite.push_back(weight);

        //Because it is an undirected graph, we need to make sure the edges are not repeated
        if (edgeList.find(opposite) == edgeList.end()) //If the edge does not already exist, add the edge
            edgeList.insert(newIndexes);
    }
}
vector<int> EdgeList::getAdjacent(int index)
{
    vector<int> adjacents;
    //Using an iterator to traverse the set
    auto iter = edgeList.begin();
    for (; iter != edgeList.end(); ++iter)
    {
        vector<int> print = *iter;
        if(print[0] == index) //Add if the edge is added from - to
            adjacents.push_back(print[1]);
        else if(print[1] == index) // Add if the edge is added to - from
            adjacents.push_back(print[0]);
    }
    return adjacents;
}
map<int, Song*> EdgeList::traverse()
{
    srand(unsigned(time(0))); //Using the random generator to not alphabetically present choices to user
    vector<int> visited;
    vector<int> q;
    visited.push_back(sourceIndex);
    q.push_back(sourceIndex);
    map<int, Song*> songMap;
    cout << "BFS:";
    int cnt = 0;
    while (q.size() != 0)
    {
        int u = q[0];
        //cout << songList[u]->get_name() << endl;
        songMap[u] = songList[u];
        cnt++;
        q.erase(q.begin());
        vector<int> neigbors = getAdjacent(u);
        random_shuffle(q.begin(), q.end(), myrandom); //The random generator makes the traversal not alphabetical
        for (int i = 0; i < neigbors.size(); i++)
        {
            if (!count(visited.begin(), visited.end(), i))
            {
                if (neigbors[i] != 0)
                {
                    visited.push_back(i);
                    q.push_back(i);
                }
            }
        }
    }
    return songMap;
}
//Function traverseOrder returns a vector containing Song object pointers in the BFS traversal random order
vector<Song*> EdgeList::traverseOrder()
{
    vector<Song*> result;
    srand(unsigned(time(0))); //Using the random generator to not alphabetically present choices to user
    vector<int> visited;
    vector<int> q;
    visited.push_back(sourceIndex);
    q.push_back(sourceIndex);
    cout << "BFS:";
    int cnt = 0;
    while (q.size() != 0)
    {
        int u = q[0];
        //cout << songList[u]->get_name() << endl;
        result.push_back(songList[u]);
        cnt++;
        q.erase(q.begin());
        vector<int> neigbors = getAdjacent(u);
        random_shuffle(q.begin(), q.end(), myrandom); //The random generator makes the traversal not alphabetical
        for (int i = 0; i < neigbors.size(); i++)
        {
            if (!count(visited.begin(), visited.end(), i))
            {
                if (neigbors[i] != 0)
                {
                    visited.push_back(i);
                    q.push_back(i);
                }
            }
        }
    }
    return result;
}

/* AJDLIST CODE*/
class AdjList
{
private:
    vector<vector<int>> edgeMatrix;
    vector<Song*> songList;
    int sourceIndex;
    int V;
    vector<Song*> likeMusic;
public:
    AdjList(vector<Song*> list, string targetName);
    ~AdjList();
    vector<Song*> get_songList();
    int get_V();
    int get_sourceIndex();
    void insertEdge(int from, int to, int weight);
    //bool isEdge(int from, int to);
    //int getWeight(int from, int to);
    vector<int> getAdjacent(int index);
    //void printGraph();
    map<int, struct Song *> traverse();
};
AdjList::AdjList(vector<Song*> list,string targetName)
{
    int index;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->get_name() == targetName) {
            index = i;
        }
    }
    this->V = list.size();
    this->songList = list;
    this->sourceIndex = index;
    vector<vector<int>> matrix;
    for (int i = 0; i < V; i++) {
        vector<int> newlist(V,0);
        for (int j = 0; j < V; j++) {
            if (i!=j && list[i]->get_album() == list[j]->get_album()) {
                newlist[j] = 1;
            }
            else if (i != j && list[i]->get_album() != list[j]->get_album()) {
                newlist[j] = 2;
            }
        }
        //cout<<newlist.size() << endl;
        matrix.push_back(newlist);
    }
    this->edgeMatrix = matrix;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
           // cout<< matrix[i][j]<<" ";
        }
        cout << endl;
    }
    //cout << matrix.size() << endl;
}
AdjList::~AdjList()
{
}
vector<Song*> AdjList::get_songList(){
    return songList;
}
int AdjList::get_V(){
    return V;
}
int AdjList::get_sourceIndex() {
    return sourceIndex;
}
void AdjList::insertEdge(int from, int to, int weight) {

}
vector<int> AdjList::getAdjacent(int index) {
    vector<int> weightList = edgeMatrix[index];
    return weightList;
}
map<int, Song*> AdjList::traverse() {
    srand(unsigned(time(0)));
    vector<int> visited;
    vector<int> q;
    map<int, Song*> songsMap;
    visited.push_back(sourceIndex);
    q.push_back(sourceIndex);
    cout << "BFS:";
    int cnt = 0;
    while (q.size()!=0)
    {
        int u = q[0];
       // cout << songList[u]->get_name() << endl;
        songsMap[u] = songList[u];

        cnt++;
        q.erase(q.begin());
        vector<int> neigbors = getAdjacent(u);
        random_shuffle(q.begin(), q.end(), myrandom);
        for(int i=0;i<neigbors.size();i++)
        {
            if (!count(visited.begin(),visited.end(),i))
            {
                if (neigbors[i]!=0)
                {
                    visited.push_back(i);
                    q.push_back(i);
                }
            }
        }
    }
    return songsMap;
}






