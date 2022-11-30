#include "WebView.h"

using namespace Wt;


WebView::WebView(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
{
    // Get Application instance
    app = WApplication::instance();
    content_=0;
    
    // Set application attributes
    setTitle(APP_NAME);
    setTheme(std::make_shared<WBootstrap5Theme>());

    //set up logger
    WServer srv;
    srv.logger().setFile("wt_log.txt");
    srv.logger().configure("* -debug debug:wthttp");
    

    // Define model
    setModel(new Model());
    // Path change
    app->internalPathChanged().connect([=]{
      handleInternalPathChange();
    });

    // Set up main containers and layout
    auto container = new WContainerWidget();
    container->setWidth(WLength(50, LengthUnit::Percentage));
    horizBox = container->setLayout(std::make_unique<WHBoxLayout>());

    // Add navbar
    auto navbarCont = navbar();
    app->root()->addWidget(std::unique_ptr<WContainerWidget>(navbarCont));

    // Add sidebar
    auto sidebarCont = std::unique_ptr<WContainerWidget>(sidebar());
    horizBox->addWidget(std::move(sidebarCont));

    // Add the content widget
    auto contentContainer = std::unique_ptr<WContainerWidget>(content());
    horizBox->addWidget(std::move(contentContainer));

    app->root()->addWidget(std::unique_ptr<WContainerWidget>(container));

}

/**
 * Navigation Bar - NOT USED
*/
WContainerWidget* WebView::navbar(){

    // Create navigation bar container
    auto nav_container = new WContainerWidget();
   
    //Create nav bar
    WNavigationBar *nav = nav_container->addNew<WNavigationBar>();
    nav->setResponsive(true);
    nav->addStyleClass("navbar-light bg-light");
    nav->setTitle("Freschipes", "/");

    /*
    WStackedWidget *menuStack = nav_container->addNew<WStackedWidget>();
    menuStack->addStyleClass("contents");
    
    // Setup a Left-aligned menu.
    auto leftMenu = std::make_unique<Wt::WMenu>(menuStack);
    auto leftNavMenu = nav->addMenu(std::move(leftMenu));

    // Create a popup submenu for the Recipe menu.
    auto recipePopupPtr = std::make_unique<Wt::WPopupMenu>();
    auto recipePopup = recipePopupPtr.get();
    recipePopup->addItem("Find By Item")
        ->setLink(WLink(LinkType::InternalPath, "recipe-by-item"));
    recipePopup->addItem("Find for All Stock")
        ->setLink(WLink(LinkType::InternalPath, "recipe-by-all-stock"));

    // Create a popup submenu for the Stock menu.
    auto stockPopupPtr = std::make_unique<Wt::WPopupMenu>();
    auto stockPopup = stockPopupPtr.get();
    stockPopup->addItem("Add")->setLink(WLink(LinkType::InternalPath, "add-stock"));
    stockPopup->addItem("Delete")->setLink(WLink(LinkType::InternalPath, "delete-stock"));
    stockPopup->addItem("Edit")->setLink(WLink(LinkType::InternalPath, "edit-stock"));
    stockPopup->addItem("Find")->setLink(WLink(LinkType::InternalPath, "find-stock"));

    auto searchResult = std::make_unique<Wt::WText>("Buy or Sell... Bye!");
    auto searchResult_ = searchResult.get();

    leftNavMenu->addItem("Home", std::make_unique<Wt::WText>("There is no better place!"))
       ->setLink(Wt::WLink(LinkType::InternalPath, "/"));
    
    auto stockItem = std::make_unique<Wt::WMenuItem>("Stock");
    stockItem->setMenu(std::move(stockPopupPtr));
    leftNavMenu->addItem(std::move(stockItem));
 
     auto recipeItem = std::make_unique<Wt::WMenuItem>("Recipes");
    recipeItem->setMenu(std::move(recipePopupPtr));
    leftNavMenu->addItem(std::move(recipeItem));

    leftNavMenu->addItem("TEST", std::move(searchResult));
    leftNavMenu->addStyleClass("me-auto");

    // Add a Search control.
    auto editPtr = std::make_unique<Wt::WLineEdit>();
    auto edit = editPtr.get();
    edit->setPlaceholderText("Enter a search item");

    edit->enterPressed().connect([=] {
    leftNavMenu->select(2); // is the index of the "Sales"
    searchResult_->setText(Wt::WString("Nothing found for {1}.")
                                    .arg(edit->text()));
    });

    nav->addSearch(std::move(editPtr));

    // Setup a Right-aligned menu.
    auto rightMenu = std::make_unique<Wt::WMenu>();
    auto rightNavMenu = nav->addMenu(std::move(rightMenu));

    // Create a popup submenu for the Help menu.
    auto popupPtr = std::make_unique<Wt::WPopupMenu>();
    auto popup = popupPtr.get();
    popup->addItem("Contents");
    popup->addItem("Index");
    popup->addSeparator();
    popup->addItem("About");

    popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
        auto messageBox = popup->addChild(
                std::make_unique<Wt::WMessageBox>
                ("Help",
                Wt::WString("<p>Showing Help: {1}</p>").arg(item->text()),
                Wt::Icon::Information,
                Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            popup->removeChild(messageBox);
        });

        messageBox->show();
    });

    auto menuItem = std::make_unique<Wt::WMenuItem>("Help");
    menuItem->setMenu(std::move(popupPtr));
    rightNavMenu->addItem(std::move(menuItem));
    */
    return nav_container;

}


/**
 * Build Sidebar Navigation
*/
WContainerWidget* WebView::sidebar(){

  // Create sidebar container
  auto sidebarCont = new WContainerWidget();
  sidebarCont->setWidth(WLength(20,WLength::Unit::Percentage));
  sidebarCont->setHeight(WLength(100,WLength::Unit::Percentage));

  // Create panel for stock buttons to be added oin
  auto stockPanel = sidebarCont->addWidget(std::make_unique<Wt::WPanel>());
  stockPanel->addStyleClass("centered-example");
  stockPanel->setTitle("STOCK ACTIONS");

  // Create container for pushbuttons
  auto stockPbCont = new WContainerWidget();

  // Add pushbuttons to pb container
  // Add Item Button
  auto addItemBtn = stockPbCont->addWidget(std::make_unique<Wt::WPushButton>("Add Item"));
  addItemBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, addItemPath));
  addItemBtn->setMargin(5, Wt::Side::Bottom);
  addItemBtn->setVerticalAlignment(AlignmentFlag::Center);
  addItemBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  addItemBtn->setStyleClass("btn-success");
  stockPbCont->addWidget(std::make_unique<WBreak>());
  
  // Delete Item Button
  auto deleteItemBtn = stockPbCont->addWidget(std::make_unique<Wt::WPushButton>("Delete Item"));
  deleteItemBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, deleteItemPath));
  deleteItemBtn->setMargin(5, Wt::Side::Bottom);
  deleteItemBtn->setVerticalAlignment(AlignmentFlag::Center);
  deleteItemBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  deleteItemBtn->setStyleClass("btn-success");
  stockPbCont->addWidget(std::make_unique<WBreak>());
  
  // Modify Item Button
  auto modItemBtn = stockPbCont->addWidget(std::make_unique<Wt::WPushButton>("Modify Item"));
  modItemBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, modItemPath));
  modItemBtn->setMargin(5, Wt::Side::Bottom);
  modItemBtn->setVerticalAlignment(AlignmentFlag::Center);
  modItemBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  modItemBtn->setStyleClass("btn-success");

 // Find Item Button
  auto findStockItemBtn = stockPbCont->addWidget(std::make_unique<Wt::WPushButton>("Find Item"));
  findStockItemBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, findItemPath));
  findStockItemBtn->setMargin(5, Wt::Side::Bottom);
  findStockItemBtn->setVerticalAlignment(AlignmentFlag::Center);
  findStockItemBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  findStockItemBtn->setStyleClass("btn-success");

  stockPbCont->addWidget(std::make_unique<WBreak>());
  stockPbCont->setVerticalAlignment(AlignmentFlag::Center);

  // Add stock action pbs to panel
  stockPanel->setCentralWidget(std::unique_ptr<WContainerWidget>(stockPbCont));

  sidebarCont->addWidget(std::make_unique<WBreak>());

  // Create panel for Recipe buttons to be added in
  auto recipePanel = sidebarCont->addWidget(std::make_unique<Wt::WPanel>());
  recipePanel->addStyleClass("centered-example");
  recipePanel->setTitle("RECIPE ACTIONS");

  // Create container for pushbuttons
  auto recipePbCont = new WContainerWidget();

  // Add pushbuttons to pb container
  // Find Recipe by Item Button
  auto findRecipeByItemBtn = recipePbCont->addWidget(std::make_unique<Wt::WPushButton>("Find By Item"));
  findRecipeByItemBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, "recipe-by-item"));
  findRecipeByItemBtn->setMargin(5, Wt::Side::Bottom);
  findRecipeByItemBtn->setVerticalAlignment(AlignmentFlag::Center);
  findRecipeByItemBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  findRecipeByItemBtn->setStyleClass("btn-success");
  recipePbCont->addWidget(std::make_unique<WBreak>());
  
  // Find Recipes for all stock Button
  auto findRecipeForAllBtn = recipePbCont->addWidget(std::make_unique<Wt::WPushButton>("Find for All Items"));
  findRecipeForAllBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, "recipe-all-stock"));
  findRecipeForAllBtn->setMargin(5, Wt::Side::Bottom);
  findRecipeForAllBtn->setVerticalAlignment(AlignmentFlag::Center);
  findRecipeForAllBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  findRecipeForAllBtn->setStyleClass("btn-success");
  recipePbCont->addWidget(std::make_unique<WBreak>());
  
  // Select Recipe to Cook Button
  auto selectRecipeBtn = recipePbCont->addWidget(std::make_unique<Wt::WPushButton>("Select Recipe"));
  selectRecipeBtn->setLink(Wt::WLink(Wt::LinkType::InternalPath, "recipe-select"));
  selectRecipeBtn->setMargin(5, Wt::Side::Bottom);
  selectRecipeBtn->setVerticalAlignment(AlignmentFlag::Center);
  selectRecipeBtn->setWidth(WLength(NAV_BUTTON_WIDTH,WLength::Unit::Percentage));
  selectRecipeBtn->setStyleClass("btn-success");

  recipePbCont->addWidget(std::make_unique<WBreak>());
  recipePbCont->setVerticalAlignment(AlignmentFlag::Center);

  // Add stock action pbs to panel
  recipePanel->setCentralWidget(std::unique_ptr<WContainerWidget>(recipePbCont));

  return sidebarCont;

}

