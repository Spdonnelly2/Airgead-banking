//Airgeadbanking.h
#pragma once
#ifndef AIRGEADBANKING_H
#define AIRGEADBANKING_H
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Airgeadbanking {
public:
	void Data(int, double, double, double);
	void deposit(double);
	void Int_Calc();
	void Main_H1();
	void Main_H2();
	void Result();
private:
	void Main_H();
	int Years = 0;
	double Yearly_int = 0.00;
	double First_dep = 0.00;
	double Monthly_dep = 0.00;
	vector<double> List_int;
	vector<double> List_tot;
};

#endif