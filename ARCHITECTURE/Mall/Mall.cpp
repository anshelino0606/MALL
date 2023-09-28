//
// Created by Anhelina Modenko on 22.09.2023.
//

#include "Mall.h"
#include "ENGINE/glad/glad.h"
#include <GLFW/glfw3.h>

const glm::vec2 PLAYER_SIZE(38.4f, 57.6f);
const float PLAYER_VELOCITY(200.0f);


GameObject *Player;
GameObject *Cursor;
SpriteRenderer* Renderer;
Shop* shop;
ShoppingCart* cart;

enum class TileType;

bool checkCollisions(GameObject &one, GameObject &two)  {
    bool collisionX = one.pos.x + one.size.x >= two.pos.x &&
                      two.pos.x + two.size.x >= one.pos.x;
    bool collisionY = one.pos.y + one.size.y >= two.pos.y &&
                      two.pos.y + two.size.y >= one.pos.y;
    return collisionX && collisionY;
}


void Mall::doCollisions() {
    for (GameObject &box : this->level.tiles) {
        if (checkCollisions(*Player, box)) {
            if (box.isBarrier && !box.isHalfBarrier) {
                float overlapX = std::min(Player->pos.x + Player->size.x - box.pos.x,
                                          box.pos.x + box.size.x - Player->pos.x);
                float overlapY = std::min(Player->pos.y + Player->size.y - box.pos.y,
                                          box.pos.y + box.size.y - Player->pos.y);

                // Determine the side of collision
                bool collisionFromLeft = overlapX < overlapY && (Player->pos.x + Player->size.x > box.pos.x) &&
                                         (Player->pos.x < box.pos.x);
                bool collisionFromRight = overlapX < overlapY && (Player->pos.x < box.pos.x + box.size.x) &&
                                          (Player->pos.x + Player->size.x > box.pos.x + box.size.x);
                bool collisionFromTop = overlapY < overlapX && (Player->pos.y + Player->size.y > box.pos.y) &&
                                        (Player->pos.y < box.pos.y);
                bool collisionFromBottom = overlapY < overlapX && (Player->pos.y < box.pos.y + box.size.y) &&
                                           (Player->pos.y + Player->size.y > box.pos.y + box.size.y);

                // Resolve collision based on the side of collision
                if (collisionFromLeft) {
                    Player->pos.x = box.pos.x - Player->size.x;
                } else if (collisionFromRight) {
                    Player->pos.x = box.pos.x + box.size.x;
                } else if (collisionFromTop) {
                    Player->pos.y = box.pos.y - Player->size.y;
                } else if (collisionFromBottom) {
                    Player->pos.y = box.pos.y + box.size.y;
                }

                // Zero out velocity on the axis of collision
                if (collisionFromLeft || collisionFromRight) {
                    Player->velocity.x = 0.0f;
                }
                if (collisionFromTop || collisionFromBottom) {
                    Player->velocity.y = 0.0f;
                }
            } else if (box.isHalfBarrier && !box.isShop) {
                float overlapX = std::min(Player->pos.x + Player->size.x - box.pos.x,
                                          box.pos.x + box.size.x - Player->pos.x) / 2.0f;
                float overlapY = std::min(Player->pos.y + Player->size.y - box.pos.y,
                                          box.pos.y + box.size.y - Player->pos.y) / 2.0f;

                bool collisionFromLeft = overlapX < overlapY && (Player->pos.x + Player->size.x/2.0f > box.pos.x) &&
                                         (Player->pos.x < box.pos.x);
                bool collisionFromRight = overlapX < overlapY && (Player->pos.x < box.pos.x + box.size.x/2.0f) &&
                                          (Player->pos.x + Player->size.x/2.0f > box.pos.x + box.size.x/2.0f);
                bool collisionFromTop = overlapY < overlapX && (Player->pos.y + Player->size.y/2.0f > box.pos.y) &&
                                        (Player->pos.y < box.pos.y);
                bool collisionFromBottom = overlapY < overlapX && (Player->pos.y < box.pos.y + box.size.y/2.0f) &&
                                           (Player->pos.y + Player->size.y/2.0f > box.pos.y + box.size.y/2.0f);

                if (collisionFromLeft) {
                    Player->pos.x = box.pos.x - Player->size.x/2.0f;
                } else if (collisionFromRight) {
                    Player->pos.x = box.pos.x + box.size.x/2.0f;
                } else if (collisionFromTop) {
                    Player->pos.y = box.pos.y - Player->size.y/2.0f;
                } else if (collisionFromBottom) {
                    Player->pos.y = box.pos.y + box.size.y/2.0f;
                }

                // Zero out velocity on the axis of collision
                if (collisionFromLeft || collisionFromRight) {
                    Player->velocity.x = 0.0f;
                }
                if (collisionFromTop || collisionFromBottom) {
                    Player->velocity.y = 0.0f;
                }

            } else if (box.isShop) {
                this->state = GameStates::GAME_IN_SHOP;
            }
        }
    }
}

