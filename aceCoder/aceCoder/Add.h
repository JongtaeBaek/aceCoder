#pragma once
#include "member.h"
#include <vector>

using namespace std;
class Add {
public:
	bool isValid  (const member &newmem) const {
		for (const auto& mem : members) {
			if (mem.employeeNum == newmem.employeeNum)
				return false;
		}

		if (newmem.name == "" || newmem.phoneNum == "" || newmem.birthday == 0 )
			return false;
		return true;
	}

	int run(const member& newmem) {
		members.push_back(newmem);
		return 1;
	}
private:
	vector<member> members;
};
