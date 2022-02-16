#include "pch.h"
#include "Add.h"

Add::Add(vector<member>& members) : members_(members) {
}

bool Add::isValid(const member& newmem) const {
	for (const auto& mem : members_) {
		if (mem.employeeNum == newmem.employeeNum)
			return false;
	}

	if (newmem.name == "" || newmem.phoneNum == "" || newmem.birthday == 0)
		return false;
	return true;
}

int Add::run(const member& newmem) {
	members_.push_back(newmem);
	return 1;
}