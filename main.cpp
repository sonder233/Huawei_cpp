#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <stack>
#include <set>
#include <iomanip>
#include<time.h>
#include <cmath>
#include <queue>

using namespace std;

void HJ11(){
    int a;
    while (cin >> a) { // 注意 while 处理多个 case
        string str = to_string(a);
        reverse(str.begin(),str.end());
        cout << str << endl;
    }
}

void HJ10(){
    string str = "uqic^g`(s&jnl(m#vt!onwdj(ru+os&wx";
//    string str = "abcccaaffb";
    int i = 1;
    while (i < str.length()){
        bool found = false;
        for (int j = 0; j <i; j++) {
            char str_j = str[j];
            char str_i = str[i];
            if (str_j == str_i){ //有相同的元素
                found = true;
            }
        }
        if (found){
            str.replace(i,1,"");
        } else{
            i++;
        }
    }
    cout<<str<<endl;
    cout<<str.length()<<endl;
//    auto it_end =  unique(str.begin(), str.end());
//    for(auto t = str.begin();t != it_end;t++){
//        cout<<*t<<endl;
//    }
}

void HJ13(){
    string str;
    getline(cin, str);
    int i = str.length()-1;
    int j = i;

    vector<string> vec;
    while(j >= 0){
        bool b = str[j] == ' ';
        if (b){
            vec.push_back(str.substr(j+1,i-j));
            j--;
            i = j;
        }else if(j==0){
            vec.push_back(str.substr(j,i-j+1));
            j--;
        }else{
            j--;
        }
    }
    for (int k = 0; k < vec.size(); ++k) {
        cout<<vec[k]<<endl;
    }
}

int icompare(string str1,string str2){
    char ch_a[str1.size()];
    char ch_b[str2.size()];
    for (int i = 0; i < sizeof(ch_a); ++i) {
        ch_a[i] = str1[i];
    }
    for (int i = 0; i < sizeof(ch_b); ++i) {
        ch_b[i] = str2[i];
    }
    int b = 1;  // str1 > str2 需要对换
    for (int i = 0,j=0; i <str1.length(),j<str2.length(); ++i,++j) {
//        if (str1[i]>str2[j]){
//            b= 1;
//        }
    }
    return strcmp(ch_a,ch_b);
}

void HJ14(){
    int n;
    cin>>n;
    vector<string> vec;
    string str;
    for (int i = 0; i < n; ++i) {
        cin>>str;
        vec.push_back(str);
    }
    std::sort(vec.begin(), vec.end());

//    bool sorted = false;
//    int size = vec.size();
//    while (!sorted){
//        sorted = true;
//        for (int i = 1; i < size; ++i) {
//            if (icompare(vec[i-1],vec[i])>0){
//                sorted = false;
//                //交换
//                string temp = vec[i-1];
//                vec[i-1] = vec[i];
//                vec[i] = temp;
//            }
//        }
//        size--;
//    }
    for (int i = 0; i < vec.size(); ++i) {
        cout<<vec[i]<<endl;
    }
//    int n =strcmp(b,c);
//    cout<< strcmp(b,c)  <<endl;
}

void HJ15(){
    int n;
    cin>>n;
    stack<int> s;
    int y;
    while (n >0){
        s.push(n%2);
        n /= 2;
    }
    int count = 0;
    while (!s.empty()){
        if (s.top() == 1){
            count++;
        }
        s.pop();

    }

    cout<<count<<endl;
}

string getPass(char str){
    string abc = "abc";
    string def = "def";
    string ghi = "ghi";
    string jkl = "jkl";
    string mno = "mno";
    string pqrs = "pqrs";
    string tuv = "tuv";
    string wxyz = "wxyz";
    if (isupper(str)){
        if (str == 'Z'){
            return "a";
        } else{
            return string(1,tolower(str)+1);
        }
    }else if (!isupper(str)){
        if (count(abc.begin(), abc.end(),str)>0){
            return "2";
        } else if(count(def.begin(), def.end(),str)>0){
            return "3";
        }else if(count(ghi.begin(), ghi.end(),str)>0){
            return "4";
        }else if(count(jkl.begin(), jkl.end(),str)>0){
            return "5";
        }else if(count(mno.begin(), mno.end(),str)>0){
            return "6";
        }else if(count(pqrs.begin(), pqrs.end(),str)>0){
            return "7";
        }else if(count(tuv.begin(), tuv.end(),str)>0){
            return "8";
        }else if(count(wxyz.begin(), wxyz.end(),str)>0){
            return "9";
        }
    } else{
        return to_string(str);
    }
    return "";
}
void HJ21(){
    string str = "YUANzhi1987";
    for (int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])){
            str.replace(i,1,getPass(str[i]));

        }
    }
    cout<<str<<endl;

}

int getBottle(int num){
    int count = 0;
    int a = num / 3 ;
    int b = num % 3 ;
    count += a;
    if (num == 2){
        count += 1;
    }else if (num == 1){
        count += 0;
    }else{
        count += getBottle(a+b);
    }
    return count;
}

void HJ22(){
    int number;
    while (cin >> number){
        if (number != 0){
            int count = 0;
            count += getBottle(number);
            cout<<count<<endl;
        }

    }
}

