#pragma once
#include "pch.h"
#include "Sch.h"
#include "Add.h"
#include "modifier.h"
#include "delete.h"
#include "SchParameterChecker.h"
#include "ADDParmeterChecker.h"
#include "ModParameterChecker.h"

TEST(SCH_TEST, SCH_PARAM_TEST) {
	vector<member> members;
	ParameterChecker* schpara = new SchParameterChecker();
	vector<string>lines = schpara->loadTxt(".\\input\\input_search_test.txt");

	for (const auto& line : lines) {
		if (line.substr(0, 3) != "SCH") {
			continue;
		}
		vector<string> values = schpara->parse(line);
		ASSERT_TRUE(schpara->isValid(values));
	}

	delete schpara;
}

TEST(SCH_TEST, FUNC_TEST) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	ParameterChecker* modParamChecker = new ModParameterChecker();
	vector<string>lines = para->loadTxt(".\\input\\TC1_input.txt");
	ASSERT_NE(0, lines.size());

	Command* add = new Add(members, para);
	Command* del = new Del(members);
	Command* modifier = new Modifier(members, modParamChecker);
	Command* sch = new Sch(members);
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
	outputfile.open(".\\output_search.txt");
	outputfile << outputresult;
	outputfile.close();

	vector<string>outputlines = para->loadTxt(".\\output_search.txt");
	vector<string>targetLines = para->loadTxt(".\\input\\TC1_output.txt");
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