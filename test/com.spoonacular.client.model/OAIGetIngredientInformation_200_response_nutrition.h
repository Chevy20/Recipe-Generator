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
 * OAIGetIngredientInformation_200_response_nutrition.h
 *
 * 
 */

#ifndef OAIGetIngredientInformation_200_response_nutrition_H
#define OAIGetIngredientInformation_200_response_nutrition_H

#include <QJsonObject>

#include "com.spoonacular.client.model\OAIParseIngredients_200_response_inner_nutrition_caloricBreakdown.h"
#include "com.spoonacular.client.model\OAIParseIngredients_200_response_inner_nutrition_nutrients_inner.h"
#include "com.spoonacular.client.model\OAIParseIngredients_200_response_inner_nutrition_properties_inner.h"
#include "com.spoonacular.client.model\OAIParseIngredients_200_response_inner_nutrition_weightPerServing.h"
#include <QList>
#include <QSet>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {
class OAIParseIngredients_200_response_inner_nutrition_nutrients_inner;
class OAIParseIngredients_200_response_inner_nutrition_properties_inner;
class OAIParseIngredients_200_response_inner_nutrition_caloricBreakdown;
class OAIParseIngredients_200_response_inner_nutrition_weightPerServing;

class OAIGetIngredientInformation_200_response_nutrition : public OAIObject {
public:
    OAIGetIngredientInformation_200_response_nutrition();
    OAIGetIngredientInformation_200_response_nutrition(QString json);
    ~OAIGetIngredientInformation_200_response_nutrition() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QSet<OAIParseIngredients_200_response_inner_nutrition_nutrients_inner> getNutrients() const;
    void setNutrients(const QSet<OAIParseIngredients_200_response_inner_nutrition_nutrients_inner> &nutrients);
    bool is_nutrients_Set() const;
    bool is_nutrients_Valid() const;

    QSet<OAIParseIngredients_200_response_inner_nutrition_properties_inner> getProperties() const;
    void setProperties(const QSet<OAIParseIngredients_200_response_inner_nutrition_properties_inner> &properties);
    bool is_properties_Set() const;
    bool is_properties_Valid() const;

    OAIParseIngredients_200_response_inner_nutrition_caloricBreakdown getCaloricBreakdown() const;
    void setCaloricBreakdown(const OAIParseIngredients_200_response_inner_nutrition_caloricBreakdown &caloric_breakdown);
    bool is_caloric_breakdown_Set() const;
    bool is_caloric_breakdown_Valid() const;

    OAIParseIngredients_200_response_inner_nutrition_weightPerServing getWeightPerServing() const;
    void setWeightPerServing(const OAIParseIngredients_200_response_inner_nutrition_weightPerServing &weight_per_serving);
    bool is_weight_per_serving_Set() const;
    bool is_weight_per_serving_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QSet<OAIParseIngredients_200_response_inner_nutrition_nutrients_inner> nutrients;
    bool m_nutrients_isSet;
    bool m_nutrients_isValid;

    QSet<OAIParseIngredients_200_response_inner_nutrition_properties_inner> properties;
    bool m_properties_isSet;
    bool m_properties_isValid;

    OAIParseIngredients_200_response_inner_nutrition_caloricBreakdown caloric_breakdown;
    bool m_caloric_breakdown_isSet;
    bool m_caloric_breakdown_isValid;

    OAIParseIngredients_200_response_inner_nutrition_weightPerServing weight_per_serving;
    bool m_weight_per_serving_isSet;
    bool m_weight_per_serving_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIGetIngredientInformation_200_response_nutrition)

#endif // OAIGetIngredientInformation_200_response_nutrition_H
