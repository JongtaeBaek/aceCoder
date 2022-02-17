#include <iostream>
#include "pch.h"
#include "Add.h"
#include "delete.h"
#include "modifier.h"
#include "Sch.h"

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
	vector<string>lines = para->loadTxt(argv[1]);

	if (lines.size() == 0)
		return 	EXIT_FAILURE;

	Add* add = new Add(members);
	add->setParameterChecker(para);
	Del* del = new Del(members);
	Modifier* modifier = new Modifier(members);
	Sch* sch = new Sch(members);
	string outputresult;

	int pos = 0;
	for (int i = 0; i < lines.size(); i++) {
		const string value = para->getCMD(lines[i]);
		if (value != "ADD")
		{
			pos = i;
			break;
		}
		add->run(lines[i]);
	}
	// sort
	sort(members.begin(), members.end(), [](const member& e1, const member& e2) { return (e1.employeeNum < e2.employeeNum); });

	for (int i = pos; i < lines.size(); i++) {
		const string value = para->getCMD(lines[i]);
		if (value == "DEL")
		{
			outputresult += del->run(lines[i]);
		}
		else if (value == "MOD")
		{
			outputresult += modifier->run(lines[i]);
		}
		else if (value == "SCH")
		{
			outputresult += sch->run(lines[i]);
		}
	}

	ofstream outputfile;
	outputfile.open(argv[2]);
	outputfile << outputresult;
	outputfile.close();

	delete add;
	delete del;
	delete para;
	delete modifier;
	delete sch;
}