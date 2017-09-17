#include<cstdio>

int validateInt(){
	int ans = 0;
	while(1){
	  try{
	  	char p[20];
	  	cin>>p;
	  	int i;
	  	for(i=0;i<strlen(p);++i){
	  		if(isdigit(p[i]) != 1){
	  			throw "\n\n\t\t\t\t\t\tInvalid\n";
	  		}
	  		else{
	  			ans = ans + ((int)(p[i]-'0'))*pow(10,strlen(p)-i-1);
	  		}
	  	}
	  }
	  catch(const char *msg){
	  	cout<<msg;
		cout<<"\n\n\t\t\t\t\t\t\tEnter again : ";
	  	continue;
	  }
	  break;
  	}
  	return ans;
}


class libClass:public PersonClass
{
  char usrname[15];
  char pass[15];
public:
  libClass(){}
  libClass(char* name,char* email,char* usrname, char* pass):PersonClass(name,email)
  {
    strcpy(this->usrname,usrname);
    strcpy(this->pass,pass);
    //cout<<getname()<<" "<<getemail()<<" "<<usrname<<pass<<endl;
  }
  void LibrarianSpace();
  friend void LibrarianAccessControl();
  void AddBooks();
  void ViewAllBooks();
  void AddCustomer();
  void ViewAllCustomers();
  void RemoveCustomer();
  void copyCustomer(int,int);
  void copyBook(int,int);
  void RemoveBook();
};

libClass* librarian_ptr = new libClass();

void libClass::copyCustomer(int a1,int a2){
  *customer_ptr[a1] = *customer_ptr[a2];
}
void libClass::copyBook(int a1,int a2){
  *book_ptr[a1] = *book_ptr[a2];
}
void libClass::LibrarianSpace()
{
  while(1){
	  cout<<"\n\n\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 to add books to library\n\n\t\t\t\t\t\t2 to add customers\n\n\t\t\t\t\t\t3 to view all book details";
	  cout<<"\n\n\t\t\t\t\t\t4 to remove customer\n\n\t\t\t\t\t\t5 to remove book\n\n\t\t\t\t\t\t6 to View customers\n\n\t\t\t\t\t\t7 to add Front desk staff\n\n\t\t\t\t\t\t8 to exit:";
	  char i;
	  cin>>i;

	  switch(i)
	  {
	    case '1': AddBooks();
		    break;
	    case '2': AddCustomer();
		    break;
	    case '3': ViewAllBooks();
		    break;
	    case '6': ViewAllCustomers();
		    break;
	    case '4': RemoveCustomer();
		    break;
	    case '5': RemoveBook();
		    break;
	    case '7': char name[10];
              char usrname[10];
              char pass[10];
              char email[10];

              cout<<"\n\n\t\t\t\t\t\tEnter name(String):";
              cin>>name;
              cout<<"\n\t\t\t\t\t\tEnter email-ID(String):";
              while(1){
            		cin>>email;
            		if(isValidEmailAddress(email)){
            			break;
            		}
               cout<<"\n\t\t\t\t\t\tEnter Valid email-ID:";
              }
              cout<<"\n\t\t\t\t\t\tChoose username:";
              cin>>usrname;
              cout<<"\n\t\t\t\t\t\tEnter a password:";
              cin>>pass;

              fd[FDcount]=new FDClass(name,email,usrname,pass);
              FDcount++;

              writeFD();

              break;
			case '8':return;
	    default:cout<<"\n\n\t\t\t\t\t\tInvalid input\n";
	  }
  }
}

void libClass::AddBooks()
{
  char name[25];
  char author[25];
  char ISBN[25];
  float price;
  int NoCopies;

  cout<<"\n\n\t\t\t\t\t\tEnter title:";
  cin.getline(name,25);// NOT ACCEPTING HENCE TWO STATEMENTS
  cin.getline(name,25);
  cout<<"\n\n\t\t\t\t\t\tEnter author:";
  cin.getline(author,25);
  cout<<"\n\n\t\t\t\t\t\tEnter ISBN:";
  cin.getline(ISBN,25);
  cout<<"\n\n\t\t\t\t\t\tEnter price:";
  price = validateInt();
  cout<<"\n\n\t\t\t\t\t\tEnter number of copies:";
  NoCopies = validateInt();

  book_ptr[Bookct]=new book(name,author,ISBN,price,NoCopies);
  Bookct++;
  writeRecordsBooks();
}

void libClass::ViewAllBooks()
{
  for(int i=0;i<Bookct;i++)
  book_ptr[i]->PrintBookDetails();
}

void libClass::AddCustomer()
{
  char name[10];
  char mob[10];
  char email[30];

  cout<<"\n\n\t\t\t\t\t\tEnter you name(String):";
  cin.getline(name,30);
  cin.getline(name,30);
  cout<<"\n\t\t\t\t\t\tEnter your email-ID(String):";
  while(1){
		cin>>email;
		if(isValidEmailAddress(email)){
			break;
		}
		cout<<"\n\t\t\t\t\t\tEnter Valid email-ID:";
  }
	cout<<"\n\t\t\t\t\t\tEnter your mobile no:";
  cin>>mob;

  customer_ptr[Customerct]=new customerClass(name,email,mob,previous+1);
  cout<<"\n\n\t\t\t\t\t\tCustomer ID generated : "<<previous+1<<"\n";
  Customerct++;
  previous++;
  writeRecords();
}

void libClass::ViewAllCustomers(){
  int i;
  for(i=0;i<Customerct;++i){
    customer_ptr[i]->PrintCustomerDetails();
  }
}

void libClass::RemoveCustomer(){
  int key,i;
  cout<<"\n\n\t\t\t\t\t\tEnter id of customer to remove : ";
  cin>>key;
  int found = 0,j;
  for(i=0;i<Customerct;++i){
    if(customer_ptr[i]->getid() == key){
        cout<<"\n\n\t\t\t\t\t\tFound and Deleted\n";
        found = 1;
        for(j=i+1;j<Customerct;++j){
          copyCustomer(j-1,j);
        }
        --Customerct;
    }
  }
  writeRecords();
}
void libClass::RemoveBook(){
  char key[25];
  int i;
  cout<<"\n\n\t\t\t\t\t\tEnter ISBN of book to remove : ";
  cin>>key;
  int found = 0,j;
  for(i=0;i<Bookct;++i){
    if(strcmp(book_ptr[i]->getISBN(),key) == 0){
        cout<<"\n\n\t\t\t\t\t\tFound and Deleted\n";
        found = 1;
        for(j=i+1;j<Bookct;++j){
          copyBook(j-1,j);
        }
        --Bookct;
    }
  }
  writeRecordsBooks();
}
