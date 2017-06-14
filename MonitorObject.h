//
// Created by szymon on 13.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_MONITOROBJECT_H
#define THREADSMANAGEMENTSYSTEM_MONITOROBJECT_H

#include <string>
#include "Types.h"
#include "NcursesWrapper.h"

namespace SystemMonitoring {

    template<typename T> struct FunctionType
    {
        typedef std::function<T()> Function ;
    } ;


    class MonitorObject {
    protected:
        std::string name;
        TypeComponentNcurses componentNcurses;

        std::function< std::string()> functionMonitorObject;

        ///GETTERS
    public:
        const std::string &getName() const {
            return name;
        }

        const TypeComponentNcurses getComponentNcurses() const {
            return componentNcurses;
        }

         auto functionMonitorObjectF() const {

            return functionMonitorObject();

        }

        const std::string functionMonitorObject_ToString() const {

            return functionMonitorObject();

        }

        void display(size_t & row)const {
            switch (componentNcurses)
            {
                case TypeComponentNcurses ::text_view: SystemMonitoring::NcursesWrapper::TextView(row, 0, name, functionMonitorObject());
                    break;
                case TypeComponentNcurses ::progress_bar: SystemMonitoring::NcursesWrapper::ProgressBar(row, 0,  stod(functionMonitorObject()));
                    break;
            }
            ++row;
        }


        ///CPNSTRUCTORS
        MonitorObject(const std::string &name,
                      TypeComponentNcurses componentNcurses,
                      const std::function< std::string()> &functionMonitorObject)
                :
                name(name),
                componentNcurses(componentNcurses),
                functionMonitorObject(functionMonitorObject) {}


    };

}

#endif //THREADSMANAGEMENTSYSTEM_MONITOROBJECT_H
