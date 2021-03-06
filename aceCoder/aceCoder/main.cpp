#include <iostream>
#include <algorithm>
#include "pch.h"
#include "FactoryCommand.h"
#include "AddParmeterChecker.h"

static void print_help(void)
{
	cout << "Follow the form below" << endl;
	cout << "aceCoder.exe \"input.txt\" \"output.txt\"" << endl;
}

int main(int argc, char **argv)
{	
	if (argc != 3) {
		print_help();
		return EXIT_FAILURE;
	}

	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	if (para == nullptr)
		return 	EXIT_FAILURE;

	if (!para->isValidFileName(argv[1]) || !para->isValidFileName(argv[2])){
		cout << "[Error] File name" << endl;
		return 	EXIT_FAILURE;
	}

	vector<string>lines = para->loadTxt(argv[1]);
	if (lines.size() == 0){
		cout << "[Error] File open" << endl;
		return 	EXIT_FAILURE;
	}

	vector<string> commands = { "ADD","DEL","MOD" ,"SCH" };
	std::map<std::string, Command*> cmdmap;
	IFactoryCommand* factory = new FactoryCommand();
	if (factory == nullptr)
		return 	EXIT_FAILURE;

	for (const auto& cmd : commands) {
		cmdmap.insert(make_pair(cmd, factory->createCommand(cmd, members, para)));
	}

	int pos = 0;
	if(cmdmap.find("ADD") == cmdmap.end())
		return 	EXIT_FAILURE;
	Command* add = cmdmap["ADD"];
	if (add == nullptr)
		return 	EXIT_FAILURE;

	for (int i = 0; i < lines.size(); i++) {
		const string value = para->getCMD(lines[i]);
		if (value != "ADD"){
			pos = i;
			break;
		}
		add->run(lines[i]);
	}

	sort(members.begin(), members.end(), [](const member& e1, const member& e2) { return (e1.employeeNum < e2.employeeNum); });

	string outputresult;
	for (int i = pos; i < lines.size(); i++) {
		const string value = para->getCMD(lines[i]);
		const auto item = cmdmap.find(value);
		if ((item == cmdmap.end()) || (item->second == nullptr))
			return 	EXIT_FAILURE;
		outputresult += item->second->run(lines[i]);
	}

	ofstream outputfile;
	outputfile.open(argv[2]);
	outputfile << outputresult;
	outputfile.close();

	delete para;
	return EXIT_SUCCESS;
}