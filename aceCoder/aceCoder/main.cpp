#include <iostream>
#include "pch.h"
#include "Add.h"
#include "delete.h"
#include "modifier.h"
#include "Sch.h"

int main()
{	
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	if (lines.size() == 0)
		return 	EXIT_FAILURE;

	Add* add = new Add(members);
	add->setParameterChecker(para);
	Del* del = new Del(members);
	Modifier* modifier = new Modifier(members);
	Sch* sch = new Sch(members);
	string outputresult;

	for (const auto& line : lines) {
		vector<string> values = para->parse(line);
		if (values[IDXCMD] == "ADD")
		{
			add->run(line);
		}
		else if (values[IDXCMD] == "DEL")
		{
			outputresult += del->run(line);
		}
		else if (values[IDXCMD] == "MOD")
		{
			outputresult += modifier->run(line);
		}
		else if (values[IDXCMD] == "SCH")
		{
			outputresult += sch->run(line);
		}
	}

	ofstream outputfile;
	outputfile.open(".\\output.txt");
	outputfile << outputresult;
	outputfile.close();

	delete add;
	delete del;
	delete para;
}