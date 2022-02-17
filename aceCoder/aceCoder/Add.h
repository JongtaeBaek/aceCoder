#pragma once
#include <vector>
#include "member.h"
#include "AddParmeterChecker.h"
#include "Command.h"

class Add : public Command {
public:
	Add(vector<member>& members, ParameterChecker* para = nullptr);
	virtual ~Add() = default;

	bool isValid(const member& newmem) const;
	int run(const member& newmem);
	string run_old(const string& comand1line);
	string run(const string& comand1line) override;	
private:
	vector<member> &members_;
	ParameterChecker* parachecker_;
};
