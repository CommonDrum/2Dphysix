//
// Created by Karol on 08/09/2022.
//

#ifndef INC_2DPHYSIX_KEYEVENT_H
#define INC_2DPHYSIX_KEYEVENT_H

#include "Event.h"

namespace PX2D
{
    /// This is a blueprint class it will not be used in the actual app
    /// Constructor is private so only deriving classes can use it
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const {return m_KeyCode;}

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(int keycode)
            : m_KeyCode(keycode){}

            int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount )
        : KeyEvent( keycode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const {return m_RepeatCount;}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " Repeated:" << m_RepeatCount;
            return ss.str();
        };
    private:
        int m_RepeatCount; // When button is hold down record how many times to repeat

    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent( int keycode)
                : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}



#endif //INC_2DPHYSIX_KEYEVENT_H
