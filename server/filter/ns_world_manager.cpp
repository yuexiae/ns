#include "server/server_pch.h"

#include "server/ext/ns_ext.h"
#include "server/db/game_db.h"


class CNSWorldManagerFilter : public CNSWorldManager {
public:
	BOOL DBFortressLoadFilter() {
		GameUtil::Output("DBFortressLoad");
        return GameDb::GetSingleton()->DBFortressLoad(this);
	}

	void DBFortressSaveFilter(BOOL bRVREnd) {
		GameUtil::Output("DBFortressSave");

		if (bRVREnd) {
			SYSTEMTIME st;
			GetLocalTime(&st);
			this->m_wRVREndDate = st.wDay + 100 * st.wMonth;
		} else if (!this->m_bRVRStart) {
			return;
		}

		GameDb::GetSingleton()->DBFortressSave(this);
	}
};

bool CNSWorldManagerFilterInit() {
	return CNSWorldManager::_PatchDBFortressLoad(&CNSWorldManagerFilter::DBFortressLoadFilter)
		&& CNSWorldManager::_PatchDBFortressSave(&CNSWorldManagerFilter::DBFortressSaveFilter);
}
