#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
 
main()
{
   vector<int> v;
 
   v.push_back(10);
   v.push_back(20);
   v.push_back(30);
   v.push_back(40);
   v.push_back(50);
 
   cout << "Loop by index:" << endl;
 
   int ii;
   for(ii=0; ii < v.size(); ii++)
   {
      cout << v[ii] << endl;
   }

   cout << endl << "random_shuffle .." << endl;
   random_shuffle(v.begin(), v.end());
 
   cout << endl << "Constant Iterator:" << endl;
 
   vector<int>::const_iterator cii;
   for(cii=v.begin(); cii!=v.end(); cii++)
   {
      cout << *cii << endl;
   }
 
   cout << endl << "sort .." << endl;
   sort(v.begin(), v.end());

   cout << endl << "Reverse Iterator:" << endl;
 
   vector<int>::reverse_iterator rii;
   for(rii=v.rbegin(); rii!=v.rend(); ++rii)
   {
      cout << *rii << endl;
   }

   cout << "size: " << v.size() << endl;
   cout << endl << "erasing content ..." << endl;
   v.clear();
   cout << "size: " << v.size() << endl;
   cout << "capacity: " << v.capacity() << endl;
 
}
