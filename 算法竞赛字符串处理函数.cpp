#include <bits/stdc++.h>
using namespace std;
int main(){
	//1、字符串输入输出 
    string s;
	cin >> s; //输入String cin是以空格，回车作为结束输入的标志
    cout<< s <<endl; //输出为Hello
    // int n = s.size();
    //2、字符串拼接 
    //支持使用 + 连接字符串
    s = " " + s; // 常用拼接：for i: 1 to n
    
    //3、读取一行字符(cin.getline())并根据空格分割
	// cin.getline定义在<iostream>下，如：a[n] 则最多读取 n-1个字符 
	// cin.getline(a,8);
    string t;
    getline(cin, t); //* getline()函数读取一行字符串，包含空格
    stringstream ss(t); //将字符串转换为字符串流
    while(ss >> t) {
        cout << t << " "; //输出每个以空格隔开的单词
    } 
    cout << endl;
	
    //4、获取字符串的长度
	//size() , length()
	
    //5、可以把字符串当成字符数组使用
    cout << s[1]; //输出第一个字符(前面已和空格拼接，所以字符起始下标为1)

    //6、字符串与字符数组的互换，C-风格的字符数组可以与字符串互相转换 
    //字符串转字符数组
    //内置函数 copy 
    //int lens = s.copy(a,s.size());
    //a[lens] = '\0';
    //strcpy 函数 
   	//strcpy(a,s.c_str());//头文件使用 cstring 
    //字符数组转字符串
    //string s(a);

    //7、字符串的比较 ，数组用strcmp(),相等为0，不等为1 (或者循环遍历)
    string s1 = "abc", s2 = "abc", s3 = "bca";
    if(s1 == s2) cout << "相等" << endl;
    else cout << "不相等" << endl;
    if(s1 == s3) cout << "相等" << endl;
    else cout << "不相等" << endl;

    //8、字符串的子串(截取字符串) substr(start, length)
	cout << s.substr(1,3) << endl;
	
    //9、查找字符串的子串 find("子串")
    // 返回第一个匹配的第一个字符的位置
    cout << s.find("tr") << endl;// 1
    // 没有找到, 该函数返回string:npos
    cout << s.find("sss") << endl;
    if(s.find("sss") == string::npos) //string::npos表示没有找到
        cout << "没有找到" << endl;

    //10、替换字符串 replace(起始位置，长度，"替换内容")
    s.replace(4, 1, "<censored>");
    cout << s << endl; // Str<censored>ng
    //指定替换
    //int n=s.find("t");
    //s.replace(n,3,"HUA");// 输出 sHUAIng
    
    //11、删除子串
    s.erase(2, 2); //起始位置,删除的长度 
    cout << s << endl; // 输出 S<censored>ng

    //12、添加子串
    s.insert(2, "aaa");// 在第二个字符前插入str："aaa"
    cout << s << endl; // 输出 Saaa<censored>ng 
    //13、reverse 反转函数 
	reverse(s.begin()+1,s.end());
    cout << s << endl; // 输出 gn>derosnec<aaaS 
	
	//14、sort 排序
	sort(s.begin()+1,s.end());
    cout << s << endl; // 输出 <>Saaacdeegnnors
	return 0;
}
