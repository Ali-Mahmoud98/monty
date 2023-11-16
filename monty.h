#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct args_s - hold variables.
 * get the stream from the provided file.
 * @stream: pointer to the file.
 * @line: line of text read from stream.
 * Description: hold vars that will be uesd in different functions
 * of the project as well as vars that will require memory allocation
 * and freeing.
*/
typedef struct args_s
{
	char **line_strs; /* used to store tokens from line */
	char *line; /* used for getting line from file */
	unsigned int line_number; /* for tracking current line number */
	instruction_t *instruction; /* a valid instruction from a line */
	int n_tokens; /* number of tokens created from line */
	int isComment; /* tracks whether or not tokens start with # */
	FILE *stream; /* file stream */
	int stack_length; /* tracks the number of nodes in the stack */
	stack_t *stackHead; /* head/top of the stack
	(doubly linked lists of struct stack_s) */
	int stack; /* for switching between the use of stack and queue */
} args_t;

extern args_t *arguments;

/*Functions*/
/*Arguments functions handler*/
void validate_args(int argc);
void malloc_failed(void);
void init_args(void);
void read_failed(char *fileName);
/*Stream function handlers*/
void get_stream_failed(char *fileName);
void get_stream(char *fileName);
/*free functions*/
void free_args(void);
void closeStream(void);
void free_toks(void);
void free_all_args(void);
void free_stackHead(void);
void free_stack(stack_t *head);
/*tokenize function*/
void tokenize(void);
/*Instruction functions*/
void run_instruction(void);
void invalid_instruction(void);
void setStream(char *fileName);
void setInstruction(void);
/*stack funcs*/
void delete_stack_Top_node(void);
/*Checking funcs*/
int is_comment(void);
int is_number(char *);
/*push pall function*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
/*pint function*/
void pint(stack_t **stack, unsigned int line_number);
/*pop function*/
void pop(stack_t **stack, unsigned int line_number);
/*swap function*/
void swap(stack_t **stack, unsigned int line_number);
#endif
