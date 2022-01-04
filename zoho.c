#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int load_cash();
int maintain_customer_details();
int handle_atm_operations();
int isvalid(int);
int Check_Balance(int);
int Withdraw_Money(int);
int Transfer_Money();
int user_account(int);
int check_ATM_balance();

//Structure declaration for denominations of cash details
struct denominations{
    int two_thousands,five_hundreds,hundreds;
}d;

//Structure declaration for customer details
struct customer_entry{
    int acc_no;
    char Name[50];
    int pin;
    int acc_balance;
}s[100];

int total_balance_in_ATM=0 , no_of_customers = 5;


//To load cash to the ATM 
int load_cash(){	
	printf("Enter the number of Two Thousands:\t");
	scanf("%d",&(d.two_thousands));
	printf("Enter the number of Five Hundreds:\t");
	scanf("%d",&(d.five_hundreds));
	printf("Enter the number of Hundreds:\t\t");
	scanf("%d",&(d.hundreds));
	total_balance_in_ATM += (2000*d.two_thousands)+(500*d.five_hundreds)+(100*d.hundreds);
	printf("\n-------------------------------------------------------\n");
	printf("Denomination\tNumber\t\tValue\n");
	printf("-------------------------------------------------------\n");
	printf("2000\t\t%d\t\t%d\n",(d.two_thousands),(2000*d.two_thousands));
	printf("-------------------------------------------------------\n");
	printf("500\t\t%d\t\t%d\n",(d.five_hundreds),(500*d.five_hundreds));
	printf("-------------------------------------------------------\n");
	printf("100\t\t%d\t\t%d\n",(d.hundreds),(100*d.hundreds));
	printf("-------------------------------------------------------\n");	
	printf("Total available cash in the ATM is : %d\n",total_balance_in_ATM);
}

//To create customers details
int customer_details_entry()
{
    s[0].acc_no =101;
    strcpy(s[0].Name,"Suresh");
    s[0].pin = 2343;
    s[0].acc_balance = 25234;
    
    s[1].acc_no =102;
    strcpy(s[1].Name,"Ganesh");
    s[1].pin = 5432;
    s[1].acc_balance = 34123;
    
    s[2].acc_no =103;
    strcpy(s[2].Name,"Magesh");
    s[2].pin = 7854;
    s[2].acc_balance = 26100;
    
    s[3].acc_no =104;
    strcpy(s[3].Name,"Naresh");
    s[3].pin = 2345;
    s[3].acc_balance = 80000;
    
    s[4].acc_no =105;
    strcpy(s[4].Name,"Harish");
    s[4].pin = 1907;
    s[4].acc_balance = 103400;
}

//To maintain all the customer details
int maintain_customer_details(){
    int i;
    printf("-----------------------------------------------------\n");
    printf("Acc_No\tAccount_Holder\tPin_Number\tAccount_Balance\n");
    printf("-----------------------------------------------------\n");
    for(i=0;i<no_of_customers;i++)
	    printf(" %d\t  %s\t  %d\t\t %d\n",s[i].acc_no,s[i].Name,s[i].pin,s[i].acc_balance);
			printf("---------------------------------------------------\n");     
}

//To handle atm operation for the customer
int handle_atm_operations()
{
	int choices,pin,acc_no,flag;
	printf("1. Check Balance\n");
	printf("2. Withdraw Money\n");
	printf("3. Transfer Money\n");
	printf("Enter the operation to be performed: ");
	scanf("%d",&choices);
	if(choices>0 & choices<4)
	{
		printf("Enter your account number \n");
		scanf("%d",&acc_no);
		if(acc_no == s[0].acc_no)
			flag = 0;
		else if(acc_no == s[1].acc_no)
			flag = 0;
		else if(acc_no == s[2].acc_no)
			flag = 0;
		else if(acc_no == s[3].acc_no)
			flag = 0;
		else if(acc_no == s[4].acc_no)
			flag = 0;
		else 
			flag = 1;
			
		
		if(flag==0)
		{
			printf("Enter you Pin\n");
			scanf("%d",&pin);
			if(isvalid(pin))
			{
				switch(choices)
				{
					case 1:
						Check_Balance(pin);
						break;
					case 2:
						Withdraw_Money(pin);
						break;
					case 3:
						Transfer_Money(pin);
						break;
					default:
						printf("Invalid Entry");
						break;
				}
			}
		}
	}
}
 
