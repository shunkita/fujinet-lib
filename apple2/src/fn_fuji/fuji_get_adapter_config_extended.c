#include <stdint.h>
#include <string.h>

#include "fujinet-fuji.h"
#include "fujinet-bus-apple2.h"

bool fuji_get_adapter_config_extended(AdapterConfigExtended *acx)
{
	if (sp_get_fuji_id() == 0) {
		return false;
	}

	sp_error = sp_status(sp_fuji_id, 0xC4);
	if (sp_error == 0) {
		memcpy(acx, &sp_payload[0], sizeof(AdapterConfigExtended));
	}
	return sp_error == 0;
}
