#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ransom_note.h"

/* Can canConstruct
 * given an arry of characters Magazine, check if the note can be
 * constructed with the characters of magazine
 * @param:
 *  note: note (can't contain '0')
 *  magazine: magazine characters
 * @return:
 *  integer: 0 if the note can be constructed, 1 if not.
 */
int canConstruct(char note[], char magazine[]){
  int noteLen = strlen(note);
  int magazineLen = strlen(magazine);
  State isFound;

  if(noteLen > magazineLen){
    return 1;
  }

  for(int i = 0; i < noteLen; i++){
    isFound = NOTFOUND;
    for(int j = 0; j < magazineLen; j++){
      if(note[i] == magazine[j]){
        isFound = FOUND;
        magazine[j] = '0';
      }
      if(isFound == FOUND){
        break;
      }
    }
    if(isFound == NOTFOUND){
      //after a cycle through the magazine couldn´t
      //find a character.
      return 1;
    }
  }
  return 0;
}