void HJ23(){
    string str = "aabcddd";
    vector<int> vec(26);
    //先统计出现个数
    for (int i = 0; i <= str.size() ; ++i) {
        vec[str[i] - 97] ++;
    }
    int min = 1000;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i]>0 && vec[i]<min){
            min = vec[i];
        }
    }
    for (int i = 0; i < str.size(); ++i) {
        if (vec[str[i]-97]>min){
            cout<<str[i];
        }
    }
}
void HJ35(){
    int n = 3;
    int arr[n][n] ;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int start = i*(i+1)/2 + 1;
        for (int j = 0; j < i + 1; ++j) {
            arr[i-j][j] = start++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] != 0){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
//int *getNextStep(int n,int arr[][n],int coord[]){
//    int x = coord[0];
//    int y = coord[1];
//    //右下左上
//    int arr1[5][5] = {{0,1,0,0,0},
//                     {0,1,1,1,0},
//                     {0,0,0,0,0},
//                     {0,1,1,1,0},
//                     {0,0,0,1,0}};
//}

bool isPassed(vector<int> index,vector<vector<int>> vec){
    bool b = false;
    for (int i = 0; i < vec.size(); ++i) {
        if (index[0] == vec[i][0] && index[1] == vec[i][1]) {
            b = true;
        }
    }
    return b;
}

void HJ43_fail(){
    int n = 5;
    int arr[5][5] = {{0,0,0,0,0},
                     {0,1,1,1,0},
                     {0,0,0,0,0},
                     {0,1,1,1,0},
                     {1,0,0,1,0}};
    int index[] = {0,0};
    stack<vector<int>> s;
    vector<vector<int>> passed;
    s.push(vector<int> {0,0});
    //记录一下当前栈头
    int x = s.top()[0];
    int y = s.top()[1];
    int count  =  0;
    while(!s.empty()){
        bool isDead = true;//是死路
        vector<int> vector1 = {x,y};
        arr[x][y] = 1;//把当前点设为1（等同于墙壁），代表走过了
        if (x - 1 >= 0 && arr[x - 1][y] == 0 && !isPassed({x - 1,y},passed)){ //上
            isDead = false;
            s.push(vector<int>{x - 1,y});
        }
        if(y-1 >= 0 && arr[x][y-1] == 0 && !isPassed({x,y-1},passed)){//左
            isDead = false;
            s.push(vector<int>{x,y-1});
        }
        if(y+1 < n && arr[x][y+1] == 0 && !isPassed({x,y+1},passed)){//右
            isDead = false;
            s.push(vector<int>{x,y+1});
        }
        if (x + 1 < n && arr[x + 1][y] == 0 && !isPassed({x+1,y},passed)){//下
            isDead = false;
            s.push(vector<int>{x + 1,y});
        }
        x = s.top()[0];
        y = s.top()[1];
        if (!isDead){//当前路已经无解了，走到死路了
            s.pop();
        }
        //passed.push_back(vector1);

        if (x == n-1 && y== n-1){
            cout<<"到终点了，确认了一条路线";
            for(auto v : passed){
                cout<<v[0]<<" "<<v[1]<<endl;
            }
            break;
        }
        cout<<s.size()<<endl;

    }
}
class position{
public:
    int x;
    int y;
    position(int a,int b){
        x = a;
        y = b;
    }
};
bool dfs(vector<vector<int>> map,int x,int y,vector<position> path){
    path.push_back(position(x,y));//添加当前坐标
    map[x][y] = 1;//标记此点
    //结束标志
    if (x== map.size()-1 && y == map[0].size()-1){
        return true;//?
    }
    //向下能走
    if (x+1<map.size() && map[x+1][y] == 0){
        if (dfs(map,x+1,y,path)){
            return true;
        }
    }
    //右
    if (y+1 < map[0].size() && map[x][y+1] == 0){
        if (dfs(map,x,y+1,path)){
            return true;
        }
    }
    //上
    if (x-1 >= 0 && map[x-1][y] == 0){
        if (dfs(map,x-1,y,path)){
            return true;
        }
    }
    //左
    if (y-1 >= 0 && map[x][y-1] == 0){
        if (dfs(map,x,y-1,path)){
            return true;
        }
    }
    //回溯（都不行，死路时）
    path.pop_back();//删除尾元素
    cout<<"pop"<<endl;
    map[x][y] = 0;//重新置为可通
    return false;

}

void HJ43_dfs(){
    int n ;
    int m;
    while(cin>>n>>m){
        vector<vector<int>> map;
        for (int i = 0; i < n; ++i) {
            vector<int> v;
            for (int j = 0; j < m; ++j) {
                int temp;
                cin>>temp;
                v.push_back(temp);
            }
            map.push_back(v);
        }
        vector<position> path;
        dfs(map,0,0,path);
        for (auto p : path) {
            cout<<"("<<p.x<<","<<p.y<<")"<<endl;
        }
    }


}


void HJ3(){
    int n;

    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        int i = 1;
        //去重
        while (i < v.size()) {
            auto it =find(v.begin(), v.begin()+i,v[i]);
            if (it != v.begin()+i){//查找成功
                v.erase(v.begin() + i);
            }else{
                i++;
            }
        }
        std::sort(v.begin(), v.end());
        for (auto v : v) {
            cout << v << endl;
        }
    }

}


class commodity{
public:
    int v;
    int p;
    int q;
    commodity(int value,int importance,int que){
        v = value;
        p = importance;
        q = que;
    }
};

int getSatisfy(vector<commodity> vec){
    int n= 0;
    for(auto c : vec){
        n += c.v*c.p;
    }
    return n;
}

