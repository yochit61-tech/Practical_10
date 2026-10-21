#include <iostream>
using namespace std;

int main()
{
    int n, cost[20][20];
    int parent[20];
    int i, j, a, b, u, v;
    int min, mincost = 0, edges = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        min = 999;
        a = -1;
        b = -1;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a == -1 || b == -1)
        {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        u = a;
        v = b;

        while (parent[u] != u)
            u = parent[u];

        while (parent[v] != v)
            v = parent[v];

        if (u != v)
        {
            cout << a << " - " << b
                 << " : " << min << endl;

            mincost = mincost + min;
            parent[u] = v;
            edges++;
        }

        cost[a][b] = 999;
        cost[b][a] = 999;
    }

    cout << "Minimum cost = " << mincost << endl;

    return 0;
}
