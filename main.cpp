#include <iostream>
#include<conio.h>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include <time.h>
#include<string.h>
using namespace std;

stringstream ss,table;

MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;

int flag=0;
char foo1[50][20]={"Idly","Dosa","Pongal","Vadai","Poori","Tea","Coffee","Milk","Jammun"};
char foo2[50][20]={"Sambar Rice","Rasam Rice", "Curd Rice", "Meals", "Mini Meals", "Veg Briyani" , "Thum Briyani" , "Tomato Rice", "Lemon Rice"};
char foo3[50][20]={"Fried Rice","Paneer Rice","Gobi Rice","Mushroom Rice"," Parota"," Dosa"," Noodles" ,"Chappathi" ,"Curd Rice" };
char foo4[50][20]={" Parota","Chappathi","Tea","Coffee","Boost","Moltova","Complain"," Black Tea","Jammun" };
char foo5[50][20]={"Idly","  Dosa "," Pongal", " Vadai","Poori","Tea","Coffee","Milk","Jammun"};
char foo6[50][20]={"Chicken Briyani","Mutton Briyani","Fish Briyani","Veg Briyani","Veg Meals","Veg-Mini Meals","Non-Veg Meals","Non-Veg Mini Meals","Fish Fry","Chicken 65" ," Mutton 65"," Sweet corn Soup"};
char foo7[100][50]={"Fish Fry","Chicken 65","Mutton 65","Dragon Chicken","Chilly Chicken","Chilly MUtton","Mushroom Fry","Gobi Manchurian","  Panneer Finger","Sweet corn Soup","  Mushroom Soup","Baby Corn Soup "," Ginger Garlic Soup ","Pepper Garlic soup "," Aatu Kall Soup  ","Chicken Soup"," Fried Rice ","Paneer Rice","Gobi Rice "," Mushroom Rice"," Egg Fried Rice ","Schwan Chicken Rice "," Mutton Rice "};
char foo8[50][20]={" Parota","Chappathi","Tea","Coffee","Boost","Moltova","Complain"," Black Tea","Jammun" };
char f[50][25],h[10][25],food[50][20];


int cost1[30]={30,45,35,5,40,10,12,10,15};
int cost2[30]={40,40,35,80,50,55,75,40,40};
int cost3[30]={80,95,95,95,25,45,85,25,35};
int cost4[30]={25,25,10,12,10,10,10,15,15};
int cost5[30]={30,45,35,5,40,10,12,10,15};
int cost6[30]={100,110,100,80,80,50,120,60,150,90,90,50,50,50};
int cost7[30]={120,90,90,150,130,130,90,90,90,50,50,50,50,80,80,80,95,95,95,95,95,95,85,100,95};
int cost8[30]={25,25,10,12,10,10,10,15,15};
int setset[50],costtt[50];

int hour,i=0,sets[50],cost[100],c[100],cow=0,kn[50],total=0;


class login
{
private :
    string name,phno,email,password,lname,lpassword;//lname login name
    public :
    usersignup()
    {
        cout<<"\n Sign up ...";
        cout<<"\n\n Name : ";
        cin>>name;
        cout<<"\n phno : ";
        cin>>phno;
        cout<<"\n email : ";
        cin>>email;
        cout<<"\n password : ";
        cin>>password;

        ss << "INSERT INTO `signup`(`Name`, `Email`, `Phno`, `Password`) VALUES ('"+name+"','"+email+"','"+phno+"','"+password+"')";

        string query = ss.str();
        int qstate = 0;
        const char* q = query.c_str();
        qstate=mysql_query(conn, q);
        if(qstate == 0)
        {
        cout<<"\n Sign up complete ";
        }
        else
        cout<<"\n Failed to sign up";
    }


    void userlogin()
    {
        cout<<"\n User login....";
        cout<<"\n\n User name : ";
        cin>>lname;
        cout<<"\n Password : ";
        cin>>lpassword;

        if(conn)
        {
            int qstate = mysql_query(conn , "select Name,Password from signup");

        if(!qstate)
        {
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res))
                    {
                        if(row[0]==lname && row[1]==lpassword)
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag=0;
                    }
                }
        }
        if(flag==1)
        {
            cout<<"\n Login Successful";
        }
        else
            cout<<"\n User name or Password is incorrect";
        }

}
}u;




class restaurants
{
private:
 int opt,ch,se,ch1,setta;
    public:

