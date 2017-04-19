/*
 * main.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: jack
 */
#include <iostream>

using namespace std;
/*
 *
 * x^n = { 1			if n = 0
 * 		 { x*x^(n-1)	if n > 0
 * */
double power(double x, unsigned int n) {
	if(0 == n)
		return 1.0;
	else
		return x * power(x, n-1);
}

double nonRecPower(double x, unsigned int n){
	double result = 1;
	for(result = x; n > 1; n--)
		result *= x;
	return result;
}

// Tail recursion
void tail(int i){
	if(i > 0) {
		cout << i << ' ';
		tail(i-1);
	}
}

void iterativeEquivalentOfTail(int i){
	for(; i > 0; i--)
		cout << i << ' ';
}

// NonTail Recursion - Figure 5.3
void reverse(){
	char ch;
	cin.get(ch);

	if(ch != '\n'){
		reverse();
		cout.put(ch);
	}
}
int main(int argc, char *argv[]){
	cout << "-- Chapter 5: Recursion --" << endl;

	cout << "power(2,4) = " << power(2,4) << endl;

	cout << "tail recursion: "; tail(5);

	cout << "\nnonTail recursion (reverse): " << endl;
	cout << "Type a message: ";
	reverse();

	return 0;
}


