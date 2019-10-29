#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <utmp.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <ctime>
class WtmpParser
{
private:
	std::string _file_path = WTMP_FILE;
	std::vector<utmp*> _utmp_vector;
public:
	WtmpParser() {};
	WtmpParser(std::string wtmp_file_path);
	~WtmpParser();

	WtmpParser& get_content();
};

