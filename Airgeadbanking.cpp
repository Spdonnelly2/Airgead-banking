//Airgeadbanking.cpp
#include "Airgeadbanking.h"

void Airgeadbanking::Data(int Years, double Yearly_int, double First_dep, double Monthly_dep) {
	this->Years = Years;
	this->Yearly_int = Yearly_int;
	this->First_dep = First_dep;
	this->Monthly_dep = Monthly_dep;
}

void Airgeadbanking::deposit(double Monthly_dep) {
	this->Monthly_dep = Monthly_dep;
}

void Airgeadbanking::Int_Calc() { //Declares variables
	int Month;
	int Months_tot;
	double Current_int;
	double total_dep;
	double Mon_int;
	double Mon_dep;
	
	Month = 1; //Initializes variables
	Months_tot = Years * 12;
	total_dep = First_dep; 
	Current_int = 0.00;
	Mon_int = (Yearly_int / 100) / 12;
	Mon_dep = Monthly_dep;
	List_int.clear(); //Clears vector elements
	List_tot.clear();
	
	while (Month <= Months_tot) { //Monthly loop and calculations
		total_dep += Mon_dep; 
		Current_int = total_dep * Mon_int; 
			List_int.push_back(Current_int);
			total_dep += Current_int; 
			List_tot.push_back(total_dep); 
			Month++;
	}
}

void Airgeadbanking::Main_H() {
	cout << setw(10) << left << "Year" << flush;
	cout << setw(20) << left << "Year End Balance" << flush;
	cout << setw(10) << right << "Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------"
		<< endl;

}

void Airgeadbanking::Main_H2() {
	cout << "Balance and Interest without additional monthly deposits" << endl;
	cout << "--------------------------------------------------------------"
		<< endl;
	cout << "--------------------------------------------------------------"
		<< endl;
	this->Main_H();
}

void Airgeadbanking::Main_H1() {
	cout << "Balance and Interest with additional monthly deposits" << endl;
	cout << "--------------------------------------------------------------"
		<< endl;
	cout << "--------------------------------------------------------------"
		<< endl;
	this->Main_H();
}

void Airgeadbanking::Result() {
	double Sum_int = 0;
	cout << setprecision(2) << fixed << endl;
	for (int i = 1; i <= Years; i++) {
		cout << setw(10) << left << i << flush;
		cout << setw(20) << left << List_tot.at((i * 12) - 1) << flush;
		for (int j = (i - 1) * 12; j <= (i * 12) - 1; j++) {
			Sum_int += List_int.at(j);
		}
		cout << setw(10) << left << Sum_int << endl;
		cout << endl;
	}
}
