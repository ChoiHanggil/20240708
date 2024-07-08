#include <iostream>
#include <vector>
#include<queue>

class Heap
{
private:
    std::vector<int> mHeap;

public:
    void Insert(int value)
    {
        mHeap.push_back(value);

        int i = static_cast<int>(mHeap.size() - 1);
        int parent = (i - 1) / 2;
        while (i != 0 && value > mHeap[parent])
        {
            mHeap[i] = mHeap[parent];
            mHeap[parent] = value;
            
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void Pop()
    {
        if (mHeap.size() == 0)
        {
        }

        //int root = mHeap.front();
        
        mHeap[0] = mHeap.back();
        mHeap.pop_back();
        
        int i{};
        while (i < mHeap.size())
        {

            int child = (i * 2) + 1;

            if (child >= mHeap.size())
            {
                break;
            }
            //배열 크기 
            if (child + 1 < mHeap.size() && mHeap[child] < mHeap[child + 1])
            {
                child++;
            }
            if (mHeap[i] >= mHeap[child])
            {
                break;
            }

            std::swap(mHeap[i], mHeap[child]);
            i = child;
        }

    }

    int GetRoot()
    {
        return mHeap.front();
    }

    void Print()
    {
        for (const auto& e : mHeap)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    Heap h;
    //O( n* log n)
    h.Insert(1);
    h.Insert(2);
    h.Insert(3);
    h.Insert(4);
    h.Insert(5);
    h.Print();
    //O( n* log n)
    std::cout << h.GetRoot() << std::endl;
    h.Pop();
    std::cout << h.GetRoot() << std::endl;
    h.Pop();
    std::cout << h.GetRoot() << std::endl;
    h.Pop();
    std::cout << h.GetRoot() << std::endl;
    h.Pop();
    std::cout << h.GetRoot() << std::endl;
    h.Pop();

    

    //Heap Sort
    //O(2 n * log n) = O( n* log n)

    std::priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;
    pq.pop();

   
    std::vector<int> v{ 1,2,3,4,5 };

    //heapify 힙화
    std::make_heap(v.begin(), v.end());

    for (const auto& e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << v.front() << std::endl;
    std::pop_heap(v.begin(), v.end());
    v.pop_back();

    std::cout << v.front() << std::endl;
    std::pop_heap(v.begin(), v.end());
    v.pop_back();

    std::cout << v.front() << std::endl;
    std::pop_heap(v.begin(), v.end());
    v.pop_back();

    std::cout << v.front() << std::endl;
    std::pop_heap(v.begin(), v.end());
    v.pop_back();

    std::cout << v.front() << std::endl;
    std::pop_heap(v.begin(), v.end());
    v.pop_back();

}

