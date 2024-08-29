#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "command_reader.h"

CommandLine* init_command()
{
	CommandLine* command = malloc(sizeof(CommandLine));
	command->NUM = 0;//TODO change the struct
	command->A = false;//
	command->b = false;
	command->c = false;
	command->i = false;
	command->n = false;
	command->v = false;
	command->x = false;
	command->E = false;
	command->expression = NULL;
	command->file_name = NULL;
	return command;
}

CommandLine* read_command(int argc,char* argv[], CommandLine* command)
{
	int i = 1;
	while (i < argc -1)
	{
		if (strcmp(argv[i], "-A") == 0) {
			command->A = true;
			command->NUM = atoi(argv[i + 1]);
			i++;
		}
		else if (strcmp(argv[i], "-b") == 0) {
			command->b = true;
		}
		else if (strcmp(argv[i], "-c") == 0) {
			command->c= true;
		}
		else if (strcmp(argv[i], "-i") == 0) {
			command->i= true;
		}
		else if (strcmp(argv[i], "-n") == 0) {
			command->n = true;
		}
		else if (strcmp(argv[i], "-v") == 0) {
			command->v = true;
		}
		else if (strcmp(argv[i], "-x") == 0) {
			command->x = true;
		}
		else if (strcmp(argv[i], "-E") == 0) {
			command->E = true;
			command->expression = argv[i+1];
			i++;
		}
		else {
			command->expression = argv[i];
		}
		i++;
		//TODO check if implement invalid case.
	}
	if (command->expression == NULL)
	{
		command->expression = argv[i];
	}
	else
	{
		command->file_name = argv[i];//TODO implement stdin case
	}

	return command;
}