    void hotel()
    {
        cout<<"\n\t\t\t\t\t Hotel ";
        cout<<"\n\t\t\t 1. Saravana Bhavan \n\t\t\t 2. Namma Veedu \n\t\t\t 3. Royal vega \n\t\t\t 4. The Reef ";
        cout<<"\n\t\t\t 5. Chick Inn \n\t\t\t 6. vegie Nation \n\t\t\t 7. Sangam Restaurant \n\t\t\t 8. Oasis Restaurant";
        cout<<"\n\t\t\t 9. Hilltop Towers \n\t\t\t 10. cloud hall ";
        cout<<"\n\n\n\t\t\t Enter the hotel : ";
        cin>>opt;
        /*switch(opt)
        {
            case 1:
                h[12][25] = "Saravana Bhavan";
            break;
            case 2:
                h[12][25]=" Namma Veedu";
            break;
            case 3:
                h[12][25]="Royal vega";
            break;
            case 4:
                h[12][25]="The Reef";
            break;
            case 5:
                h[12][25]="Chick Inn ";
            break;
            case 6:
                h[12][25]="vegie Nation ";="Fried Rice","Paneer Rice","Gobi Rice","Mushroom Rice"," Parota"," Dosa"," Noodles" ,"Chappathi" ,"Curd Rice" ;
            break;
            case 7:
                h[12][25]="Sangam Restaurant";
            break;
            case 8:
                h[12][25]=" Oasis Restaurant";
            break;
            case 9:
                h[12][25]="Hilltop Towers";
            break;
            case 10:
                h[12][25]="Cloud Hall";

        }*/
        if((opt == 1)|| (opt == 6) || (opt == 7))
        {
            vegfood();
        }
        else
        {
                nonveg();
        }
    }
    void vegfood()
    {

        if((hour >= 1) && (hour <= 11))
           {
               cout<<"\n Menu : ";
               cout<<"\n 1. Idly \t\t\t\t\t\t RS:30 \n 2. Dosa \t\t\t\t\t\t RS:45\n 3. Pongal \t\t\t\t\t\t RS:35\n 4. Vadai \t\t\t\t\t\t RS:5\n 5. Poori \t\t\t\t\t\t RS:40\n 6. Tea \t\t\t\t\t\t RS:10\n 7. Coffee \t\t\t\t\t\t RS:12\n 8.Milk \t\t\t\t\t\t RS:10\n 9. Jammun \t\t\t\t\t\t RS:15\n 10.exit";
                quantity(10,1);
           }
           else if((hour>=12)&&(hour<=16))
           {
               cout<<"\n Menu : ";
               cout<<"\n 1. Sambar Rice \t\t\t\t\t\t RS: 40\n 2. Rasam Rice \t\t\t\t\t\t RS: 40\n 3. Curd Rice \t\t\t\t\t\t RS: 35\n 4. Meals \t\t\t\t\t\t RS :80\n 5. Mini Meals \t\t\t\t\t\t RS: 50";
               cout<<"\n 6. Veg Briyani \t\t\t\t\t\t RS:55\n 7. Thum Briyani \t\t\t\t\t\t RS:75\n 8. Tomato Rice \t\t\t\t\t\t RS:40\n 9. Lemon Rice \t\t\t\t\t\t RS:30\n 10.Exit";
               quantity(10,2);
           }
           else if((hour>=17)&&(hour<=22))
           {
                cout<<"\n Menu : ";
               cout<<"\n 1. Fried Rice \t\t\t\t\t\t RS :80\n 2. Paneer Rice \t\t\t\t\t\t RS:95\n 3. Gobi Rice \t\t\t\t\t\t RS:95\n 4. Mushroom Rice \t\t\t\t\t\t RS:95\n 5. Parota \t\t\t\t\t\t RS: 25";
               cout<<"\n 6. Dosa \t\t\t\t\t\t RS:45\n 7. Noodles \t\t\t\t\t\t RS :85\n 8. Chappathi \t\t\t\t\t\t RS: 25\n 9. Curd Rice \t\t\t\t\t\t RS:35\n 10.Exit";
               quantity(10,3);
           }
          else if((hour>=23)&&(hour<=24))
          {
              cout<<"\n Memu : ";
              cout<<"\n 1. Parota \t\t\t\t\t\t RS:25\n 2. Chappathi \t\t\t\t\t\t RS:25\n 3. Tea \t\t\t\t\t\t RS:10\n 4. Coffee \t\t\t\t\t\t RS:12\n 5. Boost \t\t\t\t\t\t RS:10\n 6. Moltova \t\t\t\t\t\t RS:10\n 7. Complain \t\t\t\t\t\t RS:10\n 8.Black Tea \t\t\t\t\t\t RS:15\n 9. Jammun \t\t\t\t\t\t RS:15\n 10.exit";
             quantity(10,4);
          }
    }
    void quantity(int x,int y)
        {


                  do
                    {
                        cout<<"\n Choose option : ";
                        cin>>ch1;
                        if(ch != x)
                        {
                        cout<<"\n sets : ";
                        cin>>se;
                        ch=ch1;
                        if(y==1)
                        {
                            strcpy(food[i],foo1[ch]);
                            setset[i]=se;
                            costtt[i]=cost1[ch];
                            setta=se*cost1[ch-1];
                            total=total+setta;
                        }
                         if(y==2)
                        {
                            strcpy(food[i],foo2[ch]);
                            setset[i]=se;
                            costtt[i]=cost2[ch];
                            setta=se*cost2[ch-1];
                            total=total+setta;
                        }
                         if(y==3)
                        {
                            strcpy(food[i],foo3[ch]);
                            setset[i]=se;
                            costtt[i]=cost3[ch];
                            setta=se*cost3[ch-1];
                            total=total+setta;
                        }
                         if(y==4)
                        {
                            strcpy(food[i],foo4[ch]);
                            setset[i]=se;
                            costtt[i]=cost4[ch];
                           setta=se*cost4[ch-1];
                            total=total+setta;
                        }
                         if(y==5)
                        {
                            strcpy(food[i],foo5[ch]);
                            setset[i]=se;
                            costtt[i]=cost5[ch];
                            setta=se*cost5[ch-1];
                            total=total+setta;
                        }
                         if(y==6)
                        {
                            strcpy(food[i],foo6[ch]);
                            setset[i]=se;
                            costtt[i]=cost6[ch];
                            setta=se*cost6[ch-1];
                            total=total+setta;
                        }
                         if(y==7)
                        {
                            strcpy(food[i],foo7[ch]);
                            setset[i]=se;
                            costtt[i]=cost7[ch];
                            setta=se*cost7[ch-1];
                            total=total+setta;
                        }
                         if(y==8)
                        {
                            strcpy(food[i],foo8[ch]);
                            setset[i]=se;
                            costtt[i]=cost8[ch];
                            setta=se*cost8[ch-1];
                            total=total+setta;
                        }


                        i=i+1;
                        cow=i;
                        }
                    }while(ch != x);
                    /*/ switch(y)
            {
            case 1:
                {

                    cost[100]=30,45,35,5,40,10,12,10,15;
                }
                break ;
            case 2 :
                {

                    cost[100]=40,40,35,80,50,55,75,40,40;
                }
                break;
            case 3 :
                {
                     cost[100]=30,45,35,5,40,10,12,10,15;
                    cost[100]=80,95,95,95,25,45,85,25,35;
                cost[100]=25,25,10,12,10,10,10,15,15;
                cost[100]=30,45,35,5,40,10,12,10,15;
                cost[100]=100,110,100,80,80,50,120,60,150,90,90,50;
                cost[100]=120,90,90,150,130,130,90,90,90,75,75,75,75,80,80,80,95,95,95,95,95,95,85,100,95;
                cost[100]=25,25,10,12,10,10,10,15,15;
                }
                break;
            case 4 :
                {


                }
                break;
                 case 5:
               {


               }
               break ;
                 case 6:
                  {


                  }
                    break ;
                 case 7 :
                    {

                        cost[100]=120,90,90,150,130,130,90,90,90,75,75,75,75,80,80,80,95,95,95,95,95,95,85,100,95;
                    }cout<<total;
                    break;
                    case 8:
                {

                    cost[100]=25,25,10,12,10,10,10,15,15;
                }

            }*/

            }

