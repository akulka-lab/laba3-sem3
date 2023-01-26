#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>


using namespace::std;

void Main_menu();
int menu_var(int count);
int random_int(int max, int min);
int menu_01 ();
int menu_02 ();
int input_count ();
void Menu();
void print_list(const list<int> & lt);
void print_vector(const vector<int> & vc);


int menu_var(int count)
{
    int a;
    cin >> a;
    while (a < 0 || a > count)
    {
        cout << ("ERROR!") << endl << ("Enter a new number: ");

        cin >> a;
    }

    return a;
}

int random_int(int max = 5, int min = 0)
{
    return (min + rand()%((max + 1) - min));
}

int menu_01 ()
{

    cout << " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                ~WELCOME TO MENU 3 OF LAB WORK!~                       | \n" <<
        "|                                                                       | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl <<
        " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                      Choose a further action:                         | \n" <<
        "|                                                                       | \n" <<
        "|   1 - oriented graph test                                             | \n" <<
        "|   2 - undirected graph test                                           | \n" <<
        "|   3 - manual graph entry                                              | \n" <<
        "|                                                                       | \n" <<
        "|   0 - finish work                                                     | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl;

    cout << "Enter the selected number: ";

    int r = menu_var(3);
    return r;
}

int menu_02 ()
{
    cout << " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|        The menu for selecting works with the hashing map              | \n" <<
        "|                                                                       | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl <<
        " _______________________________________________________________________  \n" <<
        "|                                                                       | \n" <<
        "|                      Choose a further action:                         | \n" <<
        "|                                                                       | \n" <<
        "|   1 - display the map on the screen                                   | \n" <<
        "|   2 - element search                                                  | \n" <<
        "|   3 - deleting an element                                             | \n" <<
        "|   4 - insert a new element                                            | \n" <<
        "|                                                                       | \n" <<
        "|   0 - go back                                                         | \n" <<
        "|____  _________________________________________________________________| \n" <<
        "     |/                                                                   \n" << endl;

    cout << "Enter the selected number: ";

    int r = menu_var(4);
    return r;
}


void Main_menu()
{
    while (1 == 1)
    {
        int var = menu_01();
        switch (var)
        {
            case 0:
                return;
                
            case 1:
            {
                vector<Edge<int>> edges_graph01;
                vector<Edge<int>> proba = {
                    {0,1,1}, {1,2,5}, {2,0,2}, {2,1,7}, {3,2,6}, {3,3,2}, {4,5,1}, {5,4,3}
                };
                vector<Edge<int>> proba2 = {
                    {1,4,1}, {1,2,1}, {4,6,1}, {4,5,1}, {5,1,1}, {6,3,1}, {3,1,1}, {2,3,1}, {2,0,1}
                };
              
    
                Graph<int> primer = Graph<int>(proba, 6, true);
                Graph<int> primer2 = Graph<int>(proba2, 7, true);
                Graph<int> primer3 = Graph<int>(proba2, 7, true);
                primer2.printGraph();
                primer2.showGraph();
                
                
                
            
                
                for (int i = 0; i < primer2.V(); i++)
                {
                    list<int> * res = primer2.DFS(i);
                    print_list(* res);
                }
                
                vector<int> * vres = primer2.BFS(4, 2);
               // print_vector(* vres);
                vector<int> * vres2 = primer2.BFS(6,2);
               // print_vector(* vres2);
                
            }
                break;
            
            case 2:
            {
                vector<Edge<int>> edges_graph01;
                vector<Edge<int>> proba = {
                    {0,1,1}, {1,2,5}, {2,0,2}, {2,1,7}, {3,2,6}, {3,3,2}, {4,5,1}, {5,4,3}
                };
                vector<Edge<int>> proba2 = {
                    {1,4,1}, {1,2,1}, {4,6,1}, {4,5,1}, {5,1,1}, {6,3,1}, {3,1,1}, {2,3,1}, {2,0,1}
                };
              
    
                Graph<int> primer = Graph<int>(proba, 6, false);
                Graph<int> primer2= Graph<int>(proba2, 7, false);
                Graph<int> primer3= Graph<int>(proba2, 7, false);
                primer2.printGraph();
                primer2.showGraph();
                
                
                
            
                
                for (int i = 0; i < primer2.V(); i++)
                {
                    list<int> * res = primer2.DFS(i);
                    print_list(* res);
                }
                
                vector<int> * vres = primer2.BFS(6, 2);
               // print_vector(* vres);
                vector<int> * vres2 = primer2.BFS(4,2);
               // print_vector(* vres2);
              
            }
                break;
                
            case 3:
            {
                
                Graph<int> df = Graph<int>(7, true); // = & (Graph<int>(10,false));
                df.printGraph();
                cout<<"Vertex = "<<df.V()<<" ; Edges = "<<df.E()<<" ; Orient = "<<df.directed()<<endl;
                cout << "THE NUMBER OF CONNECTIONS AND WEIGHTS BETWEEN THE VERTICES OF THE GRAPH " << endl;
                int out = 0, in = 0, wt = 0;
                while (in!=-1 or out!=-1)
                {
                    out=0; in=0; wt=0;
                    cout << endl <<"Entering the number of the outgoing vertex, incoming vertex, link weight: ";
                    cin >> out >> in >> wt;
                    cout << endl;
                    Edge<int> temp;
                    temp.v = out;
                    temp.w = in;
                    temp.weight = wt;
                    df.insert(temp);
                    df.printGraph();
                    cout<<"Vertex = "<<df.V()<<" ; Edges = "<<df.E()<<" ; Orient = "<<df.directed()<<endl;
                }
                df.showGraph();
                
                for (int i = 0; i < df.V(); i++)
                {
                    list<int> * res = df.DFS(i);
                    print_list(* res);
                }
                
                vector<int> * vres = df.BFS(5, 2);
                
            }
                break;
                
            default:
                break;
        }
    }
    

}



void print_list(const list<int> & lt)
{
    cout << "list: ";
    list<int>::iterator it;
    for (auto i = lt.cbegin(); i!= lt.cend(); ++i)
        cout<<" "<< * i;
    cout << endl;
}

void print_vector(const vector<int> & vc)
{
    cout << "list: ";
    vector<int>::iterator it;
    for (auto i = vc.cbegin(); i!= vc.cend(); ++i)
        cout<<" "<< * i;
    cout << endl;
}



#endif /* menu_hpp */
