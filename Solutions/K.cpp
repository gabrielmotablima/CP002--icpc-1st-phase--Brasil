#include <bits/stdc++.h>
    using namespace std;


bool recognizeGraphBipartite(  vector<vector<int>> G, int N )
{
    queue<int> vertex;
    int r, v, w, i;
    int Achieved[N], Level[N];

    for( i = 0; i< N; i++ )
    {
        Achieved[i] = 0;
    }

    r = 0;
    vertex.push( r );
    int achieved = 1;
    Achieved[r] = 1;
    Level[r] = 1;

    while ( !vertex.empty() )
    {
        v = vertex.front();

        for( w = 0; w < N; w++ )
        {
            if(G[v][w] == 1 )
            {    
                if( Achieved[w] == 0 )
                {
                    vertex.push( w );
                    achieved++;
                    Achieved[w] = achieved;
                    Level[w] = Level[v]+1;
                }
                if( Achieved[v] < Achieved[w] )
                {   
                    if(Level[v] == Level[w])    
                        return false;
                }
            }
        }

        vertex.pop();
    }

    return true;
}

int main()
{
    int P, F, n, i, j, x = 0;
    cin >> P;
    cin >> F;
    
    i =0;
    vector<vector<int>> matrix(P, vector<int>(P));

    for( int u = 0; u < P; u++)
    {
        for( int k = 0; k < P; k++)
            matrix[u][k] = 0;
    }

    while(i < F)
    {
        cin >> j;
        cin >> x;
        matrix[j-1][x-1] = 1;
        matrix[x-1][j-1] = 1;
        i++;
    }
    

    int sum=0;
    vector<int> d;


    if(recognizeGraphBipartite( matrix, P))
    {

        for( int i = 0; i < P; i++)
        {
            for(int k = 0; k < P; k++)
            {
                if(matrix[i][k]==1)
                    sum++;
            }

            d.push_back(sum);
            
        }

        for( int i = 0; i < P; i++)
        {
            if(d[i]%2==0)
            {
                cout << 'N'<< endl;
                return 0;
            }
        }   

        cout<< 'Y' << endl;
    }
        cout << 'N'<< endl;

    return 0;
}