    void nonveg()
    {
        if((hour >=1 ) && (hour <=11 ))
           {
               cout<<"\n Menu : ";
                cout<<"\n 1. Idly \t\t\t\t\t\t RS:30 \n 2. Dosa \t\t\t\t\t\t RS:45\n 3. Pongal \t\t\t\t\t\t RS:35\n 4. Vadai \t\t\t\t\t\t RS:5\n 5. Poori \t\t\t\t\t\t RS:40\n 6. Tea \t\t\t\t\t\t RS:10\n 7. Coffee \t\t\t\t\t\t RS:12\n 8.Milk \t\t\t\t\t\t RS:10\n 9. Jammun \t\t\t\t\t\t RS:15\n 10.exit";
                quantity(10,5);
           }
           else if((hour>=12)&&(hour<=18))
           {
               cout<<"\n Menu : ";
               cout<<"\n BRIYANI \n\tNON-VEG \n 1. Chicken Briyani \t\t\t\t\t\t RS:100\n 2. Mutton Briyani \t\t\t\t\t\t RS:110\n 3. Fish Briyani \t\t\t\t\t\t RS:100\n\t VEG \n 4. Veg Briyani \t\t\t\t\t\t RS:80\n\n Meals \n\t VEG \n 5. Veg Meals \t\t\t\t\t\t RS:80\n 6. Veg-Mini Meals \t\t\t\t\t\t RS:50";
               cout<<" \n\t NON-VEG \n 7. Non-Veg Meals \t\t\t\t\t\t RS:120\n 8. Non-Veg Mini Meals \t\t\t\t\t\t RS:60\n\n STARTERS \n\t NON-VEG \n 10. Fish Fry \t\t\t\t\t\t RS:150\n 11. Chicken 65 \t\t\t\t\t\t RS:90\n 12. Mutton 65 \t\t\t\t\t\t RS:90\n\n SOUP \n\t VEG \n 13. Sweet corn Soup \t\t\t\t\t\t RS:50\n 14. Mushroom Soup \t\t\t\t\t\t RS:50\n\t NON-VEG \n 15. Aatu Kall Soup \t\t\t\t\t\t RS:50\n  16.Exit";
               quantity(16,6);
           }
           else if((hour>=19)&&(hour<=22))
           {
                cout<<"\n Menu : ";
               cout<<"\n \n STARTERS \n\t NON-VEG \n 1. Fish Fry \t\t\t\t\t\t RS:120\n 2. Chicken 65 \t\t\t\t\t\t RS:90\n 3. Mutton 65 \t\t\t\t\t\t RS:90\n 4. Dragon Chicken \t\t\t\t\t\t RS:150\n 5. Chilly Chicken \t\t\t\t\t\t RS:130\n 6. Chilly MUtton \t\t\t\t\t\t RS:130\n\t VEG \n 7. Panneer Fry \t\t\t\t\t\t RS:130\n 8. Mushroom Fry \t\t\t\t\t\t RS:90\n 9. Gobi Manchurian \t\t\t\t\t\t RS:90\n 10. Panneer Finger \t\t\t\t\t\t RS:90\n\n SOUP \n\t VEG \n 11. Sweet corn Soup \t\t\t\t\t\t RS:50\n 12. Mushroom Soup \t\t\t\t\t\t RS:50";
               cout<<"\n 13. Baby Corn Soup \t\t\t\t\t\t RS:50\n 14. Ginger Garlic Soup \t\t\t\t\t\t RS:50\n 15. Pepper Garlic soup \t\t\t\t\t\t RS:50\n\t NON-VEG \n 16. Aatu Kall Soup \t\t\t\t\t\t RS:80\n 17. Chicken Soup \t\t\t\t\t\t RS:80\n \n\n FRIED RICE \n\t VEG \n 18. Fried Rice \t\t\t\t\t\t RS:80\n 19. Paneer Rice \t\t\t\t\t\t RS:95\n 20. Gobi Rice \t\t\t\t\t\t RS:95\n 21. Mushroom Rice  \t\t\t\t\t\t RS:95\n\t NON-VEG \n 22. Chicken Fried Rice \t\t\t\t\t\t RS:95\n 23. Egg Fried Rice \t\t\t\t\t\t RS:85";
               cout<<"\n 24.Schwan Chicken Rice \t\t\t\t\t\t RS:100\n 25. Mutton Rice \t\t\t\t\t\t RS:95\n 26.Exit";
               quantity(26,7);
           }
          else if((hour>=23)&&(hour<=24))
          {
              cout<<"\n Memu : ";
              cout<<"\n 1. Parota \n 2. Chappathi \n 3. Tea \n 4. Coffee \n 5. Boost \n 6. Moltova \n 7. Complain \n 8.Black Tea \n 9. Jammun \n 10.exit";
             quantity(10,8);
          }
    }
}r;

