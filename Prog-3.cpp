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
	
	cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	
    system("pause");
}

void quicksort(int *data, int left, int right)
{
    int pivot, i, j;
    int pivot_1, pivot_2, pivot_3, n, m;
    int p1, p2, p3;

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
    		p3= (left+right)/2;
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

	cout<<"pivot1= "<<pivot_1<<" pivot2= "<<pivot_2<<" pivot3= "<<pivot_3<<endl;

    //pivot = data[left];
    /*if((data[(left+right)/2]<= data[right]&& data[left]<= data[(left+right)/2])|| (data[(left+right)/2]<= data[left]&& data[right]<= data[(left+right)/2]))
    	pivot = data[(left+right)/2];
	else if((data[right]<= data[(left+right)/2]&& data[left]<= data[right])|| (data[right]<= data[left]&& data[(left+right)/2]<= data[right]))
    	pivot = data[right];
    else if((data[left]<= data[(left+right)/2]&& data[right]<= data[left])|| (data[left]<= data[right]&& data[(left+right)/2]<= data[left]))
    	pivot = data[left];*/
    if((pivot_2<= pivot_3&& pivot_1<= pivot_2)|| (pivot_2<= pivot_1&& pivot_3<= pivot_2))
    	pivot = pivot_2;
	else if((pivot_3<= pivot_2&& pivot_1<= pivot_3)|| (pivot_3<= pivot_1&& pivot_2<= pivot_3))
    	pivot = pivot_3;
    else if((pivot_1<= pivot_2&& pivot_3<= pivot_1)|| (pivot_1<= pivot_3&& pivot_2<= pivot_1))
    	pivot = pivot_1;
    
    
    cout<<"pivot= "<<pivot<<endl;
    
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
		
		cout<<"swap1 "<<data[i]<<" "<<data[j]<<endl;
		swap(&data[i], &data[j]);			//swap
		
        
    }
	cout<<"data[j]= "<<data[j]<<"j= "<<j<<endl;
	cout<<"data[i]= "<<data[i]<<"i= "<<i<<endl;

	if(pivot== data[p1]&& j> p1)
	{
		cout<<"swap2 "<<data[p1]<<" "<<data[j]<<endl;
		swap(&data[p1], &data[j]);
		quicksort(data, left, j - 1);
    	quicksort(data, j + 1, right);
	}
	if(pivot== data[p1]&& j== p1)							//for j = left
	{
		cout<<"swap2 "<<data[p1]<<" "<<data[j]<<endl;
		swap(&data[p1], &data[j]);
		quicksort(data, left, j);
    	quicksort(data, j + 1, right);
	}
	else if(pivot== data[p1]&& i< p1)
	{
		cout<<"swap2 "<<data[p1]<<" "<<data[i]<<endl;
		swap(&data[p1], &data[i]);
		quicksort(data, left, i - 1);
   		quicksort(data, i + 1, right);
	}
	else if(pivot== data[p2]&& j> p2)
	{
		cout<<"swap2 "<<data[p2]<<" "<<data[j]<<endl;
		swap(&data[p2], &data[j]);
		quicksort(data, left, j - 1);
    	quicksort(data, j + 1, right);
	}
	else if(pivot== data[p2]&& j== p2)
	{
		cout<<"swap2 "<<data[p2]<<" "<<data[j]<<endl;
		swap(&data[p2], &data[j]);
		quicksort(data, left, j);
    	quicksort(data, j + 1, right);
	}
	else if(pivot== data[p2]&& i< p2)
	{
		cout<<"swap2 "<<data[p2]<<" "<<data[i]<<endl;
		swap(&data[p2], &data[i]);
		quicksort(data, left, i - 1);
   		quicksort(data, i + 1, right);
	}
	else if(pivot== data[p3]&& j> p3)
	{
		cout<<"swap2 "<<data[p3]<<" "<<data[j]<<endl;
		swap(&data[p3], &data[j]);
		quicksort(data, left, j - 1);
    	quicksort(data, j + 1, right);
	}
	else if(pivot== data[p3]&& j== p3)
	{
		cout<<"swap2 "<<data[p3]<<" "<<data[j]<<endl;
		swap(&data[p3], &data[j]);
		quicksort(data, left, j);
    	quicksort(data, j + 1, right);
	}
	else if(pivot== data[p3]&& i< p3)
	{
		cout<<"swap2 "<<data[p3]<<" "<<data[i]<<endl;
		swap(&data[p3], &data[i]);
		quicksort(data, left, i - 1);
   		quicksort(data, i + 1, right);
	}

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

