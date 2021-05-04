#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>


class vehicle
{
	public:
	int vno;
	float amt;
	float count;
	char  dname[15],x,l[50];

	void input()
	{
		system("CLS");
		int d;
		cout<<"\n\n\t\tEnter the name of driver : ";
		cin>>dname;
		cout<<"\n\n\t\tEnter the car no : ";
		cin>>vno;
		cout<<"\n\n\t\tEnter the no of hours of stay : ";
		cin>>count;
		cout<<"\n\n\t\tEnter the time slot : ";
		cin>>l;

    }

    	void output()
	{
		cout<<"\n\n\t\tThe Driver Name : "<<dname<<endl;
		cout<<"\n\n\t\tThe Car No : "<<vno<<endl;
		cout<<"\n\n\t\tThe Hours Of Stay : " <<count;
		cout<<"\n\n\t\tThe Time Slot Of Parking : " <<l;

	}

	virtual float cal()
	{
	    amt=amt*count;

	}

}a,a1;




class twowheeler:public vehicle
{

public:
    float charge=10;

float cal()
	{
            amt=count*charge;
            return amt;
    }



};

class fourwheeler:public vehicle
{
public:
    float charge=20;

float cal()
	{
            amt=count*charge;
            return amt;
    }

};


class pspace
{
public:
        int sp_no;
       static int count1;
        twowheeler tt;
        fourwheeler ff;

        virtual void offer()
        {
            cout<<"virtual function\n";

        }

};
int pspace::count1=0;

class vipspace:public pspace
{
public:
    static int count2;
   float discount;
   float total;
    float offer1()
    {
          discount=tt.count*0.1;
            total=tt.cal();
            total=total-discount;
            return total;
        }

    float offer2()
    {
           discount=ff.count*0.1;
            total=ff.cal();
            total=total-discount;
            return total;
        }


};
int vipspace::count2=0;


class regspace:public pspace
{
public:
    static int count3;
    /*float offer()
    {
        float ch=0;
        return ch;

    }*/
};
int regspace::count3=0;


class lot

{
public:
    int lotn;
    pspace p[100];
    regspace r[75];
    vipspace v[25];
    int counter;

    void occupied()
    {
        cout<<"................TOTAL OCCUPIED SPACE="<<p[0].count1;
    }

    void freespace()
    {
        counter=counter-p[0].count1;
        cout<<"............NUMBER OF FREE SPACE="<<counter<<endl;
    }


};


void delete_record1()
{
    twowheeler t1;
    fourwheeler fo;
	int n,x;
	system("CLS");
	cout<<"Enter where you parked 1.VIP SPACE 2.REGULAR SPACE\n";
	cin>>x;
	if(x==1)
    {
	cout<<"\n\n\t\tEnter the car no you want to get depart : ";
	cin>>n;
	ifstream inFile;
    inFile.open("p1.dat", ios::binary);
	ofstream outFile;
    outFile.open("temp1.dat", ios::out | ios::binary);

    while(inFile.read((char*)&t1, sizeof(t1)))
    {
        if(t1.vno!= n)
        {

            outFile.write((char*)&t1, sizeof(t1));
        }

    }
    while(inFile.read((char*)&fo, sizeof(fo)))
    {
        if(fo.vno!= n)
        {

            outFile.write((char*)&fo, sizeof(fo));
        }

    }
    cout<<"\n\n\t\t Parking Record Deleted";

    inFile.close();
    outFile.close();

    remove("p1.dat");
    rename("temp1.dat", "p1.dat");
    }
    if(x==2)
    {
	cout<<"\n\n\t\tEnter the car no you want to get depart : ";
	cin>>n;
	ifstream inFile;
    inFile.open("p2.dat", ios::binary);
	ofstream outFile;
    outFile.open("temp2.dat", ios::out | ios::binary);

    while(inFile.read((char*)&t1, sizeof(t1)))
    {
        if(t1.vno!= n)
        {

            outFile.write((char*)&t1, sizeof(t1));
        }

    }
    while(inFile.read((char*)&fo, sizeof(fo)))
    {
        if(fo.vno!= n)
        {

            outFile.write((char*)&fo, sizeof(fo));
        }

    }
    cout<<"\n\n\t\t Parking Record Deleted";

    inFile.close();
    outFile.close();

    remove("p2.dat");
    rename("temp2.dat", "p2.dat");
    }
}

