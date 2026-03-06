#include <iostream>
using namespace std;
int main(){
	int km;
	float mile = 0.621;
	float result;
	
	cout<< "KM to Miles Calculator\n\n";
	cout<< "Enter Kilometers to convert it into Miles: ";
	cin>> km;
	
	result = km * mile;
	cout<< km <<" Kilometers into Miles are:";
	cout<<result <<" Miles";
}