/**
 * Page Content
*/
WContainerWidget* WebView::content(){
  
  if (content_ == 0) {
    content_ = new WContainerWidget();
    content_->setId("content");
  }
  
  return content_;
}

/**
 * Add Stock Item
 * */ 
WContainerWidget* WebView::addStockItem(){

    auto container = new WContainerWidget();
    auto addStockCont = new WContainerWidget();
    
    // Create panel for Recipe buttons to be added in
    auto addPanel = container->addWidget(std::make_unique<WPanel>());
    addPanel->addStyleClass("centered-example");
    addPanel->setTitle("ADD ITEM TO STOCK");
    addPanel->setWidth(WLength(100,LengthUnit::Percentage));

    // Item Name
    auto nameContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());
    nameContainer->setId("nameContainer");
    // nameContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Mesurement Unit Entry
    auto unitContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    unitContainer->addWidget(std::make_unique<Wt::WText>("Measurement Unit"));
    unitEdit_ = unitContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    unitContainer->addWidget(std::make_unique<Wt::WBreak>());
    unitContainer->setId("unitContainer");
    // unitContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Quantity Entry
    auto qtyContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    qtyContainer->addWidget(std::make_unique<Wt::WText>("Quantity"));
    qtyEdit_ = qtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    qtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    qtyContainer->setId("qtyContainer");
    // qtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Date Purchased Entry
    auto purchaseContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    purchaseContainer->addWidget(std::make_unique<Wt::WText>("Purchase Date (YYYY/MM/DD)"));
    purchaseEdit_ = purchaseContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    purchaseContainer->addWidget(std::make_unique<Wt::WBreak>());
    purchaseContainer->setId("purchaseContainer");
    // purchaseContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Expiry Date Entry
    auto expiryContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    expiryContainer->addWidget(std::make_unique<Wt::WText>("Expiration Date (YYYY/MM/DD)"));
    expiryEdit_ = expiryContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    expiryContainer->addWidget(std::make_unique<Wt::WBreak>());
    expiryContainer->setId("expiryContainer");
    // expiryContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Storage Location Entry
    auto locationContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    locationContainer->addWidget(std::make_unique<Wt::WText>("Storage Location"));
    locationEdit_ = locationContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    locationContainer->addWidget(std::make_unique<Wt::WBreak>());
    locationContainer->setId("locationContainer");
    // locationContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Stock Low Alert Quantity Entry
    auto alertQtyContainer = addStockCont->addWidget(std::make_unique<WContainerWidget>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WText>("Low Qty Threshold"));
    alertQtyEdit_ = alertQtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    alertQtyContainer->setId("locationContainer");
    // alertQtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Add to Stock Pushbutton
    Wt::WPushButton *addItemBtn = addStockCont->addWidget(std::make_unique<Wt::WPushButton>("Add Item to Stock"));
    addStockCont->addWidget(std::make_unique<Wt::WBreak>());
    addStockCont->addWidget(std::make_unique<Wt::WBreak>());
    
    // Build the FoodItem and connect the Add stock button
    auto addItem = [this]{
      FoodItem *fi = new FoodItem(nameEdit_->text().toUTF8(), std::stoi(qtyEdit_->text().toUTF8()), 
        unitEdit_->text().toUTF8(), purchaseEdit_->text().toUTF8(), 
        expiryEdit_->text().toUTF8(), locationEdit_->text().toUTF8(), std::stoi(alertQtyEdit_->text().toUTF8()));
      
      try{
        
        if(getModel()->addFoodItem(*fi)){
          // Success Message
          std::cout << nameEdit_->text() << " successfully added!" << std::endl;
          auto messageBox = app->addChild(std::make_unique<WMessageBox>(
            "Success!", WString("{1} successfully added!").arg(nameEdit_->text()), 
            Icon::Information, StandardButton::Ok));

          messageBox->buttonClicked().connect([=]{
            app->removeChild(messageBox);
          });
          messageBox->show();
        }
        else{
          throw "Item could not be added";
        } 

      } catch(const char* msg){
        //THROW POP UP BOX
        auto messageBox = app->addChild(std::make_unique<WMessageBox>(
        "Error!", WString(msg), Icon::Warning, StandardButton::Ok));
        
        messageBox->buttonClicked().connect([=]{
          app->removeChild(messageBox);
        });
        messageBox->show();
      }

    };
    addItemBtn->clicked().connect(addItem);

    addStockCont->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));
    addPanel->setCentralWidget(std::unique_ptr<WContainerWidget>(addStockCont));

    return container;
}

