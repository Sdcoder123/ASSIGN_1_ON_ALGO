#include<bits/stdc++.h>
using namespace std;

#define MAXIMUM 15
#define NO_OF_ITER 20
void swap(short *a, short *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


void printArray(short array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int partition(short *array, int low, int high, int *count) {
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
            (*count)++;
        }
        else
        return left;
    }
}

int randomised_part(short *array, int initial, int final, int *count){
    int val = rand() % (final - initial) + initial;
    swap(&array[initial], &array[val]);
    return partition(array,initial,final,count);
}

void quickSort(short *array, int low, int high, int *count) {
  if (low < high) {
    int pos = randomised_part(array, low, high, count);
    quickSort(array, low, pos, count);
    quickSort(array, pos + 1, high, count);
  }
}

void file_array(short *arr, int n){
    ifstream infile;
    infile.open("normal_dist.csv");
    int data = 0;
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

int isSortedArray(short *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

int main(){
    srand(time(0));
    ofstream outfile("RQS normal datasets_obs.txt");
    outfile<<"num"<<","<<"avg_comp"<<","<<"avg_time"<<endl;
    int n = 2;
    for(int p = 0; p < MAXIMUM; p++){
        int sum_c = 0;
        float sum_t = 0;
        for(int i = 0; i < NO_OF_ITER; i++){
            short *array = new short[n];
            file_array(array,n);
            int c = 0;

            float start_time = clock();
            quickSort(array,0,n-1,&c);
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
        int avg_count = sum_c / NO_OF_ITER;
        outfile<<n<<","<<avg_count<<","<<fixed<<setprecision(4)<<avg_t<<endl;
        n *= 2;
    }
    outfile.close();
}