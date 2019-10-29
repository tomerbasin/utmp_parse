#include "Utmp_Parse.h"

int main()
{
	UtmpParser *w = new UtmpParser(WTMP_FILE);
	w->modifier();
	return 1;
}