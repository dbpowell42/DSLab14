#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{

//test insertion of duplicates
//test removal of something not there
//test retrievals of items both present and not present

   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << "Original ListArray size: " << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   ListArrayIterator<CD>* iter = cds -> iterator();

   while(iter -> hasNext())
   {
      CD* cd = iter -> next();
      slt -> tableInsert(cd);
   }

   int slt_size = slt -> tableSize();
   cout << "Original TableSortedList size: " << slt_size << endl;

   String* string1 = new String("Waiting for the End to Come"); 
   bool removeTest = slt -> tableRemove(string1);
   cout << "Removing Waiting for the End to Come (1 if true): " << removeTest << endl;
   delete string1;
   slt_size = slt -> tableSize();
   cout << "Size after this remove: " << slt_size << endl;
   cout << endl;

   String* string2 = new String("Portals To Uphobia");
   removeTest = slt -> tableRemove(string2);
   cout << "Removing Portals To Uphobia (1 if true): " << removeTest << endl;
   delete string2;
   slt_size = slt -> tableSize();
   cout << "Size after this remove: " << slt_size << endl;
   cout << endl;

   String* string3 = new String("Dead Calm Chaos");
   removeTest = slt -> tableRemove(string3);
   cout << "Removing Dead Calm Chaos (1 if true): " << removeTest << endl;
   delete string3;
   slt_size = slt -> tableSize();
   cout << "Size after this remove: " << slt_size << endl;
   cout << endl;

   String* string4 = new String("Years In Waste");
   removeTest = slt -> tableRemove(string4);
   cout << "Removing Years In Waste (1 if true): " << removeTest << endl;
   delete string4;
   slt_size = slt -> tableSize();
   cout << "Size after this remove: " << slt_size << endl;
   cout << endl;

   String* string5 = new String("I Love Dr.Boshart");
   removeTest = slt -> tableRemove(string5);
   cout << "Removing I Love Dr.Boshart (1 if true): " << removeTest << endl;
   delete string5;
   slt_size = slt -> tableSize();
   cout << "Size after this remove: " << slt_size << endl;

   String* string6 = new String("Cosmogenesis");
   CD* foundCD = slt -> tableRetrieve(string6);
   cout << "Retrieving the CD:" << endl;
   foundCD -> displayCD();
   cout << endl;
   delete string6;

   String* string7 = new String("I Love Dr.Boshart");
   CD* foundCD2 = slt -> tableRetrieve(string7);
   cout << "Retrieving the CD:" << endl;
   if (foundCD2 != NULL)
   {
      foundCD2 -> displayCD();
   }
   else cout << "The CD was not found" << endl;
   cout << endl;
   delete string7;

   deleteCDs(cds);
   delete cds;
   delete slt;

   cout << "Testing duplicates:" << endl;

   ListArray<CD>* cds2 = CD::readCDs("cds2.txt");
   num_items = cds2->size();

   TableSortedList<CD>* slt2 = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);

   ListArrayIterator<CD>* iter2 = cds2 -> iterator();

   while(iter2 -> hasNext())
   {
      CD* cd = iter2 -> next();
      slt2 -> tableInsert(cd);
   }

   slt_size = slt2 -> tableSize();
   cout << "Inserted 5 duplicates, table size should be 1, table size: " << slt_size << endl; 



   deleteCDs(cds2);
   delete cds2;
   delete slt2;
   return 0;
}
