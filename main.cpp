#include <iostream>
#define MAX 10
#define INF 99999
using namespace std;
// class for storing the data of available space in a warehouse (implementing circular linked list)
class warehouse
{
public:
    int availableSpace;
    warehouse *next;
    warehouse(int val)
    {
        availableSpace = val;
        next = NULL;
    }
};
// function to update the capacity of a warehouse from a list of warehouses
void updateCapacity(warehouse *wh)
{
    int i, newCap;
    cout << "\nEnter warehouse number: ";
    cin >> i;
    cout << "\nEnter new capacity(in percentage): ";
    cin >> newCap;
    for (int n = 1; n <= i; n++)
    {
        if (n == i)
        {
            wh->availableSpace = newCap;
        }
        wh = wh->next;
    }
}
// function to display the available space in a particular warehouse
void display(warehouse *wh1)
{
    for (int i = 1; i <= 11; i++)
    {
        cout << "Warehouse " << i << ", Available Space " << wh1->availableSpace << " percent" << endl;
        wh1 = wh1->next;
    }
}
// function to display the warehouses ready for quick sell i.e. warehouses with atmost 30% capacity left
void display70(warehouse *wh1)
{
    for (int i = 1; i <= 11; i++)
    {
        if (wh1->availableSpace <= 30)
        {
            cout << "Available space in warehouse " << i << " is " << wh1->availableSpace << " percent" << endl;
        }
        wh1 = wh1->next;
    }
}
// Implementation of Dijkstra's Algorithm to find the shortest path
void dijk(int G[MAX][MAX], int n, int start, warehouse *wh1)
{
    int cost[MAX][MAX], dist[MAX], visited[MAX], pred[MAX];
    int i, j, count, min_distance, nextnode;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = G[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1)
    {
        min_distance = INF;
        for (i = 0; i < n; i++)
        {
            if (dist[i] < min_distance && !visited[i])
            {
                min_distance = dist[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if ((min_distance + cost[nextnode][i]) < dist[i])
                {
                    dist[i] = min_distance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            cout << "\nThe distance of warehouse " << i << " from the farmer is " << dist[i] << ".\n";
            j = i;
            cout << j;
            do
            {
                j = pred[j];
                cout << "<-----" << j;
            } while (j != start);
        }
        cout << endl;
    }
    cout << "\nAvailable space in warehouses \n\n";
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            for (int k = 0; k < 11; k++)
            {
                if (k == i)
                {
                    cout << "Warehouse number " << k << " is " << wh1->availableSpace << " percent vacant.\n";
                    wh1 = wh1->next;
                }
                wh1 = wh1->next;
            }
        }
        cout << endl;
    }
}
void mainProgram(int G[MAX][MAX], int n, int start, warehouse *wh1)
{
    cout << "\nEnter number of warehouses(including farmer): ";
    cin >> n;
    cout << "\nEnter the distances between each of the connections: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    cout << "\nEnter Source/Farmer or Starting Node: ";
    cin >> start;
    dijk(G, n, start, wh1);
}
int main()
{
    // wh1,wh2....,wh11 are the nodes of linked list
    warehouse *wh1 = new warehouse(30);
    warehouse *wh2 = new warehouse(40);
    warehouse *wh3 = new warehouse(70);
    warehouse *wh4 = new warehouse(55);
    warehouse *wh5 = new warehouse(50);
    warehouse *wh6 = new warehouse(10);
    warehouse *wh7 = new warehouse(80);
    warehouse *wh8 = new warehouse(70);
    warehouse *wh9 = new warehouse(20);
    warehouse *wh10 = new warehouse(50);
    warehouse *wh11 = new warehouse(30);
    wh1->next = wh2;   // linking the first warehouse to the second one
    wh2->next = wh3;   // linking the second warehouse to the third one
    wh3->next = wh4;   // linking the third warehouse to the fourth one
    wh4->next = wh5;   // linking the fourth warehouse to the fifth one
    wh5->next = wh6;   // linking the fifth warehouse to the sixth one
    wh6->next = wh7;   // linking the sixth warehouse to the seventh one
    wh7->next = wh8;   // linking the seventh warehouse to the eighth one
    wh8->next = wh9;   // linking the eighth warehouse to the ninth one
    wh9->next = wh10;  // linking the ninth warehouse to the tenth one
    wh10->next = wh11; // linking the tenth warehouse to the eleventh one
    wh11->next = wh1;  // linking the eleventh warehouse to the first one (circular linked list)
    cout << "\n\t\t<-----This is Terminal Window----->\n";
    int G[MAX][MAX], n, start;
    int i, j, choice;
    int trigger;
    cout << "\nSelect from the following: \n";
    cout << "\n1. User Window\n2. Admin Window\n";
    cout << "Enter your operation number: ";
    cin >> trigger;
    switch (trigger)
    {
    case 1:
        cout << "\n\t\t<------This is User Window----->\n";
        cout << "\nSelect from the following:\n1. Create Network\n\t-->will display available routes\n\t-->will display available warehouses\n";
        cout << "\n2. Exit\n";
        do
        {
            cout << "Enter your operation number: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                mainProgram(G, n, start, wh1);
                cout << "\nExecuted Successfully.\n";
                break;
            case 2:
                cout << "\nProgram Ended Successfully.\n";
                exit(0);
            default:
                cout << "\nInvalid Choice\n";
                cout << "\nClosing Program Now.\n";
                exit(0);
            }
        } while (choice != 2);
        break;
    case 2:
        cout << "\n\t\t<-----This is Admin Window----->\n";
        cout << "\nSelect from the following: \n1. Display network of warehouses \n\t-->Shows available spaces";
        cout << "\n2. Update Capacity of warehouse.\n3. Display warehouses ready for quick sell\n\t-->Warehouses with atmost 30 percent capacity";
        cout << "\n4. Exit\n";
        do
        {
            cout << "\nEnter your operation number: \n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                display(wh1);
                cout << "\nExecuted Successfully.\n";
                break;

            case 2:
                updateCapacity(wh1);
                display(wh1);
                cout << "\nExecuted Successfully.\n";
                break;
            case 3:
                display70(wh1);
                cout << "\nExecuted Successfully.\n";
                break;
            case 4:
                cout << "\nProgram Ended Successfully.\n";
                exit(0);
            default:
                cout << "\nInvalid Choice\n";
                cout << "\nClosing Program Now.\n";
            }
        } while (choice != 4);
        break;
    default:
        cout << "\nInvalid Choice\n";
        cout << "\nClosing Program Now.\n";
        exit(0);
    }
    return 0;
}
