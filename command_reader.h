#ifndef COMMAND_READER_H
#define COMMAND_READER_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct _CommandLine
{
	int NUM;
	bool A;
	bool b;
	bool c;
	bool i;
	bool n;
	bool v;
	bool x;
	bool E;
	char * expression;
	char *file_name;
}CommandLine;

CommandLine* init_command();
CommandLine* read_command(int argc, char* argv[], CommandLine* command);


#endif