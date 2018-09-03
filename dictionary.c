// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"


// Initialize word count and word variable to temporarily store data
int wordCount = 0;
char tempWord[LENGTH+1];

// Hash Function for words
int hash(const char *word)
{
    int result = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        result += word[i];
    }
    return result % HASHTABLE_SIZE;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{

    // Create lowWord to store lower case version of words
    char lowWord[LENGTH+1];
    int len = strlen(word);

    // Transform all letters in word to lower
    for (int i=0; i<len; i++)
    {
        lowWord[i] = tolower(word[i]);
    }
    lowWord[len]='\0';

    // Get the hash number of the  word
    int hashNum = hash(lowWord);
    //printf("hash number is %i \n",hashNum);

    // Create a cursor to iterate over the bucket
    node* cursor = hashtable[hashNum];

    if(hashtable[hashNum] == NULL)
    {
        return false;
    }

    // Iterate over the bucket with a while loop
    while (cursor != NULL)
    {
        // Compare two words
        if (strcmp(cursor->word,lowWord) == 0)
           {
            //printf("f %s \n",cursor->word);
            return true;
           }
        //printf("a %s \n",cursor->word);
        cursor = cursor->next;
    }
    return false;
}
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // First Read the dictionary file
    FILE* dictPtr = fopen(dictionary, "r");
    if (dictPtr == NULL)
    {
        //fprintf(stderr, "Could not open file. %s \n", dictionary);
        return false;
    }

    // Iterate over the dictionary file until end
    while(!feof(dictPtr))
    {
         // Read one word a time from the dict filem then store it in the newNode created earlier
         fscanf(dictPtr,"%s", tempWord);
         // Create a new node
         node* newNode = malloc(sizeof(node));
         if (newNode == false)
            {
              unload();
              return false;
            }
        strcpy(newNode->word,tempWord);
        //printf("e %s \n",newNode->word);
        // Calculate the hash number of the word
        int hashNum = hash(tempWord);
        // Set a traverse node point to the head of the bucket
        //printf("a %i \n",hashNum);
        //printf("d %s \n",hashtable[hashNum]->word);

        // If no singledlist is assigned, create a new one using the node, else insert the node to the existing list
        if (hashtable[hashNum] == NULL){
           newNode->next = NULL;
           hashtable[hashNum] = newNode;
        }
        else{
             newNode->next = hashtable[hashNum];
             hashtable[hashNum] = newNode;
        }
        // Keep count of the words in dictionary
        wordCount++;
    }
    fclose(dictPtr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i=0; i<HASHTABLE_SIZE; i++){
        node* head = hashtable[i];
        node* cursor = head;
        while(cursor != NULL){
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
