#include<iostream>
#include<iomanip>

using namespace std;

char const *mainMenu[] = {

	"add a book in the library",
	"Borrow a Book",
	"Return a Book",
	"view a book",
	"view all Books",
	"Add a User in the Library",
	"View a User",
	"view all users",
	"Exit"};

//code for exit
const int EXIT_CODE = 9 ;

//total books in library 
const int BOOKS_LIMIT = 5;

//BOOKS POSITION IN LIBRARY
int currentBooksPosition = -1;


//code for book id
int bookId[BOOKS_LIMIT] ;

//code for book name 
char bookName[BOOKS_LIMIT][50] ;


//code for author name 
char authorName[BOOKS_LIMIT][50] ;

// code for book types
int bookTypes[BOOKS_LIMIT];

// code for amounts of book
double bookAmounts[BOOKS_LIMIT] ;

// available books
char const *availableBooks[] = {  " Programming Fundamental " , " information Technology " , " Calculus and Analytical Geometry" , "  Functional English " , "basic electronics "} ;

// total user in library
const int USER_LIMIT = 5;

//user POSITION IN LIBRARY
int currentUserPosition = -1;

//code for user id
int userId[USER_LIMIT] ;

//take first name of user
char firstName[USER_LIMIT][50];

//take last name of user
char lastName[USER_LIMIT][50];

// code for book types
int userTypes[USER_LIMIT];

// code for amounts of book
double userAmounts[USER_LIMIT] ;




// ************************************************************
// Function declarations
// ************************************************************

//CODE FOR CLEAR SCREEN
void clearScreen(void);

//CODE for wait for user to press enter key
void waitForUser(void);




void line(char  , int=80);


//show main menu
void showMainMenu(void);

//get main menu option from user
int getMainMenuOption(void);

// add new book 
void addbook(void);

// borrow book 
void borrowBook(void);

// borrow book 
void returnBook(void);

// borrow book 
void viewBook(void);

// borrow book 
void viewAllBooks(void);

// borrow book 
void addUser(void);


// borrow book 
void viewUser(void);

// borrow book 
void viewAllUser(void);

void showBookStatus(int);

void showUserStatus(int);




int main()
{
	int menuOption = 0;
	while(menuOption!=EXIT_CODE)
	{
	
	menuOption = getMainMenuOption();
	cout<<menuOption<<endl;
	
	switch (menuOption)
	{
		case 1:
            addbook();
            break;

	case 2:
            borrowBook();
            break;
            
    case 3:
            returnBook();
            break;

	case 4:
            viewBook();
            break;

	case 5:
            viewAllBooks();
            break;
            
    case 6:
            addUser();
            break;

	case 7:
            viewUser();
            break;
            
    case 8:
            viewAllUser();
            break;


	case EXIT_CODE:
			cout<<" --SYSTEM IS EXITING---! " <<endl;
            break;


	default:
		cout<<menuOption << "is invalid option" <<endl;
		break;
}
}
	
	
}


// ************************************************************
// Function definitions
// ************************************************************


void showMainMenu()
{
	
		clearScreen();

    cout << "\t\t*********************************" << endl;
    cout << "\t\t*                               *" << endl;
    cout << "\t\t*   WELCOME TO LIBRARY SYSTEM   *" << endl;
    cout << "\t\t*                               *" << endl;
    cout << "\t\t*********************************" << endl
         << endl
         << endl;

	    cout << "------ MAIN MENU -------" << endl
         << endl;

	int menuOption=0;
	while(menuOption < EXIT_CODE)
	{
		cout<<(menuOption + 1)<<". " <<mainMenu[menuOption] << endl;
		menuOption++;
			}	

}

int getMainMenuOption()
{
	showMainMenu();
	 
	cout<<" SELECT ONE OPTION FROM ABOVE MENU BETWEEN 1 TO 9  ";
	int menuOption=9;
	cin >> menuOption ;
	return menuOption;
	
	waitForUser();	
}

void addbook()
{
	clearScreen();

	cout<<"------- ADD NEW BOOK ------" <<endl;
	
	//currentBooksPosition <= BOOKS_LIMIT
	currentBooksPosition++;

	if(currentBooksPosition == BOOKS_LIMIT)
	
{
	
	cout<<" MAXIMUM BOOKS  REACHED! YOU CAN NOT ADD ANOTHER ADD BOOK" <<endl;
	waitForUser();
	
	//return from function from here
	return;
	
}
	cout<<endl;		
		
	cout<<" book info " <<endl ;
	 line('-' , 12);


	 cout<<"ENTER BOOK ID ";	
	 cin >> bookId[currentBooksPosition];
	 
	 cout<<"ENTER BOOK NAME ";	
	 cin >> bookName[currentBooksPosition];
	 
	 cout<<"ENTER AUTHOR NAME ";	
	 cin >> authorName[currentBooksPosition];
	waitForUser();			
	cout<< " BOOK IS SUCCESSFULLY ADDED  " <<endl
	<<endl;	 
 	 
	showBookStatus(currentBooksPosition);

}


