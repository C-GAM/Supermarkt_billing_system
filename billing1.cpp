#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    std::cout << "\t\t\t\t__________________________________\n";
    std::cout << "\t\t\t\t                                  \n";
    std::cout << "\t\t\t\t     Supermarkt Main Menu         \n";
    std::cout << "\t\t\t\t                                  \n";
    std::cout << "\t\t\t\t__________________________________\n";
    std::cout << "\t\t\t\t                                  \n";
    std::cout << "\t\t\t\t    1)Administrator      \n";
    std::cout << "\t\t\t\t                         \n";
    std::cout << "\t\t\t\t    1)Buyer              \n";
    std::cout << "\t\t\t\t                         \n";
    std::cout << "\t\t\t\t    3)Exit               \n";
    std::cout << "\t\t\t\t                         \n";
    std::cout << "\n\t\t\t    Please select !    \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "\t\t\t\t Please Login \n";
        std::cout << "\t\t\t\t Enter Email  \n";
        cin >> email;
        std::cout << "\t\t\t\t Password     \n";
        cin >> password;

        if (email == "charfeddinegam@gmail.com" && password == "theadminpassword")
        {
            administrator();
        }
        else
        {
            std::cout << "Invalid Email/Password";
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
        std::cout << "Please select from the given options" ;
    }
}
    goto m;
}
void shopping::administrator()
{
m:
    int choice;
    std::cout << "\n\n\n\t\t\t\t   Administrator menu    \n";
    std::cout << "\n\t\t\t     1) Add the product        \n";
    std::cout << "\n\t\t\t                               \n";
    std::cout << "\n\t\t\t     2) Modify the product     \n";
    std::cout << "\n\t\t\t                               \n";
    std::cout << "\n\t\t\t     2) Delete the product     \n";
    std::cout << "\n\t\t\t                               \n";
    std::cout << "\n\t\t\t     2) Back to main menu      \n";
    std::cout << "\n\n\t\t     Please enter your choice  \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        menu();
        break;

    default:
        std::cout << "Invalid choice ";
    }

    goto m;
}
void shopping ::buyer()
{
m:
    int choice;
    std::cout << "\t\t\t     Buyer \n";
    std::cout << "\t\t\t ______________ \n";
    std::cout << "\t\t\t                \n";
    std::cout << "\t\t\t 1) Buy Product \n";
    std::cout << "\t\t\t                \n";
    std::cout << "\t\t\t 2) Go back     \n";
    std::cout << "\t\t\t Enter your choice : ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        std::cout << "invalid choice";
    }
    goto m;
}
void shopping ::add()
{
m:
    fstream data;
    int c;
    int tocken = 0;
    float p;
    float d;
    string n;

    std::cout << "\n\n\t\t Add new product ";
    std::cout << "\n\n\t\t Product code  ";
    cin >> pcode;
    std::cout << "\n\n\t\t Name of the product ";
    cin >> pname;
    std::cout << "\n\n\t\t Price of the product ";
    cin >> price;
    std::cout << "\n\n\t\t Discount on product ";
    cin >> dis;

    data.open("database.txt ,ios::in");

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                tocken++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (tocken == 1)
            goto m;

        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    std::cout << "\n\n\t\t Record inserted !";
}
void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int tocken = 0;
    int c;
    float p, d;
    string n;

    std::cout << "\n\t\t\t Modify the record ";
    std::cout << "\n\t\t\t Product code      ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        std::cout << "\t\n\n File doesn't exist !";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                std::cout << "\n\t\t Product new code :";
                cin >> c;
                std::cout << "\n\t\t Name of the product :";
                cin >> n;
                std::cout << "\n\t\t Price :";
                cin >> p;
                std::cout << "\n\t\t Discount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " "
                      << " " << d << "\n";
                std::cout << "\n\n\t\t Record edited";
                tocken++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (tocken == 0)
        {
            std::cout << "\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data1, data;
    int pkey;
    int token = 0;
    

    std::cout<<"\n\n\t Delete product";
    std::cout<<"\n\n\t Product code :";
    cin>>pkey ;
    data.open("database.txt",ios::in) ;
    if (!data)
    {
        std::cout<<"File doesnt exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if (pcode==pkey)
            {
                std::cout<<"\n\n\t Product deleted succesfully" ;
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n" ;
            }
            data>>pcode>>pname>>price>>dis ;
        }
        data.close();
        data1.close();
        remove("database.txt") ;
        rename("database1.txt","database.txt") ;

        if (token==0)
        {
            std::cout<<"\n\n Record not found ";
        }
    }

}

void shopping ::list ()
{
    fstream data ;
    data.open ("database.txt",ios::in) ;
    std::cout<<"\n\n |____________________________________________\n" ;
    std::cout<<"ProNo\t\tName\t\tPrice\n" ;
    std::cout<<"\n\n |____________________________________________\n" ;
    data>>pcode>>pname>>price>>dis ;
    while(!data.eof())
    {
        std::cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n" ;
        data>>pcode>>pname>>price>>dis;
    }
    data.close() ;
}

void shopping :: receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice ;
    int c=0;
    float amont =0;
    float dis =0 ;
    float total =0 ;
    m:
    std::cout<<"\n\n\t\t\t\t\t RECEIPT ";
    data.open ("database.txt",ios::in);
    if (!data)
    {
        std::cout<<"\n\n Empty database" ;
    }
    else {
        data.close();

        list();
        std::cout<<"\n________________________________________________\n";
        std::cout<<"\n                                                \n";
        std::cout<<"\n__________  Please place the order  ____________\n";
        std::cout<<"\n                                                \n";
        std::cout<<"\n________________________________________________\n";
        do
        {
            std::cout<<"\n\n Enter product code :" ;
            cin>>arrc[c] ;
            std::cout<<"\n\n Enter the product quqntity :" ;
            cin>>arrq[c] ;
            for (int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    std::cout<<"\n\n Duplicatw product code. Please try again";
                    goto m;
                }
            }
            c++;
            std::cout<<"\n\n Do you want to buy another product ? if yes then press y else no";
            cin>>choice ;
        } while (choice=='y');
        std::cout<<"\n\n\t\t\t________________RECCEIPT_____________________\n" ;
        std::cout<<"\nProduct No\t Product name\t Product quqntity\tPrice\tAmount\tAmount with discount\n";

        for (int i=0 ;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while (!data.eof())
            {
                if (pcode==arrc[i])
                {
                    amont=price*arrq[i] ;
                    dis=amont-(amont*dis/100) ;
                    total=total+dis ;
                    std::cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amont<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    std::cout<<"\n\n_______________________________________________" ;
    std::cout<<"\n Total Amount :"<<total ;
}

int main ()
{
    shopping s;
    s.menu();

}