void HJ16(){
    int N = 50;
    int n = 5;
    vector<commodity> vec;
    vec.push_back(commodity(20,3,5));
    vec.push_back(commodity(20,3,5));
    vec.push_back(commodity(10,3,0));
    vec.push_back(commodity(10,2,0));
    vec.push_back(commodity(10,1,0));

    //暴力解法
    vector<commodity> target;
    int current_money = 0;
    for (int i = 0; i < n; ++i) {

    }
}
void HJ17(){

    string str = "A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    while (cin>>str){
        //解析字符串
        vector<char> dir;
        vector<int> val;
        int i = 0;
        int j = 0;
        while (j<str.size()){
            if (str[j] != ';'){
                j++;
            }else{
                string temp = str.substr(i,j-i);

                if (temp[0] == 'A' || temp[0] == 'S' ||
                    temp[0] == 'D' || temp[0] == 'W'){
                    bool b = true;
                    for (int k = i+1; k < j; ++k) {
                        if (!isdigit(str[k])){
                            b = false;
                        }
                    }
                    if (b){
                        int number = atoi(temp.substr(1,temp.size()-1).c_str());
                        if (number < 100){
                            dir.push_back(temp[0]);
                            val.push_back(number);
                        }
                    }
                }
                i = j;

                j++;
                i++;
            }
        }
        int x = 0;
        int y = 0;
        for (int k = 0; k < dir.size() ; ++k) {
            if (dir[k] == 'A'){
                x -= val[k];
            }else if (dir[k] == 'D'){
                x += val[k];
            }else if (dir[k] == 'W'){
                y += val[k];
            }else if (dir[k] == 'S'){
                y -= val[k];
            }
        }
        cout<<"("<<x<<","<<y<<")"<<endl;

    }

}


void HJ56(){
    int m;
    int num = 0;
    while (cin>>m){
        for (int k = 2; k <= m; ++k) {
            int n = k;
            vector<int> vec;
            for (int i = 1; i<n ; ++i) {
                if (n % i == 0){
                    vec.push_back(i);
                }
            }
            int count=0;
            for(auto i : vec){
                count += i;
            }
            if (count == n){
                cout<<"yes"<<endl;
                num++;
            }
        }

    }
}

bool isPrime(int n){
    bool b = true;
    for (int i = 2; i*i <= n ; ++i) {
        if (n%i == 0){
            b = false;
        }
    }
    return b;
}

void HJ60(){
    int n = 4;
    while(cin>>n){
        for (int i = n/2; i >0 ; --i) {
            if (isPrime(i) && isPrime(n-i)){
                cout<<i<<endl;
                cout<<n-i<<endl;
                break;
            }
        }
    }
}

int getNumber(int apple , int plate){
    if ( apple == 0 || plate == 1){
        return 1;
    }else if (plate>apple){
        return getNumber(apple,apple);
    }else{
        return getNumber(apple,plate-1) + getNumber(apple-plate,plate);
    }

}

void HJ73(){
    int y = 1900;
    int m = 3;
    int d = 1;
    while (cin>>y>>m>>d){
        vector<int> day = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (y % 400 == 0 || (y%4==0 && y%100 != 0)){
            day[1] = 29;
        }
        int count = 0;
        for (int i = 0; i < m-1; ++i) {
            count += day[i];
        }
        count += d;
        cout<<count<<endl;
    }
}

void HJ76(){
    int n = 3;
    while(cin>>n){
        int first = n*n-n+1;
        string str = "";
        for (int i = 0,j = first; i < n; ++i,j += 2) {
            str += to_string(j);
            if (i != n-1){
                str += "+";
            }
        }
        cout<<str;
    }
}

void HJ80(){ //整型数组合并
    int m = 3;
    int n;
    cin>>m;
    vector<int> vec;
    for (int i = 0; i < m; ++i) {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    set<int> s(vec.begin(),vec.end());
    for(auto a : s){
        cout<<a;
    }
}

void HJ83(){//字符串匹配
    string str_s;
    string str_b;
    while(cin>>str_s>>str_b){
        bool res = true;
        for (int i = 0; i < str_s.size(); ++i) {
            bool b= false;
            for (int j = 0; j < str_b.size(); ++j) {
                if (str_s[i] == str_b[j]){
                    b = true;
                }
            }
            if (!b){
                res = false;
                break;
            }

        }
        if (res){
            cout<<"true";
        }else{
            cout<<"false";
        }
    }
}
int getLen(string str,int low, int high){
    while (-1 < low && high < str.size() && str[low] == str[high]){
        low--;
        high++;
    }
    return high-low-1;
}
void HJ85(){//最长回文子串
    string str = "cdabbacc";
    while(cin>>str){
        int len = 0;
        //遍历回文中心
        for (int i = 0; i < str.size(); ++i) {
            int x = getLen(str,i,i) ;//奇数中心
            int y = getLen(str,i,i+1);//偶数中心
            len = max(max(x,y),len);
        }
        cout<<len<<endl;
    }


}

void HJ86(){
    int n = 1;
    while (cin>>n){
        vector<int> vec;
        while (n != 0){
            vec.push_back(n%2);
            n /= 2;
        }

        reverse(vec.begin(),vec.end());
        int result = 0;
        int count_max = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == 1) {
                count_max++;
                result = max(count_max,result);
            }else{
                result = max(count_max,result);
                count_max = 0;
            }
        }
        cout<<result<<endl;
    }

