#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<stdio.h>
#include<cstring>
#include<stdlib.h>

struct student {
	//int id;
	union {
		int id_int;
		char id_str[30];
	} id;
	char name[50];
	float m;
	float c;
	float p;
	void (*import_std)(struct student*);
	void (*export_std)(struct student*);
};

void import_std(struct student* st)
{
	printf("\nid: ");
	scanf("%d", &st->id.id_int);
	printf("name: ");
	scanf("%s", &st->name);
	printf("math: ");
	scanf("%f", &st->m);
	printf("physics: ");
	scanf("%f", &st->p);
	printf("chemistry: ");
	scanf("%f", &st->c);   
}

void export_std(struct student* st)
{
	char buffer[10];
	int temp_to_hold_id_int = st->id.id_int;

	printf("\nid: %d (at %p)", st->id.id_int, &st->id);
	
	itoa(st->id.id_int, buffer, 10);
	strcpy(st->id.id_str,  "FUCK_YEAH_");
	printf("\nid in string: %s%s", st->id.id_str, buffer);
	st->id.id_int = temp_to_hold_id_int;
	//printf("\nid: %d | %s (at %p)", st->id.id_int, st->id.id_str, &st->id);
	
	printf("\nname: %s", st->name);
	printf("\nmath: %.2f", st->m);
	printf("\nphysics: %.2f", st->p);
	printf("\nchemistry: %.2f\n\n", st->c);     
}

#endif