#pragma once
#include <string>
using namespace std;
class Command {
public:
	Command() = default;
	virtual ~Command() = default;
	virtual string run(const string& comand1line) = 0;
};