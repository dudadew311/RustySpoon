/*
 * File name:		theRustySpoonMenu.c
 * Name:			Raul Diaz
 * Course:			COP 1000 at Valencia College
 * Instructor:		David Stendel
 * Description:		Program will be able to act like a modern cash register providing
 *					menus to display different items and fuctions. User will be able to select
 *					an Item from the menu by its number, or an action by a letter. Cash
 *					register will keep track of the items ordered and display a consolidated
 *					list along with with the subTotal, tax and GrandTotal of the order. Program
 *					then ask the user if they would like to quit the program or to start a new order.
 * Team Members:	Raul Diaz
 *					Margarita Alvarez
 *					Philip Alberts
 *					Yanier Moldon
 *					Jose Solorzano
 * Date:			7/22/2014
 */

// Preprocessor Directives
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

// Constants
#define SIZE 100
#define TAX 0.075
#define SQUID_STEAK_PRICE 2.95
#define TOMATO_SALAD_PRICE 2.75
#define CHICKEN_CAESAR_PRICE 3.10
#define LINGUINE_RAGU_PRICE 2.50
#define ORLANDO_BURGER_PRICE 3.50
#define MUSHROOMS_PRICE 1.50
#define BACON_PRICE 0.75
#define CHEDDAR_PRICE 0.80

// Prototypes
int addMainItem(int [], int);
int addToppings(int [], int);
int askNewOrder();
double calculateSubTotal(int [], int);
double makeCompiledList(int [], int );
void makeProgresiveList(int [], int);
void printTotal(double);
void pyramid();
int removeItem(int [], int);

int main()
{
	int choice = 0;
	
	do
	{
		int list[SIZE] = {0}, lineNumber = 0;
		double subTotal = 0.0;
		
		printf("Welcome to the Rusty Spoon!\n\n");
		printf("What would you like to order?\n\n");
		do
		{
			choice = addMainItem(list, SIZE);
			
			if (choice < 97)
			{
				list[lineNumber++] = choice;
				calculateSubTotal(list,SIZE);
				
				if (choice >= 4 && choice <= 5)
				{
					do
					{
						choice = addToppings(list,SIZE);
						if (choice < 97)
						{
							list[lineNumber++] = choice;
						}
						calculateSubTotal(list, SIZE);
					}
					
					while (choice != 99);
					choice = 4;
				}
			}
			else
			{
				switch (choice)
				{
					case 97:
						do
						{
							choice = removeItem(list, SIZE);
							
							if (choice < 97)
							{
								list[lineNumber++] = choice;
							}
							calculateSubTotal(list,SIZE);
						}
						while (choice != 99);
						choice = 97;
						break;
					case 98:
						calculateSubTotal(list,SIZE);
						break;
					case 99:
						break;
					default:
						printf("\n\tERROR: That is not a choice!!\n");
				}
			}
		}
		while (choice != 99);
		subTotal = makeCompiledList(list, SIZE);
		
		printTotal(subTotal);
		choice = askNewOrder();
	}
	while (choice != 99);
	
	pyramid();
	system("pause");
	return 0;
}

int addMainItem(int list[], int size)
{
	char choice;
	int item = 0;
	
	printf("\n\tMenu\n\n");
	printf("1. Squid Steak\t\t$%.2lf\n", SQUID_STEAK_PRICE);
	printf("2. Tomato Salad\t\t$%.2lf\n", TOMATO_SALAD_PRICE);
	printf("3. Chicken Caesar\t$%.2lf\n", CHICKEN_CAESAR_PRICE);
	printf("4. Linguine Ragu\t$%.2lf\n", LINGUINE_RAGU_PRICE);
	printf("5. Orlando Burger\t$%.2lf\n", ORLANDO_BURGER_PRICE);
	printf("\n(V)oid an Entry\n");
	printf("(L)ist Order\n");
	printf("e(X)it\n");
	printf("\nChoice: ");
	scanf(" %c", &choice);  //choice determine what case happens
	
	switch (choice)
	{
		case '1':		//Squid Steak
			printf("\nYou entered Squid Steak\n");
			item = 1;
			break;
		case '2':		//Tomato Salad
			printf("\nYou entered Tomato Salad\n");
			item = 2;
			break;
		case '3':		//Chicken Caesar
			printf("\nYou entered Chicken Caesar\n");
			item = 3;
			break;
		case '4':		//Linguine Ragu
			printf("\nYou entered Linguine Ragu\n");
			item = 4;
			break;
		case '5':		//Orlando Burger
			printf("\nYou entered Orlando Burger\n");
			item = 5;
			break;
		case 'v':		//When Voiding an Item
		case 'V':
			item = 97;
			break;
		case 'l':	//To list items one at a time
		case 'L':
			item = 98;
			makeProgresiveList(list, size);
			break;
		case 'x':
		case 'X':
			item = 99;
			printf("Completing your order!\n\n");
			break;
		default:
			item = 98;
			printf("\n\tERROR: That is not a choice!!\n");
	}
return item;
}

