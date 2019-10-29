#include "WtmpParser.h"
#include <fcntl.h>

int main()
{
	WtmpParser *w = new WtmpParser(WTMP_FILE);
	w->get_content();
	return 1;
}