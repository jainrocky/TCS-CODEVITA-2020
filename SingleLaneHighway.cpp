/***
                 _________________________
                |                         |         
                |_________________________|         
                |           * *           |         
                |          *@IN*          |         
                |___________*_*___________|         
                |                         |
                |_________________________| 
                                    
                                    ~@Scorpion
**/

#include<bits/stdc++.h>
#define BOOSTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REPEAT intll t; cin >> t; for(intll iterator=0; iterator<t; iterator++)
#define UMap unordered_map
#define Map map
#define BLN 1000000000
#define MLN 1000000
#define LKH 100000
typedef long long intll;
typedef long intl;
using namespace std;

template<typename E>
inline void write(const E &tar, string end="\n"){ cout << tar << end; }
template<typename E>
inline void write(const E *tar, intll len, string end=" "){ for(intll i=0; i<len; i++) cout << tar[i] << end; }
template<typename E>
inline void write(const vector<E> &tar, intll len=INT64_MAX, string end=" "){len=min(len, (intll)tar.size());for(intll i=0; i<len; i++) cout << tar[i] << end;}
template<typename E>
inline void read(E &tar){ cin >> tar; }
template<typename E>
inline void read(E *tar, intll len){ for(intll i=0; i<len; i++) cin >> tar[i]; }
template<typename E>
inline void read(vector<E> &tar, intll len){if(tar.size()>0) for(intll i=0; i<tar.size(); i++) cin >> tar[i]; else{E temp; for(intll i=0; i<len; i++)cin >> temp, tar.push_back(temp);}}
class File: public fstream{
    public:
        File(string name, ios_base::openmode __mode = ios_base::in | ios_base::out):fstream(name, __mode){}
        File():fstream(){}
        template<typename E>
        inline void write(const E &tar, string end="\n"){ (*this)<< tar << end; }
        template<typename E>
        inline void write(const E *tar, intll len, string end=" "){ for(intll i=0; i<len; i++) (*this) << tar[i] << end; }
        template<typename E>
        inline void write(const vector<E> &tar, string end=" "){ for(intll i=0; i<tar.size(); i++) (*this) << tar[i] << end; }
        template<typename E>
        inline void read(E &tar){ (*this) >> tar; }
        template<typename E>
        inline void read(E *tar, intll len){ for(intll i=0; i<len; i++) (*this) >> tar[i]; }
        template<typename E>
        inline void read(vector<E> &tar, intll len){if(tar.size()>0) for(intll i=0; i<tar.size(); i++) (*this) >> tar[i]; else {E temp; for(intll i=0; i<len; i++)(*this) >> temp, tar.push_back(temp);}}
};
template<typename E>
E power(E val, intll expo){
    E res = (E)1;
    while(expo > 1LL){
        if(expo % 2LL==0LL) val *= val,  expo/=2LL;
        else res *= val, --expo;
    }
    val *= res;
    return val;
}
template<typename E>
E modPower(E val, intll expo, intll mod=BLN+7){
    E res = (E)1;
    while(expo > 0LL){
        // odd
        if(expo & 1LL) res = (res%mod) * (val%mod)%mod;
        expo >>= 1LL;
        val = (val%mod) * (val%mod) % mod;
    }
    return res%mod;
}
template<typename E>
void cookPrimes(vector<E> &primes, intll upto=MLN){
    bool p[upto];
    memset(p, false, sizeof(p));
    for(intll  i = 2 ;i*i <= upto ; i++){
        intll m = i * i;
        if(p[i] == false){
            while( m <= upto){
                p[m] = true;
                m += i;
            }
        }
    }
    for(intll i = 2 ; i <= upto; i++) if(p[i] == false) primes.push_back(i);
}

void stress_test(){
    string output_file="test.txt";
    intll test_count=100;
    File file(output_file, ios::out);
    intll test_no=1;
    string hline(50, '-');
    write("STARTED");
    while(test_no<=test_count){
        file.write(hline);
        file.write("TEST"," "), file.write(test_no++);
        file.write(hline);
        file.write("Input:");
        // generate inputs and write to file.

        file.write("\nCorrect Output:");
        //generate correct ouput and write to file.
        
        file.write("\nYour Output:");
        //generate your output and write to file.
        
        file.write("\nVERDICT:"," ");
        // compare correct and your output, return true if not matched else false.
        if(1){
            file.write("WA\n");
            write("FAILED");
            break;
        }
        file.write("AC\n");
    }
    file.close();
    write("COMPLETED");
}


int main(){
    BOOSTER
    intll n;
    read(n);
    intll arr[n];
    read(arr, n);
    double ans=1;
    for(double i=2; i<=n; i++) ans += (1.0 / i);
    cout<<fixed<<setprecision(6);
    write(ans);
    return 0;
}

