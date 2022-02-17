#include <iostream>
#include <algorithm>
#include "pch.h"
#include "Add.h"
#include "delete.h"
#include "modifier.h"
#include "Sch.h"
#include "FactoryCommand.h"

TEST(DB_TEST, SAMPLE_SORT_TEST) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_sort.txt");
	ASSERT_NE(0, lines.size());

	Command* add = new Add(members, para);
	Command* del = new Del(members);
	Command* modifier = new Modifier(members);
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

TEST(DB_TEST, SAMPLE_TEST_UPDATE) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	ASSERT_NE(0, lines.size());

	Command* add = new Add(members, para);
	Command* del = new Del(members);
	Command* modifier = new Modifier(members);
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
	outputfile.open(".\\output.txt");
	outputfile << outputresult;
	outputfile.close();

	vector<string>outputlines = para->loadTxt(".\\output.txt");
	vector<string>targetLines = para->loadTxt(".\\input\\output_20_20.txt");
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

TEST(DB_TEST, SAMPLE_TEST_FACTORY) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_20_20.txt");
	ASSERT_NE(0, lines.size());


	vector<string> commands = { "ADD","DEL","MOD" ,"SCH" };
	std::map<std::string, Command*> cmdmap;
	IFactoryCommand* factory = new FactoryCommand();
	for (const auto& cmd : commands) {
		cmdmap.insert(make_pair(cmd, factory->createCommand(cmd, members, para)));
	}

	int pos = 0;
	ASSERT_NE(cmdmap.find("ADD"), cmdmap.end());

	Command* add = cmdmap["ADD"];
	for (int i = 0; i < lines.size(); i++) {
		const string value = para->getCMD(lines[i]);
		if (value != "ADD") {
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
		ASSERT_NE(item, cmdmap.end());
		outputresult += item->second->run(lines[i]);
	}

	ofstream outputfile;
	outputfile.open(".\\output.txt");
	outputfile << outputresult;
	outputfile.close();

	vector<string>outputlines = para->loadTxt(".\\output.txt");
	vector<string>targetLines = para->loadTxt(".\\input\\output_20_20.txt");
	EXPECT_EQ(outputlines.size(), targetLines.size());

	int idx = 0;
	for (const auto& target : targetLines) {
		EXPECT_EQ(target, outputlines[idx++]);
	}

	delete para;
}

TEST(DB_TEST, SAMPLE_TEST_FACTORY_SORT) {
	vector<member> members;
	ParameterChecker* para = new AddParmeterChecker();
	vector<string>lines = para->loadTxt(".\\input\\input_sort.txt");
	ASSERT_NE(0, lines.size());


	vector<string> commands = { "ADD","DEL","MOD" ,"SCH" };
	std::map<std::string, Command*> cmdmap;
	IFactoryCommand* factory = new FactoryCommand();
	for (const auto& cmd : commands) {
		cmdmap.insert(make_pair(cmd, factory->createCommand(cmd, members, para)));
	}

	int pos = 0;
	ASSERT_NE(cmdmap.find("ADD"), cmdmap.end());

	Command* add = cmdmap["ADD"];
	for (int i = 0; i < lines.size(); i++) {
		const string value = para->getCMD(lines[i]);
		if (value != "ADD") {
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
		ASSERT_NE(item, cmdmap.end());
		outputresult += item->second->run(lines[i]);
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

	delete para;
}