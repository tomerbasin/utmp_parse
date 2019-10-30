#include "Utmp_Parse.h"

int main()
{
	UtmpParser *w = new UtmpParser(WTMP_FILE, "l", "10.0.0.1");
	w->modifier();
	return 1;
}