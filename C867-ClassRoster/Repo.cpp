#include "Repo.h"
void Repo::parse(string bookdata)//this parses out each row - one at a time
{
	BookType bt = UNDECIDED;/*default value*/
	if (bookdata.at(0) == 'F') bt = FICTION;//The first character tells us the book type
	else if (bookdata.at(0) == 'N') bt = NONFICTION;

	int rhs = bookdata.find(",");/*find the comma*/
	string bID = bookdata.substr(0, rhs);//extract the substring in front of the comma

	int lhs = rhs + 1;/*move past the previous comma*/
	rhs = bookdata.find(",", lhs);
	string ttl = bookdata.substr(lhs, rhs - lhs);//book title

	lhs = rhs + 1;/*keep going*/
	rhs = bookdata.find(",", lhs);
	string aut = bookdata.substr(lhs, rhs - lhs);//book author

	lhs = rhs + 1;/*keep going*/
	rhs = bookdata.find(",", lhs);
	double p1 = stod(bookdata.substr(lhs, rhs - lhs));//first price - convert to double
	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	double p2 = stod(bookdata.substr(lhs, rhs - lhs));//second price
	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	double p3 = stod(bookdata.substr(lhs, rhs - lhs));//third price
	/*already determined the book type (will need to add later)*/

	add(bID, ttl, aut, p1, p2, p3, bt);//prices go in seperately
}

/*The infamous, redundant, and wholly unnecessary add method - it only does one thing*/
void Repo::add(string bookID, string title, string author, double price1, double price2, double price3, BookType bt)
{
	/*put prices back into an array for constructor*/
	double parr[3] = { price1, price2, price3 };
	/*make the new Book object. Remember that lastIndex starts at -1 and NOT 0*/
	/*remember to use the PREFIX form of ++*/
	bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt);//use full constructor
}

/*display all books using tap-separated output*/
void Repo::printAll()
{
	Book::printHeader();
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		cout << bookRepoArray[i]->getID(); cout << '\t';
		cout << bookRepoArray[i]->getTitle(); cout << '\t';
		cout << bookRepoArray[i]->getAuthor(); cout << '\t';
		cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
		cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
		cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
		cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;
	}
}

/*display only books which match given book type*/
void Repo::printByBookType(BookType bt)
{
	Book::printHeader();
	for (int i = 0; i <= Repo::lastIndex; i++) 
	{
		if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
	}
	cout << std::endl;
}

/*each book's ID must contain an undercore and either an upper case 'X' or a lower case 'x'*/
void Repo::printInvalidIDs()
{
	bool any = false;
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		string bID = (bookRepoArray[i]->getID());
		if (bID.find('_') == string::npos || (bID.find('X') == string::npos && bID.find('x') == string::npos))
		{
			any = true;
			cout << bID << ": " << bookRepoArray[i]->getTitle() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

/*display the average price of the books*/
void Repo::printAveragePrices(string bookID) //CHANGED - ADDED PARAMETERS
{
	for (int i = 0; i <= Repo::lastIndex; i++) 
	{
		if (bookRepoArray[i]->getID() == bookID)//CHANGED - ADDED IF STATEMENT
		{
			cout << bookID << ": "; //CHANGED - WITH IF STATEMENT
			cout << (bookRepoArray[i]->getPrices()[0]
				+ bookRepoArray[i]->getPrices()[1]
				+ bookRepoArray[i]->getPrices()[2]) / 3.0 << std::endl;
		}
		
	}
	cout << std::endl;
}

/*remove a book - comes in as a parameter*/
void Repo::removeBookByID(string bookID)
{
	bool success = false;//assume it's not there
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		if (bookRepoArray[i]->getID() == bookID)
		{
			success = true;//found
			if (i < numBooks - 1)
			{
				Book* temp = bookRepoArray[i];//swap it with last book
				bookRepoArray[i] = bookRepoArray[numBooks - 1];
				bookRepoArray[numBooks - 1] = temp;
			}
			Repo::lastIndex--;//last book is no longer visible
			/*Note: book is not actually deleted, it is only no longer visible*/
		}
	}
	if (success)
	{
		cout << bookID << " removed from repository." << std::endl << std::endl;
		this->printAll();//display the books - the remoed book should not display
	}
	else cout << bookID << " not found." << std::endl << std::endl;
}

Repo::~Repo()
{
	cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
	for (int i = 0; i < numBooks; i++)
	{
		cout << "Destroying book #" << i + 1 << std::endl;
		delete bookRepoArray[i];
		bookRepoArray[i] = nullptr;
	}
}
