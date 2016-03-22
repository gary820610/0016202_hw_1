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
    int i, j, data[10002];
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
	
	cout << endl << "進行運算所花費的時間：" << (END - START) << " ms" << endl;
	
    system("pause");
}

void quicksort(int *data, int left, int right)
{
    int pivot, i, j, p;

    if (left >= right) { return; }			//if already in right sorted

    if((data[(left+right)/2]<= data[right]&& data[left]<= data[(left+right)/2])|| (data[(left+right)/2]<= data[left]&& data[right]<= data[(left+right)/2]))
    {
    	p= (left+right)/2;
    	pivot = data[(left+right)/2];
	}
    	
	else if((data[right]<= data[(left+right)/2]&& data[left]<= data[right])|| (data[right]<= data[left]&& data[(left+right)/2]<= data[right]))
	{
		p= right;
		pivot = data[right];
	}
    	
    else if((data[left]<= data[(left+right)/2]&& data[right]<= data[left])|| (data[left]<= data[right]&& data[(left+right)/2]<= data[left]))
    {
    	p= left;
    	pivot = data[left];
	}
    	
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

        if (i >= j) { break; }
		
		swap(&data[i], &data[j]);			//swap
		
    }

	if(p== left&& j== p)						//left=j=p<i
	{
		quicksort(data, i, right);
	}
	else if(p== left&& j>p)						//left=p<j<i
	{
		swap(&data[p], &data[j]);
		quicksort(data, left, j - 1);
		quicksort(data, j + 1, right);
	}
	else if(p== (left+right)/2&& j>p)			//left<p<j<i
	{
		swap(&data[p], &data[j]);
		quicksort(data, left, j - 1);
		quicksort(data, j + 1, right);
	}
	else if(p== (left+right)/2&& j<p&& i>p)		//left ? j<p<i
	{
		quicksort(data, left, j);
		quicksort(data, i, right);
	}
	else if(p== (left+right)/2&& i<p)			//left?j<i<p
	{
		swap(&data[p], &data[i]);
		quicksort(data, left, i-1);
		quicksort(data, i + 1, right);
	}
	else if(p== right&& i>right)				//right=p<i
	{
		quicksort(data, left, j);
	}
	else if(p== right&& i<p)					//i<p=right
	{
		swap(&data[p], &data[i]);
		quicksort(data, left, i-1);
		quicksort(data, i + 1, right);
	}
	
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

