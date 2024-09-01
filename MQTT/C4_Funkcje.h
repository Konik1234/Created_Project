#pragma once

#include <iostream>
#include <queue>
#include <sstream>
#include <map>
#include "mysql.h"
#include "mosquitto.h"
#include <chrono>
#include <thread>


// Funkcja obs�uguj�ca po��czenie z brokerem MQTT
void onConnect(struct mosquitto* mosq, void* userdata, int result);



// Funkcja do wysy�ania danych z kolejki do tabeli w bazie danych MySQL
void sendToMySQL(MYSQL* connection, std::queue<std::string>& messageQueue, const std::string& tableName, const std::vector<std::string>& columns);