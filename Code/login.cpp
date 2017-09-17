void LibrarianAccessControl();
void CustomerSpace();
void FrontDeskAccessControl();
void LibrarianSignup();
void SearchBooks();
char pass[20];
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
char * enterPwd(){
   pass[0] = '\0';
   char ch;
   cout << "\n\n\t\t\t\t\t\tEnter password(String) : ";
   ch = getch();
   ch = getch();
   int count = 0;
   while(ch != '\n'){//character 13 is enter
      pass[count] = ch;
      cout << '*';
      ch = getch();
      count++;
   }
   return pass;
}


void LibrarianAccessControl()
{
  while(1){
	  cout<<"\n\n\t\t\t\t\t\t...LibrarianLoginPage...\n\n";
	  cout<<"\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 to login\n\n\t\t\t\t\t\t2 to exit:";
	  char i;
	  cin>>i;

	  switch(i)
	  {
	    case '1': cout<<"\n\n\t\t\t\t\t\tEnter your username(String):";
		    char tempName[20];
		    cin>>tempName;

		    if(strcmp(tempName,librarian_ptr->usrname)==0)
		    {

		      char tempPass[20];
		      strcpy(tempPass,enterPwd());

		      if(strcmp(librarian_ptr->pass,tempPass)==0)
		      {
		        cout<<"\n\n\t\t\t\t\t\t....Access Granted....\n\n";
		        librarian_ptr->LibrarianSpace();
		      }
		      else
		      cout<<"\n\n\t\t\t\t\t\tWrong password";
		    }
		    else
		    cout<<"\n\n\t\t\t\t\t\tWrong username";
		    break;
	    case '2':return;
	    default:cout<<"\n\n\t\t\t\t\t\tInvaild choice\n";
	  }
  }

}

void FrontDeskAccessControl()
{
  while(1){
  cout<<"\n\n\t\t\t\t\t\t...FrontDeskLoginPage...\n\n";
  cout<<"\n\t\t\t\t\t\tEnter\n\n\t\t\t\t\t\t1 to login\n\n\t\t\t\t\t\t2 to exit:";
  char i;
  cin>>i;

  switch(i)
  {
    case '1': cout<<"\n\n\t\t\t\t\t\tEnter your username(String):";
            char tempName[10];
            cin>>tempName;
            int i;
            for(i=0;i<FDcount;i++)
            {
              if(strcmp(tempName,fd[i]->usrname)==0)
              {

                char tempPass[20];
		              strcpy(tempPass,enterPwd());
                if(strcmp(tempPass,fd[i]->pass)==0)
                {
                  cout<<"\n\n\t\t\t\t\t\tAccess granted\n";
                  fd[i]->FrontDeskSpace();
                  break;
                }
                else
                {
                  cout<<"\n\n\t\t\t\t\t\tWrong password!\n";
                  break;
                }
              }
            }

            if(i==FDcount)
            cout<<"\n\n\t\t\t\t\t\tInvalid username!\n";
            break;

     case '2':return;
    default: cout<<"\n\n\t\t\t\t\t\tInvaild choice\n";
  }
  }
}

void CustomerSpace()
{
  cout<<"\n\t\t\t\t\t\tEnter your customer ID(int):";
  int i,tempID;
  char a[50];
  try{
	  tempID = 0;
	  cin>>a;
	  int n = strlen(a);
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
	      customer_ptr[i]->SearchBooks();
	      break;
	    }
	  }
	  if(i==Customerct)
	  cout<<"\n\t\t\t\t\t\tGo to Front Desk to register yourself\n";
  }
  catch(const char *msg){
  	cout<<msg;
	return;
  }
}

void LibrarianSignup()
{
  char name[10];
  char usrname[10];
  char pass[10];
  char email[30];
  //
  cout<<"\n\t\t\t\t\t\tEnter your name:";
  cin.getline(name,25);
  cout<<"\n\t\t\t\t\t\tEnter your email-ID:";
  while(1){
		cin>>email;
		if(isValidEmailAddress(email)){
			break;
	  }
    cout<<"\n\t\t\t\t\t\tEnter Valid email-ID:";
  }
  cout<<"\n\t\t\t\t\t\tChoose a username:";
  cin>>usrname;
  cout<<"\n\t\t\t\t\t\tChoose a password:";
  cin>>pass;
  librarian_ptr=new libClass((char *)name,(char *)email,(char *)usrname,(char *)pass);
  int i;
  ofstream os("Librarian.dat",ios::out|ios::trunc|ios::binary);//Open file in binary mode.
    os.write(reinterpret_cast<char*>(librarian_ptr), sizeof(libClass));
}