int addToppings(int list[], int size)
{
	char choice;
	int item = 0;
	
	printf("\n\nToppings, Pick twice for Extra!:\n\n");
	printf("1. Mushrooms\t\t$%.2lf\n", MUSHROOMS_PRICE);
	printf("2. Bacon\t\t$%.2lf\n", BACON_PRICE);
	printf("3. Cheddar Topping\t$%.2lf\n",CHEDDAR_PRICE);
	printf("\ne(X)it to main menu\n");
	printf("\nChoice of Topping: ");
	scanf(" %c", &choice);
	
	switch (choice)
	{
		case '1':
			item = 6;
			printf("\nMushrooms have been added\n");
			break;
		case '2':
			item = 7;
			printf("\nBacon have been added\n");
			break;
		case '3':
			item = 8;
			printf("\nCheddar has been added\n");
			break;
		case 'x':
		case 'X':
			printf("Returning to Main Menu!\n\n");
			choice = 'x';
			item = 99;
			break;
		default:
			item = 98;
			printf("\n\tERROR: That is not a choice!!\n");
	}
	return item;
	
}

int askNewOrder()
{
	char choice;
	int selection;
	do
	{
		printf("\n(N)ew Order\tor\te(X)it Program\n");
		printf("\nChoice: ");
		scanf(" %c", &choice);
		
		switch (choice)	//Choice to start new order or finish with program
		{
			case 'n':
			case 'N':
				selection = 0;
				system("cls");
				printf("\n\n\tNew Order\n\n");
				break;
			case 'x':
			case 'X':
				selection = 99;
				printf("\tClosing program!!\n");
				break;
			default:
				selection = 1;
				printf("\tERROR: that is not a choice\n");
		}
	}
	while (selection != 99 && selection != 0);
	return selection;
}

double calculateSubTotal(int list[],int size)
{
	int i;
	double subTotal = 0.0;
	
	for (i = 0; i < size && list[i] != 0; i++)
	{
		switch (list[i])
		{
			case 1:
				subTotal += SQUID_STEAK_PRICE;
				break;
			case 2:
				subTotal += TOMATO_SALAD_PRICE;
				break;
			case 3:
				subTotal += CHICKEN_CAESAR_PRICE;
				break;
			case 4:
				subTotal += LINGUINE_RAGU_PRICE;
				break;
			case 5:
				subTotal += ORLANDO_BURGER_PRICE;
				break;
			case 6:
				subTotal += MUSHROOMS_PRICE;
				break;
			case 7:
				subTotal += BACON_PRICE;
				break;
			case 8:
				subTotal += CHEDDAR_PRICE;
				break;
			case 11:
				subTotal -= SQUID_STEAK_PRICE;
				break;
			case 12:
				subTotal -= TOMATO_SALAD_PRICE;
				break;
			case 13:
				subTotal -= CHICKEN_CAESAR_PRICE;
				break;
			case 14:
				subTotal -= LINGUINE_RAGU_PRICE;
				break;
			case 15:
				subTotal -= ORLANDO_BURGER_PRICE;
				break;
			case 16:
				subTotal -= MUSHROOMS_PRICE;
				break;
			case 17:
				subTotal -= BACON_PRICE;
				break;
			case 18:
				subTotal -= CHEDDAR_PRICE;
				break;
		}
	}
	printf("Your total is:\t$%.2lf\n", subTotal);
	
	return subTotal;
}