//    for(auto i:vec){
//        cout<<i;
//    }
}
void HJ87(){
    string str = "38$@NoNoN";
    int len_mark = 0;
    int al_mark = 0;
    int di_mark = 0;
    int other_mark = 0;
    int reward = 0;

    //密码长度
    if (str.length() <= 4){
        len_mark = 5;
    }else if(str.length() <= 7){
        len_mark = 10;
    }else{
        len_mark = 25;
    }

    //字母得分
    bool haveUpper = false;
    bool haveLower = false;
    //数字
    int count_Number = 0;
    int count_Other = 0;
    for(auto i : str){
        if (islower(i)){
            haveLower = true;
        }
        if (isupper(i)){
            haveUpper = true;
        }
        if (isdigit(i)){
            count_Number++;
        }
//        int temp = i;
//        cout<<hex<<i<<endl;
        if ((0x21 <= i && i<=0x2f)
            ||  (0x3A <= i && i<=0x40)
            ||  (0x5B <= i && i<=0x60)
            ||  (0x7B <= i && i<=0x7E)
            ){
            count_Other++;
        }
    }
    if ( haveUpper && haveLower){
        al_mark = 20;
    }else if(!haveLower && !haveUpper){
        al_mark = 0;
    }else{
        al_mark = 10;
    }

    if (count_Number==0){
        di_mark = 0;
    }else if(count_Number ==1){
        di_mark = 10;
    }else{
        di_mark = 20;
    }
    if (count_Other==0){
        other_mark = 0;
    }else if(count_Other ==1){
        other_mark = 10;
    }else{
        other_mark = 25;
    }

    if (haveUpper && haveLower && count_Other >0 && count_Number >0){
        reward = 5;
    }else if ((haveLower || haveUpper) && count_Other>0 && count_Number>0  ){
        reward = 3;
    }else if((haveLower || haveUpper) && count_Number>0){
        reward = 2;
    }

    int result = len_mark+al_mark+di_mark+other_mark+reward;
    if (result >= 90){
        cout<<"VERY_SECURE";
    }else if (result >= 80){
        cout<<"SECURE";
    }else if (result >= 70){
        cout<<"VERY_STRONG";
    }else if (result >= 60){
        cout<<"STRONG";
    }else if (result >= 50){
        cout<<"AVERAGE";
    }else if (result >= 25){
        cout<<"WEAK";
    }else{
        cout<<"VERY_WEAK";
    }

}

int getStep(int i,int j,int m, int n){
    if (i == n || j == m){
        return 1;
    }
    return getStep(i+1,j,m,n)+ getStep(i,j+1,m,n);
}

void HJ91(){
    int n =2;
    int m = 2;
    while(cin>>n>>m){
        cout<<getStep(0,0,n,m);
    }
}
void HJ94(){
    int num_people = 4;
    vector<pair<string,int>> people;
    while (cin>>num_people){
        map<string,int> map_score;
        for (int i = 0; i < num_people; ++i) {
            string str_cin;
            cin>>str_cin;
            people.push_back(make_pair(str_cin,0));
        }
        int num_votes = 8;
        cin>>num_votes;
        int Invalid = 0;
        for (int i = 0; i < num_votes; ++i) {
            string str_vote;
            cin>>str_vote;
            bool b = false;
            for (int j = 0; j < people.size(); ++j) {
                if (people[j].first == str_vote){
                    b = true;
                    people[j].second++;
                    break;
                }
            }
            if (!b){
                Invalid++;
            }
        }
//        for(auto i :  ){
//            cout<<i.first<<" : "<<i.second<<endl;
//        }
        cout<<"Invalid : "<<Invalid<<endl;
    }


}

void HJ97(){
    double positive = 0;
    double p_count = 0;
    double number_p=0;
    int number_n=0;
    int n;
    while (cin>>n) {
        for (int i=0; i<n; i++) {
            int t ;
            cin>>t;
            if (t<0) {
                number_n++;
            }else if(t>0){
                positive += t;
                number_p++;
            }
        }

        cout<<number_n<<" ";
        if (number_p >0) {
            cout<<fixed<<setprecision(1)<<positive/number_p;
        }else{
            cout<<"0.0";
        }
    }
}

void HJ99(){
    int n = 6;
    while (cin>>n){
        int count = 0;
        for (int m = 0; m <= n; ++m) {
            string str_1 = to_string(m);
            string str_2 = to_string(m*m);
            bool b = true;
            for (int i = str_2.size()-1,j = str_1.size()-1;
                 j>=0; --j,--i) {
                if (str_1[j] != str_2[i]){
                    b = false;
                }
            }
            if (b){
                count++;
            }
        }
        cout<<count<<endl;
    }
}
void HJ96(){
    string str = "i234kl7b";
    while (cin >> str) {
        int i = 0;
        int j = 0;
        while (j < str.size()) {
            if (!isdigit(str[i]) && !isdigit(str[j])) {
                i++;
                j++;
            } else if (isdigit(str[i]) && isdigit(str[j])) {
                if (j == str.size()-1){
                    str.insert(i, "*");
                    str.append("*");
                    break;
                }
                j++;
            } else if (isdigit(str[i]) && !isdigit(str[j])) {
                str.insert(j, "*");
                str.insert(i, "*");
                i = j;
                i++;
                j++;
            }

        }
        cout << str;
    }
}




void HJ26(){
    string str = "A Famous Saying: Much Ado About Nothing (2012/8).";
    while(getline(cin,str)){

        vector<char> vec;
        for (int i = 0; i < str.size(); ++i) {
            if (!isspace(str[i]) && (isupper(str[i]) || islower(str[i])) ){
                vec.push_back(str[i]);
            }
        }
        //冒泡排序，稳定
        bool sorted = false;
        while (!sorted){
            sorted = true;
            for (int i = 1; i < vec.size(); ++i) {
                char left = vec[i-1];
                char right = vec[i];
//            bool swap = false;
                if (!isalpha(vec[i-1]) || !isalpha(vec[i])){
                    continue;
                }
                if ((abs(vec[i-1] -vec[i]) == 32)
                    || vec[i-1] == vec[i]){//是一个字母的大小写 or 同一个字母
                    continue;
                }else if (::tolower(left) > ::tolower(right)){
                    //交换
                    char temp = vec[i-1];
                    vec[i -1] = vec[i];
                    vec[i] = temp;
                    sorted = false;
                }
            }


        }
        for (int i = 0,j=0; j < str.size();++j) {
            if (isalpha(str[j])){
                str[j] = vec[i];
                i++;
            }
        }
        cout<<str<<endl;

    }
}

int climbStairs(int n){
    if (n<=1) return 1;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}

