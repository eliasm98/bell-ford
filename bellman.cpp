#include <iostream>

using namespace std;

#define INF 999999

struct edges
{
    int u, v, w;
};

void fillmat (int ** m, int n)
{
    int x = 0;
    int u, v, w;
    while(x == 0)
    {
        cout << "Input the vertices and weight: ";
        cin >> u >> v >> w;
        cout <<endl;
        m[u][v] = w;
      //  m[v][u] = w;

        cout << "to stop adding edges, enter 1" <<endl;
        cin >> x; 
    }
}

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


bool bellman(int ** mat, int n, int m, int s)
{
    int d[n], pi[n];
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        pi[i] = -1;
    }

    d[s] = 0;
    int k = 0;
    edges E[m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mat[i][j] != 0)
            {
                E[k].u = i;
                E[k].v = j;
                E[k].w = mat[i][j];
                k++;

            }
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for(int j = 0; j <m; j++)
        {
            
            if(d[E[j].v] > d[E[j].u] + E[j].w)
            {
                d[E[j].v] = d[E[j].u] + E[j].w;
                pi[E[j].v] = E[j].u;
            }
        }
    }
        for(int j = 0; j <m; j++)
        {
            if(d[E[j].v] > d[E[j].u] + E[j].w)
            {
                return false;
            }
        }
    
    for (int i = 0; i < n; i++)
    {
        cout << pi[i] << "  " << d[i] << endl;
    }
    cout <<endl;
    return true;
}


int main()
{
int ** mat;
  int  n;
  cout << "input n: " ;
  cin >> n;
  cout <<endl;
  mat = new int*[n];
  	
  for (int i = 0; i < n; i++) {
	mat[i] = new int[n];
	}

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j <n ; j++)
    {
       mat[i][j] = 0;
    }
 }
  fillmat(mat, n);
  printmat(mat, n);
  cout << "input source vertex: ";
  int s;
  cin >> s;
  cout <<endl;

  int m = 0;
  for (int i = 0; i < n; i ++)
  {
    for (int j = 0; j < n; j++)
    {
       if(mat[i][j] != 0)
       {
        m = m + 1;
       }
    }
  }
  cout <<m <<endl;
  bool test = bellman(mat, n, m ,s);

  if(test = true)
  {
    cout << "solution found";
  }
  return 0;
}
