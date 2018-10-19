// thread1.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct order order;

struct order
{
	int id;  // index of the order in the current shift
	long date;   // time when the order was created
	long delivery; // time when the order is asked to be delivered

	int pasta;      // type of pasta ordered (1 to 4)
	int cooking;	//1 = al dente, 2 = normal, 3 = fondantes
	int x, y;          // coordinate of the strainer used
	long straining_time;  //time when the pasta are cooked

	int sauce;	    // type of sauce ordered (1 to 4)

	order *next;
};

order* newOrder(order **orders, int Id, long Date, long Delivery, int Pasta, int Cooking, int X, int Y, long Straining_time, int Sauce)
{
	order* last = *orders;   //create a placeholder to move through the pile
	while (last->next != NULL) { // get to the last element of the pile

		last = last->next;
	}
	last->next = malloc(sizeof(order)); //set the adress of the "next" element of the struct to a new order

	if (!last->next) exit(EXIT_FAILURE);   //exit if the malloc didn't work

	last->next->id = Id;		//assign each member to its value
	last->next->date = Date;
	last->next->delivery = Delivery;
	last->next->pasta = Pasta;
	last->next->cooking = Cooking;
	last->next->x = X;
	last->next->y = Y;
	last->next->straining_time = Straining_time;
	last->next->sauce = Sauce;
	last->next->next = NULL;

}

void printOrder(order* order) // function to print the content of an order
{
	printf("*************************************************\n\n");
	printf("Order number : %d\n", order->id);
	printf("Was ordered at %ld and is supposed to arrive at %ld\n", order->date, order->delivery);
	printf("The pasta ordered was %d with a cooking of type %d\n", order->pasta, order->cooking);
	if (order->x == NULL) {
		printf("The cooking hasn't started yet\n");
	}
	else
	{
		printf("The cooking location is at (%d, %d) and will be done at %ld\n");
	}
	printf("The sauce ordered is %d\n", order->sauce);
	printf("\n*************************************************\n");
}

order* goToID(order** first, int Id)  // function to reach a specific order ID
{
	order* current = first;

	while (current->id != Id) {
		current = current->next;
	}
	return current;  // return the adress of the specific order
}

int main()
{
	order* orders = NULL;
	orders = malloc(sizeof(order));
	orders->next = NULL;
	orders->id = 1;

	newOrder(&orders, 2, 30, 40, 3, 1, NULL, NULL, NULL, 4);

	printOrder(orders);
	printOrder(goToID(orders, 2));



	system("pause");
	return 0;
}

