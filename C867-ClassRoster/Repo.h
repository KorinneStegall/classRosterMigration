#pragma once
#include "Book.h"
class Repo
{
public: //CHANGED TO PUBLIC
	int lastIndex = -1;
	const static int numBooks = 5;
	Book* bookRepoArray[numBooks];/*NOT declared dynamically*/

public:
	/*Note that Repo has no constructor; or DOES IT...?*/
	/*The parse method goes through a set of comma delimited strings and extracts the data of a book*/
	void parse(string row);
	/*All book data is then passed into add method which creates the Book object and places it in the array*/
	void add(string bID,
		string bTitle,
		string bAuthor,
		double bprice1,
		double bprice2,
		double bprice3,
		BookType bt);
	void printAll();/*calls the print() method in Book class for each book*/
	void printByBookType(BookType bt);/*BookType is passed in*/
	void printInvalidIDs();/*each book's ID needs an underscore and either an upper case 'X' or a lower case 'x'*/
	void printAveragePrices(string bookID);/*all students with negative prices*/											//CHANGED ADDED PARAMETERS
	void removeBookByID(string bookID);/*find the book with supplied ID and remove*/
	~Repo();
};