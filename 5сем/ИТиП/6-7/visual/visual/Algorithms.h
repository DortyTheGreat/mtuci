#pragma once
#include <vector>
#include <queue>
#include <limits>

// Алгоритм Дейкстры
std::vector<int> dijkstra(const std::vector<std::vector<int>>& graph, int src);

// Алгоритм Дейкстры, O(E * log2(V)) с восстановлением пути
std::vector<int> dijkstra2(const std::vector<std::vector<std::pair<int, int>>>& g, int s);

// Алгоритм Флойда-Уоршелла
std::vector<std::vector<int>> floydWarshall(std::vector<std::vector<int>> graph);

// Алгоритм Форма-Фалкерсона (макс. выход)
std::pair<int, std::vector<std::vector<int>> > fordFulkerson(std::vector<std::vector<std::pair<int, int>>> graph_adj, int source, int sink);


std::pair<int, std::vector<std::vector<int>> > findMinimalCut(std::vector<std::vector<std::pair<int, int>>> graph_adj, int source, int sink);

std::vector<int> hungarianMethod(const std::vector<std::vector<int>>& costMatrix);


// Алгоритм перевода из списка смежности в матрицу смежности
std::vector<std::vector<int>> to_adjacency_matrix(const std::vector<std::vector<std::pair<int, int >>>& g);



#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;

bool LoadXML(const std::string& fileName, XMLDocument& doc);

bool SaveXML(const std::string& fileName, XMLDocument& doc);

void checkFile(const std::string& fileName, XMLDocument& doc);

int get_static_id(XMLDocument& doc);

int update_static_id(tinyxml2::XMLDocument& doc);

std::string get_table_name(int val);

class DBObject {
public:
    int id;

    virtual void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) = 0;

    void SetDefaultAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) {
        id = update_static_id(doc);
        elem->SetAttribute("id", id);
    }

    virtual std::vector<std::string> get_description() = 0;
    //virtual std::vector<std::string> get_data() = 0;
};

void AddObject(XMLDocument& doc, DBObject* obj, const std::string& table);

class Pet : public DBObject {
public:
    int breedCode;
    std::string name;
    std::string birthDate;
    int ownerCode;


    void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) override {
        elem->SetAttribute("breedCode", breedCode);
        elem->SetAttribute("name", name.c_str());
        elem->SetAttribute("birthDate", birthDate.c_str());
        elem->SetAttribute("ownerCode", ownerCode);
    }
    Pet() = default;
    Pet(const std::string& s1, const std::string& s2, const std::string& s3, const std::string& s4) {
        breedCode = atoi(s1.c_str());
        name = s2;
        birthDate = s3;
        ownerCode = atoi(s4.c_str());
    }

    std::vector<std::string> get_description() override {
        return { "breedCode", "name", "birthDate", "ownerCode" };
    }
};

class Ownerw : public DBObject {
public:
    std::string fullName;
    std::string address;

    void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) override {
        elem->SetAttribute("fullName", fullName.c_str());
        elem->SetAttribute("address", address.c_str());

    }
    Ownerw() = default;
    Ownerw(const std::string& s1, const std::string& s2) {
        fullName = s1;
        address = s2;
    }

    std::vector<std::string> get_description() override {
        return { "fullName", "address" };
    }
};

class Breed : public DBObject {
public:
    std::string breedName;

    void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) override {
        elem->SetAttribute("breedName", breedName.c_str());

    }
    Breed() = default;
    Breed(const std::string& s1) {
        breedName = s1;
    }

    std::vector<std::string> get_description() override {
        return { "breedName" };
    }
};

class Vaccine : public DBObject {
public:
    std::string vaccineName;
    std::string comment;

    void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) override {
        elem->SetAttribute("vaccineName", vaccineName.c_str());
        elem->SetAttribute("comment", comment.c_str());

    }

    Vaccine() = default;
    Vaccine(const std::string& s1, const std::string& s2) {
        vaccineName = s1;
        comment = s2;
    }

    std::vector<std::string> get_description() override {
        return { "vaccineName", "comment"};
    }
};

class PetVaccine : public DBObject {
public:
    int petCode;
    int vaccineCode;
    std::string date;

    void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) override {
        elem->SetAttribute("petCode", petCode);
        elem->SetAttribute("vaccineCode", vaccineCode);
        elem->SetAttribute("date", date.c_str());
    }

    PetVaccine() = default;
    PetVaccine(const std::string& s1, const std::string& s2, const std::string& s3) {
        petCode = atoi(s1.c_str());
        vaccineCode = atoi(s2.c_str());
        date = s3;
    }

    std::vector<std::string> get_description() override {
        return { "petCode", "vaccineCode", "date"};
    }
};

DBObject* get_class(int val);