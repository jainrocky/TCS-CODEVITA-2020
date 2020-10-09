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


bool not_stop(intll *v, intll *pos, intll h){
    for(int i=0; i<4; i++) if(v[i]!=0 and ((v[i]<0 and pos[i]>0) or (v[i]>0 and pos[i]<h))) return true;
    return false;
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(
        power((x1-x2), 2ll) + power((y1-y2), 2ll)
    );
}

int main(){
    BOOSTER
    intll h;
    read(h);
    intll pos[4];
    read(pos, 4);
    intll v[4];
    read(v, 4);
    char dir[4];
    read(dir, 4);

    //signed velocity 
    //positive for upward motion and negative for downward motion
    for(int i=0; i<4; i++)
        if(dir[i]=='D') v[i]*=-1;

    //sides of both the triangle having 'ca' as common side
    double ab, bc, ca, ad, dc;
    //total_area of triangle and semiperimeter of both the triangles
    double total_area, s1, s2;
    //answer to be print
    intll max_area, min_area;


    ab=distance(0, pos[0], h, pos[1]);
    bc=distance(0, pos[1], h, pos[2]);
    
    ca=distance(0, pos[0], h * 1.41421, pos[2]);

    ad=distance(0, pos[0], h, pos[3]);
    dc=distance(0, pos[3], h, pos[2]);

    s1 = (ab+bc+ca)/2.0;
    s2 = (ad+dc+ca)/2.0;

    total_area = sqrt(  s1 * (s1-ab) * (s1-bc) * (s1-ca) ) + sqrt(s2 * (s2-ad) * (s2-dc) * (s2-ca));
    total_area = power(total_area, 2ll);
    total_area *= 4.0;
    min_area=max_area=round(total_area);

    while(not_stop(v, pos, h)){
        for(int i=0; i<4; i++) pos[i] = v[i] >= 0 ? min((pos[i] + v[i]), h): max((pos[i] + v[i]), 0ll);
        ab=distance(0, pos[0], h, pos[1]);
        bc=distance(0, pos[1], h, pos[2]);
        
        ca=distance(0, pos[0], h * 1.41421, pos[2]);

        ad=distance(0, pos[0], h, pos[3]);
        dc=distance(0, pos[3], h, pos[2]);

        s1 = (ab+bc+ca)/2.0;
        s2 = (ad+dc+ca)/2.0;
        total_area = sqrt(  s1 * (s1-ab) * (s1-bc) * (s1-ca) ) + sqrt(s2 * (s2-ad) * (s2-dc) * (s2-ca));
        total_area = power(total_area, 2ll);

        total_area *= 4.0;

        total_area = round(total_area);
        min_area = min(min_area, (intll) total_area);
        max_area = max(max_area, (intll) total_area);
    }
    write(max_area, " "), write(min_area);

    return 0;
}




