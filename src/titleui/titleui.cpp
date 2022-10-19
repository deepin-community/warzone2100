/*
	This file is part of Warzone 2100.
	Copyright (C) 1999-2004  Eidos Interactive
	Copyright (C) 2005-2020  Warzone 2100 Project

	Warzone 2100 is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	Warzone 2100 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Warzone 2100; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/
/*
 * titleui/titleui.cpp
 *
 * WzTitleUI common stuff
 */

#include "titleui.h"
#include "../intdisplay.h"
#include "../hci.h"

std::shared_ptr<WzTitleUI> wzTitleUICurrent;
char serverName[128];

WzTitleUI::~WzTitleUI()
{
}

void WzTitleUI::screenSizeDidChange(unsigned int oldWidth, unsigned int oldHeight, unsigned int newWidth, unsigned int newHeight)
{
}

void changeTitleUI(std::shared_ptr<WzTitleUI> target)
{
	wzTitleUICurrent = target;
	if (psWScreen)
	{
		// Deletes the backdrop, which in turn deletes the rest of the UI from whatever was on screen before this UI
		widgDelete(psWScreen, FRONTEND_BACKDROP);
	}
	if (target)
	{
		target->start();
	}
}