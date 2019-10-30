#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <utmp.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <fcntl.h>
#include <sys/stat.h>
#include <utime.h>
class UtmpParser
{
private:
	std::string _attacker_name = "root";
	std::string _attacker_address = "10.0.0.1";
	std::string _file_path = WTMP_FILE;
	std::vector<utmp*> _utmp_vector;
public:
	UtmpParser() {};
	UtmpParser(std::string file_path);
	UtmpParser(std::string file_path, std::string attcker_name);
	UtmpParser(std::string file_path, std::string attcker_name, std::string attacker_address);
	~UtmpParser();

	std::string get_attacker_name();
	std::string get_attacker_address();
	std::string get_utmp_file();
	std::vector<utmp*> get_utmp_vector();

	UtmpParser& set_attacker_name(std::string name);
	UtmpParser& set_attacker_address(std::string address);
	UtmpParser& set_utmp_file(std::string path);
	UtmpParser& set_utmp_vector(std::vector<utmp*> utmp_vector);


	std::vector<utmp*> get_content();
	UtmpParser& modifier();
};

