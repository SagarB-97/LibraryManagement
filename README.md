# Functionalities Implemented in Library Management System

## Librarian

### Signup<br>
Input: Enter name, email ID, username, password<br>
Processing: Stores this data in a binary file<br>
Output: Display “Welcome to LibManager”<br>

### Login<br>
Input: Enter username and password<br>
Processing: Check validity of both username and password<br>
Output: If both username and password are valid, grant access to the system, else               
display appropriate message<br>

### Add books to Library
Input: Book name, Book author, ISBN, Total no. of copies purchased<br>
Output: Adds the book to the list of books in library<br>

### View all Books in Library
Output: Lists the details of all the books available in the library<br>

### Add Customer
Input: Enter customer name, mobile number<br>
Processing: Generates a unique ID for the customer<br>
Output: Adds customer to the list of existing customers<br>

### View All Customers
Output: Shows the details of all customers of the library<br>

### Remove Customer
Input: Enter Customer ID<br>
Processing: Searches customer list having this ID<br>
Output: Deletes the customer entry from the list<br>

### Remove Book
Input: Enter book author<br>
Processing: Search book list with this author<br>
Output: Delete this entry<br>


### Input: Enter book title   
Processing: Search book list with this author<br>
Output: Delete this entry<br>

## Front Desk Staff
### Signup
Input: Enter name, email ID, username, password<br>
Processing: Stores this data in a binary file<br>
Output: Grant access to “LibManager”<br>

### Login
Input: Enter username and password<br>
Processing: Check validity of both username and password<br>
Output: If both username and password are valid, grant access to the system, else display appropriate message<br>

### Check customer Validity
Input: Customer ID<br>
Processing: Search customer list for customer with this ID<br>
Output: Return true if valid ID, else display appropriate message<br>

### View Customer Borrowed Books
Input: Customer ID<br>
Processing: Check customer validity<br>
Output:  If valid, display all books borrowed by customer else, display appropriate message<br>         


### Renew Book
Input: Customer ID, Book Name/Author Name, New Return Date<br>
Processing:If customer ID valid, renew the corresponding book to new date<br>
Output: The book is renewed in database<br>

### Return Book
Input:Customer ID, Book Name/Author Name, Actual Return Date<br>
Processing:If customer ID valid, return the corresponding book and calculate fine<br>
Output:  The fine to be paid by customer<br>

## Customer
### Search Books in Library
Input: Enter book author<br>
Processing: Search book list with this author<br>
Output: Display this entry<br><br>

Input: Enter book title<br> 
Processing: Search book list with this title<br>
Output: Display this entry<br>






