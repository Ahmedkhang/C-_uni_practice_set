#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char name[50];
    char author[50];
    int quantity;
};
char history[100][50];
int hcount = 0;
struct Book books[100];
int count = 0;

void addBook(){
	if(count >= 100){
		printf("\n\t\t\t\t\tLibrary is Full!!\n");
		return;
	}
	printf("\t\t\t\t\t===== Book Info =====\n\n");
	printf("\t\t\t\t\tEnter Book Id: ");
	scanf("%d",&books[count].id);
	
    if(books[count].id <= 0){
    printf("\n\t\t\t\t\tInvalid Book ID!\n");
    return;
}	

    for(int i = 0; i< count; i++){
    	if(books[i].id == books[count].id){
    		printf("\n\t\t\t\t\tBook ID Already Exists!!");
    		return;
		}
	}
	getchar();
	
	printf("\t\t\t\t\tEnter Book Name: ");
	fgets(books[count].name,50,stdin);
	books[count].name[strcspn(books[count].name, "\n")] = '\0';
	
	printf("\t\t\t\t\tEnter Author Name: ");
	fgets(books[count].author,50,stdin);
	books[count].author[strcspn(books[count].author, "\n")] = '\0';
	
	printf("\t\t\t\t\tEnter Book Quantity: ");
	scanf("%d",&books[count].quantity);
    if(books[count].quantity <= 0){
    printf("Invalid Book Quantity!\n");
    return;
}
    count++;
    
    printf("\n\t\t\t\t\t======= Book added Successfully! =======\n");

};


void displayBooks(){
	if(count == 0){
    printf("No books available!\n");
    return;
}
	for(int i = 0; i< count; i++){
	printf("\n\t\t\t\t\t Book Number %d",books[i].id);
	printf("\n\n\t\t\t\t\tbook_id: %d\n\t\t\t\t\tbook_name: %s\n\t\t\t\t\tauthor_name: %s\n\t\t\t\t\tbook_quantity: %d\n",books[i].id,books[i].name,books[i].author,books[i].quantity);	
	}
	
};


void searchBook()
{
    int book_id;
    int found = 0;

    printf("\t\t\t\t\tEnter Book ID: ");
    scanf("%d", &book_id);
    if(book_id <= 0){
    printf("Invalid Book ID!\n");
    return;
}
    for(int i = 0; i < count; i++)
    {
        if(book_id == books[i].id)
        {
            printf("\t\t\t\t\tBook ID: %d\n", books[i].id);
            printf("\t\t\t\t\tBook Name: %s\n", books[i].name);
            printf("\t\t\t\t\tAuthor Name: %s\n", books[i].author);
            printf("\t\t\t\t\tBook Quantity: %d\n", books[i].quantity);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\t\t\t\t\tBook Not Found!\n");
    }
}


void issueBook(){
  	int book_id;
  	int found = 0;
	printf("\t\t\t\t\tEnter Book ID: ");
	scanf("%d",&book_id);
	for(int i =0; i< count; i++){
  	 if(book_id == books[i].id){
  	 		if(books[i].quantity > 0){
  	 		  printf("\t\t\t\t\tBook Issued Successfully!");	  	 	
	          books[i].quantity--;
	          sprintf(history[hcount],"Issued Book ID %d",book_id);
	          hcount++;
		   }
		   else{
    			printf("Book is Out of Stock!\n");
}
		   found = 1;
		   break;

	}
     }
	 if(found == 0){
        printf("\t\t\t\t\tBook Not Found!\n");
    }	
};


void returnBook(){
	int book_id;
	int found = 0;
	printf("\t\t\t\t\tEnter Book ID: ");
	scanf("%d",&book_id);
	for(int i =0; i< count; i++){
		
  	 if(book_id == books[i].id){
//  	 	if(books[i].quantity > 0){
//  	 		
//		   }
  	 	printf("\t\t\t\t\tBook returned Successfully!!"); 	 	
	   books[i].quantity++;
	   sprintf(history[hcount],"Returned Book Id %d",book_id);
	   	found = 1;
	break;
	}

 }	
 if(found == 0)
    {
        printf("\t\t\t\t\tBook Not Found!\n");
    }
};


void saveToFile(){
    FILE *fp = fopen("books_library.txt", "w");

    for(int i = 0; i < count; i++){
        fprintf(fp, "%d | %s | %s | %d |\n",
          books[i].id,
          books[i].name,
          books[i].author,
          books[i].quantity);
    }
    fclose(fp);
}



void loadFromFile()
{
    FILE *fp = fopen("books_library.txt", "r");

    if(fp == NULL)
        return;

    count = 0;

    while(fscanf(fp, "%d | %s | %s | %d |\n",
        &books[count].id,
        books[count].name,
        books[count].author,
        &books[count].quantity) == 4) {
        count++;
    }

    fclose(fp);
}

void showHistory(){
    printf("\n\t\t\t\t\t======= History =======\n");
    if(hcount == 0){
        printf("\n\t\t\t\t\tNo history yet.\n");
        return;
    }
    for(int i = 0; i < hcount; i++){
        printf("\n\t\t\t\t\t- %s", history[i]);
    }
    printf("\n");
}


int main() {
    int choice;

    loadFromFile(); 

    while(1) {
        printf("\n\t\t\t\t\t======= LIBRARY SYSTEM =======\n\n");
        printf("\t\t\t\t\t1. Add Book\n");
        printf("\t\t\t\t\t2. Display Books\n");
        printf("\t\t\t\t\t3. Search Book\n");
        printf("\t\t\t\t\t4. Issue Book\n");
        printf("\t\t\t\t\t5. Return Book\n");
        printf("\t\t\t\t\t6. View History Log\n");
        printf("\t\t\t\t\t7. Save & Exit\n\n");

        printf("\t\t\t\t\tEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: showHistory();break;
            case 7: saveToFile(); exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
