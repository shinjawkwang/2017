#include <iostream>

using namespace std;

int is_anagram(char *a, char *b)
{
  int len_a = 0, len_b = 0;
  int alphabet_count['z' - 'a' + 1] = {0, };
  while (a[len_a] != '\0')
    len_a++;
  while (b[len_b] != '\0')
    len_b++;

  if (len_a != len_b)
     return 0;

  for(int i=0;i<len_a;i++){
		alphabet_count[a[i] - 'a']++;
	}
	for(int i=0;i<len_b;i++){
		alphabet_count[b[i] - 'a']--;
	}
	//for(int i = 0; i < 'z' - 'a' + 1; i++)	cout << alphabet_count[i] << " ";

  for (int i = 0; i < 'z' - 'a' + 1; i++)
    if (alphabet_count[i] != 0)
      return 0;
  return 1;
}

int main() {
	char a[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char b[6] = {'b', 'a', 'c', 'd', 'e', 'f'};
	cout << is_anagram(a, b);
	//is_anagram(a, b);
  return 0;
}
