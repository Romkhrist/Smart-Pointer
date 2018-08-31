/*
*
* Let's me introduce my own implementation
* of the shared_ptr<T> smart pointer.
* This pointer performs counts references
* and delete. The work is not finished yet.
*
*/

#include <iostream>
#include <cstddef>
#include "smart_ptr.h"

int main()
{
    using std::cout;
    using std::endl;
    
    smart_ptr<int> s1(new int(5));
    smart_ptr<int> s2;
    
    s2 = s1;
    
    {
        smart_ptr<int> s3;
        
        s3 = s2;
        //here destructor of s3 will be invoked
    }
    
    cout << "value: " << *s2 << endl;
    
    return 0;
}
