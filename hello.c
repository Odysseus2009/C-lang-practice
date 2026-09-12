++	/*This is My First Program*/
	#include <stdio.h> 
	#include <math.h>
	int main(void){
		double principal,rate,time;
		double simple_interest,compound_interest,amount;
		
		printf("Enter Principal Amount");
		scanf("%lf",&principal);
		
		printf("Enter Annual Rate Amount(in%%)");
		scanf("%lf",&rate);
		
		printf("Enter Time Period(In years)");
		scanf("%lf",&time);
		
		//Calculate simple interest
		simple_interest = (principal * rate * time)/100.0;
		amount = principal * pow((1.0 + rate / 100.0), time);
		compound_interest = amount - principal;
		
		//Showing results
		printf("---RESULTS---\n");
		printf("Simple Interest   =%.2lf\n", simple_interest);
		printf("Compound Interest   =%.2lf\n", compound_interest);
		printf("Amount   =%2.lf\n", amount);
		
		return 0;
		
		}
		
