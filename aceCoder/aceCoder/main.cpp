#include <iostream>
#include "pch.h"
#include "Add.h"
#include "ADDParmeterChecker.h"
#include "delete.h"
#include "modifier.h"

int main()
{	
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	if (lines.size() == 0)
		return 	EXIT_FAILURE;

	Add* add = new Add(members);
	Del* del = new Del(members);
	Modifier* modifier = new Modifier(members);

	ofstream outputfile;
	string outputresult;
	outputfile.open(".\\output.txt");


	for (const auto& line : lines) {
		vector<string> values = para->parse(line);
		if (values[IDXCMD] == "ADD")
		{
			if (!para->isValid(values))
				continue;
			const member mem = para->convert(values);
			if (!add->isValid(mem))
				continue;
			add->run(mem);
		}

		else if (values[IDXCMD] == "DEL")
		{
			outputresult += del->run(line);
			continue;
		}
		else if (values[IDXCMD] == "MOD")
		{
			outputresult += modifier->run(line);
			continue;
		}
	}

	/*TODO :fille save*/
	outputfile << outputresult;
	outputfile.close();

	delete add;
	delete del;
	delete para;
}