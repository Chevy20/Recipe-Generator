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

#include "OAIImageAnalysisByURL_200_response.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIImageAnalysisByURL_200_response::OAIImageAnalysisByURL_200_response(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIImageAnalysisByURL_200_response::OAIImageAnalysisByURL_200_response() {
    this->initializeModel();
}

OAIImageAnalysisByURL_200_response::~OAIImageAnalysisByURL_200_response() {}

void OAIImageAnalysisByURL_200_response::initializeModel() {

    m_nutrition_isSet = false;
    m_nutrition_isValid = false;

    m_category_isSet = false;
    m_category_isValid = false;

    m_recipes_isSet = false;
    m_recipes_isValid = false;
}

void OAIImageAnalysisByURL_200_response::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIImageAnalysisByURL_200_response::fromJsonObject(QJsonObject json) {

    m_nutrition_isValid = ::OpenAPI::fromJsonValue(nutrition, json[QString("nutrition")]);
    m_nutrition_isSet = !json[QString("nutrition")].isNull() && m_nutrition_isValid;

    m_category_isValid = ::OpenAPI::fromJsonValue(category, json[QString("category")]);
    m_category_isSet = !json[QString("category")].isNull() && m_category_isValid;

    m_recipes_isValid = ::OpenAPI::fromJsonValue(recipes, json[QString("recipes")]);
    m_recipes_isSet = !json[QString("recipes")].isNull() && m_recipes_isValid;
}

QString OAIImageAnalysisByURL_200_response::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIImageAnalysisByURL_200_response::asJsonObject() const {
    QJsonObject obj;
    if (nutrition.isSet()) {
        obj.insert(QString("nutrition"), ::OpenAPI::toJsonValue(nutrition));
    }
    if (category.isSet()) {
        obj.insert(QString("category"), ::OpenAPI::toJsonValue(category));
    }
    if (recipes.size() > 0) {
        obj.insert(QString("recipes"), ::OpenAPI::toJsonValue(recipes));
    }
    return obj;
}

OAIImageAnalysisByURL_200_response_nutrition OAIImageAnalysisByURL_200_response::getNutrition() const {
    return nutrition;
}
void OAIImageAnalysisByURL_200_response::setNutrition(const OAIImageAnalysisByURL_200_response_nutrition &nutrition) {
    this->nutrition = nutrition;
    this->m_nutrition_isSet = true;
}

bool OAIImageAnalysisByURL_200_response::is_nutrition_Set() const{
    return m_nutrition_isSet;
}

bool OAIImageAnalysisByURL_200_response::is_nutrition_Valid() const{
    return m_nutrition_isValid;
}

OAIImageAnalysisByURL_200_response_category OAIImageAnalysisByURL_200_response::getCategory() const {
    return category;
}
void OAIImageAnalysisByURL_200_response::setCategory(const OAIImageAnalysisByURL_200_response_category &category) {
    this->category = category;
    this->m_category_isSet = true;
}

bool OAIImageAnalysisByURL_200_response::is_category_Set() const{
    return m_category_isSet;
}

bool OAIImageAnalysisByURL_200_response::is_category_Valid() const{
    return m_category_isValid;
}

QSet<OAIImageAnalysisByURL_200_response_recipes_inner> OAIImageAnalysisByURL_200_response::getRecipes() const {
    return recipes;
}
void OAIImageAnalysisByURL_200_response::setRecipes(const QSet<OAIImageAnalysisByURL_200_response_recipes_inner> &recipes) {
    this->recipes = recipes;
    this->m_recipes_isSet = true;
}

bool OAIImageAnalysisByURL_200_response::is_recipes_Set() const{
    return m_recipes_isSet;
}

bool OAIImageAnalysisByURL_200_response::is_recipes_Valid() const{
    return m_recipes_isValid;
}

bool OAIImageAnalysisByURL_200_response::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (nutrition.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (category.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (recipes.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIImageAnalysisByURL_200_response::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_nutrition_isValid && m_category_isValid && m_recipes_isValid && true;
}

} // namespace OpenAPI
