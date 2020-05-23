#include <stdio.h>
#include <stdlib.h>
#define MAXN 10010
#define MAXM 110

int W[MAXN];		
int B[MAXN][MAXN] = {0};
int flag[MAXN][MAXM] = {0};

int cmp( const void * a, const void * b )
{
	int *x = (int*) a;
	int *y = (int*) b;
	return ( *y - *x );
}

int main ()
{
	int N , M, i;
	scanf( "%d %d", &N, &M );

	W[0] = M+1;
	for ( i = 1 ; i <= N ; i ++ )
		scanf( "%d", &W[i] );

	qsort( W, N+1, sizeof( int ), cmp );
	
	/*
	for ( i = 0 ; i <= N ; i ++ )
		printf( "%d ", W[i] );
	printf( "\n" );
	*/
	int j;
	for ( i = 1 ; i <= N ; i ++ )
		for ( j = 1 ; j <= M ; j ++ ){
			if ( W[i] > j )
				B[i][j] = B[i-1][j];
			else{
				if ( B[i-1][j] > B[i-1][ j-W[i] ] + W[i] )
					B[i][j] = B[i-1][j];
				else{
					B[i][j] = B[i-1][ j-W[i] ] + W[i];
					flag[i][j] = 1;
				}
			}
		}
	/*
	for ( i = 0 ; i <=N ; i ++ ){
		for ( j = 0 ; j <= M ; j ++ )
			printf( "%d ", B[i][j] );
		printf( "\n" );
	}
	*/

	int m;
	if ( B[N][M] < M )
		printf( "No Solution" );
	else{
		i = N;
		m = M;
		while( m ){
			while( flag[i][m] == 0 )
				i --;
			m -= W[i];
			if ( m == 0 )
				printf( "%d", W[i] );
			else
				printf( "%d ", W[i] );
			i --;
		}
	}


	return 0;
}
