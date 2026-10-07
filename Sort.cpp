#include "Sort.h"

// ==================== QUICK SORT ====================

void quick_sort ( vector<double>& a , int left , int right )
	{
	int i = left;
	int j = right;

	double pivot = a [ left + ( right - left ) / 2 ];

	while ( i <= j )
		{
		while ( a [ i ] < pivot )
			i++;

		while ( a [ j ] > pivot )
			j--;

		if ( i <= j )
			{
			swap ( a [ i ] , a [ j ] );
			i++;
			j--;
			}
		}

	if ( left < j )
		quick_sort ( a , left , j );

	if ( i < right )
		quick_sort ( a , i , right );
	}


// ==================== HEAP SORT ====================

void heapify ( vector<double>& a , int n , int i )
	{
	int largest = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if ( left < n && a [ left ] > a [ largest ] )
		largest = left;

	if ( right < n && a [ right ] > a [ largest ] )
		largest = right;

	if ( largest != i )
		{
		swap ( a [ i ] , a [ largest ] );

		heapify ( a , n , largest );
		}
	}

void heap_sort ( vector<double>& a )
	{
	int n = a.size ( );

	for ( int i = n / 2 - 1; i >= 0; i-- )
		heapify ( a , n , i );

	for ( int i = n - 1; i > 0; i-- )
		{
		swap ( a [ 0 ] , a [ i ] );

		heapify ( a , i , 0 );
		}
	}


// ==================== MERGE SORT ====================

void merge (
	vector<double>& a ,
	vector<double>& temp ,
	int left ,
	int mid ,
	int right
)
	{
	int i = left;
	int j = mid + 1;
	int k = left;

	while ( i <= mid && j <= right )
		{
		if ( a [ i ] <= a [ j ] )
			temp [ k++ ] = a [ i++ ];
		else
			temp [ k++ ] = a [ j++ ];
		}

	while ( i <= mid )
		temp [ k++ ] = a [ i++ ];

	while ( j <= right )
		temp [ k++ ] = a [ j++ ];

	for ( int p = left; p <= right; p++ )
		a [ p ] = temp [ p ];
	}

void merge_sort_recursive (
	vector<double>& a ,
	vector<double>& temp ,
	int left ,
	int right
)
	{
	if ( left >= right )
		return;

	int mid = left + ( right - left ) / 2;

	merge_sort_recursive ( a , temp , left , mid );

	merge_sort_recursive ( a , temp , mid + 1 , right );

	merge ( a , temp , left , mid , right );
	}

void merge_sort ( vector<double>& a )
	{
	if ( a.empty ( ) )
		return;

	vector<double> temp ( a.size ( ) );

	merge_sort_recursive (
		a ,
		temp ,
		0 ,
		static_cast< int >( a.size ( ) ) - 1
	);
	}