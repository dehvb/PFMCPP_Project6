/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* name);   //1
    int value; //2
    std::string name; //3
};

T::T(int v, const char* myName) :
value(v),
name(myName)
{}

struct CompareBear                                //4
{
    T* compare(T& a, T& b) //5
    {
        
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        
        return nullptr;
    }
};

struct U
{
    float uFlt1 { 0 }, uFlt2 { 0 };
    float updatingMmbFunc(const float& nuMmbFlt)      //12
    {
        std::cout << "U's uFlt1 value: " << this->uFlt1 << std::endl;
        this->uFlt1 = nuMmbFlt;
        std::cout << "U's uFlt1 updated value: " << this->uFlt1 << std::endl;
        while( std::abs(this->uFlt2 - this->uFlt1) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            this->uFlt2 += 0.0005f;
        }
        std::cout << "U's uFlt2 updated value: " << this->uFlt2 << std::endl;
        return this->uFlt2 * this->uFlt1;
    }
};

struct UpdateR
{
    static float updatingFunc(U& that, const float& nuFlt )        //10
    {
        std::cout << "U's uFlt1 value: " << that.uFlt1 << std::endl;
        that.uFlt1 = nuFlt;
        std::cout << "U's uFlt1 updated value: " << that.uFlt1 << std::endl;
        while( std::abs(that.uFlt2 - that.uFlt1) > 0.001f )
        {
            /*
            write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            */
            that.uFlt2 += 0.0005f;
        }
        std::cout << "U's uFlt2 updated value: " << that.uFlt2 << std::endl;
        return that.uFlt2 * that.uFlt1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(2, "t1");                                             //6
    T t2(3, "t2");                                             //6
    
    CompareBear f;                                            //7
    auto* smaller = f.compare(t1, t2);                              //8
    std::cout << "the smaller one is " << (smaller != nullptr ? smaller->name : "- neither, invalid pointer or same") << std::endl; //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << UpdateR::updatingFunc(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updatingMmbFunc(updatedValue) << std::endl;
}

        
        
        
        
        
        
        
