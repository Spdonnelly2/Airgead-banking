//AirgeadBanking main.cpp
#include <string>
#include <cctype>
#include "Airgeadbanking.h"
using namespace std;

bool cont_Loop(string prompt); //prompts user for input and checks data provided

void dataInput(Airgeadbanking* plan);

int main() {

	Airgeadbanking* app = new Airgeadbanking;
	bool continue_L = true;
	while (continue_L) {
		dataInput(app);
		app->Main_H1(); 
		app->Int_Calc();
		app->Result();
		app->deposit(0); 
		app->Main_H2(); 
		app->Int_Calc();
		app->Result();
		continue_L = cont_Loop("Exit? (y for yes) ");
	}

	return 0;
}

bool cont_Loop(string prompt) {
	bool continue_L = true;
	string User_continue;
	cout << prompt;
	cin >> User_continue;
	if (tolower(User_continue.at(0)) == 'y') {
		continue_L = false;
	}

	cout << endl;
	return continue_L;
}
void dataInput(Airgeadbanking* plan) {
	int Years;
	double Yearly_int;
	double First_dep;	double deposit;
	bool continue_L = true;
	string user_continue;
	while (continue_L) {
		try {
			cout << "************************************" << endl;
			cout << "************ Data Input ************" << endl;
			cout << "Initial Investment Amount: " << flush;
			cin >> First_dep;
			if (First_dep < 0) {
				throw runtime_error("Initial Investment Amount must greater than 0.");
			}

			cout << "Monthly Deposit: " << flush;
			cin >> deposit;
			if (deposit < 0) {
				throw runtime_error("Monthly Deposit must be greater than 0");
			}

			cout << "Annual Interest (%): " << flush;
			cin >> Yearly_int;
			if (Yearly_int < 0) {
				throw runtime_error("Annual Interest must be greater than 0");
			}

			cout << "Number of years: " << flush;
			cin >> Years;
			if (Years < 1) {
				throw runtime_error("Number of Years must be 1 or greater.");
			}

			continue_L = cont_Loop("Continue? (y for yes) ");
		}

		catch (runtime_error& error) {
			cout << "ERROR: " << error.what() << endl;
			cout << endl;
		}
	}
	
	plan->Data(Years, Yearly_int, First_dep, deposit);
}