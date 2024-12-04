#pragma once

#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;

// Функция для загрузки XML файла
bool LoadXML(const std::string& fileName, XMLDocument& doc) {
    XMLError eResult = doc.LoadFile(fileName.c_str());
    if (eResult != XML_SUCCESS) {
        std::cerr << "Error loading file: " << fileName << std::endl;
        return false;
    }
    return true;
}

// Функция для сохранения XML файла
bool SaveXML(const std::string& fileName, XMLDocument& doc) {
    XMLError eResult = doc.SaveFile(fileName.c_str());
    if (eResult != XML_SUCCESS) {
        std::cerr << "Error saving file: " << fileName << std::endl;
        return false;
    }
    return true;
}

/*
int get_static_id(){
    using namespace tinyxml2;

    XMLDocument doc;
    std::string fileName = "static.xml";

    // Если файл не существует, создаем новый документ
    if (!LoadXML(fileName, doc)) {
        XMLElement* root = doc.NewElement("static_id");
        root->SetAttribute("id_counter", 1);
        doc.InsertFirstChild(root);
        SaveXML(fileName, doc);
        return 1;
    }

    XMLElement* root = doc.RootElement();
    auto attr = root->FindAttribute("id_counter");
    std::cout << "retrieved static_id " << attr->IntValue() << std::endl;
    return attr->IntValue();
}
*/
class DBObject {
public:
    int id;
    static int id_counter;

    virtual void SetAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) = 0;

    void SetDefaultAttributes(tinyxml2::XMLDocument& doc, tinyxml2::XMLElement* elem) {
        id = id_counter++;
        elem->SetAttribute("id", id);
    }
};

void AddObject(XMLDocument& doc, DBObject* obj) {
    XMLElement* root = doc.RootElement();
    XMLElement* newObject = doc.NewElement("Object");

    obj->SetDefaultAttributes(doc, newObject);
    obj->SetAttributes(doc, newObject);

    root->InsertEndChild(newObject);
}

int DBObject::id_counter = 10;//get_static_id();

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
};