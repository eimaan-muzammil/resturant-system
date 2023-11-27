#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Item {
    char name[50];
    int quantity;
    float price;
    float total;};

void printTitle() {
    printf("\t\t ============================\n");
    printf("\t\t |   Welcome to Restaurant  |\n");
    printf("\t\t ============================\n");
    printf("\t\t           |MENU|            \n");
    printf("\t\t           ======\n");
}

void printMenu() {
    printf("\n\n");
    printf("\n---------------------------------");
    printf("\n1. Kabab              -/70");
    printf("\n2. Tikka              -/60");
    printf("\n3. Chapati            -/10");
    printf("\n4. Naan               -/25");
    printf("\n5. Tea                -/35");
    printf("\n6. Karahi             -/1000");
    printf("\n7. Quurma             -/900");
    printf("\n8. Fish               -/800");
    printf("\n9. Finger fish        -/1000");
    printf("\n10. Mutton            -/1400");
    printf("\n---------------------------------");
}

void takeOrder(struct Item bill[], int* itemCount) {
    int option, qty;
    float price;
    
    printf("\nWhat would you like to order  ");
    scanf("%d", &option);
    
    if (option < 1 || option > 10) {
        printf("Invalid item number. Please enter a number between 1 and 10.\n");
        return; 
    }

    printf("Please enter the quantity of the desired meal: ");
    scanf("%d", &qty);

    switch (option) {
        case 1:
            strcpy(bill[*itemCount].name , "Kabab" );
            bill[*itemCount].price = 70.0;
            break;
        case 2:
            strcpy(bill[*itemCount].name, "Tikka");
            bill[*itemCount].price = 60.0;
            break;
        case 3:
        	strcpy(bill[*itemCount].name, "Chapati");
        	bill[*itemCount].price = 10.0;
        	break;
        case 4:
        strcpy(bill[*itemCount].name, "naan");
        bill[*itemCount].price = 25.0;
        break;
        case 5:
       	strcpy(bill[*itemCount].name, "tea");
       	bill[*itemCount].price = 35.0;
       	break;
       	case 6:
       	strcpy(bill[*itemCount].name, "karahi");
       	bill[*itemCount].price = 1000.0;
       	break;
       	case 7:
       	strcpy(bill[*itemCount].name, "quroma");
       	bill[*itemCount].price = 900.0;
       	break;
       	case 8:
       	strcpy(bill[*itemCount].name, "fish");
       	bill[*itemCount].price = 800.0;
       	break;
       	case 9:
       	strcpy(bill[*itemCount].name, "finger fish");
       	bill[*itemCount].price = 1000.0;
       	break;
        case 10:
            strcpy(bill[*itemCount].name, "Mutton");
            bill[*itemCount].price = 1400.0;
            break;
    }


    bill[*itemCount].quantity = qty;
    bill[*itemCount].total = qty * bill[*itemCount].price;

    (*itemCount)++;
}



void printBill(struct Item bill[], int itemCount) {
    printf("\t\n          \t--------");
    printf("\t\n          \t| BILL |");																	
    printf("\n---------------------------------------------");
    printf("\n|NAME|");
    printf("\t |QUANTITY|");
    printf("\t |PRICE|");
    printf("\t |TOTAL|");
    printf("\n---------------------------------------------");

    for (int i = 0; i < itemCount; i++) {
        printf("\n%s\t%d\t%.2f\t%.2f", bill[i].name, bill[i].quantity, bill[i].price, bill[i].total);
        
    }
}


void decisionMaking(struct Item bill[], int* itemCount) 
{
    char response[30];
    printf("Calculate bill (yes/no): ");
    scanf("%s", response);

    if (strcmp(response, "no") == 0) {
        printMenu();
        takeOrder(bill, itemCount);
        decisionMaking(bill, itemCount);
    } else if (strcmp(response, "yes") == 0) {
        printBill(bill, *itemCount);
    } else {
        printf("Invalid response\n");
    }
}
float calculateBillTotal(struct Item bill[], int itemCount) {
    float total = 0.0;

    for (int i = 0; i < itemCount; i++) {
        total += bill[i].total;
    }

    printf("\nTotal Cost: %.2f\n", total);
    return total;
}



int main() {
     struct Item bill[100];
    int itemCount = 0;

    printTitle();
    printMenu();
    takeOrder(bill, &itemCount);
    decisionMaking(bill, &itemCount);
    calculateBillTotal(bill, itemCount);

    return 0;
}

 

