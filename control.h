#ifndef _CONTROL_H_
#define _CONTROL_H_

#include "student.h"

#include<stdlib.h>
#include<cstring>

void add(int n, struct student *st)
{
	int i;

	for(i = 1; i <= n; i++)
	{
		printf("\n\n");
		printf("student number %d\n", i);    
		printf("\n--------------\n");
		import_std(&st[i]);
		/*printf("\n\tyou have entered:");
		export_std(&st[i]);*/
	}
}

void show(int n, struct student *st)
{
	int i;
	int num;

	for(i = 0; i < n; i++)
	{
		num = i+1;
		printf("\n\nstudent number %d", num);
		printf("\n--------------\n");
		export_std(&st[num]);
	}
}

void update(int n, struct student *st)
{
	int id;
	int i;
	int f = 0;

	printf("\nenter student id to update info: ");
	scanf("%d", &id);
	
	for(i = 0; i <= n; i++)
	{
		if(st[i].id.id_int == id)
		{
			f = 1;
			printf("\n\nupdate student's new informations: \n");
			printf("name: ");
			fflush(stdin);
			gets(st[i].name);
			printf("math: ");
			scanf("%f", &st[i].m);
			printf("phys: ");
			scanf("%f", &st[i].p);
			printf("chem: ");
			scanf("%f", &st[i].c);
		}
	}
	printf("\n\nrecord list updated\n");
	printf("-------------------\n");
	show(n, st);

	if(f == 0)
	{
		printf("\n\trecord not found!\n");
	}
}

void del(int &n, struct student *st)
{
	int id;
	int f = 0;
	int i;
	int j;
	struct student temp;

	printf("enter student id to delete record: ");	
	scanf("%d", &id);

	for(i = 0; i <= n; i++)
	{
		if(st[i].id.id_int == id)
		{
			f = 1;			
			
			for(j = i; j < n; j++)
			{
				temp = st[j];
				st[j] = st[j+1];
				st[j+1] = temp;
			}
			n--;
			printf("\nto fill: %p", &st[n+1].id);
			
			//to prevent memory leak
			memset((&st[n].c)+10/*size of c*/+1, 0, 76);
		}
	}

	printf("\n\nrecord list updated\n");
	printf("-------------------\n");
	show(n, st);

	if(f == 0){
		printf("record not found\n");
	}
}

void sort(int n, struct student *st)
{
	struct student temp;
	int i;
	int j;

	for(i = 0; i <= n; i++)
	{
		for(j = i + 1; j <= n; j++)
		{
			if(st[i].id.id_int > st[j].id.id_int)
			{
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
	show(n,st);
}

#endif