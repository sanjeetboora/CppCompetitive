/* Problem -  */
/* By Sanjeet Boora */
#include <stdio.h>

#define MODULO 1000000007

long fact[100002];

long p(long b, long pow)
{
	long num1 = 1;
	long num2 = b;
	while (pow)
	{
		if (pow % 2)
		{
			num1 = (num1 * num2) % MODULO;
		}
		num2 = (num2 * num2) % MODULO;
		pow /= 2;
	}
	return num1 % MODULO;
}
void start()
{
	long temp = 1;
	fact[0] = 1;
	for (int i = 1; i < 100001; i++)
	{
		temp = (temp * (long long)i) % MODULO;
		fact[i] = temp;
	}
}

long modinv(long b)
{
	return p(b, MODULO - 2);
}
void compute()
{
	long temp = 8;
	//fact[0] = 1;
	for (int i = 1; i < 100001; i++)
	{
		temp = (temp * (long long)i) % MODULO;
		fact[i] = temp;
	}
	//printf()
}

long comb(long one, long two)
{
	return (fact[one] *
	        modinv((fact[two] * fact[one - two]) % MODULO)) % MODULO;
}

void calc() {
	int num;
	long long int result;
	char ch;
	long long int i, j;
	long long int minimum1, maximum1;

	long long int a, b;

	scanf("%d", &num);

	scanf("%c", &ch);

	a = b = 0;

	for (i = 0; i < num; i++)
	{
		scanf("%c", &ch);
		if (ch == '1')
		{
			a++;
		}
	}

	scanf("%c", &ch);

	for (i = 0; i < num; i++)
	{
		scanf("%c", &ch);
		if (ch == '1')
		{
			b++;
		}
	}

	if (b > a)
	{
		maximum1 = a;
		a = b;
		b = maximum1;
	}

	minimum1 = a - b;

	if ((a + b) > num)
	{
		maximum1 = (2 * num) - (a + b);
	}
	else
	{
		maximum1 = a + b;
	}

	result = 0;

	for (i = minimum1; i <= maximum1; i += 2)
	{
		result = (result + comb(num, i)) % MODULO;
	}

	printf("%lld\n", result);
}

int main()
{
	start();

	int t;

	scanf("%d", &t);
	while (t--)
	{
		calc();
	}

	return 0;
}