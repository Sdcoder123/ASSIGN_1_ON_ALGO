#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 20
#define NO_OF_ITER 16
void merge(int arr[], int left, int mid, int right, int *count){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *temp1 = new int[n1];
    int *temp2 = new int[n2];

    for(int i = 0; i < n1; i++){
        temp1[i] = arr[left + i];
    }

    for(int i = 0; i < n2; i++){
        temp2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while( i < n1 && j < n2){
        if(temp1[i] <= temp2[j]){
            arr[k] = temp1[i];
            i++;
        }
        else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
        (*count)++;
    }

    while(i < n1){
        arr[k] = temp1[i];
        i++;
        k++;
        (*count)++;
    }

    while(j < n2){
        arr[k] = temp2[j];
        j++;
        k++;
        (*count)++;
    }
}

void mergeSort(int arr[], int initial, int final, int *count){
    int mid;
    if(initial < final){
        mid = initial + (final - initial)/2;
        mergeSort(arr, initial, mid, count);
        mergeSort(arr, mid + 1, final, count);
        merge(arr, initial, mid, final, count);
    }
}

void file_array(int arr[], int n){
    ifstream infile;
    infile.open("uniform_dist.csv");
    int data = 0;
    infile >> data;
    for(int i = 0; i < n; i++){
        int skip = rand()%10;
        for(int j = 0; j < skip; j++){
            infile >> data;
        }
        infile >> data;
        arr[i] = data;
    }
    infile.close();
}

int isSortedArray(int *arr, int n){
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

int main(){

    srand(time(0));
    ofstream outfile("uniform_comparisons.txt");
    outfile<<"num"<<","<<"avg_comp"<<","<<"avg_time"<<endl;
    int n = 2;
    for(int p = 0; p < MAXIMUM; p++){
        long sum_c = 0;
        float sum_t = 0;
        for(int i = 0; i < NO_OF_ITER; i++){
            int *array = new int[n];
            file_array(array,n);
            int c = 0;

            float start_time = clock();
            mergeSort(array,0,n-1,&c);
            float end_time = clock();
            sum_c += c;

            float time_taken = (end_time - start_time) * 1000/CLOCKS_PER_SEC;
            sum_t += time_taken;

            if(isSortedArray(array, sizeof(array)/sizeof(array[0])) == 1)
            cout << "Num = "<< n << " Run = " << i+1 << " Comp = " << c << " Time = " <<setprecision(4)<<fixed<<time_taken<<" ms "<<endl;
            else{
                cout<<" Array not sorted "<<endl;
                break;
            }
        }
        float avg_t = sum_t / NO_OF_ITER;
        long avg_count = sum_c / NO_OF_ITER;
        outfile<<n<<","<<avg_count<<","<<fixed<<setprecision(4)<<avg_t<<endl;
        n *= 2;
    }
    outfile.close();

}
