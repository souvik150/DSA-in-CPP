#include <iostream>
using namespace std;

class DEQueue
{
  int *data;
  int front;
  int rear;
  int size;
  int capacity;

public:
  DEQueue(int s)
  {
    data = new int[s];
    front = -1;
    rear = 0;
    size = 0;
    capacity = s;
  }

  int sizeOf()
  {
    return size;
  }

  bool isEmpty()
  {
    return size == 0;
  }

  void enqueueFront(int element)
  {
    if (data[front] != 0)
    {
      front = 0;
      data[front] = element;
      rear++;
    }
    else
    {
      cout << "Position occupied" << endl;
    }
  }

  int dequeueFront()
  {
    if (front == -1)
    {
      cout << "Queue Empty!" << endl;
      return -1;
    }
    else
    {
      int ans = data[front];
      front++;
      return ans;
    }
  }

  void enqueueRear(int element)
  {
    if (rear == capacity)
    {
      cout << "Queue Full!" << endl;
    }
    data[rear] = element;
    rear++;
  }

  int dequeueRear()
  {
    if (rear == -1)
    {
      cout << "Queue Empty!" << endl;
      return -1;
    }
    int ans = data[rear];
    rear--;
    return ans;
  }

  void display()
  {
    for (int i = 0; i < rear; i++)
    {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  DEQueue q(5);
  cout << q.dequeueFront() << endl;
  q.enqueueFront(10);
  q.enqueueRear(20);
  q.enqueueRear(30);
  q.enqueueRear(40);
  q.enqueueRear(50);
  q.display(); // 10,20,30,40,50
  q.enqueueRear(50);
  cout << q.dequeueFront() << endl;
  q.enqueueFront(60);
  q.display();
  cout << q.dequeueRear() << endl;
  q.enqueueRear(70);
  q.display();
}