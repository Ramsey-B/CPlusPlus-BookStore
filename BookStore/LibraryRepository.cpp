#include "LibraryRepository.h"
#include <sstream>

void LibraryRepository::Add(Book& book)
{
}

void LibraryRepository::Remove(std::string id)
{
}

void LibraryRepository::Update(std::string id, Book& book)
{
}

std::list<Book*> LibraryRepository::GetAll()
{
	std::list<Book*> books;
	std::ifstream in("library.txt");
	std::string line;

	while (std::getline(in, line))
	{
		Book* book = new Book();
		std::stringstream ss(line);
		ss >> book;
		books.push_back(book);
	}

	return books;
}

Book* LibraryRepository::Get(std::string id)
{
	std::list<Book*> books = GetAll();
	Book* foundBook;
	for (Book* book : books)
	{
		if (book->Id == id)
		{
			foundBook = book;
			break;
		}
	}
	DeleteBookList(books);
	return foundBook;
}

void LibraryRepository::DeleteBookList(std::list<Book*> books)
{
	for (Book* book : books)
	{
		delete book;
	}
}