void borrowBook()
{ 

		clearScreen();

	cout<<"------- BORROW A BOOK----" <<endl <<endl;
	
	// book exist or not
    int bookExist;
    cout << "Enter book id (between 0 and " << (BOOKS_LIMIT - 1) << "): ";
    cin >> bookExist;
    // If book does not exist, return
    if (!(bookExist > -1 && bookExist <= currentBooksPosition))
    {
        cout << "book with this book id is not added yet " << bookExist
             << ". borrow book cannot be performed!" << endl;
        waitForUser();
        return;
    }
    
    //borrow book can be perform or not
    int borrowBook;
    cout << "Enter book id (between 0 and " << (BOOKS_LIMIT - 1) << "): ";
    cin >> borrowBook;
    // If book exist, return
    if (!(borrowBook >-1 && borrowBook <= currentBooksPosition))
    {
        cout << "book with this book id is available " <<borrowBook
             << ". borrow book can not  be performed!" << endl;
        waitForUser();
        return;
    }
	//  user exist or not
    int userExist;
    cout << "Enter user id (between 0 and " << (USER_LIMIT - 1) << "): ";
    cin >> userExist;
    // If useres not exist, return
    if (!(userExist > -1 && userExist <= currentUserPosition))
    {
        cout << "user with this user id is not added yet " << userExist
             << ". borrow book cannot be performed!" << endl;
        waitForUser();
        return;
    }
	 bookAmounts[currentBooksPosition]+=borrowBook ;
    cout << endl;
    cout << "book isued successfully!" << endl;
    cout << "BOOK " <<  bookExist<< " has been trasnferred from sender account "
    << userExist << endl;
	waitForUser();    
}


void returnBook()
{ 

	clearScreen();
	cout<<"------- RETURN A BOOK----" <<endl <<endl;
	int bookPosition ;
	cout<<"enter book id( between 0 and " <<(BOOKS_LIMIT - 1 ) <<"): " <<endl;
	cin >>bookPosition;
	if(bookPosition > -1 && bookPosition <= currentBooksPosition)
	{
		cout<<"ENTER USER ID " ;
		int bookAmount;
		cin >> bookAmount;
		bookAmounts[currentBooksPosition]-=bookAmount ;
		showUserStatus(bookPosition);
		}
	else
{
	cout<<"BOOK DOES NOT EXIST WITH THIS BOOK ID"  <<bookPosition <<endl;
	waitForUser();
}

}

void viewBook()
{
	clearScreen();
	cout<<"------- VIEW BOOK ------" <<endl <<endl;
	int bookPosition ;
	cout<< "ENTER BOOK ID BETWEEN ( 0 AND " <<(BOOKS_LIMIT-1) << "): " ;
	cin >> bookPosition ;
	showBookStatus(bookPosition);

}


void viewAllBooks()
{
	clearScreen();
	cout<<"------- VIEW ALL BOOKS ------" <<endl <<endl;
	
	int bookPosition = 0;
    if (bookPosition > -1 && bookPosition <= currentBooksPosition)
    {
        line('=');
        cout << setw(7) << left << "Book ID .\t\t"
             << setw(20) << left << "Book Name"
             << setw(20) << left << "Author Name"
             << setw(10) << left << "book status" << endl;
        line('=');
        for (int bookPosition = 0; bookPosition <= currentBooksPosition; bookPosition++)
        {
            cout << setw(7) << right << bookPosition << "\t\t"
                 << setw(20) << left << bookName[bookPosition]
                 << setw(20) << left << authorName[bookPosition]
                 << setw(15) << left << availableBooks[bookTypes[bookPosition]]
                 << setw(10) << right
                 << bookAmounts[bookPosition] << endl;
            line('-');

		
		}
	}
		
		else
		cout << " THIS book ID NOT ADDED YET " <<endl ;
		 waitForUser();
	
		
		}
	
		
		


	void addUser()
{
	clearScreen();
	cout<<"------- ADD USER ------" 
	<<endl 
	<<endl;
	currentUserPosition ++ ;
	//currentUserPosition <= USER_LIMIT
	//	
	
	if(currentUserPosition==USER_LIMIT)
	{
		cout<<" MAXIMUM USER'S LIMIT REACHED YOU CAN NOT ADD ANOTHER USER " <<endl;
		waitForUser();
		 
		 //return function from here
		 return ;
		
	}
	
	
	cout<<" USER DETAILS "  <<endl;
	line('-',13);
	
	cout << "Enter user id: ";
    userId[currentUserPosition];

    cout << "Enter first name: ";
    cin >> firstName [currentUserPosition];

    cout << "Enter last name: ";
    cin >> lastName[currentUserPosition];

    cout << endl;
    cout << "books " << endl;
    line('-', 6);

    cout << "Available books" << endl;
    for (int i = 0; i < 5; i++)
        cout << i << ". " << availableBooks[i] << endl;

	cout<<"ENTER BOOK ID MUST BE BETWEEN (0 AND 5 ) " ;
	int bookType = -1 ;
	cin >>bookType ;
	//no validiation
	bookTypes[currentUserPosition]=bookType;
	cout<<endl;
	
		int bookAmount;
		cin>>bookAmount;
		bookAmounts[currentBooksPosition]=bookAmount;
		cout<< " USER   SUCCESSFULLY BORROWED A BOOK "<<endl 
	   <<endl;

	showUserStatus(currentUserPosition);	
}

