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
		out << "id:" << obj.Id << ";title:" << Replace(obj.Title, ' ', '_') << ";author:" << Replace(obj.Author, ' ', '_') << ";stock:" << obj.Stock << ";"<< std::endl;
		return out;
	}

	/*
	 * Read data from stream object and fill it in member variables
	 */
	friend std::istream& operator >> (std::istream& in, Book& obj)
	{
		std::string str;
		in >> str;
		std::string propName = "";
		std::string value = "";
		bool passedProp = false;
		for (int i = 0; i < str.length(); ++i)
		{
			char strChar = str[i];
			if (strChar == ':') passedProp = true;
			else if (strChar == ';')
			{
				if (propName == "id") obj.Id = value;
				if (propName == "title") obj.Title = value;
				if (propName == "author") obj.Author = value;
				if (propName == "stock") obj.Stock = std::stoi(value);
				passedProp = false;
				propName = "";
				value = "";
			}
			else if (!passedProp) propName += strChar;
			else if (passedProp) value += strChar;
		}
		obj.Title = Replace(obj.Title, '_', ' ');
		obj.Author = Replace(obj.Author, '_', ' ');
		return in;
	}

	friend std::istream& operator >> (std::istream& in, Book* obj)
	{
		std::string str;
		in >> str;
		std::string propName = "";
		std::string value = "";
		bool passedProp = false;
		for (int i = 0; i < str.length(); ++i)
		{
			char strChar = str[i];
			if (strChar == ':') passedProp = true;
			else if (strChar == ';')
			{
				if (propName == "id") obj->Id = value;
				if (propName == "title") obj->Title = value;
				if (propName == "author") obj->Author = value;
				if (propName == "stock") obj->Stock = std::stoi(value);
				passedProp = false;
				propName = "";
				value = "";
			}
			else if (!passedProp) propName += strChar;
			else if (passedProp) value += strChar;
		}
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

