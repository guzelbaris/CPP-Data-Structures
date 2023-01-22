#ifndef stackqueue_h
#define stackqueue_H
using namespace std;
template <class T>
class StackQueue {
  private:


  public:
  T* data;
  int size;
  int front;
  int rear;
StackQueue() {
    data = new T[1024];
    size = 0;
    front = 0;
    rear = 0;
  }
void push_front(T element) {
    if (size == 1024) return;
    data[front] = element;
    front = (front + 1) % 1024;
    size++;
}
void push_rear(T element) {
    if (size == 1024) return;
    rear = (1024 + rear - 1) % 1024;
    data[rear] = element;
    size++;
}

T pop_front() {
    if (size == 0) return 0;
    front = (1024 + front - 1) % 1024;
    size--;
    return data[front];
  }

T pop_rear() {
    if (size == 0) return 0;
    size--;
    int temp = rear;
    rear = (rear + 1) % 1024;
    return data[temp];
  }

T peek_front() {
    if (size == 0) return 0;
    return data[front];
  }

void print_elements() {
    int i = rear;
    while (i != front) {
      cout << data[i];
      i = (i + 1) % 1024;
    }
  }
  int isEmpty()
{
    if(size==0){
        return 1;
    }
    else
        return 0;
}
};
#endif // stackqueue_h
