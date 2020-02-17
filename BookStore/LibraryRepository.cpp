#include "LibraryRepository.h"
#include <sstream>
#include <iostream>

void LibraryRepository::Add(Book& book)
{
	std::ofstream out("library.txt", std::ios::app);
	out << book;

	out.close();
}

void LibraryRepository::Remove(std::string id)
{
	std::list<Book*> books = GetAll();
	Book* book = Get(id);
	books.remove(book);
	delete book;
	UpdateFile(books);
	DeleteBookList(books);
}

void LibraryRepository::Update(std::string id, Book& updatedbook)
{
	std::list<Book*> books = GetAll();
	for (Book* book : books)
	{
		if (book->Id == id)
		{
			book = new Book(updatedbook);
		}
		delete book;
	}
	UpdateFile(books);
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

	in.close();

	return books;
}

Book* LibraryRepository::Get(std::string id)
{
	std::list<Book*> books = GetAll();
	Book* foundBook{};
	for (Book* book : books)
	{
		if (book->Id == id)
		{
			foundBook = book;
		}
		delete book;
	}
	return foundBook;
}

Book* LibraryRepository::GetByTitle(std::string title)
{
	std::list<Book*> books = GetAll();
	Book* foundBook{};
	for (Book* book : books)
	{
		if (book->Title == title)
		{
			foundBook = book;
		}
		delete book;
	}
	return foundBook;
}

void LibraryRepository::DeleteBookList(std::list<Book*> books)
{
	for (Book* book : books)
	{
		delete book;
	}
}

void LibraryRepository::UpdateFile(std::list<Book*> books)
{
	std::ofstream file("library.txt");
	file.clear();
	for (Book* book : books)
	{
		file << book;
	}
	file.close();
	DeleteBookList(books);
}
