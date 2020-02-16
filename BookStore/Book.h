#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <random>

class Book
{
public:
	std::string Title;
	std::string Author;
	std::string CheckOutBy;
	int Stock;
	std::string Id;

	Book(std::string title = "", std::string author = "", int stock = 0, std::string id = "", std::string checkoutBy = "")
	{
		Title = title;
		Author = author;
		Stock = stock;
		if (id.empty())
		{
			id = Generate_Id();
		}
		Id = id;
		CheckOutBy = checkoutBy;
	}

	bool operator==(const Book& obj)
	{
		return (Id == obj.Id) && (Title == obj.Title) && (Author == obj.Author) && (Stock == obj.Stock);
	}

	/*
	 * Write the member variables to stream objects
	 */
	friend std::ostream& operator << (std::ostream& out, const Book& obj)
	{
		out << obj.Id << "\n" << Replace(obj.Title, ' ', '_') << "\n" << Replace(obj.Author, ' ', '_') << "\n" << obj.Stock << std::endl;
		return out;
	}

	/*
	 * Read data from stream object and fill it in member variables
	 */
	friend std::istream& operator >> (std::istream& in, Book& obj)
	{
		in >> obj.Id;
		in >> obj.Title;
		in >> obj.Author;
		in >> obj.Stock;
		obj.Title = Replace(obj.Title, '_', ' ');
		obj.Author = Replace(obj.Author, '_', ' ');
		return in;
	}

	friend std::istream& operator >> (std::istream& in, Book* obj)
	{
		in >> obj->Id;
		in >> obj->Title;
		in >> obj->Author;
		in >> obj->Stock;
		obj->Title = Replace(obj->Title, '_', ' ');
		obj->Author = Replace(obj->Author, '_', ' ');
		return in;
	}

private:
	std::string Generate_Id();
	static std::string Replace(std::string str, char replaceChar, char addChar)
	{
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == replaceChar)
				str[i] = addChar;
		}

		return str;
	}
};

