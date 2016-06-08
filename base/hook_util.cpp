#include "base/hook_util.h"
#include <memory.h>
#include <windows.h>
#include "base/logging.h"
#include "third-party/tcmalloc/src/windows/preamble_patcher.h"

#define GET_RELATIVE_ADDR(op, dest) (unsigned long)((unsigned long)dest - (unsigned long)op - 5)

namespace base {

namespace internal {

class PatchVirtualProtect {
public:
	PatchVirtualProtect(unsigned int address, unsigned int len)
		: address_(address), len_(len) {
		VirtualProtect((void *)address_, len_, PAGE_EXECUTE_READWRITE, &flag_);
	}

	~PatchVirtualProtect() {
		VirtualProtect((void *)address_, len_, flag_, &flag_);
	}

private:
	unsigned long address_;
	unsigned long len_;
	unsigned long flag_;
};


}


void HookUtil::PatchBytes(unsigned int address, unsigned char ch, unsigned int len) {
	internal::PatchVirtualProtect protect(address, len);
	memset((void *)address, ch, len);
}


void HookUtil::PatchBytes(unsigned int address, void *data, unsigned int len) {
	internal::PatchVirtualProtect protect(address, len);
	memcpy((void *)address, data, len);
}

void HookUtil::PatchUChar(unsigned int address, unsigned char data) {
	internal::PatchVirtualProtect protect(address, sizeof(unsigned char));
	memcpy((void *)address, &data, sizeof(unsigned char));
}

void HookUtil::PatchUShort(unsigned int address, unsigned short data) {
	internal::PatchVirtualProtect protect(address, sizeof(unsigned short));
	memcpy((void *)address, &data, sizeof(unsigned short));
}

void HookUtil::PatchULong(unsigned int address, unsigned long data) {
	internal::PatchVirtualProtect protect(address, sizeof(unsigned long));
	memcpy((void *)address, &data, sizeof(unsigned long));
}


bool HookUtil::PatchFunctionImpl(unsigned char *address, void *filter_address, void *new_address) {
	if (sidestep::PreamblePatcher::RawPatch(address, filter_address, (void **)new_address) != sidestep::SIDESTEP_SUCCESS) {
		return false;
	}

	return true;
}



}//namespace base {
