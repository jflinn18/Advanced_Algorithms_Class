#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//long long farida_rec(int mNum, long long FN1, long long FN2, long long m) {
long long farida_rec(int mNum, long long FN1, long long FN2){
	
	if (mNum == 0) return FN1;
	
	long long coin;
	cin >> coin;
	long long temp = max(FN2+coin, FN1);

	
	
	return farida_rec(mNum-1, temp, FN1);
}

int main() {
	int num_cases = 0;
	int num_monsters;
	int temp;
	cin >> num_cases;

	for (int i = 0; i < num_cases; i++) {
		cin >> num_monsters;
		cout << "Case " << i + 1 << ": " << farida_rec(num_monsters, 0, 0) << endl;

	}
}