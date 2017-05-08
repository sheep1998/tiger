// suffix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
using namespace std;

map<string, int> m;
vector<string>vec;
set<string>whether;
vector<string>vec2;
map<string,int>m2;
vector<string>v3;

int main()
{
	//requirement 1
	cout << "please put in the number of suffix" << endl;
	string number_s;
	getline(cin, number_s);
	stringstream ss;
	ss << number_s;
	int number;
	ss >> number;

	ifstream fin("EnglishWords.txt");
	string line;
	while (getline(fin, line)) {
		string suffix;
		for (int i = line.size() - number; i < line.size(); i++) {
			suffix += line[i];
		}
		m[suffix] += 1;
		if (whether.find(suffix)!=whether.end()){}
		else { 
			whether.insert(suffix);
			vec.push_back(suffix);
		}
	}
	
	string first;
	int first_number=0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < vec.size(); j++) {
			if (m[vec[j]] > first_number && vec[j]!="") {
				first = vec[j];
				first_number = m[vec[j]];
			}
		}
		vec2.push_back(first);
		m2[first] = first_number;
		if (first_number != 0)
		{
			cout << first << "   " << first_number << endl;
		}
		m[first] = 0;
		first_number = 0;
	}
	for (int i = 0; i < vec2.size(); i++) {
		m[vec2[i]] = m2[vec2[i]];
	}
	//requirement 2
	cout << "please input a suffix of the size above" << endl;
	string line2;
	getline(cin, line2);
	cout << m[line2] << endl;

	ifstream fin2("EnglishWords2.txt");
	while (getline(fin2, line)) {
		string suffix;
		for (int i = line.size() - number; i < line.size(); i++) {
			suffix += line[i];
		}
		if (suffix == line2) { v3.push_back(line); }
		}
	for (int i = v3.size()-1; i>-1; i--)
		cout << v3[i] << endl;

    return 0;
}

