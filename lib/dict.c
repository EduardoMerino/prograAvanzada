#include <stdlib.h>
#include <stdio.h>
#include "dict.h"

Dict *initDictionary(unsigned int size, int *errorCode){
  Dict *newDict;
  newDict = calloc(1, sizeof(Dict));
  if(newDict == NULL){
    *errorCode = 100;
    return NULL;
  }
  newDict->size = size;
  newDict->elements = (DictElement *) calloc(size, sizeof(DictElement));
  if(newDict->elements == NULL){
    *errorCode = 200;
    return NULL;
  }

  return newDict;
}

/* hash: form hash value for string s */
static unsigned hash(char *s, unsigned int size){
  unsigned hashval;
  for(hashval = 0; *s != '\0'; s++){
    hashval = *s + 31 * hashval;
  }
  return hashval % size;
}

void upsertDictionary(Dict *dictionary, char *key, void *value, int *errorCode){
  if(dictionary == NULL){
    *errorCode = 100;
    return;
  }

  if(dictionary->elements == NULL){
    *errorCode = 100;
    return;
  }

  if(key == NULL){
    *errorCode = 100;
    return;
  }

  if(value == NULL){
    *errorCode = 100;
    return;
  }

  int index = hash(key, dictionary->size);
  dictionary->elements[index].key = key;
  dictionary->elements[index].key = value;
  *errorCode = 0;
}
