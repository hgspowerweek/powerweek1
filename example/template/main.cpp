#include <iostream>
using std::cout;
using std::endl;

template<class T>
T* find(T* first, T* last, const T& value) {
  while (first != last && *first != value) ++first;
  return first;
}

int main()
{
  const int size=10;
  int   arrayI[10]={7,5,6,2,3,1,4,0,9,8};
  float arrayF[10]={.7,.5,.6,.2,.3,.1,.4,.0,.9,.8};

  {// set a scope for local variables
  int* elementI=find(&arrayI[0], &arrayI[10], 1);
  if (elementI!=&arrayI[10])
    cout << "element " << *elementI << " found" << endl;
  else
    cout << "element not found" << endl;
  }

  {// set a scope for local variables
    float* elementF=find(&arrayF[0], &arrayF[10], (float)1.);
    if (elementF!=&arrayF[10])
      cout << "element " << *elementF << " found" << endl;
    else
      cout << "element not found" << endl;
  }

  return 0;
}
