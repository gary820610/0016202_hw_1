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
	
	cout << endl << "進行運算所花費的時間：" << (END - START)<< " ms" << endl;
	
    system("pause");
}

void quicksort(int *data, int left, int right)
{
    int pivot, i, j;
    int pivot_1, pivot_2, pivot_3, n, m;
    int p1, p2, p3, pp;

    if (left >= right) { return; }			//if already in right sorted
    
	n= (right- left+1)%3;
	m= (right- left+1)/3;
	
	if(n== 0)
	{
		if((data[(left+left+m-1)/2]<= data[left+m-1]&& data[left]<= data[(left+left+m-1)/2])|| (data[(left+left+m-1)/2]<= data[left]&& data[left+m-1]<= data[(left+left+m-1)/2]))
		{
			p1= (left+left+m-1)/2;
			pivot_1 = data[(left+left+m-1)/2];
		}	
		else if((data[left+m-1]<= data[(left+left+m-1)/2]&& data[left]<= data[left+m-1])|| (data[left+m-1]<= data[left]&& data[(left+left+m-1)/2]<= data[left+m-1]))
		{
			p1= left+m-1;
			pivot_1 = data[left+m-1];
		}
   		else if((data[left]<= data[(left+left+m-1)/2]&& data[left+m-1]<= data[left])|| (data[left]<= data[left+m-1]&& data[(left+left+m-1)/2]<= data[left]))
   		{
   			p1= left;
   			pivot_1 = data[left];
		}
    	
    	if((data[(right+right-m+1)/2]<= data[right]&& data[right-m+1]<= data[(right+right-m+1)/2])|| (data[(right+right-m+1)/2]<= data[right-m+1]&& data[right]<= data[(right+right-m+1)/2]))
    	{
    		p3= (right+right-m+1)/2;
    		pivot_3 = data[(right+right-m+1)/2];
		}
		else if((data[right]<= data[(right+right-m+1)/2]&& data[right-m+1]<= data[right])|| (data[right]<= data[right-m+1]&& data[(right+right-m+1)/2]<= data[right]))
		{
			p3= right;
			pivot_3 = data[right];
		}
   		else if((data[right-m+1]<= data[(right+right-m+1)/2]&& data[right]<= data[right-m+1])|| (data[right-m+1]<= data[right]&& data[(right+right-m+1)/2]<= data[right-m+1]))
   		{
   			p3= right-m+1;
   			pivot_3 = data[right-m+1];
		}
    		
    	if((data[(left+right)/2]<= data[right-m]&& data[left+m]<= data[(left+right)/2])|| (data[(left+right)/2]<= data[left+m]&& data[right-m]<= data[(left+right)/2]))
    	{
    		p2= (left+right)/2;
    		pivot_2 = data[(left+right)/2];
		}
		else if((data[right-m]<= data[(left+right)/2]&& data[left+m]<= data[right-m])|| (data[right-m]<= data[left+m]&& data[(left+right)/2]<= data[right-m]))
		{
			p2= right-m;
			pivot_2 = data[right-m];
		}
	    else if((data[left+m]<= data[(left+right)/2]&& data[right-m]<= data[left+m])|| (data[left+m]<= data[right-m]&& data[(left+right)/2]<= data[left+m]))
	    {
	    	p2= left+m;
	    	pivot_2 = data[left+m];
		}
    
	}
	else if(n== 1)
	{
		if((data[(left+left+m-1)/2]<= data[left+m-1]&& data[left]<= data[(left+left+m-1)/2])|| (data[(left+left+m-1)/2]<= data[left]&& data[left+m-1]<= data[(left+left+m-1)/2]))
		{
			p1= (left+left+m-1)/2;
			pivot_1 = data[(left+left+m-1)/2];
		}
		else if((data[left+m-1]<= data[(left+left+m-1)/2]&& data[left]<= data[left+m-1])|| (data[left+m-1]<= data[left]&& data[(left+left+m-1)/2]<= data[left+m-1]))
		{
			p1= left+m-1;
			pivot_1 = data[left+m-1];
		}
   		else if((data[left]<= data[(left+left+m-1)/2]&& data[left+m-1]<= data[left])|| (data[left]<= data[left+m-1]&& data[(left+left+m-1)/2]<= data[left]))
   		{
   			p1= left;
   			pivot_1 = data[left];
		}
    	
    	if((data[(right+right-m+1)/2]<= data[right]&& data[right-m+1]<= data[(right+right-m+1)/2])|| (data[(right+right-m+1)/2]<= data[right-m+1]&& data[right]<= data[(right+right-m+1)/2]))
    	{
    		p3= (right+right-m+1)/2;
    		pivot_3 = data[(right+right-m+1)/2];
		}
		else if((data[right]<= data[(right+right-m+1)/2]&& data[right-m+1]<= data[right])|| (data[right]<= data[right-m+1]&& data[(right+right-m+1)/2]<= data[right]))
		{
			p3= right;
			pivot_3 = data[right];
		}
   		else if((data[right-m+1]<= data[(right+right-m+1)/2]&& data[right]<= data[right-m+1])|| (data[right-m+1]<= data[right]&& data[(right+right-m+1)/2]<= data[right-m+1]))
   		{
   			p3= right-m+1;
   			pivot_3 = data[right-m+1];
		}
    		
    	if((data[(left+right+1)/2]<= data[right-m]&& data[left+m+1]<= data[(left+right+1)/2])|| (data[(left+right+1)/2]<= data[left+m+1]&& data[right-m]<= data[(left+right+1)/2]))
    	{
    		p2= (left+right+1)/2;
    		pivot_2 = data[(left+right+1)/2];
		}
		else if((data[right-m]<= data[(left+right+1)/2]&& data[left+m+1]<= data[right-m])|| (data[right-m]<= data[left+m+1]&& data[(left+right+1)/2]<= data[right-m]))
		{
			p2= right-m;
			pivot_2 = data[right-m];
		}
	    else if((data[left+m+1]<= data[(left+right+1)/2]&& data[right-m]<= data[left+m+1])|| (data[left+m+1]<= data[right-m]&& data[(left+right+1)/2]<= data[left+m+1]))
	    {
	    	p2= left+m+1;
	    	pivot_2 = data[left+m+1];
		}
	}
	else if(n== 2)
	{
		if((data[(left+left+m-1)/2]<= data[left+m-1]&& data[left]<= data[(left+left+m-1)/2])|| (data[(left+left+m-1)/2]<= data[left]&& data[left+m-1]<= data[(left+left+m-1)/2]))
		{
			p1= (left+left+m-1)/2;
			pivot_1 = data[(left+left+m-1)/2];
		}
		else if((data[left+m-1]<= data[(left+left+m-1)/2]&& data[left]<= data[left+m-1])|| (data[left+m-1]<= data[left]&& data[(left+left+m-1)/2]<= data[left+m-1]))
		{
			p1= left+m-1;
			pivot_1 = data[left+m-1];
		}
   		else if((data[left]<= data[(left+left+m-1)/2]&& data[left+m-1]<= data[left])|| (data[left]<= data[left+m-1]&& data[(left+left+m-1)/2]<= data[left]))
   		{
   			p1= left;
   			pivot_1 = data[left];
		}
    	
    	if((data[(right+right-m+1)/2]<= data[right]&& data[right-m+1]<= data[(right+right-m+1)/2])|| (data[(right+right-m+1)/2]<= data[right-m+1]&& data[right]<= data[(right+right-m+1)/2]))
    	{
    		p3= (right+right-m+1)/2;
    		pivot_3 = data[(right+right-m+1)/2];
		}
		else if((data[right]<= data[(right+right-m+1)/2]&& data[right-m+1]<= data[right])|| (data[right]<= data[right-m+1]&& data[(right+right-m+1)/2]<= data[right]))
		{
			p3= right;
			pivot_3 = data[right];
		}
   		else if((data[right-m+1]<= data[(right+right-m+1)/2]&& data[right]<= data[right-m+1])|| (data[right-m+1]<= data[right]&& data[(right+right-m+1)/2]<= data[right-m+1]))
   		{
   			p3= right-m+1;
   			pivot_3 = data[right-m+1];
		}
    		
    	if((data[(left+right)/2]<= data[right-m-1]&& data[left+m+1]<= data[(left+right)/2])|| (data[(left+right)/2]<= data[left+m+1]&& data[right-m-1]<= data[(left+right)/2]))
    	{
    		p2= (left+right)/2;
    		pivot_2 = data[(left+right)/2];
		}
		else if((data[right-m-1]<= data[(left+right)/2]&& data[left+m+1]<= data[right-m-1])|| (data[right-m-1]<= data[left+m+1]&& data[(left+right)/2]<= data[right-m-1]))
		{
			p2= right-m-1;
			pivot_2 = data[right-m-1];
		}
	    else if((data[left+m+1]<= data[(left+right)/2]&& data[right-m-1]<= data[left+m+1])|| (data[left+m+1]<= data[right-m-1]&& data[(left+right)/2]<= data[left+m+1]))
	    {
	    	p2= left+m+1;
	    	pivot_2 = data[left+m+1];
		}
	}
	
    if((pivot_2<= pivot_3&& pivot_1<= pivot_2)|| (pivot_2<= pivot_1&& pivot_3<= pivot_2))
    {
    	pp= p2;
    	pivot = pivot_2;
	}
	else if((pivot_3<= pivot_2&& pivot_1<= pivot_3)|| (pivot_3<= pivot_1&& pivot_2<= pivot_3))
	{
		pp= p3;
		pivot = pivot_3;
	}	
    else if((pivot_1<= pivot_2&& pivot_3<= pivot_1)|| (pivot_1<= pivot_3&& pivot_2<= pivot_1))
    {
    	pp= p1;
    	pivot = pivot_1;
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
    
	if(pp== left&& j== pp)						//left=j=p<i
	{
		quicksort(data, i, right);
	}
	else if(pp== left&& j>pp)						//left=p<j<i
	{
		swap(&data[pp], &data[j]);
		quicksort(data, left, j - 1);
		quicksort(data, j + 1, right);
	}
	else if(pp> left&& pp< right&& j<pp&& i>pp)		//left ? j<p<i
	{
		quicksort(data, left, j);
		quicksort(data, i, right);
	}
	else if(pp> left&& pp< right&& j>pp)			//left<p<j<i
	{
		swap(&data[pp], &data[j]);
		quicksort(data, left, j - 1);
		quicksort(data, j + 1, right);
	}
	else if(pp> left&& pp< right&& i<pp)			//left?j<i<p
	{
		swap(&data[pp], &data[i]);
		quicksort(data, left, i-1);
		quicksort(data, i + 1, right);
	}
	else if(pp== right&& i>right)				//right=p<i
	{
		quicksort(data, left, j);
	}
	else if(pp== right&& i<pp)					//i<p=right
	{
		swap(&data[pp], &data[i]);
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