class orderinfo
{
public :
    string add;
   void getadd()
      {
        cout<<"\n Enter the address : ";
        cin>>add;
        display();
    }
    void display()
    {
        cout<<"\n Your Orders ..";
       for(i=0;i<cow;i++)
       {
           cout<<endl;
           cout<<"\n\t\t";
           cout<<food[i] <<"\t" <<setset[i] <<"\t" <<costtt[i];
           cout<<endl<<endl;
       }
        cout<<"\n\t\t TOTAL : "<<total;
        cout<<endl<<endl;
        cout<<endl<<endl;
    }


}o;

class payment
{
	public:
		int card1,walet;



		void pay_method()
		{
			int option;
			cout<<"\t\t\t\t*******************PAYMENT METHODS**********************";
			cout<<endl;
			cout<<"\t\t\t\tChoose the payment methods";
			cout<<endl;
			cout<<"\t\t1.NET BANKING \t 2.DEBIT/CREDIT CARD  \t 3.CASH ON DELIVERY \t 4.WALLET";
			cout<<endl;
			cout<<"Choose the payment methods : ";
			cin>>option;

			switch (option)
			{

				case 1:
					{
					    cout<<endl;
					    cout<<"You have chosen Net banking";
						 Netbanking();
						 break;
					}
				case 2:
					{
					    cout<<endl;
					    cout<<"You have chosen Card payment";
						card();
						break;
					}
				case 3:
					{
					    cout<<endl;
					    cout<<"You have chosen Cash on Delivery";
						cod();
						break;
					}
				case 4:
					{
					    cout<<endl;
					    cout<<"You have chosen Wallet Payment";
						wallet();
						break;
					}
                default:
                    {
                        cout<<endl;
                        cout<<"Enter the correct choice";
                        system("cls");
                        pay_method();
                    }
			}

		}
		void Netbanking()
		{
			int bank;
			char banks[15];
			cout<<endl;
			cout<<"\t\t1.Andhra Bank \t\t 2.City Union Bank \t\t3.Allahabad Bank\n";
			cout<<endl;
			cout<<"\t\t4.HDFC Bank \t\t 5.Bank of Baroda \t\t6.IndusInd Bank\n";
			cout<<endl;
			cout<<"\t\t7.Canara Bank \t\t 8.Syndicate Bank \t\t9.IDBI Bank\n";
			cout<<endl;
			cout<<"\t\t10.Icici Bank \t\t 11.Corporation Bank \t\t12.Indian Overseas Bank\n";
			cout<<endl;
            cout<<"\t\t13.State Bank Of India \t 14.Punjab National Bank \t15.Indian Bank\n\n";
            cout<<"\t\t\t\t\tChoose Your Bank : ";
            cin>>bank;
            switch (bank)
            {

					case 1:
            		{
            			user();
            			break;
					}
					case 2:
            		{
            			user();
            			break;
					}
					case 3:
            		{
            			user();
            			break;
					}
					case 4:
            		{
            			user();
            			break;
					}
					case 5:
            		{
            			user();
            			break;
					}
					case 6:
            		{
            			user();
            			break;
					}
					case 7:
            		{
            			user();
            			break;
					}
					case 8:
            		{
            			user();
            			break;
					}
					case 9:
            		{
            			user();
            			break;
					}
					case 10:
            		{
            			user();
            			break;
					}
					case 11:
            		{
            			user();
            			break;
					}
					case 12:
            		{
            			user();
            			break;
					}
					case 13:
            		{
            			user();
            			break;
					}
					case 14:
            		{
            			user();
            			break;
					}
					case 15:
            		{
            			user();
            			break;
					}
					default:
						{
							cout<<endl;
                            system("cls");
                            cout<<"Choose the correct Bank:";
                            Netbanking();

						}
			}

		}
		void card()
		{

			cout<<"\n\t\t1.Debit Card \t\t2.Credit Card";
			cout<<"\n\tChoose Your Card:";
			cin>>card1;
			switch (card1)
			{
				case 1:
					{
						debit();
						break;
					}
				case 2:
					{
						debit();
						break;
					}
				default:
					{
						cout<<endl;
                        system("cls");
                        cout<<"Choose the valid Card Option:";
                        card();
					}
			}
		}
		void debit()
		{
			int cnum,cvv,select;
			char date[11], cname[30];
			if(card1==1)
			{
				cout<<"\n\t\t\t\tEnter Your Debit Card Information\n\n";
			}
			else
			{
				cout<<"\n\t\t\t\tEnter Your Credit Card Information\n\n";
			}
			cout<<"\t\tNAME ON CARD:";
			cin>>cname;
			cout<<"\n\n\t\tCARD NUMBER:";
			cin>>cnum;
			cout<<"\n\t\tEXPIRATION DATE:";
			cin>>date;
			cout<<"\n\t\tCVV NUMBER:";
			cin>>cvv;
			cout<<"\nPress one for CONFIRM or two for CANCEL\n";
			cout<<"\t\t\t1.CONFIRM \t\t\t 2.CANCEL";
			cin>>select;
			if(select==1)
			{
				cout<<"\n\tYou have done successful payment";
			}
			else
			{
				cout<<"\n\tYou have cancelled your payment request";
			}


		}
		void cod()
		{
			cout<<"You are Eligible for Cash on Delivery";


		}
		void wallet()
		{

			cout<<"\n\t\t1.PAYPAL \t\t2.PAYTM \t\t3.AMAZON PAY";
			cout<<"\n\tChoose Your Wallet:";
			cin>>walet;
			switch (walet)
			{
				case 1:
					{
						wallet_info();
						break;
					}
				case 2:
					{
						wallet_info();
						break;
					}
				case 3:
					{
						wallet_info();
						break;
					}
				default:
					{
						cout<<endl;
                        system("cls");
                        cout<<"Choose the valid Wallet Option:";
                        card();
					}
			}

		}
		void wallet_info()
		{
			int selection;
			char email[35],password[20];
			if(walet==1)
			{
				cout<<"\n\t\t\tLogin into your PAYPAL account\n";

			}
			else if(walet==2)
			{
				cout<<"\n\t\t\tLogin into your PAYTM account\n";
			}
			else
			{
			  cout<<"\n\t\t\tLogin into your AMAZON PAY account\n";
			}
			cout<<"\t\tEMAIL OR PHONE NUMBER:";
			cin>>email;
			cout<<"\n\n\t\tPASSWORD:";
			cin>>password;

			cout<<"\t\t\t1.CONFIRM \t\t\t 2.CANCEL";
			cout<<"\nPress one for CONFIRM or two for CANCEL:";
			cin>>selection;
			if(selection==1)
			{
				cout<<"\n\tYou have done successful payment";
			}
			else
			{
				cout<<"\n\tYou have cancelled your payment request";
			}
		}
		void user()
		{
			int select;
			char login[20],pass[20];
			system("cls");
			cout<<"\n\t\t\t\tWelcome to your Bank\n";
			cout<<"\t\t\tEnter Your Login Id:";
			cin>>login;
			cout<<"\n\t\t\tEnter Your Password:";
			cin>>pass;
			cout<<"\t\tFoodhunt is requested to pay some Amount\n";
			cout<<"Press one for CONFIRM or two for CANCEL\n";
			cout<<"\t\t\t1.CONFIRM \t\t\t 2.CANCEL";
			cin>>select;
			if(select==1)
			{
				cout<<"\nYou have done successful payment";
			}
			else
			{
				cout<<"\nYou have cancelled your payment request";
			}

		}
}pay;

