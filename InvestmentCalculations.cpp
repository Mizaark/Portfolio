/*
    Tyler Smith
    CS 210
    11/27/2022
    Airgead Banking Application
*/

#include <iostream>
#include "InvestmentCalculations.h"

using namespace std;

void InvestmentCalculations::setInitialInvestment(double t_initialInvestment)   // Sets initial investment
{
    this->m_initialInvestment = t_initialInvestment;
}

void InvestmentCalculations::setMonthlyDeposit(double t_monthlyDeposit)   // Sets monthly deposit
{
    this->m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentCalculations::setAnnualInterest(double t_annualInterest)   // Sets annual interest
{
    this->m_annualInterest = t_annualInterest;
}

void InvestmentCalculations::setNumOfYears(int t_numOfYears)   // Sets number of years
{
    this->m_numOfYears = t_numOfYears;
}

double InvestmentCalculations::calcInterestWithoutDeposits()   // Calculates interest without deposits
{
    return ((this->m_totalWithoutDeposits) * ((this->m_annualInterest / 100) / 12));
}

double InvestmentCalculations::calcInterestWithDeposits()   // Calculates interest with deposits
{
    return ((this->m_totalWithDeposits) * ((this->m_annualInterest / 100) / 12));
}

void InvestmentCalculations::setTotalWithoutDeposits(double t_amount)   // Sets total without deposits
{
    this->m_totalWithoutDeposits += t_amount;
}

void InvestmentCalculations::setTotalWithDeposits(double t_amount)   // Sets total with deposits
{
    this->m_totalWithDeposits += t_amount;
}

double InvestmentCalculations::getTotalWithoutDeposits()   // Gets total without deposits
{
    return this->m_totalWithoutDeposits;
}

double InvestmentCalculations::getTotalWithDeposits()   // Gets total with deposits
{
    return this->m_totalWithDeposits;
}