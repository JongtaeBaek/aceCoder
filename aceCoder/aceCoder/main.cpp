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

	for (const auto& line : lines) {
		const string value = para->getCMD(line);
		if (value == "ADD")
		{
			add->run(line);
		}
		else if (value == "DEL")
		{
			outputresult += del->run(line);
		}
		else if (value == "MOD")
		{
			outputresult += modifier->run(line);
		}
		else if (value == "SCH")
		{
			outputresult += sch->run(line);
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