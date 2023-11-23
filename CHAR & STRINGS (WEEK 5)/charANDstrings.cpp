#include<bits/stdc++.h>
#include<string>
using namespace std;

// void reverse(string str){
//     int i=0,j=str.size()-1;

//     while(i<=j){
//         swap(str[i],str[j]);
//         i++;
//         j--;
//     }

//     cout<<str<<endl;
// }

// int main(){
//     // string s;
//     // getline(cin,s);
//     // // // cin>>s;
    
//     // string s2="waghela";

//     // s.insert(2,s2);

//     // cout << s<<endl;

//     // int b=s.size();
//     // cout<<b;

// //   string name = "Love Babbar ";
// //   string middle = "kumar ";

// //   name.insert(12, middle);

// //   cout << "Printing name:  " << name << endl;

// string s="23:59";
// // reverse(s);
// cout<<s.size()<<endl;
// cout<<s.length()<<endl;
// }

int main(){
    vector<string>bank;
    //  ["011001","000000","010100","001000"];
bank.push_back("011001");
bank.push_back("000000");
bank.push_back("010100");
bank.push_back("001000");

        int i=0;
        int j=1;
        
        int laser=0;
        
        while(j<bank.size()){

            string s1=bank[i];
            string s2=bank[j];

            // cout<<s1[1]<<" "<<s2[2]<<endl;

            // cout<<s1<<" "<<"and"<<s2<<endl;

            int count1=0;
            int count2=0;

            for(int curr=0;curr<s1.size();curr++){

                
                
                
                count1=count1+int(s1[curr])-48;
                count2=count2+int(s2[curr])-48;

                
                
               

                

            }
            cout<<"count1="<<count1<<endl<<"count2="<<count2<<endl;
            break;

            
            if(count1==0){
                i++;
                j++;
            }
            else if(count2==0){
                j++;
            }
            else{
                laser+=count1*count2;
                i=j;
                j++;
            }
            // cout<<"laser="<<laser<<endl;
        }
}