#include <iostream>

using namespace std;

void printmat(int ** mat, int n)
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "   ";
            if (j == n-1)
            {
                cout << endl;
            }
        }
    }

}
void dfsvist(int ** mat, int n, int k, int d[], int f[], int pi[], int count[], int& time)
{
    d[k] =++ time;
    count[k]++;
    for(int i = 0; i < n; i++)
    {
        if(mat[k][i] !=0) 
        {
            if(d[i] == 0)
            {
                pi[i] = k;
                dfsvist(mat, n, i, d, f, pi, count, time);
            }
        }

    }
    f[k] = ++time;

}

void dfs(int ** mat, int n)
{
    int d[n], pi[n], f[n];
    int count[n] ={0};
    int time = 0;
    for(int i = 0; i < n; i ++)
    {
        d[i] = 0;
        f[i] = 0;
        pi[i] = -1; 
    }

    for(int i = 0; i < n; i ++)
    {
        if( d[i] == 0)
        {
            dfsvist(mat, n, i, d, f, pi, count, time);
        }

    }

    for(int i = 0; i < n; i++)
    {
        cout << d[i] << "/" << f[i] <<"  ";
    }



}
void randomsimplegraph(int n, int m)
{
    int u, v;
    int ** mat;
    mat = new int*[n];
    for (int k = 0; k < n; k++) 
    {
	    mat[k] = new int[n];
	}
    for(int l = 0; l < n; l++)
    {
        for(int pp = 0; pp < n; pp++)
        {
            mat[l][pp] = 0;
        }
    }
    srand(time(0));

    for(int val = 0; val < m;)
    {
        u = rand()%n;
        v = rand()%n;
        if(mat[u][v] != 0 || u == v) {continue;}
        else{
            mat[u][v] = 1;
            mat[v][u]= 1;
            val++;
        }
    }

    printmat(mat,n);
    dfs(mat, n);
}

int main()
{
    int n,m;
    cin >> n >> m;
    randomsimplegraph(n,m);
    return 0;
}