int main()
{

    fourwheeler fo;
    twowheeler t1;
    lot l;
    vipspace vp;
    regspace rp;
    pspace pp;
	int login();
    login();
	int choice,vno1,d,c1,c2,i,s;
	float t,di,b;
	while(1) {
	system("CLS");

     cout << "\n\n\t\t ====== CAR PARKING MANAGEMENT SYSTEM======";
     cout <<"\n\n                                          ";
     cout<<" \n\t\t\t======================";

     cout << "\n\n\t\t\t  1. Arrival of a Car";
      cout << "\n\n\t\t\t  2. Total no of cars Arrived";
     cout << "\n\n\t\t\t  3. Total parking charges of all cars with details";
     cout << "\n\n\t\t\t  4. Departure of the car";
     cout << "\n\n\t\t\t  5. Exit Program";
     cout<<" \n\t\t\t======================";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice ::";
     cin>>choice;
     switch(choice)
     {
      case 1 :


                cout<<"\nAre you a VIP(1) or regular(2)\n";
                cin>>c1;
                switch(c1)
               {
                      case 1:
                          cout<<"\nEnter your vehicle type two wheeler(1) or four wheeler(0)\n";
                      cin>>c2;
                    if(c2==1)
                   {
                       ofstream f1("p1.dat",ios::binary|ios::out|ios::app);
                       t1.input();
                       f1.write((char*)&t1,sizeof(t1));
                       l.v[vp.count2].tt=t1;
                       t= l.v[vp.count2].tt.cal();
                       di= l.v[vp.count2].offer1();

                      vp.count2++;
                      pp.count1++;

                   }
                   if(c2==0)
                   {
                        ofstream f1("p1.dat",ios::binary|ios::out|ios::app);
                        fo.input();
                        l.v[vp.count2].ff=fo;
                       t=l.v[vp.count2].ff.cal();
                       f1.write((char*)&fo,sizeof(fo));
                        di=l.v[vp.count2].offer2();

                      vp. count2++;
                        pp.count1++;

                   }
                   break;
                   case 2:cout<<"\nEnter your vehicle type two wheeler(1) or four wheeler(0)\n";
                   cin>>c2;
                   if(c2==1)
                   {
                       ofstream f1("p2.dat",ios::binary|ios::out|ios::app);
                       t1.input();
                       f1.write((char*)&t1,sizeof(t1));
                       l.r[rp.count3].tt=t1;
                       t= l.v[rp.count3].tt.cal();

                      rp.count3++;
                        pp.count1++;

                   }
                   if(c2==0)
                   {
                        ofstream f1("p2.dat",ios::binary|ios::out|ios::app);
                        fo.input();
                        l.v[rp.count3].ff=fo;
                       t=l.v[rp.count3].ff.cal();
                       f1.write((char*)&fo,sizeof(fo));

                       rp.count3++;
                         pp.count1++;

                   }
                   break;

              }
              break;






       case 2 :
           {
           	system("CLS");
  		   cout << "\n\n\t\t=== View the Records in the Parking Database ===";
           cout << "\n";
           cout<<"\n......................Press 1-Vip space 2-Regular space....................\n";
           cin>>s;
           if(s==1)
           {
           ifstream infile("p1.dat",ios::binary|ios::in);
           int d=1;
           while (infile.read((char *)&t1,sizeof (t1)))
		   {
		   system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<d;
           d++;
           t1.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
       	   }
       	    while (infile.read((char *)&fo,sizeof (fo)))
		   {
		system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<d;
           d++;
           fo.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
       	   }
           }

           if(s==2)
           {

           ifstream infile("p2.dat",ios::binary|ios::in);
           int d=1;
           while (infile.read((char *)&t1,sizeof (t1)))
		   {
		   system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<d;
           d++;
           t1.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
       	   }
       	    while (infile.read((char *)&fo,sizeof (fo)))
		   {
		system("CLS");
           cout << "\n";
           cout<<"\n\n\tThe Car position in parking lot : "<<d;
           d++;
           fo.output();
           cout<<"\n";
           cout<<"\n\n\n";
           system("PAUSE");
           cout<<endl;
       	   }

           }

           break;
           }



       	case 4:
		   {

		   delete_record1();
		   break;
	}
    	case 3:
		{
		    cout<<"vip space parking chages\n";
            ifstream infile("p1.dat",ios::binary|ios::in);
           while (infile.read((char *)&t1,sizeof (t1)))
		   {
             cout << "\n";
             vp.tt=t1;
			 b=vp.offer1();
			 t1.output();
			 cout<<"\nParking charges="<<b<<endl;
			 cout<<"\n";

			 cout<<endl;

       		}
       		while (infile.read((char *)&fo,sizeof (fo)))
		   {
             cout << "\n";
             vp.ff=fo;
			 b=vp.offer2();
			 fo.output();
			 cout<<"\nParking charges="<<b<<endl;
			 cout<<"\n";

			 cout<<endl;

       		}
			cout<<"\n\n\t\tPress Enter to continue........................";
       		break;
   }

   		case 5:
		   {
		   	system("CLS");
		   	cout<<"\n\n\n\t\t\tTerminating";
		   	for(int k=0;k<8;k++)
		   	{for(i=0;i<100000000;i++);
		   	cout<<".";}
		   exit(0);
   			break;
   		}
   		default :
		   {
		   cout<<"\n\n\t\t Invalid input";
			cout<<"\n\n\t\tPress Enter to continue";


   	}
   }
getch();
}}

int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\tCar Parking Management System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");

   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}


