
#include "plugin/sample_plugin.hpp"
#include "plumage/plugin_repository.hpp"
#include "plumage/plugin_manager.hpp"

int main(int argc, char const* argv[])
{
    plumage::PluginManager manager;
    try {
#ifdef MAC_OSX
        manager.loadPlugin("./libsample_plugin.dylib", "createSamplePlugin");
#else
        manager.loadPlugin("./libsample_plugin.so", "createSamplePlugin");
#endif
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    plumage::PluginRepository* repos = manager.getPluginRepository("SamplePlugin", 1, true);
    if(repos == nullptr) {
        return 0;
    }
    try {
        repos->activate(1);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    plumage::PluginInterface* pif = repos->getActivatedPlugin();
    if(pif == nullptr) {
        std::cout << "A-----------------------" << std::endl;
        return 0;
    }
    std::cout << "pif = " << pif << std::endl;
    pif->start();
    std::cout << "-----------------------" << std::endl;
    pif->stop();

    pif->call("testMethod");
    return 0;
}