void getMaxArrayNum(){
    int n;
    vector<int> vec = {10,9,2,5,3,7,101,18};
    vector<int> dp(vec.size());
    int maxNum = 1;
    dp[0] = 1;
    //求出dp[i]
    for (int i = 1; i < vec.size(); ++i) {
        dp[i] = 1;//默认为1
        for (int j = 0; j < i; ++j) {
            //找到比vec[i]小的数
            if (vec[i]<vec[j]){
                dp[i] = max(dp[i],dp[j]+1);//可能会有多个 所以取个大的
            }
        }
        //dp[i]中最大的就是要求的了
        maxNum = max(dp[i],maxNum);
    }
    cout<<maxNum<<endl;
}

void printTwo(){

}

void myBag(){
    int m = 4;//物品的数量
    int n = 8;//背包容量
    vector<int> w = {0,2,3,4,5};
    vector<int> v = {0,3,4,5,8};
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));//m行n列
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (w[i]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }
        }
    }

    for (auto i : dp) {
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<dp[m][n]<<endl;

}

int haveSameSub(string str){
    int max = 0;

    for (int i = 0; i < str.size(); ++i) {
        int start = i;
        int j = i+1;
        int max_temp = 0;
        while (j<str.size()){
            if (str[start] == str[j]){
                start++;
            }else{
                 if (start != i && (start - i)>max_temp){
                    max_temp = start-i;
                }
                start = i;
            }
            if (j == str.size()-1 && start != i && (start - i) > max_temp){
                max_temp = start-i;

            }
            if (max_temp > max){
                max = max_temp;
            }
            j++;

        }
    }
    return max;
}
// 398h$ 720CD 0h&7f 9~A40 3mex~ lu#$* 0+0CD 0
void HJ20(){
    string str = "021Ab9Abc1";
    while (cin>>str){
        bool b = true;
        if (str.size()<=8){
            b = false;
        }
        bool upper,lower,digit,other;
        for (auto item : str) {
            if (isupper(item)){
                upper=true;
            }else if (islower(item)){
                lower = true;
            }else if (isdigit(item)){
                digit = true;
            }else{
                other = true;
            }
        }
        int count = 0;
        if (upper){
            count++;
        }
        if (lower){
            count++;
        }
        if (digit){
            count++;
        }
        if (other){
            count++;
        }
        if (count<3){
            b = false;
        }
        if (haveSameSub(str)>2){
            b = false;
        }
        if (b){
            cout<<"OK"<<endl;
        }else{
            cout<<"NG"<<endl;
        }
//        if (b){
//            vec.push_back("OK");
//        }else{
//            vec.push_back("NG");
//        }

    }
}

void HJ27(){
    int n = 3;
    while (cin>>n){
        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            string temp;
            cin>>temp;
            vec.push_back(temp);
        }
        string key = "abc";
        cin>>key;
        int m = 1;
        cin>>m;
        vector<string> bro ;
        int count = 0;
        for(int i = 0;i<vec.size();i++){
            if (vec[i].compare(key) != 0
                && vec[i].size() == key.size()){ //不完全相同
                string old = vec[i];
                sort(old.begin(),old.end());
                string key_sorted = key;
                sort(key_sorted.begin(),key_sorted.end());
                if (old.compare(key_sorted) == 0){ //相等
                    bro.push_back(vec[i]);
                }
            }
        }
        cout<<bro.size()<<endl;
        sort(bro.begin(),bro.end());

        if(!bro.empty()) cout<<bro[m-1]<<endl;

    }
}

void HJ29(){
    string info = "2OA92AptLq5G1lW8564qC4nKMjv8C";
    string code = "B5WWIj56vu72GzRja7j5";

    for (int i = 0; i < info.size(); ++i) {
        if (isupper(info[i])){
            if (info[i] == 'Z'){
                info[i] = 'a';
            }else{
                info[i] = ::tolower(info[i])+1;
            }
        }else if(islower(info[i])){
            if (info[i] == 'z'){
                info[i] = 'A';
            }else{
                info[i] = ::toupper(info[i])+1;
            }
        }else if(isdigit(info[i])){
            if (info[i] == '9'){
                info[i] = '0';
            }else{
                info[i]++;
            }
        }
    }
    cout<<info<<endl;
    //解码
    for (int i = 0; i < code.size(); ++i) {
        if (isupper(code[i])){
            if (code[i] == 'A'){
                code[i] = 'z';
            }else{
                code[i] = ::tolower(code[i])-1;
            }
        }else if(islower(code[i])){
            if (code[i] == 'a'){
                code[i] = 'Z';
            }else{
                code[i] = ::toupper(code[i])-1;
            }
        }else if(isdigit(code[i])){
            if (code[i] - '0' == 0){
                code[i] = '9';
            }else{
                code[i]--;
            }
        }
    }
    cout<<code<<endl;


}
int getMaxSub(string str,int i,int j){
    while (i > -1 && j < str.size() && str[i] == str[j]){
        i--;
        j++;
    }
    return j-i-1;
}
void HJ32(){
    string str = "ABBBA";
    int maxNum = 0;
    for (int i = 0; i < str.size(); ++i) {
        maxNum = max(maxNum,max(getMaxSub(str,i,i), getMaxSub(str,i,i+1)));
    }
    cout<<maxNum<<endl;
}

string dec_to_bin(long n){
    //要拼成8位
    string result ="";
    stack<int> s;
    while (n != 0){
        s.push(n%2);
        n /= 2;
    }
    while (!s.empty()){
        result += to_string(s.top()) ;
        s.pop();
    }
    if(result.length() < 8){
        string head(8 - result.length(),'0');
        result = head + result;
    }
    return result;
}
long bin2dec(string bin){
    long num_dec = 0;
    reverse(bin.begin(),bin.end());
    for (int i = 0; i < bin.size(); ++i) {
        num_dec += pow(2,i) * (bin[i] - '0');
    }
    return num_dec;
}


