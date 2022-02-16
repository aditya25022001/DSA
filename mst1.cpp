#include<iostream>
#include<math.h>

using namespace std;

void putpixel(int x, int y, int color){}

void plot(int x, int y, int color){}

int getPixel(int x, int y){}

void arc(int xc, int yc, int startAngle, int endAngle, int radius){}

void floodFill(int x, int y, int oldColor, int newColor){
    if(getPixel(x,y)!=newColor){
        putpixel(x,y,newColor);
        floodFill(x+1,y,oldColor,newColor);
        floodFill(x-1,y,oldColor,newColor);
        floodFill(x,y+1,oldColor,newColor);
        floodFill(x,y-1,oldColor,newColor);
        floodFill(x+1,y-1,oldColor,newColor);
        floodFill(x+1,y+1,oldColor,newColor);
        floodFill(x-1,y+1,oldColor,newColor);
        floodFill(x-1,y-1,oldColor,newColor);
    }
}

void boundaryFill(int x, int y, int boundaryColor, int newColor){
    if(getPixel(x,y)!=newColor && getPixel(x,y)!=boundaryColor){
        putpixel(x,y,newColor);
        boundaryFill(x+1,y,boundaryColor,newColor);
        boundaryFill(x-1,y,boundaryColor,newColor);
        boundaryFill(x,y+1,boundaryColor,newColor);
        boundaryFill(x,y-1,boundaryColor,newColor);
        boundaryFill(x+1,y-1,boundaryColor,newColor);
        boundaryFill(x+1,y+1,boundaryColor,newColor);
        boundaryFill(x-1,y+1,boundaryColor,newColor);
        boundaryFill(x-1,y-1,boundaryColor,newColor);
    }
}

void midpointCircle(int r){
    int x=0, y=r;
    int decisionParameter = 1-r;
    putpixel(x, y,2);
    x++;
    while(x<=y){
        if(decisionParameter>0){
            y--;
            plot(x, y,2);
            decisionParameter+=2*(x-y)+1;
        }
        else{
            plot(x, y,2);
            decisionParameter+=2*x+1;
        }
        x++;
    }
}

void bresenhamCircle(int r){
    int x=0, y=r, decisionParameter=3-2*r;
    putpixel(x,y,2);
    x++;
    while(x<=y){
        if(decisionParameter>0){
            y--;
            plot(x,y,2);
            decisionParameter+=4*(x-y)+10;
        }
        else{
            plot(x,y,2);
            decisionParameter+=4*x+6;
        }
        x++;
    }
}

void bresenhamLine(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1), dy=abs(y2-y1);
    int p;
    int x=x1, y=y1;
    if(dy<=dx){
        putpixel(x,y,2);
        x++;
        p=2*dy-dx;
        while(x<=x2){
            if(p>=0){
                y++;
                putpixel(x,y,2);
                p+=2*(dy-dx);
            }
            else{
                putpixel(x,y,2);
                p+=2*dy;
            }
        }
    }
    else{
        putpixel(x,y,2);
        y++;
        p=2*dx-dy;
        while(y<=y2){
            if(p>=0){
                x++;
                putpixel(x,y,2);
                p+=2*(dx-dy);
            }
            else{
                putpixel(x,y,2);
                p+=2*dx;
            }
        }
    }
}

void ddaLine(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int x=x1;
    int y=y1;
    putpixel(x,y,2);
    x++;
    int whichToIncrement;
    if(dx>=dy){
        whichToIncrement = dx;
    }
    else{
        whichToIncrement = dy;
    }
    dx=dx/whichToIncrement;
    dy=dy/whichToIncrement;
    int i=1;
    while(i<=whichToIncrement){
        putpixel(x,y,5);
        x+=dx;
        y+=dy;
        i++;
    }

}

int binarySearch(int arr[], int n, int searchItem){
    int left=0, right=n-1, mid;
    while(right>=left){
        mid=floor((right+left)/2);
        if(arr[mid]==searchItem){
            return mid;
        }
        if(arr[mid]>searchItem){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}

int linearSearch(int arr[], int n, int searchItem){
    for(int i=0;i<n;++i){
        if(arr[i]==searchItem){
            return i;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int n){
    int temp;
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[], int n){
    int current, j;
    for(int i=0;i<n;++i){
        current=arr[i];
        j=i-1;
        while(j>-1 && current<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n, choice, found;
    int arr[100];
    cout<<"Menu"<<endl;
    cout<<"________________________"<<endl;
    cout<<"Bubble Sort : 1"<<endl;
    cout<<"Insertion Sort : 2"<<endl;
    cout<<"Binary Search : 3"<<endl;
    cout<<"Linear Search : 4"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
    switch(choice){
        case 1 :
            cout<<"Enter no of elements (max 100) : ";
            cin>>n;
            cout<<"Enter elements : "<<endl;
            for(int i=0;i<n;++i){
                cin>>arr[i];
            }
            bubbleSort(arr,n);
            break;
        case 2 :
            cout<<"Enter no of elements (max 100) : ";
            cin>>n;
            cout<<"Enter elements : "<<endl;
            for(int i=0;i<n;++i){
                cin>>arr[i];
            }
            insertionSort(arr,n);
            break;
        case 3 :
            cout<<"Enter no of elements in increasing order (max 100) : ";
            cin>>n;
            int searchItem;
            cout<<"Enter elements : "<<endl;
            for(int i=0;i<n;++i){
                cin>>arr[i];
            }
            cout<<"Enter element to search : ";
            cin>>searchItem;
            found = binarySearch(arr,n,searchItem);
            if(found==-1){
                cout<<"Not present";
            }
            else{
                cout<<"Found at index : "<<found;
            }
            break;
        case 4 :
            cout<<"Enter no of elements (max 100) : ";
            cin>>n;
            cout<<"Enter elements : "<<endl;
            for(int i=0;i<n;++i){
                cin>>arr[i];
            }
            cout<<"Enter element to search : ";
            cin>>searchItem;
            found = linearSearch(arr,n,searchItem);
            if(found==-1){
                cout<<"Not present";
            }
            else{
                cout<<"Found at index : "<<found;
            }
            break;
    }
    return 0;
}