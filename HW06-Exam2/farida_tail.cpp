#include <iostream>
#include <algorithm>

using namespace std;


long long farida_rec(int mNum, long long FN1, long long FN2, long long m) {
	long long coin;
	cin >> coin;
	//if (mNum == 0) return 0;
	//if (mNum == 1) return coin;
	//if (mNum == 1) return max(FN1, FN2);

	long long temp = max(FN2, FN1 + coin);
	if (mNum == 1) return temp;
	//return farida_rec(mNum - 1, FN2 + coin, FN1);
	return farida_rec(mNum-1, FN2, FN1+coin, temp);   //Doesn't work either. It just returns that value at the bottom of the recursion
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

	for (int i = 0; i < num_cases; i++) {
		cin >> num_monsters;
		//cin >> temp;
		cout << "Case " << i + 1 << ": " << farida_rec(num_monsters, 0, 0, 0) << endl;
	}

	/*
	--- This is to test Fib_tail. Fib_tail works---

	cin >> num_monsters;

	if (num_monsters > 0)
	cout << "Fib " << num_monsters << ": " << Fib_tail(num_monsters, 0, 1) << endl;
	*/
}