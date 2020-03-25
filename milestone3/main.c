#include <stdio.h>
#include "header.h"

int main (void) {
    int i, n_customers;

    init_stock();

    printf("\nHow many customers do you want to handle?: ");
    scanf("%d", &n_customers);

    for (i=0; i < n_customers; i++) {
        handle_customer();
    }

    return 0;
}
