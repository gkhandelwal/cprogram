/* Written by Gaurav Khandelwal */
/* building and print all the words of trie */
/* Starting point of trie.. Done using Linked List */
/* This is just archive of programs which I code in my free time */
/* I don't take any responsibility of any code errors and other errors. Use it at your own risk */
/* Feedback and Errors from my code is always welcomed and I love to discuss about the problems */


#include<stdio.h>
#include<stdlib.h>
struct tri
{
	char data;
	struct tri *level;
	struct tri *next;
	int flag;
};
typedef struct tri trie;
trie *head=NULL;
void trieBuild(char *str)
{
	int i=0;
	trie *hop;
	trie *temptrie,*tra;
	int tempFlag;
	hop=head;
	while(*str)
	{
		//printf("%c",*str);
		tra = hop->next;
		tempFlag = 0;
		
		if(tra==NULL)
		{
			temptrie= (trie*)malloc(sizeof(trie));
			temptrie->next=NULL;
			temptrie->level=NULL;
			temptrie->flag=0;
			hop->next=temptrie;
			hop=temptrie;
			temptrie->data=*str;
			i++;
			str++;
		}
		else
		{
			while(tra!=NULL)
			{
				if(tra->data==*str)
				{
					hop = tra;
					tempFlag=1;
					break;
				}
				tra=tra->level;
			}
			if(tempFlag==0)
			{
							
				temptrie= (trie*)malloc(sizeof(trie));
				temptrie->next=NULL;
				temptrie->flag=0;
				temptrie->data = *str;
				temptrie->level=hop->next;
				hop->next=temptrie;
				hop=temptrie;
			}
			i++;
			str++;		
		}
		
		
	
	}
	hop->flag=1;
}



char arr[255];
int i=-1;
// printing all the available words from trie 
void print(trie *h)
{
	if(h==NULL)
	{	
		
		return;
	}
	arr[++i]=h->data;
	if(h->flag==1)
	{
		arr[++i]='\0';
		printf("\n word is : %s ", arr);
		i=i-2;
	}
	
	
	print(h->next);
	if(h->level==NULL)
	{
		arr[i]='\0';
		i--;
		
	}		
	print(h->level);
}
// Searching a particular word in a dictionary
int search(char *str)
{
	int flag=0;
	int eflag=0;;
	trie *c;
	c=head->next;
	while(*str)
	{	flag=0;
		while(c!=NULL)
		{
			if(c->data==*str)
			{
				flag=1;
				break;
			}
			c=c->level;
		}
		if(flag==0)
			return 0;
		eflag=c->flag;
		c=c->next;
		str++;
	}
	if(eflag)
		return 1;
	else
		return 0;
}
void main()
{
	head=(trie*)malloc(sizeof(trie));
	head->next=NULL;
	head->level=NULL;
	head->flag=0;
	trieBuild("abc");
	trieBuild("gaurav");
	trieBuild("hello");
	trieBuild("khandelwal");
	
	if(search("gh"))
		printf("\nfound\n");
	else
		printf("\nnot found\n");
	print(head->next);
}
