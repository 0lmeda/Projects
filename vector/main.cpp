#include <iostream>


using namespace std;


class vector{
    private:
    int* arr;
    int size;
    int capacity;

    public:
    

    vector(int* currentArr, int currentSize){
    size = currentSize;
    capacity = size;
    arr = new int[capacity];
    for(int i = 0; i<size; i++){
        arr[i] = currentArr[i];
    }


    }

    void resize(){
        capacity += 1;
        int* newArr = new int[capacity];

        for(int i = 0; i<size; i++){
            newArr[i] = arr[i]; 
        }
        
        delete[] arr;
        arr = newArr;
            
    }

    void push_back(int value){
        if(size >= capacity){
            resize();
           
        }

        arr[size] = value;
        size++;
    }

    ~vector(){
        delete[] arr;
        cout<<"bye";
    }

    int get(int v){
        return arr[v];
    }
};

int main(){

    //Day 1 of trying to make a function like vector
    int arr [3] = {1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector vec(arr,n);

    vec.push_back(2);


    for(int i = 0; i<4; i++){
        cout<<vec.get(i)<<endl;
    }

    return 0;

}