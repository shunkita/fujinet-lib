#include <stdint.h>
#include "fujinet-fuji.h"
#include "fujinet-bus-apple2.h"

bool fuji_mount_all(void)
{
	if (sp_get_fuji_id() == 0) {
		return false;
	}

	sp_payload[0] = 0x00;
	sp_payload[1] = 0x00;

	sp_error = sp_control(sp_fuji_id, 0xD7);
	return sp_error == 0;
}
