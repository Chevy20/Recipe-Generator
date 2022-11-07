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

/*
 * OAIClassifyCuisine_200_response.h
 *
 * 
 */

#ifndef OAIClassifyCuisine_200_response_H
#define OAIClassifyCuisine_200_response_H

#include <QJsonObject>

#include <QList>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIClassifyCuisine_200_response : public OAIObject {
public:
    OAIClassifyCuisine_200_response();
    OAIClassifyCuisine_200_response(QString json);
    ~OAIClassifyCuisine_200_response() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getCuisine() const;
    void setCuisine(const QString &cuisine);
    bool is_cuisine_Set() const;
    bool is_cuisine_Valid() const;

    QList<QString> getCuisines() const;
    void setCuisines(const QList<QString> &cuisines);
    bool is_cuisines_Set() const;
    bool is_cuisines_Valid() const;

    double getConfidence() const;
    void setConfidence(const double &confidence);
    bool is_confidence_Set() const;
    bool is_confidence_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString cuisine;
    bool m_cuisine_isSet;
    bool m_cuisine_isValid;

    QList<QString> cuisines;
    bool m_cuisines_isSet;
    bool m_cuisines_isValid;

    double confidence;
    bool m_confidence_isSet;
    bool m_confidence_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIClassifyCuisine_200_response)

#endif // OAIClassifyCuisine_200_response_H
