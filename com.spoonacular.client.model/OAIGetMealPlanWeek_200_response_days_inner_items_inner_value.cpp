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

#include "OAIGetMealPlanWeek_200_response_days_inner_items_inner_value.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::OAIGetMealPlanWeek_200_response_days_inner_items_inner_value(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::OAIGetMealPlanWeek_200_response_days_inner_items_inner_value() {
    this->initializeModel();
}

OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::~OAIGetMealPlanWeek_200_response_days_inner_items_inner_value() {}

void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::initializeModel() {

    m_servings_isSet = false;
    m_servings_isValid = false;

    m_id_isSet = false;
    m_id_isValid = false;

    m_title_isSet = false;
    m_title_isValid = false;

    m_image_type_isSet = false;
    m_image_type_isValid = false;
}

void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::fromJsonObject(QJsonObject json) {

    m_servings_isValid = ::OpenAPI::fromJsonValue(servings, json[QString("servings")]);
    m_servings_isSet = !json[QString("servings")].isNull() && m_servings_isValid;

    m_id_isValid = ::OpenAPI::fromJsonValue(id, json[QString("id")]);
    m_id_isSet = !json[QString("id")].isNull() && m_id_isValid;

    m_title_isValid = ::OpenAPI::fromJsonValue(title, json[QString("title")]);
    m_title_isSet = !json[QString("title")].isNull() && m_title_isValid;

    m_image_type_isValid = ::OpenAPI::fromJsonValue(image_type, json[QString("imageType")]);
    m_image_type_isSet = !json[QString("imageType")].isNull() && m_image_type_isValid;
}

QString OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::asJsonObject() const {
    QJsonObject obj;
    if (m_servings_isSet) {
        obj.insert(QString("servings"), ::OpenAPI::toJsonValue(servings));
    }
    if (m_id_isSet) {
        obj.insert(QString("id"), ::OpenAPI::toJsonValue(id));
    }
    if (m_title_isSet) {
        obj.insert(QString("title"), ::OpenAPI::toJsonValue(title));
    }
    if (m_image_type_isSet) {
        obj.insert(QString("imageType"), ::OpenAPI::toJsonValue(image_type));
    }
    return obj;
}

double OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::getServings() const {
    return servings;
}
void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::setServings(const double &servings) {
    this->servings = servings;
    this->m_servings_isSet = true;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_servings_Set() const{
    return m_servings_isSet;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_servings_Valid() const{
    return m_servings_isValid;
}

double OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::getId() const {
    return id;
}
void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::setId(const double &id) {
    this->id = id;
    this->m_id_isSet = true;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_id_Set() const{
    return m_id_isSet;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_id_Valid() const{
    return m_id_isValid;
}

QString OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::getTitle() const {
    return title;
}
void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::setTitle(const QString &title) {
    this->title = title;
    this->m_title_isSet = true;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_title_Set() const{
    return m_title_isSet;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_title_Valid() const{
    return m_title_isValid;
}

QString OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::getImageType() const {
    return image_type;
}
void OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::setImageType(const QString &image_type) {
    this->image_type = image_type;
    this->m_image_type_isSet = true;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_image_type_Set() const{
    return m_image_type_isSet;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::is_image_type_Valid() const{
    return m_image_type_isValid;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (m_servings_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_id_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_title_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (m_image_type_isSet) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIGetMealPlanWeek_200_response_days_inner_items_inner_value::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_servings_isValid && m_id_isValid && m_title_isValid && m_image_type_isValid && true;
}

} // namespace OpenAPI