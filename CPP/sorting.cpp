#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

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
            int temp;
            for(int i=0;i<9;++i){
                for(int j=0;j<10-i-1;++j){
                    if(arr[j+1]<arr[j]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }
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
        void selectionSort(){
            int temp, j, k;
            for(int i=0;i<9;++i){
                for(j=k=i; j<10;++j){
                    if(arr[j]<arr[k]){
                        k=j;
                    }
                }
                temp = arr[i];
                arr[i]=arr[k];
                arr[k]=temp;
            }
        }
        
        // O(nlog(n))
        void quickSort(){

        }
        void mergeSort(){

        }
        void heapSort(){

        }
        void treeSort(){

        }
        
        // O(n^3/2)
        void shellSort(){
            
        }

        // O(n)
        void countSort(){

        }
        void bucketSort(){

        }
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
    s.selectionSort();
    s.printArr();
    return 0;
}