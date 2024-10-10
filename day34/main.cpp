#include <iostream>
#include <fstream>
#include "node_conf.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main()
{
    std::cout << "hello world!" << std::endl;
    std::string conf_path = "./conf.json";

    std::fstream input (conf_path); 

    if(!input.is_open())
    {
        std::cout <<"file is not exist!" << std::endl;
        return 0;
    }
    
    json json_value;
    input >> json_value;


    NodeConf node_conf;

    NodeDescribe node_des_;
    // std::cout << "iros_version: " << json_value.at("node_describe").get<json>().at("iros_version").get<std::string> () << std::endl;
    node_des_.iros_version = json_value.at("node_describe").get<json>().at("iros_version").get<std::string> ();
    node_des_.node_name = json_value.at("node_describe").get<json>().at("node_name").get<std::string> ();
    node_des_.node_id = json_value.at("node_describe").get<json>().at("node_id").get<std::string> ();
    node_des_.list_node();
    node_conf.node_des = node_des_;

    Channel channel_des_reader;
    json j_array = json::array();
    j_array = json_value.at("reader_group");
    for(uint32_t index = 0; index < j_array.size(); index++)
    {
        channel_des_reader.connect_type = j_array.at(index).get<json>().at("connect_type").get<std::string> ();
        channel_des_reader.connect_name = j_array.at(index).get<json>().at("connect_name").get<std::string> ();
        channel_des_reader.connect_id = j_array.at(index).get<json>().at("connect_id").get<std::string> ();
        channel_des_reader.connect_attr = j_array.at(index).get<json>().at("connect_attr").get<std::string> ();
        channel_des_reader.channel_name = j_array.at(index).get<json>().at("channel_name").get<std::string> ();
        channel_des_reader.channel_id = j_array.at(index).get<json>().at("channel_id").get<std::string> ();
        channel_des_reader.channel_data_type = j_array.at(index).get<json>().at("channel_data_type").get<std::string> ();
        channel_des_reader.channel_rx_cbk = j_array.at(index).get<json>().at("channel_rx_cbk").get<std::string> ();
        channel_des_reader.task_name = j_array.at(index).get<json>().at("task_name").get<std::string> ();
        channel_des_reader.task_priority = j_array.at(index).get<json>().at("task_priority").get<uint32_t> ();
        node_conf.readers_conf.emplace_back(channel_des_reader);
    }
    
    for(auto item : node_conf.readers_conf)
    {
        item.list_channel();
    }

    Channel channel_des_writer;
    j_array = json_value.at("writer_group");
    for(uint32_t index = 0; index < j_array.size(); index++)
    {
        channel_des_writer.connect_type = j_array.at(index).get<json>().at("connect_type").get<std::string> ();
        channel_des_writer.connect_name = j_array.at(index).get<json>().at("connect_name").get<std::string> ();
        channel_des_writer.connect_id = j_array.at(index).get<json>().at("connect_id").get<std::string> ();
        channel_des_writer.connect_attr = j_array.at(index).get<json>().at("connect_attr").get<std::string> ();
        channel_des_writer.channel_name = j_array.at(index).get<json>().at("channel_name").get<std::string> ();
        channel_des_writer.channel_id = j_array.at(index).get<json>().at("channel_id").get<std::string> ();
        channel_des_writer.channel_data_type = j_array.at(index).get<json>().at("channel_data_type").get<std::string> ();
        node_conf.writers_conf.emplace_back(channel_des_writer);
    }

    for(auto item : node_conf.writers_conf)
    {
        item.list_channel();
    }

    Service service_des_service;
    j_array = json_value.at("service_group");
    for(uint32_t index = 0; index < j_array.size(); index++)
    {
        service_des_service.connect_type = j_array.at(index).get<json>().at("connect_type").get<std::string> ();
        service_des_service.connect_name = j_array.at(index).get<json>().at("connect_name").get<std::string> ();
        service_des_service.connect_id = j_array.at(index).get<json>().at("connect_id").get<std::string> ();
        service_des_service.connect_attr = j_array.at(index).get<json>().at("connect_attr").get<std::string> ();
        service_des_service.service_name = j_array.at(index).get<json>().at("service_name").get<std::string> ();
        service_des_service.service_id = j_array.at(index).get<json>().at("service_id").get<std::string> ();
        service_des_service.request_data_type = j_array.at(index).get<json>().at("request_data_type").get<std::string> ();
        service_des_service.response_data_type = j_array.at(index).get<json>().at("response_data_type").get<std::string> ();
        service_des_service.task_name = j_array.at(index).get<json>().at("task_name").get<std::string> ();
        service_des_service.task_priority = j_array.at(index).get<json>().at("task_priority").get<uint32_t> ();
        node_conf.services_conf.emplace_back(service_des_service);
    }

    for(auto item : node_conf.services_conf)
    {
        item.list_service();
    }

    Service service_des_client;
    j_array = json_value.at("client_group");
    for(uint32_t index = 0; index < j_array.size(); index++)
    {
        service_des_client.connect_type = j_array.at(index).get<json>().at("connect_type").get<std::string> ();
        service_des_client.connect_name = j_array.at(index).get<json>().at("connect_name").get<std::string> ();
        service_des_client.connect_id = j_array.at(index).get<json>().at("connect_id").get<std::string> ();
        service_des_client.connect_attr = j_array.at(index).get<json>().at("connect_attr").get<std::string> ();
        service_des_client.service_name = j_array.at(index).get<json>().at("service_name").get<std::string> ();
        service_des_client.service_id = j_array.at(index).get<json>().at("service_id").get<std::string> ();
        service_des_client.request_data_type = j_array.at(index).get<json>().at("request_data_type").get<std::string> ();
        service_des_client.response_data_type = j_array.at(index).get<json>().at("response_data_type").get<std::string> ();
        service_des_client.task_name = j_array.at(index).get<json>().at("task_name").get<std::string> ();
        service_des_client.task_priority = j_array.at(index).get<json>().at("task_priority").get<uint32_t> ();
        node_conf.clients_conf.emplace_back(service_des_client);
    }

    for(auto item : node_conf.clients_conf)
    {
        item.list_service();
    }

    Task task_des_cycle;
    j_array = json_value.at("cycle_task_group");
    for(uint32_t index = 0; index < j_array.size(); index++)
    {
        task_des_cycle.task_name = j_array.at(index).get<json>().at("task_name").get<std::string> ();
        task_des_cycle.task_id = j_array.at(index).get<json>().at("task_id").get<std::string> ();
        task_des_cycle.task_period = j_array.at(index).get<json>().at("task_period").get<uint64_t> ();
        task_des_cycle.task_func = j_array.at(index).get<json>().at("task_func").get<std::string> ();
        task_des_cycle.task_priority = j_array.at(index).get<json>().at("task_priority").get<uint64_t> ();
        node_conf.cycle_tasks_conf.emplace_back(task_des_cycle);
    }
    
    for(auto item : node_conf.cycle_tasks_conf)
    {
        item.list_task();
    }

    Task task_des;
    j_array = json_value.at("task_group");
    for(uint32_t index = 0; index < j_array.size(); index++)
    {
        task_des.task_name = j_array.at(index).get<json>().at("task_name").get<std::string> ();
        task_des.task_id = j_array.at(index).get<json>().at("task_id").get<std::string> ();
        task_des.task_func = j_array.at(index).get<json>().at("task_func").get<std::string> ();
        task_des.task_priority = j_array.at(index).get<json>().at("task_priority").get<uint64_t> ();
        node_conf.tasks_conf.emplace_back(task_des);
    }
    
    for(auto item : node_conf.tasks_conf)
    {
        item.list_task();
    }


    return 0;
}