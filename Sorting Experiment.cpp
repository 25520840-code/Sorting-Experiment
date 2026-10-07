#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <string>
#include <filesystem>
#include "Sort.h"
#include "DataGenerator.h"

using namespace std;
using namespace chrono;

const int SO_LAN_CHAY = 5;


// =====================================================
// DOC FILE
// =====================================================

vector<double> doc_file ( const string& filename )
	{
	ifstream fin ( filename );

	if ( !fin )
		{
		cout << "Khong mo duoc file: "
			<< filename << endl;

		return {};
		}

	int n;
	fin >> n;

	vector<double> a ( n );

	for ( int i = 0; i < n; i++ )
		fin >> a [ i ];

	return a;
	}


// =====================================================
// KIEM TRA DA SAP XEP CHUA
// =====================================================

bool kiem_tra ( const vector<double>& a )
	{
	return is_sorted ( a.begin ( ) , a.end ( ) );
	}


// =====================================================
// QUICK SORT
// =====================================================

double test_quick_sort (
	const vector<double>& data
)
	{
	double tong_thoi_gian = 0;

	for ( int lan = 1; lan <= SO_LAN_CHAY; lan++ )
		{
		// Copy lai du lieu goc moi lan
		vector<double> a = data;

		auto start =
			high_resolution_clock::now ( );

		quick_sort (
			a ,
			0 ,
			static_cast< int >( a.size ( ) ) - 1
		);

		auto end =
			high_resolution_clock::now ( );

		double time =
			duration<double , milli> (
				end - start
			).count ( );

		tong_thoi_gian += time;

		cout << "    QuickSort lan "
			<< lan
			<< ": "
			<< time
			<< " ms"
			<< endl;

		if ( !kiem_tra ( a ) )
			cout << "    QuickSort ERROR!"
			<< endl;
		}

	return tong_thoi_gian / SO_LAN_CHAY;
	}


// =====================================================
// HEAP SORT
// =====================================================

double test_heap_sort (
	const vector<double>& data
)
	{
	double tong_thoi_gian = 0;

	for ( int lan = 1; lan <= SO_LAN_CHAY; lan++ )
		{
		vector<double> a = data;

		auto start =
			high_resolution_clock::now ( );

		heap_sort ( a );

		auto end =
			high_resolution_clock::now ( );

		double time =
			duration<double , milli> (
				end - start
			).count ( );

		tong_thoi_gian += time;

		cout << "    HeapSort lan "
			<< lan
			<< ": "
			<< time
			<< " ms"
			<< endl;

		if ( !kiem_tra ( a ) )
			cout << "    HeapSort ERROR!"
			<< endl;
		}

	return tong_thoi_gian / SO_LAN_CHAY;
	}


// =====================================================
// MERGE SORT
// =====================================================

double test_merge_sort (
	const vector<double>& data
)
	{
	double tong_thoi_gian = 0;

	for ( int lan = 1; lan <= SO_LAN_CHAY; lan++ )
		{
		vector<double> a = data;

		auto start =
			high_resolution_clock::now ( );

		merge_sort ( a );

		auto end =
			high_resolution_clock::now ( );

		double time =
			duration<double , milli> (
				end - start
			).count ( );

		tong_thoi_gian += time;

		cout << "    MergeSort lan "
			<< lan
			<< ": "
			<< time
			<< " ms"
			<< endl;

		if ( !kiem_tra ( a ) )
			cout << "    MergeSort ERROR!"
			<< endl;
		}

	return tong_thoi_gian / SO_LAN_CHAY;
	}


// =====================================================
// STD::SORT
// =====================================================

double test_cpp_sort (
	const vector<double>& data
)
	{
	double tong_thoi_gian = 0;

	for ( int lan = 1; lan <= SO_LAN_CHAY; lan++ )
		{
		vector<double> a = data;

		auto start =
			high_resolution_clock::now ( );

		sort ( a.begin ( ) , a.end ( ) );

		auto end =
			high_resolution_clock::now ( );

		double time =
			duration<double , milli> (
				end - start
			).count ( );

		tong_thoi_gian += time;

		cout << "    std::sort lan "
			<< lan
			<< ": "
			<< time
			<< " ms"
			<< endl;

		if ( !kiem_tra ( a ) )
			cout << "    std::sort ERROR!"
			<< endl;
		}

	return tong_thoi_gian / SO_LAN_CHAY;
	}


