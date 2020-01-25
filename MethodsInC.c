#include <stdio.h>

void primeCheck();
int isPrime(int);
void binaryConversion();
void reverseNum();
int dayValueFromDate(int, int, int);
const char* dayFromNumber(int);
void dayOfTheWeek();

void main()
{
	int num = 0;
	printf("Welcome to the CSE220 number tool!\n");
	while (num != 1 && num != 2 && num != 3 && num != 4)
	{
		printf("Menu:\n1 – Prime Number Checker\n2 – Convert a Number to binary\n3 – Compute the reverse of a Number\n4 – Find the Day – Zeller’s Rule\n");
		printf("Choose an option: ");
		scanf("%d", &num);
		if (num == 1)
		{
			primeCheck();
		}
		else if (num == 2)
		{
			binaryConversion();
		}
		else if (num == 3)
		{
			reverseNum();
		}
		else if (num == 4)
		{
			dayOfTheWeek();
		}
		else
		{
			printf("Invalid character, try again.\n");
		}
	}
}

void primeCheck()
{
	int num;
	printf("\nEnter a number: ");
	scanf("%d", &num);
	int a = isPrime(num);
	if (a == 0)
	{
		printf("%d is not a prime number", num);
	}
	else
	{
		printf("%d is a prime number", num);
	}
}

int isPrime(int num)
{
	int i = 2;
	int count = 0;

	if (num == 0 || num == 1 || num % 2 == 0)
	{
		return 0;
	}

	else
	{
		while (i < num && count == 0)
		{
			if (num % i == 0)
			{
				count++;
			}
			i++;
		}
		if (count == 0)
		{
			return 1;
		}
		return 0;
	}
}

void binaryConversion()
{
	int num, temp;
	int count = 0;
	int arr[32] = { 0 };

	printf("\nEnter a number: ");
	scanf("%d", &num);
	temp = num;

	while (temp > 0)
	{
		arr[count] = temp % 2;
		temp /= 2;
		count++;
	}
	printf("%d in binary is: ", num);
	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d", arr[i]);
	}
}

void reverseNum()
{
	int num, temp;
	int count = 0;
	int arr[32] = { 0 };

	printf("Enter a number: ");
	scanf("%d", &num);
	temp = num;

	while (temp != 0)
	{
		arr[count] = temp % 10;
		temp /= 10;
		count++;
	}
	printf("%d reversed is: ", num);
	for (int i = 0; i <= count - 1; i++)
	{
		printf("%d", arr[i]);
	}
}

int dayValueFromDate(int date, int month, int year)
{
	date = (double) date;
	month = (double) month;
	year = (double) year;
	double century = year % 100;
	int day = (int)(date + (2.6 * month - 0.2) - (2 * century) + year + (year / 4) + (century / 4)) % 7; 
		return day;
}

const char* dayFromNumber(int num)
{
	///int count ==
	///char day[10];
	if (num == 0)
	{
		return "Sunday";
	}
	else if (num == 1)
	{
		return "Monday";
	}
	else if (num == 2)
	{
		return "Tuesday";
	}
	else if (num == 3)
	{
		return "Wednesday";
	}
	else if (num == 4)
	{
		return "Thursday";
	}
	else if (num == 5)
	{
		return "Friday";
	}
	else
	{
		return "Saturday";
	}
}

void dayOfTheWeek()
{
	int date, month, year;
	printf("Find the day of the week from any Gregorian calendar date!\n");
	printf("Enter the Month : ");
	scanf("%d", &month);
	printf("Enter the date:  ");
	scanf("%d", &date);
	printf("Enter the Year:  ");
	scanf("%d", &year);

	int day = dayValueFromDate(date, month, year);
	printf("The day of the week was: %s", dayFromNumber(day));
}
