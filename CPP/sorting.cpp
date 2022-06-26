#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<limits>
#include<climits>

using namespace std;

vector<int> arr(10,0);

class Sorting{
    public:
        void takeInput(){
            for(int i=0;i<10;++i){
                cin>>arr[i];
            }
        }
        
        // O(n^2)
        void bubbleSort(){
            for(int i=0;i<9;++i)
                for(int j=0;j<10-i-1;++j)
                    if(arr[j+1]<arr[j]) swap(arr[j],arr[j+1]);
        }
        
        // O(n^2)
        void insertionSort(){
            int current, j;
            for(int i=1;i<10;++i){
                current = arr[i];
                j=i-1;
                while(j>-1 && current<arr[j]){
                    arr[j+1]=arr[j];
                    j--;
                }
                arr[j+1]=current;
            }
        }
        
        // O(n^2)
        void selectionSort(){
            int j, k;
            for(int i=0;i<9;++i){
                for(j=k=i; j<10;++j) k=arr[j]<arr[k] ? j : k;
                swap(arr[i],arr[k]);
            }
        }
        
        // O(nlog(n))
        int quickSortHelper(int l, int h){
            int pivot = arr[l], i=l, j=h;
            do{
                do{i++;}while(arr[i]<=pivot); //looking for greater elements than pivot
                do{j--;}while(arr[j]>pivot);  //looking for smaller elements than pivot
                if(i<j){swap(arr[i],arr[j]);}
            }while(i<j);
            swap(arr[l],arr[j]);
            return j;
        }
        void quickSort(int l, int h){
            int j;
            if(l<h){
                j=quickSortHelper(0,10);
                quickSort(l,j);
                quickSort(j+1,h);
            }
        }
        
        void mergeSortHelper(vector<int>&A, int l, int mid, int h){
            int i=l, j=mid+1, k=l;
            vector<int> B(l+h+1);
            while(i<=mid && j<=h){
                if(A[i]<A[j]){
                    B[k++]=A[i++];
                }
                else{
                    B[k++]=A[j++];
                }
            }
            for(;i<=mid;++i){
                B[k++]=A[i];
            }
            for(;j<=h;++j){
                B[k++]=A[j];
            }
            for(int p=l;p<=h;++p){
                A[p]=B[p];
            }
        }
        void mergeSort(vector<int>&A, int l, int h){
            int mid;
            if(l<h){
                mid=(l+h)/2;
                mergeSort(A,l,mid);
                mergeSort(A,mid+1,h);
                mergeSortHelper(A,l,mid,h);
            }
        }
        
        // O(n^3/2)
        // O(nlog(n))
        void shellSort(){
            int gap, i, j, temp;
            for(gap=5;gap>=1;gap/=2){
                for(i=gap;i<10;++i){
                    temp = arr[i];
                    j=i;
                    while(j>=gap && arr[j-gap]>temp){
                        arr[j] = arr[j-gap];
                        j-=gap;
                    }
                    arr[j]=temp;
                }
            }
        }

        // O(n)
        void countSort(){
            int max=*max_element(arr.begin(),arr.end());
            vector<int> count(max+1,0);
            for(auto i:arr) count[i]+=1;
            arr.clear();
            for(int i=0;i<count.size();++i)
                if(count[i]>0){
                    arr.push_back(i);
                    count[i]--;
                    i--;
                }
        }
        
        // O(n)
        void bucketSort(){
            int max=*max_element(arr.begin(),arr.end());
            vector<vector<int>> bin(max+1);
            for(auto i:arr) bin[i].push_back(i);
            arr.clear();
            for(int i=0;i<bin.size();++i){
                if(bin[i].size()!=0){
                    for(auto j:bin[i]){
                        arr.push_back(j);
                    }
                }
            }
        }
        
        // Based on modulus function
        void radixSort(){

        }

        void printArr(){
            for(int i=0;i<10;++i){
                cout<<arr[i]<<" ";
            }
        }
};

int main(){
    int a;
    Sorting s = Sorting();
    s.takeInput();
    cout<<"Prev : ";
    s.printArr();
    cout<<endl<<"After : ";
    // algorithm
    s.shellSort();
    s.printArr();
    return 0;
}