#include <iostream>
#include <array>

using namespace std;

class Dish {
    private:
    string description;

    public:
    Dish(){

    }
    Dish(string description){
        this->description = description;
    };
    string get_description(){
        return this->description;
    };
};

class Stack{
    private:
    Dish arr[5];
    Dish *top;
    Dish *start;   

    public:
    Stack(){
        top = arr;
        start = top;
    }
    bool is_empty(){
        return (top == start);
    }
    bool is_full(){
        return ((start + 5) == top);
    }
    void push(Dish element){
        if(!is_full()){
            *top = element;
            top++;

            cout << "Pushed " << (*(top-1)).get_description() << " to the stack.\n\n";
        }
        else{
            cout << "Stack is full. :(\n\n";
        }
    }
    void pop(){
        if(!is_empty()){
            cout << "Popped " << (*(top-1)).get_description() << "\n\n";
            top--;
        }
        else{
            cout << "Stack is empty.\n\n";
        }
    }

    void peek(){
        if(!is_empty()){
            cout << "Next Dish: " << (*(top-1)).get_description() << "\n\n";
        }
        else{
            cout << "Stack is empty.\n\n";
        }
    }

    void size(){
        cout << "Stack size: " << (top - start) << "\n\n";
    }
};

int main(){
    Stack myStack;
    Dish one_dish = Dish("A dish with one fish pattern on it");
    Dish two_dish = Dish("A dish with two fish patterns on it");
    Dish red_dish = Dish("A dish with a red fish pattern on it");
    Dish blue_dish = Dish("A dish with a blue fish pattern on it");

    myStack.size();

    myStack.push(one_dish);
    myStack.push(two_dish);
    myStack.push(red_dish);
    myStack.push(blue_dish);

    myStack.size();

    myStack.peek();
    myStack.pop();

    myStack.pop();

    myStack.size();

    return 0;
}
