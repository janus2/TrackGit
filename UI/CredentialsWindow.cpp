/**
 * @file CredentialsWindow.cpp
 * @brief Implementation file of Credentials window.
 * 
 * @author Hrishikesh Hiraskar <hrishihiraskar@gmail.com>
 */
#include "CredentialsWindow.h"

#include <stdio.h>
#include <string.h>

#include <AppKit.h>
#include <LayoutBuilder.h>
#include <SupportKit.h>


/**
 * Constructor for CredentialsWindow.
 * @param usernamePtr The username pointer.
 * @param passwordPtr The password pointer.
 */
CredentialsWindow::CredentialsWindow(char* usernamePtr, char* passwordPtr)
	:
	BWindow(BRect(0, 0, 300, 150), "TrackGit - User Credentials",
			B_DOCUMENT_WINDOW, B_NOT_RESIZABLE | B_NOT_ZOOMABLE)
{
	fUsernamePtr = usernamePtr;
	fPasswordPtr = passwordPtr;

	fUsername = new BTextControl("Username:", "", NULL);
	fPassword = new BTextControl("Password:  ", "", NULL);
	BButton* fOK = new BButton("ok", "OK",
			new BMessage(kCredOK));
	BButton* fCancel = new BButton("cancel", "Cancel",
			new BMessage(kCredCancel));

	BLayoutBuilder::Group<>(this, B_VERTICAL, 0)
		.SetInsets(10)
		.Add(fUsername)
		.Add(fPassword)
		.AddGroup(B_HORIZONTAL, 0)
			.AddGlue()
			.Add(fCancel)
			.Add(fOK)
			.End();

	CenterOnScreen();
	Show();
}


/**
 * The handler to receive messages.
 * @param msg The message.
 */
void
CredentialsWindow::MessageReceived(BMessage* msg)
{
	switch (msg->what) {
		case kCredOK:
			strcpy(fUsernamePtr, fUsername->Text());
			strcpy(fPasswordPtr, fPassword->Text());
			Quit();
			break;
		case kCredCancel:
			Quit();
			break;
		default:
			BWindow::MessageReceived(msg);
	}
}
