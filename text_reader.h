#ifndef TEXT_READER_H
#define TEXT_READER_H
#include "link_list.h"
#include "command_reader.h"



bool line_contain_experssion(char* line, char* expression_to_find);//check if rellevant here
line_node* read_lines(char* fptr);
void execute_commands(line_node* head, CommandLine *commands);








#endif