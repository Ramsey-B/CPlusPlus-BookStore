#pragma once
#include "Book.h"
#include <list>
#include "LibraryRepository.h"
class BookService
{
public:
	BookService(LibraryRepository* libraryRepo = NULL)
	{
		if (libraryRepo == NULL)
		{
			libraryRepo = new LibraryRepository();
		}
		libraryRepository = libraryRepo;
		delete libraryRepo;
	}

	~BookService()
	{
		delete libraryRepository;
	}

	bool Add(Book& book);
	bool Remove(std::string id);
	Book* Checkout(std::string id);
	Book* CheckoutByTitle(std::string tittle);
	std::list<Book*> GetAll();
	Book* Get(std::string id);
	Book* GetByTitle(std::string title);
private:
	LibraryRepository* libraryRepository;
};