/**
 * Delete Stock Item
*/
WContainerWidget* WebView::deleteStockItem(){

    auto container = new WContainerWidget();
    auto deleteStockCont = new WContainerWidget();

    // Create panel for Recipe buttons to be added in
    auto deletePanel = container->addWidget(std::make_unique<WPanel>());
    deletePanel->addStyleClass("centered-example");
    deletePanel->setTitle("DELETE ITEM FROM STOCK");
    deletePanel->setWidth(WLength(100,LengthUnit::Percentage));

    // Item Name
    auto nameContainer = deleteStockCont->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());
    nameContainer->setId("nameContainer");

    // Delete Stock Pushbutton
    Wt::WPushButton *deleteItemBtn = deleteStockCont->addWidget(std::make_unique<Wt::WPushButton>("Delete Item"));
    deleteStockCont->addWidget(std::make_unique<Wt::WBreak>());
    deleteStockCont->addWidget(std::make_unique<Wt::WBreak>());
    
    // Delete the item from the model
    auto deleteItem = [this]{
      try{
        if(getModel()->removeFoodItem(nameEdit_->text().toUTF8())){
          
          // Success Message
          std::cout << nameEdit_->text() << " successfully deleted!" << std::endl;
          auto messageBox = app->addChild(std::make_unique<WMessageBox>(
            "Success!", WString("{1} successfully deleted.").arg(nameEdit_->text()), 
            Icon::Information, StandardButton::Ok));

          messageBox->buttonClicked().connect([=]{
            app->removeChild(messageBox);
          });
          messageBox->show();
        }
        else{
          throw "Item could not be deleted";
        }        
      } catch (const char* msg) {         
        auto messageBox = app->addChild(std::make_unique<WMessageBox>(
        "Error!", WString(msg), Icon::Warning, StandardButton::Ok));
        
        messageBox->buttonClicked().connect([=]{
          app->removeChild(messageBox);
        });
        messageBox->show();
      }
    };

    deleteItemBtn->clicked().connect(deleteItem);

    deleteStockCont->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));
    deletePanel->setCentralWidget(std::unique_ptr<WContainerWidget>(deleteStockCont));

    return container;
}


