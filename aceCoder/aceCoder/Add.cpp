#include "pch.h"
#include "Add.h"

Add::Add(vector<member>& members, ParameterChecker* para) : members_(members),parachecker_ (para){
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

string Add::run_old(const string& comand1line) {
	if (!parachecker_)
		return string{ "[Error] Add Parameter Checker is nullptr!"};
	vector<string> values = parachecker_->parse(comand1line);
	if (!parachecker_->isValid(values))
		return string{"[Error] ADD parameters are invaild!"};

	const member mem = parachecker_->convert(values);
	if (!isValid(mem))
		return string{ "[Error] ADD parameters are invaild!" };

	run(mem);
	return string{};
}

string Add::run(const string& comand1line) {
	if (!parachecker_)
		return string{ "[Error] Add Parameter Checker is nullptr!" };
	vector<string> values = parachecker_->parse(comand1line);
	if (!parachecker_->isValid(values))
		return string{ "[Error] ADD parameters are invaild!" };

	const member mem = parachecker_->convert_4sort(values);
	if (!isValid(mem))
		return string{ "[Error] ADD parameters are invaild!" };

	run(mem);
	return string{};
}