#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char *name;
    double price;
} product_t;

double getPtrPrice(product_t *ptrProd) {
   return (* ptrProd).price;
}

/*
 * @return: the price of the product prod
 */
double getPrice(product_t prod) {
    return prod.price;
}

/*
 * ptrProd != NULL
 * @name in ptrProd != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getPtrName(product_t *ptrProd) {
    return (* ptrProd).name;
}

int prodEquals(product_t *ptrProd, product_t prod) {
   if ( strcmp((* ptrProd).name, prod.name) != 0) return 0;
   if ( (* ptrProd).price != prod.price ) return 0;
   return 1;
}

char* getName(product_t prod) {
   char * strcopied = (char *)malloc(strlen(prod.name)+1);
   if ( strcopied == NULL) return NULL;
   strcpy(strcopied, prod.name);
   return strcopied;
}


int main()
{
    product_t myprod = {"My product", 100.50};
    double productprice = getPtrPrice(&myprod);
    printf("Product price %f\n", productprice);

    product_t myprod2 = {"My product", 100.50};
    int rc = prodEquals(&myprod, myprod2);
    printf("Return code %d\n", rc);


    char * prodname = getName(myprod );
    printf("Product name %s\n", prodname);

    return 0;
}
