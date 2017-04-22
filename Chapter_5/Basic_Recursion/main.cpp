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

/*
 *  fib(n) = { n					if n < 2
 *  	     { fib(n-2) + fib(n-1)	else
 *
 * Simple BUT EXTERMLY INEFFICENT
 * -Does the same stuff multiple times
 *  resulting in way to many function calls
 */
unsigned long fibonacci(unsigned long n){
	if(2 > n)
		return n;
	else
		return fibonacci(n-2) + fibonacci(n-1);

	//result = (2 > n) ? n : fibonacci(n-1) + fibonacci(n-2);
	//return result;
}

// iterative alternative to fibonacci sequency
unsigned long iterativeFibonacci(unsigned long n){
	if(2 > n)
		return n;
	else{
		register long i = 2, current = 0, last = 1, temp;
		for(i; i <= n; i++){
			temp = current;				// t: 0,1,1,2,3,5,8,13
			current = current + last;	// c: 1,1,2,3,5,8,13,21
			last = temp;				// l: 0,1,1,2,3,5,8,13
		}
		return current;
	}
}

int main(int argc, char *argv[]){
	long fibIn;

	cout << "-- Chapter 5: Recursion --" << endl;

	cout << "power(2,4) = " << power(2,4) << endl;

	cout << "tail recursion: "; tail(5);

	cout << "\nnonTail recursion (reverse): " << endl;
	cout << "Type a message: ";
	reverse();

	cout <<"\nFibonacci: ";
	cin >> fibIn;
	cout << fibonacci(fibIn) << endl;
	cout << iterativeFibonacci(fibIn) << endl;

	return 0;
}


