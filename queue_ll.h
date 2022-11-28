template <typename T>
class Queue
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
    };
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = nullptr;
    }
    ~Queue()
    {
        while (head != nullptr)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
    void push(const T &x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = nullptr;
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    T pop()
    {
        Node *temp = head;
        T data = temp->data;
        head = temp->next;
        delete temp;
        return data;
    }
    bool isEmpty() { return head == nullptr; }
};