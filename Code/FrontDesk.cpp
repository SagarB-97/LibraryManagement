#include <ctime>

class FDClass:public PersonClass
{
  char usrname[15];
  char pass[15];
public:
  FDClass()
  {}
  FDClass(char* name,char* email,char* usrname, char* pass):PersonClass(name,email)
  {
    strcpy(this->usrname,usrname);
    strcpy(this->pass,pass);
  }
  void FrontDeskSpace();
  customerClass* customerCheck();
  void borrowBooks();
  void listBooks();
  void renewBook();
  void returnBook();
  friend void FrontDeskAccessControl();
};
customerClass *t;

FDClass* fd[10];
int FDcount=0;

void writeFD(){
  int i;
  ofstream os("frontdesk.dat",ios::out|ios::trunc|ios::binary);//Open file in binary mode.
 	for(i=0;i<FDcount;++i)
    os.write(reinterpret_cast<char*>(fd[i]), sizeof(FDClass));
}
void writeRecords(){
  int i;
  ofstream os("customer.dat",ios::out|ios::trunc|ios::binary);//Open file in binary mode.
 	for(i=0;i<Customerct;++i)
    os.write(reinterpret_cast<char*>(customer_ptr[i]), sizeof(customerClass));
}

void writeRecordsBooks(){
  int i;
  ofstream os("book.dat",ios::out|ios::trunc|ios::binary);//Open file in binary mode.
 	for(i=0;i<Bookct;++i)
    os.write(reinterpret_cast<char*>(book_ptr[i]), sizeof(book));
}

void FDClass::FrontDeskSpace()
{
    while(1){
        cout<<"\n\n\t\t\t\t\t\t...Front Desk Space...\n\n";
        cout<<"\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1. Customer Check\n\n\t\t\t\t\t\t"
            <<"2. Borrow Books\n\n\t\t\t\t\t\t3. List of Borrowed Books"
            <<"\n\n\t\t\t\t\t\t4. Renew Book\n\n\t\t\t\t\t\t5. Return Book\n\n\t\t\t\t\t\t"
            <<"6. Exit\n\n\t\t\t\t\t\tEnter Choice : ";
        char i;
        cin>>i;

        switch(i)
        {
          case '1': cout<<"\n\t\t\t\t\t\tChecking Customer existence";
                  t = customerCheck();
                  if(t==NULL)
                    cout<<"\n\t\t\t\t\t\tThe Customer doesn't exist. Please Sign Up";
                  else{
                        cout<<"\n\t\t\t\t\t\tThe Customer exists.";
                        t->PrintCustomerDetails();
                    }
                  break;
          case '2': borrowBooks();
                  break;
          case '3': listBooks();
                  break;
          case '4': renewBook();
                  break;
          case '5': returnBook();
                  break;
          case '6':return;
          default:cout<<"\n\t\t\t\t\t\tInvalid option!\n";
        }
    }
}

