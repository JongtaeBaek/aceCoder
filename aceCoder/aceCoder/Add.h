#pragma once
#include <vector>
#include "member.h"
#include "AddParmeterChecker.h"

class Add {
public:
	Add(vector<member>& members);
	virtual ~Add() = default;

	bool isValid(const member& newmem) const;
	int run(const member& newmem);
	string run_old(const string& comand1line);
	string run(const string& comand1line);
	void  setParameterChecker(ParameterChecker* parachecker) {
		parachecker_ = parachecker;
	}
private:
	vector<member> &members_;
	ParameterChecker* parachecker_;
};
