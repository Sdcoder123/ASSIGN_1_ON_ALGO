#include<bits/stdc++.h>
using namespace std;

void insertion_sort(short arr[], int initial, int final)
{
    for (int i = initial; i <= final; i++)
    {
        int value = arr[i];
        int pos = i - 1;
        while (pos >= initial && arr[pos] > value)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = value;
    }
}

int findMedian(short arr[], int initial, int final)
{
    insertion_sort(arr, initial, final);
    int mid = (initial + final) / 2;
    return arr[mid];
}

int median_of_median(short arr[], int arr_size, int divide_size)
{
    if (arr_size < divide_size)
    {
        int median = findMedian(arr, 0, arr_size - 1);
        return median;
    }

    int no_full_group = arr_size / divide_size;
    int elements_in_last = arr_size % divide_size;

    int next_arr_size;

    if (elements_in_last == 0)
        next_arr_size = no_full_group;
    else
        next_arr_size = no_full_group + 1;

    short next_arr[next_arr_size];

    for (int i = 0; i < next_arr_size; i++)
    {
        if (i == next_arr_size -1)
            next_arr[i] = findMedian(arr, divide_size * i, arr_size - 1);
        else
            next_arr[i] = findMedian(arr, divide_size * i, divide_size * (i + 1) - 1);
    }

    return median_of_median(next_arr, next_arr_size,divide_size);
}

void swap(short *a, short *b)
{
    short c = *a;
    *a = *b;
    *b = c;
}

int partition(short *array, int low, int high) {
    int pivot = array[low];
    int left = low, right = high;
    while(true){
        while(array[left] < pivot){
            left++;
        }
        while(pivot < array[right]){
            right--;
        }
        if(array[left] == array[right]){
            if(left == right)
            return left;
            else
            right--;
        }
        else if(left < right){
            swap(&array[left],&array[right]);
            
        }
        else
        return left;
    }
}

int find_partition_size_MoM(short *arr, int arr_size, int divide_size)
{
    int val = median_of_median(arr, arr_size, divide_size);

    for (int i = 0; i < arr_size; i++)
        if (arr[i] == val)
        {
            swap(&arr[0], &arr[i]);
            return partition(arr, 0, arr_size - 1);
        }
}

void file_array(short *arr, int n){
    ifstream infile;
    infile.open("normal_dist.csv");
    int data;
    infile >> data;
    for(int i = 0; i < n; i++){
        int skip = rand()%10;
        for(int j = 0; j < skip; j++){
            infile >> data;
        }
        infile >> data;
        arr[i] =(short)data;
    }
    infile.close();
}

int main(){

    srand(time(0));

    const int max_arr_size = 50000;

    int divide_size = 5;
    int num_iter = 10;
    int part_size;
    float avg_part_size;
    ofstream outfile("mom normal obs.csv");
    outfile << "arr_size" << "," << "avg_partition_size" <<endl;
    for (int arr_size = 100; arr_size <= max_arr_size; arr_size += 100)
    {
        short *arr = new short[arr_size];
        avg_part_size = 0;

        for (int i = 0; i < num_iter; i++)
        {
            file_array(arr,arr_size);
            part_size = find_partition_size_MoM(arr,arr_size,divide_size);
            avg_part_size += part_size;
        }
        avg_part_size = avg_part_size / num_iter;
        cout << "Array Size " << arr_size << " Average Part Size " << fixed << setprecision(4) << avg_part_size << endl;
        outfile << arr_size << "," << fixed << setprecision(4) << avg_part_size << endl;
    }
    outfile.close();
    return 0;
}