// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<iterator>
#include<sstream>
#include<vector>

#include "stdafx.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	// get my shit toghether
	ifstream myfile;
	myfile.open( "C:\\Temp\\diamonds1.txt" );
	string base( ( std::istreambuf_iterator<char>(myfile) ), ( std::istreambuf_iterator<char>() ) );
	myfile.close();

	// replace new lines
	string new_base;
	std::remove_copy( base.begin(), base.end(), back_inserter(new_base), '\n' ); // newline
	base = "";
	std::remove_copy( new_base.begin(), new_base.end(), back_inserter(base), '\r' ); // newline
	new_base = "";
	std::remove_copy( base.begin(), base.end(), back_inserter(new_base), 'li' ); // no one cares about li
	std::replace( new_base.begin(), new_base.end(), 'I', ' ' ); // change 'I' to ' '

	istringstream iss( new_base );
	vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};

	// magic


	return 0;
}

