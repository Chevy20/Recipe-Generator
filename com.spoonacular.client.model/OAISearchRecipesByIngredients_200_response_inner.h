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
 * OAISearchRecipesByIngredients_200_response_inner.h
 *
 * 
 */

#ifndef OAISearchRecipesByIngredients_200_response_inner_H
#define OAISearchRecipesByIngredients_200_response_inner_H

#include <QJsonObject>

#include "com.spoonacular.client.model\OAIObject.h"
#include "com.spoonacular.client.model\OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner.h"
#include <QList>
#include <QSet>
#include <QString>

#include "OAIEnum.h"
#include "OAIObject.h"

namespace OpenAPI {
class OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner;

class OAISearchRecipesByIngredients_200_response_inner : public OAIObject {
public:
    OAISearchRecipesByIngredients_200_response_inner();
    OAISearchRecipesByIngredients_200_response_inner(QString json);
    ~OAISearchRecipesByIngredients_200_response_inner() override;

    QString asJson() const override;
    QJsonObject asJsonObject() const override;
    void fromJsonObject(QJsonObject json) override;
    void fromJson(QString jsonString) override;

    qint32 getId() const;
    void setId(const qint32 &id);
    bool is_id_Set() const;
    bool is_id_Valid() const;

    QString getImage() const;
    void setImage(const QString &image);
    bool is_image_Set() const;
    bool is_image_Valid() const;

    QString getImageType() const;
    void setImageType(const QString &image_type);
    bool is_image_type_Set() const;
    bool is_image_type_Valid() const;

    qint32 getLikes() const;
    void setLikes(const qint32 &likes);
    bool is_likes_Set() const;
    bool is_likes_Valid() const;

    qint32 getMissedIngredientCount() const;
    void setMissedIngredientCount(const qint32 &missed_ingredient_count);
    bool is_missed_ingredient_count_Set() const;
    bool is_missed_ingredient_count_Valid() const;

    QSet<OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner> getMissedIngredients() const;
    void setMissedIngredients(const QSet<OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner> &missed_ingredients);
    bool is_missed_ingredients_Set() const;
    bool is_missed_ingredients_Valid() const;

    QString getTitle() const;
    void setTitle(const QString &title);
    bool is_title_Set() const;
    bool is_title_Valid() const;

    QList<OAIObject> getUnusedIngredients() const;
    void setUnusedIngredients(const QList<OAIObject> &unused_ingredients);
    bool is_unused_ingredients_Set() const;
    bool is_unused_ingredients_Valid() const;

    double getUsedIngredientCount() const;
    void setUsedIngredientCount(const double &used_ingredient_count);
    bool is_used_ingredient_count_Set() const;
    bool is_used_ingredient_count_Valid() const;

    QSet<OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner> getUsedIngredients() const;
    void setUsedIngredients(const QSet<OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner> &used_ingredients);
    bool is_used_ingredients_Set() const;
    bool is_used_ingredients_Valid() const;

    virtual bool isSet() const override;
    virtual bool isValid() const override;

private:
    void initializeModel();

    qint32 id;
    bool m_id_isSet;
    bool m_id_isValid;

    QString image;
    bool m_image_isSet;
    bool m_image_isValid;

    QString image_type;
    bool m_image_type_isSet;
    bool m_image_type_isValid;

    qint32 likes;
    bool m_likes_isSet;
    bool m_likes_isValid;

    qint32 missed_ingredient_count;
    bool m_missed_ingredient_count_isSet;
    bool m_missed_ingredient_count_isValid;

    QSet<OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner> missed_ingredients;
    bool m_missed_ingredients_isSet;
    bool m_missed_ingredients_isValid;

    QString title;
    bool m_title_isSet;
    bool m_title_isValid;

    QList<OAIObject> unused_ingredients;
    bool m_unused_ingredients_isSet;
    bool m_unused_ingredients_isValid;

    double used_ingredient_count;
    bool m_used_ingredient_count_isSet;
    bool m_used_ingredient_count_isValid;

    QSet<OAISearchRecipesByIngredients_200_response_inner_missedIngredients_inner> used_ingredients;
    bool m_used_ingredients_isSet;
    bool m_used_ingredients_isValid;
};

} // namespace OpenAPI

Q_DECLARE_METATYPE(OpenAPI::OAISearchRecipesByIngredients_200_response_inner)

#endif // OAISearchRecipesByIngredients_200_response_inner_H