Mall::Mall(unsigned int width, unsigned int height)
        : state(GameStates::GAME_ACTIVE), keys(), width(width), height(height), cam(glm::vec2(0.0f, 0.0f), 0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height))
{

}

Mall::~Mall()
{
    delete Player;
    delete Renderer;
    delete shop;
}


void Mall::init()
{
    this->state = GameStates::GAME_ACTIVE;
    ResourceManager::loadShader("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Shaders/sprite.vert", "/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Shaders/sprite.frag", nullptr, "sprite");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width),
                                      static_cast<float>(this->height), 0.0f, -1.0f, 1.0f);

    ResourceManager::getShader("sprite").activate();
    ResourceManager::getShader("sprite").setInt("image", 0);
    ResourceManager::getShader("sprite").setMat4("projection", projection);
    Shader myShader;
    myShader = ResourceManager::getShader("sprite");
    Renderer = new SpriteRenderer(myShader);

    shop = nullptr;
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Images/map.png", true, "map");
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Images/pier.png", true, "player");
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Images/transparent.png", true, "blank");
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Images/Box.png", true, "box");
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Images/shop.png", true, "shop");
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Images/cart.png.png", true, "cart");
    ResourceManager::loadTexture("/Users/anhelinamodenko/CLionProjects/SmartShoppingCart/Game/Assets/Tiles/cursor.png", true, "cursor");

    GameLevel level1;
    level1.load("/Users/anhelinamodenko/CLionProjects/MALL/ADDONS/Maps/walls_walls.csv", this->width, this->height);
    this->level = level1;

    shop = new Shop(this->width, this->height, ResourceManager::getTexture("shop"), "shop1", 10000);

    glm::vec2 playerPos = glm::vec2(this->width / 2 - PLAYER_SIZE.x / 2,
                                    this->height / 2 - PLAYER_SIZE.y);
    glm::vec2 mousePos = glm::vec2(this->width / 2 ,this->height / 2);
    Player = new GameObject(playerPos, PLAYER_SIZE, ResourceManager::getTexture("player"));
    Cursor = new GameObject(mousePos, PLAYER_SIZE, ResourceManager::getTexture("cursor"));


}

void Mall::update(float dt)
{
    if (this->state == GameStates::GAME_ACTIVE) {
        this->doCollisions();
    } else if (this->state == GameStates::GAME_IN_SHOP) {
//         Render the shop content
        // init items array


        shop->update(dt);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        shop->doCollisions();
    } else if (this->state == GameStates::GAME_IN_CART) {
        if (shop) {
            shop->printAllItems();
            cart->update(dt);

            std::vector<Item> cartItems = cart->getItemsVec();

            std::sort(cartItems.begin(), cartItems.end(), [](const Item& a, const Item& b) {
                // Sort items in descending order of height
                return a.getHeight() > b.getWidth();
            });

            if (!shop) {
                shop = new Shop(this->width, this->height, ResourceManager::getTexture("shop"), "shop1" , 10000 ,shop->getItems());
            }
            float currentX = 100.0f;
            float itemSpacing = 0.0f;

            for (Item& obj : cartItems) {
                obj.pos = glm::vec2(currentX, 100.0f);
                currentX += obj.width + itemSpacing;
            }
        }
    }
}

