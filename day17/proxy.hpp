#ifndef PROXY_HPP
#define PROXY_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>

#include <unistd.h>
#include <limits.h>
#include <string.h>

std::vector<std::string> g_ItemFileList;

class ReadInfo
{
    public:
        virtual void read() = 0;
        virtual ~ReadInfo() {};
};


class ReadInfoFromFile : public ReadInfo
{
    public:
        virtual void read()
        {
            char path[PATH_MAX];
            getcwd(path,sizeof(path));
            strcat(path,"/../day17/text.txt");
            std::cout << "path: " << path << std::endl;
            
            std::ifstream fin(path);

            if(!fin.is_open())
            {
                std::cout << "无法打开文件！" << std::endl;
                return;
            }

            std::string line_str;
            while(getline(fin,line_str))
            {
                g_ItemFileList.push_back(line_str);
            }
            fin.close();
        }
};

class ReadInfoProxy : public ReadInfo
{
    public:
        virtual void read()
        {   
            if(!m_loaded)
            {
                std::cout << "从文件中读取数据......" << std::endl;
                m_loaded = true;

                std::shared_ptr<ReadInfo> p_readInfo = std::make_shared<ReadInfoFromFile> ();
                p_readInfo->read();
            }
            else
            {
                std::cout << "从缓存中读取数据......" << std::endl;
            }

            for(auto iter : g_ItemFileList)
            {
                std::cout << iter << std::endl;
            }
        }
    private:
        bool m_loaded = false;
};


#endif