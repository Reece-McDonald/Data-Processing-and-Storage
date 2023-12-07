#include "DB.h"

void DB::begin_transaction()
{
	if (isTransaction)
	{
		std::cout << "Transaction in progress already!" << std::endl;
		return;
	}
	isTransaction = true;
}
void DB::put(std::string _key, int value)
{
	if (!isTransaction)
	{
		throw std::invalid_argument("Transaction not in progress!"); // Source used to refresh me on using throw statements in C++ https://rollbar.com/blog/error-exceptions-in-c/.
	}
	buffer[_key] = value;
}
int DB::get(std::string _key)
{
	if (db.find(_key) != db.end())
	{
		return db[_key];
	}
	return NULL;
}
void DB::commit()
{
	if (!isTransaction)
	{
		throw std::invalid_argument("Transaction not in progress!"); 
	}
	for (auto iter = buffer.begin(); iter != buffer.end(); iter++)
	{
		db[iter->first] = iter->second;
	}
	buffer.clear();
	isTransaction = false;
}
void DB::rollback()
{
	if (!isTransaction)
	{
		throw std::invalid_argument("Transaction not in progress!");
	}
	buffer.clear();
	isTransaction = false;
}