/**
 * Modify Stock Item
*/
WContainerWidget* WebView::modifyStockItem(){

    auto container = new WContainerWidget();
    auto modStockCont = new WContainerWidget();
    
    // Create panel for input fields to be added in
    auto modPanel = container->addWidget(std::make_unique<WPanel>());
    modPanel->addStyleClass("centered-example");
    modPanel->setTitle("MODIFY STOCK ITEM");
    modPanel->setWidth(WLength(100,LengthUnit::Percentage));

    // Item Name
    auto nameContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    nameContainer->addWidget(std::make_unique<Wt::WText>("Item Name"));
    nameEdit_ = nameContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    nameContainer->addWidget(std::make_unique<Wt::WBreak>());
    nameContainer->setId("nameContainer");
    // nameContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Mesurement Unit Entry
    auto unitContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    unitContainer->addWidget(std::make_unique<Wt::WText>("Measurement Unit"));
    unitEdit_ = unitContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    unitContainer->addWidget(std::make_unique<Wt::WBreak>());
    unitContainer->setId("unitContainer");

    // Quantity Entry
    auto qtyContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    qtyContainer->addWidget(std::make_unique<Wt::WText>("Quantity"));
    qtyEdit_ = qtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    qtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    qtyContainer->setId("qtyContainer");

    // Date Purchased Entry
    auto purchaseContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    purchaseContainer->addWidget(std::make_unique<Wt::WText>("Purchase Date (YYYY/MM/DD)"));
    purchaseEdit_ = purchaseContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    purchaseContainer->addWidget(std::make_unique<Wt::WBreak>());
    purchaseContainer->setId("purchaseContainer");

    // Expiry Date Entry
    auto expiryContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    expiryContainer->addWidget(std::make_unique<Wt::WText>("Expiration Date (YYYY/MM/DD)"));
    expiryEdit_ = expiryContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    expiryContainer->addWidget(std::make_unique<Wt::WBreak>());
    expiryContainer->setId("expiryContainer");
    // expiryContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Storage Location Entry
    auto locationContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    locationContainer->addWidget(std::make_unique<Wt::WText>("Storage Location"));
    locationEdit_ = locationContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    locationContainer->addWidget(std::make_unique<Wt::WBreak>());
    locationContainer->setId("locationContainer");
    // locationContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Stock Low Alert Quantity Entry
    auto alertQtyContainer = modStockCont->addWidget(std::make_unique<WContainerWidget>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WText>("Low Qty Threshold"));
    alertQtyEdit_ = alertQtyContainer->addWidget(std::make_unique<Wt::WLineEdit>());
    alertQtyContainer->addWidget(std::make_unique<Wt::WBreak>());
    alertQtyContainer->setId("locationContainer");
    // alertQtyContainer->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));

    // Add to Stock Pushbutton
    Wt::WPushButton *modItemBtn = modStockCont->addWidget(std::make_unique<Wt::WPushButton>("Modify Item"));
    modStockCont->addWidget(std::make_unique<Wt::WBreak>());
    modStockCont->addWidget(std::make_unique<Wt::WBreak>());
    
    // Populate the text fields
    auto populateFields = [this]{
      FoodItem fi = getModel()->querySingleFoodItem(nameEdit_->text().toUTF8());
      try{
        
        // If invalid entry throw exception
        if(fi.getName()==""){
          throw std::exception();
        }

        nameEdit_->setText(fi.getName());
        unitEdit_->setText(fi.getMeasureUnit());
        qtyEdit_->setText(std::to_string(fi.getQuantity()));
        purchaseEdit_->setText(fi.getDatePurchased());
        expiryEdit_->setText(fi.getExpiry());
        locationEdit_->setText(fi.getType());
        alertQtyEdit_->setText(std::to_string(fi.getThreshold()));

      } catch (...) {
        //THROW POP UP BOX
        auto messageBox = app->addChild(std::make_unique<WMessageBox>(
          "Error!", WString("Item doesn't exist"), Icon::Warning, StandardButton::Ok));
        
        messageBox->buttonClicked().connect([=]{
          app->removeChild(messageBox);
        });
        messageBox->show();
        
        // Clear entries
        nameEdit_->setText("");
        unitEdit_->setText("");
        qtyEdit_->setText("");
        purchaseEdit_->setText("");
        expiryEdit_->setText("");
        locationEdit_->setText("");
        alertQtyEdit_->setText("");
      }

    };
    nameEdit_->changed().connect(populateFields);

    // Build the FoodItem and connect the Add stock button
    auto modItem = [this]{
      FoodItem *fi = new FoodItem(nameEdit_->text().toUTF8(), std::stoi(qtyEdit_->text().toUTF8()), 
        unitEdit_->text().toUTF8(), purchaseEdit_->text().toUTF8(), 
        expiryEdit_->text().toUTF8(), locationEdit_->text().toUTF8(), std::stoi(alertQtyEdit_->text().toUTF8()));
      
      try{
        bool result = false;
        result = getModel()->modifyFoodItem(*fi);
        if(!result){
          throw "Food Item could not be modified.";
        }
        std::cout<<"\nITEM MODIFIED IN STOCK\n";
      } 
      catch(const char* msg){
        //THROW POP UP BOX
        auto messageBox = app->addChild(std::make_unique<WMessageBox>(
          "Error!", WString(msg), Icon::Warning, StandardButton::Ok));
        
        messageBox->buttonClicked().connect([=]{
          app->removeChild(messageBox);
        });
        messageBox->show();
      }
      delete fi;
    };
    modItemBtn->clicked().connect(modItem);

    modStockCont->setWidth(WLength(INPUT_WIDTH_PERCENT,WLength::Unit::Percentage));
    modPanel->setCentralWidget(std::unique_ptr<WContainerWidget>(modStockCont));

    return container;
}

