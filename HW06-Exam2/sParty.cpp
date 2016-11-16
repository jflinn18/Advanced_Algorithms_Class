#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> values;   // happiness of the party
vector<int> weights;  // cost of the party

vector<vector<int>> dp;

vector<int> ans; // This will need to be a pair later when we actually want the right answer

int knapsack(int items, int capacity){
	int value;
	if(dp[items][capacity] < 0){
		if (j < weights[items])
			value = knapsack(items-1, capacity);
		else{
			value = max(knapsack(items-1, capacity), values[items] + knapsack(items-1, capacity-weights[items]));
			dp[items][capacity] = value;
		}
	}
	return dp[items][capacity];
}


int main(){

	while(true){
		int budget = 0;
		int num_parties = 0;
	
		cin >> budget >> num_parties;
		
		if (budget == 0 && num_parties == 0)
			break;
		
		int temp;
		for(int i = 0; i < num_parties; i++){
			cin >> temp;
			weights.push_back(temp);
			cin >> temp;
			values.push_back(temp);
		}
		
		ans.push_back(knapsack(num_parties, budget));
		
		getline(cin, temp); // Eats the endline
		
		cin.clear(); // Clears the buffer
		cin.ignore();
		
		values.clear();
		weights.clear();
		
		// This should work. But only 91% sure
		for (auto i : dp)
			i.clear();
	}
	
	

}