void FDClass::borrowBooks()
{
    t = customerCheck();
    if(t!=NULL){
        cout<<"\n\t\t\t\t\t\tSearch by title-(0) or author-(1) ?\n\n\t\t\t\t\t\tEnter choice 0 or 1 : ";
    	char choice;
    	cin>>choice;
    	int i;
    	if(choice == '0'){
    		char tempName[25];
    		cout<<"\n\n\t\t\t\t\t\tEnter name of book to search : ";
    		cin>>tempName;
    		for(i=0;i<Bookct;++i){
    			if(strcmp(book_ptr[i]->getname(),tempName)==0){
                    if(book_ptr[i]->NoCopies > 0){
                        (book_ptr[i]->NoCopies)--;
        				book_ptr[i]->PrintBookDetails();
                        time_t tim = time(0);
                        struct tm * now = localtime( & tim );
                        date curDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                        t->borroweBooks[t->bookCount] = *book_ptr[i];
                        t->Issue[t->bookCount] = curDate;

                        cout<<"\n\t\t\t\t\t\tEnter Return Date :";
                        date RDate;
                        int errorFlag = 1;
                        while(errorFlag == 1){
                            try{
                                cin>>RDate;
                                errorFlag = 0;
                            }
                            catch(const char* msg){
                                cout<<"\n\t\t\t\t\t\tError : "<<msg<<"\n\n";
                            }
                            if(errorFlag == 0){
                                int diff = RDate - t->Issue[t->bookCount];
                                if(diff<0){
                                    cout<<"\n\t\t\t\t\t\tError : Return date before issue date\n\n";
                                    errorFlag = 1;
                                }
                            }
                        }
                        t->Return[t->bookCount] = RDate;
                        (t->bookCount)++;
        				break;
    			    }
                    else{
                        cout<<"\n\t\t\t\t\t\tBook Out of Stock\n";
                        break;
                    }
                }
    		}
    		if(i==Bookct){
                cout<<"\n\n\t\t\t\t\t\tBook not Found\n";
            }
    	}
        else if(choice == '1'){
    		char tempName[25];
    		cout<<"\n\n\t\t\t\t\t\tEnter author of book to search : ";
    		cin.getline(tempName,30);
    		for(i=0;i<Bookct;++i){
    			if(strcmp(book_ptr[i]->getauthor(),tempName)==0){
                    if(book_ptr[i]->NoCopies > 0){
                        (book_ptr[i]->NoCopies)--;
        				book_ptr[i]->PrintBookDetails();
                        time_t tim = time(0);
                        struct tm * now = localtime( & tim );
                        date curDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                        t->borroweBooks[t->bookCount] = *book_ptr[i];
                        t->Issue[t->bookCount] = curDate;

                        cout<<"\n\t\t\t\t\t\tEnter Return Date :";
                        date RDate;
                        int errorFlag = 1;
                        while(errorFlag == 1){
                            try{
                                cin>>RDate;
                                errorFlag = 0;
                            }
                            catch(const char* msg){
                                cout<<"\n\t\t\t\t\t\tError : "<<msg<<"\n\n";
                            }
                            if(errorFlag == 0){
                                int diff = RDate - t->Issue[t->bookCount];
                                if(diff<0){
                                    cout<<"\n\t\t\t\t\t\tError : Return date before issue date\n\n";
                                    errorFlag = 1;
                                }
                            }
                        }
                        t->Return[t->bookCount] = RDate;
                        (t->bookCount)++;
        				break;
    			    }
                    else{
                        cout<<"\n\t\t\t\t\t\tBook Out of Stock\n";
                        break;
                    }
                }
    		}
    		if(i==Bookct)
                cout<<"\n\n\t\t\t\t\t\tBook not Found\n";
    	}
        else
            cout<<"\n\n\t\t\t\t\t\t\nInvaild choice\n";
    }
    else{
        cout<<"\n\t\t\t\t\t\tInvalid Customer ID";
    }
    writeRecords();
    writeRecordsBooks();
}

