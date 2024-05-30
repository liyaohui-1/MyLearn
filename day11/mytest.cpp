#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <getopt.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int test_count = -1;
int test_filter = -1;
uint32_t test_period = 10000;
int test_delay = 0;

static string  g_if_name = "eth0";

static inline void get_string(string buf, string name, string format, string &str)
{
    if (strstr(buf.c_str(), name.c_str()))
    {
        char tmp[100] = {0};
        string fmt = string(name) + format;
        sscanf(buf.c_str(), fmt.c_str(), tmp);
        str = tmp;
    }
}

int atoi_hex(std::string s, int radix) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    char t = s[i];
    if (t >= '0' && t <= '9')
      ans = ans * radix + t - '0';
    else
      ans = ans * radix + t - 'a' + 10;
  }
  return ans;
}
 

int main(int argc, char **argv)
{
  /*
  int opt;

  while (-1 != (opt = getopt(argc, argv, "m:p:f:d:U"))) 
  {
    switch (opt) 
    {
      case 'm':
        test_count = atoi(optarg);
        if (test_count < 1) {
          printf(
              "[ERROR] -m [mode]: test mode\n");
          return 0;
        }
        break;
      case 'p':
        test_period = atoi(optarg);
        if (test_period < 10000) {
          test_period = 10000;
          printf(
              "[WARNNING] -p [period]: test send msg period reset to "
              "10000us\n");
        }
        break;
      case 'f':
        test_filter = atoi(optarg);
        if (test_filter < 1) {
          printf(
              "[ERROR] -f [filter]: test filter\n");
          return 0;
        }
        printf("Send CAN filter msg test ...\n");
        break;
      case 'd':
        test_delay = atoi(optarg);
        if (test_delay < 0) {
          printf("[ERROR] -d [delay]: delay recv data reset to 0\n");
        }
        break;
      default:
        printf("usage: \n");
        printf(" -m [mode] \n");
        printf("mode: \n");
        printf("      1 - CAN Extra API(Send or Recv) test \n");
        printf(" -f [filter] \n");
        printf("fliter: \n");
        printf("      1 - CAN Extra API(Send Filter) test \n");
        printf(" -p [period] \n");
        printf("period: \n");
        printf("      period >= 10000 us \n");
        printf(" -d [delay] \n");
        printf("delay: \n");
        printf("      delay recv data for fifo overflow test \n");
        return false;
        break;
  }
}
printf("-m: %d  -f:%d -p: %d -d: %d\n", test_count, test_filter, test_period, test_delay);
*/

  /*
  get_string("IfName = 100", "IfName",  " = %s", g_if_name);
  std::cout << "IfName: " << g_if_name << std::endl;
  */

 /*
  int hex_test = atoi_hex(string("123"),10);
  std::cout << "hex_test: " << hex_test << std::endl;

  uint32_t xx = 0x163;
  
  std::cout << "result: " << xx - 0x162 << std::endl;
 */

/*  
#if defined(TEST_CODE)
  cout << "TEST_CODE:" << TEST_CODE << endl;
#else
  cout << "TEST_CODE not set!" << endl;
#endif

#if defined(TEST_CODE) && TEST_CODE == 2  
  // 当 TEST_CODE 被设置为 2 时，这段代码会被编译  
  cout << "Feature level 2 is enabled." << endl;  
#elif defined(TEST_CODE) && TEST_CODE == 1  
  // 当 MY_FEATURE_LEVEL 被设置为 1 时，这段代码会被编译  
  cout << "Feature level 1 is enabled." << endl;  
#else  
// 默认情况下，这段代码会被编译  
  cout << "No feature level is enabled." << endl;  
#endif
*/

  /*
  int testGroup [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  long long  *testPoint = (long long*)&testGroup;

  std::cout << "vector.size(): " << sizeof(testGroup)/sizeof(testGroup[0]) << std::endl;
  for(int i = 0; i < sizeof(testGroup)/sizeof(testGroup[0]); i++)
  {
    std::cout << "index[" << i << "]:" << (uint32_t)testPoint[i] << std::endl;
  }
  */

 /*
  std::string str_tmp = {"ca_CD701_j3"};
  std::transform(str_tmp.begin(), str_tmp.end(), str_tmp.begin(),  
                    [](unsigned char c){ return std::tolower(c); });
  std::cout << "str_tmp: " << str_tmp << std::endl;
  std::size_t pos = str_tmp.find("cd701");

  if(pos != std::string::npos)
  {
    std::cout << "cd701_begin_at: " << pos << std::endl;
  }
  else
  {
    std::cout << "cd701_not_find!" << std::endl;

  }
 */

  


  return 0;
}

