#include<stdio.h>
typedef struct node { //design a struct to store the coordinate, also use a mark to represent whether this node have used
	int x;
	int y;
	int z;
	int mark;
}node;
intxor (int a, int b)//Since xor operation in C can only use with 0 and 1, I write a function to operate the -1, this will be useful in the next step
{
	if (a < 0 && b < 0)
		return 2;
	else
		return ((!a && b) || (a && !b));
}
void main()
{
	int n, i, j, a = 1, b = 1, c = 1, count = 0; // varible a,b,c will be useful later, they are used to prevent output the surface repeatly
	printf("how many groups of true values do you want to input\n"); //tell how many true values
	scanf("%d", &n);
	if (n == 0) //0 means all false
		printf("empty");
	else if (n < 8)
	{
		printf("please input these items\n");
		node truth[8];//represent true value
		node rel[12];//represent the line, or to say which two points can be connected
		for (i = 0; i < n; i++)
		{
			truth[i].mark = 0;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &truth[i].x, &truth[i].y, &truth[i].z);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 1; i + j < n; j++)// match one by one
			{
				if (xor (truth[i].x, truth[i + j].x) + xor (truth[i].y, truth[i + j].y) == 0)//means x and y are same, they can be a line
				{
					rel[count].x = truth[i].x;//conect these 2 true values into a line
					rel[count].y = truth[i].y;
					rel[count].z = -1; // the different one will be -1
					truth[i].mark = 1;
					truth[i + j].mark = 1;// put the mark to 1, mark these 2 values
					count++;
				}
				else if (xor (truth[i].x, truth[i + j].x) + xor (truth[i].z, truth[i + j].z) == 0)//x and z, same work
				{
					rel[count].x = truth[i].x;
					rel[count].z = truth[i].z;
					rel[count].y = -1;
					truth[i].mark = 1;
					truth[i + j].mark = 1;
					count++;
				}
				else if (xor (truth[i].y, truth[i + j].y) + xor (truth[i].z, truth[i + j].z) == 0)//y and z, same work
				{
					rel[count].z = truth[i].z;
					rel[count].y = truth[i].y;
					rel[count].x = -1;
					truth[i].mark = 1;
					truth[i + j].mark = 1;
					count++;
				}

			}
		}
		for (i = 0; i < count; i++)
		{
			rel[i].mark = 0; //initialization of line's mark
		}
		for (i = 0; i < count; i++)
		{
			for (j = 1; j + i < count; j++)
			{
				if (xor (rel[i].x, rel[i + j].x) == 2)//check if they can be a surface(possible) same position has a -1;
				{
					if (rel[i].y == rel[i + j].y)//check if they are same, they can be a surface
					{
						rel[i].mark = rel[i + j].mark = 1; //mark it;
						if (rel[i].y && b) // use b to check whether the suface has been output;
						{
							printf("B+"); b = 0;
						}
						else if (rel[i].y == 0 && b)
						{
							printf("’B+"); b = 0;
						}
					}
					else if (rel[i].z == rel[i + j].z)
					{
						rel[i].mark = rel[i + j].mark = 1;
						if (rel[i].z && c)
						{
							printf("C+"); c = 0;
						}
						else if (rel[i].z == 0 && c)
						{
							printf("’C+"); c = 0;
						}
					}
				}
				if (xor (rel[i].y, rel[i + j].y) == 2)
				{
					if (rel[i].x == rel[i + j].x)
					{
						rel[i].mark = rel[i + j].mark = 1;
						if (rel[i].x && a)
						{
							printf("A+"); a = 0;
						}
						else if (rel[i].x == 0 && a)
						{
							printf("’A+"); a = 0;
						}
					}
					else if (rel[i].z == rel[i + j].z)
					{
						rel[i].mark = rel[i + j].mark = 1;
						if (rel[i].z && c)
						{
							printf("C+"); c = 0;
						}
						else if (rel[i].z == 0 && c)
						{
							printf("’C+"); c = 0;
						}
					}
				}
				if (xor (rel[i].z, rel[i + j].z) == 2)
				{
					if (rel[i].y == rel[i + j].y)
					{
						rel[i].mark = rel[i + j].mark = 1;
						if (rel[i].y && b)
						{
							printf("B+"); b = 0;
						}
						else if (rel[i].y == 0 && b)
						{
							printf("’B+"); b = 0;
						}
					}
					else if (rel[i].x == rel[i + j].x)
					{
						rel[i].mark = rel[i + j].mark = 1;
						if (rel[i].x && a)
						{
							printf("A+"); a = 0;
						}
						else if (rel[i].x == 0 && a)
						{
							printf("’A+"); a = 0;
						}
					}
				}
			}
		}
		for (i = 0; i < count; i++)//now output the line
		{
			if (rel[i].mark == 0)
			{
				if (rel[i].x == 1)
					printf("A");
				else if (rel[i].x == 0)
					printf("’A");
				if (rel[i].y == 1)
					printf("B");
				else if (rel[i].y == 0)
					printf("’B");
				if (rel[i].z == 1)
					printf("C");
				else if (rel[i].z == 0)
					printf("’C");
				printf("+");
			}
		}
		for (i = 0; i < n; i++) //now output the true value;
		{
			if (truth[i].mark == 0)
			{
				if (truth[i].x == 1)
					printf("A");
				else if (truth[i].x == 0)
					printf("’A");
				if (truth[i].y == 1)
					printf("B");
				else if (truth[i].y == 0)
					printf("’B");
				if (truth[i].z == 1)
					printf("C");
				else if (truth[i].z == 0)
					printf("’C");
				printf("+");
			}
		}
		printf("0"); //end the output;
	}
	else //8 means all true
		printf("All sitiuations are true");
	return 0;
}