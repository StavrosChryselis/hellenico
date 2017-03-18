/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <algorithm>
#include <bitset>
#include <limits>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define DEBUG 0

struct Point
{
   int arrow[100], carrow;
};

void IdentifySet (int *set, int *cset, Point *point, int start, int avoidance, int set_start)
{
   bool flag;

   *cset = set_start;
   set[(*cset)++] = start;
  
   for (int a = 0;a < point[start].carrow;a++)
   {
       if (point[start].arrow[a] != avoidance)
       {
           flag = false;

           for (int b = 0; b < set_start;b++)
           {
               if (point[start].arrow[a] == set[b])
               {
                   flag = true;
                   break;
               }
           }

           if (flag == false)
               IdentifySet (set, cset, point, point[start].arrow[a], avoidance, *cset); //We can pass cset (2nd variable) onto this function without data loss, as we know cset is an output variable.
       }
   }

   return;
}

int CompareInt (const void *var1, const void *var2)
{
   const int a = *reinterpret_cast<int *>(const_cast<void *>((var1))), b = *reinterpret_cast<int *>(const_cast<void *>((var2)));

   if (a > b)
       return 1;
   else if (a < b)
       return -1;

   return 0;
}

int main ()
{
   std::ifstream in ("race.in");
   std::ofstream out ("race.out");
   Point point[50];
   bool flag;
   int set[2][50], cset[2], unavoidable[50], splitting[50], cunavoid = 0, csplit = 0, cpoint = 0;

   for (int a = 0;a < 50;a++)
       point[a].carrow = 0;

   for (int a;;)
   {
       in >> a;

       if (a == -2)
           cpoint++;
       else if (a == -1)
           break;
       else
           point[cpoint].arrow[point[cpoint].carrow++] = a;
   }

   in.close ();

   for (int a = 1, b;a < cpoint - 1;a++)
   {
       IdentifySet (set[0], &cset[0], point, 0, a, 0);

       for (b = 0;b < cset[0];b++)
       {
           if (set[0][b] == cpoint - 1)
               break;
       }

       if (b < cset[0])
           continue;
      
       unavoidable[cunavoid++] = a;
       
       IdentifySet (set[1], &cset[1], point, a, -1, 0);

      
       qsort (set[0], cset[0], sizeof (int), CompareInt);
       qsort (set[1], cset[1], sizeof (int), CompareInt);
      
       flag = false;
       for (int c = 0, d = 0;c < cset[0] && d < cset[1];)
       {
           if (set[0][c] < set[1][d])
           {
               c++; //lol
               continue;
           }
           else if (set[0][c] > set[1][d])
           {
               d++;
               continue;
           }
           else if (set[0][c] == set[1][d])
           {
               flag = true;
               break;
           }
       }

       if (flag == false)
           splitting[csplit++] = a;
   }

   out << cunavoid;

   for (int a = 0;a < cunavoid;a++)
       out << " " << unavoidable[a];

   out << "\n" << csplit;

   for (int a = 0;a < csplit;a++)
       out << " " << splitting[a];

   out << "\n";
   out.close ();

   return 0;
}
