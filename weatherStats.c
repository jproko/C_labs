/************************************************************
*                                                           *
* Author            : Julian Proko                          *
* Purpose           : C Programming Challenge               *
* Section           : 6.0                                   *
* Version           : 2.0                                   *
* Description       : Print all the primes beetween 0-100   *
* Date Created      : 08/05/2021                            *
* Last Modification : 08/05/2021                            *
*                                                           *
*************************************************************/
#include <stdio.h>

int main()
{
    //In this challenge, we are required to extract some statistic values
    //Specifically, we have to hardcode rainfall statistics and extract the following:
    //1. Yearly total rainfall
    //2. Yearly average rainfall
    //3. Monthly average rainfall

    //The data (which are extracted from: http://www.meteoacharnes.gr/statistika/datasummary.html) represent
    //the rainfall amount (in mm) for the past 5 years in Acharnai Area, Athens, Greece

    //declaring and initializing data
    unsigned long int years=0;
    unsigned long int months = 0;
    unsigned short int yearToBeDisplayed = 2015;
    double totalRainfallPerYear = 0.0;
    double totalRainfallPerLastYear = totalRainfallPerYear;
    double totalRainfallOfFive = 0.0;
    double yearlyAvgRainfall = 0.0;
    double monthlyAvgRainfall = 0.0;

    float yearlyRainfallStats [6][12] = 
    {
        //January - December (abs in mm)
        {53.10f, 72.00f, 88.20f, 13.80f, 09.30f, 50.40f, 01.50f, 00.00f, 82.50f, 144.70f, 55.40f, 04.40f}, //Year: 2015
        {41.20f, 34.20f, 56.40f, 00.00f, 02.40f, 36.80f, 00.00f, 00.00f, 19.80f,  25.10f, 96.00f, 38.00f}, //Year: 2016
        {44.80f, 18.10f, 60.60f, 08.01f, 47.80f, 59.90f, 02.80f, 00.00f, 15.10f, 01.20f, 109.90f, 18.70f}, //Year: 2017
        {66.20f, 83.30f, 11.70f, 01.50f, 44.30f, 118.1f, 88.00f, 06.50f, 87.70f, 03.70f,  60.10f, 59.50f}, //Year: 2018
        {115.3f, 89.60f, 18.60f, 59.00f, 04.00f, 02.50f, 07.70f, 00.00f, 13.60f, 13.00f, 111.80f, 143.7f}, //Year: 2019
        {43.90f, 32.10f, 48.20f, 25.90f, 35.50f, 09.30f, 00.00f, 27.30f, 12.70f, 27.50f, 09.80f, 124.60f}  //Year: 2020
    };

    //display UI
    printf("\nDisplaying rainfall statistics for the time period: 2015 - 2020\n");
    printf("Meteorological station location: Acharnai, Athens, Greece\n");
    printf("------------------------------------------------------------\n");
    //now, in just 1 multiple for loop, we can gather and display all the required data
    for (years;years<6;years++)
    {
        printf("Year:%hu", yearToBeDisplayed);
        for (months;months<12;months++)
        {
            totalRainfallPerYear += yearlyRainfallStats[years][months];
        }
        printf("\t %.2lf (mm)", totalRainfallPerYear);

        if(years !=0)
        {
            printf("\t%.2lf%c\n",((totalRainfallPerYear - totalRainfallPerLastYear)/totalRainfallPerYear)*100, 37);
        }
        else
        {
            printf("\n");
        }
        totalRainfallPerLastYear = totalRainfallPerYear;
        yearToBeDisplayed+=1;
        totalRainfallOfFive +=totalRainfallPerYear;
        totalRainfallPerYear = 0.0; 
        months=0;
    }
    printf("------------------------------------------------------------\n");
    printf("The average rainfall per year is: %.2lf (mm)\n", totalRainfallOfFive/5);
    printf("------------------------------------------------------------\n");
    printf("Displaying average monthly statistics:\n");
    
    years=0;
    for (months; months<12;months++)
    {
        switch (months)
        {
            case 0:
            printf("Month: Jan");
            break;

            case 1:
            printf("Month: Feb");
            break;

            case 2:
            printf("Month: Mar");
            break;

            case 3:
            printf("Month: Apr");
            break;

            case 4:
            printf("Month: May");
            break;

            case 5:
            printf("Month: Jun");
            break;

            case 6:
            printf("Month: Jul");
            break;

            case 7:
            printf("Month: Aug");
            break;

            case 8:
            printf("Month: Sep");
            break;

            case 9:
            printf("Month: Oct");
            break;

            case 10:
            printf("Month: Nov");
            break;

            case 11:
            printf("Month: Dec");
            break;

            default:
            printf("Something went wrong");
            break;
        }
        
        for(years;years<6;years++)
        {
            monthlyAvgRainfall += yearlyRainfallStats[years][months];
        }
        printf("\t %.2lf (mm)\n", monthlyAvgRainfall/12);

        monthlyAvgRainfall=0.0;
        years=0;
    }


    return 0;
}