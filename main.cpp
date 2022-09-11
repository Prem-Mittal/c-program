#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float disc;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void lis();
    void reciept();
};
void shopping::menu()
{
m:
    string email;
    int choice;
    string password;

    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t SUPERMARKET MAIN MENU \n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t_______________________\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t   1. ADMINISTRATOR    \n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t   2.BUYER             \n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t   3.EXIT              \n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t  Please Select        \n";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t\t Please login \n";
        cout<<"\t\t\t\t Enter email id \n";
        cin>>email;
        cout<<"\t\t\t\t Enter Password \n";
        cin>>password;

        if(email=="premmittal88@gmail.com"&& password=="Prem")
        {
            administrator();
        }
        else
        {
            cout<<"Invalid Email ID and Password";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout<<"Invalid choice \n";
    }
    }
    goto m;
}

void shopping::administrator()
{
m:
    int choice;
    cout<<"\n\n\t\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|___1)Add the Product______|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___2)Modify the Product___|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___3)Delete the Product___|";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|___4)Back to main menu____|";
    cout<<"\n\t\t\t|                          |";

    cout<<"\n\n\t Please Enter your choice";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"Invalid Choice! Please choose again";

    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout<<"\t\t\t    Buyer       \n";
    cout<<"______________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t 1)Buy product  \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2)Go back      \n";
    cout<<"\t\t\t Enter your choice:";

    cin>>choice;

    switch(choice)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
    default:
        cout<<"Invalid Choice";
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the Product";
    cin>>pname;
    cout<<"\n\n\t Price of the Product";
    cin>>price;
    cout<<"\n\n\t Discount of the Product";
    cin>>disc;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app| ios::out );
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app| ios::out );
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
            data.close();
        }
    }
    cout<<"\n\n\t\t Record Inserted !";

}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t Modify the Record";
    cout<<"\n\n\t\t Enter the Product Code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\tFile doesnt Exist";
    }
    else
    {
        data1.open("database1.txt", ios::app| ios::out);
        data>>pcode>>pname>>price>>disc;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t\t Product New Code:";
                cin>>c;
                cout<<"\n\n\t\t Name of the product";
                cin>>n;
                cout<<"\n\n\t\t Price";
                cin>>p;
                cout<<"\n\n\t\t discount";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
            }
            data>>pcode>>pname>>price>>disc;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found!";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product Code";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app| ios::out);
        data>>pcode>>pname>>price>>disc;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<disc<<"\n";
            }
            data>>pcode>>pname>>price>>disc;

        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record Not found";
        }
    }
}

void shopping::lis()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n!______________________________________________\n";
    cout<<"Product No\t\tName\t\tPrice\n";
    cout<<"\n\n!______________________________________________\n";
    data>>pcode>>pname>>price>>disc;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>disc;
    }
    data.close();
}

void shopping::reciept()
{
m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t  Reciept";
    data.open("database.txt", ios::in );
    if(!data)
    {
        cout<<"\n\nEmpty database";
    }
    else
    {
        data.close();

        lis();
        cout<<"\n\n!______________________________________________\n";
        cout<<"\n\n!                                              \n";
        cout<<"\n\n!        Please place the order                \n";
        cout<<"\n\n!                                              \n";
        cout<<"\n\n!______________________________________________\n";
        do
        {
            cout<<"\n\n\t\tEnter Product Code\n";
            cin>>arrc[c];
            cout<<"\t\tEnter the Product Quantity\n";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code Try Again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n\t\t Do you want to buy another product or not. If yes type y else n";
            cin>>choice;
        }
        while(choice=="y");

        cout<<"\n\n\t\t\t______________Reciept__________________\n";
        cout<<"\n \tProduct No\t Product name \t Product Quantity \t Price \t Amount \tAmount with discount";

        for(int i=0; i<c; i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>disc;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*disc/100);
                    total=total+dis;
                    cout<<"\t\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>disc;
            }
        }
        data.close();

    }
    cout<<"\n\n___________________________________________";
    cout<<"\n\n Total amount:"<<total;
}

int main()
{
    shopping s;
    s.menu();
}
