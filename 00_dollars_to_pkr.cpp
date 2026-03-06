#include <iostream>
using namespace std;
int main(){
	float dollars;
	float pkr = 285;
	float result;
	
	cout<< "Dollars to PKR Converter";
	cout<< "Enter the number of dollars: ";
	
	cin>> dollars;
	result = dollars * pkr;
	
	cout<< "$"<<dollars << " into PKR is :"<< result;
	
}
