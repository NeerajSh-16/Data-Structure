#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Maximum size of each queue
#define MAX_QUEUES 5 // Maximum number of queues

class MultipleQueue {
private:
    int queues[MAX_QUEUES][MAX_SIZE]; // Array of queues
    int front[MAX_QUEUES]; // Array to store front index of each queue
    int rear[MAX_QUEUES]; // Array to store rear index of each queue

public:
    // Constructor to initialize the multiple queue
    MultipleQueue() {
        for (int i = 0; i < MAX_QUEUES; ++i) {
            front[i] = -1;
            rear[i] = -1;
        }
    }

    // Function to check if a specific queue is empty
    bool isEmpty(int queueIndex) {
        return front[queueIndex] == -1 && rear[queueIndex] == -1;
    }

    // Function to check if a specific queue is full
    bool isFull(int queueIndex) {
        return (rear[queueIndex] + 1) % MAX_SIZE == front[queueIndex];
    }

    // Function to insert an element into a specific queue
    void enqueue(int queueIndex, int data) {
        // Check if the queue is full
        if (isFull(queueIndex)) {
            cout << "Queue " << queueIndex << " is full. Cannot enqueue element." << endl;
            return;
        }
        // If the queue is empty, set both front and rear to 0
        if (isEmpty(queueIndex)) {
            front[queueIndex] = 0;
            rear[queueIndex] = 0;
        } else {
            // Increment rear in a circular manner
            rear[queueIndex] = (rear[queueIndex] + 1) % MAX_SIZE;
        }
        queues[queueIndex][rear[queueIndex]] = data;
        cout << "Enqueued " << data << " into queue " << queueIndex << endl;
    }

    // Function to delete an element from a specific queue
    int dequeue(int queueIndex) {
        // Check if the queue is empty
        if (isEmpty(queueIndex)) {
            cout << "Queue " << queueIndex << " is empty. Cannot dequeue element." << endl;
            return -1;
        }
        int data = queues[queueIndex][front[queueIndex]];
        // If there's only one element in the queue
        if (front[queueIndex] == rear[queueIndex]) {
            front[queueIndex] = -1;
            rear[queueIndex] = -1;
        } else {
            // Move front to the next element in a circular manner
            front[queueIndex] = (front[queueIndex] + 1) % MAX_SIZE;
        }
        return data;
    }

    // Function to display elements of a specific queue
    void displayQueue(int queueIndex) {
        if (isEmpty(queueIndex)) {
            cout << "Queue " << queueIndex << " is empty." << endl;
        } else {
            cout << "Queue " << queueIndex << " elements: ";
            int current = front[queueIndex];
            while (current != rear[queueIndex]) {
                cout << queues[queueIndex][current] << " ";
                current = (current + 1) % MAX_SIZE;
            }
            cout << queues[queueIndex][rear[queueIndex]] << endl;
        }
    }
};

int main() {
    MultipleQueue mq;

    // Insert elements into queue 0
    mq.enqueue(0, 10);
    mq.enqueue(0, 20);
    mq.enqueue(0, 30);

    // Insert elements into queue 1
    mq.enqueue(1, 40);
    mq.enqueue(1, 50);
    mq.enqueue(1, 60);

    // Display elements of queue 0
    mq.displayQueue(0);

    // Display elements of queue 1
    mq.displayQueue(1);

    return 0;
}
