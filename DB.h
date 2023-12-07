#pragma once
#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class DB {
public:
	void begin_transaction();
	void put(std::string _key, int value);
	int get(std::string _key);
	void commit();
	void rollback();

private:
	bool isTransaction = false;
	std::string key = "";
	int val = 0;
	std::map<std::string, int> db;
	std::map<std::string, int> buffer;
};
