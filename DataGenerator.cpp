#include "DataGenerator.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <chrono>

using namespace std;

const int N = 1000000;

void ghi_file (
	const string& filename ,
	const vector<double>& a
)
	{
	ofstream fout ( filename );

	fout << a.size ( ) << '\n';

	for ( double x : a )
		fout << x << '\n';

	fout.close ( );
	}

void tao_du_lieu ( )
	{
	vector<double> data ( N );

	mt19937_64 rng (
		chrono::steady_clock::now ( )
		.time_since_epoch ( )
		.count ( )
	);

	uniform_real_distribution<double>
		dist ( -1000000.0 , 1000000.0 );

	// ====================================
	// Data 1: tang dan
	// ====================================

	for ( int i = 0; i < N; i++ )
		data [ i ] = dist ( rng );

	sort ( data.begin ( ) , data.end ( ) );

	ghi_file (
		"data/data01.txt" ,
		data
	);

	cout << "Da tao data01 - tang dan\n";


	// ====================================
	// Data 2: giam dan
	// ====================================

	reverse ( data.begin ( ) , data.end ( ) );

	ghi_file (
		"data/data02.txt" ,
		data
	);

	cout << "Da tao data02 - giam dan\n";


	// ====================================
	// Data 3 -> 10: random
	// ====================================

	for ( int file = 3; file <= 10; file++ )
		{
		for ( int i = 0; i < N; i++ )
			data [ i ] = dist ( rng );

		string filename;

		if ( file < 10 )
			filename =
			"data/data0"
			+ to_string ( file )
			+ ".txt";
		else
			filename =
			"data/data10.txt";

		ghi_file ( filename , data );

		cout
			<< "Da tao "
			<< filename
			<< " - random\n";
		}
	}