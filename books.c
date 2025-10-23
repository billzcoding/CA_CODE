#include <stdio.h>
#include <stdlib.h>

struct Book {
    int pages;
    float price;
};

int main() {
    struct Book *books = NULL;
    int i;
    int mostCostlyIndex = 0;

    books = (struct Book*)malloc(5 * sizeof(struct Book));

    if (books == NULL) {
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);
        
        printf("Enter number of pages: ");
        scanf("%d", &(books[i].pages));
        
        printf("Enter price: ");
        scanf("%f", &(books[i].price));

        if (books[i].price > books[mostCostlyIndex].price) {
            mostCostlyIndex = i;
        }
    }

    printf("\n--- Most Costly Book Record ---\n");
    printf("Book Number: %d\n", mostCostlyIndex + 1);
    printf("Pages: %d\n", books[mostCostlyIndex].pages);
    printf("Price: $%.2f\n", books[mostCostlyIndex].price);

    free(books);

    return 0;
}