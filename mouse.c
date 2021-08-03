#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Protocol/GraphicsOutput.h>
#include <Protocol/SimplePointer.h>
#include <Protocol/AbsolutePointer.h>


EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE IH, IN EFI_SYSTEM_TABLE *ST){

	EFI_STATUS  status;
	EFI_SIMPLE_POINTER_PROTOCOL* souris = 0;
	EFI_SIMPLE_POINTER_STATE etat;
	EFI_EVENT events[2];

	gST->ConOut->EnableCursor (gST->ConOut, TRUE);
	status = gBS->LocateProtocol(&gEfiSimplePointerProtocolGuid,NULL,(VOID**)&souris);
	
	if (EFI_ERROR(status)){
		Print(L"Erreur dans la recherche du protocole: Simple Pointer Protocol.\n");
		return status;
	}

	status = souris->Reset(souris, TRUE);
	events[0] = souris->WaitForInput;
	events[1] = gST->ConIn->WaitForKey;
	
	while(TRUE){
		EFI_INPUT_KEY touche;
		UINTN index;
		
		status = gBS->WaitForEvent(2, events, &index);
		
		if(index == 0){
		
			status = souris->GetState(souris, &etat);
			Print(L"Xpos:%d\n Ypos:%d\n Lclick:%d\n Rclick:%d\n\n",
					etat.RelativeMovementX,
					etat.RelativeMovementY,
					etat.LeftButton,
					etat.RightButton
			     );
		}else{            
			status = gST->ConIn->ReadKeyStroke (gST->ConIn, &touche);
			Print(L"keycode:%d\n",touche.UnicodeChar);
			if (touche.UnicodeChar == 0 )
				break;
		}
	}
	return EFI_SUCCESS; 
}