void FDClass::renewBook()
{
    t = customerCheck();
    if(t!=NULL){
        cout<<"\n\t\t\t\t\t\tSearch by title-(0) or author-(1) ?\n\n\t\t\t\t\t\tEnter choice 0 or 1 : ";
        char choice;
        cin>>choice;
        int i;
        if(choice == '0'){
            char tempName[25];
            cout<<"\n\n\t\t\t\t\t\tEnter name of book to search : ";
            cin.getline(tempName,30);
            for(i=0;i<(t->bookCount);++i){
                if(strcmp(t->borroweBooks[i].getname(),tempName)==0){
                    cout<<"\n\t\t\t\t\t\tEnter Return Date :";
                    date newRDate;
                    int errorFlag = 1;
                    while(errorFlag == 1){
                        try{
                            cin>>newRDate;
                            errorFlag = 0;
                        }
                        catch(const char* msg){
                            cout<<"\n\t\t\t\t\t\tError : "<<msg<<"\n\n";
                        }
                        if(errorFlag == 0){
                            int diff = newRDate - t->Issue[t->bookCount];
                            if(diff<0){
                                cout<<"\n\t\t\t\t\t\tError : Return date before issue date\n\n";
                                errorFlag = 1;
                            }
                            diff = newRDate - t->Return[t->bookCount];
                            if(diff<0){
                                cout<<"\n\t\t\t\t\t\tError : New Return date before expected return date\n\n";
                                errorFlag = 1;
                            }
                        }
                    }
                    t->Return[i] = newRDate;
                    break;
                }
            }
            if(i==Bookct)
                cout<<"\n\n\t\t\t\t\t\tBook not Found\n";
        }
        else if(choice == 1){
            char tempauthor[25];
            cout<<"\n\n\t\t\t\t\t\tEnter author of book to search : ";
            cin.getline(tempauthor,24);
            int found = 0;
            for(i=0;i<(t->bookCount);++i){
                if(strcmp(t->borroweBooks[i].getauthor(),tempauthor)==0){
                    cout<<"\n\t\t\t\t\t\tEnter Return Date :";
                    date newRDate;
                    int errorFlag = 1;
                    while(errorFlag == 1){
                        try{
                            cin>>newRDate;
                            errorFlag = 0;
                        }
                        catch(const char* msg){
                            cout<<"\n\t\t\t\t\t\tError : "<<msg<<"\n\n";
                        }
                        if(errorFlag == 0){
                            int diff = newRDate - t->Issue[t->bookCount];
                            if(diff<0){
                                cout<<"\n\t\t\t\t\t\tError : Return date before issue date\n\n";
                                errorFlag = 1;
                            }
                            diff = newRDate - t->Return[t->bookCount];
                            if(diff<0){
                                cout<<"\n\t\t\t\t\t\tError : New Return date before expected return date\n\n";
                                errorFlag = 1;
                            }
                        }
                    }
                    t->Return[i] = newRDate;
                    break;
                }
            }
            if(found == 0)
                cout<<"\n\t\t\t\t\t\tBook not Found\n";
        }
        else cout<<"\n\n\t\t\t\t\t\t\nInvaild choice\n";
    }
    else{
        cout<<"\n\n\t\t\t\t\t\t\nInvalid Customer ID\n";
    }
    writeRecords();
}

