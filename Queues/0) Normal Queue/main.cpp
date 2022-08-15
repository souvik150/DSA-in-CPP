#include <iostream>
using namespace std;

class QueueUsingArray
{
  int *data;
  int front;
  int rear;
  int capacity;

public:
  QueueUsingArray(int size)
  {
    data = new int[size];
    front = -1;
    rear = -1;
    capacity = size;
  }

  void enqueue(int element)
  {
    if (rear == capacity)
    {
      cout << "Queue Full" << endl;
    }
    if (front == -1)
    {
      front++;
      data[front] = element;
      rear++;
    }
    else
    {
      rear++;
      data[rear] = element;
    }
  }

  int dequeue()
  {
    if (front == -1)
    {
      cout << "Queue is empty" << endl;
      return -1;
    }
    else
    {
      int ans = data[front];
      front++;
      return ans;
    }
  }

  int top()
  {
    if (front == -1)
    {
      cout << "Queue is empty" << endl;
      return -1;
    }
    else
    {
      return data[front];
    }
  }
};

int main()
{
  QueueUsingArray s(4);
  s.enqueue(10);
  s.enqueue(20);
  s.enqueue(30);
  s.enqueue(40);
  s.enqueue(50);

  cout << s.top() << endl;
  cout << s.dequeue() << endl;
  cout << s.dequeue() << endl;
  cout << s.dequeue() << endl;
  cout << s.top() << endl;
}