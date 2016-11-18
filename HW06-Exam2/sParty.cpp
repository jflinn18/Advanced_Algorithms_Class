#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<pair<int,int>> ans; // This will need to be a pair later when we actually want the right answer

pair<int, int> compare_pair(pair<int, int> v1, pair<int,int> v2) {
	if (v1.second == v2.second && v1.first >= v2.first)
		return v2;
	else if (v1.second == v2.second && v1.first < v2.first)
		return v1;
	else if (v1.second > v2.second)
		return v1;
	else
		return v2;
}

pair<int, int> add_pairs(int a, int b, pair<int, int> p) {
	p.first = p.first + a;
	p.second = p.second + b;

	return p;
}

pair<int, int> knapsack(int items, int capacity, vector<int> &weights, vector<int> &values, vector<vector<pair<int, int>>> &dp) {
	pair<int, int> value1(0, 0);
	pair<int, int> value2(0, 0);


	if (dp[items][capacity].second < 0) {
		value1 = knapsack(items - 1, capacity, weights, values, dp);
		if (capacity >= weights[items]) 
			value2 = add_pairs(weights[items], values[items], knapsack(items - 1, capacity - weights[items], weights, values, dp));
		dp[items][capacity] = compare_pair(value1, value2);

	}
	return dp[items][capacity];
}


int main() {
	string temp_string = "";

	while (true) {
		int budget = 0;
		int num_parties = 0;

		cin >> budget >> num_parties;

		if (budget == 0 && num_parties == 0) break;

		vector<int> weights(num_parties + 1,0);
		vector<int> values(num_parties + 1,0);

		vector<vector<pair<int, int>>> dp(num_parties + 1, vector<pair<int, int>>(budget + 1, pair<int, int>(-1, -1)));

		for (int i = 1; i <= num_parties; i++) {
			dp[i-1][0] = pair<int, int>(0, 0); 
			cin >> weights[i] >> values[i];
		}
		
		//dp.resize(num_parties+1, vector<pair<int, int>>(budget+1, pair<int, int>(-1, -1)));

		for (int j = 0; j <= budget; j++) 
			dp[0][j] = pair<int, int>(0, 0);

		ans.push_back(knapsack(num_parties, budget, weights, values, dp));


		getline(cin, temp_string); // Eats the endline

		cin.clear(); // Clears the buffer
		cin.ignore();

		values.clear();
		weights.clear();

		// This should work. But only 91% sure
		for (auto i : dp)
			i.clear();
	}

	for (auto i : ans)
		cout << i.first << " " << i.second << endl;
}
