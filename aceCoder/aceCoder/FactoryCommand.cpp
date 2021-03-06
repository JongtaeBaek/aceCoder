#include "pch.h"
#include "FactoryCommand.h"
#include "Add.h"
#include "delete.h"
#include "modifier.h"
#include "Sch.h"

Command* FactoryCommand::createCommand(const string& cmd, vector<member>& members, ParameterChecker* para) {
	if (cmd == "ADD") {
		return new Add(members, para);
	}
	else if (cmd == "DEL") {
		return new Del(members);
	}
	else if (cmd == "MOD") {
		ParameterChecker* modParamChecker = new ModParameterChecker();
		if (modParamChecker == nullptr) return nullptr;
		return new Modifier(members, modParamChecker);
	}
	else if (cmd == "SCH") {
		return new Sch(members);
	}

	return nullptr;
}