//To check the pin is correct or not 
int user_account(int p)
{
	if(p == s[0].pin)
		return 0;
	else if(p == s[1].pin)
		return 1;
	else if(p == s[2].pin)
		return 2;
	else if(p == s[3].pin)
		return 3;
	else if(p == s[4].pin)
		return 4;
	else 
		return -1;	
}

int isvalid(int p)
{
	if(user_account(p) == -1)
		return 0;
	
	return 1;
}

//To check the Account Balance of the customer
int Check_Balance(int p)
{
	int i;
	i = user_account(p);
	printf("%d",i);
	printf("---------------------------------------------------\n");
	printf("Your Account Balance is : %d",s[i].acc_balance);
	printf("\n---------------------------------------------------\n");	
	return 0;
}


//To Withdraw the money from ATM
int Withdraw_Money(int p)
{
	int i,amt;
	printf("NOTE : Your withdrawal money should be above 100 and below 10000\n");
	printf("Enter the Amount to be Withdrawn : ");
	scanf("%d",&amt);
	if((amt<100||amt>10000) && (amt%100 == 0))
		printf("Enter the valid amount\n");
	else if(amt>total_balance_in_ATM)
		printf("The ATM has insufficient funds");
	else
		{
			i = user_account(p);
			if(amt > s[i].acc_balance)
				printf("The account balance is lower than entered withdrawal amount");
			else
			{
			  	s[i].acc_balance -= amt;
			   	d.two_thousands -= amt/2000;
			  	amt -= amt/2000;
			  	d.five_hundreds -= amt/1000;
			  	amt -= amt/1000;
			  	d.hundreds -= amt/100;
			  	amt -= 100;
				total_balance_in_ATM -= amt;
				printf("-----Please Collect the Cash-----Visit again------\n");
			}
		}
}

//To transfer money from one account to another account
int Transfer_Money(int p)
{
    int amt,i,j,acc,valid;
	printf("NOTE: Max transfer limit per transaction is above 1000 and below 10000\n");
 	printf("Enter the Amount to be transfered : ");
 	scanf("%d",&amt);
	if ((amt<100 || amt >10000) && ((amt%100) == 0))
		printf("Enter the valid amount\n");
 	i = user_account(p);
 	if(amt > s[i].acc_balance)
	   printf("Account balance is lower than entered amount\n"); 
	else
	{
		printf("Enter the Account Number to which the money has to be transfered : ");
	  	scanf("%d",&acc);
	  	for(j=0;j<no_of_customers;j++)
	  	{
	  		if(s[j].acc_no == acc)
	  		   {
				 valid = 1;
	  		     break;
				} 
		  }
		if(valid)
		{
		  	s[i].acc_balance -= amt;
		  	s[j].acc_balance += amt;
		  	printf("-------------TRANSACTION SUCCESSFULL-------------\n");
		}
		else
		 printf("Invalid Account number\n");
	}	  
 }
//To display the remaining cash amount in ATM 
int check_ATM_balance()
{
	int total=total_balance_in_ATM-101;
	printf("\n-------------------------------------------------------\n");
	printf("Denomination\tNumber\t\tValue\n");
	printf("-------------------------------------------------------\n");
	printf("2000\t\t%d\t\t%d\n",(d.two_thousands),(2000*d.two_thousands));
	printf("-------------------------------------------------------\n");
	printf("500\t\t%d\t\t%d\n",(d.five_hundreds),(500*d.five_hundreds));
	printf("-------------------------------------------------------\n");
	printf("100\t\t%d\t\t%d\n",(d.hundreds),(100*d.hundreds));
	printf("-------------------------------------------------------\n");
	printf("Total available cash in the ATM is : %d\n",total);
}


//To display the choices when user enter the ATM
int main()
{
	int choice;
	customer_details_entry();
    do{
        printf("\n-----------Welcome to the ATM service--------------\n");
		printf("1. Load Cash to ATM\n");
		printf("2. Maintain Customer Details\n");
		printf("3. Handle ATM Process\n");
		printf("4. Check ATM Balance\n");
		printf("5. Quit\n");
		printf("--------------------------------------------------\n\n");
		printf("Enter your choice: \n ");
		scanf("%d", &choice);
        switch(choice)
        {
		case(1):
            		load_cash();
            		break;
		case(2):
	        	maintain_customer_details();
                	break;
		case(3):
                	handle_atm_operations();
                	break;
		case(4):
					check_ATM_balance();
            		break;
	}
    }while(choice!=5);
    return 0;
}
