#pragma once
#include <string>
#include "Book.h"
#include "BookService.h"
class ConsoleService
{
public:
	ConsoleService(BookService* bookSrvc = NULL)
	{
		if (bookSrvc == NULL)
		{
			bookSrvc = new BookService();
		}
		bookService = bookSrvc;
	}

	~ConsoleService()
	{
		delete bookService;
	}

	BookService* bookService;
	void AddBook();
	void RemoveBook();
	void CheckoutBook();
	void ListBooks();
	void SearchBooks();
private:
	std::string BookAsString(Book& book);
};

