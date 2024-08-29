#ifndef	LINK_LIST_H
#define LINK_LIST_H
#include <stdbool.h>


typedef struct line_node
{
	char* line;
	int line_num;
	int bytes_from_beginning;
	bool to_print;
	struct line_node *next;
} line_node;


line_node* add_to_list(line_node* head, char* line, int num_of_line, int num_byte);

void free_link_list(line_node* head);





#endif
