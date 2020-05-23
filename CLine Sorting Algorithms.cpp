/*
Bryan Yam
April, 25, 2020 
The purpose of this program is to sort arrays using different sorting methods
using the command line. The program also shows the step by step process of how
each sorting methods operates.
*/

#include <iostream>

using namespace std;

//function declarations

void swap(int *a, int *b);
//PURPOSE: Swaps pointer values a and b
//INPUT: Uses variable location for a and b
//OUTPUT: No output

void bubble_sort(int arr[], int n);
//PURPOSE: Sorts array using a bubble sort method
//INPUT: Array to be sorted and the number of values in the array
//OUTPUT: No output

void selection_sort(int arr[], int n);
//PURPOSE: Sorts array using a selection sort method
//INPUT: Array to be sorted and the number of values in the array
//OUTPUT: No output

void insertion_sort(int arr[], int n);
//PURPOSE: Sorts array using a insertion sort method
//INPUT: Array to be sorted and the number of values in the array
//OUTPUT: No output

void merge(int arr[], int left, int mid, int right);
//PURPOSE: Divides array into left and right for sorting
//INPUT: Array to be sorted and the number of values in the array
//OUTPUT: No output

void merge_sort(int arr[], int left, int right);
//PURPOSE: Sorts array using a merge sort method
//INPUT: Array to be sorted,
//OUTPUT: No output

int partition(int arr[], int low, int high);
//PURPOSE: Sorts array using a merge sort method
//INPUT: 
//OUTPUT: No output

void quick_sort(int arr[], int low, int high);
//PURPOSE: Sorts array using a merge sort method
//INPUT: Array to be sorted, ,
//OUTPUT: No output

void print_array(int arr[], int n);
//PURPOSE: Prints array given
//INPUT: Array and array size
//OUTPUT: the array


void swap(int *a, int *b)
{
	int temp = *a; //sets temp value as a to allow a swap in data
	*a = *b;
	*b = temp;
}

void print_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " "; //cycles through array and prints each value with a space
	cout << endl;
}

void bubble_sort(int arr[], int n)
{
	bool swapped; 
	for (int i = 0; i < n; i++)
	{
		swapped = false;
		for (int j = 0; j < n - i - 1; j++)
		// j < n - i - 1 so loop doesn't check elements already in place
		{
			if (arr[j] > arr[j + 1]) //checks if left digit is greater in array
			{
				swap(&arr[j], &arr[j + 1]); // swaps values using their variable location
				swapped = true;
				print_array(arr, n); //visualzation of swap
			}
		}
		if (swapped = false)
		   break; //optimizes function by checking if array is already sorted
	}
}

void selection_sort(int arr[], int n)
{
	int index;
	for (int i = 0; i < n - 1; i++) //iterates through values, skips last value for comparison
	{
		index = i;
		for (int j = i + 1; j < n; j++) //checks values to the right of i
		{
			if (arr[j] < arr[index]) //finds smallest value to be moved to front
				index = j;
			swap(&arr[index], &arr[i]);
			print_array(arr, n); //visualization of swap
		}
	}
}

void insertion_sort(int arr[], int n)
{
	int j, k;
	for (int i = 1; i < n; i++)
	{
		j = i - 1; //first element to start
		k = arr[i]; // right of element j
		while (j >= 0 && arr[j] > k) //checks if next value is less than previous value
		{
			arr[j+1] = arr[j]; //assigns next value to previous value
			j = j - 1; //iterates j down
		}
		arr[j + 1] = k; //assigns previous value to next value
		print_array(arr, n); //visualization
	}
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1; //elements in left array
    int n2 = right - mid; //elements in right array

    int temp_l[n1]; //declare left and right arrays
    int temp_r[n2];

    for (i = 0; i < n1; i++) //fill arrays
        temp_l[i] = arr[left + i];
    cout << "Temporary left side array: " << endl;
    print_array(temp_l, n1);
    cout << endl;
    for (j = 0; j < n2; j++)
        temp_r[j] = arr[mid + j + 1];
    cout << "Temporary right side array: " << endl;
    print_array(temp_r, n2);
    cout << endl;

    i = 0; //initial index of left temp array
    j = 0; //initial index of right temp array
    k = left; //initial index of array

    while (i < n1 && j < n2) //checks if either side is full
    {
        if (temp_l[i] <= temp_r[j]) //if left element is greater than right element, insert left element into array
        {
            arr[k] = temp_l[i];
            i++;
            print_array(arr, k);
        } else {
            arr[k] = temp_r[j];
            j++;
            print_array(arr, k);
        }
        k++;
        print_array(arr, k);
    }

    while (i < n1) //fills remaining elements if n2 is full
    {
        arr[k] = temp_l[i];
        i++;
        k++;
        print_array(arr, right + 1);
    }

    while (j < n2) //fills remaining elements if n1 is full
    {
        arr[k] = temp_r[j];
        j++;
        k++;
        print_array(arr, right + 1);
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + (right - 1)) / 2; //finds middle of array
        merge_sort(arr, left, mid); //
        merge_sort(arr, (mid + 1), right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; //take last element as the pivot
	int temp = low - 1;
	for (int i = low; i <= high - 1; i++)
	{
		if (arr[i] < pivot) //if element is less than the pivot value, swap temp value with element (temp value starts as first element in the array)
		{
			temp++;
			swap(&arr[temp], &arr[i]);
			print_array(arr, high + 1);
		}
	}
	swap(&arr[temp + 1], &arr[high]); //swap value to the right of temp (since it is greater than the pivot), with the last element in the array
	print_array(arr, high + 1);
	return (temp + 1); //returns number of last element; the new pivot
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high) //always true for first instance as first values are 0 and n (n > 0)
	{
		int temp = partition(arr, low, high);
		quick_sort(arr, low, temp - 1);
		quick_sort(arr, temp + 1, high);
	}
}

int main()
{
	int max;
	char input;
	int size;
	cout << "How many values would you like to enter?" << endl; //obtains # of elements user wants to provide
	cin >> max;
	int array[max];
	int count = 0;
	int val;
	while (count < max) //continuously fills array until size it met
	{
		cout << "Please enter a number:" << endl;
		cin >> val;
		array[count] = val;
		count++; //increments until size is reached
	}	
	size = sizeof(array)/sizeof(array[0]); //size of array
	cout << "Which sort method would you like? \n"
	<< "type b for bubble, s for selection, i for insertion, m for merge, or q for quick." << endl;
	cin >> input;
	switch (input)
    {
        case 'b':
        	cout << "Original Array:" << endl;
        	print_array(array, size);
            bubble_sort(array, size);
            break;
        case 's':
 		    cout << "Original Array:" << endl;
        	print_array(array, size);
            selection_sort(array, size);
            break;
        case 'i':
        	cout << "Original Array:" << endl;
        	print_array(array, size);        	
            insertion_sort(array, size);
            break;
        case 'm':
        	cout << "Original Array:" << endl;
        	print_array(array, size);   
            merge_sort(array, 0, size - 1);
            break;
        case 'q':
        	cout << "Original Array:" << endl;
        	print_array(array, size);   
            quick_sort(array, 0, size - 1);
            break;
    }
    return 0;
}
