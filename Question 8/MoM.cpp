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

int main()
{
    srand(time(0));

    int arr_size = 10000;
    int num_iter = 10;
    float start_t, end_t, t_taken;
    double avg_t;
    
    ofstream outfile("mom obs.csv");
    outfile << "div_size" << "," << "avg_time" <<endl;
    int divide_size;
    short arr[arr_size];
    for (int obs_counter = 0; obs_counter <= 1000; obs_counter++)
    {
        divide_size = 2 * obs_counter + 3;
        avg_t = 0;

        for (int i = 0; i < num_iter; i++)
        {
            for (int j = 0; j < arr_size; j++)
                arr[j] = rand() % 100;

            start_t = clock();
            int temp = median_of_median(arr, arr_size, divide_size);
            end_t = clock();

            t_taken = (end_t - start_t) * 1000 / CLOCKS_PER_SEC;
            avg_t += t_taken;
        }
        avg_t = avg_t/num_iter;
        cout << "Divide Size: " << setw(4) << divide_size << " Average Time: " << setw(3) << fixed << setprecision(4) << avg_t << " ms " << endl;
        outfile << divide_size << "," << fixed << setprecision(4) << avg_t << endl;
    }
    outfile.close();

    
    

    return 0;
}