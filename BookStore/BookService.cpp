#include "BookService.h"
#include "OutOfStockException.h"

bool BookService::Add(Book& book)
{
	try
	{
		libraryRepository->Add(book);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool BookService::Remove(std::string id)
{
	try
	{
		libraryRepository->Remove(id);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

Book* BookService::Checkout(std::string id)
{
	auto book = libraryRepository->Get(id);
	if (book == nullptr)
	{
		throw "Book Not Found";
	}
	if (book->Stock == 0)
	{
		throw OutOfStockException("Out of stock for book with Id: " + id);
	}
	book->Stock = book->Stock - 1;
	libraryRepository->Update(id, *book);
	return book;
}

Book* BookService::CheckoutByTitle(std::string title)
{
	auto book = libraryRepository->GetByTitle(title);
	if (book == nullptr)
	{
		throw "Book Not Found";
	}
	if (book->Stock == 0)
	{
		throw OutOfStockException("Out of stock for book with Title: " + title);
	}
	book->Stock = book->Stock - 1;
	libraryRepository->Update(book->Id, *book);
	return book;
}

std::list<Book*> BookService::GetAll()
{
	return libraryRepository->GetAll();
}

Book* BookService::Get(std::string id)
{
	return libraryRepository->Get(id);
}

Book* BookService::GetByTitle(std::string title)
{
	return libraryRepository->GetByTitle(title);
}
