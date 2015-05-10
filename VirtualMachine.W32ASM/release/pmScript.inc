
LoadScript			PROCDESC	STDCALL ptrPortableBinary:DWORD, lenPortableBinary:DWORD, ptrAPICallback:DWORD
LoadScriptFromFile		PROCDESC	STDCALL ptrFilename:DWORD, ptrAPICallback:DWORD
CreateVirtualMachine		PROCDESC	STDCALL ptrCodeBlock:DWORD, lenCodeBlock:DWORD, lenStack:DWORD, intStartIP:DWORD, ptrAPICallback:DWORD
RunScript			PROCDESC	STDCALL hndMachine:DWORD
TakeStep			PROCDESC	STDCALL hndMachine:DWORD
ResetVirtualMachine		PROCDESC	STDCALL hndMachine:DWORD
PushVMStack			PROCDESC	STDCALL hndMachine:DWORD, pushValue:DWORD
PopVMStack			PROCDESC	STDCALL hndMachine:DWORD