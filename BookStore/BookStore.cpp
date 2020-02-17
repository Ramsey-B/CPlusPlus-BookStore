// BookStore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h";
#include <fstream>;
#include "BookStore.h"
#include "BookService.h"

BookService* bookService;

int main()
{
    std::cout << "Hello World!\n";
	bool done = false;
	bookService = new BookService();
	while (!done)
	{
		std::string command;
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
			AddBook();
		}
		else if (command == "r" || command == "remove")
		{
			RemoveBook();
		}
		else if (command == "c" || command == "checkout")
		{
			CheckoutBook();
		}
		else if (command == "l" || command == "list")
		{
			ListBooks();
		}
		else if (command == "s" || command == "search")
		{
			SearchBooks();
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
	delete bookService;
}

void AddBook()
{
	std::string title;
	std::string author;
	std::string stock;

	std::cout << "Please enter the book title.\n";
	std::getline(std::cin, title);
	std::cout << "Please enter the book author.\n";
	std::getline(std::cin, author);
	std::cout << "Please enter the book stock count.\n";
	std::getline(std::cin, stock);

	Book* book = new Book(title, author, std::stoi(stock));
	auto created = bookService->Add(*book);
	if (created)
	{
		std::cout << "The book was added to the library.\n";
	}
	std::cout << "Unable to create the book. Please try again.\n";
	delete book;
}

void RemoveBook()
{
	std::string id;
	std::cout << "Please enter the Id of the book to remove.\n";
	std::getline(std::cin, id);
	auto removed = bookService->Remove(id);
	if (remove)
	{
		std::cout << "The book was removed library.\n";
	}
	std::cout << "Unable to remove the book. Please try again.\n";
}

void CheckoutBook()
{
	std::string selection;
	Book* book;
	std::cout << "Would you like to checkout by 'id' or 'title'.\n";
	std::getline(std::cin, selection);
	if (selection == "id")
	{
		std::string id;
		std::cout << "Please enter the book Id.\n";
		std::getline(std::cin, id);
		book = bookService->Checkout(id);
	}
	else if (selection == "title")
	{
		std::string title;
		std::cout << "Please enter the book title.\n";
		std::getline(std::cin, title);
		book = bookService->CheckoutByTitle(title);
	}
	auto bookAsString = BookAsString(*book);
	std::cout << "Checkout book | " + bookAsString + "\n";
	delete book;
}

void ListBooks()
{
	std::cout << "The library currently contains the following books: \n";
	auto books = bookService->GetAll();
	int count = 1;
	for (Book* book : books)
	{
		auto bookAsString = BookAsString(*book);
		std::cout << "Book #" + std::to_string(count) + ": " + bookAsString + "\n";
		delete book; 
		count = count + 1;
	}
}

void SearchBooks()
{
	std::string selection;
	Book* book;
	std::cout << "Would you like to search by 'id' or 'title'.\n";
	std::getline(std::cin, selection);
	if (selection == "id")
	{
		std::string id;
		std::cout << "Please enter the book Id.\n";
		std::getline(std::cin, id);
		book = bookService->Get(id);
	}
	else if (selection == "title")
	{
		std::string title;
		std::cout << "Please enter the book title.\n";
		std::getline(std::cin, title);
		book = bookService->GetByTitle(title);
	}
	auto bookAsString = BookAsString(*book);
	std::cout << "Found book | " + bookAsString + "\n";
	delete book;
}

std::string BookAsString(Book& book)
{
	return "Id: " + book.Id + " | Title: " + book.Title + " | Author: " + book.Author + " | Stock: " + std::to_string(book.Stock);
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
