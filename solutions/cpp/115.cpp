#include <iostream>
#include <stack>

class MinStack
{
private:
    std::stack<int> stack;
    std::stack<int> min_number;

public:
    MinStack()
    {
        min_number.push(INT_MAX); // INT_MAX --> int 数据类型的最大值
    }

    void push(int value)
    {
        if (value <= min_number.top()) // 避免出现重复的最小值，导致提前将当前栈中最小元素全部删除
        {
            min_number.push(value);
        }
        stack.push(value);
    }

    void pop()
    {
        if (stack.top() <= min_number.top())
        {
            min_number.pop();
        }
        stack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        if (stack.empty())
        {
            return NULL;
        }
        return min_number.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */