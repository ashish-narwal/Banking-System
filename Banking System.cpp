
#include<bits/stdc++.h>
using namespace std;
class bank;
class branch;
class account;
class savings_account;
class current_account;
class loan
{
private:
    int loan_no;
    int amount;
    int branch_code;
public:
    loan()
    {
        ;
    }
    loan(int l,int a,int b)
    {
        loan_no=l;
        amount=a;
        branch_code=b;
    }
    int get_lno()
    {
        return loan_no;
    }
    int get_amount()
    {
        return amount;
    }
    int get_bcode()
    {
        return branch_code;
    }
    
   void update_balance(int bala){
    amount=bala;
}
    void prepayment()
    {
        int prepay;
        int l_no,b_code;
       
        cout<<"enter loan number and branch code"<<endl;
        cin>>l_no>>b_code;
                fstream file;
                file.open("loan.dat",ios::in|ios::out|ios::ate|ios::binary);
                file.clear();
                file.seekg(0);
                loan a;
                file.read((char*)&a,sizeof(a));
                while(!file.eof()){
                    if(l_no==a.get_lno()&&b_code==a.get_bcode()){
                        cout<<"Enter prepayment amount"<<endl;
                        cin>>prepay;
                       
                        a.update_balance(a.get_amount()-prepay);
                        file.seekp(file.tellp()-sizeof(a));
                        file.write((char*)&a,sizeof(a));
                       break;
                    }
                    file.read((char*)&a,sizeof(a));
                }
      
                file.close();
        
    
    }
    void getemi()
    {
         int l_no,b_code;
         float emi=0;
  
        cout<<"enter loan number and branch code"<<endl;
        cin>>l_no>>b_code;
                fstream file;
                file.open("loan.dat",ios::in|ios::out|ios::ate|ios::binary);
                file.clear();
                file.seekg(0);
                loan a;
                file.read((char*)&a,sizeof(a));
                while(!file.eof()){
                    if(l_no==a.get_lno()&&b_code==a.get_bcode()){
                        float r=5;
                        float t;
                        cout<<"Enter duration in years"<<endl;
                        cin>>t;
                        
                        r=r/(12*100);
                        t=t*12;
                        int f=a.get_amount();
                        emi=(f*r*pow(1+r,t))/(pow(1+r,t)-1);
                        
                        cout<<emi<<endl;
                        
                       break;
                    }
                    file.read((char*)&a,sizeof(a));
                }
      
                file.close();
      
    }
};
class account
{
     private:
     int ac_no,bra_code,bal;
     public:
     account();
     account(int,int,int);
     void getaccinfo();
     int return_account_no();
     int return_branch_code();
     int get_balance();
};
class savings_account:public account{
    private:
        char name[50];int a_no,amt,brcode;
        public:
        savings_account();
        savings_account(char *, int, int, int);
        void debit();
        void credit();
        void update_balance(int);
         int return_account_no();
         char* get_name();
     int return_branch_code();
     int get_balance();
};
class current_account:public account{
    private:
        char name[50];int a_no,amt,brcode;
        public:
        current_account();
        current_account(char *, int, int, int);
        void debit();
        void credit();
        void update_balance(int);
         int return_account_no();
         char* get_name();
     int return_branch_code();
     int get_balance();
};

class branch{
    private:
        char city[25];
        int br_code;
        int ba_code;
    public:
        branch();
        branch(char [], int, int);
        void addaccount();
        int get_ba_code();
        int get_br_code();
        void set_branch(char *, int, int);
        char* get_br_city();
     
                void addloan();
     
};
class bank
{
     private:
     char bname[50],bcoun[50];int bank_code;
     public:
     bank();
     bank(char *,char *,int);
     void bankinfo();
     void addbranch();
     bank& getbank();
     branch& getbranch();
     char* get_bank_name();
     int return_bank_code();
     char* get_bank_country();
};

char* bank::get_bank_name(){
    return bname;
}
int bank::return_bank_code(){
        return bank_code;
}
char* bank::get_bank_country(){
    return bcoun;
}
bank::bank()
{
     ;
}
bank::bank(char *bn,char *bc,int c){
    for(int i=0;i<strlen(bn);i++)
           {
           bname[i] = bn[i];
           }
        for(int i=0;i<strlen(bc);i++)
           {
           bcoun[i] = bc[i];
           }
         bank_code = c;
       
     fstream file_obj;
    file_obj.open("bank.dat", ios::app|ios::binary);
    file_obj.write((char*)this, sizeof(*this));
    file_obj.close();
                  
}

