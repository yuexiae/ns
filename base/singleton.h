#ifndef BASE_SINGLETON_HPP_
#define BASE_SINGLETON_HPP_

#include "base/micros.h"
#include <windows.h>

namespace base {


template <class T>
class Singleton
{
public:
	static T* GetSingleton() {
		if (instance_ == NULL) {
			if (!::InterlockedExchange(&create_mark_, 1)) {
				instance_ = new T();
			} else {
				while (instance_ == NULL) {
					Sleep(0);
				}
			}
		}

		return instance_;
	}

	static void DestorySingleton() {
		delete instance_;
	}


protected:
	Singleton() {}

	~Singleton() {}

private:
	DISALLOW_COPY_AND_ASSIGN(Singleton);

	static T *instance_;
	static volatile long create_mark_;
};


template <typename T> T *Singleton<T>::instance_ = NULL;

template <typename T> volatile long Singleton<T>::create_mark_ = 0;

}




#endif