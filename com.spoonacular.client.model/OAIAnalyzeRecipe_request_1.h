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
 * OAIAnalyzeRecipe_request_1.h
 *
 * 
 */

#ifndef OAIAnalyzeRecipe_request_1_H
#define OAIAnalyzeRecipe_request_1_H

#include <QJsonObject>

#include <QList>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIAnalyzeRecipe_request_1 : public OAIObject {
public:
    OAIAnalyzeRecipe_request_1();
    OAIAnalyzeRecipe_request_1(QString json);
    ~OAIAnalyzeRecipe_request_1() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getTitle() const;
    void setTitle(const QString &title);
    bool is_title_Set() const;
    bool is_title_Valid() const;

    qint32 getServings() const;
    void setServings(const qint32 &servings);
    bool is_servings_Set() const;
    bool is_servings_Valid() const;

    QList<QString> getIngredients() const;
    void setIngredients(const QList<QString> &ingredients);
    bool is_ingredients_Set() const;
    bool is_ingredients_Valid() const;

    QString getInstructions() const;
    void setInstructions(const QString &instructions);
    bool is_instructions_Set() const;
    bool is_instructions_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString title;
    bool m_title_isSet;
    bool m_title_isValid;

    qint32 servings;
    bool m_servings_isSet;
    bool m_servings_isValid;

    QList<QString> ingredients;
    bool m_ingredients_isSet;
    bool m_ingredients_isValid;

    QString instructions;
    bool m_instructions_isSet;
    bool m_instructions_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIAnalyzeRecipe_request_1)

#endif // OAIAnalyzeRecipe_request_1_H
