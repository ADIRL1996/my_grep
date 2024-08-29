#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "text_reader.h"
#include "link_list.h"

//create new list.

line_node* create_line_node(char* line, int num_of_line,int num_byte)
{
	line_node* new_line_node = (line_node*)malloc(sizeof(line_node*));
	if (new_line_node != NULL)
	{
		new_line_node->line = malloc(sizeof(char)*strlen(line));
		//new_line_node->line = line/*(char*)malloc(sizeof(char)*strlen(line))*/;//TODO check if we need it
		strcpy(new_line_node->line, line);
		new_line_node->line_num = num_of_line;
		new_line_node->bytes_from_beginning = num_byte;
		new_line_node->to_print = false;
		new_line_node->next = NULL;
	}
	return new_line_node;
}

line_node* add_to_list(line_node* head,char* line, int num_of_line, int num_byte)
{
	line_node* iter = head;
	line_node* new_line_node = create_line_node(line, num_of_line, num_byte);

	if (head == NULL)
	{
		return new_line_node;
	}
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = new_line_node;
	return head;
}


void free_link_list(line_node* head)
{
	line_node* temp = head;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->line);
		free(temp);
	}
}

