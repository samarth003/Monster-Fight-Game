#include <gtest/gtest.h>
#include<gmock/gmock.h>

#include<sstream>

#include "RenderingGame.h"

class RenderGame : public ::testing::Test
{
protected:
    int m_dimWidth = 800;
    int m_dimHeight = 600;
    std::string m_gameName = "BattleOut";
    sf::Texture imageTest;

    RenderGame()
    {

    }
};

//test throw error for no window name
TEST_F(RenderGame, RenderGame_WindowName_Test)
{
    m_gameName = "";
    EXPECT_THROW(CreateGameWindow(m_dimWidth, m_dimHeight, m_gameName), std::runtime_error);
}

//test no window width throw error
TEST_F(RenderGame, RenderGame_NoWindowWidth_Test)
{
    m_dimWidth = 0;
    EXPECT_THROW(CreateGameWindow(m_dimWidth, m_dimHeight, m_gameName), std::runtime_error);
}

//test no window height throw error
TEST_F(RenderGame, RenderGame_NoWindowHeight_Test)
{
    m_dimHeight = 0;
    EXPECT_THROW(CreateGameWindow(m_dimWidth, m_dimHeight, m_gameName), std::runtime_error);
}

//test if window is created successfully
TEST_F(RenderGame, RenderGame_CreateWindow_Test)
{
    sf::RenderWindow window = CreateGameWindow(m_dimWidth, m_dimHeight, m_gameName);
    EXPECT_EQ(window.getSize().x, m_dimWidth);
    EXPECT_EQ(window.getSize().y, m_dimHeight);
}

//test to check if background image is loaded successfully
TEST_F(RenderGame, RenderGame_CheckBackGndImage_Test)
{
    EXPECT_TRUE(LoadBackgndImage(imageTest));
}

//test if image dimensions are scaled properly
TEST_F(RenderGame, RenderGame_CheckScalingDimension_Test)
{
    sf::RenderWindow window = CreateGameWindow(m_dimWidth, m_dimHeight, m_gameName);
    EXPECT_TRUE(LoadBackgndImage(imageTest));
    
    sf::Vector2f testDims = GetScaledBackgndImage(window, imageTest);
    
    EXPECT_FLOAT_EQ((testDims.x * imageTest.getSize().x), window.getSize().x);
    EXPECT_FLOAT_EQ((testDims.y * imageTest.getSize().y), window.getSize().y);
}