#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 시공의 폭풍은 정말 최고야!!!
// 2020.11.10 - made by MtNight

void DrawStorm(double n);
void DrawStorm1(double x, double y, double n, double *check);
void DrawStorm2(double x, double y, double n, double *check);
void DrawStorm3(double x, double y, double n, double *check);

int main() 
{
	double n;
	scanf("%lf", &n);

	DrawStorm(n);

	return 0;
}

void DrawStar(double *c) 
{
	if (*c == 0) 
	{
		printf("*");
		(*c)++;
	}
}

double Rounds(double a) 
{
	return floor(a + 0.5);
}

int IsInsideCircle(double cx, double cy, double r, double x, double y)
{
	if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r)
	{
		return 1;
	}
	return 0;
}

void DrawStorm(double n)
{
	double x, y, check;
	for (y = 0; y <= n * 2; y++)
	{
		for (x = 0; x < n * 2; x += 0.5)
		{
			check = 0;
			if (y < n / 2) 
			{
				if (y == Rounds(-1 / sqrt(3)*(x - n)))
				{
					DrawStar(&check);
				}
				if (y == Rounds(1 / sqrt(3)*(x - n))) 
				{
					DrawStar(&check);
				}
			}
			else if (y < n * 3 / 2) 
			{
				if (x == Rounds(n * (2 - sqrt(3)) / 2))
				{
					DrawStar(&check);
				}
				if (x == Rounds(n * (2 + sqrt(3)) / 2))
				{
					DrawStar(&check);
				}
			}
			else 
			{
				if (y == Rounds(1 / sqrt(3)*(x + n * (2 * sqrt(3) - 1))))
				{
					DrawStar(&check);
				}
				if (y == Rounds(-1 / sqrt(3)*(x - n * (2 * sqrt(3) + 1))))
				{
					DrawStar(&check);
				}
			}

			DrawStorm1(x, y, n, &check);
			DrawStorm2(x, y, n, &check);
			DrawStorm3(x, y, n, &check);
			if (check == 0)
			{
				printf(" ");
			}
		}

		printf("\n");
	}
}
void DrawStorm1(double x, double y, double n, double *check)
{
	int isInCircle, isOutCircle;
	double a = n / 4;
	if (*check == 0)
	{
		isInCircle = IsInsideCircle(n, n, n * 3 / 4, x, y);
		isOutCircle = !IsInsideCircle(n - a + a / 2 + n * 3 / 8, n, (a + n * 3 / 4) / 2, x, y);

		if (isInCircle == 1 && isOutCircle == 1)
		{
			if (x >= n - a && y <= n)
			{
				DrawStar(check);
			}
		}
	}
}
void DrawStorm2(double x, double y, double n, double *check)
{
	int isInCircle, isOutCircle;
	double a = n / 4;
	if (*check == 0)
	{
		isInCircle = IsInsideCircle(n, n, n * 3 / 4, x, y);
		isOutCircle = !IsInsideCircle((n + a / 2) - ((a + 3 / 4 * n)), (n - sqrt(3) / 2 * a) + ((a + 3 / 4 * n)*sqrt(3)), (a + n * 3 / 4) / 2, x, y);

		if (isInCircle == 1 && isOutCircle == 1)
		{
			if (y >= -sqrt(3)*x + (1 + sqrt(3))*n && y >= 1 / sqrt(3)*(x + (sqrt(3) - 1)*n - 2 * a))
			{
				DrawStar(check);
			}
		}
	}
}
void DrawStorm3(double x, double y, double n, double *check)
{
	int isInCircle, isOutCircle;
	double a = n / 4;
	if (*check == 0)
	{
		isInCircle = IsInsideCircle(n, n, n * 3 / 4, x, y);
		isOutCircle = !IsInsideCircle((n + a / 2) - ((a + 3 / 4 * n)), (n + sqrt(3) / 2 * a) - ((a + 3 / 4 * n)*sqrt(3)), (a + n * 3 / 4) / 2, x, y);


		if (isInCircle == 1 && isOutCircle == 1)
		{
			if (y >= sqrt(3)*x + (1 - sqrt(3))*n && y <= -1 / sqrt(3)*(x - (1 + sqrt(3))*n - 2 * a))
			{
				DrawStar(check);
			}
		}
	}
}