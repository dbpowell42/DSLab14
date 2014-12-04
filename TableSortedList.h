#if !defined (TABLESORTEDLIST_H)
#define TABLESORTEDLIST_H

#include "SortedListDoublyLinked.h"

template < class T >
class TableSortedList
{

   private:
      SortedListDoublyLinked<T>* sldl;

      int (*compare_items) (T* item_1, T* item_2);
      int (*compare_keys) (String* key, T* item);

   public:
      TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
      ~TableSortedList();

      bool tableIsEmpty();
      int tableSize();
      T* tableRetrieve(String* sk);
      void tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
      bool tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)

      ListDoublyLinkedIterator<T>* iterator();

};

//DO THIS
//complete the implementation for TableSortedList

template < class T >
TableSortedList<T>::TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item))
{
   sldl = new SortedListDoublyLinked<T>((*comp_item), (*comp_key));

   compare_items = comp_item;
   compare_keys = comp_key;
}

template < class T >
TableSortedList<T>::~TableSortedList()
{
   sldl -> removeAll();
}

template < class T >
bool TableSortedList<T>::tableIsEmpty()
{
   bool tableIsEmpty = sldl -> isEmpty();
   return tableIsEmpty;
}

template < class T >
int TableSortedList<T>::tableSize()
{
   int tableSize = sldl -> size();
   return tableSize;
}

template < class T >
T* TableSortedList<T>::tableRetrieve(String* sk)
{
   T* item = sldl -> get(sk);
   return item; 
}

template < class T >
void TableSortedList<T>::tableInsert(T* item)
{
   T* retrieveItem = tableRetrieve(item -> getKey());
   if (retrieveItem == NULL) sldl -> add(item);
}

template < class T >
bool TableSortedList<T>::tableRemove(String* search_key)
{
   T* item = tableRetrieve(search_key);
   if (item == NULL)
   {
      bool removeItem = sldl -> remove(search_key);
      return removeItem;
   }
   return item;
}

template < class T >
ListDoublyLinkedIterator<T>* TableSortedList<T>::iterator()
{
   ListDoublyLinkedIterator<T>* iterator = sldl -> iterator;
   return iterator;
}

#endif
