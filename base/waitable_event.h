#ifndef BASE_WAIT_EVENT_H_
#define BASE_WAIT_EVENT_H_

#include <windows.h>

namespace base {

class WaitableEvent {
public:
    WaitableEvent(bool manual_reset, bool signaled) 
        : handle_(CreateEvent(NULL, manual_reset, signaled, NULL)) {
    }

    ~WaitableEvent()  {
        CloseHandle(handle_);
    }

    void Reset() {
        ResetEvent(handle_);
    }
    void Signal() {
        SetEvent(handle_);
    }

    void Wait() {
        WaitForSingleObject(handle_, INFINITE);
    }

    bool Wait(unsigned int timeout) {
        DWORD result = WaitForSingleObject(handle_, timeout);
        switch (result) {
        case WAIT_OBJECT_0:
            return true;
        case WAIT_TIMEOUT:
            return false;
        }
        return false;
    }


private:
    HANDLE handle_;
};



} //namespace base {


#endif