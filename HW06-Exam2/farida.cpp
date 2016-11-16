#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Change to long long
int main(){
	long long test_cases = 0;
	long long num_monsters = 0;
	vector<long long> monsters_coins;
	vector<long long> ans;
	
	cin >> test_cases;
	
	for(long long i = 0; i < test_cases; i++){
		cin >> num_monsters;
		
		long long temp;
		for (long long j = 0; j < num_monsters; j++){
			cin >> temp;
			monsters_coins.push_back(temp);
		}
		
		vector<long long> max_coins(monsters_coins.size(), 0);
		
		if (num_monsters == 0)
			ans.push_back(0);
		else if (num_monsters == 1)
			ans.push_back(monsters_coins[0]);
		else{
			max_coins[0] = monsters_coins[0];
			max_coins[1] = max(monsters_coins[0], monsters_coins[1]);
			for (long long j = 2; j < num_monsters; j++){
				max_coins[j] = max(monsters_coins[j] + max_coins[j-2], max_coins[j-1]);
			}
			
			ans.push_back(max_coins[num_monsters-1]);
		}
		monsters_coins.clear();
	}
	
	for (long long i = 0; i < test_cases; i++)
		cout << "Case " << i+1 << ": " << ans[i] << endl; 

	return 0;
}