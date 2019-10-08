/*

the code object is to calculate a worker wage 
--------------------------------------
Write a C program that calculates a worker’s wages from their hours worked and hourly rate. 
This wage calculator should also account for overtime hours,
calculate amount to be witheld from taxes,
and calculate the final net income.
---------------------------------------
Abdulrahman Aldhubaiban
*/





#include <stdio.h>

#define tax_rate .15
#define max_normal_hours 40

// main method 
int main(void)

{
//declare variables 
float hours_worked=0.0, hours_rate=0.0;
float normal_income=0.0, tax=0.0, net_income=0.0,overtime=0.0; 

// prompt the user to enter hours worked and rate 
printf("Enter the number of you have worked: ");
scanf("%f",& hours_worked);


// input validation for hours 
while(hours_worked<0)
{
printf("Enter the number of you have worked: ");
scanf("%f",& hours_worked);
}


printf("Enter your hourly wage in US dollars: ");
scanf("%f",& hours_rate);
printf("\n\n");






// if statement to distinguish overtime hours 
if (hours_worked<=40)
{

normal_income= (hours_worked*hours_rate); 
tax= (normal_income* tax_rate) ;
net_income= (normal_income-tax);


printf("Description\t\t Amount\n-----------------------------------\n");
printf("Normal income:\t\t$%10.2f \n",normal_income);
printf("Overtime income:\t$\t0.00 \n");
printf("Taxes withheld:\t\t$%10.2f",tax);
printf("\n-----------------------------------\n");
printf("Net income:\t\t$%10.2f \n\n",net_income);


}
else
{
// equation to calculate the wage 	
normal_income= (max_normal_hours*hours_rate); 
overtime= (hours_rate*(1.5) *(hours_worked-max_normal_hours));
tax= (normal_income+overtime)*( tax_rate) ;
net_income= (normal_income+overtime-tax);



printf("Description\t\tAmount\n-----------------------------------\n");
printf("Normal income:\t\t$%10.2f \n",normal_income);
printf("Overtime income:\t$%10.2f \n",overtime);
printf("Taxes withheld:\t\t$%10.2f",tax);
printf("\n-----------------------------------\n");
printf("Net income:\t\t$%10.2f \n\n",net_income);


}


return 0;
}

