#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string, string> json;
int state;
string key;

void Deal(string &s)
{

   for (int i = 0; i < s.size(); i++)
   {
      if (s[i] == '{')
      {
         if (state == 0)
         {            // 还未进入json语句
            key = ""; // 键位空
         }
         else
         { // 值的部分以{开头，说明键对应的值为一个对象
            json[key] = "OBJECT";
         }
         state = 1; // 不管是上述那种情况，下一步都应该处理键
      }
      if (s[i] == '}')
      { // 对象的层次结构超过两层可能超过两层
         int j;
         for (j = (int)key.size() - 1; j >= 0 && key[j] != '.'; j--)
            ;
         if (j >= 0)
         { // 将key值更新（去掉最后一个点及之后的内容）
            key = key.substr(0, j);
         }
         else
         {
            key = "";
         }
      }
      if (s[i] == ':')
      { // 下一步处理值
         state = 2;
      }
      if (s[i] == ',')
      { // 下一步处理键
         state = 1;
      }
      if (s[i] == '"')
      {
         string temp;
         for (i++; i < s.size(); i++)
         { // 获取双引号内的内容
            if (s[i] == '\\')
            {
               temp += s[++i];
            }
            else if (s[i] == '"')
            {
               break;
            }
            else
            {
               temp += s[i];
            }
         }
         if (state == 1)
         { // 此时处于键的位置
            if (key.empty())
            {
               key = temp;
            }
            else
            { // 多层次的键的位置
               key += "." + temp;
            }
            state = 2; // enter value part
         }
         else if (state == 2)
         { // 获取的字符串是值
            json[key] = "STRING " + temp;
            int j;
            for (j = (int)key.size() - 1; j >= 0 && key[j] != '.'; j--)
               ;
            if (j >= 0)
            {
               key = key.substr(0, j);
            }
            else
            {
               key = "";
            }
            state = 1;
         }
      }
   }
}

int main()
{
   int n, m;
   cin >> n >> m;
   getchar();
   state = 0;
   while (n--)
   { // 输入n行的json数据
      string line;
      getline(cin, line);
      Deal(line); // 输入之后直接进行处理
   }
   while (m--)
   { // 输入m种查询
      string search;
      getline(cin, search);
      if (!json[search].empty())
      {
         cout << json[search] << endl;
      }
      else
      {
         cout << "NOTEXIST" << endl;
      }
   }
   return 0;
}
