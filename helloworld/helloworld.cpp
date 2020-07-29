#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Legs
{
public:
   void WalkAround() 
   {
       cout << "walking on legs" << endl;
   }
};

class Arms
{
public:
   void GrabThings() 
   {
        cout << "I like grabbing" << endl;
   }
};

class Robot
{
public:
   void WalkAround() {legs.WalkAround();}
   void GrabThings() {arms.GrabThings();}

private:
   Legs legs;
   Arms arms;
};

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int i = 0;

    for (const string& word : msg)
    {
        cout << word << " ";
        i++;
    }
    cout << endl;

    Robot Rob;

    Rob.WalkAround();
    Rob.GrabThings();


    cout << endl;
}