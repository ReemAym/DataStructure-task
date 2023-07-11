#include <iostream>
using namespace std;

const int MaxSize=100;
template<class T>

class Queue
{
private:
    int front ,rear,len;

public:

    T array[100];
    Queue()
    {
        front=0;
        rear=MaxSize-1;
        len=0;

      array[100]={};
    }

    bool IsFull()
    {
        return len>=MaxSize;
    }

    bool IsEmpty()
    {
        return len==0;
    }

    void Enqueue(int element)
    {
        if(IsFull())
        {
            cout<<"Queue is full,"<< element <<" can't be added.";
        }
        else
        {
            rear=(rear+1)%MaxSize;
            array[rear]=element;
            len++;
        }
    }

    int Dequeue()
    {
        if(IsEmpty())
        {
            cout<<"Queue is empty,there isn't any element to be deleted";
        }
        else
        {
            int temp= array[front];
            front=(front+1)%MaxSize;
            len--;
            return temp;
        }


    }

    void Delete()
    {
        front=(front+1)%MaxSize;
        len--;
    }

    void clear()
    {
        while(len!=0)
        {
            Delete();
        }
    }
    int First()
    {
        return array[front];
    }

    int Back()
    {
        return array[rear];
    }

  void Print()
  {
        if(IsEmpty())
        {
            cout<<"Queue is empty,There isn't element to print";
        }
        else
        {
            for(int i=front;i!=rear;i=(i+1)%MaxSize)
            {
                cout<<array[i]<<" ";
            }
            cout<<array[rear];
        }

  }

  int getFront()
  {
        return front;
  }
  int getRear()
  {
        return rear;
  }
int Size()
{
        return len;
}
};

template<class T>
class Solution
{
private:
    Queue<T> a;
    int time_for_each_person=1, sum =0;

public:
    void EnterItem(int n[],int size)
    {
        for(int i=0;i<size;i++)
        {
            a.Enqueue(n[i]);
        }
    }

   void CalculateTime1(int n,int k)
    {
       if(a.array[n]<a.array[k])
       {
           sum+=a.array[n];
       }
       else
       {
           if(n<=k)
           {
               sum+=a.array[k];
           }
           else
           {
              sum=sum+ a.array[k]-1;
           }
       }
    }

   int CalculateTime2(int x)
    {
        for(int i=a.getFront();i!=a.getRear();i=(i+1)%MaxSize)
        {
            CalculateTime1(i, x);
          /*  if(a.array[x]==0)
                break;*/
        }
        CalculateTime1(a.getRear(), x);

        return sum*time_for_each_person;
    }
};

void test1()
{
    Solution<int> s;
    int array[3]={2,3,2};
    s.EnterItem(array,3);
    cout<<s.CalculateTime2(2)<<" seconds"<<endl;
}

void test2()
{
    Solution<int> s;
    int array[4]={5,1,1,1};
    s.EnterItem(array,4);
    cout<<s.CalculateTime2(0)<<" seconds"<<endl;
}

void test3()
{
    Solution<int> s;
    int array[3]={3,2,3};
    s.EnterItem(array,3);
    cout<<s.CalculateTime2(1)<<" seconds"<<endl;
}

void test4()
{
    Solution<int> s;
    int array[5]={1,4,2,3,2};
    s.EnterItem(array,5);
    cout<<s.CalculateTime2(2)<<" seconds"<<endl;
}

void test5()
{
    Solution<int> s;
    int array[5]={1,4,2,3,2};
    s.EnterItem(array,5);
    cout<<s.CalculateTime2(1)<<" seconds"<<endl;
}

int main() {

    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
