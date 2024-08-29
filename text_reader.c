#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "text_reader.h"
#include "link_list.h"
#include "command_reader.h"
#define MAX_LINE 100//TODO delete after change to getline

void to_lower_case(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		str[i] = tolower(str[i]);
		i++;
	}
}

bool line_contain_experssion(char* line, char* expression_to_find) //check if expression is exist in the line
{
	char *char_ptr = strstr(line, expression_to_find);
	return (char_ptr != NULL);
}

void i_switch(line_node* head, char* expression_to_find)
{
	line_node* iter = head;
	char copy_line[MAX_LINE];
	to_lower_case(expression_to_find);
	while (iter != NULL)
	{
		//copy_line = (char*)malloc(strlen(iter->line));
		//free(copy_line);
		strcpy(copy_line, iter->line);
		to_lower_case(copy_line);
		if (line_contain_experssion(copy_line, expression_to_find))
		{
			iter->to_print = true;
		}
		else
		{
			iter->to_print = false;

		}
		iter = iter->next;
		//copy_line = 0;
	}
	return;
}



line_node* read_lines(char* fptr) {
	FILE *text_file;
	if (fptr != NULL)
	{
		text_file = fopen(fptr, "r");
	}
	else
	{
		text_file = stdin;
	}
	char* line = NULL;
	int number_of_lines = 0;
	int number_of_bytes = 0;
	line_node* list_line_head = NULL;//for create list
	if (text_file == NULL) /// if the file not open
	{
		printf("File did not open. Exit..\n");
		exit(-1);
	}

	while (NULL != fgets((line = (char*)malloc(MAX_LINE)), MAX_LINE, text_file))
	{
		line[strcspn(line, "\n")] = 0;
		list_line_head = add_to_list(list_line_head, line, number_of_lines,number_of_bytes);
		number_of_lines++;
		number_of_bytes += MAX_LINE;//TODO replace to size.
		free(line);
		line = NULL;
		
	}
	free(line);
	fclose(text_file);

	//_CrtDumpMemoryLeaks();


	return list_line_head;

}

void v_switch(line_node* head)
{
	line_node* temp_line_node = head;
	while (temp_line_node != NULL)
	{
		if (temp_line_node->to_print == true)
		{
			temp_line_node->to_print = false;
		}
		else
		{
			temp_line_node->to_print = true;
		}
		temp_line_node = temp_line_node->next;
	}
	return;
}


void expression_in_line(line_node* head, char* expression_to_find)
{
	line_node* temp_line_node = head;
	while (temp_line_node != NULL)
	{
		if (line_contain_experssion(temp_line_node->line, expression_to_find))
		{
			temp_line_node->to_print = true;
		}
		else
		{
			temp_line_node->to_print = false;

		}
		temp_line_node = temp_line_node->next;
	}
	return;
}

int c_switch_counter(head)
{
	line_node* temp_line_node = head;
	int counter_expression_in_line = 0;
	while (temp_line_node != NULL)
	{
		if (temp_line_node->to_print == true)
		{
			counter_expression_in_line++;
		}
		temp_line_node = temp_line_node->next;
	}
	return counter_expression_in_line;
}

void x_switch(line_node* head, char* expression_to_find)
{
	line_node* temp_line_node = head;
	while (temp_line_node != NULL)
	{
		if (temp_line_node->to_print)
		{
			if (strcmp(temp_line_node->line, expression_to_find) != 0)
			{
				temp_line_node->to_print = false;
			}
		}
		temp_line_node = temp_line_node->next;
	}
	return;
	
}


void execute_commands(line_node* head, CommandLine *commands)
{
	if (commands->i) {
		i_switch(head, commands->expression);
	}
	else
	{
		expression_in_line(head, commands->expression);
	}
	if (commands->v) {
		v_switch(head);
	}
//	if (commands->c) {
//		c_switch(head);
//	}                     ///////// implement in Print function
	if (commands->x) {
		x_switch(head, commands->expression);
	}
}




//TODO

//create new list.



