#ifndef _VIEW_H_
#define _VIEW_H_

#include "student.h"
#include "control.h"

#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

void show_your_fucking_view()
{   
    printf("\nAnhNV StdMan in painful C++");
    printf("\n---------------------------\n\n");

	int n = 0;
	printf("\nnumber of records to add: ");
	scanf("%d", &n);

	student *st = (struct student*) malloc(n * sizeof(struct student));
	add(n, st);

	while(n < 32){
		printf("\n\n	---MENU---\n");
		printf(" 1-add new student records\n");
		printf(" 2-show all student records\n");
		printf(" 3-update a student info\n");
		printf(" 4-delete a student record\n");
		printf(" 5-sort records\n");
		printf(" 0-exit program\n\n");

		int fearture;
		printf("your choice: ");
		scanf("%d", &fearture);

		int c_delay = 1;
		int d_delay = 1;

		switch(fearture){
			/*case 1:
				printf("\nnumber of records to add: ");
				scanf("%d", &n);
				student *st = (struct student*) malloc(n * sizeof(struct student));
				add(n, st);
				break;*/
			case 2:
				show(n, st);
				break;
			case 3:
				update(n, st);
				break;
			case 4:
				del(n, st);
				break;
			case 5:
				sort(n, st);
				break;
			case 0:
				printf("\nwill now exit program...");
				for ( c_delay = 1 ; c_delay <= 32767 ; c_delay++ )
					for ( d_delay = 1 ; d_delay <= 32767 ; d_delay++ )
					{}
				exit(0);
			default:
				printf("invalid parameter. please choose one of following parameters..\n");
		}
	}
}

#endif