#include <iostream>
#include "pch.h"
#include "Add.h"
#include "ADDParmeterChecker.h"


int main()
{	
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	if (lines.size() == 0)
		return 	EXIT_FAILURE;

	Add* add = new Add(members);
	
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
		else{
			continue;
			/*TODO 
			* each command rresult accumulation
			*/
		}
	}

	/*TODO :fille save*/

	delete add;
	delete para;
}