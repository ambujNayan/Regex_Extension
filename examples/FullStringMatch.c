/*This file shows the regular expression matching in case of full string matching against a regex*/

#include<stdio.h>
#include "dfa.h"
#include "regex.h"

extern void init_DFA (struct DFA *, state, int);
extern void add_trans (struct DFA *, state, state, input);
extern void set_final_state (struct DFA *, state);
extern eBool match (struct DFA *, char *);
extern void release_DFA (struct DFA *);

int main (int argc, char ** argv) {

  struct DFA dfa1;

  /*generating dfa for regex "(a|b)*abb"  */
  init_DFA (&dfa1, 0, 4);
  set_final_state (&dfa1, 3);
  add_trans (&dfa1, 0, 1, 'a');
  add_trans (&dfa1, 0, 0, 'b');
  add_trans (&dfa1, 1, 1, 'a');
  add_trans (&dfa1, 1, 2, 'b');
  add_trans (&dfa1, 2, 1, 'a');
  add_trans (&dfa1, 2, 3, 'b');
  add_trans (&dfa1, 3, 1, 'a');
  add_trans (&dfa1, 3, 0, 'b');
  
  struct DFA dfa2;

  /*generating dfa for regex "(a)*bab"  */
  init_DFA (&dfa2, 0, 4);
  set_final_state (&dfa2, 3);
  add_trans (&dfa2, 0, 0, 'a');
  add_trans (&dfa2, 0, 1, 'b');
  add_trans (&dfa2, 1, 2, 'a');
  add_trans (&dfa2, 2, 3, 'b');

  const char *text = "abaabb";  /*text to match*/

  //Matching the text against the regex1
  if (match (&dfa1, text) == TRUE) {
    printf("text matches first regex(correct)\n");
  } else {
    printf("text does not match first regex(incorrect)\n");
  }
  
  //Matching the text against the regex2
  if (match (&dfa2, text) == TRUE) {
    printf("text matches second regex(incorrect)\n");
  } else {
    printf("Second text does not match second regex(correct)\n");
  }

  release_DFA (&dfa);

  return 0;
}