void HJ33(){
    string ip = "10.0.3.193";
    string ip_dec_str = "3868643487";
    istringstream iss(ip);
    string token;//接受缓冲区
    vector<int> vec;

    string bin_str = "";

    while (getline(iss,token,'.')){
        vec.push_back(::atoi(token.c_str()));
    }

    for(auto item : vec){
        bin_str += dec_to_bin(item);
    }
//    cout<<bin_str<<endl;
    long dec_res = bin2dec(bin_str);
    cout<<dec_res<<endl;
    long long ip_dec = ::atoi(ip_dec_str.c_str());
    string ip_bin_str = dec_to_bin(ip_dec);

    if(ip_bin_str.length() < 32){
        string head(32 - ip_bin_str.length(),'0');
        ip_bin_str = head + ip_bin_str;
    }
    vector<string> ip_bin_sub;

    //分割
    for (int i = 0; i < ip_bin_str.size(); i += 8) {
        string temp = ip_bin_str.substr(i,8);
        ip_bin_sub.push_back(temp);
    }
    string ip_result = "";
    for (int i = 0; i < ip_bin_sub.size();i++) {
        ip_result += to_string(bin2dec(ip_bin_sub[i]));
        if( i != ip_bin_sub.size()-1){
            ip_result += ".";
        }
    }
    cout<<ip_result<<endl;

}
void HJ33_bit(){
    long long int x,y,m,n;
    long long int num;
    while (::scanf("%lld.%lld.%lld.%lld",&x,&y,&m,&n) != EOF){
        cout<<(x<<24)+(y<<16)+(m<<8)+(n)<<endl;
        cin>>num;
        long long int a = num >> 24;
        num = num - (a<<24);
        long long int b = num >> 16;
        num = num - (b<<16);
        long long int c = num >> 8;
        long long int d = num - (c<<8);
        cout<<a<<"."<<b<<"."<<c<<"."<<d<<endl;
    }
}

void HJ36(){
    string key = "nihaoin";
    string info = "ni";
    while(cin>>key>>info){
        int al[26] = {0};
        string head = "";
        string tail = "";
        for (int i = 0; i < key.size(); ++i) {
            if (al[key[i] - 97] != 1){
                head += key[i];
                al[key[i] - 97] = 1;
            }
        }

        for (int i = 0 ; i < size(al); i++) {
            if (al[i] == 0){
                tail += char(i+97);
            }
        }

        string new_al = head + tail;
        string result = "";
        for (int i = 0; i < info.size(); ++i) {
            result += new_al[info[i] - 97];
        }
        cout<<result<<endl;
    }


}
void HJ38(){
    double h = 1;
    double h_5 = h*pow(0.5,5);
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += h+h/2;
        h /= 2;
    }
    sum -= h_5;
    cout<<fixed<<setprecision(6)<<sum<<endl;
    cout<<h_5<<endl;
}

void HJ41(){
    //暴力算法
    int n = 2;
    vector<int> w = {1,2};
    vector<int> num = {2,1};
    vector<vector<int>> weights;
    for (int i = 0; i < w.size(); ++i) {
        vector<int> temp;
        for (int j = 0; j <= num[i]; ++j) {
            temp.push_back(w[i]*j);
        }
        weights.push_back(temp);
    }
    set<int> s;
    for (int i = 0; i < weights.size(); ++i) {
        for (int j = 0; j < weights[i].size(); ++j) {
//            s.insert(weights)
        }
    }
    cout<<endl;
}

typedef pair<char, int> PAIR;

struct CmpByValue{
    bool operator()(const PAIR& left,const PAIR& right){
        return left.second > right.second;
    }
};

void HJ45(){
    string str = "zhangsan";
    map<char,int> m;
    for (int i = 0; i < str.size(); ++i) {
        if (m.count(str[i]) == 0){
            m.insert(make_pair(str[i],1));
        }else{
            m[str[i]]++;
        }
    }
    vector<PAIR> vec_map(m.begin(),m.end());

    sort(vec_map.begin(),vec_map.end(),CmpByValue());

//    for (auto item : vec_map) {
//        cout<<item.first<<" "<<item.second<<endl;
//    }
    int sum = 0;
    int beauty = 26;
    for (int i = 0; i < vec_map.size(); ++i) {
        sum += vec_map[i].second*beauty;
        beauty--;
    }
    cout<<sum<<endl;
}

class list{
public:

};

void HJ37(){
    int n = 7;
    int rabbit_two = 1;
    int rabbit_one = 0;
    int rabbit_old = 0;
    for (int i = 0; i < n-1; ++i) {
        int temp = rabbit_two;
        if (rabbit_old > 0){
            rabbit_two += rabbit_old;
        }
        if (rabbit_one>0){
            rabbit_old += rabbit_one;
            rabbit_two += rabbit_one;
            rabbit_one = 0;
        }
        if (temp > 0){
            rabbit_two -= temp;
            rabbit_one += temp;
        }
    }
    cout<<rabbit_one+rabbit_two+rabbit_old<<endl;

}

void HJ48(){

}
void HJ50(){

}

bool contain_7(int number){
    string str =  to_string(number);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '7'){
            return true;
        }
    }
    return false;
}

void HJ55(){
    int n = 198;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        if ( i%7 == 0 || contain_7(i)){
            sum++;
        }
    }
    cout<<sum<<endl;
}

string plus_str(string num_1,string num_2){
    string result = "";
    reverse(num_1.begin(),num_1.end());
    reverse(num_2.begin(),num_2.end());
    int m = 0;
    int i = 0,j = 0;
    for (; i < num_1.size(),j < num_2.size(); ++i,++j) {
        int a = num_1[i] - '0';
        int b = num_2[j] - '0';
        if (a+b+m>9){
            m = 1;
        }
        result += to_string((a+b+m)%10);
    }
}

