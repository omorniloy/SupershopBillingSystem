//header files
#define MAX 10
#define BRANCH 2
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct date
{
    int mm,dd,yy;
};

//classes
class product
{
protected:
    int number;
    string name;
    date d1,d2;
    static int a,branch;
public:
    product() : name(){
    }
    ~product(){
    }
    void setnumber()
    {
        number=99*10000+((branch+1)*100)+(a+1);
        a++;
        if (a==MAX)
        {
            ++branch;
            a=0;
        }
    }
    void setname(string b)
    {
        name=b;
    }


    int getnumber()const
    {
        return number;
    }
    string getname()const
    {
        return name;
    }

    void shownumber()const
    {
        cout<<"\t\tProduct number: "<<number<<endl;
    }
    void showproductInfo()const
    {
        cout<<"\t\tProduct number: "<<number<<endl;
        cout<<"\t\tName of the product : "<<name<<endl;
        /*cout<<"\t\tMfg. date :"<<d1.dd<<"."<<d1.mm<<"."<<d1.yy;
		cout<<endl;
        cout<<"\t\tExp. date :"<<d2.dd<<"."<<d2.mm<<"."<<d2.yy;
        cout<<endl;*/
    }

    void inputproductInfo()
    {
        cout<<"\t\tEnter Name of the product : ";
        fflush(stdin);
        getline(cin,name);
        cout<<"\t\tMfg. date :\n";
        cout<<"\t\t\tday	:";
        cin>>d1.dd;
        cout<<"\t\t\tmonth	:";
        cin>>d1.mm;
        cout<<"\t\t\tyear	:";
        cin>>d1.yy;
        cout<<"\t\tExp. date :\n";
        cout<<"\t\t\tday	:";
        cin>>d2.dd;
        cout<<"\t\t\tmonth	:";
        cin>>d2.mm;
        cout<<"\t\t\tyear	:";
        cin>>d2.yy;
    }
};

class amount: public product        //derived class
{
private:
    float price,quantity,vat,discount,netamount,g;
public:
    amount(): price(), quantity(), vat(), discount(), netamount(){
    }
    ~amount(){
    }
    void setprice(float c)
    {
        price=c;
    }
    void setvat(float d)
    {
        vat=d;
    }
    void setdiscount(float e)
    {
        discount=e;
    }
    void setquantity(float f)
    {
        quantity=f;
    }
    void setnetamount(float g)
    {
        netamount=g;
    }

    float getprice()const
    {
        return price;
    }
    float getvat()const
    {
        return vat;
    }
    float getdiscount()const
    {
        return discount;
    }
    float getquantity()const
    {
        return quantity;
    }
    float getnetamount()
    {
        return netamount;
    }

    void showproductInfo()const
    {
        product :: showproductInfo();
        cout<<"\t\tPrice of the product : "<<price<<endl;
        cout<<"\t\tQuantity of the product : "<<quantity<<endl;
        cout<<"\t\tDiscount : "<<discount<<endl;
    }

    void inputproductInfo()
    {
        product :: inputproductInfo();
        cout<<"\t\tEnter Price of the product : ";
        cin>>price;
        cout<<"\t\tEnter Quantity of the product : ";
        cin>>quantity;
        cout<<"\t\tEnter Discount : ";
        cin>>discount;
        calculateNetamount();
    }

    void addProduct(int a)
    {
        quantity=a;
        quantity++;
    }

    void calculateVat()
    {
        vat=price*5/100;
    }

    void calculateDiscount()
    {
        discount=price*10/100;
    }

    void calculateNetamount()
    {
        netamount=quantity*(price+vat-discount);
    }

    void detail()
    {
        cout<<"\n\n\n\t\t*********************************************";
        cout<<"\n\t\t*                Detail                     *";
        cout<<"\n\t\t*********************************************";
        cout<<"\n\t\tPRICE                      :"<<price;
        cout<<"\n\t\tQUANTITY                   :"<<quantity;
        cout<<"\n\t\tVAT PERCENTAGE             :"<<vat;
        cout<<"\n\t\tDISCOUNT PERCENTAGE        :"<<discount;
        cout<<"\n\t\tNET AMOUNT               TK:"<<netamount;
        cout<<"\n\t\t*********************************************";
        cout<<endl<<endl;
    }

    void sellProduct()
    {
        char ch;
        cout<<"\t\tDo you want to buy this prduct? (y/n)";
        cin>>ch;
            if (ch=='y' ||ch=='Y')
            {
                int q;
                cout<<"\t\tEnter quantity : ";
                cin>>q;
                quantity -= q;
            }
            else
                cout<<"\t\tPlease choose another product."<<endl;

        cout<<endl;
    }
};

class branch
{
private:
    float total;
public:
    branch (): total(0){
    }
    branch (float ttl): total(ttl){
    }
    ~branch() {
    }
    void settotal(int t)
    {
        total=t;
    }
    float gettotal()const
    {
        return total;
    }
    void showtotal()const
    {
        cout<<"\t\tEnd of the day total balance :"<<total<<endl;
    }
    void inputtotal()
    {
        cout<<"\t\tEnter total : "<<endl;
        cin>>total;
    }
    void calculateTotal(float b)
    {
        total+=b;
    }

};

class employee                                  // abstract base class
{
protected:
    string name;
    int id;
    float salary;
public:
    employee () : name(), id() {
    }
    employee (string nam, int nmbr) : name(nam), id(nmbr){
    }
    ~employee(){
    }

