#pragma once
#include "Book.h"
#include <list>
class LibraryRepository
{
public:
	void Add(Book& book);
	void Remove(std::string id);
	void Update(std::string id, Book& book);
	std::list<Book*> GetAll();
	Book* Get(std::string id);

private:
	void DeleteBookList(std::list<Book*> books);
};

