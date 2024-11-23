#include <iostream>
#include <limits>
#include <string>
using namespace std;

class QueueManager
{
private:
    int *queue;
    int front, rear, size;
    int choice, element;

public:
    QueueManager()
    {
        cout << "Enter the size of the queue: ";
        size = getValidIntInput();

        queue = new int[size];
        front = -1;
        rear = -1;

        for (int i = 0; i < size; i++)
        {
            queue[i] = 0;
        }

        displayMenu();
    }

    ~QueueManager()
    {
        delete[] queue;
    }

    int getValidIntInput()
    {
        string input;
        int value;
        while (true)
        {
            getline(cin, input);

            if (isNumeric(input))
            {
                try
                {
                    value = stoi(input);
                    return value;
                }
                catch (invalid_argument& e)
                {
                    cout << "Invalid input! Please enter a valid integer: ";
                }
                catch (out_of_range& e)
                {
                    cout << "Number out of range! Please enter a valid integer: ";
                }
            }
            else
            {
                cout << "Invalid input! Please enter a valid integer: ";
            }
        }
    }

    bool isNumeric(const string& str)
    {
        if (str.empty()) return false;

        int start = 0;

        if (str[0] == '-') 
        {
            if (str.size() == 1) return false;
            start = 1;
        }

        for (int i = start; i < str.size(); i++)
        {
            if (!isdigit(str[i]))
                return false;
        }

        return true;
    }

    void enqueue(int element)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full! Cannot enqueue." << endl;
        }
        else
        {
            if (front == -1)
                front = 0;
            queue[++rear] = element;
            cout << "Element " << element << " added to the queue." << endl;
        }
    }

    void dequeueFromValue(int value)
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        bool found = false;

        for (int i = front; i <= rear; i++)
        {
            if (queue[i] == value)
            {
                found = true;

                int shiftCount = i + 1 - front;

                for (int j = 0; j <= rear - shiftCount; j++)
                {
                    queue[j] = queue[j + shiftCount];
                }

                for (int j = rear - shiftCount + 1; j <= rear; j++)
                {
                    queue[j] = 0;
                }

                rear -= shiftCount;

                if (front > rear)
                {
                    front = rear = -1;
                }

                cout << "Element " << value << " and all preceding elements dequeued." << endl;
                break;
            }
        }

        if (!found)
        {
            cout << "Element " << value << " not found in the queue." << endl;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Current queue (bottom to top):" << endl;
        for (int i = size - 1; i >= 0; i--)
        {
            if (i <= rear && i >= front)
            {
                cout << "Index [" << i << "] : " << queue[i] << endl;
            }
            else
            {
                cout << "Index [" << i << "] : 0" << endl;
            }
        }
    }

    void displayMenu()
    {
        do
        {
            cout << "\nQueue Operations Menu:\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Display Queue\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            choice = getValidIntInput();

            switch (choice)
            {
            case 1:
                cout << "Enter element to enqueue: ";
                element = getValidIntInput();
                enqueue(element);
                break;
            case 2:
                {
                    cout << "Enter the element to dequeue: ";
                    int value = getValidIntInput();
                    dequeueFromValue(value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
            }
        } while (choice != 4);
    }
};

int main()
{
    QueueManager manager;

    return 0;
}