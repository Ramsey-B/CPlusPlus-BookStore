#include "ConsoleService.h"

void ConsoleService::AddBook()
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

void ConsoleService::RemoveBook()
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

void ConsoleService::CheckoutBook()
{
	std::string selection;
	std::string bookAsString = "";
	std::cout << "Would you like to checkout by 'id' or 'title'.\n";
	std::getline(std::cin, selection);
	if (selection == "id")
	{
		std::string id;
		std::cout << "Please enter the book Id.\n";
		std::getline(std::cin, id);
		auto book = bookService->Checkout(id);
		bookAsString = BookAsString(*book);
		delete book;
	}
	else if (selection == "title")
	{
		std::string title;
		std::cout << "Please enter the book title.\n";
		std::getline(std::cin, title);
		auto book = bookService->CheckoutByTitle(title);
		bookAsString = BookAsString(*book);
		delete book;
	}
	std::cout << "Checkout book | " + bookAsString + "\n";
}

void ConsoleService::ListBooks()
{
	std::string selection;
	std::string bookAsString = "";
	std::cout << "Would you like to checkout by 'id' or 'title'.\n";
	std::getline(std::cin, selection);
	if (selection == "id")
	{
		std::string id;
		std::cout << "Please enter the book Id.\n";
		std::getline(std::cin, id);
		auto book = bookService->Checkout(id);
		bookAsString = BookAsString(*book);
		delete book;
	}
	else if (selection == "title")
	{
		std::string title;
		std::cout << "Please enter the book title.\n";
		std::getline(std::cin, title);
		auto book = bookService->CheckoutByTitle(title);
		bookAsString = BookAsString(*book);
		delete book;
	}
	std::cout << "Checkout book | " + bookAsString + "\n";
}

void ConsoleService::SearchBooks()
{
	std::string selection;
	std::string bookAsString = "";
	std::cout << "Would you like to search by 'id' or 'title'.\n";
	std::getline(std::cin, selection);
	if (selection == "id")
	{
		std::string id;
		std::cout << "Please enter the book Id.\n";
		std::getline(std::cin, id);
		auto book = bookService->Get(id);
		bookAsString = BookAsString(*book);
		delete book;
	}
	else if (selection == "title")
	{
		std::string title;
		std::cout << "Please enter the book title.\n";
		std::getline(std::cin, title);
		auto book = bookService->GetByTitle(title);
		bookAsString = BookAsString(*book);
		delete book;
	}
	std::cout << "Found book | " + bookAsString + "\n";
}

std::string ConsoleService::BookAsString(Book& book)
{
	return "Id: " + book.Id + " | Title: " + book.Title + " | Author: " + book.Author + " | Stock: " + std::to_string(book.Stock);
}
