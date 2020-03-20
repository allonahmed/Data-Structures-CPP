#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"
#include "lab15.h"

/*****************************************************
 * Remove comment line only if you completely 
 * defined all of MyStack() methods
 *****************************************************/
bool TestStackClass()
{
    ds::sn::Stack<int> a, b;
    int value;
    int n = rand() % 41 + 10;

    for(int i = 0;i < n;i += 1)
    {
        value = rand() % 100 + 1;
        a.Push(value);
        b.Push(value);
    }

    while(!a.IsEmpty() && !b.IsEmpty())
    {
        if(a.Top() != b.Top())
        {
            std::cout << "MyStack is invalid\n\n";
            return false;
        }
        a.Pop();
        b.Pop();
    }
    
    if(a.IsEmpty() == b.IsEmpty())
    {
        std::cout << "MyStack is valid\n\n";
        return true;
    }
    else
    {
        std::cout << "MyStack is invalid\n\n";
        return false;
    }
}
/*****************************************************
* End of comments
*****************************************************/

/*****************************************************
 * Remove comment line only if you completely 
 * defined all of MyQueue() methods
 *****************************************************/
// bool TestQueueClass()
// {
//     ds::da::Queue<int> a, b;
//     int value;
//     int n = rand() % 41 + 10;

//     for(int i = 0;i < n;i += 1)
//     {
//         value = rand() % 100 + 1;
//         a.Enqueue(value);
//         b.Enqueue(value);
//     }

//     while(!a.IsEmpty() && !b.IsEmpty())
//     {
//         if(a.Peek() != b.Peek())
//         {
//             std::cout << "MyQueue is invalid\n\n";
//             return false;
//         }
//         a.Dequeue();
//         b.Dequeue();
//     }
    
//     if(a.IsEmpty() == b.IsEmpty())
//     {
//         std::cout << "MyQueue is valid\n\n";
//         return true;
//     }
//     else
//     {
//         std::cout << "MyQueue is invalid\n\n";
//         return false;
//     }
// }
/*****************************************************
* End of comments
*****************************************************/

int main()
{
    srand(time(NULL));

    std::cout << TestStackClass() << std::endl;

    MyStack<int> stack;

    stack.Push(1);
    std::cout << stack.Top() << std::endl;
    stack.Push(6);
    std::cout << stack.Top() << std::endl;
    stack.Push(7);
    stack.Push(8);
    stack.Pop();
    std::cout << stack.Top() << std::endl;
    std::cout << std::boolalpha << stack.IsEmpty() << std::endl;

    MyStack<int> stack2;

    std::cout<< stack2.IsEmpty() << std::endl;

    return 0; 
}
