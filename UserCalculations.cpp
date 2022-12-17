/*
	Tyler Smith
	CS 210
	11/27/2022
	Airgead Banking Application
*/

#include <format>   // Requires C++20 to use. Necessary to format the output
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "UserCalculations.h"

using namespace std;

void UserCalculations::calculateWithoutDeposits(InvestmentCalculations t_userInvestment)   // Displays investment info w/o monthly deposits
{
	double initialInvestment = t_userInvestment.getInitialInvestment();   // Gets the inital investment
	int years = t_userInvestment.getNumOfYears();   // Gets the number of years to calculate

	// Allows the title to be centered
	int screenWidth = 62;
	string balanceMsg = "Balance & Interest Without Additional Monthly Deposits";
	int centerScreen = balanceMsg.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;

	cout << endl;
	// Creates a header for the investment information
	cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(screenWidth) << '=' << endl;
	cout << "  Year        Year End Balance     Year End Earned Interest     " << endl;
	cout << setfill('-') << setw(screenWidth) << '-' << endl;

	t_userInvestment.setTotalWithoutDeposits(initialInvestment);   // Adds the inital amount to the total
	double interestYTD = 0;

	unsigned int yearCount, monthCount;   // Loop variables

	for (yearCount = 1; yearCount <= years; yearCount++)   // Loop based on user input for years
	{
		for (monthCount = 1; monthCount <= 12; monthCount++)   // Calculates the interest per month
		{
			interestYTD += t_userInvestment.calcInterestWithoutDeposits();
		}
		t_userInvestment.setTotalWithoutDeposits(interestYTD);	// Adds total interest from the year to total
		cout << setfill(' ') << right << setw(6) << yearCount;
		cout << setfill(' ') << right << setw(24) << format("${:.2f}", t_userInvestment.getTotalWithoutDeposits());   // Formats output to 2 decimal places and aligns to right
		cout << setfill(' ') << right << setw(29) << format("${:.2f}", interestYTD) << endl;   // Formats output to 2 decimal places and aligns to right

		interestYTD = 0; // Resets for next loop
	}
}

void UserCalculations::calculateWithDeposits(InvestmentCalculations t_userInvestment)   // Display for investment w/ monthly deposits
{
	double initialInvestment = t_userInvestment.getInitialInvestment();   // Gets the initial investment amount
	double monthlyDeposit = t_userInvestment.getMonthlyDeposit();   // Gets monthly deposit amount
	int years = t_userInvestment.getNumOfYears();   // Gets the number of years to calculate

	// Allows the title to be centered
	int screenWidth = 62;
	string balanceMsg = "Balance & Interest With Additional Monthly Deposits";
	int centerScreen = balanceMsg.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;

	cout << endl;

	// Creates a header for the investment information
	cout << setfill(' ') << setw(sizeToCenter) << balanceMsg << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(screenWidth) << '=' << endl;
	cout << "  Year        Year End Balance     Year End Earned Interest     " << endl;
	cout << setfill('-') << setw(screenWidth) << '-' << endl;

	t_userInvestment.setTotalWithDeposits(initialInvestment);   // Adds the initial amount to the total

	double interestYTD = 0;   // Resets interest totals

	unsigned int yearCount, monthCount;

	for (yearCount = 1; yearCount <= years; yearCount++)   // Loop based on user input for years
	{
		for (monthCount = 1; monthCount <= 12; monthCount++)   // Calculates the interest per month
		{
			t_userInvestment.setTotalWithDeposits(monthlyDeposit);			// Adds the monthly deposit to total
			double interest = t_userInvestment.calcInterestWithDeposits();	// Gets interest calculation
			t_userInvestment.setTotalWithDeposits(interest);				// Adds the new interest to total
			interestYTD += interest;
		}

		cout << setfill(' ') << right << setw(6) << yearCount;
		cout << setfill(' ') << right << setw(24) << format("${:.2f}", t_userInvestment.getTotalWithDeposits());   // Formats output to 2 decimal places and aligns to right
		cout << setfill(' ') << right << setw(29) << format("${:.2f}", interestYTD) << endl;   // Formats output to 2 decimal places and aligns to right

		interestYTD = 0; // Resets interest for the next loop
	}
}