double makeCompiledList(int list[], int size)
{
	//varialbles for count of items
	int i;
	int countSquidSteak = 0, countTomatoSalad = 0, countChickenCaesar = 0;
	int countLinguineRagu = 0, countOrlandoBurger = 0, countMushrooms = 0;
	int countBacon = 0, countCheddar = 0;
	
	double totalSquidSteakCost = 0.0, totalTomatoSaladCost = 0.0, subTotal = 0.0;
	double totalChickenCaesarCost = 0.0, totalLinguineRaguCost = 0.0;
	double totalMushroomsCost = 0.0, totalBaconCost = 0.0;
	double totalCheddarCost = 0.0, totalOrlandoBurgerCost = 0.0;
	
	for (i = 0; i < size && list[i] != 0; i++)
	{
		switch (list[i])
		{
			case 0:
				break;
			case 1:
				countSquidSteak++;
				break;
			case 2:
				countTomatoSalad++;
				break;
			case 3:
				countChickenCaesar++;
				break;
			case 4:
				countLinguineRagu++;
				break;
			case 5:
				countOrlandoBurger++;
				break;
			case 6:
				countMushrooms++;
				break;
			case 7:
				countBacon++;
				break;
			case 8:
				countCheddar++;
				break;
			case 11:
				countSquidSteak--;
				break;
			case 12:
				countTomatoSalad--;
				break;
			case 13:
				countChickenCaesar--;
				break;
			case 14:
				countLinguineRagu--;
				break;
			case 15:
				countOrlandoBurger--;
				break;
			case 16:
				countMushrooms--;
				break;
			case 17:
				countBacon--;
				break;
			case 18:
				countCheddar--;
		}
	}
	printf("*****************************\n\n");
	subTotal = calculateSubTotal(list,size);

	//Listing Items on order after compiling them
	printf("\nQty\tItem\t\tPrice\n\n");
	
	if (countSquidSteak != 0)
	{
		totalSquidSteakCost = countSquidSteak * SQUID_STEAK_PRICE;
		printf("%i\tSquid Steak\t$%.2lf\n", countSquidSteak, totalSquidSteakCost);
	}
	
	if (countTomatoSalad != 0)
	{
		totalTomatoSaladCost = countTomatoSalad * TOMATO_SALAD_PRICE;
		printf("%i\tTomato Salad\t$%.2lf\n", countTomatoSalad, totalTomatoSaladCost);
	}
	
	if (countChickenCaesar != 0)
	{
		totalChickenCaesarCost = countChickenCaesar * CHICKEN_CAESAR_PRICE;
		printf("%i\tChicken Caesar\t$%.2lf\n", countChickenCaesar, totalChickenCaesarCost);
	}
	
	if (countLinguineRagu != 0)
	{
		totalLinguineRaguCost = countLinguineRagu * LINGUINE_RAGU_PRICE;
		printf("%i\tLinguine Ragu\t$%.2lf\n", countLinguineRagu, totalLinguineRaguCost);
	}
	
	if (countOrlandoBurger != 0)
	{
		totalOrlandoBurgerCost = countOrlandoBurger * ORLANDO_BURGER_PRICE;
		printf("%i\tOrlando Burger\t$%.2lf\n", countOrlandoBurger, totalOrlandoBurgerCost);
	}
	
	if (countMushrooms != 0)
	{
		totalMushroomsCost = countMushrooms * MUSHROOMS_PRICE;
		printf("%i\tMushrooms\t$%.2lf\n", countMushrooms, totalMushroomsCost);
	}
	
	if (countBacon != 0)
	{
		totalBaconCost = countBacon * BACON_PRICE;
		printf("%i\tBacon\t\t$%.2lf\n", countBacon, totalBaconCost);
	}
	
	if (countCheddar != 0)
	{
		totalCheddarCost = countCheddar * CHEDDAR_PRICE;
		printf("%i\tCheddar\t\t$%.2lf\n", countCheddar, totalCheddarCost);
	}
	printf("\n*****************************\n\n");
	return subTotal;
}

