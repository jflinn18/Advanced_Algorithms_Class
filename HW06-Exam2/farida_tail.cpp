#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//long long farida_rec(int mNum, long long FN1, long long FN2, long long m) {
long long farida_rec(int mNum, long long FN1, long long FN2){
	long long coin;
	cin >> coin;
	
	long long temp = max(FN2+coin, FN1);
	//long long temp = max(FN2, FN1 + coin);
	if (mNum == 0) return 0;
	if (mNum == 1) return temp;
	
	return farida_rec(mNum-1, temp, FN1);
	//return farida_rec(mNum-1, FN2, FN1+coin, temp);   //Doesn't work either. It just returns that value at the bottom of the recursion
}


//Tail recurision for Fib example
int Fib_tail(int mNum, int a, int b) {
	if (mNum == 0) return a;
	if (mNum == 1) return b;
	return Fib_tail(mNum - 1, b, b + a);
}

int main() {
	int num_cases = 0;
	int num_monsters;
	int temp;
	cin >> num_cases;
	vector<long long> ans;

	for (int i = 0; i < num_cases; i++) {
		cin >> num_monsters;
		//cout << "Case " << i + 1 << ": " << farida_rec(num_monsters, 0, 0) << endl;
		ans.push_back(farida_rec(num_monsters, 0,0));
	}
	
	for (int i = 0; i < num_cases; i++)
		cout << "Case " << i + 1 << ": " << ans[i] << endl;
		

	/*
	--- This is to test Fib_tail. Fib_tail works---

	cin >> num_monsters;

	if (num_monsters > 0)
	cout << "Fib " << num_monsters << ": " << Fib_tail(num_monsters, 0, 1) << endl;
	*/
}