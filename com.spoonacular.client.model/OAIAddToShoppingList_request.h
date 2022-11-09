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
 * OAIAddToShoppingList_request.h
 *
 * 
 */

#ifndef OAIAddToShoppingList_request_H
#define OAIAddToShoppingList_request_H

#include <QJsonObject>

#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {

class OAIAddToShoppingList_request : public OAIObject {
public:
    OAIAddToShoppingList_request();
    OAIAddToShoppingList_request(QString json);
    ~OAIAddToShoppingList_request() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    QString getItem() const;
    void setItem(const QString &item);
    bool is_item_Set() const;
    bool is_item_Valid() const;

    QString getAisle() const;
    void setAisle(const QString &aisle);
    bool is_aisle_Set() const;
    bool is_aisle_Valid() const;

    bool isParse() const;
    void setParse(const bool &parse);
    bool is_parse_Set() const;
    bool is_parse_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    QString item;
    bool m_item_isSet;
    bool m_item_isValid;

    QString aisle;
    bool m_aisle_isSet;
    bool m_aisle_isValid;

    bool parse;
    bool m_parse_isSet;
    bool m_parse_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIAddToShoppingList_request)

#endif // OAIAddToShoppingList_request_H
