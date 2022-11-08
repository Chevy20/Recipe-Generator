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

#include "OAIGetMealPlanTemplate_200_response_days_inner.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>

#include "OAIHelpers.h"

namespace OpenAPI {

OAIGetMealPlanTemplate_200_response_days_inner::OAIGetMealPlanTemplate_200_response_days_inner(QString json) {
    this->initializeModel();
    this->fromJson(json);
}

OAIGetMealPlanTemplate_200_response_days_inner::OAIGetMealPlanTemplate_200_response_days_inner() {
    this->initializeModel();
}

OAIGetMealPlanTemplate_200_response_days_inner::~OAIGetMealPlanTemplate_200_response_days_inner() {}

void OAIGetMealPlanTemplate_200_response_days_inner::initializeModel() {

    m_nutrition_summary_isSet = false;
    m_nutrition_summary_isValid = false;

    m_nutrition_summary_breakfast_isSet = false;
    m_nutrition_summary_breakfast_isValid = false;

    m_nutrition_summary_lunch_isSet = false;
    m_nutrition_summary_lunch_isValid = false;

    m_nutrition_summary_dinner_isSet = false;
    m_nutrition_summary_dinner_isValid = false;

    m_day_isSet = false;
    m_day_isValid = false;

    m_items_isSet = false;
    m_items_isValid = false;
}

void OAIGetMealPlanTemplate_200_response_days_inner::fromJson(QString jsonString) {
    QByteArray array(jsonString.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
}

void OAIGetMealPlanTemplate_200_response_days_inner::fromJsonObject(QJsonObject json) {

    m_nutrition_summary_isValid = ::OpenAPI::fromJsonValue(nutrition_summary, json[QString("nutritionSummary")]);
    m_nutrition_summary_isSet = !json[QString("nutritionSummary")].isNull() && m_nutrition_summary_isValid;

    m_nutrition_summary_breakfast_isValid = ::OpenAPI::fromJsonValue(nutrition_summary_breakfast, json[QString("nutritionSummaryBreakfast")]);
    m_nutrition_summary_breakfast_isSet = !json[QString("nutritionSummaryBreakfast")].isNull() && m_nutrition_summary_breakfast_isValid;

    m_nutrition_summary_lunch_isValid = ::OpenAPI::fromJsonValue(nutrition_summary_lunch, json[QString("nutritionSummaryLunch")]);
    m_nutrition_summary_lunch_isSet = !json[QString("nutritionSummaryLunch")].isNull() && m_nutrition_summary_lunch_isValid;

    m_nutrition_summary_dinner_isValid = ::OpenAPI::fromJsonValue(nutrition_summary_dinner, json[QString("nutritionSummaryDinner")]);
    m_nutrition_summary_dinner_isSet = !json[QString("nutritionSummaryDinner")].isNull() && m_nutrition_summary_dinner_isValid;

    m_day_isValid = ::OpenAPI::fromJsonValue(day, json[QString("day")]);
    m_day_isSet = !json[QString("day")].isNull() && m_day_isValid;

    m_items_isValid = ::OpenAPI::fromJsonValue(items, json[QString("items")]);
    m_items_isSet = !json[QString("items")].isNull() && m_items_isValid;
}

QString OAIGetMealPlanTemplate_200_response_days_inner::asJson() const {
    QJsonObject obj = this->asJsonObject();
    QJsonDocument doc(obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject OAIGetMealPlanTemplate_200_response_days_inner::asJsonObject() const {
    QJsonObject obj;
    if (nutrition_summary.isSet()) {
        obj.insert(QString("nutritionSummary"), ::OpenAPI::toJsonValue(nutrition_summary));
    }
    if (nutrition_summary_breakfast.isSet()) {
        obj.insert(QString("nutritionSummaryBreakfast"), ::OpenAPI::toJsonValue(nutrition_summary_breakfast));
    }
    if (nutrition_summary_lunch.isSet()) {
        obj.insert(QString("nutritionSummaryLunch"), ::OpenAPI::toJsonValue(nutrition_summary_lunch));
    }
    if (nutrition_summary_dinner.isSet()) {
        obj.insert(QString("nutritionSummaryDinner"), ::OpenAPI::toJsonValue(nutrition_summary_dinner));
    }
    if (m_day_isSet) {
        obj.insert(QString("day"), ::OpenAPI::toJsonValue(day));
    }
    if (items.size() > 0) {
        obj.insert(QString("items"), ::OpenAPI::toJsonValue(items));
    }
    return obj;
}

OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary OAIGetMealPlanTemplate_200_response_days_inner::getNutritionSummary() const {
    return nutrition_summary;
}
void OAIGetMealPlanTemplate_200_response_days_inner::setNutritionSummary(const OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary &nutrition_summary) {
    this->nutrition_summary = nutrition_summary;
    this->m_nutrition_summary_isSet = true;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_Set() const{
    return m_nutrition_summary_isSet;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_Valid() const{
    return m_nutrition_summary_isValid;
}

OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary OAIGetMealPlanTemplate_200_response_days_inner::getNutritionSummaryBreakfast() const {
    return nutrition_summary_breakfast;
}
void OAIGetMealPlanTemplate_200_response_days_inner::setNutritionSummaryBreakfast(const OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary &nutrition_summary_breakfast) {
    this->nutrition_summary_breakfast = nutrition_summary_breakfast;
    this->m_nutrition_summary_breakfast_isSet = true;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_breakfast_Set() const{
    return m_nutrition_summary_breakfast_isSet;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_breakfast_Valid() const{
    return m_nutrition_summary_breakfast_isValid;
}

OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary OAIGetMealPlanTemplate_200_response_days_inner::getNutritionSummaryLunch() const {
    return nutrition_summary_lunch;
}
void OAIGetMealPlanTemplate_200_response_days_inner::setNutritionSummaryLunch(const OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary &nutrition_summary_lunch) {
    this->nutrition_summary_lunch = nutrition_summary_lunch;
    this->m_nutrition_summary_lunch_isSet = true;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_lunch_Set() const{
    return m_nutrition_summary_lunch_isSet;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_lunch_Valid() const{
    return m_nutrition_summary_lunch_isValid;
}

OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary OAIGetMealPlanTemplate_200_response_days_inner::getNutritionSummaryDinner() const {
    return nutrition_summary_dinner;
}
void OAIGetMealPlanTemplate_200_response_days_inner::setNutritionSummaryDinner(const OAIGetMealPlanWeek_200_response_days_inner_nutritionSummary &nutrition_summary_dinner) {
    this->nutrition_summary_dinner = nutrition_summary_dinner;
    this->m_nutrition_summary_dinner_isSet = true;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_dinner_Set() const{
    return m_nutrition_summary_dinner_isSet;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_nutrition_summary_dinner_Valid() const{
    return m_nutrition_summary_dinner_isValid;
}

QString OAIGetMealPlanTemplate_200_response_days_inner::getDay() const {
    return day;
}
void OAIGetMealPlanTemplate_200_response_days_inner::setDay(const QString &day) {
    this->day = day;
    this->m_day_isSet = true;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_day_Set() const{
    return m_day_isSet;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_day_Valid() const{
    return m_day_isValid;
}

QSet<OAIGetMealPlanTemplate_200_response_days_inner_items_inner> OAIGetMealPlanTemplate_200_response_days_inner::getItems() const {
    return items;
}
void OAIGetMealPlanTemplate_200_response_days_inner::setItems(const QSet<OAIGetMealPlanTemplate_200_response_days_inner_items_inner> &items) {
    this->items = items;
    this->m_items_isSet = true;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_items_Set() const{
    return m_items_isSet;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::is_items_Valid() const{
    return m_items_isValid;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::isSet() const {
    bool isObjectUpdated = false;
    do {
        if (nutrition_summary.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (nutrition_summary_breakfast.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (nutrition_summary_lunch.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (nutrition_summary_dinner.isSet()) {
            isObjectUpdated = true;
            break;
        }

        if (m_day_isSet) {
            isObjectUpdated = true;
            break;
        }

        if (items.size() > 0) {
            isObjectUpdated = true;
            break;
        }
    } while (false);
    return isObjectUpdated;
}

bool OAIGetMealPlanTemplate_200_response_days_inner::isValid() const {
    // only required properties are required for the object to be considered valid
    return m_day_isValid && true;
}

} // namespace OpenAPI