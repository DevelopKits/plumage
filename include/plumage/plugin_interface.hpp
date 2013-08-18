
#ifndef PLUMAGE_PLUGIN_INTERFACE_H
#define PLUMAGE_PLUGIN_INTERFACE_H

#include <string>
#include <vector>
#include <exception>
#include <map>

#include <boost/any.hpp>

namespace plumage {

    class PluginEntity;

    class PluginInterface {
        friend class PluginEntity;
        ~PluginInterface() {
        }
    public:
        PluginInterface(PluginEntity* entity) : entity_(entity) {
        }

        std::string getPluginName() const;
        int getPluginVersion() const ;
        int getInterfaceVersion() const ;

        bool start();
        bool stop();
        bool isDebug() const ;
        bool isCompatible(int pluginVersion) const ;
        bool isCallable(const std::string& methodName) const ;

        void* call(const std::string& methodName, boost::any& parameter = nullObj) throw(std::exception) ;

    private:
        static boost::any nullObj;
        PluginEntity* entity_;
    };

}

#endif /* end of include guard */