class feedback
{
	public:
	void feedback1()
	{
		char fback[500];
		int select;
		cout<<"\n\t\t\t\t\t\tGET IN TOUCH WITH US\n";
		cout<<"\n\tGive Your Valuable Feedback Here:\t";
		cin>>fback;
		cout<<"\nPress one for CONFIRM or two for CANCEL\n";
			cout<<"\t\t\t1.CONFIRM \t\t\t 2.CANCEL";
			cout<<"\n\t\tEnter here:";
			cin>>select;
			if(select==1)
			{
				cout<<"\n\tThanks for your Valuable Feedback";
			}
			else
			{
				  cout<<"Please Enter Your Feedback";
			  system("cls");
			  feedback1();
			}

	}
};

int main()
{
    int option;


    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","admin","admin","foodhunt",0,NULL,0);

    if(conn)
    {
        cout<<"\n \n\tFOODHUNT";
     do
    {
        cout<<"\n\n 1. New User signup " <<"\n 2. Login " << "\n 3. Exit";
        cout<<"\n Enter the option : ";
        cin>>option;
        switch(option)
        {
            case 1 : u.usersignup();
            break;
            case 2 : u.userlogin();
            break;
            case 3 : cout<<"\n Thank you ";
            break;
            default : cout<<"\n Please 1 2 or 3 ";
        }
    }while((option!=3) && (flag==0));
    if(flag==1)
    {
        system("CLS");
    cout<<"\n FOOD HUNT ";

    time_t now = time(0);
   tm *ltm = localtime(&now);
   hour= 1 + ltm->tm_hour;
   cout<<hour;

    r.hotel();
    o.getadd();
    pay.pay_method();
    feedback data;
	data.feedback1();
    }
    }
    else
        cout<<"\n Server error..hi.";

    return 0;
}







