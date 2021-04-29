#ifndef ex_h
#define ex_h
#include <cstring>
char*removeNonLatin(char*s)
{
  char *s2=nullptr;
  s2 = new char;
  int k=strlen(s);
  int i,j=0;
  for (i=0; i<k; i++)
    if (s[i]>='a' && s[i]<= 'z') //Αν είναι πεζό το προσθέτει
    {
      s2[j]=s[i];
      j++;
    }
    else
    {
      if (s[i]>='A' && s[i]<= 'Z') //Αν είναι κεφαλαίο, το κάνει πεζό
      {
        s2[j]=s[i]+32;
        j++;
      }
    } //Αν δεν είναι γράμμα, απλά πηγαίνει στον επόμενο χαρακτήρα
  s2[j] = '\0'; //κλείνουμε την λέξη

  return s2;
};

#endif