// =====================================================
// MAIN
// =====================================================

int main ( )
	{
	// Chi chay 1 lan de tao du lieu
	tao_du_lieu ( );
	cout << "Current path: "
		<< filesystem::current_path ( )
		<< endl;

	ofstream result ( "results.csv" );

	result
		<< "Data,"
		<< "QuickSort,"
		<< "HeapSort,"
		<< "MergeSort,"
		<< "std::sort\n";

	double sumQuick = 0;
	double sumHeap = 0;
	double sumMerge = 0;
	double sumCpp = 0;

	cout << fixed << setprecision ( 3 );

	for ( int i = 1; i <= 10; i++ )
		{
		string filename;

		if ( i < 10 )
			{
			filename =
				"data/data0"
				+ to_string ( i )
				+ ".txt";
			}
		else
			{
			filename =
				"data/data10.txt";
			}

		cout << endl;
		cout << "===================================="
			<< endl;

		cout << "DATASET " << i << endl;

		cout << "===================================="
			<< endl;

		vector<double> data =
			doc_file ( filename );

		if ( data.empty ( ) )
			return 1;


		// ---------------------------------
		// QUICK SORT
		// ---------------------------------

		cout << endl;
		cout << "[QuickSort]" << endl;

		double quick =
			test_quick_sort ( data );


		// ---------------------------------
		// HEAP SORT
		// ---------------------------------

		cout << endl;
		cout << "[HeapSort]" << endl;

		double heap =
			test_heap_sort ( data );


		// ---------------------------------
		// MERGE SORT
		// ---------------------------------

		cout << endl;
		cout << "[MergeSort]" << endl;

		double merge =
			test_merge_sort ( data );


		// ---------------------------------
		// STD::SORT
		// ---------------------------------

		cout << endl;
		cout << "[std::sort]" << endl;

		double cpp =
			test_cpp_sort ( data );


		// ---------------------------------
		// KET QUA TRUNG BINH DATASET
		// ---------------------------------

		cout << endl;

		cout << "----- TRUNG BINH DATASET "
			<< i
			<< " -----"
			<< endl;

		cout << "QuickSort : "
			<< quick
			<< " ms"
			<< endl;

		cout << "HeapSort  : "
			<< heap
			<< " ms"
			<< endl;

		cout << "MergeSort : "
			<< merge
			<< " ms"
			<< endl;

		cout << "std::sort : "
			<< cpp
			<< " ms"
			<< endl;


		// ---------------------------------
		// CONG VAO TONG
		// ---------------------------------

		sumQuick += quick;
		sumHeap += heap;
		sumMerge += merge;
		sumCpp += cpp;


		// ---------------------------------
		// GHI CSV
		// ---------------------------------

		result
			<< i << ","
			<< quick << ","
			<< heap << ","
			<< merge << ","
			<< cpp << "\n";
		}


	// =================================================
	// TRUNG BINH 10 DATASET
	// =================================================

	double avgQuick =
		sumQuick / 10.0;

	double avgHeap =
		sumHeap / 10.0;

	double avgMerge =
		sumMerge / 10.0;

	double avgCpp =
		sumCpp / 10.0;


	cout << endl;

	cout << "===================================="
		<< endl;

	cout << "TRUNG BINH TOAN BO 10 DATASET"
		<< endl;

	cout << "===================================="
		<< endl;

	cout << "QuickSort : "
		<< avgQuick
		<< " ms"
		<< endl;

	cout << "HeapSort  : "
		<< avgHeap
		<< " ms"
		<< endl;

	cout << "MergeSort : "
		<< avgMerge
		<< " ms"
		<< endl;

	cout << "std::sort : "
		<< avgCpp
		<< " ms"
		<< endl;


	result
		<< "Average,"
		<< avgQuick << ","
		<< avgHeap << ","
		<< avgMerge << ","
		<< avgCpp << "\n";

	result.close ( );

	cout << endl;
	cout << "Da luu ket qua vao results.csv"
		<< endl;

	return 0;
	}