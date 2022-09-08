//
// Created by Karol on 04/09/2022.
//

#ifndef INC_2DPHYSIX_EVENT_H
#define INC_2DPHYSIX_EVENT_H

#define BIT(x) (1<<x)

#include "string"
#include "functional"

namespace PX2D{
    enum class EventType
    {
        None = 0,
        WindowClose,WindowResize,WindowFocus,WindowsLostFocus,WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled

    };
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4),
    };

    class Event
    {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const {return GetName();};

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    protected:
        bool m_Handaled = false;


    };
}


#endif //INC_2DPHYSIX_EVENT_H
