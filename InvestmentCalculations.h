/*
	Tyler Smith
	CS 210
	11/27/2022
	Airgead Banking Application
*/

#ifndef AIRGEADBANKING_INVESTMENTCALCULATIONS_H_
#define AIRGEADBANKING_INVESTMENTCALCULATIONS_H_

class InvestmentCalculations   // Class to calculate the investment data
{
public:
	// Setters
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterest(double t_annualInterest);
	void setNumOfYears(int t_years);
	void setTotalWithoutDeposits(double t_amount);
	void setTotalWithDeposits(double t_amount);

	// Getters
	double getInitialInvestment() { return m_initialInvestment; }
	double getMonthlyDeposit() { return m_monthlyDeposit; }
	double getAnnualInterest() { return m_annualInterest; }
	int getNumOfYears() { return m_numOfYears; }
	double getTotalWithoutDeposits();
	double getTotalWithDeposits();

	// Calculation methods
	double calcInterestWithoutDeposits();
	double calcInterestWithDeposits();

private:
	double m_initialInvestment = 0.0;
	double m_monthlyDeposit = 0.0;
	double m_annualInterest = 0.0;
	int m_numOfYears = 0;
	double m_totalWithoutDeposits = 0.0;
	double m_totalWithDeposits = 0.0;
};

#endif // AIRGEADBANKING_INVESTMENTCALCULATIONS_H_