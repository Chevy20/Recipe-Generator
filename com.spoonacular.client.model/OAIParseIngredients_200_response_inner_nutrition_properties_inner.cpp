/**
 * spoonacular API
 * The spoonacular Nutrition, Recipe, and Food API allows you to access over thousands of recipes, thousands of ingredients, 800,000 food products, over 100,000 menu items, and restaurants. Our food ontology and semantic recipe search engine makes it possible to search for recipes using natural language queries, such as \"gluten free brownies without sugar\" or \"low fat vegan cupcakes.\" You can automatically calculate the nutritional information for any recipe, analyze recipe costs, visualize ingredient lists, find recipes for what's in your fridge, find recipes based on special diets, nutritional requirements, or favorite ingredients, classify recipes into types and cuisines, convert ingredient amounts, or even compute an entire meal plan. With our powerful API, you can create many kinds of food and especially nutrition apps.  Special diets/dietary requirements currently available include: vegan, vegetarian, pescetarian, gluten free, grain free, dairy free, high protein, whole 30, low sodium, low carb, Paleo, ketogenic, FODMAP, and Primal.
 *
 * The version of the OpenAPI document: 1.1
 * Contact: mail@spoonacular.com
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#include "OAIParseIngredients_200_response_inner_nutrition_properties_inner.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIParseIngredients_200_response_inner_nutrition_properties_inner::OAIParseIngredients_200_response_inner_nutrition_properties_inner(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIParseIngredients_200_response_inner_nutrition_properties_inner::OAIParseIngredients_200_response_inner_nutrition_properties_inner() {
    this->initializeModel();
}

OAIParseIngredients_200_response_inner_nutrition_properties_inner::~OAIParseIngredients_200_response_inner_nutrition_properties_inner() {}

void OAIParseIngredients_200_response_inner_nutrition_properties_inner::initializeModel() {

    m_name_isSet = false;
    m_name_isValid = false;

    m_amount_isSet = false;
    m_amount_isValid = false;

    m_unit_isSet = false;
    m_unit_isValid = false;
}

void OAIParseIngredients_200_response_inner_nutrition_properties_inner::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIParseIngredients_200_response_inner_nutrition_properties_inner::fromJsonObject(QJsonObject json) {

    m_name_isValid = ::OpenAPI::fromJsonValue(name, json[QString("name")]);
    m_name_isSet = !json[QString("name")].isNull() && m_name_isValid;

    m_amount_isValid = ::OpenAPI::fromJsonValue(amount, json[QString("amount")]);
    m_amount_isSet = !json[QString("amount")].isNull() && m_amount_isValid;

    m_unit_isValid = ::OpenAPI::fromJsonValue(unit, json[QString("unit")]);
    m_unit_isSet = !json[QString("unit")].isNull() && m_unit_isValid;
}

QString OAIParseIngredients_200_response_inner_nutrition_properties_inner::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIParseIngredients_200_response_inner_nutrition_properties_inner::asJsonObject() const {
    QJsonObject obj;
    if (m_name_isSet) {
        obj.insert(QString("name"), ::OpenAPI::toJsonValue(name));
    }
    if (m_amount_isSet) {
        obj.insert(QString("amount"), ::OpenAPI::toJsonValue(amount));
    }
    if (m_unit_isSet) {
        obj.insert(QString("unit"), ::OpenAPI::toJsonValue(unit));
    }
    return obj;
}

QString OAIParseIngredients_200_response_inner_nutrition_properties_inner::getName() const {
    return name;
}
void OAIParseIngredients_200_response_inner_nutrition_properties_inner::setName(const QString &name) {
    this->name = name;
    this->m_name_isSet = true;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::is_name_Set() const{
    return m_name_isSet;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::is_name_Valid() const{
    return m_name_isValid;
}

double OAIParseIngredients_200_response_inner_nutrition_properties_inner::getAmount() const {
    return amount;
}
void OAIParseIngredients_200_response_inner_nutrition_properties_inner::setAmount(const double &amount) {
    this->amount = amount;
    this->m_amount_isSet = true;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::is_amount_Set() const{
    return m_amount_isSet;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::is_amount_Valid() const{
    return m_amount_isValid;
}

QString OAIParseIngredients_200_response_inner_nutrition_properties_inner::getUnit() const {
    return unit;
}
void OAIParseIngredients_200_response_inner_nutrition_properties_inner::setUnit(const QString &unit) {
    this->unit = unit;
    this->m_unit_isSet = true;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::is_unit_Set() const{
    return m_unit_isSet;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::is_unit_Valid() const{
    return m_unit_isValid;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_name_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_amount_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_unit_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIParseIngredients_200_response_inner_nutrition_properties_inner::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_name_isValid && m_amount_isValid && m_unit_isValid && true;
}

} // namespace OpenAPI
