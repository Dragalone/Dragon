#ifndef TEST_INPUTHANDLER_H
#define TEST_INPUTHANDLER_H
#include <vector>
#include "SDL.h"
#include "Vector2D.h"
#include <utility>
enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    void update();
    void clean();


    bool getMouseButtonState(int buttonNumber)
    {
        return m_mouseButtonStates[buttonNumber];
    }

    Vector2D* getMousePosition()
    {
        return m_mousePosition;
    }

    bool isKeyDown(SDL_Scancode key);
    bool isKeyUp(SDL_Scancode key);
private:
    InputHandler();
    ~InputHandler() {delete m_mousePosition;}
    static InputHandler* s_pInstance;
    bool m_mouseButtonStates[3];
    Vector2D* m_mousePosition;
    // KEYBORD???
     const Uint8* m_keystates;
    // KEYBORD???
// handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

    // handle keyboard events
    void onKeyDown();
    void onKeyUp();
};

#endif //TEST_INPUTHANDLER_H
