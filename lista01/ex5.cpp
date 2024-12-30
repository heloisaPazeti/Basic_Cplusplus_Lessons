#include <iostream>

#define maxSize 1000000
int main()
{
  int i,j, result;
  int k = 0;
  int list[maxSize];


  while(std::cin >> list[k]) { k++; }

  for(i = 0; i < k; i++)
  {
      if(list[i] == -1)
            continue;

      for(j = i + 1; j < k; j++)
      {
        if((list[i] == list[j]))
        {
            list[i] = list [j] = -1;
            result = -1;
            break;
        }

        result = list[i];

      }

      if(result > -1)
      {
        std::cout << result;
        return 0;
      }
  }


  std::cout << 0;
  return 0;
}