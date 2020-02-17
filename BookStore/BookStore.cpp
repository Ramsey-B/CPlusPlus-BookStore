// BookStore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h";
#include <fstream>;
#include "BookStore.h"
#include "BookService.h"
#include "ConsoleService.h"

BookService* bookService;

int main()
{
    std::cout << "Hello World!\n";
	bool done = false;
	ConsoleService* consoleService = new ConsoleService();
	while (!done)
	{
		std::string command;
		std::cout << "\n";
		std::getline(std::cin, command);
		if (command == "h" || command == "help")
		{
			std::cout << "Commands: \n";
			std::cout << "'a' || 'add': Add book to the library.\n";
			std::cout << "'r' || 'remove': Remove book from library.\n";
			std::cout << "'c' || 'checkout': Checkout book from library.\n";
			std::cout << "'l' || 'list': List all books in library.\n";
			std::cout << "'s' || 'search': Search for book.\n";
			std::cout << "'h' || 'help': List valid commands.\n";
			std::cout << "'exit': Ends program.\n";
		}
		else if (command == "a" || command == "add")
		{
			consoleService->AddBook();
		}
		else if (command == "r" || command == "remove")
		{
			consoleService->RemoveBook();
		}
		else if (command == "c" || command == "checkout")
		{
			consoleService->CheckoutBook();
		}
		else if (command == "l" || command == "list")
		{
			consoleService->ListBooks();
		}
		else if (command == "s" || command == "search")
		{
			consoleService->SearchBooks();
		}
		else if (command == "exit")
		{
			return 0;
		}
		else
		{
			std::cout << "Invalid input. Please try again.\n";
		}
	}
	delete consoleService;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
