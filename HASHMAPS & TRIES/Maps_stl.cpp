#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
  
  //creation
  unordered_map<string,int> mapping;

  ///insertion
  pair<string, int> p = make_pair("love", 25); // yebhi stl hi he , pair banakebi daal skte he , pair mehi values link krdo fir sidha push map me

  pair<string,int> q("dipansh",24);

  pair<string,int> r;
  q.first = "arun";
  q.second = 21;
  //insertion 
  mapping.insert(p);
  mapping.insert(q);
  mapping.insert(r);
  //insert
  mapping["babbar"] = 51; // ye apna waala method mapping ka

  cout << "Size of map: " << mapping.size() << endl; 
  //ACCESS 
  cout << mapping.at("love") << endl; //same as below
  cout << mapping["love"] << endl;

  //searching
  cout << mapping.count("lover") << endl; // present hoga to 1 naito 0
  cout << "Size of map: " << mapping.size() << endl; 

  if(mapping.find("babbar") != mapping.end() ) { //find krte jaega , nahi mila to ekdum 'end' me ake rukjaega 
    cout << "Found" << endl;
  }
  else {
    cout << "Not Found" << endl;
  }
   cout << "Size of map: " << mapping.size() << endl; 
   cout << mapping["kumar"] << endl;// ese agar kisi cheez ko dhundha to if wo present nai hua to uska 0 k saath mapping banke entry ban jaega , map ka size b badega
   cout << "Size of map: " << mapping.size() << endl;
  return 0;
}