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
 * OAISearchRecipes_200_response.h
 *
 * 
 */

#ifndef OAISearchRecipes_200_response_H
#define OAISearchRecipes_200_response_H

#include <QJsonObject>

#include "com.spoonacular.client.model\OAISearchRecipes_200_response_results_inner.h"
#include <QList>
#include <QSet>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {
class OAISearchRecipes_200_response_results_inner;

class OAISearchRecipes_200_response : public OAIObject {
public:
    OAISearchRecipes_200_response();
    OAISearchRecipes_200_response(QString json);
    ~OAISearchRecipes_200_response() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    qint32 getOffset() const;
    void setOffset(const qint32 &offset);
    bool is_offset_Set() const;
    bool is_offset_Valid() const;

    qint32 getNumber() const;
    void setNumber(const qint32 &number);
    bool is_number_Set() const;
    bool is_number_Valid() const;

    QSet<OAISearchRecipes_200_response_results_inner> getResults() const;
    void setResults(const QSet<OAISearchRecipes_200_response_results_inner> &results);
    bool is_results_Set() const;
    bool is_results_Valid() const;

    qint32 getTotalResults() const;
    void setTotalResults(const qint32 &total_results);
    bool is_total_results_Set() const;
    bool is_total_results_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    qint32 offset;
    bool m_offset_isSet;
    bool m_offset_isValid;

    qint32 number;
    bool m_number_isSet;
    bool m_number_isValid;

    QSet<OAISearchRecipes_200_response_results_inner> results;
    bool m_results_isSet;
    bool m_results_isValid;

    qint32 total_results;
    bool m_total_results_isSet;
    bool m_total_results_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAISearchRecipes_200_response)

#endif // OAISearchRecipes_200_response_H