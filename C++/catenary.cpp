#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

//Declaration of variables
long double b, h;
int iter;
long double a;

//Function to find P (as in A=x*10^P)
int nform (long double A){
	int P;
	if (A < 10){
	P = 0;
	while (A < pow(10,P) && A != pow(10,P)){
		P--;
	}
	}
	else{
		P = 1;
		while (A >= pow(10,P)){
			P++;
		}
		P--;
	}
	return P;
};
/*
//Custom cosh function using definition with extended digits of Euler's number
long double coshh (long double A){
	long double e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427427466391932003059921817413596629043572900334295260595630738132328627943490763233829880753195251019;
	return (pow(e,A)+pow(e,-A))/2;
}*/
//Function to get difference of real height to calculated height 
long double compcat (long double A){
	return (cosh(A*b)/A)-(h+1/A);
};
//Sign function, returns -1, 0, 1
int sgn (long double n){
	return (0 < n) - (n < 0);
};


int main(void){
	//Input values
    cout << "Input bredth: ";
    cin >> b;
	cout << "      height: ";
	cin >> h;
	cout << endl;
    cout << "Estimation using second-order Maclaurin series: " << 2*h/pow(b,2) << endl
        << "Input number of iterations (Significant Figures desired) for estimate: ";
    cin >> iter;
    a = 2*h/pow(b,2);

	//Start of iterative solving
    //Set p (as in a=x*10^p)
	int p = nform(a);
    for (int r = 0; r < iter; r++){
		//While a is not the closest approximation within the decimal place, work towards it.
		while (!(abs(compcat(a-pow(10,p-r))) > abs(compcat(a)) && abs(compcat(a-pow(10,p+r))) > abs(compcat(a)))){
			a-=sgn(compcat(a))*pow(10,p-r);
			cout << "On decimal " << p-r << " difference is " << compcat(a) << endl;
		}
		cout << "Decimal " << p-r << " done" << endl;
    }
	cout << fixed;
	cout << setprecision(iter-p);

	cout << "The estimate correct until ~" << iter << " Significant Figures is: " << endl << a << endl;
}
