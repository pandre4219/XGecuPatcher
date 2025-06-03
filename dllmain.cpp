#include "include.h"



int main(const HMODULE instance) {
    overlay::render();


    FreeLibraryAndExitThread(instance, 0);
    return 0;
}

//Entry Point
BOOL WINAPI DllMain(const HMODULE instance,const std::uintptr_t reason,const void* reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(instance);

        const auto thread = CreateThread(
            nullptr,
            0,
            reinterpret_cast<LPTHREAD_START_ROUTINE>(main),
            instance,
            0,
            nullptr
        );

        if (thread)
            CloseHandle(thread);
    }

    return TRUE;
};