void FDClass::returnBook()
{
    t = customerCheck();
    if(t!=NULL){
        cout<<"\n\t\t\t\t\t\tSearch by title-(0) or author-(1) ?\n\n\t\t\t\t\t\tEnter choice 0 or 1 : ";
        char choice;
        cin>>choice;
        int i;
        if(choice == '0'){
            char tempName[25];
            cout<<"\n\n\t\t\t\t\t\tEnter name of book to search : ";
            cin.getline(tempName,25);
            for(i=0;i<(t->bookCount);++i){
                if(strcmp(t->borroweBooks[i].getname(),tempName)==0){
                    cout<<"\n\n\t\t\t\t\t\tExpected Return date : "<<t->Return[i]<<"\n";

                    cout<<"\n\t\t\t\t\t\tEnter Return Date :";
                    date actualRDate;
                    int errorFlag = 1;
                    while(errorFlag == 1){
                        try{
                            cin>>actualRDate;
                            errorFlag = 0;
                        }
                        catch(const char* msg){
                            cout<<"\n\t\t\t\t\t\tError : "<<msg<<"\n\n";
                        }
                        if(errorFlag == 0){
                            int diff = actualRDate - t->Issue[t->bookCount];
                            if(diff<0){
                                cout<<"\n\t\t\t\t\t\tError : Return date before issue date\n\n";
                                errorFlag = 1;
                            }
                        }
                    }
                    int daysLate = actualRDate - t->Return[i];
                    int fine = 0;
                    if(daysLate<7)
                        fine=0;
                    else if(daysLate<=15)
                        fine = (daysLate-7)*1;
                    else if(daysLate<=30)
                        fine = (daysLate-7) + (daysLate-15)*2;
                    else
                        fine = (daysLate-7) + (daysLate-15)*2 + (daysLate-30)*5;

                    cout<<"\n\n\t\t\t\t\t\tDays Late = "<<daysLate<<"\n";
                    cout<<"\n\t\t\t\t\t\tFine to be Collected = Rs. "<<fine<<"\n";

                    char *tempName = t->borroweBooks[i].getname();
            		for(i=0;i<Bookct;++i){
            			if(strcmp(book_ptr[i]->getname(),tempName)==0){
            				(book_ptr[i]->NoCopies)++;
            				break;
            			}
                    }

                    int j;
                    for(j=i;j<(t->bookCount);j++){
                        t->borroweBooks[j] = t->borroweBooks[j+1];
                        t->Issue[j] = t->Issue[j+1];
                        t->Return[j] = t->Return[j+1];
                    }
                    (t->bookCount)--;
                    break;
                }
            }
            if(i==Bookct)
                cout<<"\n\n\t\t\t\t\t\tBook not Found\n";
        }
        else if(choice=='1'){
            char tempName[25];
            cout<<"\n\n\t\t\t\t\t\tEnter name of book to search : ";
            cin.getline(tempName,25);
            for(i=0;i<(t->bookCount);++i){
                if(strcmp(t->borroweBooks[i].getauthor(),tempName)==0){
                    cout<<"\n\n\t\t\t\t\t\tExpected Return date : "<<t->Return[i]<<"\n";
                    date actualRDate;
                    int errorFlag = 1;
                    while(errorFlag == 1){
                        try{
                            cin>>actualRDate;
                            errorFlag = 0;
                        }
                        catch(const char* msg){
                            cout<<"\n\t\t\t\t\t\tError : "<<msg<<"\n\n";
                        }
                        if(errorFlag == 0){
                            int diff = actualRDate - t->Issue[t->bookCount];
                            if(diff<0){
                                cout<<"\n\t\t\t\t\t\tError : Return date before issue date\n\n";
                                errorFlag = 1;
                            }
                        }
                    }
                    int daysLate = actualRDate - t->Return[i];
                    int fine = 0;
                    if(daysLate<7)
                        fine=0;
                    else if(daysLate<=15)
                        fine = (daysLate-7)*1;
                    else if(daysLate<=30)
                        fine = (daysLate-7) + (daysLate-15)*2;
                    else
                        fine = (daysLate-7) + (daysLate-15)*2 + (daysLate-30)*5;

                    cout<<"\n\n\t\t\t\t\t\tDays Late = "<<daysLate<<"\n";
                    cout<<"\n\t\t\t\t\t\tFine to be Collected = Rs. "<<fine<<"\n";

                    int j;
                    for(j=i;j<(t->bookCount);j++){
                        t->borroweBooks[j] = t->borroweBooks[j+1];
                        t->Issue[j] = t->Issue[j+1];
                        t->Return[j] = t->Return[j+1];
                    }
                    (t->bookCount)--;
                    break;
                }
            }
            if(i==Bookct)
                cout<<"\n\n\t\t\t\t\t\tBook not Found\n";
        }
    }
    else
        cout<<"\n\n\t\t\t\t\t\t\nInvalid Customer ID\n";

    writeRecords();
    writeRecordsBooks();
}

void FDClass::listBooks()
{
    int i;
    t = customerCheck();
    if(t!=NULL){
        cout<<"\n\n\t\t\t\t\t\tBorrowed Books are : \n";
        for(i=0; i<(t->bookCount); i++){
            t->borroweBooks[i].PrintBookDetails();
            cout<<"\n\t\t\t\t\t\tIssue Date  : "<<t->Issue[i]<<"\n";
            cout<<"\n\t\t\t\t\t\tReturn Date : "<<t->Return[i]<<"\n";
        }
    }
    else{
        cout<<"\n\n\t\t\t\t\t\tInvalid Customer ID";
    }
}
customerClass* FDClass::customerCheck()
{
    cout<<"\n\t\t\t\t\t\tEnter customer ID(int):";
    int i,tempID;
    char a[10];
    cin>>a;
    tempID = 0;
    int n = strlen(a);
    try{
        for(i=0;a[i]!='\0';++i){
        if(isdigit(a[i]) != 1){
            throw "\n\t\t\t\t\t\tinvalid input\n";
        }
        else{
            tempID = tempID + ((int)(a[i]-'0'))*pow(10,n-i-1);
        }
	}
        for(i=0;i<Customerct;i++)
        {
          if(customer_ptr[i]->getid()==tempID)
          {
            return customer_ptr[i];
          }
        }
        if(i==Customerct)
            return NULL;
    }
    catch(const char *msg){
        cout<<msg;
    }
}
