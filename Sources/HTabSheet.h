/*	$Id$

	Copyright 1996, 1997, 1998, 2002
	        Hekkelman Programmatuur B.V.  All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	1. Redistributions of source code must retain the above copyright notice,
	   this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.
	3. All advertising materials mentioning features or use of this software
	   must display the following acknowledgement:

	    This product includes software developed by Hekkelman Programmatuur B.V.

	4. The name of Hekkelman Programmatuur B.V. may not be used to endorse or
	   promote products derived from this software without specific prior
	   written permission.

	THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
	AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
	OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
	OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Created: 02-06-02
*/

#ifndef HTABSHEET_H
#define HTABSHEET_H

#include "HLibHekkel.h"

IMPEXP_LIBHEKKEL const uint32 msg_Flip = 'flip';

class IMPEXP_LIBHEKKEL HTabSheet : public BView {
public:
		HTabSheet(BRect frame, const char *name);
		~HTabSheet();

virtual void MouseDown(BPoint where);
virtual void Draw(BRect update);

		void MessageReceived(BMessage *msg);
		void AttachedToWindow();

		BPoint AdjustBottomRightOfAllPanes();

		BRect ClientArea();

		BView* AddSheet(const char *name, const char *desc = NULL);

		int CurrentTab()	{ return fCurrent; };
private:

		void FlipTo(int page);
		BPoint DetermineBottomRightOfPane(BView* pane);

		BRect fClientArea, fListArea;
		BList fPanes;
		BList fDescs;
		BListView *fEntries;
		int fCurrent;
};

#endif // HTABSHEET_H
