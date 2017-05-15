/*
 * File name:		desertBar.c
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
 * Date:			7/15/2014
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

char printMainMenu();
char showToppingsMenu();
void makeProgresiveList(int list[], int size);
double calculateSubTotal(int list[], int size);
double makeCompiledList(int list[], int size);
char printVoidMenu();
int verifyForVoid(int list[], int size, char choice);
void printTotal(double subTotal);
char askNewOrder();

int main()
{
	char choice = 0;
	
	do
	{
		//variables for list and price totals
		int list[SIZE] = { 0 }, listNumber = 0;
		double subTotal = 0.0;
		
		printf("Welcome to The Rusty Spoon!\n");
		printf("May I take your order please?\n\n");
		
		do
		{   //list Menu and Price
			choice = printMainMenu();
			
			switch (choice)
			{
				case '1':		//Squid Steak
					printf("\nYou entered Squid Steak");
					list[listNumber] = 1;
					listNumber++;
					break;
				case '2':		//Tomato Salad
					printf("\nYou entered Tomato Salad");
					list[listNumber] = 2;
					listNumber++;
					break;
				case '3':		//Chicken Caesar
					printf("\nYou entered Chicken Caesar");
					list[listNumber] = 3;
					listNumber++;
					break;
				case '4':		//Linguine Ragu
					printf("\nYou entered Linguine Ragu");
					list[listNumber] = 4;
					listNumber++;
					calculateSubTotal(list, SIZE);
					
					do
					{	//Second Menu Toppings
						choice = showToppingsMenu();
						
						
						switch (choice)
						{
							case '1':
								list[listNumber] = 6;
								listNumber++;
								printf("Mushrooms have been added\n");
								break;
							case '2':
								list[listNumber] = 7;
								listNumber++;
								printf("Bacon have been added\n");
								break;
							case '3':
								list[listNumber] = 8;
								listNumber++;
								printf("Cheddar has been added\n");
								break;
							case 'x':
							case 'X':
								choice = 'x';
								break;
							default:
								printf("\tERROR: That is not a choice!!\n\n");
						}
						if (choice != 'x')
							calculateSubTotal(list, SIZE);
					}
					while (choice != 'x');
					choice = '4';
					break;
				case '5':		//Orlando Burger
					printf("\nYou entered Orlando Burger");
					list[listNumber] = 5;
					listNumber++;
					calculateSubTotal(list, SIZE);
					do
					{	//Second Menu Toppings
						choice = showToppingsMenu();
						
						switch (choice)
						{
							case '1':
								list[listNumber] = 6;
								listNumber++;
								printf("Mushrooms have been added\n");
								break;
							case '2':
								list[listNumber] = 7;
								listNumber++;
								printf("Bacon have been added\n");
								break;
							case '3':
								list[listNumber] = 8;
								listNumber++;
								printf("Cheddar has been added\n");
								break;
							case 'x':
							case 'X':
								choice = 'x';
								break;
							default:
								printf("\tERROR: That is not a choice!!\n\n");
						}
						if (choice != 'x')
							calculateSubTotal(list, SIZE);					}
					while (choice != 'x');
					choice = '5';
					break;
				case 'v':		//When Voiding an Item
				case 'V':
					do
					{
						choice = printVoidMenu();
						
						if (verifyForVoid(list, SIZE, choice))
						{
							switch (choice)
							{
								case '1':
									list[listNumber] = 11;
									listNumber++;
									break;
								case '2':
									list[listNumber] = 12;
									listNumber++;
									break;
								case '3':
									list[listNumber] = 13;
									listNumber++;
									break;
								case '4':
									list[listNumber] = 14;
									listNumber++;
									break;
								case '5':
									list[listNumber] = 15;
									listNumber++;
									break;
								case '6':
									list[listNumber] = 16;
									listNumber++;
									break;
								case '7':
									list[listNumber] = 17;
									listNumber++;
									break;
								case '8':
									list[listNumber] = 18;
									listNumber++;
									break;
								case 'l':	//To list items one at a time
								case 'L':
									makeProgresiveList(list, SIZE);
									break;
								case 'x':
								case 'X':
									choice = 'x';
									break;
								default:
									printf("\n\tERROR: That is not a choice!!\n");
							}
							if (choice != 'x')
								calculateSubTotal(list, SIZE);
						}
						else
						{
							printf("\nThat Item may not be removed because it has not been ordered.\n");
							calculateSubTotal(list, SIZE);
						}
					}
					while (choice != 'x');
					choice = '6';
					break;
				case 'l':	//To list items one at a time
				case 'L':
					makeProgresiveList(list, SIZE);
					break;
				case 'x':
				case 'X':
					choice = 'x';
					break;
				default:
					printf("\n\tERROR: That is not a choice!!\n");
			}
			calculateSubTotal(list, SIZE);
		}
		while (choice != 'x');
		choice = 0;
		
		subTotal = makeCompiledList(list, SIZE);   //Compiling items on order
		
		printTotal(subTotal);
		
		choice = askNewOrder();
		
	}
	while (choice != 'x');
	
	printf("\n\tGood-Bye!!\n\n");
	system("pause");
	return 0;
}

char printMainMenu()
{
	char choice;
	
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
	
	return choice;
}

char showToppingsMenu()
{
	char choice;
	
	printf("\n\nToppings, Pick twice for Extra!:\n\n");
	printf("1. Mushrooms\t\t$%.2lf\n", MUSHROOMS_PRICE);
	printf("2. Bacon\t\t$%.2lf\n", BACON_PRICE);
	printf("3. Cheddar Topping\t$%.2lf\n",CHEDDAR_PRICE);
	printf("\ne(X)it to main menu\n");
	printf("\nChoice of Topping: ");
	scanf(" %c", &choice);
	printf("\n");
	
	return choice;
}

void makeProgresiveList(int list[], int size)
{
	int i;
	printf("\nYour order so far is:\n\n");
	for (i = 0; i < size && list[i] != 0; i++)
	{
		switch (list[i])
		{
			case 1:
				printf("%i\tSquid Steak\t\t\t$%.2lf\n", i + 1, SQUID_STEAK_PRICE);
				break;
			case 2:
				printf("%i\tTomato Salad\t\t\t$%.2lf\n", i + 1, TOMATO_SALAD_PRICE);
				break;
			case 3:
				printf("%i\tChicken Caesar\t\t\t$%.2lf\n", i + 1, CHICKEN_CAESAR_PRICE);
				break;
			case 4:
				printf("%i\tLinguine Ragu\t\t\t$%.2lf\n", i + 1, LINGUINE_RAGU_PRICE);
				break;
			case 5:
				printf("%i\tOrlando Burger\t\t\t$%.2lf\n", i + 1, ORLANDO_BURGER_PRICE);
				break;
			case 6:
				printf("%i\t Mushrooms\t\t\t$%.2lf\n", i + 1, MUSHROOMS_PRICE);
				break;
			case 7:
				printf("%i\t Bacon\t\t\t\t$%.2lf\n", i + 1, BACON_PRICE);
				break;
			case 8:
				printf("%i\t Cheddar Topping\t\t$%.2lf\n", i + 1, CHEDDAR_PRICE);
				break;
			case 11:
				printf("%i\t-Squid Steak\t\t\t-$%.2lf\n", i + 1, SQUID_STEAK_PRICE);
				break;
			case 12:
				printf("%i\t-Tomato Salad\t\t\t-$%.2lf\n", i + 1, TOMATO_SALAD_PRICE);
				break;
			case 13:
				printf("%i\t-Chicken Caesar\t\t\t-$%.2lf\n", i + 1, CHICKEN_CAESAR_PRICE);
				break;
			case 14:
				printf("%i\t-Linguine Ragu\t\t\t-$%.2lf\n", i + 1, LINGUINE_RAGU_PRICE);
				break;
			case 15:
				printf("%i\t-Orlando Burger\t\t\t-$%.2lf\n", i + 1, ORLANDO_BURGER_PRICE);
				break;
			case 16:
				printf("%i\t -Mushrooms\t\t\t-$%.2lf\n", i + 1, MUSHROOMS_PRICE);
				break;
			case 17:
				printf("%i\t -Bacon\t\t\t-$%.2lf\n", i + 1, BACON_PRICE);
				break;
			case 18:
				printf("%i\t -Cheddar Topping\t\t\t-$%.2lf\n", i + 1, CHEDDAR_PRICE);
				break;
			default:
				break;
		}
	}
}

double calculateSubTotal(int list[], int size)
{
	int i;
	double subTotal;
	
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
	printf("\nYour total so far is: $%.2lf\n", subTotal);
	
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
	//Listing Items on order after compiling them
	printf("\nQty\t\tItem\t\t\t\tPrice\n\n");
	
	if (countSquidSteak != 0)
	{
		totalSquidSteakCost = countSquidSteak * SQUID_STEAK_PRICE;
		printf("%i\t\tSquid Steak\t\t\t$%.2lf\n", countSquidSteak, totalSquidSteakCost);
	}
	
	if (countTomatoSalad != 0)
	{
		totalTomatoSaladCost = countTomatoSalad * TOMATO_SALAD_PRICE;
		printf("%i\t\tTomato Salad\t\t\t$%.2lf\n", countTomatoSalad, totalTomatoSaladCost);
	}
	
	if (countChickenCaesar != 0)
	{
		totalChickenCaesarCost = countChickenCaesar * CHICKEN_CAESAR_PRICE;
		printf("%i\t\tChicken Caesar\t\t\t$%.2lf\n", countChickenCaesar, totalChickenCaesarCost);
	}
	
	if (countLinguineRagu != 0)
	{
		totalLinguineRaguCost = countLinguineRagu * LINGUINE_RAGU_PRICE;
		printf("%i\t\tLinguine Ragu\t$%.2lf\n", countLinguineRagu, totalLinguineRaguCost);
	}
	
	if (countOrlandoBurger != 0)
	{
		totalOrlandoBurgerCost = countOrlandoBurger * ORLANDO_BURGER_PRICE;
		printf("%i\t\tOrlando Burger\t\t$%.2lf\n", countOrlandoBurger, totalOrlandoBurgerCost);
	}
	
	if (countMushrooms != 0)
	{
		totalMushroomsCost = countMushrooms * MUSHROOMS_PRICE;
		printf("%i\t\tLettuce\t\t\t$%.2lf\n", countMushrooms, totalMushroomsCost);
	}
	
	if (countBacon != 0)
	{
		totalBaconCost = countBacon * BACON_PRICE;
		printf("%i\t\tBacon\t\t\t\t$%.2lf\n", countBacon, totalBaconCost);
	}
	
	if (countCheddar != 0)
	{
		totalCheddarCost = countCheddar * CHEDDAR_PRICE;
		printf("%i\t\tCheddar\t\t\t\t$%.2lf\n", countCheddar, totalCheddarCost);
	}
	
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
	return subTotal;
}

char printVoidMenu()
{
	char choice;
	
	printf("\nWhat would you like to remove?\n\n");
	printf("1. Squid Steak\t\t\t\t$%.2lf\n", SQUID_STEAK_PRICE);
	printf("2. Tomato Salad\t\t\t\t$%.2lf\n", TOMATO_SALAD_PRICE);
	printf("3. Chicken Caesar\t\t$%.2lf\n", CHICKEN_CAESAR_PRICE);
	printf("4. Linguine Ragu\t\t\t\t$%.2lf\n", LINGUINE_RAGU_PRICE);
	printf("5. Orlando Burger\t\t\t$%.2lf\n", ORLANDO_BURGER_PRICE);
	printf("6. Mushrooms\t\t\t\t\t\t$%.2lf\n", MUSHROOMS_PRICE);
	printf("7. Bacon\t\t\t\t\t$%.2lf\n", BACON_PRICE);
	printf("8. Cheddar\t\t\t$%.2lf\n",CHEDDAR_PRICE);
	printf("\n(L)ist Items\n");
	printf("e(X)it to previous menu\n");
	printf("\nChoice: ");
	scanf(" %c", &choice);
	
	return choice;
}

int verifyForVoid(int list[], int size, char choice)
{
	int i = 0, choiceValue = 0, countBacon = 0, countCheddar = 0;
	int countSquidSteak = 0, countTomatoSalad = 0, countChickenCaesar = 0;
	int countLinguineRagu = 0, countOrlandoBurger = 0, countLettuce = 0;
	
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
		default:
			choiceValue = 1;
			break;
	}
	return choiceValue;
}

void printTotal(double subTotal)
{
	double taxAmount, grandTotal;
	
	taxAmount = subTotal * TAX;
	grandTotal = taxAmount + subTotal;
	
	printf("\nYour sub total is \t\t\t$%.2lf\n", subTotal);
	printf("Your tax amount is \t\t\t$%.2lf\n", taxAmount);
	printf("Grand total is \t\t\t\t$%.2lf\n", grandTotal);
	
	printf("\n\tThank you for your order!\n\n");
	
}

char askNewOrder()
{
	char choice;
	do
	{
		printf("\n(N)ew Order\t\te(X)it Program\n");
		printf("\nChoice: ");
		scanf(" %c", &choice);
		
		switch (choice)	//Choice to start new order or finish with program
		{
			case 'n':
			case 'N':
				choice = 'n';
				system("clear");
				printf("\n\n\tNew Order\n\n");
				break;
			case 'x':
			case 'X':
				choice = 'x';
				printf("\tClosing program!!\n");
				break;
			default:
				printf("\tERROR: that is not a choice\n");
		}
		
	}
	while (choice != 'x' && choice != 'n');
	return choice;
}