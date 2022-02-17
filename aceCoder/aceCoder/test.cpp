#include <iostream>
#include "pch.h"
#include "Add.h"
#include "delete.h"
#include "modifier.h"
#include "Sch.h"

TEST(DB_TEST, SAMPLE_TEST) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	ASSERT_NE(0, lines.size());

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

	vector<string>outputlines = para->loadTxt(".\\output.txt");
	vector<string>targetLines = para->loadTxt(".\\input\\output_20_20.txt");
	EXPECT_EQ(outputlines.size(), targetLines.size());
	
	int idx=0;
	for (const auto& target : targetLines) {
		EXPECT_EQ(target, outputlines[idx++]);
	}

	delete add;
	delete del;
	delete para;
	delete modifier;
	delete sch;
}


TEST(DB_TEST, SAMPLE_SORT_TEST) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_sort.txt");
	ASSERT_NE(0, lines.size());

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

	vector<string>outputlines = para->loadTxt(".\\output.txt");
	vector<string>targetLines = para->loadTxt(".\\input\\output_sort.txt");
	EXPECT_EQ(outputlines.size(), targetLines.size());

	int idx = 0;
	for (const auto& target : targetLines) {
		EXPECT_EQ(target, outputlines[idx++]);
	}

	delete add;
	delete del;
	delete para;
	delete modifier;
	delete sch;
}