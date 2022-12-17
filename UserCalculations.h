/*
	Tyler Smith
	CS 210
	11/27/2022
	Airgead Banking Application
*/

#ifndef AIRGEADBANKING_USERCALCULATIONS_H_
#define AIRGEADBANKING_USERCALCULATIONS_H_

#include "InvestmentCalculations.h"

class UserCalculations   // Class to calculate user input data
{

public:
	void calculateWithoutDeposits(InvestmentCalculations t_userInvestment);
	void calculateWithDeposits(InvestmentCalculations t_userInvestment);
};

#endif   // AIRGEADBANKING_USERCALCULATIONS_H_