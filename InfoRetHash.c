/*This program defines a Document structure that represents a document with 
an ID, title, and text. It also defines a HashTable structure that 
uses an array of Document pointers to store the documents.

Information Retrival Demo by 
- Het Joshi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

// Struct Document has a TITLE and the respective DESCRIPTION as its elements
struct Document {
  int id;
  char *title;
  char *text;
};

//Defining a Hash Table containing the Document
struct HashTable {
  struct Document *items[TABLE_SIZE];
};

//Intialises the HashTable
struct HashTable *createHashTable() {
  struct HashTable *table = (struct HashTable*)malloc(sizeof(struct HashTable));
  int i;
  for (i = 0; i < TABLE_SIZE; i++) {
    table->items[i] = NULL;
  }
  return table;
}

int hash(int id) {
  return id % TABLE_SIZE;
}

//Function to add to the Table
void insertDocument(struct HashTable *table, struct Document *doc) {
  int index = hash(doc->id);
  table->items[index] = doc;
}

//Function to retrieve a Document using its INDEX
struct Document* retrieveDocument(struct HashTable *table, int id) {
  int index = hash(id);
  return table->items[index];
}


//Driver Program
 
int main() {
  struct HashTable *table = createHashTable();

  struct Document doc1 = {1, "Doc 1", "This is the text of doc 1"};
  struct Document doc2 = {2, "Doc 2", "This is the text of doc 2"};
  struct Document doc3 = {3, "Doc 3", "This is the text of doc 3"};

  insertDocument(table, &doc1);
  insertDocument(table, &doc2);
  insertDocument(table, &doc3);

  int id = 2;
  struct Document *doc = retrieveDocument(table, id);
  if (doc != NULL) {
    printf("Document with ID %d:\n", id);
    printf("Title: %s\n", doc->title);
    printf("Text: %s\n", doc->text);
  } else {
    printf("Document with ID %d was not found\n", id);
  }

  return 0;
}
