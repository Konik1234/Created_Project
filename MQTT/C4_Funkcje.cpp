#include "C4_Funkcje.h"


// Funkcja obs�uguj�ca po��czenie z brokerem MQTT
void onConnect(struct mosquitto* mosq, void* userdata, int result) {
    if (result == MOSQ_ERR_SUCCESS) {
        std::cout << "Polaczono z brokerem MQTT." << std::endl;
        // Subskrypcja wiadomo�ci na temacie
        mosquitto_subscribe(mosq, NULL, "C2", 0);
        mosquitto_subscribe(mosq, NULL, "C3", 0);
    }
    else {
        std::cerr << "Nie uda�o si� pol�czy� z brokerem MQTT. Kod b�edu: " << result << std::endl;
    }
}


// Funkcja do wysy�ania danych z kolejki do tabeli w bazie danych MySQL
void sendToMySQL(MYSQL* connection, std::queue<std::string>& messageQueue, const std::string& tableName, const std::vector<std::string>& columns) {
    if (!messageQueue.empty()) {
        // Pobranie pierwszego elementu z kolejki
        std::string message = messageQueue.front();
        messageQueue.pop(); // Usuni�cie elementu z kolejki

        // Parsowanie otrzymanej wiadomo�ci
        std::istringstream iss(message);
        std::vector<std::string> values;
        std::string value;
        while (std::getline(iss, value)) {
            values.push_back(value);
        }

        // Sprawdzenie, czy liczba przekazanych warto�ci jest zgodna z oczekiwan� liczb� kolumn w tabeli
        if (values.size() != columns.size()) {
            std::cerr << "Bl�d: Nieprawidlowa liczba przekazanych warto�ci." << std::endl;
            return;
        }

        // Budowanie zapytania SQL
        std::string query = "INSERT INTO " + tableName + " (";
        for (size_t i = 0; i < columns.size(); ++i) {
            query += columns[i];
            if (i != columns.size() - 1) {
                query += ", ";
            }
        }
        query += ") VALUES (";
        for (size_t i = 0; i < values.size(); ++i) {
            query += "'" + values[i] + "'";
            if (i != values.size() - 1) {
                query += ", ";
            }
        }
        query += ")";

        // Wykonanie zapytania SQL
        if (mysql_query(connection, query.c_str())) {
            std::cerr << "Bl�d przy wysylaniu danych do MySQL: " << mysql_error(connection) << std::endl;
        }
        else {
            std::cout << "Dane zostaly pomyslnie wyslane do MySQL." << std::endl;
        }
    }
}