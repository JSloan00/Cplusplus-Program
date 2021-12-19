#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Declare variables to store data
	float initialInvestment;
	float monthlyDeposit;
	float annualInterest;
	float months;
	float years;
	float totalAmt;
	float initialAmt;
	float yearTotInt;

	//Display menu and get input from user
	cout << "********************************" << endl;
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> years;

	//Set months by multiplying amount of years inputted by user with 12
	months = years * 12;

	//Display data and wait for input from user
	system("PAUSE");

	//Update totalAmt to the initialInvestment inputted from user
	totalAmt = initialInvestment;

	//Display year data without monthly deposits
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	//Loops through years inputted by user
	for (int i = 0; i < years; i++) {

		//Calculate yearly interest rate
		initialAmt = (totalAmt) * ((annualInterest / 100));

		//Calculate total at end of year
		totalAmt = totalAmt + initialAmt;

		//Output results of totalAmt and initialAmt
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << initialAmt << "\n";
	}

	totalAmt = initialInvestment;

	//Display year data WITH monthly deposits
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";

	//Loop through years
	for (int i = 0; i < years; i++) {

		//Yearly interest rate must be 0 at beginning of year
		yearTotInt = 0;

		//Loop through months in a year
		for (int j = 0; j < 12; j++) {

			//Calculate monthly interest
			initialAmt = (totalAmt + monthlyDeposit) * ((annualInterest / 100) / 12);

			//Calculate end of month interest
			yearTotInt = yearTotInt + initialAmt;

			//Calculate end of month total
			totalAmt = totalAmt + monthlyDeposit + initialAmt;
		}

		//Output results of totalAmt and yearTotInt
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmt << "\t\t\t$" << yearTotInt << "\n";
	}

	return 0;
}

