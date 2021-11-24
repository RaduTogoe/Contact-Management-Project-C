#ifndef VAR
#define VAR
struct options
{
		char s[100];
};

struct node
{
		char first_name[30];
		char last_name[30];
		char phone_number[30];
		struct node *link;
};
#endif
