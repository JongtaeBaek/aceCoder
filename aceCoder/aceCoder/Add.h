#pragma once
#include <vector>
#include "member.h"

vector<member> gmembers;
class Add {
public:
	Add(vector<member>& members) : members_(members) {}
	virtual ~Add() = default;

	bool isValid  (const member &newmem) const {
		for (const auto& mem : members_) {
			if (mem.employeeNum == newmem.employeeNum)
				return false;
		}

		if (newmem.name == "" || newmem.phoneNum == "" || newmem.birthday == 0 )
			return false;
		return true;
	}

	int run(const member& newmem) {
		members_.push_back(newmem);
		return 1;
	}
private:
	vector<member> &members_;
};
