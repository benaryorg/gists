#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define BUF_SIZE 4096 //Should be longer than the longest word, else the word will get split.

struct node
{
	char *str;
	struct node *next;
};

//return value must be freed!
struct node *get_words_from_file(char *filename)
{
	FILE *file=fopen(filename,"r");
	if(!file)
	{
		return 0;
	}

	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *cur=first;
	struct node *n;

	char str[BUF_SIZE]={};
	
	char ch;

	while(!feof(file))
	{
		ch=fgetc(file);
		if(isgraph(ch))
		{
			strncat(str,&ch,1);
			if(strlen(str)>=BUF_SIZE-1)
			{
				assert(cur->str=(char *)malloc(BUF_SIZE));
				strcpy(cur->str,str);
				assert(n=(cur->next=(struct node *)malloc(sizeof(struct node))));
				n->next=cur;
				cur=n;
				*str=0;
			}
		}
		else
		{
writetonode:
			if(strlen(str))
			{
				assert(cur->str=(char *)malloc(strlen(str)+1));
				strcpy(cur->str,str);
				assert(n=(cur->next=(struct node *)malloc(sizeof(struct node))));
				n->next=cur;
				cur=n;
				*str=0;
			}
		}
	}

	if(*str)
	{
		goto writetonode;
	}

	fclose(file);

	cur->next=0;
	free(cur);
	return first;
}

/*
int main(void)
{
	struct node *tmp;
	struct node *n=get_words_from_file("main.c");
	assert(n);
	do
	{
		assert(n->str);
		puts(n->str);
		free(n->str);
		tmp=n->next;
		free(n);
		n=tmp;
	}
	while(n->next);

	return 0;
}
*/