void makeProgresiveList(int list[], int size)
{
	int i;
	printf("\n*****************************\n\n");
	printf("Your order so far is:\n\n");
	for (i = 0; i < size && list[i] != 0; i++)
	{
		switch (list[i])
		{
			case 1:
				printf("%3i. Squid Steak\t$%.2lf\n", i + 1, SQUID_STEAK_PRICE);
				break;
			case 2:
				printf("%3i. Tomato Salad\t$%.2lf\n", i + 1, TOMATO_SALAD_PRICE);
				break;
			case 3:
				printf("%3i. Chicken Caesar\t$%.2lf\n", i + 1, CHICKEN_CAESAR_PRICE);
				break;
			case 4:
				printf("%3i. Linguine Ragu\t$%.2lf\n", i + 1, LINGUINE_RAGU_PRICE);
				break;
			case 5:
				printf("%3i. Orlando Burger\t$%.2lf\n", i + 1, ORLANDO_BURGER_PRICE);
				break;
			case 6:
				printf("%3i.  Mushrooms\t\t$%.2lf\n", i + 1, MUSHROOMS_PRICE);
				break;
			case 7:
				printf("%3i.  Bacon\t\t$%.2lf\n", i + 1, BACON_PRICE);
				break;
			case 8:
				printf("%3i.  Cheddar Topping\t$%.2lf\n", i + 1, CHEDDAR_PRICE);
				break;
			case 11:
				printf("%3i. -Squid Steak\t-$%.2lf\n", i + 1, SQUID_STEAK_PRICE);
				break;
			case 12:
				printf("%3i. -Tomato Salad\t-$%.2lf\n", i + 1, TOMATO_SALAD_PRICE);
				break;
			case 13:
				printf("%3i. -Chicken Caesar\t-$%.2lf\n", i + 1, CHICKEN_CAESAR_PRICE);
				break;
			case 14:
				printf("%3i. -Linguine Ragu\t-$%.2lf\n", i + 1, LINGUINE_RAGU_PRICE);
				break;
			case 15:
				printf("%3i. -Orlando Burger\t-$%.2lf\n", i + 1, ORLANDO_BURGER_PRICE);
				break;
			case 16:
				printf("%3i. -Mushrooms\t\t-$%.2lf\n", i + 1, MUSHROOMS_PRICE);
				break;
			case 17:
				printf("%3i. -Bacon\t\t-$%.2lf\n", i + 1, BACON_PRICE);
				break;
			case 18:
				printf("%3i. -Cheddar Topping\t-$%.2lf\n", i + 1, CHEDDAR_PRICE);
				break;
			default:
				break;
		}
	}
	printf("\n*****************************\n\n");

}

void printTotal(double amount)
{
	double taxAmount = 0.0, grandTotal = 0.0;
	
	taxAmount = amount * TAX;
	grandTotal = taxAmount + amount;
	
	printf("\nYour sub total is \t$%.2lf\n", amount);
	printf("Your tax amount is \t$%.2lf\n", taxAmount);
	printf("Grand total is \t\t$%.2lf\n", grandTotal);
	
	printf("\n\tThank you for your order!\n\n");
}

void pyramid()
{
	int height = 12, space = 0, stars, line;
	
	for (line = 0;line < height; line++)
	{
		while (space < height)
		{
			printf(" ");
			space++;
		}
		for (stars = 0;stars < line;stars++)
		{
			printf("$ ");
			space = 0;
		}
		printf("\n");
		space = line;
		stars = 0;
	}
}

