/* gets example */
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	vector<map<string, int>> accts;

	int num_tests;
	int num_accts;

	string str;

	cin >> num_tests;

	for (int j = 0; j < num_tests; j++) {
		map<string, int> tmp;
		
		cin >> num_accts;
		cin.ignore();
		for (int i = 0; i < num_accts; i++) {
			getline(cin, str);
			tmp[str]++;
		}
		getline(cin, str);


		accts.push_back(tmp);
	}

	int size = accts.size();
	for (int i = 0; i < size; i++) {
		for (map<string, int>::iterator it = accts[i].begin(); it != accts[i].end(); ++it)
			cout << it->first << " " << it->second << endl;
		cout << endl;
	}
}