void HJ57(){
    string num_1 = "58797810";
    string num_2 = "80834732";

    if (num_2.length()>num_1.length()){
        swap(num_1,num_2);
    }
    string result = "";
    reverse(num_1.begin(),num_1.end());
    reverse(num_2.begin(),num_2.end());
    int m = 0;
    int i = 0,j = 0;
    for (; i < num_1.size(),j < num_2.size(); ++i,++j) {
        int a = num_1[i] - '0';
        int b = num_2[j] - '0';
        string tail = "";
        if ( j == num_1.length()-1 && a+b+m >9){
            tail =to_string(a+b+m);
            reverse(tail.begin(),tail.end());
            result += tail;
        }else{
            result += to_string((a+b+m)%10);
        }
        if (a+b+m>9){
            m = 1;
        }else{
            m = 0;
        }
    }
    if (m == 1){
        for (int k = i; k < num_1.length(); ++k){
            int c = num_1[k] - '0';
            if (k == num_1.length()-1 && c+m >9){
                string tail =to_string(c+m);
                reverse(tail.begin(),tail.end());
                result += tail;
            }else{
                result += to_string((c+m)%10);
            }
            if (c + m > 9){
                m = 1;
            }else{
                m = 0;
            }

        }
    }else{
        result += num_1.substr(i,num_1.size());
    }
    reverse(result.begin(),result.end());
    cout<<result<<endl;

}

void HJ59(){
    string str = "asdfasdfo";
    bool b = false;
    for (int i = 0; i < str.size(); ++i) {
        if (std::count(str.begin(), str.end(),str[i])==1){
            cout<<str[i]<<endl;
            b = true;
            break;
        }
    }
    if (!b){
        cout<<-1<<endl;
    }
}

void HJ63(){
    string dna = "AACTGTGCACGACCTGA";
    int n = 5;
    int sum = 0;
    string result = "";
    for (int i = 0; i < dna.length()-n+1; i++) {
        string temp = dna.substr(i,5);
        int m = 0;
        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j] == 'C' || temp[j] == 'G'){
                m++;
            }
        }
        if (m>sum){
            sum = m;
            result = temp;
        }
    }
    cout<<result<<endl;
}
void HJ64(){
    int n = 2;
    string order = "DUDUDDUUDUDDDDUDUDDDUUDDUDDUDUDUDDDUDUDUUDDUUDDUUUDUDUUUDDUDUDDUUDUDDDDUDUDUUDUDDDDDUU";
    int index = 1;
    int left = 1;
    int right = 4;
    if (n <= 4){
        right = n;
        for (int i = 0; i < order.length(); ++i) {
            if (order[i] == 'U'){
                if (index == 1){
                    index = n;
                }else{
                    index--;
                }
            }else{
                if (index == n){
                    index = 1;
                }else{
                    index++;
                }
            }
        }
    }else{
        for (int i = 0; i < order.length(); ++i) {
            if (left < index && index < right){
                if (order[i] == 'U') index--;
                else index++;
            }else if(index == left && order[i] == 'D') {
                index++;
            }else if(index == right && order[i] == 'U'){
                index--;
            }else{
                if (order[i] == 'U' && index == 1){
                    index = n;
                    left = n -3;
                    right = n;
                }else if (order[i] == 'D' && index == n){
                    index = 1;
                    left = 1;
                    right = 4;
                }else if (order[i] == 'U'){
                    left--;
                    right--;
                    index--;
                }else if (order[i] == 'D'){
                    left++;
                    right++;
                    index++;
                }
            }

        }
    }
    for (int i = left; i <= right; ++i) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<index<<endl;

}

void HJ65(){
    string str_1 = "abcdefghijklmnop";
    string str_2 = "abcsafjklmnopqrstuvw";
    string sub = "";
    for (int i = 0; i < str_1.size(); ++i) {
        int index = str_2.find_first_of(str_2[i]);
        cout<<index;
    }
}
bool isSame_ad(char a,char b){
    if (isdigit(a) && isdigit(b)){
        return a == b;
    }else if (isalpha(a) && isalpha(b)){
        return ::tolower(a) == ::tolower(b);
    }else{
        return false;
    }
}
void HJ71(){
    string s_1 = "h*h*ah**ha*h**h***hha";
    string s_2 = "hhhhhhhahhaahhahhhhaaahhahhahaaahhahahhhahhhahaaahaah";
    int i = 0;
    int j = 0;
    string r = "true";

    while (i < s_1.size() && j < s_2.size()){
        char c_1 = s_1[i];
        char c_2 = s_2[j];
        if (isSame_ad(s_1[i] , s_2[j])){
            i++;
            j++;
        }else if( s_1[i] != '?'
               && s_1[i] != '*'){
            r = "false";
        }else{
            if (s_1[i] == '?'){
                if(!isalpha(s_2[j]) && !isdigit(s_2[j])){
                    r = "false";
                }else{
                    i++;
                    j++;
                }
            }else if (s_1[i] == '*'){
                if (i < s_1.size()-1){

                    char right = s_1[i+1];//找到星号下一个
                    int m = j;
                    for (int k = j; k < s_2.size(); ++k) {
                        if (right == s_2[k]){
                            m =k;
                            break;
                        }
                    }
                    if (m == j) {//没有找到
                        r = "false";
                        break;
                    }else{
                        i++;
                        j = m;
                    }
                }else{//最后一个 且为*
                    int q = j;
                    for (; q < s_2.size(); ++q) {
                        if (!isdigit(s_2[q]) && !isalpha(s_2[q])){
                            r = "false";
                            break;
                        }
                    }
                    j = q;
                    i++;j++;
                }
            }
        }

    }
    if (i < s_1.size() || j < s_2.size()){
        r = "false";
    }
    cout<<r<<endl;
}
void HJ74(){
    string order = "xcopy /s \"C:\\\\program files\" \"d:\\\"";
    // xcopy /s c:\\ d:\\e
    // xcopy /s "C:\\program files" "d:\"
    vector<string> vec;
    bool havaLeft = false;
    int i = 0;
    int j = 0;
    while ( j < order.length()){
        char c_i = order[i];
        char c_j = order[j];
        if (isspace(order[j])){

            if (havaLeft){//有左引号
                j++;
            }else{//没有左引号
                vec.push_back(order.substr(i,j-i));
                j++;
                i = j;
            }
        }else if(j == order.size()-1){
            if (order[j] == '"'){
                vec.push_back(order.substr(i,j-i));
            }else{
                vec.push_back(order.substr(i,j-i+1));
            }

            j++;
        }else if(order[j] == '"'){
            // xcopy /s "C:\\program files" "d:\"
            if (havaLeft){
                vec.push_back(order.substr(i,j-i));
                j += 2;
                i = j;
                havaLeft = false;
            }else{
                havaLeft = true;
                i++;
                j++;
            }
        }else{//既不是空格，也不是引号
            j++;
        }
    }
    cout<<vec.size()<<endl;
    for (auto item : vec) {
        cout<<item<<endl;
    }
}

