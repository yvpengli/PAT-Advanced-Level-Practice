#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1050;
struct node
{
    int No;
    int weight;
};
vector <node> g[maxn];

int n, m, k, ds, total, ans;
double MAXDIST = -1, AVG = 0.0;
int dist[maxn], collected[maxn];

int GetNo( char a[] )
{
    int sum = 0, pre = 0, i = 0;
    if( a[0] == 'G' )
    {
        pre = n;
        i = 1;
    }
    for( ; i < strlen( a ) ; i ++ )
        sum = sum * 10 + a[i] - '0';
    return pre + sum;
}

int FindMin( void )
{
    int Min = ds+1, Minpos = -1;
    for( int i = 1 ; i <= total ; i ++ )
        if( collected[i] == 0 && dist[i] < Min )
        {
            Min = dist[i];
            Minpos = i;
        }
    return Minpos;
}

void Dijkstra( int s )
{
    
    int v, w, weight;
    for( v = 1 ; v <= total ; v ++ )
    {
        collected[v] = 0;
        dist[v] = ds+1;
    }

    collected[s] = 1;
    dist[s] = 0;

    for( int i = 0 ; i < g[s].size() ; i ++ )
    {
        w = g[s][i].No;
        dist[w] = g[s][i].weight;
    }

    while( 1 )
    {
        v = FindMin();
        if( v == -1 )
            break;
        collected[v] = 1;
        for( int i = 0 ; i < g[v].size() ; i ++ )
        {
            w = g[v][i].No;
            weight = g[v][i].weight;
            if( collected[w] == 0 && dist[w] > dist[v] + weight )
                dist[w] = dist[v] + weight;
        }
    }

}

void MinDist( double &nowMIN, double &nowAVG, bool &tag )
{
    nowMIN = ds + 1;
    nowAVG = 0;
    tag = true;
    for( int i = 1 ; i <= n ; i ++ )
    {
        if( dist[i] <= ds )
        {
            if( dist[i] < nowMIN )
                nowMIN = dist[i];
            nowAVG += dist[i];
        }
        else
            tag = false;
    }
    nowAVG /= n;
}

int main()
{
    scanf( "%d %d %d %d", &n, &m, &k, &ds );
    total = n + m;
    for( int i = 0 ; i < k ; i ++ )
    {
        char a[5], b[5];
        int distance;
        scanf( "%s %s %d", a, b, &distance );
        g[GetNo(a)].push_back( {GetNo(b), distance} );
        g[GetNo(b)].push_back( {GetNo(a), distance} );
    }
    for( int i = 1 ; i <= m ; i ++ )
    {
        Dijkstra( n + i );
        double nowMIN, nowAVG;
        bool tag;
        MinDist( nowMIN, nowAVG, tag );
        if( tag )
        {
            if( nowMIN > MAXDIST )
            {
                MAXDIST = nowMIN;
                AVG = nowAVG;
                ans = i;
            }
            else if( nowMIN == MAXDIST )
            {
                if( nowAVG < AVG )
                {
                    AVG = nowAVG;
                    ans = i;
                }
            }
        }

    }
    if( MAXDIST > 0 )
    {
        printf( "G%d\n", ans );
        printf( "%.1f %.1f", MAXDIST, AVG );
    }
    else
        printf( "No Solution" );


    return 0;
}
