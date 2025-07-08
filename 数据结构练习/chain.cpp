#include <bits/stdc++.h>
using namespace std;
class Chain
{
   public:
    Chain(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
    ~Chain()
    {
        delete this->next;
    }
    Chain* set_val(int val)
    {
        this->val = val;
        return this;
    }
    int get_val()
    {
        return val;
    }
    Chain* add_val(int delta)
    {
        val += delta;
        return this;
    }
    Chain* set_next(Chain* next)
    {
        this->next = next;
        return next;
    }

    Chain* print()
    {
        Chain* next = this;
        cout << this->val;
        next = next->next;
        while (next != nullptr)
        {
            cout << " , " << next->val;
            next = next->next;
        }
        cout << endl;
        return this;
    }

    int search(int target)
    {
        Chain* current = this;
        int index = 1;
        while (current != nullptr)
        {
            if (current->val == target)
            {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }

   private:
    int val;
    Chain* next;
};

int main()
{
    int n, num;
    Chain* next = nullptr;
    cin >> n;
    cin >> num;
    Chain* head = new Chain(num);
    next = head;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> num;
        next = next->set_next(new Chain(num));
    }
    head->print();
    cin >> num;
    cout << head->search(num);
    delete head;
    return 0;
}
