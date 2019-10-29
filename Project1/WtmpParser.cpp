#include "WtmpParser.h"

WtmpParser::WtmpParser(std::string wtmp_file_path)
{
	_file_path = wtmp_file_path;
}

WtmpParser::~WtmpParser()
{
	for (int i = 0; i < _utmp_vector.size(); i++)
	{
		delete _utmp_vector[i];
	}
	_utmp_vector.clear();
}

WtmpParser& WtmpParser::get_content()
{
	FILE* f = fopen(_file_path.c_str(), "r");
	while (true)
	{
		utmp *utmp_member = new utmp();
		fread(utmp_member, sizeof(utmp), 1, f);
		if (utmp_member->ut_type == 0)
			break;
		_utmp_vector.push_back(utmp_member);
	}
	for (int i = 0; i < _utmp_vector.size(); i++)
	{
		if (_utmp_vector[i]->ut_type == 7)
		{
			time_t time = _utmp_vector[i]->ut_tv.tv_sec;
			std::cout << "User: " << _utmp_vector[i]->ut_user << " From: " << _utmp_vector[i]->ut_host << " AT: " << std::ctime(&time) << std::endl;
		}
	}
	fclose(f);
	return *this;
}