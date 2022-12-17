/*
	Tyler Smith
	CS 210
	11/27/2022
	Airgead Banking Application
*/

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "InvestmentCalculations.h"
#include "UserCalculations.h"

using namespace std;

void dataInterface()
{
	InvestmentCalculations userInvestment; // Creates an object of the InvestmentData class
	UserCalculations dataCalculations; // Creates an object of the UserDataCalculations class

	double initialAmount, monthlyDeposit, interestRate; // User input variables
	int yearsToCalculate;

	string choice;
	bool keepRunning = true;

	do
	{
		cout << setw(34) << setfill('*') << '*' << endl;
		cout << "*********** Data Input ***********" << endl;
		cout << "Initial Investment Amount: $";
		cin >> initialAmount;   // Gets user input for initial investment

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;   // Gets user input for monthly deposit

		cout << "Annual Interest: %";
		cin >> interestRate;   // Gets user input for interest rate

		cout << "Number of years: ";
		cin >> yearsToCalculate;   // Gets user input for the number of years to display
		system("pause");

		userInvestment.setInitialInvestment(initialAmount);   // Sets the initial investment amount
		userInvestment.setMonthlyDeposit(monthlyDeposit);   // Sets the monthly deposit amount
		userInvestment.setAnnualInterest(interestRate);   // Sets the interest rate
		userInvestment.setNumOfYears(yearsToCalculate);   // Sets the years

		try   // Executes the method to display data without deposits
		{
			dataCalculations.calculateWithoutDeposits(userInvestment);
		}
		catch (const exception& exc)
		{
			cout << exc.what() << endl;
			cout << "Error occurred with dataWithoutDeposits" << endl;
			keepRunning = false;
		}

		try   // Executes the method to display data with deposits
		{
			dataCalculations.calculateWithDeposits(userInvestment);
		}
		catch (const exception& exc)
		{
			cout << exc.what() << endl;
			cout << "Error occurred with dataWithDeposits" << endl;
			keepRunning = false;
		};

		cout << "\nRun investment calculations again? Enter y/n: ";
		cin >> choice;   // Input for if user wants to continue

		if (choice == "n")
		{
			keepRunning = false;
		}
		else
		{
			system("CLS");
			continue;
		}
	}
	while (keepRunning == true);

}

int main()
{
	try
	{
		dataInterface();
	}
	catch (const exception& exc)
	{
		cout << exc.what() << endl;
		cout << "Error occurred with dataInterface" << endl;
		system("pause");
	}
}