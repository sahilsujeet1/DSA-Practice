#include <iostream>
using namespace std;

class Deque
{
    int *arr;
    int size, front, rear;

    public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool push_back(int x)
    {
        if (isFull())
        {
            cout << "Queue is already full!" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    bool push_front(int x)
    {
        if (isFull())
        {
            return false;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    int pop_back()
    {
        if(isEmpty()){
            cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { 
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int pop_front()
    {
        if(isEmpty()){
            cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) {
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Deque d(5);
    d.push_back(3);
    d.push_front(1);
    cout << d.getFront() << " " << d.getRear() << endl;
    d.push_back(4);
    d.push_front(2);
    d.push_front(-1);
    cout << d.getFront() << " " << d.getRear() << endl;
    d.pop_back();
    cout << d.getFront() << " " << d.getRear() << endl;
    d.pop_front();
    cout << d.getFront() << " " << d.getRear() << endl;
}