#include<bits/stdc++.h>
using namespace std;
int MAXIMUM =  17;
int NO_OF_ITER = 10;
typedef struct node{
    float data;
    struct node *next;
    struct node *prev;
}node;

node *insert_data(node *head, int data){
    node *new_node = new node();
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = data;

    if (head == NULL)
        head = new_node;
    else
    {
        node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }

    return head;
}

node *delete_node(node *head, float *data)
{
    node *temp = head;
    head = head->next;

    if (head != NULL && head->prev != NULL)
        head->prev = NULL;

    *data = temp->data;
    free(temp);

    return head;
}

void printLL(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout<<temp->data<<"->"<<setprecision(2)<<fixed<<endl;
        temp = temp->next;
    }
    printf("NULL\n");
}

float swap(float *a, float *b){
    float c = *a;
    *a = *b;
    *b = c;
}

node *insertion_sort(node *head, int *count)
{
    if (head != NULL)
    {
        node *ahead = head->next;

        while (ahead != NULL)
        {
            node *rev = ahead;

            while (rev->prev != NULL && rev->prev->data > rev->data)
            {
                swap(&(rev->data), &(rev->prev->data));
                rev = rev->prev;
                (*count)++;
            }
            ahead = ahead->next;
            (*count)++;
        }

        return head;
    }
    return NULL;
}

void bucket_sort(float *arr, int n, int *count)
{
    node *bins[n];

    for (int i = 0; i < n; i++)
        bins[i] = NULL;

    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        pos = floor(n * arr[i]);
        bins[pos] = insert_data(bins[pos], arr[i]);
    }

    for (int i = 0; i < n; i++)
        bins[i] = insertion_sort(bins[i], count);

    pos = 0;
    float temp;

    for (int i = 0; i < n; i++)
    {
        while (bins[i] != NULL)
        {
            bins[i] = delete_node(bins[i], &temp);
            arr[pos] = temp;
            pos++;
        }
    }
}

void file_arr(float *arr, int n){
    ifstream infile;
    infile.open("normalised uniform dist.txt");
    char a[10];
    infile >> a;
    float data;
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

int isSortedArray(float *arr, int n){
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

int main(){
    srand(time(0));
    ofstream outfile("bucket_uniform_obs.csv");
    outfile<<"num"<<","<<"avg_comp"<<","<<"avg_time"<<endl;
    int n = 2;
    for(int p = 0; p < MAXIMUM; p++){
        long sum_c = 0;
        float sum_t = 0;
        
        for(int i = 0; i < NO_OF_ITER; i++){
            float *array = new float[n];
                file_arr(array,n);
                
                
            
            for(int i = 0; i < n; i++){
                array[i] /= 100;
            }
            int c = 0;
            float start_time = clock();
            bucket_sort(array, n, &c);
            float end_time = clock();
            sum_c += c;

            float time_taken = (end_time - start_time) * 1000/CLOCKS_PER_SEC;
            sum_t += time_taken;

            if(isSortedArray(array, sizeof(array)/sizeof(array[0])) == 1)
            cout << "Num = "<< n << " Run = " << i+1 << " Comp = " << c << " Time = " << fixed << setprecision(4) << time_taken<<" ms "<<endl;
            else{
                cout<<" Array not sorted "<<endl;
                break;
            }
        }
            
        
        float avg_t = sum_t / NO_OF_ITER;
        long avg_count = sum_c / NO_OF_ITER;
        outfile<<n<<","<<avg_count<<","<<fixed<<setprecision(4) <<avg_t<<endl;
        n *= 2;
    }
    outfile.close();
    return 0;
}