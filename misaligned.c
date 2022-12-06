#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int ValidateColorFromPair(int index, const char* maj,const char* min);

int printColorMap() 
{
	int i = 0, j = 0;
	for(i = 0; i < 5; i++) 
	{
		for(j = 0; j < 5; j++) 
		{
			printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
		}
	}

return i * j;
}


int ValidateColorFromPair(int index, const char* maj, const char* min)
{
 int majindex = ((index))/5;
 int minindex = ((index))%5;
	if((majorColor[majindex] == maj) && (minorColor[minindex] == min))
	{
		/*20 is true*/
		return 20;
	}
	/*30 is false*/
	return 30;
}

int main() 
{
	int result = printColorMap();
	assert(result == 25);
	
	assert(ValidateColorFromPair(11, "Black","Orange") == 20 );
	assert(ValidateColorFromPair(12, "Black","Orange") == 30 );
	assert(ValidateColorFromPair(23, "Violet","Brown") == 20 );
	assert(ValidateColorFromPair(24, "Violet","Brown") == 30 );
	
	printf("All is well (maybe!)\n");
	return 0;
}
