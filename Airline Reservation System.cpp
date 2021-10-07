#include<iostream>
#include<math.h>
#include<iomanip>
#include <string.h>
#include <stdlib.h>
using namespace std;

int age1=-1,age2=-1,age3=-1,age4=-1,seat1,seat2,seat3,seat4=1,choice1=0, choice2=0, mDest, menu=0, mTicket, couponOption, couponInvalid, couponMenu, rTicket=0, a=0, b=0, rDest1=0, rDest2=0, rDest3=0, rDest4=0, rDest5=0, rDest6=0, rDest7=0;
double price, rAdultPercent=0.0, rKidPercent=0.0, rTicketAdult=0, rTicketKid=0, rTotalAmount=0, amount=0, rDiscount=0, rDiscountA, rDiscountB, rProfit=0;
float priceAdult, priceKid, priceBusiness;
char passenger1[50], passenger2[50], passenger3[50], passenger4[50], dest[10], time[10], coupon[15], mClass1[20], mClass2[20], mClass3[20], mClass4[20], departure, purchase, package;
	
void voidSeats();
void voidBoardingPassManual()
{	rDiscount=0.0;
	if (mTicket==1||mTicket==2||mTicket==3||mTicket==4)
	{	if (age1>=18)
			price=1000+priceAdult;
		else
			price=500+priceKid;
		if (seat1>=1&&seat1<=15)
			price=price+priceBusiness;
	}
	if (mTicket==2||mTicket==3||mTicket==4)
	{	if (age2>=18)
			price=price+1000+priceAdult;
		else
			price=price+500+priceKid;
		if (seat2>=1&&seat2<=15)
			price=price+priceBusiness;
	}
	if (mTicket==3||mTicket==4)
	{	if (age3>=18)
			price=price+1000+priceAdult;
		else
			price=price+500+priceKid;
		if (seat3>=1&&seat3<=15)
			price=price+priceBusiness;
	}
	if (mTicket==4)
	{	if (age4>=18)
			price=price+1000+priceAdult;
		else
			price=price+500+priceKid;
		if (seat4>=1&&seat4<=15)
			price=price+priceBusiness;
	}
	cout<<"\n\nYour flight is Boeing-770 (RB 370)";
	cout<<"\n\n A - 8.00AM\n B - 1.30PM\n C - 5.00PM\n D - 10.30PM\nChoose departure time\n";
	do
	{	cin>>departure;
		if (departure=='A'||departure=='a')
			strcpy(time,"8.00AM");
		else if (departure=='B'||departure=='b')
			strcpy(time,"1.30PM");
		else if (departure=='C'||departure=='c')
			strcpy(time,"5.00PM");
		else if (departure=='D'||departure=='d')
			strcpy(time,"10.30PM");
		else 
			cout<<"\nChoose (A / B / C / D) only\n";
	} while ((departure != 'A' && departure != 'a')&&(departure != 'B' && departure != 'b')&&(departure != 'C' && departure != 'c')&&(departure != 'D' && departure != 'd'));		
	system ("CLS");
	do
	{	cout<<"\nTotal amount is RM"<<fixed<<setprecision(2)<<price;
		cout<<"\nDo you want to apply any coupons? (Once)\n1. Yes\n2. No\n";
		cin>>couponOption;
		system ("CLS");
		if (couponOption==1){
			do
			{	cout<<"\nEnter your coupon\n";
				cin>>coupon;
				if (strcmp(coupon, "AEROAMEEN")==0){
					cout<<"\nSuccess, 15% off applied!";
					rDiscountB=15.0/100.0*price;
					price=price-(15.0/100.0*price);
				}
				else if (strcmp(coupon, "CAPTAINAFIQ")==0)
				{	cout<<"\nSuccess, 5% off applied!";
					rDiscountB=5.0/100.0*price;
					price=price-(5.0/100.0*price);
				}
				else if (strcmp(coupon, "COPILOTAMIR")==0)
				{	cout<<"\nSuccess, 10% off applied!";
					rDiscountB=10.0/100.0*price;
					price=price-(10.0/100.0*price);
				}
				else if (strcmp(coupon, "STEWARDFARIS")==0)
				{	cout<<"\nSuccess, 10% off applied!";
					rDiscountB=10.0/100.0*price;
					price=price-(10.0/100.0*price);
				}
				else if ((strcmp(coupon, "AEROAMEEN")!=0)&&(strcmp(coupon, "STEWARDFARIS")!=0)&&(strcmp(coupon, "COPILOTAMIR")!=0)&&(strcmp(coupon, "CAPTAINAFIQ")!=0))
				{	do
					{	couponMenu=0;
						cout<<"\nInvalid coupon\n1. Apply coupon again\n2. Continue\n";
						cin>>couponInvalid;
						if (couponInvalid==2)
							couponMenu=1;
						else if (couponInvalid!=1&&couponInvalid!=2)
								cout<<"\n\n***** E R R O R *****\nInvalid option chosen (1-Enter coupon again   2-Continue without coupon)\n*********************\n";
					} while (couponInvalid!=1&&couponInvalid!=2);
					system ("CLS");
				}
					
			} while ((strcmp(coupon, "AEROAMEEN")!=0)&&(strcmp(coupon, "STEWARDFARIS")!=0)&&(strcmp(coupon, "COPILOTAMIR")!=0)&&(strcmp(coupon, "CAPTAINAFIQ")!=0)&&couponMenu==0);
		}
		else if (couponOption!=1&&couponOption!=2)
			cout<<"\n\n***** E R R O R *****\nInvalid option chosen (1-YES   2-NO)\n*********************\n";
	} while (couponOption!=1&&couponOption!=2);
	cout<<"\n\nYou have completed your information and details\nTotal amount : RM"<<price<<"\n\n(Enter any key to CONFIRM PURCHASE)\n";
	cin.get();cin.get();
	cout<<"\n\n===== P A Y M E N T   S U C C E S S F U L =====\n\n(Enter any key to get your BOARDING PASS)\n";
	cin.get();cin.get();
	system ("CLS");
	if (seat1>=16)
		strcpy (mClass1, "Economy Class");
	else
		strcpy (mClass1, "Business Class");
	if (seat2>=16)
		strcpy (mClass2, "Economy Class");
	else
		strcpy (mClass2, "Business Class");
	if (seat3>=16)
		strcpy (mClass3, "Economy Class");
	else
		strcpy (mClass3, "Business Class");
	if (seat4>=16)
		strcpy (mClass4, "Economy Class");
	else
		strcpy (mClass4, "Business Class");
	cout<<"\n\n\n___________________________________________________________________________________________\n\n       RAUB AIRLINE             e-Boarding Pass          [Reference Number : UITMRB370]";
	cout<<"\n__________________________________________________________________________________________\n\n      PASSENGER & FLIGHT DETAILS\n";
	cout<<"\n      "<<passenger1;
	cout<<"\n      Age "<<age1<<"        Flight  RB370               "<<mClass1;
	cout<<"\n      Seat "<<seat1;
	cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	if (mTicket==2||mTicket==3||mTicket==4)
	{	cout<<"\n      "<<passenger2;
		cout<<"\n      Age "<<age2<<"        Flight  RB370               "<<mClass2;
		cout<<"\n      Seat "<<seat2;
		cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	}
	if (mTicket==3||mTicket==4)
	{	cout<<"\n      "<<passenger3;
		cout<<"\n      Age "<<age3<<"        Flight  RB370               "<<mClass3;
		cout<<"\n      Seat "<<seat3;
		cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	}
	if (mTicket==4)
	{	cout<<"\n      "<<passenger4;
		cout<<"\n      Age "<<age4<<"        Flight  RB370               "<<mClass4;
		cout<<"\n      Seat "<<seat4;
		cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	}
	cout<<"\n      TOTAL AMOUNT : "<<fixed<<setprecision(2)<<price;                                                                                    
	cout<<"\n__________________________________________________________________________________________\n(Enter any key to return to Main Menu)\n";
	cin.get();cin.get();
	if (mDest==1)
		rDest1=rDest1+mTicket;
	else if (mDest==2)
		rDest2=rDest2+mTicket;
	else if (mDest==3)
		rDest3=rDest3+mTicket;
	else if (mDest==4)
		rDest4=rDest4+mTicket;
	else if (mDest==5)
		rDest5=rDest5+mTicket;
	else if (mDest==6)
		rDest6=rDest6+mTicket;
	else if (mDest==7)
		rDest7=rDest7+mTicket;
	rTotalAmount=rTotalAmount+price+rDiscountB;
	rDiscount=rDiscount+rDiscountB;
	system ("CLS");
}
void voidFirstPassenger()
{
	cout<<"\n\nEnter 1st passenger name\n";
	cin.get();cin.getline(passenger1, 50);
	cout<<"\n\nEnter 1st passenger age\n";
	cin>>age1;
	voidSeats();
	do
	{	cin>>seat1;
		if (seat1>81 || seat1<1)
		cout<<"\n\n***** E R R O R *****\nAvailable seats for this flight is 1-81 only\n*********************\nChoose available seat\n";
	}	while (seat1>81 || seat1<1);
	system ("CLS");
}
void voidSecondPassenger()
{
	cout<<"\n\nEnter 2nd passenger name\n";
	cin.get();
	cin.getline(passenger2, 50);
	cout<<"\n\nEnter 2nd passenger age\n";
	cin>>age2;
	voidSeats();
	do		
	{	do
		{	cin>>seat2;
			if (seat2>81 || seat2<1)
				cout<<"\n\n***** E R R O R *****\nAvailable seats for this flight is 1-81 only\n*********************\nChoose available seat\n";
		}	while (seat2>81 || seat2<1);
		if (seat2==seat1)
			cout<<"\n\n***** E R R O R *****\nSeat "<<seat1<<" has been taken\n*********************\nChoose another seat\n";
	}	while (seat2==seat1);
	system ("CLS");
}
void voidThirdPassenger()
{
	cout<<"\n\nEnter 3rd passenger name\n";
	cin.get();cin.getline(passenger3, 50);
	cout<<"\n\nEnter 3rd passenger age\n";
	cin>>age3;
	voidSeats();
	do
	{	do
		{	cin>>seat3;
			if (seat3>81 || seat3<1)
				cout<<"\n\n***** E R R O R *****\nAvailable seats for this flight is 1-81 only\n*********************\nChoose available seat\n";
		}	while (seat3>81 || seat3<1);
		if (seat3==seat1||seat3==seat2)
			cout<<"\n\n***** E R R O R *****\nSeat "<<seat1<<" and "<<seat2<<" has been taken\n*********************\nChoose another seat\n";
	}	while (seat3==seat1||seat3==seat2);
	system ("CLS");
}
void voidSeats()
{
	cout<<"\n____________________________________________________________________\n\n\n";
	cout<<"                      01          02          03                      \n";
	cout<<"                      04          05          06          BUSINESS    \n";
	cout<<"                      07          08          09          CLASS       \n";
	cout<<"                      10          11          12                      \n";
	cout<<"                      13          14          15                      \n";
	cout<<"                    ________     _____     ________                   \n\n";
	cout<<"                      16  17    18  19     21  22                     \n";
	cout<<"                      23  24    25  26     27  28                     \n";
	cout<<"                      29  30    31  32     33  34                     \n";
	cout<<"                      35  36    37  38     39  40                     \n";
	cout<<"                      41  42    43  44     45  46         ECONOMY     \n";
	cout<<"                      47  48    49  50     51  52         CLASS       \n";
	cout<<"                      53  54    55  56     57  58                     \n";
	cout<<"                      59  60    61  62     63  64                     \n";
	cout<<"                      65  66    67  68     69  70                     \n";
	cout<<"                      71  72    72  73     74  75                     \n";
	cout<<"                      76  77    78  79     80  81                   \n\n";
	cout<<"____________________________________________________________________\n\n";
	cout<<"Choose seat\n";
}
void voidManualReservation()
{	age1=-1; age2=-1; age3=-1; age4=-1;menu=0;
	cout<<"\n========== M A N U A L   R E S E R V A T I O N ==========\n\n____________________________________________________\n";
	cout<<"\nYou will depart at KUALA LUMPUR\n\nAvailable DESTINATION today :\n  1. Jakarta\n  2. Bangkok\n  3. Makkah\n  4. Tokyo\n  5. Paris \n  6. London\n  7. Chicago\n____________________________________________________";
	cout<<"\nChoose your destination\n";
	do
	{	cin>>mDest;
		if (mDest==1){
			strcpy(dest, "JAKARTA");
			priceAdult=0;priceKid=0;priceBusiness=500;}
		else if (mDest==2){
			strcpy(dest, "BANGKOK");
			priceAdult=100;priceKid=50;priceBusiness=600;}
		else if (mDest==3){
			strcpy(dest, "MAKKAH");
			priceAdult=200;priceKid=100;priceBusiness=700;}
		else if (mDest==4){
			strcpy(dest, "TOKYO");
			priceAdult=300;priceKid=150;priceBusiness=800;}
		else if (mDest==5){
			strcpy(dest, "PARIS");
			priceAdult=400;priceKid=200;priceBusiness=900;}
		else if (mDest==6){
			strcpy(dest, "LONDON");
			priceAdult=500;priceKid=250;priceBusiness=1000;}
		else if (mDest==7){
			strcpy(dest, "CHICAGO");
			priceAdult=600;priceKid=300;priceBusiness=1100;}
		else if (mDest!=1&&mDest!=2&&mDest!=3&&mDest!=4&&mDest!=5&&mDest!=6&&mDest!=7){
			cout<<"\n\n***** E R R O R *****\nInvalid number chosen (Choose 1-7 only)\n*********************\n";}
	} while (mDest!=1&&mDest!=2&&mDest!=3&&mDest!=4&&mDest!=5&&mDest!=6&&mDest!=7);
	system ("CLS");
	do
	{	cout<<"\n\nEnter number of tickets (maximum 4)\n";
		cin>>mTicket;
		if (mTicket==1)
		{	system ("CLS");
			voidFirstPassenger();
			voidBoardingPassManual();
		}
		else if (mTicket==2)
		{	system ("CLS");
			voidFirstPassenger();
			voidSecondPassenger();
			voidBoardingPassManual();
		}
		else if (mTicket==3)
		{	system ("CLS");
			voidFirstPassenger();
			voidSecondPassenger();
			voidThirdPassenger();
			voidBoardingPassManual();
		}
		else if (mTicket==4)
		{	system ("CLS");
			voidFirstPassenger();
			voidSecondPassenger();
			voidThirdPassenger();
			cout<<"\n\nEnter 4th passenger name\n";
			cin.get();cin.getline(passenger4, 50);
			cout<<"\n\nEnter 4th passenger age\n";
			cin>>age4;
			voidSeats();
			do
			{	while (seat4<1||seat4>81)
				{	cin>>seat4;
					if (seat4>81||seat4<1)
						cout<<"\n\n***** E R R O R *****\nAvailable seats for this flight is 1-81 only\n*********************\n";
				}
				if (seat4==seat1||seat4==seat2||seat4==seat3)
				cout<<"\n\n***** E R R O R *****\nSeat "<<seat1<<", "<<seat2<<" and "<<seat3<<" has been taken\n*********************\n";
			}	while (seat4==seat1||seat4==seat2||seat4==seat3);
			system ("CLS");
			voidBoardingPassManual();
		}
		else if (mTicket!=1&&mTicket!=2&&mTicket!=3&&mTicket!=4)
			cout<<"\n\n***** E R R O R *****\nInvalid number of tickets chosen (1-4 only)\n*********************\n";
	} while (mTicket!=1&&mTicket!=2&&mTicket!=3&&mTicket!=4&&menu==0);
	system ("CLS");
	rTicket=rTicket+mTicket;
	if (age1>=18)
		rTicketAdult++;
	else if (age1>=0&&age1<18)
		rTicketKid++;
	if (age2>=18)
		rTicketAdult++;
	else if (age2>=0&&age2<18)
		rTicketKid++;
	if (age3>=18)
		rTicketAdult++;
	else if (age3>=0&&age3<18)
		rTicketKid++;
	if (age4>=18)
		rTicketAdult++;
	else if (age4>=0&&age4<18)
		rTicketKid++;
}
void voidPackages()
{	system ("CLS");
	voidFirstPassenger();
	voidSecondPassenger();
	cout<<"\n\nEnter 3rd passenger name\n";
	cin.get();cin.getline(passenger3, 50);
	cout<<"\n\nEnter 3rd passenger age\n";
	do
	{	cin>>age3;
		if ((age1>=18 && age2>=18) || (age1<18 && age2<18) )
		{	cout<<"\n\n\n\n_______________________________________________________________________________________________";
			cout<<"\nThis package is for 2 adults and 2 kids only. (Adults = 18 and above, Kids = Below 18)";
			cout<<"\n1st passenger age = "<<age1<<"\n2nd passenger age = "<<age2;
			cout<<"\n_______________________________________________________________________________________________\n";
			cout<<"\nEnter 3rd passenger age\n";
		}
	}	while ((age3>=18 && age1>=18 && age2>=18) || (age3<18 && age1<18 && age2<18));
	voidSeats();
	do
	{	do
		{	cin>>seat3;
			if (seat3>81 || seat3<1)
				cout<<"\n\n***** E R R O R *****\nAvailable seats for this flight is 1-81 only\n*********************\nChoose available seat\n";
		}	while (seat3>81 || seat3<1);
		if (seat3==seat1 || seat3==seat2)
			cout<<"\n\n***** E R R O R *****\nSeat "<<seat1<<" and "<<seat2<<" has been taken\n*********************\nChoose another seat\n";
	}	while (seat3==seat1 || seat3==seat2);
	system ("CLS");
	cout<<"\n\nEnter 4th passenger name\n";
	cin.get();cin.getline(passenger4, 50);
	cout<<"\n\nEnter 4th passenger age\n";
	do
	{	cin>>age4;
		if ((age1>=18 && age2>=18 && age4>=18) || (age1<18 && age2<18 && age4<18) || (age1>=18 && age3>=18 && age4>=18) || (age1<18 && age3<18 && age4<18) || (age2>=18 && age3>=18 && age4>=18) || (age2<18 && age3<18 && age4<18))
		{	cout<<"\n\n\n\n_______________________________________________________________________________________________";
			cout<<"\nThis package is for 2 adults and 2 kids only. (Adults = 18 and above, Kids = Below 18)";
			cout<<"\n1st passenger age = "<<age1<<"\n2nd passenger age = "<<age2<<"\n3rd passenger age = "<<age3;
			cout<<"\n_______________________________________________________________________________________________\n";
			cout<<"\nEnter 4th passenger age\n";
		}
	}	while ((age1>=18 && age2>=18 && age4>=18) || (age1<18 && age2<18 && age4<18) || (age1>=18 && age3>=18 && age4>=18) || (age1<18 && age3<18 && age4<18) || (age2>=18 && age3>=18 && age4>=18) || (age2<18 && age3<18 && age4<18));
	voidSeats();
	do
	{	do
		{	cin>>seat4;
			if (seat4>81 || seat4<1)
				cout<<"\n\n***** E R R O R *****\nAvailable seats for this flight is 1-81 only\n*********************\nChoose available seat\n";
		}	while (seat4>81 || seat4<1);
		if (seat4==seat1 || seat4==seat2 || seat4 == seat3)
			cout<<"\n\n***** E R R O R *****\nSeat "<<seat1<<", "<<seat2<<" and "<<seat3<<" has been taken\n*********************\nChoose another seat\n";
	}	while (seat4==seat1 || seat4==seat2 || seat4 == seat3);
	system ("CLS");
	cout<<"\n\nYour flight is Boeing-770 (RB 370)";
	cout<<"\n\n A - 8.00AM\n B - 1.30PM\n C - 5.00PM\n D - 10.30PM";
	cout<<"\nChoose departure time\n";
	do	
	{	cin>>departure;
		if (departure == 'A' || departure == 'a')
			strcpy(time, "8.00AM");
		else if (departure == 'B' || departure == 'b')
			strcpy(time, "1.30PM");
		else if (departure == 'C' || departure == 'c')
			strcpy(time, "5.00PM");
		else if (departure == 'D' || departure == 'd')
			strcpy(time, "10.30PM");
		else 
			cout<<"\n\n***** E R R O R *****\nChoose (A / B / C / D) only\n*********************\n";	
	} while ((departure != 'A' && departure != 'a')&&(departure != 'B' && departure != 'b')&&(departure != 'C' && departure != 'c')&&(departure != 'D' && departure != 'd'));
	system ("CLS");				
	cout<<"\n\nYou have completed your information and details\nTotal amount : RM"<<amount<<"\n\n(Enter any key to CONFIRM PURCHASE)\n";
	cin.get();cin.get();
	cout<<"\n\n========== P A Y M E N T   S U C C E S S F U L ==========\n\n(Enter any key to get your BOARDING PASS)\n";
	cin.get();cin.get();
	system ("CLS");
	cout<<"\n\n\n___________________________________________________________________________________________\n";
	cout<<"\n       RAUB AIRLINE             e-Boarding Pass          [Reference Number : UITMRB370]";
	cout<<"\n__________________________________________________________________________________________ \n";
	cout<<"\n      PASSENGER & FLIGHT DETAILS\n";
	cout<<"\n      "<<passenger1;
	cout<<"\n      Age "<<age1<<"        Flight  RB370";
	cout<<"\n      Seat "<<seat1;
	cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	cout<<"\n      "<<passenger2;
	cout<<"\n      Age "<<age2<<"        Flight  RB370";
	cout<<"\n      Seat "<<seat2;
	cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	cout<<"\n      "<<passenger3;
	cout<<"\n      Age "<<age3<<"        Flight  RB370";
	cout<<"\n      Seat "<<seat3;
	cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	cout<<"\n      "<<passenger4;
	cout<<"\n      Age "<<age4<<"        Flight  RB370";
	cout<<"\n      Seat "<<seat4;
	cout<<"\n      KUALA LUMPUR to "<<dest<<"    "<<time<<endl;
	cout<<"\n      TOTAL AMOUNT : RM"<<amount;                                                                                    
	cout<<"\n__________________________________________________________________________________________  ";
	cout<<"\n(Enter any key to return to Main Menu)\n";
	cin.get();cin.get();
	menu=1;
	rTicket=rTicket+4;
	rTicketAdult=rTicketAdult+2;
	rTicketKid=rTicketKid+2;
	rTotalAmount=rTotalAmount+amount+rDiscountA;
	rDiscount=rDiscount+rDiscountA;
}
//adult-RM1000
//kid-RM500
/*1. Jakarta (adult = adult, kid = kid / per person)
  2. Bangkok (adult = +100, kid = +50 / per person)
  3. Makkah (adult = +200, kid = +100 / per person)
  4. Tokyo (adult = +300, kid = +150 / per person)
  5. Paris (adult = +400, kid = +200 / per person)
  6. London (adult = +500, kid = +250 / per person)
  7. Chicago (adult = +600, kid = +300 / per person)
*/
int main()
{	do
	{
		menu=0;
		cout<<"#############################################################################################\n";
		cout<<"                      *                                           *\n";
		cout<<"            *        * *                                         * *        *\n";
		cout<<"           * *        *          WELCOME TO RAUB AIRLINE          *        * *\n";
		cout<<"          *   *            *      ONLINE RERSERVATION       *             *   *\n";
		cout<<"           * *            * *                              * *             * *\n";
		cout<<"            *              *                                *               *\n";
		cout<<"#############################################################################################\n";
		cout<<"\n\n===== M A I N   M E N U =====\n\n  1. PACKAGES \n  2. MANUAL RESERVATION\n  3. Coupons\n  4. Report\n  5. Credits\n  6. Exit\n  ";
		cin>>choice1;
		system ("CLS");
		if  (choice1==1) //< < < < < < < < < < <     P A C K A G E S    > > > > > > > > > > > >
		{	cout<<"\n========== P A C K A G E S ==========\n\n____________________________________________________\n";
			cout<<"\n A : KUALA LUMPUR to LONDON";
			cout<<"\n     2 Adults 2 Kids             < DISCOUNT 30%\n     RM3150 (After Discount)\n";
			cout<<"\n B : KUALA LUMPUR to TOKYO";
			cout<<"\n     2 Adults 2 Kids             < DISCOUNT 20%\n     RM3120 (After Discount)\n";
			cout<<"\n C : KUALA LUMPUR to MAKKAH";
			cout<<"\n     2 Adults 2 Kids             < DISCOUNT 35%\n     RM2340 (After Discount)";
			cout<<"\n____________________________________________________";
			cout<<"\nChoose package (A / B / C). If NOT interested (M = Main Menu)\n";
			do
			{	cin>>package;
				if (package=='A'||package=='a'){
					strcpy(dest, "LONDON");amount=3150;rDiscountA=1350;rDest6=rDest6+4;
					voidPackages();
				}
				else if (package=='B'||package=='b'){
					strcpy(dest, "TOKYO");amount=3120;rDiscountA=780;rDest4=rDest4+4;
					voidPackages();
				}
				else if (package=='C'||package=='c'){
					strcpy(dest, "MAKKAH");amount=2340;rDiscountA=1260;rDest3=rDest3+4;
					voidPackages();
				}
				else if (package=='M'||package=='m')
					menu=1;
				else
					cout<<"\n\n***** E R R O R *****\nChoose (A / B / C) for the packages OR (M = Main Menu) only\n*********************\n";
			} while ((package!='A'||package!='a')&&(package!='B'||package!='b')&&(package!='C'||package!='c')&&menu!=1);
		system ("CLS");
		}
		else if (choice1==2) //< < < < < < < < < < <     M A N U A L      R E S E R V A T I O N     > > > > > > > > > > > >
		{	voidManualReservation();
			menu=1;
		}
		else if (choice1==3) //< < < < < < < < < < <     C O U P O N S     > > > > > > > > > > > >
		{	cout<<"\n========== C O U P O N S ==========\n\nApply one of these coupons in Manual Reservation only\n\n  - CAPTAINAFIQ   (5% OFF)\n  - COPILOTAMIR   (10% OFF)\n  - AEROAMEEN     (15% OFF)\n  - STEWARDFARIS  (10% OFF)\n";
			cout<<"\n(Enter any key to return to Main Menu)\n";
			cin.get();cin.get();
			menu=1;
			system ("CLS");
		}
		else if (choice1==4) //< < < < < < < < < < <     R E P O R T     > > > > > > > > > > > >
		{	a=rTicketAdult;b=rTicketKid;
			cout<<"\n\n========== R A U B   A I R L I N E   R E P O R T ==========";
			cout<<"\n\nTotal Tickets Sold : "<<rTicket;
			rAdultPercent=rTicketAdult/(rTicketAdult+rTicketKid)*100;
			rKidPercent=rTicketKid/(rTicketAdult+rTicketKid)*100;
			cout<<"\nTotal Adults       : "<<a<<fixed<<setprecision(2)<<" ("<<rAdultPercent<<"%)";
			cout<<"\nTotal Kids         : "<<b<<fixed<<setprecision(2)<<" ("<<rKidPercent<<"%)";
			cout<<"\n\nTotal tickets sold (by destination)";
			cout<<"\n- JAKARTA : "<<rDest1<<"\n- BANGKOK : "<<rDest2<<"\n- MAKKAH  : "<<rDest3<<"\n- TOKYO   : "<<rDest4<<"\n- PARIS   : "<<rDest5<<"\n- LONDON  : "<<rDest6<<"\n- CHICAGO : "<<rDest7;
			cout<<"\n\nTotal Discount Allowed : RM"<<rDiscount;
			cout<<"\nTotal Income           : RM"<<fixed<<setprecision(2)<<rTotalAmount;
			rProfit=rTotalAmount-rDiscount;
			cout<<"\nNET PROFIT             : RM"<<rProfit;
			cout<<"\n\n(Enter any key to return to Main Menu)\n";
			cin.get();cin.get();
			menu=1;
			system ("CLS");
		}
		else if (choice1==5) //< < < < < < < < < < <     C R E D I T S     > > > > > > > > > > > >
		{	cout<<"\n========== C R E D I T S ==========\n\nThis program is prepared by :\n\n     1. Afiq Izzuddin Bin Mustapha\n     2. Ahmad Faris Bin Ismail\n     3. Muhammad Amir Iqbal Bin Mohd Tarmidzi\n     4. Nur Ameerul Ameen Bin Nor Hassan";
			cout<<"\n\n(Enter any key to return to Main Menu)\n";
			cin.get();cin.get();
			menu=1;
			system ("CLS");
		}
		else if (choice1!=6)
			cout<<"***** E R R O R *****\nInvalid option chosen (1-6 only)\n*********************\n\n";
	} while ((choice1!=1&&choice1!=2&&choice1!=3&&choice1!=4&&choice1!=5&&choice1!=6)||menu==1);
	return 0;				
}