void viewUser()
{
	clearScreen();
	cout<<"------- VIEW USER ------" <<endl <<endl;
	int userPosition ;
	cout<< "ENTER USER ID BETWEEN ( 0 AND " <<(BOOKS_LIMIT-1) << "): " ;
	cin >> userPosition ;
	showUserStatus(userPosition);
}

	void viewAllUser()
{
	clearScreen();
	cout<<"------- VIEW ALL USER ------" <<endl <<endl;
	
	int userPosition = 0;
    if (userPosition > -1 && userPosition <= currentUserPosition)
    {
        line('=');
        cout << setw(7) << left << "USER  ID .\t\t"
             << setw(15) << left << "First Name"
             << setw(20) << left << "Last Name"
             << setw(10) << left << "book status" << endl;
        line('=');
        for (int userPosition = 0; userPosition <= currentUserPosition; userPosition++)
        {
            cout << setw(7) << right << userPosition << "\t\t"
                 << setw(15) << left << firstName[userPosition]
                 << setw(20) << left << lastName[userPosition]
                 << setw(15) << left << availableBooks[userTypes[userPosition]]
                 << setw(10) << right
                 << userAmounts[userPosition] << endl;
            line('-');

		
		}
	}
		
		else
		cout << " THIS USER ID NOT ADDED YET " <<endl ;
		 waitForUser();
}

void clearScreen()
{
	system("clear ");
}

void waitForUser()
 {
 	cout<<"    \n Press any key to countinue! " <<endl;
	cin.ignore(); //get user input and ignore it
	cin.ignore(); //get user input and ignore it
 	
 }
 
 void line(char linecharacter , int times)
 
 {
 	for(int i=0; i <= times ; i++)
 	cout<< linecharacter;
 	cout <<endl;
 	
 }
 
 
  void showBookStatus(int booksPosition)
  
{
	clearScreen();
	cout<<"------- BOOK INFO---" <<endl <<endl;
	if(booksPosition > -1 && booksPosition <= currentBooksPosition)
	{
		cout<< " BOOK INFO : " << booksPosition <<endl;
		cout<< " BOOK ID: " << bookId[booksPosition] <<endl;
		cout<<" BOOK NAME "       <<bookName[booksPosition] <<endl;
		cout<<" AUTHOR'S NAME'   "<<authorName[booksPosition] <<endl;
	}
	else
	cout<<" BOOK DOES NOT EXIST " <<booksPosition <<endl;
	waitForUser();
}
 
 void showUserStatus(int UserPosition)
 
{
	
	clearScreen();
	cout<<"------- USER STATUS  ------" <<endl <<endl;
	
	if(UserPosition >-1 && UserPosition <= currentUserPosition)
	{
		
		cout<< " USER INFO " <<UserPosition  <<endl;
		cout<< " USER ID " <<userId[UserPosition] <<endl;
		cout<< " FIRST NAME  "<<firstName[UserPosition] <<endl;
		cout<< " LAST NAME  " <<lastName[UserPosition] <<endl;
		cout<<"  BOOK       " <<availableBooks[userTypes[UserPosition]] <<endl;
		cout<<"  book status " <<userAmounts[UserPosition] <<endl;
		}
	else
	cout<< " USER DOES NOT EXIST WITH THIS USER ID " <<UserPosition <<endl;
	waitForUser();	
}

 
