/*
 * Copyright (C) 2001-2004 Sistina Software, Inc. All rights reserved.  
 * Copyright (C) 2004 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU General Public License v.2.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "lib.h"
#include "disk-rep.h"

#include <libdevmapper.h>

/*
 * FIXME: Quick hack.  We can use caching to
 * prevent a total re-read, even so vg_number
 * causes the tools to check *every* pv.  Yuck.
 * Put in separate file so it wouldn't contaminate
 * other code.
 */
int get_free_vg_number(struct format_instance *fid, struct dev_filter *filter,
		       const char *candidate_vg, int *result)
{
	struct list all_pvs;
	struct disk_list *dl;
	struct dm_pool *mem = dm_pool_create("lvm1 vg_number", 10 * 1024);
	int numbers[MAX_VG], i, r = 0;

	list_init(&all_pvs);

	if (!mem) {
		stack;
		return 0;
	}

	if (!read_pvs_in_vg(fid->fmt, NULL, filter, mem, &all_pvs)) {
		stack;
		goto out;
	}

	memset(numbers, 0, sizeof(numbers));

	list_iterate_items(dl, struct disk_list, &all_pvs) {
		if (!*dl->pvd.vg_name || !strcmp((char *)dl->pvd.vg_name, candidate_vg))
			continue;

		numbers[dl->vgd.vg_number] = 1;
	}

	for (i = 0; i < MAX_VG; i++) {
		if (!numbers[i]) {
			r = 1;
			*result = i;
			break;
		}
	}

      out:
	dm_pool_destroy(mem);
	return r;
}
