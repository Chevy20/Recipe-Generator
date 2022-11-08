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
 * OAIGetMenuItemInformation_200_response.h
 *
 * 
 */

#ifndef OAIGetMenuItemInformation_200_response_H
#define OAIGetMenuItemInformation_200_response_H

#include <QJsonObject>

#include "com.spoonacular.client.model\OAISearchGroceryProductsByUPC_200_response_nutrition.h"
#include "com.spoonacular.client.model\OAISearchGroceryProductsByUPC_200_response_servings.h"
#include <QList>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {
class OAISearchGroceryProductsByUPC_200_response_nutrition;
class OAISearchGroceryProductsByUPC_200_response_servings;

class OAIGetMenuItemInformation_200_response : public OAIObject {
public:
    OAIGetMenuItemInformation_200_response();
    OAIGetMenuItemInformation_200_response(QString json);
    ~OAIGetMenuItemInformation_200_response() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    qint32 getId() const;
    void setId(const qint32 &id);
    bool is_id_Set() const;
    bool is_id_Valid() const;

    QString getTitle() const;
    void setTitle(const QString &title);
    bool is_title_Set() const;
    bool is_title_Valid() const;

    QString getRestaurantChain() const;
    void setRestaurantChain(const QString &restaurant_chain);
    bool is_restaurant_chain_Set() const;
    bool is_restaurant_chain_Valid() const;

    OAISearchGroceryProductsByUPC_200_response_nutrition getNutrition() const;
    void setNutrition(const OAISearchGroceryProductsByUPC_200_response_nutrition &nutrition);
    bool is_nutrition_Set() const;
    bool is_nutrition_Valid() const;

    QList<QString> getBadges() const;
    void setBadges(const QList<QString> &badges);
    bool is_badges_Set() const;
    bool is_badges_Valid() const;

    QList<QString> getBreadcrumbs() const;
    void setBreadcrumbs(const QList<QString> &breadcrumbs);
    bool is_breadcrumbs_Set() const;
    bool is_breadcrumbs_Valid() const;

    QString getGeneratedText() const;
    void setGeneratedText(const QString &generated_text);
    bool is_generated_text_Set() const;
    bool is_generated_text_Valid() const;

    QString getImageType() const;
    void setImageType(const QString &image_type);
    bool is_image_type_Set() const;
    bool is_image_type_Valid() const;

    double getLikes() const;
    void setLikes(const double &likes);
    bool is_likes_Set() const;
    bool is_likes_Valid() const;

    OAISearchGroceryProductsByUPC_200_response_servings getServings() const;
    void setServings(const OAISearchGroceryProductsByUPC_200_response_servings &servings);
    bool is_servings_Set() const;
    bool is_servings_Valid() const;

    double getPrice() const;
    void setPrice(const double &price);
    bool is_price_Set() const;
    bool is_price_Valid() const;

    double getSpoonacularScore() const;
    void setSpoonacularScore(const double &spoonacular_score);
    bool is_spoonacular_score_Set() const;
    bool is_spoonacular_score_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    qint32 id;
    bool m_id_isSet;
    bool m_id_isValid;

    QString title;
    bool m_title_isSet;
    bool m_title_isValid;

    QString restaurant_chain;
    bool m_restaurant_chain_isSet;
    bool m_restaurant_chain_isValid;

    OAISearchGroceryProductsByUPC_200_response_nutrition nutrition;
    bool m_nutrition_isSet;
    bool m_nutrition_isValid;

    QList<QString> badges;
    bool m_badges_isSet;
    bool m_badges_isValid;

    QList<QString> breadcrumbs;
    bool m_breadcrumbs_isSet;
    bool m_breadcrumbs_isValid;

    QString generated_text;
    bool m_generated_text_isSet;
    bool m_generated_text_isValid;

    QString image_type;
    bool m_image_type_isSet;
    bool m_image_type_isValid;

    double likes;
    bool m_likes_isSet;
    bool m_likes_isValid;

    OAISearchGroceryProductsByUPC_200_response_servings servings;
    bool m_servings_isSet;
    bool m_servings_isValid;

    double price;
    bool m_price_isSet;
    bool m_price_isValid;

    double spoonacular_score;
    bool m_spoonacular_score_isSet;
    bool m_spoonacular_score_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAIGetMenuItemInformation_200_response)

#endif // OAIGetMenuItemInformation_200_response_H
