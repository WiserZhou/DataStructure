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
         {            // ��δ����json���
            key = ""; // ��λ��
         }
         else
         { // ֵ�Ĳ�����{��ͷ��˵������Ӧ��ֵΪһ������
            json[key] = "OBJECT";
         }
         state = 1; // ���������������������һ����Ӧ�ô����
      }
      if (s[i] == '}')
      { // ����Ĳ�νṹ����������ܳ�������
         int j;
         for (j = (int)key.size() - 1; j >= 0 && key[j] != '.'; j--)
            ;
         if (j >= 0)
         { // ��keyֵ���£�ȥ�����һ���㼰֮������ݣ�
            key = key.substr(0, j);
         }
         else
         {
            key = "";
         }
      }
      if (s[i] == ':')
      { // ��һ������ֵ
         state = 2;
      }
      if (s[i] == ',')
      { // ��һ�������
         state = 1;
      }
      if (s[i] == '"')
      {
         string temp;
         for (i++; i < s.size(); i++)
         { // ��ȡ˫�����ڵ�����
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
         { // ��ʱ���ڼ���λ��
            if (key.empty())
            {
               key = temp;
            }
            else
            { // ���εļ���λ��
               key += "." + temp;
            }
            state = 2; // enter value part
         }
         else if (state == 2)
         { // ��ȡ���ַ�����ֵ
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
   { // ����n�е�json����
      string line;
      getline(cin, line);
      Deal(line); // ����֮��ֱ�ӽ��д���
   }
   while (m--)
   { // ����m�ֲ�ѯ
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
