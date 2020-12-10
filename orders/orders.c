/*under construction
entering data into the text file works (creates textfile if it doesn't exist)
quitting by pressing enter at the shop_url prompt*/

#include <stdio.h>
#include <stdlib.h> /*for EXIT_SUCCESS*/

/*function to delete the line break from a string
still trying to fully understand this one
(stackoverflow paste)*/
void strip(char *s) {
    char *p2 = s;
    while(*s != '\0') {
        if(*s != '\n') {
            *p2++ = *s++;
        } else {
            ++s;
        }
    }
    *p2 = '\0';
}

int main(void) {
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
		strip(order_date);
		printf("%s; ", shop_url);
		printf("%s\n", order_date);
		fprintf(table, "%s; ", &shop_url);
		fprintf(table, "%s\n", &order_date);

	}
	
	fclose(table);
	return EXIT_SUCCESS;
}
