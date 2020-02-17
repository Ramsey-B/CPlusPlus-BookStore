#pragma once
#include <iostream>
#include <exception>
class OutOfStockException : public std::exception
{
public:
	OutOfStockException(std::string m = "Out of stock.") : msg(m)
	{

	}

	const char* what() { return msg.c_str(); }

private:
	std::string msg;
};