void Mall::processInput(float dt) {
    if (this->state == GameStates::GAME_ACTIVE) {
        float velocity = PLAYER_VELOCITY * dt;
        // move playerboard
        if (Keyboard::key(GLFW_KEY_A)) {
            if (Player->pos.x >= 0.0f)
                Player->pos.x -= velocity;
        }
        if (Keyboard::key(GLFW_KEY_D)) {
            if (Player->pos.x <= this->width - Player->size.x)
                Player->pos.x += velocity;
        }
        if (Keyboard::key(GLFW_KEY_W)) {
            if (Player->pos.y >= 0.0f)
                Player->pos.y -= velocity;
        }
        if (Keyboard::key(GLFW_KEY_S)) {
            if (Player->pos.y <= this->height - Player->size.y)
                Player->pos.y += velocity;
        }
        if (Keyboard::keyWentDown(GLFW_KEY_SPACE) ) {
            this->state = GameStates::GAME_IN_SHOP;
        }
        if (Keyboard::keyWentDown(GLFW_KEY_C) ) {
            this->state = GameStates::GAME_IN_CART;
        }
        if (Keyboard::keyWentDown(GLFW_KEY_P) ) {
            shop->printAllItems();
        }
    } else if (this->state == GameStates::GAME_IN_SHOP) {
        if (Keyboard::keyWentDown(GLFW_KEY_SPACE)) {
            this->state = GameStates::GAME_ACTIVE;
        }
        if (Keyboard::keyWentDown(GLFW_KEY_P)) {
            shop->printAllItems(); // Print items when in the cart state
        }
        // mouse position
        // -------------
        double x = Mouse::getMouseX();
        double y = Mouse::getMouseY();
        Cursor->pos.x = x;
        Cursor->pos.y = y;

    } else if (this->state == GameStates::GAME_IN_CART) {
        if (Keyboard::keyWentDown(GLFW_KEY_C)) {
            this->state = GameStates::GAME_ACTIVE;
        }
        if (Keyboard::keyWentDown(GLFW_KEY_P)) {
            shop->printAllItems(); // Print items when in the cart state
        }

        // mouse position
        // -------------
        double x = Mouse::getMouseX();
        double y = Mouse::getMouseY();
        Cursor->pos.x = x;
        Cursor->pos.y = y;


    }
}

void Mall::render() {

    Renderer->DrawSprite(ResourceManager::getTexture("map"),
                         glm::vec2(0.0f, 0.0f),
                         glm::vec2(this->width, this->height),
                         0.0f);
    this->level.draw(*Renderer);
    Player->Draw(*Renderer);

    if (this->state == GameStates::GAME_IN_SHOP && shop) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        shop->render();

        Renderer->DrawSprite(ResourceManager::getTexture("shop"),
                             glm::vec2(70.0f, 70.0f),
                             glm::vec2(640.0f, 640.0f),
                             0.0f);
        Cursor->Draw(*Renderer);
    }
    if (this->state == GameStates::GAME_IN_CART) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        cart->render();

        std::vector<Item> cartItems;
        // push back items from Item*
        for (int i = 0; i < shop->getCurrentCapacity(); i++) {
            cartItems.push_back(shop->getItems()[i]);
        }
        std::sort(cartItems.begin(), cartItems.end(), [](const Item& a, const Item& b) {
            // Sort items in descending order of height
            return a.getHeight() > b.getWidth();
        });

        const float itemSpacing = 0.0f;
        const float maxRowWidth = 600.0f;
        float currentRowWidth = 0.0f;

        glm::vec2 itemPosition = glm::vec2(100.0f);

        Renderer->DrawSprite(ResourceManager::getTexture("cart"),
                             glm::vec2(70.0f, 70.0f),
                             glm::vec2(640.0f, 640.0f),
                             0.0f
        );

        for (const Item& obj : cartItems) {
            glm::vec2 itemSize = glm::vec2(obj.getWidth(), obj.getHeight());

            if (currentRowWidth + itemSize.x > maxRowWidth) {
                itemPosition.x = 100.0f;
                itemPosition.y += itemSize.y + itemSpacing;
                currentRowWidth = 0.0f;
            }

            Renderer->DrawSprite(ResourceManager::getTexture("box"),
                                 itemPosition,
                                 itemSize,
                                 0.0f
            );
            itemPosition.x += (itemSize.x + itemSpacing);
            currentRowWidth += (obj.getWidth() + itemSpacing);
        }



        Cursor->Draw(*Renderer);
    }

}