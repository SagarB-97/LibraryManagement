class book
{
  char name[25];
  char author[25];
  char ISBN[10];
  int NoCopies;
  float price;
public:
  book(char* name, char* author, char* ISBN, float price,int NoCopies)
  {
    // cout<<"Reached constructor\n";
    strcpy(this->name,name);
    strcpy(this->author,author);
    strcpy(this->ISBN,ISBN);
    this->price=price;
    this->NoCopies=NoCopies;
  }
  book(){}
  void PrintBookDetails();
  char* getname() {
  	return name;
  }
  char* getauthor(){
	return author;
  }
  char* getISBN(){
  	return ISBN;
  }

  friend class FDClass;
};

book* book_ptr[20];
int Bookct=0;

void book::PrintBookDetails()
{
    // cout<<name<<endl<<author<<endl<<price<<endl<<ISBN<<endl<<NoCopies<<endl<<Issue<<endl<<Return<<"\n\n";
    cout<<"\n\n\t\t\t\t\t\t******************************\n";
    cout<<"\n\t\t\t\t\t\tName:"<<name<<endl;
    cout<<"\n\t\t\t\t\t\tAuthor:"<<author<<endl;
    cout<<"\n\t\t\t\t\t\tPrice:"<<price<<endl;
    cout<<"\n\t\t\t\t\t\tISBN:"<<ISBN<<endl;
    cout<<"\n\t\t\t\t\t\tTotal copies:"<<NoCopies<<endl;
    cout<<"\n";
}
