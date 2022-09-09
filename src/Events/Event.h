//
// Created by Karol on 04/09/2022.
// This Event system is copied form YouTube series:
// https://www.youtube.com/watch?v=xnopUoZbMEk&t=910s
// For now I added minor changes

#ifndef INC_2DPHYSIX_EVENT_H
#define INC_2DPHYSIX_EVENT_H

#define BIT(x) (1<<x)

#include "string"
#include "functional"
#include "sstream"
#include "spdlog/spdlog.h"


/// TODO:
/// -Change ToString function to function that returns spdlog


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

    /// Macros to use in specific implementations of events to avoid code repetition
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


    class Event
    {
        friend class EventDispatcher;
    public:
        bool Handled = false;
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;

        virtual std::string ToString() const {return GetName();}; // For debug purposes

        // inline keyword helps compiler save time with small functions
        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event)
                : m_Event(event)
        {
        }

        // F will be deduced by the compiler
        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}


#endif //INC_2DPHYSIX_EVENT_H
