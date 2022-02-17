#pragma once
#include "Command.h"
#include "member.h"
#include "ParameterChecker.h"
class IFactoryCommand {
public:
	virtual Command* createCommand(const string& cmd, vector<member>& members, ParameterChecker* para) = 0;
};

class FactoryCommand : public IFactoryCommand {
public:
	Command* createCommand(const string& cmd, vector<member>& members, ParameterChecker* para) override;
};