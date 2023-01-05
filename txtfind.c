#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30
#define MAX_LINES 252 //there is no use in MAX_LINES, you can write as many lines as you want

int getLine(char s[]);
int getWord(char w[]);
int substring(char *str1, char *str2);
int similar(char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);

// Reads a line from stdin and saves it in the string s
// Returns the number of characters read
int getLine(char s[]) {
  int c, i;
  for (i = 0; i < LINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

// Reads a word from stdin and saves it in the string w
// Returns the number of characters read
int getWord(char w[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != ' ' && c != '\t' && c != '\n'; i++) {
    if (i < WORD - 1) {
      w[i] = c;
    }
  }
  if (i < WORD) {
    w[i] = '\0';
  } else {
    w[WORD - 1] = '\0';
  }
  return i;
}

// Returns 1 if str2 is a substring of str1, 0 otherwise
int substring(char *str1, char *str2) {
  return strstr(str1, str2) != NULL;
}

// Returns 1 if it is possible to get from string s to string t by omitting n characters
// Otherwise returns 0
int similar(char *s, char *t, int n) {
  if (s[0] == '\0' || t[0] == '\0') {
    return 0;
  }
  int i, j;
  i = j = 0;
  int omitted = 0;
  while (s[i] != '\0' && t[j] != '\0') {
    if (s[i] != t[j]) {
      omitted++;
      if (omitted > n) {
        return 0;
      }
    } else {
      j++;
    }
    i++;
  }
  return omitted <= n;
}

// Prints all the lines in the text where the string str appears
void print_lines(char *str) {
  char line[LINE];
  while (getLine(line) > 0) {
    if (substring(line, str)) {
      printf("%s", line);
    }
  }
}

// Prints all the words in the text that are similar to the string str
// up to the omission of one letter from the word
void print_similar_words(char *str) {
  char word[WORD];
  int c;
  while ((c = getchar()) != EOF) {
    // Read a word from the input
    int i = 0;
    while (c != EOF && c != ' ' && c != '\t' && c != '\n') {
      word[i] = c;
      i++;
      c = getchar();
    }
    word[i] = '\0';
    // Check if the word is similar to the search string
    if (str[0] != '\0' && similar(word, str, 1)) {
      if(strlen(word) == strlen(str)+1 || strlen(word) == strlen(str))
        printf("%s\n", word);
    }
  }
}

// Main function for txtfind.c
int main() {
  char str[WORD], option;
  getWord(str);
  scanf(" %c", &option);

  if (option == 'a') {
    print_lines(str);
  }
  if (option == 'b') {
    print_similar_words(str);
  }

  return 0;
}