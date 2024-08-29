#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "text_reader.h"
#include "command_reader.h"
#include "link_list.h"
#include <assert.h>
//#include <crtdbg.h>

#define MAX_LINE 100//TODO For windows

int main(int argc, char *argv[])
{
	CommandLine *commands;
	line_node *line_list;
	commands = init_command();
	//read_commands(commands, argc, argv);
	commands = read_command(argc, argv, commands);
	line_list = read_lines(commands->file_name);//TODO
	execute_commands(line_list, commands);

	line_node *temp = line_list;
	while (temp != NULL)
	{
		if (temp->to_print) {
			printf("%d , %s", temp->line_num, temp->line);
		}
		temp = temp->next;
	}
	free_link_list(line_list);
	//TODO create free function!!!
	return 0;

}


/*int main(int argc, char *argv[]) {

	FILE *text_file = NULL;
	char* experssion = NULL;
	char* line = NULL;
	bool expression_found = false;
	size_t size = 0;

	if (argc == 0) 
	{
		printf("Invalid arguments");
		return -1;
	}

	experssion = argv[1];
	assert(!strcmp(argv[1],"hays"));

	text_file = fopen(argv[2], "r");
	if (text_file == NULL) // if the file not open
	{
		printf("File did not open. Exit..\n");
		return -1;
	}

	//read_line(line, experssion, text_file);

	while (NULL != fgets(line = (char*)malloc(MAX_LINE) , MAX_LINE, text_file))//for windows NULL ; for linux EOF with getline function
	{
		expression_found = line_contain_experssion(line, experssion);
		if (expression_found == true)
		{
			printf("%s", line);
		}
		free(line);
		line = NULL;

	}
	free(line);
	fclose(text_file);
	return 0;

}*/

//_CrtDumpMemoryLeaks();