void bank::addbranch()
{
     int a,c;char b[50];
     cout<<"Enter your branch code , city and bank code: ";
     cin>>a>>b>>c;
     branch br(b,a,c);
  
     fstream file_obj;
    file_obj.open("branch.dat", ios::app|ios::binary);
    file_obj.write((char*)&br, sizeof(br));
    file_obj.close();
 
}
void bank::bankinfo()
{
     int t;
     cout<<"Enter bank code: ";
     cin>>t;
            bank a;
                   fstream file;
            file.open("bank.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&a,sizeof(a));
            while(!file.eof()){
                if(t==a.return_bank_code()){
                      
                                                cout<<a.get_bank_name()<<" "<<a.get_bank_country()<<endl;
                        file.seekp(file.tellp()-sizeof(a));
                    file.write((char*)&a,sizeof(a));
                    break;
                }
                file.read((char*)&a,sizeof(a));
        }
        file.close();
}

  
branch::branch()
{
     ;
}

branch::branch(char ci[],int c1,int c2){
    for(int i=0;i<strlen(ci);i++)
           {
           city[i] = ci[i];
           }
        br_code = c1;
        ba_code = c2;
}

int branch::get_ba_code()
{
return ba_code;
}
int branch::get_br_code()
{
    return br_code;
}
char* branch::get_br_city(){
    return city;
}
void branch::addaccount()
{
     char na[50];int acno,type,amot,brcode;
     cout<<"Enter your name, type 1 for savings and 2 for current , account number, brcode and amount: ";
     cin>>na>>type>>acno>>brcode>>amot;
     account a;
     a = account(acno,brcode,amot);
     fstream file_obj;
    file_obj.open("acc.dat", ios::app|ios::binary);
    file_obj.write((char*)&a, sizeof(a));
    file_obj.close();
     if(type==1)
     {
     savings_account sa;
     sa = savings_account(na,acno,amot,brcode);
    fstream file_obj;
    file_obj.open("sav_acc.dat", ios::app|ios::binary);
    file_obj.write((char*)&sa, sizeof(sa));
    file_obj.close();
    }
    else if(type==2)
     {
     current_account ca;
     ca = current_account(na,acno,amot,brcode);
    fstream file_obj;
    file_obj.open("curr_acc.dat", ios::app|ios::binary);
    file_obj.write((char*)&ca, sizeof(ca));
    file_obj.close();
     }
}
void branch::addloan()
{
   int lno,brcode,amot;
   cout<<"Enter the lno, brcode, amt: ";
   cin>>lno>>brcode>>amot;
    loan l;
    l = loan(lno,amot,brcode);
    fstream file_obj;
    file_obj.open("loan.dat", ios::app|ios::binary);
    file_obj.write((char*)&l, sizeof(l));
    file_obj.close();
}

account::account(){
    ;
}
account::account(int acn,int b,int balance){
            ac_no=acn;
            bra_code=b;
            bal=balance;
        }
int account::return_account_no(){
    return ac_no;
}
int account::return_branch_code(){
        return bra_code;
}
int account::get_balance(){
    return bal;
}

void account::getaccinfo(){
        int acno,brc;
    cout<<"Enter the account number and branch code: ";
        cin>>acno>>brc;
        fstream file;
        account a;
                        file.open("acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
            file.read((char*)&a,sizeof(a));
            while(!file.eof()){
                if(acno==a.return_account_no()&&brc==a.return_branch_code()){
                        cout<<a.get_balance()<<endl;
                        break;
                }
                file.read((char*)&a,sizeof(a));
        }
                file.close();
}

savings_account::savings_account(){
    ;
}
savings_account::savings_account(char *c,int acn,int balance,int b){
                        for(int i=0;i<strlen(c);i++)
                        {
                         name[i]=c[i];
                        }
            a_no=acn;
                        brcode=b;
            amt=balance;
        }
int savings_account::return_account_no(){
    return a_no;
}
void savings_account::update_balance(int bala){
    amt=bala;
}
int savings_account::return_branch_code(){
        return brcode;
}
int savings_account::get_balance(){
    return amt;
}
char* savings_account::get_name(){
    return name;
}
void savings_account::credit(){
               int acno,brc,cre;
    cout<<"Enter the account number, branch code and amount you want to credit: ";
        cin>>acno>>brc>>cre;
        int flag=0;
               savings_account a;
                   fstream file;
            file.open("sav_acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&a,sizeof(a));
            while(!file.eof()){
                if(acno==a.return_account_no()&&brc==a.return_branch_code()){
                        a.update_balance(a.get_balance()+cre);
                        file.seekp(file.tellp()-sizeof(a));
                    file.write((char*)&a,sizeof(a));
                    flag=1;
                    break;
                }
                file.read((char*)&a,sizeof(a));
        }
        file.close();
        if(flag==0)
        {
            cout<<"Account not found"<<endl;
        }
               }
void savings_account::debit(){
               int acno,brc,de;
    cout<<"Enter the account number, branch code and amount you want to debit: ";
        cin>>acno>>brc>>de;
        int flag=0;
               savings_account a;
                   fstream file;
            file.open("sav_acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&a,sizeof(a));
            while(!file.eof()){
                if(acno==a.return_account_no()&&brc==a.return_branch_code()){
                        a.update_balance(a.get_balance()-de);
                        file.seekp(file.tellp()-sizeof(a));
                    file.write((char*)&a,sizeof(a));
                    flag=1;
                    break;
                }
                file.read((char*)&a,sizeof(a));
        }
        file.close();
        if(flag==0)
        {
            cout<<"Account not found";
        }
               }

current_account::current_account(){
    ;
}
current_account::current_account(char *c,int acn,int balance,int b){
                        for(int i=0;i<strlen(c);i++)
                        {
                         name[i]=c[i];
                        }
            a_no=acn;
            brcode=b;
            amt=balance;
        }
int current_account::return_account_no(){
    return a_no;
}
int current_account::return_branch_code(){
        return brcode;
}

void current_account::update_balance(int bala){
    amt=bala;
}
int current_account::get_balance(){
    return amt;
}
char* current_account::get_name(){
    return name;
}
void current_account::credit(){
               int acno,brc,cre;
    cout<<"Enter the account number, branch code and you want to credit: ";
        cin>>acno>>brc>>cre;
        int flag=0;
               current_account a;
                   fstream file;
            file.open("curr_acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&a,sizeof(a));
            while(!file.eof()){
                if(acno==a.return_account_no()&&brc==a.return_branch_code()){
                        a.update_balance(a.get_balance()+cre);
                        file.seekp(file.tellp()-sizeof(a));
                    file.write((char*)&a,sizeof(a));
                    flag=1;
                    break;
                }
                file.read((char*)&a,sizeof(a));
        }
        file.close();
        if(flag==0)
        {
            cout<<"Account not found";
        }
               }
void current_account::debit(){
               int acno,brc,de;
    cout<<"Enter the account number, branch code and you want to debit: ";
        cin>>acno>>brc>>de;
        int flag=0;
               current_account a;
                   fstream file;
            file.open("curr_acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&a,sizeof(a));
            while(!file.eof()){
                if(acno==a.return_account_no()&&brc==a.return_branch_code()){
                        a.update_balance(a.get_balance()-de);
                        file.seekp(file.tellp()-sizeof(a));
                    file.write((char*)&a,sizeof(a));
                    flag=1;
                    break;
                }
                file.read((char*)&a,sizeof(a));
        }
        file.close();
        if(flag==0)
        {
            cout<<"Account not found";
        }
               }


int main()
{
    while(1)
    {
    int op;
   cout<<"For corporate section press 1, for public section press 2 and to exit 3:";
   cin>>op;
   if(op==1)
   {
         cout<<"If you want to add bank press 1:,to add branch press 2:,to get bank details press 3:,to get branch details press 4: ";
         int o;
         cin>>o;
         if(o==1)
         {
             char bn[50],bc[50];int k;
             cout<<"Enter the bank name,country and code: ";
             cin>>bn>>bc>>k;
         bank b(bn,bc,k);
      }
      else if(o==2)
      {
          bank h;
          int bc;
          cout<<"Enter bank code:";
          cin>>bc;int s=0;
          fstream file;
            file.open("bank.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&h,sizeof(h));
            while(!file.eof()){
                if(bc==h.return_bank_code()){
                        s=1;
                        h.addbranch();
                    break;
                }
                file.read((char*)&h,sizeof(h));
        }
        file.close();
        if(s==0) cout<<"bank not found";
      }
      else if(o==3)
      {
          int l;
          cout<<"Enter bank code: ";
          cin>>l;
          int flag = 0;
              bank h;
              fstream file;
            file.open("bank.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&h,sizeof(h));
            while(!file.eof()){
                if(l==h.return_bank_code()){
                        flag=1;
                        cout<<h.get_bank_name()<<" "<<h.get_bank_country()<<endl;
                    break;
                }
                file.read((char*)&h,sizeof(h));
        }
        file.close();
        if(flag==0) cout<<"bank not found";
      }
      else if(o==4)
      {
             int l;
          cout<<"Enter branch code: ";
          cin>>l;
          int flag = 0;
              branch h;
              fstream file;
            file.open("branch.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&h,sizeof(h));
            while(!file.eof()){
                if(l==h.get_br_code()){
                        flag=1;
                        cout<<h.get_br_city()<<endl;
                    break;
                }
                file.read((char*)&h,sizeof(h));
        }
        file.close();
        if(flag==0) cout<<"branch not found";
      }
   }
   else if(op==2)
    {
          cout<<"If you want to enter account: press 1: ,to take loan press 2: ,for transactions press 3: ,to see account details press 4:,for loan details press 5:,for prepayment of loan press 6,to know emi press 7:  ";
          int o;
             cin>>o;
          if(o==1)
             {
                    branch h;
                    cout<<"Enter branch code:";
                 int brc;
                 cin>>brc;int s=0;
              fstream file;
            file.open("branch.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&h,sizeof(h));
            while(!file.eof()){
                if(brc==h.get_br_code()){
                        s=1;
                        h.addaccount();
                    break;
                }
                file.read((char*)&h,sizeof(h));
        }
        file.close();
        if(s==0) cout<<"branch not found";
                 
          }
          else if(o==2)
          {
               branch h;
               cout<<"Enter branch code:";
                 int brc;
                 cin>>brc;int s=0;
              fstream file;
            file.open("branch.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&h,sizeof(h));
            while(!file.eof()){
                if(brc==h.get_br_code()){
                        s=1;
                        h.addloan();
                    break;
                }
                file.read((char*)&h,sizeof(h));
        }
        file.close();
        if(s==0) cout<<"branch not found";
                
          }
          else if(o==3)
          {
                 int ch;
                 cout<<"For credit press 1: , for debit press 2:";
                 cin>>ch;
                 if(ch==1)
                 {
                       int cho;
                       cout<<"For savings account press 1: and for current account press 2:";
                       cin>>cho;
                       if(cho==1)
                       {
                            savings_account sa;
                            sa.credit();
                  }
                  else if(cho==2)
                  {
                        current_account ca;
                            ca.credit();
                  }
               }
               else if(ch==2)
               {
                       int cho;
                       cout<<"For savings account press 1: and for current account press 2:";
                       cin>>cho;
                       if(cho==1)
                       {
                            savings_account sa;
                            sa.debit();
                  }
                  else if(cho==2)
                  {
                        current_account ca;
                            ca.debit();
                  }
               }
          }
          else if(o==4)
          {
                  int f,d,flag=0,z;
                  cout<<"Enter your branch code and account number and type 1 for savings and 2 for current: ";
                  cin>>f>>d>>z;
                  if(z==1)
                  {
                 savings_account q;
                 fstream file;
            file.open("sav_acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&q,sizeof(q));
            while(!file.eof()){
                if(f==q.return_branch_code()&&d==q.return_account_no()){
                        flag=1;
                        cout<<q.get_name()<<" "<<q.get_balance()<<endl;
                    break;
                }
                file.read((char*)&q,sizeof(q));
        }
        file.close();
        if(flag==0) cout<<"account not found";
                 }
                 else if(z==2)
                 {
                     current_account q;
                 fstream file;
            file.open("curr_acc.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&q,sizeof(q));
            while(!file.eof()){
                if(f==q.return_branch_code()&&d==q.return_account_no()){
                        flag=1;
                        cout<<q.get_name()<<" "<<q.get_balance()<<endl;
                    break;
                }
                file.read((char*)&q,sizeof(q));
        }
        file.close();
        if(flag==0) cout<<"account not found";
                }
          }
          else if(o==5)
          {
                int f,d,flag=0;
                cout<<"Enter your branch code and loan number: ";
                cin>>f>>d;
                 loan q;
                 fstream file;
            file.open("loan.dat",ios::in|ios::out|ios::ate|ios::binary);
            file.clear();
            file.seekg(0);
                        file.read((char*)&q,sizeof(q));
            while(!file.eof()){
                if(f==q.get_bcode()&&d==q.get_lno()){
                        flag=1;
                        cout<<q.get_amount()<<endl;
                    break;
                }
                file.read((char*)&q,sizeof(q));
        }
        file.close();
        if(flag==0) cout<<"loan not found";
          }
          else if(o==6)
          {
              loan j;
              j.prepayment();
          }
          else if(o==7)
          {
               loan j;
               j.getemi();
          }
    }
  
    else if(op==3)
    {
        break;
    }
    }
return 0;
}
