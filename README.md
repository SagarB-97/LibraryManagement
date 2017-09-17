# Functionalities Implemented in Library Management System

1. Librarian

	1.1. Signup<br>
	Input: Enter name, email ID, username, password<br>
	Processing: Stores this data in a binary file<br>
	Output: Display “Welcome to LibManager”<br>

	1.2.	Login<br>
	Input: Enter username and password<br>
	Processing: Check validity of both username and password<br>
	Output: If both username and password are valid, grant access to the system, else               
	display appropriate message<br>

	1.3.	Add books to Library
	Input: Book name, Book author, ISBN, Total no. of copies purchased
	Output: Adds the book to the list of books in library

	1.4.	View all Books in Library
	Output: Lists the details of all the books available in the library

	1.5.	Add Customer
	Input: Enter customer name, mobile number
	Processing: Generates a unique ID for the customer
	Output: Adds customer to the list of existing customers

	1.6.	View All Customers
	Output: Shows the details of all customers of the library

	1.7.	Remove Customer
	Input: Enter Customer ID
	Processing: Searches customer list having this ID
	Output: Deletes the customer entry from the list

	1.8.	Remove Book
	1.8.1.	Input: Enter book author
	Processing: Search book list with this author
	Output: Delete this entry
	

	1.8.2.	Input: Enter book title   
	Processing: Search book list with this author
	Output: Delete this entry
	
2.	Front Desk Staff
	2.1.	Signup
	Input: Enter name, email ID, username, password
	Processing: Stores this data in a binary file
	Output: Grant access to “LibManager”
	
	2.2.	Login
	Input: Enter username and password
	Processing: Check validity of both username and password
	Output: If both username and password are valid, grant access to the system, else               
	display appropriate message
	
	2.3.	Check customer Validity
	Input: Customer ID
	Processing: Search customer list for customer with this ID
	Output: Return true if valid ID, else display appropriate message
	
	2.4.	View Customer Borrowed Books
	Input: Customer ID
	Processing: Check customer validity. 
	Output:  If valid, display all books borrowed by customer else, display appropriate      
	message         


	2.5.	Renew Book
	Input: Customer ID, Book Name/Author Name, New Return Date
	Processing:If customer ID valid, renew the corresponding book to new 	date
	Output: The book is renewed in database

	2.6.	Return Book
	Input:Customer ID, Book Name/Author Name, Actual Return Date
	Processing:If customer ID valid, return the corresponding book			and calculate fine
	Output:  The fine to be paid by customer  

3.	Customer
	3.1.	Search Books in Library
	3.1.1.	Input: Enter book author
	Processing: Search book list with this author
	Output: Display this entry
	
	3.1.2.	Input: Enter book title   
	Processing: Search book list with this author
	Output: Display this entry






