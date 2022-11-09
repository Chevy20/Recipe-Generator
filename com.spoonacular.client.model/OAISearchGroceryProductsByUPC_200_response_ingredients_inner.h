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
 * OAISearchGroceryProductsByUPC_200_response_ingredients_inner.h
 *
 * 
 */

#ifndef OAISearchGroceryProductsByUPC_200_response_ingredients_inner_H
#define OAISearchGroceryProductsByUPC_200_response_ingredients_inner_H

#include <QJsonObject>

#include <QJsonValue>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAISearchGroceryProductsByUPC_200_response_ingredients_inner : public OAIObject {
public:
    OAISearchGroceryProductsByUPC_200_response_ingredients_inner();
    OAISearchGroceryProductsByUPC_200_response_ingredients_inner(QString json);
    ~OAISearchGroceryProductsByUPC_200_response_ingredients_inner() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QJsonValue getDescription() const;
    void setDescription(const QJsonValue &description);
    bool is_description_Set() const;
    bool is_description_Valid() const;

    QString getName() const;
    void setName(const QString &name);
    bool is_name_Set() const;
    bool is_name_Valid() const;

    QJsonValue getSafetyLevel() const;
    void setSafetyLevel(const QJsonValue &safety_level);
    bool is_safety_level_Set() const;
    bool is_safety_level_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QJsonValue description;
    bool m_description_isSet;
    bool m_description_isValid;

    QString name;
    bool m_name_isSet;
    bool m_name_isValid;

    QJsonValue safety_level;
    bool m_safety_level_isSet;
    bool m_safety_level_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAISearchGroceryProductsByUPC_200_response_ingredients_inner)

#endif // OAISearchGroceryProductsByUPC_200_response_ingredients_inner_H