    void calculateSalary(float s, float a)
    {
        salary = s*a;
    }
};

class bonusEmployee : public employee           //derived class ,multi-level inheritance
{
protected:
    float bonus;
public:
    bonusEmployee(): bonus () {
    }
    bonusEmployee (float bon) : bonus(bon) {
    }
    ~bonusEmployee() {
    }
    void setbonus(int b)
    {
        bonus=b;
    }
    float getbonus()const
    {
        return bonus;
    }
    void showbonus()const
    {
        cout<<" bonus: "<<bonus<<endl;
    }
    void inputbonus()
    {
        cout<<"\t\tEnter sellsman bonus: "<<endl;
        cin>>bonus;
    }

    void calculateBonus(float c, int x)
    {
        bonus=c*x/100;
    }
};

class sellsman : public bonusEmployee             // derived class, multi-level inheritance
{
public:
    sellsman () : bonusEmployee(){
    }
    ~sellsman (){
    }
};

class manager : public bonusEmployee                // derived class, multi-level inheritance
{
public:
    manager () : bonusEmployee(){
    }
    ~manager(){
    }
};

int product::branch=0;
int product::a=0;

int main()
{
    int i,j,k,c;
    float grand;
    char ch;
    amount a[BRANCH][MAX];
    branch bra[BRANCH];
    sellsman sman[BRANCH][2];
    manager m[BRANCH];

    cout<<"\n\n\t SUPER SHOP BILLING SYSEM\n";
    cout<<"\t--------------------------\n";

    do
    {
        cout<<"\n\n\n\tMENU";
        cout<<"\n\n\t1.Create Information";
        cout<<"\n\n\t2.Show Information";
        cout<<"\n\n\t3.Add Product";
        cout<<"\n\n\t4.Sell Product";
        cout<<"\n\n\t5.Show Bill Detail";
        cout<<"\n\n\t6.Total Bill";
        cout<<"\n\n\t7.Branch Info";
        cout<<"\n\n\t8.Employee Detail";
        cout<<"\n\n\t9.EXIT";
        cout<<"\n\n\tPlease Enter Your Choice (1-9) : ";
        cin>>c;
        cout<<endl<<endl;
    switch(c)
    {
    case 1:
        for(i=0; i<BRANCH; i++)
        for(j=0; j<MAX; j++)
        {
            a[i][j].setnumber();
            a[i][j].shownumber();
            a[i][j].inputproductInfo();
            cout<<endl;
        }
    break;

    case 2:
        for(i=0; i<BRANCH; i++)
            for(j=0; j<MAX; j++)
            {
                a[i][j].showproductInfo();
                cout<<endl;
            }
        break;

    case 3:
        for(i=0; i<BRANCH; i++)
            for(j=0; j<MAX; j++)
            {
                int add;
                a[i][j].shownumber();
                cout<<"\t\tAdd product quantity:";
                cin>>add;
                a[i][j].addProduct(add);
            }
        break;

    case 4:
        while(1)
        {
            for(i=0; i<BRANCH; i++)
                for(j=0; j<MAX; j++)
                {
                    a[i][j].shownumber();
                    a[i][j].sellProduct();
                    a[i][j].calculateNetamount();
                }
            cout<<"\n\t\tDo You Want To Order Another Product ? (y/n)";
            cout<<endl;
            cin>>ch;
            if (ch=='y' ||ch=='Y')
                continue;
            else
                break;
        }
        break;

    case 5:
        for(i=0; i<BRANCH; i++)
            for(j=0; j<MAX; j++)
            {
                a[i][j].calculateVat();
                a[i][j].calculateDiscount();
                a[i][j].calculateNetamount();
                a[i][j].detail();
            }

        break;

    case 6:
        for(i=0; i<BRANCH; i++)
            for(j=0; j<MAX; j++)
            {
                grand=a[i][j].getnetamount();
                grand++;
            }
            cout<<"\t\tGrand Total: "<<grand<<endl<<endl;
        break;

    case 7:
        for (i=0;i<BRANCH;i++)
            for(j=0;j<MAX;j++)
            {
                bra[i].calculateTotal(a[i][j].getnetamount());
            }

        for (i=0;i<BRANCH;i++)
        {
            bra[i].showtotal();
            cout<<endl;
        }
        break;

    case 8:
        for(i=0; i<BRANCH; i++)
        {
            sman[i][0].calculateBonus(bra[i].gettotal(), 3);
            sman[i][1].calculateBonus(bra[i].gettotal(), 3);
        }

        for (i=0;i<BRANCH;i++)
            for(k=0;k<2;k++)
            {
                cout<<"\t\tBranch "<<i+1<<": "
                    <<"\tsellsman "<<k+1<<": ";
                sman[i][k].showbonus();
                cout<<endl;
            }

        for (i=0;i<BRANCH;i++)
            {
                m[i].calculateBonus(bra[i].gettotal(), 5);
            }

        for (i=0;i<BRANCH;i++)
        {
            cout<<"\t\tBranch "<<i+1<<": "<<"\tManager ";
            m[i].showbonus();
            cout<<endl;
        }
        break;

    case 9:
        cout<<"\n\n\tThanks for using Super Shop Information System softwere.\n\n";
        break;

    }

    }while(c!=9);

    fflush(stdin);
    getchar();
    return 0;
}
