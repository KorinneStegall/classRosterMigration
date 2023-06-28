// C867-ClassRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Repo.h"
int main()
{
    /*The long strings to parse*/
    const string bookData[] =
    {
        "NX_1,Forensics for Housewives!,Genevieve Valentin,23.4,45.99,35,NONFICTION",
        "Fx0_F2,Useless Cyberpunk Gamer Chat,SuperKool CyberDog,0,19.99,200,FICTION",
        "UXU1x,A Primer of Educational Wisdom,Sage the Divine Goddess,0.99,123.45,987.65,UNDECIDED",
        "F3-F,Mein Kampf est NICHT Fiction!,Adolf Hitler's Corpse,0,1,2.49,FICTION",
        "N_W1,An Agonizing Death from C++,David Wayne Bishop,999.99,3.14,123, NONFICTION"
    };

    const int numBooks = 5;
    Repo repo;//creates repo using default parameterless constructor

    for (int i = 0; i < numBooks; i++) repo.parse(bookData[i]);
    cout << "Displaying all books: " << std::endl;
    repo.printAll();
    cout << std::endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying by book type: " << bookTypeStrings[i] << std::endl;
        repo.printByBookType((BookType)i);//Cast the integer to a BookType
    }

    cout << "Displaying books with invalid IDs: " << std::endl;
    repo.printInvalidIDs();
    cout << std::endl;

    cout << "Displaying average prices: " << std::endl;
    for (int i = 0; i < numBooks; i++)
    {
        repo.printAveragePrices(repo.bookRepoArray[i]->getID()); //CHANGED - ADDED PARAMETERS
    }
    

    cout << "Removing book with ID N_W1: " << std::endl;
    repo.removeBookByID("N_W1");//method does its own input
    cout << std::endl;

    cout << "Removing book with ID N_W1: " << std::endl;
    repo.removeBookByID("N_W1");
    cout << std::endl;

    system("pause");
    return 0;
}