int removeItem(int list[], int size)
{
	char choice = 0;
	int i, item = 0, choiceValue = 0, countBacon = 0, countCheddar = 0;
	int countSquidSteak = 0, countTomatoSalad = 0, countChickenCaesar = 0;
	int countLinguineRagu = 0, countOrlandoBurger = 0, countLettuce = 0;
	
	printf("\nWhat would you like to remove?\n\n");
	printf("1. Squid Steak\t\t$%.2lf\n", SQUID_STEAK_PRICE);
	printf("2. Tomato Salad\t\t$%.2lf\n", TOMATO_SALAD_PRICE);
	printf("3. Chicken Caesar\t$%.2lf\n", CHICKEN_CAESAR_PRICE);
	printf("4. Linguine Ragu\t$%.2lf\n", LINGUINE_RAGU_PRICE);
	printf("5. Orlando Burger\t$%.2lf\n", ORLANDO_BURGER_PRICE);
	printf("6. Mushrooms\t\t$%.2lf\n", MUSHROOMS_PRICE);
	printf("7. Bacon\t\t$%.2lf\n", BACON_PRICE);
	printf("8. Cheddar\t\t$%.2lf\n",CHEDDAR_PRICE);
	printf("\n(L)ist Items\n");
	printf("e(X)it to previous menu\n");
	printf("\nChoice to remove: ");
	scanf(" %c", &choice);
	
	for (i = 0; i < size && list[i] != 0; i++)
	{
		switch (list[i])
		{
			case 0:
				break;
			case 1:
				countSquidSteak++;
				break;
			case 2:
				countTomatoSalad++;
				break;
			case 3:
				countChickenCaesar++;
				break;
			case 4:
				countLinguineRagu++;
				break;
			case 5:
				countOrlandoBurger++;
				break;
			case 6:
				countLettuce++;
				break;
			case 7:
				countBacon++;
				break;
			case 8:
				countCheddar++;
				break;
			case 11:
				countSquidSteak--;
				break;
			case 12:
				countTomatoSalad--;
				break;
			case 13:
				countChickenCaesar--;
				break;
			case 14:
				countLinguineRagu--;
				break;
			case 15:
				countOrlandoBurger--;
				break;
			case 16:
				countLettuce--;
				break;
			case 17:
				countBacon--;
				break;
			case 18:
				countCheddar--;
		}
	}
	switch (choice)
	{
		case '1':
			if (countSquidSteak > 0)
				choiceValue = 1;
			break;
		case '2':
			if (countTomatoSalad > 0)
				choiceValue = 1;
			break;
		case '3':
			if (countChickenCaesar > 0)
				choiceValue = 1;
			break;
		case '4':
			if (countLinguineRagu > 0)
				choiceValue = 1;
			break;
		case '5':
			if (countOrlandoBurger > 0)
				choiceValue = 1;
			break;
		case '6':
			if (countLettuce > 0)
				choiceValue = 1;
			break;
		case '7':
			if (countBacon > 0)
				choiceValue = 1;
			break;
		case '8':
			if (countCheddar > 0)
				choiceValue = 1;
			break;
		case 'l':
		case 'L':
			choiceValue = 1;
			break;
		case 'x':
		case 'X':
			choiceValue = 1;
			break;
		default:
			break;
	}
	if (choiceValue)
	{
		switch (choice)
		{
			case '1':
				printf("1 Squid Steak was removed from your order!\n");
				item = 11;
				break;
			case '2':
				printf("1 Tomato Salad was removed from your order!\n");
				item = 12;
				break;
			case '3':
				printf("1 Chicken Caesar was removed from your order!\n");
				item = 13;
				break;
			case '4':
				printf("1 Linguine Ragu was removed from your order!\n");
				item = 14;
				break;
			case '5':
				printf("1 Orlando Burger was removed from your order!\n");
				item = 15;
				break;
			case '6':
				printf("An order of Mushrooms was removed from your order!\n");
				item = 16;
				break;
			case '7':
				printf("An order of Bacon was removed from your order!\n");
				item = 17;
				break;
			case '8':
				printf("An order of Cheddar was removed from your order!\n");
				item = 18;
				break;
			case 'l':	//To list items one at a time
			case 'L':
				makeProgresiveList(list, SIZE);
				item = 98;
				break;
			case 'x':
			case 'X':
				printf("Returning to previous Menu!\n");
				item = 99;
				break;
			default:
				printf("\n\tERROR: That is not a choice!!\n");
		}
	}
	else
	{
		printf("\nThat Item may not be removed because it has not been ordered.\n");
		item = 97;
	}
	
	return item;
}
