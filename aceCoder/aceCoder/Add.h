#pragma once
#include <vector>
#include "member.h"

class Add {
public:
	Add(vector<member>& members);
	virtual ~Add() = default;

	bool isValid(const member& newmem) const;
	int run(const member& newmem);
private:
	vector<member> &members_;
};
