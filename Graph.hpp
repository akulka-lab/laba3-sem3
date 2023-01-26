#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace::std;


template <typename T>
struct Edge
{
    int v, w;
    T weight;
};

template <typename T>
class Graph
{
    int Vg, Eg;
    bool orient;
    vector<vector<T>> adj;
public:
    Graph();
    Graph(int vertex, bool);
    Graph(vector<Edge<T>> const &edges, int vertex, bool orient);
//    ~Graph();
    int V() const {return Vg;};
    int E() const {return Eg;};
    bool directed() const {return orient;};
    int insert (Edge<T>);
    int remove (Edge<T>);
    bool edge (int,int);
    void printGraph();
    void showGraph();
    list<int> * DFS(int start);
    vector<T> * BFS(int start, int end);
    class adjIterator
    {
    public:
        adjIterator(const Graph &, int);
        int begin();
        int next();
        int end();
    };
};

template <typename T>
Graph<T>::Graph() : Vg(5), Eg(0), orient(false)
{
    adj.resize(5);
    for (int i =0; i < Vg; i++)
        adj[i].assign(Vg, 0);
}

template <typename T>
Graph<T>::Graph(int V, bool orient) : Vg(V), Eg(0), orient(orient)
{
    adj.resize(V);
    for (int i =0; i < V; i++)
        adj[i].assign(V, 0);
}

template <typename T>
Graph<T>::Graph(vector<Edge<T>> const &edges, int n, bool orient) : Eg(0), orient (orient), Vg(n)
{
    int vertex;
    vertex = n;
    adj.resize(vertex);
    for (int i =0; i < n; i++)
        adj[i].assign(n, 0);
    for (auto & edge: edges)
        this->insert(edge);
        
}





template <typename T>
int Graph<T>::insert(Edge<T> e)
{
    if ((e.w >= Vg) or (e.v >= Vg) or (e.v < 0) or (e.w <0))
        return -1;
    int v = e.v;
    int w = e.w;
    if (adj[v][w] == 0)
        Eg++;
    adj[v][w] = e.weight;
    if (orient == false)
        adj[w][v] = e.weight;
    return 0;
}

template <typename T>
int Graph<T>::remove(Edge<T> e)
{
    if (e.w > Vg or e.v > Vg or e.v < 0 or e.w <0)
        return -1;
    int v = e.v;
    int w = e.w;
    if (adj[v][w] != 0)
        Eg--;
    adj[v][w] = 0;
    if (orient == false)
        adj[w][v] = 0;
    return 0;
}

template <typename T>
bool Graph<T>::edge(int v, int w)
{
    if (adj[v][w] != 0)
        return true;
    else
        return false;
}

template <typename T>
void Graph<T>::printGraph()
{
    cout<<"   ";
    for (int i = 0; i < Vg; i++)
    {
        cout.width(6);
        cout<<i;
    }
    cout<<"  |"<<endl<<"------";
    for (int i = 0; i < Vg; i++)
    {
        cout.width(3);
        cout<<"------";
    }
    cout<< endl;
    for (int i = 0; i < Vg; i++)
    {
        cout.width(3);
        cout<<i<<" | ";
        for (int j = 0; j <Vg; j++)
        {
            cout.width(3);
            cout<<adj[i][j]<<"  |";
            
        }
        
        cout<<endl;
    }
}

template <typename T>
void Graph<T>::showGraph()
{
    for (int i = 0; i < Vg; i++)
    {
        cout.width(2);
        cout<<i<<":";
        for (int j = 0; j <Vg; j++)
            if (adj[i][j] != 0)
            {
                cout.width(2);
                cout<<j<<" ";
            };
        cout<<endl;
    }
}


template <typename T>
list<int> * Graph<T>::DFS(int start)
{
    vector<bool> discovered(Vg);
    list<int> * result = new list<int>();
    discovered.assign(Vg, false);
   // for (int i=0; i<Vg; i++)
     //   discovered[i] = false;
    stack<int> st;

    discovered[start] = true;
    st.push(start);

    while (!st.empty())
    {
        int i = st.top();
        //cout << i << " ";
        result->push_back(i);
        st.pop();

        for (int j = 0; j < Vg; j++)
        {
            if ((discovered[j] != true) && (adj[i][j] != 0))
            {
                discovered[j] = true;
                st.push(j);
            }
        }
    }
    cout << endl;
    return result;
}


template <typename T>
vector<T> * Graph<T>::BFS(int start, int end)
{
    vector<int> * result = new vector<int>();
    vector<int> rr(Vg);
    //result->resize(Vg);
    //result->assign(Vg, 0);
    vector<bool> discovered(Vg);
    discovered.assign(Vg, false);
    discovered[start] = true;
    queue<int> queue_spis;
    queue_spis.push(start);
    rr[start]=0;
    int temp =0;
    
    int e;
    while (!queue_spis.empty())
    {
        int i = queue_spis.front();
        //cout << i << " ";
      //  result->push_back(i);
        temp = rr[i];
        queue_spis.pop();

        for (int j =0; j < Vg; j++)
        {
            if ((discovered[j] != true) && (j != end) && (adj[i][j] != 0))
            {
                discovered[j] = true;
                queue_spis.push(j);
                rr[j] = temp + 1; //или вес ребра
            }
            else
                if ((j == end) && (adj[i][j] != 0))
                {
                    discovered[j] = true;
                    rr[j] = temp + 1;//или вес ребра
                    while (!queue_spis.empty())
                        queue_spis.pop();
                    break;
                }
        }
    }
    if (discovered[end] == true)
        cout << end << endl;
    if (discovered[end] != true)
        cout << "Element not found"<< endl;
    else
    {
        stack<int> Way;
        cout << "Way: ";
        discovered[end] = false;
        int index = end;
        while (index != start)
        {
            for (int j=Vg-1; j>=0; j--)
            {
                if ((discovered[j] == true) && (adj[j][index] != 0))
                {
                    discovered[j] = false;
                    Way.push(j);
                    index = j;
                    break;
                }
            }
        }
        while (!Way.empty())
        {
            cout << Way.top() << " -> ";
            Way.pop();
        }
        cout << end;

    }
    cout << endl;
    * result = rr;
    return result;
}


#endif /* Graph_hpp */
