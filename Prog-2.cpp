#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

void quicksort(int *data, int left, int right);
void swap(int *a, int *b);
double START,END;

int main(void)
{
    int i, j, data[10001];
	char s[20];
	
    cout<< "input: "<< endl;
	
    scanf("%s", s);
 	j=0;
 	
 	while(s[0]!='x')
 	{
 		data[j]=atoi (s);					//let input be array
 		scanf("%s", s);						//get input
 		j++;
 	}
	
    START = clock();						//time start

    quicksort(data, 0, j-1);					//quicksort

    printf("\n result: ");
    for (i = 0; i < j; i++)
        printf("%d ", data[i]);

	END = clock();							//end
	
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	
    system("pause");
}

void quicksort(int *data, int left, int right)
{
    int pivot, i, j;

    if (left >= right) { return; }			//if already in right sorted

    if((data[(left+right)/2]<= data[right]&& data[left]<= data[(left+right)/2])|| (data[(left+right)/2]<= data[left]&& data[right]<= data[(left+right)/2]))
    	pivot = data[(left+right)/2];
	else if((data[right]<= data[(left+right)/2]&& data[left]<= data[right])|| (data[right]<= data[left]&& data[(left+right)/2]<= data[right]))
    	pivot = data[right];
    else if((data[left]<= data[(left+right)/2]&& data[right]<= data[left])|| (data[left]<= data[right]&& data[(left+right)/2]<= data[left]))
    	pivot = data[left];
    
    
	i = left;
    j = right;

    while (1)
    {
        while (i <= right)
        {
            if (data[i] > pivot)
            {
                break;
            }

            i = i + 1;
        }

        while (j > left)
        {
            if (data[j] < pivot)
            {
                break;
            }

            j = j - 1;
        }

        if (i > j) { break; }
		
		swap(&data[i], &data[j]);			//swap
		
        
    }
	
	if(pivot== data[(left+right)/2]&& j>(left+right)/2)
		swap(&data[(left+right)/2], &data[j]);

	else if(pivot== data[left])
		swap(&data[left], &data[j]);

	    
	else if(pivot== data[right]&& j>right)
		swap(&data[right], &data[j]);
	    

    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