/**
 * Handle an internal path change
*/
void WebView::handleInternalPathChange()
{
    WApplication *app = Wt::WApplication::instance();
    
    content()->clear();

    if (app->internalPath() == addItemPath){
      std::cerr<<"\nPATH CHANGED - ADD ITEM\n";
      content()->addWidget(std::unique_ptr<WContainerWidget>(addStockItem()));
    }
    else if (app->internalPath() == deleteItemPath){
      std::cerr<<"\nPATH CHANGED - DELETE ITEM\n";
      content()->addWidget(std::unique_ptr<WContainerWidget>(deleteStockItem()));
    }
    else if (app->internalPath() == modItemPath){
      std::cerr<<"\nPATH CHANGED - MODIFY ITEM\n";
      content()->addWidget(std::unique_ptr<WContainerWidget>(modifyStockItem()));
    }
    else if (app->internalPath() == findItemPath){
      std::cerr<<"\nPATH CHANGED - FIND ITEM\n";
      //delete content_;
      //content_= modifyStockItem();
    }    
    else
      std::cerr<<"\nPATH CHANGED - HOME\n";
      //delete content_;
      //content_ = new WContainerWidget();

}

Model* WebView::getModel(){
  return model;
}

void WebView::setModel(Model *model){
  this->model = model;
}

void WebView::display(){

}

/**
 * Launch Application
*/
static int launch(int argc, char**argv){
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
      return std::make_unique<WebView>(env);
    });    
}

/*
int main(int argc, char **argv)
{
    launch(argc, argv);
}
*/

