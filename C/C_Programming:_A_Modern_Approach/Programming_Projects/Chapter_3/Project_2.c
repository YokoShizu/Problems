//	Write a program that formats product information entered by the user. A session with the
//	program should look like this:

//	Enter item number: 583
//	Enter unit price: 13.5
//	Enter purchase date (mm/dd/yyyy): 10/24/2010
//	Item			Unit			Purchase
//					Price			Date
//	583				$ 13.50			10/24/2010

//	The item number and date should be left justified; the unit price should be right justified.
//	Allow dollar amounts up to $9999.99. 
//	Hint: Use tabs to line up the columns.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int item_number = 0, month = 0, day = 0, year = 0;
	float price = 0.0f;

	printf("Enter item number: ");
	scanf("%d", &item_number);
	printf("Enter unit price: ");
	scanf("%f", &price);
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);
	
	printf("Item\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");
	printf("%d\t\t$ %.2f\t%d/%02d/%d\n", item_number, price, month, day, year);

	//	We can also use one printf for all text, but that will be less readable

	return 0;
}
