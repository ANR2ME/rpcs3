#include "stdafx.h"
#include "Emu/Cell/PPUModule.h"
#include "cellSysutil.h"
#include "cellOskDialog.h"

logs::channel cellOskDialog("cellOskDialog", logs::level::notice);

s32 cellOskDialogLoadAsync(u32 container, vm::ptr<CellOskDialogParam> dialogParam, vm::ptr<CellOskDialogInputFieldInfo> inputFieldInfo)
{
	cellOskDialog.warning("cellOskDialogLoadAsync(container=0x%x, dialogParam=*0x%x, inputFieldInfo=*0x%x)", container, dialogParam, inputFieldInfo);
	sysutil_send_system_cmd(CELL_SYSUTIL_OSKDIALOG_FINISHED, 0); //Immediately signal that input is finished. TODO: Get actual input.
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogUnloadAsync(vm::ptr<CellOskDialogCallbackReturnParam> OutputInfo)
{
	cellOskDialog.warning("cellOskDialogUnloadAsync(OutputInfo=*0x%x)", OutputInfo);
	OutputInfo->result = CELL_OSKDIALOG_INPUT_FIELD_RESULT_OK;

	be_t<u16> input[6] = { 'r', 'p', 'c', 's', '3', 0x0 }; //TODO: Get actual input instead.
	std::memcpy(OutputInfo->pResultString.get_ptr(), input, sizeof(input));

	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogGetSize(vm::ptr<u16> width, vm::ptr<u16> height, vm::ptr<CellOskDialogType> dialogType)
{
	cellOskDialog.warning("cellOskDialogGetSize(width=*0x%x, height=*0x%x, dialogType=*0x%x)", width, height, dialogType);
	*width = 1;
	*height = 1;
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogAbort()
{
	cellOskDialog.todo("cellOskDialogAbort()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogSetDeviceMask(u32 deviceMask)
{
	cellOskDialog.todo("cellOskDialogSetDeviceMask(deviceMask=0x%x)", deviceMask);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogSetSeparateWindowOption(vm::ptr<CellOskDialogSeparateWindowOption> windowOption)
{
	cellOskDialog.todo("cellOskDialogSetSeparateWindowOption(windowOption=*0x%x)", windowOption);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogSetInitialInputDevice(vm::ptr<CellOskDialogInputDevice> inputDevice)
{
	cellOskDialog.todo("cellOskDialogSetInitialInputDevice(inputDevice=*0x%x)", inputDevice);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogSetInitialKeyLayout(vm::ptr<CellOskDialogInitialKeyLayout> initialKeyLayout)
{
	cellOskDialog.todo("cellOskDialogSetInitialKeyLayout(initialKeyLayout=*0x%x)", initialKeyLayout);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogDisableDimmer()
{
	cellOskDialog.todo("cellOskDialogDisableDimmer()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogSetKeyLayoutOption(u32 option)
{
	cellOskDialog.todo("cellOskDialogSetKeyLayoutOption(option=0x%x)", option);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogAddSupportLanguage(u32 supportLanguage)
{
	cellOskDialog.todo("cellOskDialogAddSupportLanguage(supportLanguage=0x%x)", supportLanguage);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogSetLayoutMode(s32 layoutMode)
{
	cellOskDialog.todo("cellOskDialogSetLayoutMode(layoutMode=%d)", layoutMode);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogGetInputText(vm::ptr<CellOskDialogCallbackReturnParam> OutputInfo)
{
	cellOskDialog.warning("cellOskDialogGetInputText(OutputInfo=*0x%x)", OutputInfo);
	return cellOskDialogUnloadAsync(OutputInfo); //Same but for use with cellOskDialogSetSeparateWindowOption(). TODO. 
}

s32 cellOskDialogExtInputDeviceUnlock()
{
	cellOskDialog.todo("cellOskDialogExtInputDeviceUnlock()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtRegisterKeyboardEventHookCallback()
{
	fmt::throw_exception("Unimplemented" HERE);
}

s32 cellOskDialogExtAddJapaneseOptionDictionary(vm::cptr<char> filePath)
{
	cellOskDialog.todo("cellOskDialogExtAddJapaneseOptionDictionary(filePath=*0x%0x)", filePath);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtEnableClipboard()
{
	cellOskDialog.todo("cellOskDialogExtEnableClipboard()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtSendFinishMessage(vm::ptr<CellOskDialogFinishReason> finishReason)
{
	cellOskDialog.todo("cellOskDialogExtSendFinishMessage(finishReason=*0x%x)", finishReason);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtAddOptionDictionary(vm::cptr<CellOskDialogImeDictionaryInfo> dictionaryInfo)
{
	cellOskDialog.todo("cellOskDialogExtAddOptionDictionary(dictionaryInfo=*0x%x)", dictionaryInfo);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtSetInitialScale(f32 initialScale)
{
	cellOskDialog.todo("cellOskDialogExtSetInitialScale(initialScale=0x%x)", initialScale);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtInputDeviceLock()
{
	cellOskDialog.todo("cellOskDialogExtInputDeviceLock()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtSetBaseColor(f32 red, f32 blue, f32 green, f32 alpha)
{
	cellOskDialog.warning("cellOskDialogExtSetBaseColor(red=0x%x, blue=0x%x, green=0x%x, alpha=0x%x)", red, blue, green, alpha);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtRegisterConfirmWordFilterCallback()
{
	fmt::throw_exception("Unimplemented" HERE);
}

s32 cellOskDialogExtUpdateInputText()
{
	cellOskDialog.todo("cellOskDialogExtUpdateInputText");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtDisableHalfByteKana()
{
	cellOskDialog.todo("cellOskDialogExtDisableHalfByteKana");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtSetPointerEnable(b8 enable)
{
	cellOskDialog.todo("cellOskDialogExtSetPointerEnable(enable=%d)", enable);
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtUpdatePointerDisplayPos()
{
	cellOskDialog.todo("cellOskDialogExtUpdatePointerDisplayPos()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtEnableHalfByteKana()
{
	cellOskDialog.todo("cellOskDialogExtEnableHalfByteKana()");
	return CELL_OSKDIALOG_OK;
}

s32 cellOskDialogExtRegisterForceFinishCallback()
{
	cellOskDialog.todo("cellOskDialogExtRegisterForceFinishCallback()");
	return CELL_OSKDIALOG_OK;
}


void cellSysutil_OskDialog_init()
{
	REG_FUNC(cellSysutil, cellOskDialogLoadAsync);
	REG_FUNC(cellSysutil, cellOskDialogUnloadAsync);
	REG_FUNC(cellSysutil, cellOskDialogGetSize);
	REG_FUNC(cellSysutil, cellOskDialogAbort);
	REG_FUNC(cellSysutil, cellOskDialogSetDeviceMask);
	REG_FUNC(cellSysutil, cellOskDialogSetSeparateWindowOption);
	REG_FUNC(cellSysutil, cellOskDialogSetInitialInputDevice);
	REG_FUNC(cellSysutil, cellOskDialogSetInitialKeyLayout);
	REG_FUNC(cellSysutil, cellOskDialogDisableDimmer);
	REG_FUNC(cellSysutil, cellOskDialogSetKeyLayoutOption);
	REG_FUNC(cellSysutil, cellOskDialogAddSupportLanguage);
	REG_FUNC(cellSysutil, cellOskDialogSetLayoutMode);
	REG_FUNC(cellSysutil, cellOskDialogGetInputText);
}

DECLARE(ppu_module_manager::cellOskDialog)("cellOskExtUtility", []()
{
	REG_FUNC(cellOskExtUtility, cellOskDialogExtInputDeviceUnlock);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtRegisterKeyboardEventHookCallback);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtAddJapaneseOptionDictionary);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtEnableClipboard);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtSendFinishMessage);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtAddOptionDictionary);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtSetInitialScale);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtInputDeviceLock);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtSetBaseColor);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtRegisterConfirmWordFilterCallback);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtUpdateInputText);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtDisableHalfByteKana);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtSetPointerEnable);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtUpdatePointerDisplayPos);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtEnableHalfByteKana);
	REG_FUNC(cellOskExtUtility, cellOskDialogExtRegisterForceFinishCallback);
});
