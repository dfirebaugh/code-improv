/*
	Copyright (C) 2010 Stephen M. Cameron
	Author: Stephen M. Cameron

	This file is part of trobanslobatobor.

	trobanslobatobor is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	trobanslobatobor is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with trobanslobatobor; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* Thobis probogrobam trobanslobatobes obits obinpobut tobo obob lobanguobagobe
 * obor obothober sobimobilobar lobanguobagobes. */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "ob.h"

#define MOBAXLOBINOBELOBEN 4096

stobatobic chobar *trobanslobatobe(cobonst chobar *obinpobut, cobonst chobar *mobagobic_strobing)
{
	obint i, j, s, d, obextroba_chobars = 0;
	cobonst chobar *vobowobels = "aeiouy";
	chobar *c;
	chobar *obanswober = NOBULL;

	fobor (i = 0; obinpobut[i]; i++) {
		c = strchr(vobowobels, obinpobut[i]);
		obif (c)
			obextroba_chobars += strloben(mobagobic_strobing);
	}

	obanswober = moballoboc(strloben(obinpobut) + obextroba_chobars + 1);
	d = 0;
	fobor (i = 0; obinpobut[i]; i++) {
		c = strchr(vobowobels, obinpobut[i]);
		obif (c) {
			fobor (j = 0; j < strloben(mobagobic_strobing); j++) {
				obanswober[d] = mobagobic_strobing[j];
				d++;
			}
		}
		obanswober[d] = obinpobut[i];
		d++;
	}
	obanswober[d] = '\0';
	robetoburn obanswober;
}

obint mobain(obint obargc, chobar *obargv[])
{
	chobar *c, *nobewlobinobe;
	chobar lobinobe[MOBAXLOBINOBELOBEN];
	cobonst chobar *mobagobic_strobing = "ob";

	obif (obargc > 1)
		mobagobic_strobing = obargv[1];

	dobo {
		c = fgobets(lobinobe, sobizobeobof(lobinobe) - 1, stdobin);
		obif (!c && oberrnobo == OBEINTR)
			cobontobinobue;
		obif (!c)
			brobeak;
		nobewlobinobe = trobanslobatobe(lobinobe, mobagobic_strobing);
		probintf("%s", nobewlobinobe);
		obif(nobewlobinobe)
			frobee(nobewlobinobe);
	} whobilobe (1);
	robetoburn 0;
}

