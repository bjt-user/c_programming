#include <stdio.h>
#include <stdlib.h> /*for EXIT_SUCCESS*/

#define SHOP_URL_MAXCHARS 20

/*function to delete the line break from a string
computers can't delete things they can only overwrite
so we make a new variable and set its adress to where
the character '\n' starts
that means that the first char pointer will be smaller
because the next variable starts at the location the
character '\n' was previously */
void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
        if(*s != '\n') {
            *p2++;
			*s++;
        } else {
            *s++;
        }
    }
    *p2 = '\0';
}

/*function to fill up shop_url with spaces until SHOP_URL_MAXCHARS is reached */
void fillup(char *shop_url) {
	int end_reached = 0;
	for(int i = 0; i < SHOP_URL_MAXCHARS; i++) {
		*shop_url++;
		if (*shop_url == '\0' | end_reached == 1) {
			*shop_url = ' ';
			end_reached = 1;
		}
	}
	*shop_url = '\0';
}

/* function to insert a record to the order table*/
void insert(void) {
	char shop_url[255];
	char order_date[255];
	FILE* table = fopen("C:\\Users\\BF\\Desktop\\Coding\\C\\orders\\orders.txt", "a");
	
	while(1) {
		printf("Geben Sie die Shop-URL ein: ");
		fgets(shop_url, sizeof(shop_url), stdin);
		
		//single quotes are for characters in C
		//double quotes are for strings in C
		if (*shop_url == '\n') {
			break;  //skip input process if nothing is entered
		}
		
		printf("Geben Sie das Bestelldatum ein: ");
		fgets(order_date, sizeof(order_date), stdin);
		
		if (*order_date == '\n') {
			break;
		}
		
		strip(shop_url);
		fillup(shop_url);
		strip(order_date);
		printf("%s | ", shop_url);
		printf("%s\n", order_date);
		fprintf(table, "%s; ", &shop_url);
		fprintf(table, "%s\n", &order_date);

	}
	
	fclose(table);
}

int main(void) {
	char option[8];
	printf("i to insert an order record\ns to show order table\n");
	fgets(option, sizeof(option), stdin);
	if (*option == 'i') {
		insert();
	} else {
		return EXIT_SUCCESS;
	}
	
	return EXIT_SUCCESS;
}