stack<int> stack_wash(stack<int> b,stack<int> s,stack<int> a){
    if (!s.empty()) s.push(a.top());
    stack<int> out = b;
    out.push(s.top());

}

void HJ77(){
    int n = 3;
    stack<int> b;
    stack<int> s;
    stack<int> a;
    for (int i = 3; i>0; i--) {
        b.push(i);
    }

}

bool isDigit(string str){
   bool r = true;
   for(char c : str){
       if (!isdigit(c)){
           r = false;
           break;
       }
   }
    return r;

}

void HJ90(){
    string ip = "+1.2.3.8";
    vector<string> vec;
    istringstream iss(ip);
    string token;
    bool b = true;
    while (getline(iss,token,'.')){
        if (token == ""){
            cout<<"NO";
            return;
        }
        vec.push_back(token);
    }


    if (vec.size()==4){
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i][0] == '0' && vec[i].length()>1){
                b = false;
                break;
            }
            if (!isDigit(vec[i]) || (::atoi(vec[i].c_str())>255 || ::atoi(vec[i].c_str())<0)){
                b = false;
                break;
            }
        }
    }else{
        b = false;
    }
    if (b){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}
void HJ92(){
    string str = "a8a72a6a5yy98y65ee1r2";
    int i = 0;
    int j = 0;
    vector<string> vec;
    while (j < str.length()){
        char c_i = str[i];
        char c_j = str[j];
        if (!isdigit(c_i) && !isdigit(c_j)){
            i++;
            j++;
        }else if (isdigit(c_i) && isdigit(c_j) && j != str.length()-1){
            j++;
        }else if ((isdigit(str[i]) && !isdigit(str[j]))
                 || (isdigit(str[i]) && j == str.length()-1 )){
            string digitString = "";
            if(j == str.length()-1){
                digitString = str.substr(i,j-i+1);
            }else{
                digitString = str.substr(i,j-i);
            }
            if (vec.empty()){
                vec.push_back(digitString);
            }else{
                if (digitString.length() > vec[0].length()){
                    vec.clear();
                    vec.push_back(digitString);
                }else if(digitString.length() == vec[0].length()){
                    vec.push_back(digitString);
                }
            }
            j++;
            i=j;
        }
    }
    for(auto item : vec){
        cout<<item;
    }
    cout<<","<<vec[0].length();
}

int getMaxSubque(vector<int> nums){
    vector<int> dp(nums.size());//初始化为0
    dp[0] = 1;
    for (int i = 0; i < nums.size() ; ++i) {
        int Max = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]){
                Max = max(Max,dp[j] + 1);
            }
        }
        dp[i] = Max;
    }
    int final_max = 0;
    for(int item : dp){
        final_max = max(final_max,item);
    }
    return final_max;
}


void HJ103(){
    int n = 6;
    int Max = 1;
    int nums[] = {2,5,1,5,4,5};
    for (int i = 0; i < n ; ++i) {
        vector<int>  rightNum;
        //拷贝部分
        for (int j = i; j < n; ++j) {
            rightNum.push_back(nums[j]);
        }
        Max = max(Max,getMaxSubque(rightNum));
    }
    cout<<Max<<endl;

}

#define eps 1e-5 //精度
void HJ107(){
    double num,left,right,mid;
    while(cin>>num){
        left = min(-1.0,num);
        right = min(1.0,num);
        while (::fabs(right - left)>eps){
            mid = (right + left) / 2;
            if (mid * mid * mid <num){
                left = mid;
            }else{
                right = mid;
            }
        }
    }
    ::printf("%.1f",mid);
}

void HJ66(){

}

int main() {
    float n;
    int token;
    int number_neg = 0;
    float sum = 0;
    float number = 0;
    while (cin >> n) { // 注意 while 处理多个 case
        if (n<0) {
            number_neg++;
        }else{
            number++;
            sum += n;
        }
    }
    cout<<number_neg<<endl;
    if (number > 0 ) {
        cout<<fixed<<setprecision(sum/number)<<endl;
    }else{
        cout<<fixed<<setprecision(0.0)<<endl;
    }
    HJ103();
//    cout<<getBinary(6)<<endl;

//    string a = "dacbb";
//    string b = "aabad";
//    sort(a.begin(),a.end());
//    sort(b.begin(),b.end());
//
//    cout<<a.compare(b);





//    map<int,int> memo;
//
//    clock_t s,e;
//    s=clock();
//    //---------------------------------------
//    myBag();
//    //---------------------------------------
//    e=clock();
//    cout<<"T="<<(double(e-s)/CLOCKS_PER_SEC)<<"s\n";
//    cout<<"T="<<(1000*double(e-s)/CLOCKS_PER_SEC)<<"ms\n";
    return 0;
}
