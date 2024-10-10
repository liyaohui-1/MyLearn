#ifndef NODE_CONF_H_
#define NODE_CONF_H_

#include <vector>
#include <string>
#include <iostream>

struct NodeDescribe
{
    std::string iros_version;
    std::string node_name;
    std::string node_id; 

    void list_node ()
    {
        std::cout << "*****************************"  << std::endl;
        std::cout << "iros_version: " << iros_version << std::endl;
        std::cout << "iros_name: "    << node_name    << std::endl; 
        std::cout << "node_id: "      << node_id      << std::endl; 
    }
};

struct Channel
{
    std::string connect_type;
    std::string connect_name;
    std::string connect_id;
    std::string connect_attr;
    std::string channel_name;
    std::string channel_id;
    std::string channel_data_type;
    std::string channel_rx_cbk;
    std::string task_name;
    uint32_t task_priority;

    void list_channel()
    {
        std::cout << "*****************************"  << std::endl;
        std::cout << "connect_type: " << connect_type << std::endl;
        std::cout << "connect_name: " << connect_name << std::endl;
        std::cout << "connect_id: " << connect_id << std::endl;
        std::cout << "connect_attr: " << connect_attr << std::endl;
        std::cout << "channel_name: " << channel_name << std::endl;
        std::cout << "channel_id: " << channel_id << std::endl;
        std::cout << "channel_data_type: " << channel_data_type << std::endl;
        std::cout << "channel_rx_cbk: " << channel_rx_cbk << std::endl;
        std::cout << "task_name: " << task_name << std::endl;
        std::cout << "task_priority: " << task_priority << std::endl;
    }
};

struct Service
{
    std::string connect_type;
    std::string connect_name;
    std::string connect_id;
    std::string connect_attr;
    std::string service_name;
    std::string service_id;
    std::string request_data_type;
    std::string response_data_type;
    std::string task_name;
    uint32_t task_priority;

    void list_service()
    {
        std::cout << "*****************************"  << std::endl;
        std::cout << "connect_type: " << connect_type << std::endl;
        std::cout << "connect_name: " << connect_name << std::endl;
        std::cout << "connect_id: " << connect_id << std::endl;
        std::cout << "connect_attr: " << connect_attr << std::endl;
        std::cout << "service_name: " << service_name << std::endl;
        std::cout << "service_id: " << service_id << std::endl;
        std::cout << "request_data_type: " << request_data_type << std::endl;
        std::cout << "response_data_type: " << response_data_type << std::endl;
        std::cout << "task_name: " << task_name << std::endl;
        std::cout << "task_priority: " << task_priority << std::endl;
    }
};

struct Task
{
    std::string task_name;
    std::string task_id;
    uint32_t task_period;
    std::string task_func;
    uint32_t task_priority;

    void list_task()
    {
        std::cout << "*****************************"  << std::endl;
        std::cout << "task_name: " << task_name << std::endl;
        std::cout << "task_id: " << task_id << std::endl;
        std::cout << "task_period: " << task_period << std::endl;
        std::cout << "task_func: " << task_func << std::endl;
        std::cout << "task_priority: " << task_priority << std::endl;
    }
};

struct NodeConf
{
    NodeDescribe node_des;
    std::vector<Channel> readers_conf;
    std::vector<Channel> writers_conf;
    std::vector<Service> services_conf;
    std::vector<Service> clients_conf;
    std::vector<Task> cycle_tasks_conf;
    std::vector<Task> tasks_conf;
};

#endif