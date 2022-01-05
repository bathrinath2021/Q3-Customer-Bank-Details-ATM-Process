**Q3 Customer Bank Details & ATM Process Problem :**

You are to program an Automated Teller Machine (ATM) to show the Main
Menu specified below and perform the list of tasks given.

> 1\. Load Cash to ATM
>
> 2\. Show Customer Details
>
> 3\. Show ATM Operations

**Initialization of pre-processors**

> \#include&lt;stdio.h&gt;
>
> \#include&lt;stdlib.h&gt;
>
> \#include&lt;string.h&gt;

**Main Function**

In the main function we will be displaying the ATM operations for the
Customer and for the Operator.

**Output**

-----------Welcome to the ATM service--------------

1\. Load Cash to ATM

2\. Maintain Customer Details

3\. Handle ATM Process

4\. Check ATM Balance

5\. Quit

--------------------------------------------------

Enter your choice:

**Task 1 : Load cash to ATM**

The ATM will be initially empty and you are required to programatically
feed money into the machine, along with specific currency denominations.
Maintain the currency and denominations in a suitable data structure.

Initially the ATM will be (0).

A structure has been implemented for denominations.

struct denominations{

int two\_thousands,five\_hundreds,hundreds;

}d;

By calling the load\_cash() function in the main fucntion the ATM cash
depositor can deposit money it will be asking the details regarding the
denominations.

Finally, the obtained amount is added with the total available amount in
the ATM.

**Output**

Enter your choice:

1

Enter the number of Two Thousands: 20

Enter the number of Five Hundreds: 100

Enter the number of Hundreds: 100

-------------------------------------------------------

Denomination Number Value

-------------------------------------------------------

2000 20 40000

-------------------------------------------------------

500 100 50000

-------------------------------------------------------

100 100 10000

-------------------------------------------------------

Total available cash in the ATM is : 100000

-----------Welcome to the ATM service--------------

1\. Load Cash to ATM

2\. Maintain Customer Details

3\. Handle ATM Process

4\. Check ATM Balance

5\. Quit

--------------------------------------------------

**Task 2 : Maintain Customer Details **

Using simple Data Structure, maintain the following Customer Details in
a separate file, with which we will be performing further operations and
display the details in a tabular structure.

To maintain the customer details in a separate file I have used
structure for the details.

Structure declaration

struct customer\_entry{

int acc\_no;

char Name\[50\];

int pin;

int acc\_balance;

}s\[100\];

Then using the function show\_customer\_details() called in the main
function the following output will be displayed.

**Output**

Enter your choice:

2

----------------------------------------------------------------------------

Acc\_No Account\_Holder Pin\_Number Account\_Balance

----------------------------------------------------------------------------

101 Suresh 2343 25234

102 Ganesh 5432 34123

103 Magesh 7854 26100

104 Naresh 2345 80000

105 Harish 1907 103400

---------------------------------------------------------------------------

**Task 3 : Handle ATM Process **

On selecting this option, ask user to input Account Number and Pin
Number. After validation, the customer should be given the following
options

1\. Check Balance

2\. Withdraw Money

3\. Transfer Money

**Task 3.1 : Check Balance **

Upon selecting this option, the customer must be shown the balance
amount from his account on the screen.

Now our task is to check the account balance of the user.

**Output**

Enter your choice:

3

1\. Check Balance

2\. Withdraw Money

3\. Transfer Money

Enter the operation to be performed: 1

Enter your account number

103

Enter you Pin

7854

---------------------------------------------------

Your Account Balance is : 26100

---------------------------------------------------

**Task 3.2 : Withdraw Money**

Basic criteria for withdrawal of money are listed below. Customer should
be alerted when any of the criteria is met.

1\. Max withdrawal limit for a single transaction is10,000₹ and minimum
is100₹. 2. For every subsequent withdrawal, pin number should be entered
by the customer. After selecting Withdraw Money option the following
actions should be performed. 1. Prompt to Enter the Amount to be
withdrawn

2\. An alert should be shown when the ATM does not have enough money to
vend.

3\. Cross verify Acc Balance with requested withdrawal amount and alert
the Customer when - account balance is lower than entered withdrawal
amount.

4\. The minimum vended denomination for amount &lt;= 5000 ₹ should be as
follows.

> a\. 2000₹ (Minimum 1 for withdrawal greater than 3000 ₹)
>
> b\. 500₹ (Minimum 1 for withdrawal greater than 1000₹ )
>
> c\. 100₹ i. Maximum 15 numbers and ii. minimum 10 for withdrawal greater
> than 1500 ₹ iii. Reduce for lesser amounts

5\. The minimum vended denomination for amount &gt; 5000 ₹ should be as
follows.

> a\. 2000₹ X 2
>
> b\. 500₹ X 2 (increase for higher amounts)
>
> c\. 100₹ X 10 (Maximum 10 numbers)
>
> 6\. The withdrawn amount should be reduced from customers account balance
> and the ATM balance. (In the local-files)
>
> 7\. If the ATM does not have the denominations to give the balance to the
> user, Let the users know and stop the transaction.

**Output**

Enter your choice:

3

1\. Check Balance

2\. Withdraw Money

3\. Transfer Money

Enter the operation to be performed: 2

Enter your account number

101

Enter you Pin

2343

NOTE : Your withdrawal money should be above 100 and below 10000

Enter the Amount to be Withdrawn : 2000

-----Please Collect the Cash-----Visit again------

**Task 3.3 : Transfer Money **

Basic Criteria for Transfer are as follows and the customer should be
alerted when any of the criteria is met.

1\. Max transfer limit per transaction cannot exceed 10,000 ₹ and should
be more than 1000 ₹

2\. Transaction can happen only between the customers mentioned
previously

Upon selecting Transfer Money, the following actions should be performed

1\. Prompt the customer to input Account Number to which the money has to
be transferred

2\. Account balance should be properly altered for both sender and
receiver and the balance in ATM should not be affected.

**Output**

Enter your choice:

3

1\. Check Balance

2\. Withdraw Money

3\. Transfer Money

Enter the operation to be performed: 3

Enter your account number

102

Enter you Pin

5432

NOTE: Max transfer limit per transaction is above 1000 and below 10000

Enter the Amount to be transfered : 5000

Enter the Account Number to which the money has to be transfered : 101

-------------TRANSACTION SUCCESSFULL-------------

**Task 4 : Check ATM Balance **

> Upon selecting this option, the user should be shown the balance
> amount in the ATM along with denomination.

**Output**

Enter your choice:

4

-------------------------------------------------------

Denomination Number Value

-------------------------------------------------------

2000 19 38000

-------------------------------------------------------

500 99 49500

-------------------------------------------------------

100 81 8100

-------------------------------------------------------

Total available cash in the ATM is : 98000

**Conclusion **

> While entering each choice the user can load and see the changes on
> the screen.

**Output**

Enter your choice:

5

--------------------------------
